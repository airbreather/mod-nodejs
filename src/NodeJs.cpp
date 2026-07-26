#include "NodeJs.h"

#include <filesystem>
#include <node.h>
#include <ranges>
#include <stdexcept>
#include <utility>
#include <uv.h>
#include <v8-context.h>
#include <v8-exception.h>
#include <v8-function-callback.h>
#include <v8-function.h>
#include <v8-isolate.h>
#include <v8-locker.h>
#include <v8-maybe.h>
#include <v8-message.h>
#include <v8-object.h>
#include <v8-primitive.h>
#include <boost/algorithm/string/join.hpp>

#include "ChatCommandBuilderBuilder.h"
#include "Config.h"
#include "CtoJ.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "NodeEmbeddedScriptFiles.h"
#include "NodePropertySystem.h"
#include "NodeWrappedObject.h"
#include "QueryResult.h"
#include "StringFormat.h"
#include "fmt/base.h"

v8::Local<v8::FunctionTemplate> create_global_interop_object_template();
v8::Local<v8::FunctionTemplate> create_add_listener_callback_template();
v8::Local<v8::FunctionTemplate> create_remove_listener_callback_template();

namespace {
class AlreadyRegisteredTemplateError : public std::runtime_error {
public:
	explicit AlreadyRegisteredTemplateError()
		: std::runtime_error("NodeRuntime: cannot register the same template twice") {
	}
};

class MissingTemplateError : public std::runtime_error {
public:
	explicit MissingTemplateError()
		: std::runtime_error("NodeRuntime: missing template") {
	}
};

class InitializationFailure : public std::runtime_error {
public:
	explicit InitializationFailure()
		: std::runtime_error(
			"NodeRuntime: unknown failure trying to initialize the runtime.") {
	}
};

class CannotInitializeTwice : public std::runtime_error {
public:
	explicit CannotInitializeTwice()
		: std::runtime_error(
			"NodeRuntime: already initialized, cannot init twice.") {
	}
};

class CannotRegisterSameCommandTwice : public std::runtime_error {
public:
	explicit CannotRegisterSameCommandTwice()
		: std::runtime_error(
			"NodeRuntime: cannot register the same command more than once.") {
	}
};

// we can only initialize Node.js once per process.
std::mutex ONCE_INIT_LOCK;
std::optional<OnceInitResult> ONCE_INIT_RESULT{};
OnceInitResult init_node_and_v8_once() {
	auto args = std::vector<std::string>{
		"node", "--expose-gc", "--enable-source-maps"
	};
	auto const extra_node_args_count = sConfigMgr->GetOption<int>("NodeJs.ExtraNodeArgsCount", 0);
	for (auto i = 0; i < extra_node_args_count; ++i) {
		auto const key = Acore::StringFormat("NodeJs.ExtraNodeArg.{}", i);
		args.emplace_back(sConfigMgr->GetOption<std::string>(key, ""));
	}
	v8::V8::InitializeICU();
	auto init = node::InitializeOncePerProcess(args,
		{
			node::ProcessInitializationFlags::kNoInitializeV8,
			node::ProcessInitializationFlags::kNoInitializeNodeV8Platform,
		});

	auto plat(node::MultiIsolatePlatform::Create(4));
	v8::V8::InitializeICU();
	v8::V8::InitializePlatform(plat.get());
	v8::V8::Initialize();
	return {
		.plat = std::move(plat),
		.init = init
	};
}
OnceInitResult & get_once_init_result() {
	if (!ONCE_INIT_RESULT) {
		std::lock_guard lck(ONCE_INIT_LOCK);
		if (!ONCE_INIT_RESULT) {
			ONCE_INIT_RESULT = init_node_and_v8_once();
		}
	}
	return *ONCE_INIT_RESULT;
}

std::unique_ptr<NodeJs> RUNTIME_INSTANCE { nullptr };
auto RUNTIME_IS_INITIALIZED = false;
}

NodeJs::NodeJs(OnceInitResult & once_init_result)
	: init_result_(once_init_result.init), platform_(once_init_result.plat.get()), m_command_map(1024) {
	setup_ = node::CommonEnvironmentSetup::Create(
		platform_, &errors_, init_result_->args(), init_result_->exec_args());
}

NodeJs::~NodeJs() {
	Acore::ChatCommands::InvalidateCommandMap();
	run_scoped([this] {
		v8::SealHandleScope seal(setup_->isolate());
		node::Stop(setup_->env());
	});
	delete post_to_event_loop_master_;
}

NodeJs * NodeJs::instance() {
	return RUNTIME_INSTANCE.get();
}

void NodeJs::shutdown() {
	RUNTIME_INSTANCE.reset(nullptr);
	RUNTIME_IS_INITIALIZED = false;
}

bool NodeJs::instance_is_fully_initialized() {
	return RUNTIME_IS_INITIALIZED;
}

void NodeJs::init_instance() {
	if (RUNTIME_IS_INITIALIZED) {
		throw CannotInitializeTwice();
	}

	RUNTIME_INSTANCE = std::make_unique<NodeJs>(get_once_init_result());
	RUNTIME_INSTANCE->actual_init();
	RUNTIME_IS_INITIALIZED = true;
	invoke_hook("nodejs:startup");
	Acore::ChatCommands::InvalidateCommandMap();
}

void NodeJs::reload_instance() {
	std::string persist_data{};
	invoke_hook("nodejs:before-shutdown", jarg("reloading", true), jarg_inout("persistData", persist_data));
	RUNTIME_INSTANCE.reset(nullptr);
	RUNTIME_IS_INITIALIZED = false;
	RUNTIME_INSTANCE = std::make_unique<NodeJs>(get_once_init_result());
	RUNTIME_INSTANCE->actual_init();
	RUNTIME_IS_INITIALIZED = true;
	invoke_hook("nodejs:startup", jarg("persistData", persist_data));
	Acore::ChatCommands::InvalidateCommandMap();
}

void NodeJs::reg_template(std::type_index const typ, v8::Local<v8::FunctionTemplate> const ft) {
	if (m_ac_templates.contains(typ)) {
		throw AlreadyRegisteredTemplateError();
	}
	m_ac_templates[typ] = v8::Global<v8::FunctionTemplate>(v8::Isolate::GetCurrent(), ft);
}

v8::Local<v8::FunctionTemplate> NodeJs::get_template(std::type_index const typ) const {
	auto const ft = m_ac_templates.find(typ);
	if (ft == m_ac_templates.end()) {
		[[unlikely]] throw MissingTemplateError();
	}
	return ft->second.Get(v8::Isolate::GetCurrent());
}

v8::Local<v8::FunctionTemplate> NodeJs::get_most_specific_template(std::type_index typ, void * p) const {
	// ASSUMPTION: no diamond inheritance. this should be the case anyway since v8::FunctionTemplate
	// can only do single inheritance, so it's not actually an issue.
	auto const [start, end] = m_ac_derived_template_types.equal_range(typ);
	std::vector<std::pair<std::type_index, DerivedTemplateRTTIFunc>> better_types(start, end);
	while (!better_types.empty()) {
		auto const [candidate, fun] = better_types.back();
		better_types.pop_back();
		if (auto const better = fun(p)) {
			typ = *better;
			auto const [start2, end2] = m_ac_derived_template_types.equal_range(typ);
			for (auto it = start2; it != end2; ++it) {
				better_types.emplace_back(*it);
			}
		}
	}
	return get_template(typ);
}

void NodeJs::add_listener(std::string const & event_name) {
	if (
		auto const it = m_active_listeners.find(event_name);
		it == m_active_listeners.end()
	) {
		m_active_listeners[event_name] = 1;
	} else {
		++it->second;
	}
}

void NodeJs::remove_listener(std::string const & event_name) {
	if (
		auto const it = m_active_listeners.find(event_name);
		--it->second == 0
	) {
		m_active_listeners.erase(it);
	}
}

void NodeJs::reg_command(ChatCommandBuilderBuilderBox box) {
	Acore::ChatCommands::InvalidateCommandMap();
	if (
		auto old = m_command_map.find(box->get_name());
		old != m_command_map.end()
	) {
		throw CannotRegisterSameCommandTwice();
	}
	box->assign_slots([this](std::vector<std::string> & path, v8::Global<v8::Function> cb) {
		auto s = boost::algorithm::join(path, ".");
		if (
			auto old = m_command_map.find(s);
			old != m_command_map.end()
		) {
			m_command_callbacks[old->second] = std::move(cb);
			return old->second;
		}
		auto sz = m_command_callbacks.size();
		m_command_map[s] = sz;
		m_command_callbacks.push_back(std::move(cb));
		return sz;
	});
	m_top_level_commands.push_back(std::move(box));
}

std::vector<ChatCommandBuilder> NodeJs::get_commands() {
	auto const commands = m_top_level_commands
		| std::ranges::views::transform([](auto & cmd) { return cmd->build(); })
		;
	return {commands.begin(), commands.end()};
}

bool NodeJs::exec_chat_command(size_t n, ChatHandler * ch, char const * argstr) const {
	auto res_bool = false;
	run_scoped([this, n, ch, argstr, &res_bool] {
		auto const isolate = v8::Isolate::GetCurrent();
		auto const ctx = isolate->GetCurrentContext();
		v8::Local<v8::Value> args[2] = { jval(ch), jstrz(argstr) };
		if (
			v8::Local<v8::Value> res;
			this->m_command_callbacks[n].Get(isolate)->Call(ctx, jnull(), 2, args).ToLocal(&res)
		) {
			if (auto const res_val = cval<bool>(res)) {
				res_bool = *res_val;
			}
		}
	});
	return res_bool;
}

void NodeJs::tick() {
	run_scoped([this] {
		query_processor_.ProcessReadyCallbacks();
		uv_run(setup_->event_loop(), UV_RUN_NOWAIT);
		if (run_microtasks_this_tick_) {
			setup_->isolate()->PerformMicrotaskCheckpoint();
			run_microtasks_this_tick_ = false;
		}
		platform_->DrainTasks(setup_->isolate());
	});
}

void NodeJs::run_garbage_collection_once() const {
	setup_->isolate()->RequestGarbageCollectionForTesting(v8::Isolate::GarbageCollectionType::kFullGarbageCollection);
}

void log_and_reset_if_signaled(v8::TryCatch & try_catch) {
	if (!try_catch.HasCaught()) {
		return;
	}
	auto const isolate = v8::Isolate::GetCurrent();
	auto const ctx = isolate->GetCurrentContext();
	auto has_stack = false;
	v8::Local<v8::String> stack_string;
	if (v8::Local<v8::Value> stack; try_catch.StackTrace(ctx).ToLocal(&stack)) {
		has_stack = stack->ToString(ctx).ToLocal(&stack_string);
	}
	if (!has_stack) {
		// at least log the message
		stack_string = try_catch.Message()->Get();
	}
	LOG_ERROR("module.nodejs", std::string(*v8::String::Utf8Value(isolate, stack_string)));
	try_catch.Reset();
}

inline void NodeJs::run_scoped(std::function<void()> const & f) const {
	v8::Locker locker(setup_->isolate());
	v8::Isolate::Scope isolate_scope(setup_->isolate());
	v8::HandleScope handle_scope(setup_->isolate());
	v8::Context::Scope context_scope(setup_->context());
	v8::TryCatch try_catch(setup_->isolate());
	f();
	log_and_reset_if_signaled(try_catch);
}

v8::Local<v8::FunctionTemplate> NodeJs::hook_arg_template(std::string const & hook_name, const std::vector<Arg *> & args) {
	auto it = m_hook_arg_templates.find(hook_name);
	if (it == m_hook_arg_templates.end()) {
		[[unlikely]] it = hook_arg_template_rare(hook_name, args);
	}
	return it->second.Get(setup_->isolate());
}

std::unordered_map<std::string, v8::Global<v8::FunctionTemplate>>::iterator NodeJs::hook_arg_template_rare(std::string const & hook_name, const std::vector<Arg *> & args) {
	auto const ft = v8::FunctionTemplate::New(setup_->isolate());
	ft->InstanceTemplate()->SetInternalFieldCount(2);
	auto i = 0;
	for (auto arg_name : args | std::views::transform([](Arg const * a) { return a->name; })) {
		ft->InstanceTemplate()->SetNativeDataProperty(
			jstr_intern(arg_name),
			[](v8::Local<v8::Name>, v8::PropertyCallbackInfo<v8::Value> const & info) {
				auto const dynamic_args = extract_native_pointer_from<std::vector<Arg *> *>(info.HolderV2());
				auto const arg_index = info.Data()
					.As<v8::Number>()
					->Int32Value(info.GetIsolate()->GetCurrentContext())
					.ToChecked();
				auto const dynamic_arg = dynamic_args->at(arg_index);
				info.GetReturnValue().Set(dynamic_arg->val());
			},
			[](v8::Local<v8::Name>, v8::Local<v8::Value> const val, v8::PropertyCallbackInfo<void> const & info) {
				auto const dynamic_args = extract_native_pointer_from<std::vector<Arg *> *>(info.HolderV2());
				auto const arg_index = info.Data()
					.As<v8::Number>()
					->Int32Value(info.GetIsolate()->GetCurrentContext())
					.ToChecked();
				if (auto const dynamic_arg = dynamic_args->at(arg_index); !dynamic_arg->try_set_val(val)) {
					info.GetIsolate()->ThrowError(
						jstr(Acore::StringFormat("The '{}' property wraps a native argument - it MUST be a compatible type.", dynamic_arg->name))
					);
				}
			},
			v8::Number::New(setup_->isolate(), i++),
			v8::PropertyAttribute::None,
			v8::SideEffectType::kHasNoSideEffect,
			v8::SideEffectType::kHasSideEffect
		);
	}
	return m_hook_arg_templates.insert(
		{hook_name, v8::Global<v8::FunctionTemplate>(setup_->isolate(), ft)}
	).first;
}

void NodeJs::invoke_hook_(std::string const & hook_name, std::vector<Arg *> & args) {
	run_scoped([this, & hook_name, & args] {
		auto const obj_creator = hook_arg_template(hook_name, args)
			->GetFunction(setup_->context())
			.ToLocalChecked();
		auto const obj = obj_creator->NewInstance(setup_->context()).ToLocalChecked();
		reference_pointer_from(obj, &args);
		v8::Local<v8::Value> args_v8[] = {jstr_intern(hook_name), obj};
		auto const ignored = acore_hooks_emit_.Get(setup_->isolate())->Call(
			setup_->context(),
			acore_hooks_.Get(setup_->isolate()),
			2,
			args_v8
		);
		if (ignored.IsEmpty()) {
			// this means that it threw an exception, which will already get logged by InScope.
		}
	});
}

v8::Local<v8::Value> NodeJs::load_environment_callback(node::StartExecutionCallbackInfoWithModule const & info) {
	instance()->post_to_event_loop_master_ = new NodePostToEventLoopMaster(instance()->setup_->event_loop());
	instance()->reg_template<NodeJs *>(jcreate_template<NodeJs *>());
	auto const isolate = v8::Isolate::GetCurrent();
	auto const context = isolate->GetCurrentContext();
	auto const global_this = context->Global();

	// load Long.js
	v8::Local<v8::Value> args[] = {
		jstr(LONGJS_SCRIPT),
		v8::Integer::New(isolate, static_cast<int>(node::ModuleFormat::kModule)),
		jstr_intern("internal"),
	};
	v8::Local<v8::Value> long_result;
	if (!info.run_module()->Call(context, context->Global(), 3, args).ToLocal(&long_result)) {
		return {};
	}

	global_this->Set(context, jstr_intern("Long"), long_result).Check();

	args[0] = jstr(INIT_SCRIPT);
	v8::Local<v8::Object> init_result;
	if (!info.run_module()->Call(context, context->Global(), 3, args).As<v8::Object>().ToLocal(&init_result)) {
		return {};
	}

	v8::Local<v8::Function> finish_init;
	if (!init_result->Get(context, jstr_intern("finishInit")).As<v8::Function>().ToLocal(&finish_init)) {
		return {};
	}

	// export function finishInit(acore, addListenerCallback, removeListenerCallback)
	auto const acore = jtemplated_object(instance());
	args[0] = acore;
	args[1] = jfn([](std::string hook_name) { instance()->add_listener(hook_name); });
	args[2] = jfn([](std::string hook_name) { instance()->remove_listener(hook_name); });

	v8::Local<v8::Function> run_user_script;
	if (!finish_init->Call(context, context->Global(), 3, args).As<v8::Function>().ToLocal(&run_user_script)) {
		return {};
	};

	if (
		auto const script_path = sConfigMgr->GetOption<std::string>("NodeJs.Script", "");
		!script_path.empty()
	) {
		auto const abs_script_path = std::filesystem::canonical(script_path).string();
		args[0] = jstr(abs_script_path);
		v8::TryCatch try_catch(isolate);
		if (run_user_script->Call(context, jnull(), 1, args).IsEmpty()) {
			log_and_reset_if_signaled(try_catch);
		} else {
			LOG_INFO("module.nodejs", "Loaded user script from {}", script_path);
		}
	}
	return acore;
}

void NodeJs::actual_init() {
	run_scoped([this] {
		v8::Local<v8::Object> acore;
		if (!node::LoadEnvironment(setup_->env(), load_environment_callback).As<v8::Object>().ToLocal(&acore)) {
			throw InitializationFailure();
		}

		auto const global_this = setup_->context()->Global();
		acore_ = v8::Global<v8::Object>(setup_->isolate(), acore);
		auto const long_js = global_this->Get(
			setup_->context(),
			jstr_intern("Long")
		).As<v8::Object>().ToLocalChecked();
		long_js_ = v8::Global<v8::Object>(setup_->isolate(), long_js);
		auto const hooks = acore->Get(
			setup_->context(),
			jstr_intern("hooks")
		).As<v8::Object>().ToLocalChecked();
		acore_hooks_ = v8::Global<v8::Object>(setup_->isolate(), hooks);
		auto const emit = hooks->Get(
			setup_->context(),
			jstr_intern("emit")
		).As<v8::Function>().ToLocalChecked();
		acore_hooks_emit_ = v8::Global<v8::Function>(setup_->isolate(), emit);
	});
}

void NodeJs::post_to_event_loop(std::function<void()> f) const {
	post_to_event_loop_master_->post(std::move(f));
}

v8::Local<v8::Promise> NodeJs::world_db_query_async(std::string_view const s) {
	return db_query_async(WorldDatabase, s);
}

v8::Local<v8::Promise> NodeJs::login_db_query_async(std::string_view s) {
	return db_query_async(LoginDatabase, s);
}

v8::Local<v8::Promise> NodeJs::character_db_query_async(std::string_view s) {
	return db_query_async(CharacterDatabase, s);
}

template <typename T>
requires std::is_base_of_v<MySQLConnection, T>
v8::Local<v8::Promise> NodeJs::db_query_async(DatabaseWorkerPool<T> & db, std::string_view s) {
	auto const prom = v8::Promise::Resolver::New(setup_->context()).ToLocalChecked();
	auto resolver_ref = new v8::Global<v8::Promise::Resolver>(setup_->isolate(), prom);
	query_processor_.AddCallback(db.AsyncQuery(s).WithCallback([this, resolver_ref](QueryResult result) {
		post_to_event_loop([this, resolver_ref, result = std::move(result)] {
			auto const resolver = resolver_ref->Get(setup_->isolate());
			delete resolver_ref;
			resolver->Resolve(setup_->context(), jval(result)).Check();
			// TODO: figure out why DrainTasks isn't enough to make this respond in a timely fashion
			run_microtasks_this_tick_ = true;
		});
	}));
	return prom->GetPromise();
}
