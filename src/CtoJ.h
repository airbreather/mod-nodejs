#ifndef MOD_NODEJS_CTOJ_H
#define MOD_NODEJS_CTOJ_H

#include <typeindex>
#include <v8-container.h>
#include <v8-external.h>
#include <v8-function.h>
#include <v8-isolate.h>

#include "NodeCommon.h"

v8::Local<v8::FunctionTemplate> jtemplate(std::type_index);

template <typename T>
requires std::is_pointer_v<T>
v8::Local<v8::FunctionTemplate> jtemplate() {
	return jtemplate(typeid(T));
}

v8::Local<v8::FunctionTemplate> jtemplate(std::type_index, void *);

template <typename T>
requires std::is_pointer_v<T>
v8::Local<v8::FunctionTemplate> jtemplate(T p) {
	if constexpr (std::is_same_v<T, std::add_pointer_t<std::remove_const_t<std::remove_pointer_t<T>>>>) {
		return jtemplate(typeid(T), p);
	} else {
		return jtemplate(typeid(T), const_cast<std::add_pointer_t<std::remove_const_t<std::remove_pointer_t<T>>>>(p));
	}
}

template <typename T>
requires std::is_pointer_v<T>
v8::Local<v8::Object> jtemplated_object(T p) {
	auto const context = v8::Isolate::GetCurrent()->GetCurrentContext();
	v8::Local<v8::Value> arg;
	if constexpr (std::is_same_v<T, std::add_pointer_t<std::remove_const_t<std::remove_pointer_t<T>>>>) {
		arg = v8::External::New(v8::Isolate::GetCurrent(), p);
	} else {
		arg = v8::External::New(v8::Isolate::GetCurrent(), const_cast<std::add_pointer_t<std::remove_const_t<std::remove_pointer_t<T>>>>(p));
	}
	return jtemplate<T>(p)->GetFunction(context).ToLocalChecked()->NewInstance(context, 1, &arg).ToLocalChecked();
}

// ReSharper disable once CppFunctionIsNotImplemented
template <typename T>
v8::Local<v8::Value> jval(T);

// ReSharper disable once CppFunctionIsNotImplemented
template <typename T>
requires std::is_pointer_v<T>
v8::Local<v8::FunctionTemplate> jcreate_template();

v8::Local<v8::Value> jnull();
v8::Local<v8::String> jstr(std::string_view s);
v8::Local<v8::String> jstrz(char const * s);

template <std::size_t N>
v8::Local<v8::String> jstr(char const (& s)[N]) {
	return v8::String::NewFromUtf8Literal(v8::Isolate::GetCurrent(), s);
}

v8::Local<v8::String> jstr_intern(std::string_view s);

template <std::size_t N>
v8::Local<v8::String> jstr_intern(char const (& s)[N]) {
	return v8::String::NewFromUtf8Literal(v8::Isolate::GetCurrent(), s, v8::NewStringType::kInternalized);
}

template <MapLike M>
requires std::is_trivially_copyable_v<typename M::mapped_type>
v8::Local<v8::Map> jmap(M const & map) {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const context = isolate->GetCurrentContext();
	auto const result = v8::Map::New(isolate);
	for (auto const [k, v] : map) {
		result->Set(context, jval(k), jval(v)).ToLocalChecked();
	}
	return result;
}

template <MapLike M>
requires (!std::is_trivially_copyable_v<typename M::mapped_type>)
v8::Local<v8::Map> jmap(M const & map) {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const context = isolate->GetCurrentContext();
	auto const result = v8::Map::New(isolate);
	for (auto [k, v] : map) {
		result->Set(context, jval(k), jval<typename M::mapped_type *>(&v)).ToLocalChecked();
	}
	return result;
}

template <typename T>
void jobj_set_tup(v8::Local<v8::Object> const data_obj, T props) {
	std::apply([& data_obj](auto... p) { (data_obj->Set(v8::Isolate::GetCurrent()->GetCurrentContext(), jstr_intern(p.get_name()), p.val()).Check(), ...); }, props);
}

template <typename... Props>
void jobj_set(v8::Local<v8::Object> const data_obj, Props... props) {
	jobj_set_tup(data_obj, std::tuple{props...});
}

template <typename T>
v8::Local<v8::Object> jobj_tup(T props) {
	auto const data_obj = v8::Object::New(v8::Isolate::GetCurrent());
	jobj_set_tup(data_obj, props);
	return data_obj;
}

template <typename... Props>
v8::Local<v8::Object> jobj(Props... props) {
	return jobj_tup(std::tuple{props...});
}

template <typename T>
concept jarrable = requires(T t1, T const t2) { t1 == t2; ++t1; *t1; };

template <jarrable T>
v8::Local<v8::Value> jarr(T curr, T const end) {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const context = isolate->GetCurrentContext();
	auto const arr = v8::Array::New(isolate);
	uint32_t len = 0;
	while (curr != end) {
		arr->Set(context, len++, jval(*curr)).Check();
		++curr;
	}
	return arr;
}

template <std::ranges::range R>
v8::Local<v8::Value> jarr(R&& rng) {
	return jarr(std::ranges::begin(rng), std::ranges::end(rng));
}

inline v8::Local<v8::Value> jarr() {
	return v8::Array::New(v8::Isolate::GetCurrent());
}

template <jarrable T>
v8::Local<v8::Value> jset(T curr, T const end) {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const context = isolate->GetCurrentContext();
	auto const arr = v8::Set::New(isolate);
	while (curr != end) {
		arr->Add(context, jval(*curr)).ToLocalChecked();
		++curr;
	}
	return arr;
}

template <std::ranges::range R>
v8::Local<v8::Value> jset(R&& rng) {
	return jset(std::ranges::begin(rng), std::ranges::end(rng));
}

inline v8::Local<v8::Value> jset() {
	return v8::Set::New(v8::Isolate::GetCurrent());
}

v8::Local<v8::FunctionTemplate> jctor();

template <typename ArgsTuple, std::size_t... Is>
void jfill_args_impl(v8::Local<v8::Value> * vals, ArgsTuple args, std::index_sequence<Is...>) {
	size_t i = 0;
	((vals[i++] = jval<std::tuple_element_t<Is, ArgsTuple>>(std::get<Is>(args))), ...);
}

template <typename... Args>
void jfill_args(v8::Local<v8::Value> * vals, Args... args) {
	jfill_args_impl(vals, std::make_tuple(args...), std::make_index_sequence<sizeof...(Args)>{});
}

#define JVAL_TMPL_RW(cname) \
template<> \
[[nodiscard]] v8::Local<v8::Value> jval<cname *>(cname * data) { \
	return data ? jtemplated_object(data) : jnull(); \
} \
template<> \
[[nodiscard]] v8::Local<v8::Value> jval<cname const *>(cname const * data) { \
	return jval<cname *>(const_cast<cname *>(data)); \
}

#define CVAL_TMPL_RW(cname) \
template<> \
std::optional<cname *> cval<cname *>(v8::Local<v8::Value> const v) { \
	return ctemplated_object<cname *>(v); \
} \
template<> \
std::optional<cname const *> cval<cname const *>(v8::Local<v8::Value> const v) { \
	return cval<cname *>(v); \
}

#define JVAL_TMPL_RO(cname) \
template<> \
[[nodiscard]] v8::Local<v8::Value> jval<cname *>(cname * data) { \
	return data ? jtemplated_object(data) : jnull(); \
}

#define CVAL_TMPL_RO(cname) \
template<> \
std::optional<cname *> cval<cname *>(v8::Local<v8::Value> const v) { \
	return ctemplated_object<cname *>(v); \
}

#define JVAL_CVAL_TMPLS_RO(cname) \
	JVAL_TMPL_RO(cname) \
	CVAL_TMPL_RO(cname)

#define JVAL_CVAL_TMPLS_RW(cname) \
	JVAL_TMPL_RW(cname) \
	CVAL_TMPL_RW(cname)

#endif //MOD_NODEJS_CTOJ_H
