#ifndef MOD_NODEJS_NODE_PROPERTY_SYSTEM_H
#define MOD_NODEJS_NODE_PROPERTY_SYSTEM_H

#include <v8-external.h>

#include "Functions.h"
#include "JtoC.h"
#include "NodeJs.h"
#include "NodeWrappedObject.h"

class DifferentSettersForSameGetter : public std::runtime_error {
public:
	explicit DifferentSettersForSameGetter()
		: std::runtime_error("NodeRuntime: cannot have different setters for the same getter.") {
	}
};

template <typename T>
requires std::is_pointer_v<T>
struct TypedTemplate {
	v8::Local<v8::FunctionTemplate> ft;

	// ReSharper disable once CppNonExplicitConvertingConstructor -- that's actually exactly what we want here
	TypedTemplate(v8::Local<v8::FunctionTemplate> const ft) : ft(ft) {}

	// ReSharper disable once CppNonExplicitConversionOperator -- that's actually exactly what we want here
	operator v8::Local<v8::FunctionTemplate>() const { return ft; }
	v8::Local<v8::FunctionTemplate> operator->() const { return ft; }

	template <typename B>
	requires (true
		&& std::is_const_v<std::remove_pointer_t<B>> == std::is_const_v<std::remove_pointer_t<T>>
		&& std::is_pointer_v<B>
		&& std::is_base_of_v<std::remove_pointer_t<B>, std::remove_pointer_t<T>>
	)
	void safe_inherit() const {
		ft->Inherit(jtemplate<B>());
		NodeJs::instance()->reg_template_inheritance<B, T>();
	}
};

template <typename Obj, typename Getter>
requires (std::is_pointer_v<Obj> && std::is_invocable_v<Getter, Obj>)
void reg_prop_ro(TypedTemplate<Obj> const ft, std::string_view const name, Getter const && getter) {
	using Prop = std::invoke_result_t<Getter, Obj>;
	using GetterPtr = Prop (*)(Obj);
	auto const getter_ptr = static_cast<GetterPtr>(getter);
	auto const isolate = v8::Isolate::GetCurrent();
	ft->InstanceTemplate()->SetNativeDataProperty(
		jstr_intern(name),
		[](v8::Local<v8::Name>, v8::PropertyCallbackInfo<v8::Value> const & args) {
			auto obj = extract_native_pointer_from<Obj>(args.HolderV2());
			auto recovered_getter_ptr = reinterpret_cast<GetterPtr>(args.Data().As<v8::External>()->Value());
			args.GetReturnValue().Set(jval<Prop>((*recovered_getter_ptr)(obj)));
		},
		nullptr,
		v8::External::New(isolate, reinterpret_cast<void *>(getter_ptr))
	);
}

// not the cleanest, but setup is single-threaded and completes before the first user script runs.
static std::unordered_map<void *, void *> SETTERS_BY_GETTER;

template <typename Obj, typename Getter, typename Setter>
requires (std::is_pointer_v<Obj> && std::is_invocable_v<Getter, Obj> && std::is_invocable_v<Setter, Obj, std::invoke_result_t<Getter, Obj>>)
void reg_prop(TypedTemplate<Obj> const ft, std::string_view const name, Getter && getter, Setter && setter) {
	using Prop = std::invoke_result_t<Getter, Obj>;
	using GetterPtr = Prop (*)(Obj);
	using SetterPtr = void (*)(Obj, Prop);
	auto const getter_ptr = static_cast<GetterPtr>(getter);
	auto const setter_ptr = static_cast<SetterPtr>(setter);
	auto const getter_void_ptr = reinterpret_cast<void *>(getter_ptr);
	auto const setter_void_ptr = reinterpret_cast<void *>(setter_ptr);
	if (
		auto const found_setter = SETTERS_BY_GETTER.find(reinterpret_cast<void *>(getter_ptr));
		found_setter != SETTERS_BY_GETTER.end()
	) {
		if (found_setter->second != setter_void_ptr) {
			throw DifferentSettersForSameGetter();
		}
	} else {
		SETTERS_BY_GETTER[getter_void_ptr] = setter_void_ptr;
	}
	auto const isolate = v8::Isolate::GetCurrent();
	ft->InstanceTemplate()->SetNativeDataProperty(
		jstr_intern(name),
		[](v8::Local<v8::Name>, v8::PropertyCallbackInfo<v8::Value> const & args) {
			auto obj = extract_native_pointer_from<Obj>(args.HolderV2());
			auto const recovered_getter_ptr = reinterpret_cast<GetterPtr>(args.Data().As<v8::External>()->Value());
			args.GetReturnValue().Set(jval<Prop>((*recovered_getter_ptr)(obj)));
		},
		[](v8::Local<v8::Name>, v8::Local<v8::Value> const value, v8::PropertyCallbackInfo<void> const & args) {
			auto val = cval<Prop>(value);
			if (!val) {
				args.GetIsolate()->ThrowError("Failed to run setter.");
				return;
			}
			auto obj = extract_native_pointer_from<Obj>(args.HolderV2());
			auto const recovered_setter_ptr = reinterpret_cast<SetterPtr>(SETTERS_BY_GETTER[args.Data().As<v8::External>()->Value()]);
			(*recovered_setter_ptr)(obj, *val);
		},
		v8::External::New(isolate, getter_void_ptr)
	);
}

template <typename Obj, typename Fn>
requires (std::is_pointer_v<Obj>)
void reg_method(TypedTemplate<Obj> const ft, std::string_view const name, Fn && fn) {
	ft->PrototypeTemplate()->Set(jstr_intern(name), jmeth<Obj>(fn));
}

template <typename Fn>
void reg_static_method(v8::Local<v8::FunctionTemplate> const ft, std::string_view const name, Fn && fn) {
	ft->Set(jstr_intern(name), jfnt(fn));
}

template <typename Obj, typename Fn>
requires (std::is_pointer_v<Obj>)
void reg_method_raw(TypedTemplate<Obj> const ft, std::string_view const name, Fn && fn) {
	ft->PrototypeTemplate()->Set(jstr_intern(name), jmeth_raw<Obj>(fn));
}

template <typename Fn>
void reg_static_method_raw(v8::Local<v8::FunctionTemplate> const ft, std::string_view const name, Fn && fn) {
	ft->Set(jstr_intern(name), jfnt(fn));
}

template <typename Obj, typename... Args>
requires std::is_pointer_v<Obj>
v8::Local<v8::Value> jnew(Args... args) {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const ctx = isolate->GetCurrentContext();
	v8::Local<v8::Value> vals[sizeof...(Args)];
	jfill_args(vals, args...);
	if (isolate->HasPendingException()) {
		return jnull();
	}
	return jtemplate<Obj>()->GetFunction(ctx).ToLocalChecked()->NewInstance(ctx, sizeof...(Args), vals).ToLocalChecked();
}

template <size_t T>
bool exec_chat_command_in_slot(ChatHandler * ch, char const * args) {
	if (auto r = NodeJs::instance()) {
		return r->exec_chat_command(T, ch, args);
	}
	return false;
}

#endif // MOD_NODEJS_NODE_PROPERTY_SYSTEM_H
