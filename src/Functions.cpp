#include "Functions.h"

v8::Local<v8::FunctionTemplate> jfnt_raw_impl(void (*fn)(v8::FunctionCallbackInfo<v8::Value> const &)) {
	return v8::FunctionTemplate::New(
		v8::Isolate::GetCurrent(),
		[](v8::FunctionCallbackInfo<v8::Value> const & args) {
			auto const recovered_fn_ptr = reinterpret_cast<decltype(fn)>(args.Data().As<v8::External>()->Value());
			(*recovered_fn_ptr)(args);
		},
		v8::External::New(v8::Isolate::GetCurrent(), reinterpret_cast<void *>(fn))
	);
}
