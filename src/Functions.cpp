#include "Functions.h"

v8::Local<v8::FunctionTemplate> jfnt_raw_impl(void (*fn)(v8::FunctionCallbackInfo<v8::Value> const &)) {
	return v8::FunctionTemplate::New(
		v8::Isolate::GetCurrent(),
		[](v8::FunctionCallbackInfo<v8::Value> const & args) {
			auto const recovered_fn_ptr = reinterpret_cast<decltype(fn)>(args.Data().As<v8::External>()->Value(v8::kExternalPointerTypeTagDefault));
			(*recovered_fn_ptr)(args);
		},
		v8::External::New(v8::Isolate::GetCurrent(), reinterpret_cast<void *>(fn), v8::kExternalPointerTypeTagDefault)
	);
}

v8::Local<v8::FunctionTemplate> jctor() {
	auto const ft = v8::FunctionTemplate::New(v8::Isolate::GetCurrent(), [](v8::FunctionCallbackInfo<v8::Value> const & args) {
		if (args[0]->IsExternal() && args[1]->IsUint32() && *cval<uint32_t>(args[1]) == OBJECT_REFERENCE_MAGIC) {
			reference_pointer_from(args.This(), args[0].As<v8::External>()->Value(v8::kExternalPointerTypeTagDefault));
			args.GetReturnValue().Set(args.This());
		} else {
			args.GetIsolate()->ThrowError("Instances of this type cannot have ownership transferred to scripts.");
		}
	});
	ft->InstanceTemplate()->SetInternalFieldCount(2);
	return ft;
}
