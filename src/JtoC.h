#ifndef MOD_NODEJS_JTOC_H
#define MOD_NODEJS_JTOC_H

#include <v8-isolate.h>

#include "CtoJ.h"
#include "DBCStore.h"
#include "NodeCommon.h"
#include "NodeWrappedObject.h"

template <typename T>
requires std::is_pointer_v<T>
std::optional<T> ctemplated_object(v8::Local<v8::Value> const v) {
	return
		jtemplate<T>()->HasInstance(v)
			? std::optional(extract_native_pointer_from<T>(v.As<v8::Object>()))
			: std::nullopt;
}

// ReSharper disable once CppFunctionIsNotImplemented
template <typename T>
std::optional<T> cval(v8::Local<v8::Value>);

template <typename T>
std::optional<T> cval(v8::Local<v8::Object> const obj, std::string_view const prop) {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const context = isolate->GetCurrentContext();
	v8::Local<v8::Value> val;
	return obj->Get(context, jstr_intern(prop)).ToLocal(&val)
		? cval<T>(val)
		: std::nullopt;
}

template <typename T>
bool ctry_set(T & dst, v8::Local<v8::Value> const jsrc) {
	if (auto const src = cval<T>(jsrc)) {
		dst = *src;
		return true;
	}
	return false;
}

template <typename T>
bool ctry_set(T & dst, v8::Local<v8::Object> const obj, std::string_view const prop) {
	if (auto const src = cval<T>(obj, prop)) {
		dst = *src;
		return true;
	}
	return false;
}

template <typename E>
std::optional<E const *> centry_lookup(v8::Local<v8::Value> const v, DBCStorage<E> const & store) {
	auto const context = v8::Isolate::GetCurrent()->GetCurrentContext();
	v8::Local<v8::Uint32> id;
	if (v->ToUint32(context).ToLocal(&id)) {
		lkup_by_id:
		if (auto const entry = store.LookupEntry(id->Value())) {
			return entry;
		}
	} else {
		v8::Local<v8::Object> obj;
		if (v->ToObject(context).ToLocal(&obj)) {
			v8::Local<v8::Value> id_prop;
			if (obj->Get(context, jstr_intern("id")).ToLocal(&id_prop) && id_prop->ToUint32(context).ToLocal(&id)) {
				goto lkup_by_id;
			}
		}
	}
	return std::nullopt;
}

template <typename P, int I>
requires (is_specialization_of_v<std::optional, P>)
P carg(v8::FunctionCallbackInfo<v8::Value> const & info, bool & failed) {
	return failed
		? std::nullopt
		: cval<typename P::value_type>(info[I]);
}

template <typename P, int I>
requires (!is_specialization_of_v<std::optional, P>)
P carg(v8::FunctionCallbackInfo<v8::Value> const & info, bool & failed) {
	if (failed) {
		// don't bother, it threw already.
		return {};
	}
	if (auto val = cval<P>(info[I])) {
		return *val;
	}
	info.GetIsolate()->ThrowError("Failed to convert required arg.");
	failed = true;
	return {};
}

#endif //MOD_NODEJS_JTOC_H
