#ifndef MOD_NODEJS_NODEJS_H
#define MOD_NODEJS_NODEJS_H

#include <functional>
#include <mutex>
#include <node.h>
#include <typeindex>
#include <v8-object.h>
#include <vector>

#include "AsyncCallbackProcessor.h"
#include "ChatCommand.h"
#include "Db.h"
#include "Log.h"
#include "MySQLConnection.h"
#include "NodeJPropHelpers.h"
#include "NodePostToEventLoopMaster.h"

class ChatCommandBuilderBuilder;
using ChatCommandBuilderBuilderBox = std::shared_ptr<ChatCommandBuilderBuilder>;
using ChatCommandBuilder = Acore::ChatCommands::ChatCommandBuilder;

struct OnceInitResult {
	std::unique_ptr<node::MultiIsolatePlatform> plat;
	std::shared_ptr<node::InitializationResult> init;
};

using DerivedTemplateRTTIFunc = std::function<std::optional<std::type_index>(void *)>;
class NodeJs {
	std::shared_ptr<node::InitializationResult> init_result_;
	node::MultiIsolatePlatform * platform_;
	std::unique_ptr<node::CommonEnvironmentSetup> setup_;
	QueryCallbackProcessor query_processor_;
	NodePostToEventLoopMaster * post_to_event_loop_master_ = nullptr;
	std::vector<std::string> errors_;
	v8::Global<v8::Object> acore_;
	v8::Global<v8::Object> acore_hooks_;
	v8::Global<v8::Function> acore_hooks_emit_;
	bool run_microtasks_this_tick_ = false;

	std::unordered_multimap<std::type_index, DerivedTemplateRTTIFunc> m_ac_derived_template_types;
	std::unordered_map<std::type_index, v8::Global<v8::FunctionTemplate>> m_ac_templates;
	std::unordered_map<std::string, v8::Global<v8::FunctionTemplate>> m_hook_arg_templates;
	std::unordered_map<std::string, size_t> m_active_listeners;
	std::unordered_map<std::string, size_t> m_command_map;
	std::vector<ChatCommandBuilderBuilderBox> m_top_level_commands;
	std::vector<v8::Global<v8::Function>> m_command_callbacks;

public:
	NodeJs(OnceInitResult &);
	~NodeJs();

	static NodeJs * instance();
	[[nodiscard]] static bool instance_is_fully_initialized();

	static void init_instance();
	static void reload_instance();
	static void shutdown();

	template <typename T>
	requires std::is_pointer_v<T>
	void reg_template(v8::Local<v8::FunctionTemplate> const ft) {
		reg_template(typeid(T), ft);
	}
	void reg_template(std::type_index, v8::Local<v8::FunctionTemplate>);

	template <typename B, typename T>
	requires (true
		&& std::is_pointer_v<T>
		&& std::is_pointer_v<B>
		&& std::is_base_of_v<std::remove_pointer_t<B>, std::remove_pointer_t<T>>
	)
	void reg_template_inheritance() {
		m_ac_derived_template_types.insert(std::pair<std::type_index, DerivedTemplateRTTIFunc>(typeid(B), [](void * p) {
			return dynamic_cast<T>(reinterpret_cast<B>(p))
				? std::optional<std::type_index>(typeid(T))
				: std::nullopt;
		}));
	}

	template <typename T>
	requires std::is_pointer_v<T>
	v8::Local<v8::FunctionTemplate> get_template() const {
		return get_template(typeid(T));
	}
	v8::Local<v8::FunctionTemplate> get_template(std::type_index) const;

	template <typename T>
	requires std::is_pointer_v<T>
	v8::Local<v8::FunctionTemplate> get_most_specific_template(T ptr) const {
		return get_most_specific_template(typeid(T), ptr);
	}
	v8::Local<v8::FunctionTemplate> get_most_specific_template(std::type_index, void *) const;

	void post_to_event_loop(std::function<void()> f) const;

	void add_listener(std::string const & event_name);
	void remove_listener(std::string const & event_name);

	void reg_command(ChatCommandBuilderBuilderBox);
	std::vector<ChatCommandBuilder> get_commands();
	bool exec_chat_command(size_t, ChatHandler *, char const *) const;

	template <Db Db>
	v8::Local<v8::Promise> db_query_async(std::string_view s) {
		auto const prom = v8::Promise::Resolver::New(setup_->context()).ToLocalChecked();
		auto resolver_ref = new v8::Global<v8::Promise::Resolver>(setup_->isolate(), prom);
		query_processor_.AddCallback(db<Db>().worker().AsyncQuery(s).WithCallback([this, resolver_ref](QueryResult result) {
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

	void tick();
	void run_garbage_collection_once() const;

	void run_scoped(std::function<void()> const & f) const;

	std::optional<std::chrono::time_point<std::chrono::utc_clock, Milliseconds>> convert_instant(v8::Local<v8::Object>) const;
	std::optional<Milliseconds> convert_duration(v8::Local<v8::Object>) const;

	template <typename T, typename... Args>
	static T invoke_hook_t(std::string const & hook_name, T dfault, Args && ... args) {
		if (!(instance_is_fully_initialized() && instance()->m_active_listeners.contains(hook_name))) {
			[[likely]] return dfault;
		}
		std::vector<Arg *> args_vec{& args...};
		auto ret_arg = jarg_inout("__return", dfault);
		args_vec.push_back(&ret_arg);
		LOG_TRACE("module.nodejs", "begin hook {}", hook_name);
		instance()->invoke_hook_(hook_name, args_vec);
		LOG_TRACE("module.nodejs", "end hook {}", hook_name);
		return dfault;
	}

	static bool hook_has_listeners(std::string const & hook_name) {
		if (!(instance_is_fully_initialized() && instance()->m_active_listeners.contains(hook_name))) {
			[[likely]] return false;
		}
		return true;
	}

	template <typename... Args>
	static void invoke_hook(std::string const & hook_name, Args && ... args) {
		if (!(instance_is_fully_initialized() && instance()->m_active_listeners.contains(hook_name))) {
			[[likely]] return;
		}
		std::vector<Arg *> args_vec{& args...};
		LOG_TRACE("module.nodejs", "begin hook {}", hook_name);
		instance()->invoke_hook_(hook_name, args_vec);
		LOG_TRACE("module.nodejs", "end hook {}", hook_name);
	}

private:
	v8::Local<v8::FunctionTemplate> hook_arg_template(std::string const & hook_name, const std::vector<Arg *> & args);
	std::unordered_map<std::string, v8::Global<v8::FunctionTemplate>>::iterator hook_arg_template_rare(std::string const & hook_name, const std::vector<Arg *> & args);
	void invoke_hook_(std::string const & hook_name, std::vector<Arg *> & args);
	static v8::Local<v8::Value> load_environment_callback(node::StartExecutionCallbackInfoWithModule const & info);

	void actual_init();
};

#endif //MOD_NODEJS_NODEJS_H
