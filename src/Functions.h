#ifndef MOD_NODEJS_FUNCTIONS_H
#define MOD_NODEJS_FUNCTIONS_H

#include <v8-isolate.h>

#include "CtoJ.h"
#include "JtoC.h"
#include "NodeWrappedObject.h"

template <typename T>
requires std::is_pointer_v<T>
bool wrap_or_manage(v8::FunctionCallbackInfo<v8::Value> const & args) {
	if (!args[0]->IsExternal()) {
		return false;
	}

	auto ptr = args[0].As<v8::External>()->Value(v8::kExternalPointerTypeTagDefault);
	switch (cval<uint32_t>(args[1]).value_or(0)) {
		case OWNERSHIP_TRANSFER_MAGIC:
			// this references an object created in C++ code but whose ownership is being
			// transferred to a garbage-collected object in v8.
			manage_pointer_with(args.This(), static_cast<T>(ptr));
			break;
		case OBJECT_REFERENCE_MAGIC:
			// this is just referencing an object with an externally managed lifetime
			reference_pointer_from(args.This(), ptr);
			break;
		default:
			return false;
	}

	// either way, we're done. the provided callback is only for when objects are being
	// created using a constructor **called from JavaScript code**.
	args.GetReturnValue().Set(args.This());
	return true;
}

template <typename FnPtr, typename ArgsTuple, std::size_t... Is>
void jfnt_impl2_ret(v8::FunctionCallbackInfo<v8::Value> const & args, std::index_sequence<Is...>) {
	auto failed = false;
	auto converted_args = std::make_tuple(carg<std::tuple_element_t<Is, ArgsTuple>, Is>(args, failed)...);
	if (failed) {
		// carg already threw, so we can just return here.
		return;
	}
	auto const recovered_fn_ptr = reinterpret_cast<FnPtr>(args.Data().As<v8::External>()->Value(v8::kExternalPointerTypeTagDefault));
	args.GetReturnValue().Set(jval(std::apply(recovered_fn_ptr, converted_args)));
}

template <typename FnPtr, typename ArgsTuple, std::size_t... Is>
void jfnt_impl2_void(v8::FunctionCallbackInfo<v8::Value> const & args, std::index_sequence<Is...>) {
	auto failed = false;
	auto converted_args = std::make_tuple(carg<std::tuple_element_t<Is, ArgsTuple>, Is>(args, failed)...);
	if (failed) {
		// carg already threw, so we can just return here.
		return;
	}
	auto const recovered_fn_ptr = reinterpret_cast<FnPtr>(args.Data().As<v8::External>()->Value(v8::kExternalPointerTypeTagDefault));
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
	auto const recovered_fn_ptr = reinterpret_cast<FnPtr>(args.Data().As<v8::External>()->Value(v8::kExternalPointerTypeTagDefault));
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
	auto const recovered_fn_ptr = reinterpret_cast<FnPtr>(args.Data().As<v8::External>()->Value(v8::kExternalPointerTypeTagDefault));
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
	auto const recovered_fn_ptr = reinterpret_cast<FnPtr>(args.Data().As<v8::External>()->Value(v8::kExternalPointerTypeTagDefault));
	if (Obj obj = std::apply(recovered_fn_ptr, converted_args)) {
		manage_pointer_with(args.This(), obj);
		args.GetReturnValue().Set(args.This());
	}
}

template <typename Ret, typename... Args>
v8::Local<v8::FunctionTemplate> jfnt_impl1(Ret (*fn)(Args...)) {
	return v8::FunctionTemplate::New(
		v8::Isolate::GetCurrent(),
		[](v8::FunctionCallbackInfo<v8::Value> const & args) {
			jfnt_impl2_ret<Ret (*)(Args...), std::tuple<Args...>>(args, std::make_index_sequence<sizeof...(Args)>{});
		},
		v8::External::New(v8::Isolate::GetCurrent(), reinterpret_cast<void *>(fn), v8::kExternalPointerTypeTagDefault)
	);
}

template <typename... Args>
v8::Local<v8::FunctionTemplate> jfnt_impl1(void (*fn)(Args...)) {
	return v8::FunctionTemplate::New(
		v8::Isolate::GetCurrent(),
		[](v8::FunctionCallbackInfo<v8::Value> const & args) {
			jfnt_impl2_void<void (*)(Args...), std::tuple<Args...>>(args, std::make_index_sequence<sizeof...(Args)>{});
		},
		v8::External::New(v8::Isolate::GetCurrent(), reinterpret_cast<void *>(fn), v8::kExternalPointerTypeTagDefault)
	);
}

template <typename Obj, typename Ret, typename... Args>
requires std::is_pointer_v<Obj>
v8::Local<v8::FunctionTemplate> jmeth_impl1(Ret (*fn)(Obj, Args...)) {
	return v8::FunctionTemplate::New(
		v8::Isolate::GetCurrent(),
		[](v8::FunctionCallbackInfo<v8::Value> const & args) {
			jmeth_impl2_ret<Ret (*)(Obj, Args...), Obj, std::tuple<Args...>>(args, std::make_index_sequence<sizeof...(Args)>{});
		},
		v8::External::New(v8::Isolate::GetCurrent(), reinterpret_cast<void *>(fn), v8::kExternalPointerTypeTagDefault)
	);
}

template <typename Obj, typename... Args>
requires std::is_pointer_v<Obj>
v8::Local<v8::FunctionTemplate> jmeth_impl1(void (*fn)(Obj, Args...)) {
	return v8::FunctionTemplate::New(
		v8::Isolate::GetCurrent(),
		[](v8::FunctionCallbackInfo<v8::Value> const & args) {
			jmeth_impl2_void<void (*)(Obj, Args...), Obj, std::tuple<Args...>>(args, std::make_index_sequence<sizeof...(Args)>{});
		},
		v8::External::New(v8::Isolate::GetCurrent(), reinterpret_cast<void *>(fn), v8::kExternalPointerTypeTagDefault)
	);
}

template <typename Obj, typename... Args>
requires std::is_pointer_v<Obj>
v8::Local<v8::FunctionTemplate> jctor_impl1(Obj (*fn)(Args...)) {
	auto const ft = v8::FunctionTemplate::New(
		v8::Isolate::GetCurrent(),
		[](v8::FunctionCallbackInfo<v8::Value> const & args) {
			if (wrap_or_manage<Obj>(args)) {
				return;
			}

			jctor_impl2<Obj (*)(Args...), Obj, std::tuple<Args...>>(args, std::make_index_sequence<sizeof...(Args)>{});
		},
		v8::External::New(v8::Isolate::GetCurrent(), reinterpret_cast<void *>(fn), v8::kExternalPointerTypeTagDefault)
	);
	ft->InstanceTemplate()->SetInternalFieldCount(2);
	return ft;
}

v8::Local<v8::FunctionTemplate> jfnt_raw_impl(void (*fn)(v8::FunctionCallbackInfo<v8::Value> const &));

template <typename Obj>
requires std::is_pointer_v<Obj>
v8::Local<v8::FunctionTemplate> jmeth_raw_impl(void (*fn)(Obj, v8::FunctionCallbackInfo<v8::Value> const &)) {
	return v8::FunctionTemplate::New(
		v8::Isolate::GetCurrent(),
		[](v8::FunctionCallbackInfo<v8::Value> const & args) {
			auto const recovered_fn_ptr = reinterpret_cast<decltype(fn)>(args.Data().As<v8::External>()->Value(v8::kExternalPointerTypeTagDefault));
			auto const obj = extract_native_pointer_from<Obj>(args.This());
			(*recovered_fn_ptr)(obj, args);
		},
		v8::External::New(v8::Isolate::GetCurrent(), reinterpret_cast<void *>(fn), v8::kExternalPointerTypeTagDefault)
	);
}

template <typename Obj>
requires std::is_pointer_v<Obj>
v8::Local<v8::FunctionTemplate> jctor_raw_impl(Obj (*fn)(v8::FunctionCallbackInfo<v8::Value> const &)) {
	auto const ft = v8::FunctionTemplate::New(
		v8::Isolate::GetCurrent(),
		[](v8::FunctionCallbackInfo<v8::Value> const & args) {
			if (wrap_or_manage<Obj>(args)) {
				return;
			}

			auto const recovered_fn_ptr = reinterpret_cast<decltype(fn)>(args.Data().As<v8::External>()->Value(v8::kExternalPointerTypeTagDefault));
			if (Obj obj = (*recovered_fn_ptr)(args)) {
				manage_pointer_with(args.This(), obj);
				args.GetReturnValue().Set(args.This());
			}
		},
		v8::External::New(v8::Isolate::GetCurrent(), reinterpret_cast<void *>(fn), v8::kExternalPointerTypeTagDefault)
	);
	ft->InstanceTemplate()->SetInternalFieldCount(2);
	return ft;
}

template <typename Fn>
v8::Local<v8::FunctionTemplate> jfnt(Fn && fn) {
	return jfnt_impl1(+fn);
}

template <typename Fn>
v8::Local<v8::Function> jfn(Fn && fn) {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const ctx = isolate->GetCurrentContext();
	return jfnt_impl1(+fn)->GetFunction(ctx).ToLocalChecked();
}

template <typename Obj, typename Fn>
requires std::is_pointer_v<Obj>
v8::Local<v8::FunctionTemplate> jmeth(Fn && fn) {
	return jmeth_impl1(+fn);
}

template <typename Fn>
v8::Local<v8::FunctionTemplate> jctor(Fn && fn) {
	return jctor_impl1(+fn);
}

template <typename Obj>
requires std::is_pointer_v<Obj>
v8::Local<v8::FunctionTemplate> jctor() {
	auto const ft = v8::FunctionTemplate::New(v8::Isolate::GetCurrent(), [](v8::FunctionCallbackInfo<v8::Value> const & args) {
		if (wrap_or_manage<Obj>(args)) {
			return;
		}
		args.GetIsolate()->ThrowError("This type cannot be constructed directly from scripts.");
	});
	ft->InstanceTemplate()->SetInternalFieldCount(2);
	return ft;
}

v8::Local<v8::FunctionTemplate> jctor();

template <typename Fn>
v8::Local<v8::FunctionTemplate> jfnt_raw(Fn && fn) {
	return jfnt_raw_impl(+fn);
}

template <typename Obj, typename Fn>
requires std::is_pointer_v<Obj>
v8::Local<v8::FunctionTemplate> jmeth_raw(Fn && fn) {
	return jmeth_raw_impl(+fn);
}

template <typename Fn>
v8::Local<v8::FunctionTemplate> jctor_raw(Fn && fn) {
	return jctor_raw_impl(+fn);
}

#endif //MOD_NODEJS_FUNCTIONS_H
