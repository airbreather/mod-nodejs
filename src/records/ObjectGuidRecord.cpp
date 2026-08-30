#include <optional>
#include <v8-isolate.h>
#include <v8-local-handle.h>
#include <v8-value.h>

#include "ByteBuffer.h"
#include "CtoJ.h"
#include "JtoC.h"
#include "ObjectGuid.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<ObjectGuid const>(ObjectGuid const p) {
	return p
		? v8::BigInt::NewFromUnsigned(v8::Isolate::GetCurrent(), p.GetRawValue())
		: jnull();
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<ObjectGuid>(ObjectGuid const p) {
	return jval<ObjectGuid const>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<PackedGuid const>(PackedGuid const p) {
	ByteBuffer b; b<<p;
	uint64_t d; b.readPackGUID(d);
	return jval(ObjectGuid(d));
}

[[nodiscard]] std::optional<ObjectGuid> cval_guid_slow(v8::Local<v8::Value> const v) {
	// we probably won't USUALLY see these as empty, but representing empty GUIDs as undefined will
	// theoretically help make it easier to translate C++ routines to JavaScript... which means that
	// we can definitely see them come back that way; when they do, we have to handle them.
	if (v->IsUndefined()) {
		return ObjectGuid::Empty;
	}

	// by default, the fast-path will unpack from the same v8::BigInt that we gave out, because
	// that's expected to be *by far* the most common way to get a GUID. however, there are still
	// plenty of use cases for scripts to examine a GUID's individual parts themselves and to create
	// them anew. for those cases, we let them decode the opaque token to a 3-element array. this
	// array can be passed directly back to us anywhere that we expect a GUID.
	auto const isolate = v8::Isolate::GetCurrent();
	auto const ctx = isolate->GetCurrentContext();
	if (v->IsArray()) {
		if (auto const arr = v.As<v8::Array>(); arr->Length() == 3) {
			std::array<uint32_t, 3> vals{0, 0, 0};
			auto const it = arr->Iterate(ctx, [](uint32_t const index, v8::Local<v8::Value> const val, void * data) {
				if (index < 3) {
					if (auto const n = cval<uint32_t>(val)) {
						(*static_cast<std::array<uint32_t, 3> *>(data))[index] = *n;
						return v8::Array::CallbackResult::kContinue;
					}
					return v8::Array::CallbackResult::kException;
				}
				return v8::Array::CallbackResult::kBreak;
			}, &vals);
			if (it.IsJust()) {
				return ObjectGuid(static_cast<HighGuid>(vals[0]), vals[1], vals[2]);
			}
		}
	}
	isolate->ThrowError(jstr_intern("expected an opaque or decoded GUID"));
	return std::nullopt;
}

template<>
[[nodiscard]] std::optional<ObjectGuid> cval<ObjectGuid>(v8::Local<v8::Value> const v) {
	if (v->IsBigInt()) {
		auto raw = v.As<v8::BigInt>()->Uint64Value();
		return std::optional{ObjectGuid(raw)};
	}
	return cval_guid_slow(v);
}

template<>
[[nodiscard]] std::optional<ObjectGuid const> cval<ObjectGuid const>(v8::Local<v8::Value> const v) {
	return cval<ObjectGuid>(v);
}

template<>
[[nodiscard]] std::optional<PackedGuid> cval<PackedGuid>(v8::Local<v8::Value> const v) {
	auto const guid_maybe = cval<ObjectGuid>(v);
	return guid_maybe
		? std::optional{PackedGuid(*guid_maybe)}
		: std::nullopt;
}
