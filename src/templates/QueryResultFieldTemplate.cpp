#include <optional>
#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>
#include <vector>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "Player.h"
#include "QueryResult.h"

JVAL_CVAL_TMPLS_RW(Field)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Field *>() {
	TypedTemplate<Field *> const ft = jctor();

	ft->SetClassName(jstr_intern("Field"));

	reg_prop_ro(ft, "fieldType", [](Field * f) {
		// rename because "type" is a keyword in TypeScript.
		return f->GetType();
	});
	reg_prop_ro(ft, "isNull", [](Field * f) {
		return f->IsNull();
	});

	reg_method(ft, "getBool", [](Field * f) {
		return f->Get<bool>();
	});
	reg_method(ft, "getU8", [](Field * f) {
		return f->Get<uint8_t>();
	});
	reg_method(ft, "getI8", [](Field * f) {
		return f->Get<int8_t>();
	});
	reg_method(ft, "getU16", [](Field * f) {
		return f->Get<uint16_t>();
	});
	reg_method(ft, "getI16", [](Field * f) {
		return f->Get<int16_t>();
	});
	reg_method(ft, "getU32", [](Field * f) {
		return f->Get<uint32_t>();
	});
	reg_method(ft, "getI32", [](Field * f) {
		return f->Get<int32_t>();
	});
	reg_method(ft, "getU64", [](Field * f) {
		return f->Get<uint64_t>();
	});
	reg_method(ft, "getI64", [](Field * f) {
		return f->Get<int64_t>();
	});
	reg_method(ft, "getF32", [](Field * f) {
		return f->Get<float>();
	});
	reg_method(ft, "getF64", [](Field * f) {
		return f->Get<double>();
	});
	reg_method(ft, "getString", [](Field * f) {
		return f->Get<std::string>();
	});
	reg_method(ft, "getBinary", [](Field * f) {
		auto const bin = f->Get<Binary>();
		auto const buf = v8::ArrayBuffer::New(v8::Isolate::GetCurrent(), bin.size(), v8::BackingStoreInitializationMode::kUninitialized);
		std::memcpy(buf->Data(), bin.data(), bin.size());
		return v8::Uint8Array::New(buf, 0, bin.size());
	});

	return ft;
}
