#include "JtoC.h"

#include <v8-context.h>

#include "Util.h"

template<>
std::optional<std::string> cval<std::string>(v8::Local<v8::Value> const v) {
	auto const isolate = v8::Isolate::GetCurrent();
	if (!v->IsString()) {
		return std::nullopt;
	}
	auto const str = v.As<v8::String>();
	auto const len = str->Utf8LengthV2(isolate);
	std::string s(len, '\0');
	str->WriteUtf8V2(isolate, s.data(), int{len});
	return s;
}

template<>
std::optional<std::string const> cval<std::string const>(v8::Local<v8::Value> const v) {
	return cval<std::string>(v);
}

template<>
std::optional<uint8_t> cval<uint8_t>(v8::Local<v8::Value> const v) {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const ctx = isolate->GetCurrentContext();
	v8::Local<v8::Uint32> u32;
	if (
		v->IsUint32()
		&& v->ToUint32(ctx).ToLocal(&u32)
		&& u32->Value() <= std::numeric_limits<uint8_t>::max()
	) {
		return uint8_t{u32->Value()};
	}
	return std::nullopt;
}

template<>
std::optional<uint16_t> cval<uint16_t>(v8::Local<v8::Value> const v) {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const ctx = isolate->GetCurrentContext();
	v8::Local<v8::Uint32> u32;
	if (
		v->IsUint32()
		&& v->ToUint32(ctx).ToLocal(&u32)
		&& u32->Value() <= std::numeric_limits<uint16_t>::max()
	) {
		return uint16_t{u32->Value()};
	}
	return std::nullopt;
}

template<>
std::optional<uint32_t> cval<uint32_t>(v8::Local<v8::Value> const v) {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const ctx = isolate->GetCurrentContext();
	v8::Local<v8::Uint32> u32;
	if (
		v->IsUint32()
		&& v->ToUint32(ctx).ToLocal(&u32)
	) {
		return u32->Value();
	}
	return std::nullopt;
}

template<>
std::optional<uint64_t> cval<uint64_t>(v8::Local<v8::Value> const v) {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const ctx = isolate->GetCurrentContext();
	auto const global_this = ctx->Global();
	auto const long_js = global_this->Get(ctx, jstr_intern("Long")).As<v8::Object>().ToLocalChecked();
	auto const long_js_from_value = long_js->Get(ctx, jstr_intern("fromValue")).As<v8::Function>().ToLocalChecked();
	auto const long_js_to_bigint = long_js->Get(ctx, jstr_intern("toBigInt")).As<v8::Function>().ToLocalChecked();
	v8::TryCatch try_catch(isolate);

	v8::Local<v8::Value> long_js_from_value_args[] = {
		v, // val
		v8::True(isolate), // unsigned
	};
	v8::Local<v8::Object> long_js_value;
	if (!long_js_from_value->Call(ctx, v8::Undefined(isolate), 1, long_js_from_value_args).As<v8::Object>().ToLocal(&long_js_value)) {
		return std::nullopt;
	}

	auto const bigint_value = long_js_to_bigint->Call(ctx, long_js_value, 0, nullptr).As<v8::BigInt>().ToLocalChecked();
	return bigint_value->Uint64Value();
}

template<>
std::optional<int8_t> cval<int8_t>(v8::Local<v8::Value> const v) {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const ctx = isolate->GetCurrentContext();
	v8::Local<v8::Int32>s32;
	if (
		v->IsInt32()
		&& v->ToInt32(ctx).ToLocal(&s32)
		&& s32->Value() >= std::numeric_limits<int8_t>::min()
		&& s32->Value() <= std::numeric_limits<int8_t>::max()
	) {
		return int8_t{s32->Value()};
	}
	return std::nullopt;
}

template<>
std::optional<int16_t> cval<int16_t>(v8::Local<v8::Value> const v) {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const ctx = isolate->GetCurrentContext();
	v8::Local<v8::Int32>s32;
	if (
		v->IsInt32()
		&& v->ToInt32(ctx).ToLocal(&s32)
		&& s32->Value() >= std::numeric_limits<int16_t>::min()
		&& s32->Value() <= std::numeric_limits<int16_t>::max()
	) {
		return int16_t{s32->Value()};
	}
	return std::nullopt;
}

template<>
std::optional<int32_t> cval<int32_t>(v8::Local<v8::Value> const v) {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const ctx = isolate->GetCurrentContext();
	v8::Local<v8::Int32> s32;
	if (
		v->IsInt32()
		&& v->ToInt32(ctx).ToLocal(&s32)
	) {
		return s32->Value();
	}
	return std::nullopt;
}

template<>
std::optional<int64_t> cval<int64_t>(v8::Local<v8::Value> const v) {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const ctx = isolate->GetCurrentContext();
	auto const global_this = ctx->Global();
	auto const long_js = global_this->Get(ctx, jstr_intern("Long")).As<v8::Object>().ToLocalChecked();
	auto const long_js_from_value = long_js->Get(ctx, jstr_intern("fromValue")).As<v8::Function>().ToLocalChecked();
	auto const long_js_to_bigint = long_js->Get(ctx, jstr_intern("toBigInt")).As<v8::Function>().ToLocalChecked();
	v8::TryCatch try_catch(isolate);

	v8::Local<v8::Value> long_js_from_value_args[] = {
		v, // val
		v8::False(isolate), // unsigned
	};
	v8::Local<v8::Object> long_js_value;
	if (!long_js_from_value->Call(ctx, v8::Undefined(isolate), 1, long_js_from_value_args).As<v8::Object>().ToLocal(&long_js_value)) {
		return std::nullopt;
	}

	auto const bigint_value = long_js_to_bigint->Call(ctx, long_js_value, 0, nullptr).As<v8::BigInt>().ToLocalChecked();
	return bigint_value->Int64Value();
}

template<>
std::optional<float> cval<float>(v8::Local<v8::Value> const v) {
	if (v->IsNumber()) {
		return std::optional{float{v.As<v8::Number>()->Value()}};
	}
	return std::nullopt;
}

template<>
std::optional<double> cval<double>(v8::Local<v8::Value> const v) {
	if (v->IsNumber()) {
		return std::optional{v.As<v8::Number>()->Value()};
	}
	return std::nullopt;
}

template<>
std::optional<bool> cval<bool>(v8::Local<v8::Value> const v) {
	return v->BooleanValue(v8::Isolate::GetCurrent());
}

template<>
std::optional<std::optional<bool>> cval<std::optional<bool>>(v8::Local<v8::Value> const v) {
	if (v->IsNullOrUndefined()) {
		return std::optional<std::optional<bool>>{ std::nullopt };
	}
	auto const result = cval<bool>(v);
	return result
		? std::optional<std::optional<bool>>{result}
		: std::nullopt;
}

template<>
std::optional<flag96> cval<flag96>(v8::Local<v8::Value> const v) {
	if (!v->IsBigInt()) {
		return std::nullopt;
	}
	auto const v_bigint = v.As<v8::BigInt>();
	static auto sign_0 = 0;
	auto word_count = 2;
	uint64_t words[2];
	v_bigint->ToWordsArray(&sign_0, &word_count, words);
	if (word_count > 2 || (words[1] & (1ull << 32) - 1) != 0) {
		return std::nullopt;
	}
	return std::optional{flag96(words[0] >> 32, words[0] & (1ull << 32) - 1, words[1])};
}
