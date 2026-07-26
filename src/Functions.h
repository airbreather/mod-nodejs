#ifndef MOD_NODEJS_FUNCTIONS_H
#define MOD_NODEJS_FUNCTIONS_H

#include <v8-isolate.h>

#include "CtoJ.h"
#include "JtoC.h"
#include "NodeWrappedObject.h"

template <typename FnPtr, typename ArgsTuple, std::size_t... Is>
void jfn_impl2_ret(v8::FunctionCallbackInfo<v8::Value> const & args, std::index_sequence<Is...>) {
	auto failed = false;
	auto converted_args = std::make_tuple(carg<std::tuple_element_t<Is, ArgsTuple>, Is>(args, failed)...);
	if (failed) {
		// carg already threw, so we can just return here.
		return;
	}
	auto const recovered_fn_ptr = reinterpret_cast<FnPtr>(args.Data().As<v8::External>()->Value());
	args.GetReturnValue().Set(jval(std::apply(recovered_fn_ptr, converted_args)));
}

template <typename FnPtr, typename ArgsTuple, std::size_t... Is>
void jfn_impl2_void(v8::FunctionCallbackInfo<v8::Value> const & args, std::index_sequence<Is...>) {
	auto failed = false;
	auto converted_args = std::make_tuple(carg<std::tuple_element_t<Is, ArgsTuple>, Is>(args, failed)...);
	if (failed) {
		// carg already threw, so we can just return here.
		return;
	}
	auto const recovered_fn_ptr = reinterpret_cast<FnPtr>(args.Data().As<v8::External>()->Value());
	std::apply(recovered_fn_ptr, converted_args);
}

template <typename FnPtr, typename Obj, typename ArgsTuple, std::size_t... Is>
void jmeth_impl2_ret(v8::FunctionCallbackInfo<v8::Value> const & args, std::index_sequence<Is...>) {
	auto failed = false;
	auto converted_args = std::make_tuple(carg<std::tuple_element_t<Is, ArgsTuple>, Is>(args, failed)...);
	if (failed) {
		// convert_arg already threw, so we can just return here.
		return;
	}
	auto const recovered_fn_ptr = reinterpret_cast<FnPtr>(args.Data().As<v8::External>()->Value());
	auto const obj = extract_native_pointer_from<Obj>(args.This());
	auto all_args = std::tuple_cat(std::tuple(obj), converted_args);
	auto const ret = std::apply(recovered_fn_ptr, all_args);
	if constexpr (std::is_pointer_v<Obj> && std::is_pointer_v<decltype(ret)>) {
		// slightly optimize "fluent builder"-style patterns to not create unnecessary new objects.
		args.GetReturnValue().Set(
			reinterpret_cast<void const *>(ret) == reinterpret_cast<void const *>(obj)
				? args.This()
				: jval(ret)
		);
	} else {
		args.GetReturnValue().Set(jval(ret));
	}
}

template <typename FnPtr, typename Obj, typename ArgsTuple, std::size_t... Is>
void jmeth_impl2_void(v8::FunctionCallbackInfo<v8::Value> const & args, std::index_sequence<Is...>) {
	auto failed = false;
	auto converted_args = std::make_tuple(carg<std::tuple_element_t<Is, ArgsTuple>, Is>(args, failed)...);
	if (failed) {
		// convert_arg already threw, so we can just return here.
		return;
	}
	auto const recovered_fn_ptr = reinterpret_cast<FnPtr>(args.Data().As<v8::External>()->Value());
	auto const obj = extract_native_pointer_from<Obj>(args.This());
	auto all_args = std::tuple_cat(std::tuple(obj), converted_args);
	std::apply(recovered_fn_ptr, all_args);
}

template <typename FnPtr, typename Obj, typename ArgsTuple, std::size_t... Is>
void jctor_impl2(v8::FunctionCallbackInfo<v8::Value> const & args, std::index_sequence<Is...>) {
	auto failed = false;
	auto converted_args = std::make_tuple(carg<std::tuple_element_t<Is, ArgsTuple>, Is>(args, failed)...);
	if (failed) {
		// convert_arg already threw, so we can just return here.
		return;
	}
	auto const recovered_fn_ptr = reinterpret_cast<FnPtr>(args.Data().As<v8::External>()->Value());
	if (Obj obj = std::apply(recovered_fn_ptr, converted_args)) {
		manage_pointer_with(args.This(), obj);
		args.GetReturnValue().Set(args.This());
	}
}

template <typename Ret, typename... Args>
v8::Local<v8::FunctionTemplate> jfn_impl1(Ret (*fn)(Args...)) {
	return v8::FunctionTemplate::New(
		v8::Isolate::GetCurrent(),
		[](v8::FunctionCallbackInfo<v8::Value> const & args) {
			jfn_impl2_ret<Ret (*)(Args...), std::tuple<Args...>>(args, std::make_index_sequence<sizeof...(Args)>{});
		},
		v8::External::New(v8::Isolate::GetCurrent(), reinterpret_cast<void *>(fn))
	);
}

template <typename... Args>
v8::Local<v8::FunctionTemplate> jfn_impl1(void (*fn)(Args...)) {
	return v8::FunctionTemplate::New(
		v8::Isolate::GetCurrent(),
		[](v8::FunctionCallbackInfo<v8::Value> const & args) {
			jfn_impl2_void<void (*)(Args...), std::tuple<Args...>>(args, std::make_index_sequence<sizeof...(Args)>{});
		},
		v8::External::New(v8::Isolate::GetCurrent(), reinterpret_cast<void *>(fn))
	);
}

template <typename Obj, typename Ret, typename... Args>
requires (std::is_pointer_v<Obj>)
v8::Local<v8::FunctionTemplate> jmeth_impl1(Ret (*fn)(Obj, Args...)) {
	return v8::FunctionTemplate::New(
		v8::Isolate::GetCurrent(),
		[](v8::FunctionCallbackInfo<v8::Value> const & args) {
			jmeth_impl2_ret<Ret (*)(Obj, Args...), Obj, std::tuple<Args...>>(args, std::make_index_sequence<sizeof...(Args)>{});
		},
		v8::External::New(v8::Isolate::GetCurrent(), reinterpret_cast<void *>(fn))
	);
}

template <typename Obj, typename... Args>
requires (std::is_pointer_v<Obj>)
v8::Local<v8::FunctionTemplate> jmeth_impl1(void (*fn)(Obj, Args...)) {
	return v8::FunctionTemplate::New(
		v8::Isolate::GetCurrent(),
		[](v8::FunctionCallbackInfo<v8::Value> const & args) {
			jmeth_impl2_void<void (*)(Obj, Args...), Obj, std::tuple<Args...>>(args, std::make_index_sequence<sizeof...(Args)>{});
		},
		v8::External::New(v8::Isolate::GetCurrent(), reinterpret_cast<void *>(fn))
	);
}

template <typename Obj, typename... Args>
requires (std::is_pointer_v<Obj>)
v8::Local<v8::FunctionTemplate> jctor_impl1(Obj (*fn)(Args...)) {
	auto const ft = v8::FunctionTemplate::New(
		v8::Isolate::GetCurrent(),
		[](v8::FunctionCallbackInfo<v8::Value> const & args) {
			if (args.Length() == 1 && args[0]->IsExternal()) {
				// this is just referencing an object with an externally managed lifetime
				reference_pointer_from(args.This(), args[0].As<v8::External>()->Value());
				args.GetReturnValue().Set(args.This());
				return;
			}

			jctor_impl2<Obj (*)(Args...), Obj, std::tuple<Args...>>(args, std::make_index_sequence<sizeof...(Args)>{});
		},
		v8::External::New(v8::Isolate::GetCurrent(), reinterpret_cast<void *>(fn))
	);
	ft->InstanceTemplate()->SetInternalFieldCount(2);
	return ft;
}

template <typename Fn>
v8::Local<v8::FunctionTemplate> jfn(Fn && fn) {
	return jfn_impl1(+fn);
}

template <typename Obj, typename Fn>
requires (std::is_pointer_v<Obj>)
v8::Local<v8::FunctionTemplate> jmeth(Fn && fn) {
	return jmeth_impl1(+fn);
}

template <typename Fn>
v8::Local<v8::FunctionTemplate> jctor(Fn && fn) {
	return jctor_impl1(+fn);
}

v8::Local<v8::FunctionTemplate> jfn_raw_impl(void (*fn)(v8::FunctionCallbackInfo<v8::Value> const &));

template <typename Fn>
v8::Local<v8::FunctionTemplate> jfn_raw(Fn && fn) {
	return jfn_raw_impl(+fn);
}

template <typename Obj>
requires (std::is_pointer_v<Obj>)
v8::Local<v8::FunctionTemplate> jmeth_raw_impl(void (*fn)(Obj, v8::FunctionCallbackInfo<v8::Value> const &)) {
	return v8::FunctionTemplate::New(
		v8::Isolate::GetCurrent(),
		[](v8::FunctionCallbackInfo<v8::Value> const & args) {
			auto const recovered_fn_ptr = reinterpret_cast<decltype(fn)>(args.Data().As<v8::External>()->Value());
			auto const obj = extract_native_pointer_from<Obj>(args.This());
			(*recovered_fn_ptr)(obj, args);
		},
		v8::External::New(v8::Isolate::GetCurrent(), reinterpret_cast<void *>(fn))
	);
}

template <typename Obj, typename Fn>
requires (std::is_pointer_v<Obj>)
v8::Local<v8::FunctionTemplate> jmeth_raw(Fn && fn) {
	return jmeth_raw_impl(+fn);
}

template <typename Obj>
requires std::is_pointer_v<Obj>
v8::Local<v8::FunctionTemplate> jctor_raw_impl(Obj (*fn)(v8::FunctionCallbackInfo<v8::Value> const &)) {
	auto const ft = v8::FunctionTemplate::New(
		v8::Isolate::GetCurrent(),
		[](v8::FunctionCallbackInfo<v8::Value> const & args) {
			if (args.Length() == 1 && args[0]->IsExternal()) {
				// this is just referencing an object with an externally managed lifetime
				reference_pointer_from(args.This(), args[0].As<v8::External>()->Value());
				args.GetReturnValue().Set(args.This());
				return;
			}

			auto const recovered_fn_ptr = reinterpret_cast<decltype(fn)>(args.Data().As<v8::External>()->Value());
			if (Obj obj = (*recovered_fn_ptr)(args)) {
				manage_pointer_with(args.This(), obj);
				args.GetReturnValue().Set(args.This());
			}
		},
		v8::External::New(v8::Isolate::GetCurrent(), reinterpret_cast<void *>(fn))
	);
	ft->InstanceTemplate()->SetInternalFieldCount(2);
	return ft;
}

template <typename Fn>
v8::Local<v8::FunctionTemplate> jctor_raw(Fn && fn) {
	return jctor_raw_impl(+fn);
}

#endif //MOD_NODEJS_FUNCTIONS_H
