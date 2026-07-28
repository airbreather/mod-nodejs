#include "CtoJ.h"

#include <cstring>
#include <stdexcept>
#include <v8-local-handle.h>

#include "NodeJs.h"
#include "Object.h"
#include "ObjectGuid.h"
#include "Pet.h"
#include "StringFormat.h"
#include "TemporarySummon.h"
#include "UnixTimestamp.h"
#include "fmt/base.h"

v8::Local<v8::FunctionTemplate> jtemplate(std::type_index const typ) {
	return NodeJs::instance()->get_template(typ);
}

v8::Local<v8::FunctionTemplate> jtemplate(std::type_index const typ, void * p) {
	return NodeJs::instance()->get_most_specific_template(typ, p);
}

v8::Local<v8::Value> jnull() {
	return v8::Undefined(v8::Isolate::GetCurrent());
}

v8::Local<v8::String> jstr(std::string_view const s) {
	return v8::String::NewFromUtf8(
		v8::Isolate::GetCurrent(),
		s.data(),
		v8::NewStringType::kNormal,
		static_cast<int>(s.length())
	).ToLocalChecked();
}

v8::Local<v8::String> jstrz(char const * s) {
	return v8::String::NewFromUtf8(
		v8::Isolate::GetCurrent(),
		s,
		v8::NewStringType::kNormal,
		static_cast<int>(strlen(s))
	).ToLocalChecked();
}

v8::Local<v8::String> jstr_intern(std::string_view const s) {
	return v8::String::NewFromUtf8(
		v8::Isolate::GetCurrent(),
		s.data(),
		v8::NewStringType::kInternalized,
		static_cast<int>(s.length())
		).ToLocalChecked();
}

// the C++ class hierarchy kinda breaks the compile-time dispatch since we might have a pointer to
// an object that we only statically know is a Unit but is actually a Player. JavaScript code should
// be able to do Player stuff with it, provided that they also have reason to know what type it is.
// fortunately, we have one bulletproof way to know which types the

class UntemplatedObjectType : public std::runtime_error {
public:
	explicit UntemplatedObjectType(TypeID type_id)
		: std::runtime_error(Acore::StringFormat("wrap_object: Object type {} does not have a template", type_id)) {
	}
};

v8::Local<v8::Value> wrap_object(Object * obj) {
	if (!obj) {
		return jnull();
	}
	switch (obj->GetTypeId()) {
		case TYPEID_UNIT:
			if (auto const obj_pet = dynamic_cast<Pet *>(obj)) {
				return jtemplated_object(obj_pet);
			}
			if (auto const obj_guardian = dynamic_cast<Guardian *>(obj)) {
				return jtemplated_object(obj_guardian);
			}
			if (auto const obj_minion = dynamic_cast<Minion *>(obj)) {
				return jtemplated_object(obj_minion);
			}
			if (auto const obj_temp_summon = dynamic_cast<TempSummon *>(obj)) {
				return jtemplated_object(obj_temp_summon);
			}
			return jtemplated_object(obj->ToCreature());
		case TYPEID_PLAYER:
			return jtemplated_object(obj->ToPlayer());
		case TYPEID_GAMEOBJECT:
			return jtemplated_object(obj->ToGameObject());
		case TYPEID_DYNAMICOBJECT:
			return jtemplated_object(obj->ToDynObject());
		case TYPEID_CORPSE:
			return jtemplated_object(obj->ToCorpse());
		default:
			throw UntemplatedObjectType(obj->GetTypeId());
	}
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<char const *>(char const * data) {
	return jstr(data);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<std::string>(std::string const data) {
	return jstr(data);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<std::string const &>(std::string const & data) {
	return jstr(data);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<uint32_t>(uint32_t const data) {
	return v8::Number::New(
		v8::Isolate::GetCurrent(),
		data
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<int32_t>(int32_t const data) {
	return v8::Number::New(
		v8::Isolate::GetCurrent(),
		data
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<float>(float const data) {
	return v8::Number::New(
		v8::Isolate::GetCurrent(),
		data
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<double>(double const data) {
	return v8::Number::New(
		v8::Isolate::GetCurrent(),
		data
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<bool>(bool const data) {
	return v8::Boolean::New(
		v8::Isolate::GetCurrent(),
		data
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<std::optional<bool>>(std::optional<bool> const data) {
	return data
		? v8::Boolean::New(v8::Isolate::GetCurrent(), *data)
		: jnull();
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<uint8_t>(uint8_t const data) {
	return v8::Number::New(
		v8::Isolate::GetCurrent(),
		data
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<int8_t>(int8_t const data) {
	return v8::Number::New(
		v8::Isolate::GetCurrent(),
		data
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<uint16_t>(uint16_t const data) {
	return v8::Number::New(
		v8::Isolate::GetCurrent(),
		data
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<int16_t>(int16_t const data) {
	return v8::Number::New(
		v8::Isolate::GetCurrent(),
		data
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<uint64_t>(uint64_t const v) {
	if (v < 1L<<53) {
		return v8::Number::New(v8::Isolate::GetCurrent(), double{v});
	}
	auto const isolate = v8::Isolate::GetCurrent();
	auto const ctx = isolate->GetCurrentContext();
	auto const global_this = ctx->Global();
	auto const long_js = global_this->Get(ctx, jstr_intern("Long")).As<v8::Object>().ToLocalChecked();
	auto const long_js_from_bits = long_js->Get(ctx, jstr_intern("fromBits")).As<v8::Function>().ToLocalChecked();
	v8::Local<v8::Value> args[] = {
		jval<uint32_t>(uint32_t{v}), // lowBits
		jval<uint32_t>(uint32_t{v >> 32}), // highBits
		v8::True(isolate), // unsigned
	};
	return long_js_from_bits->Call(ctx, v8::Undefined(isolate), 3, args).ToLocalChecked();
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<int64_t>(int64_t const v) {
	if (v > -1L<<53 && v < 1L<<53) {
		return v8::Number::New(v8::Isolate::GetCurrent(), double{v});
	}
	auto const isolate = v8::Isolate::GetCurrent();
	auto const ctx = isolate->GetCurrentContext();
	auto const global_this = ctx->Global();
	auto const long_js = global_this->Get(ctx, jstr_intern("Long")).As<v8::Object>().ToLocalChecked();
	auto const long_js_from_bits = long_js->Get(ctx, jstr_intern("fromBits")).As<v8::Function>().ToLocalChecked();
	v8::Local<v8::Value> args[] = {
		jval<int32_t>(int32_t{v}), // lowBits
		jval<int32_t>(int32_t{v >> 32}), // highBits
		v8::False(isolate), // unsigned
	};
	return long_js_from_bits->Call(ctx, v8::Undefined(isolate), 3, args).ToLocalChecked();
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<flag96>(flag96 const data) {
	uint64_t const words[] = { uint64_t{data[1]} << 32 & data[0], data[2] };
	return v8::BigInt::NewFromWords(
		v8::Isolate::GetCurrent()->GetCurrentContext(),
		0,
		2,
		words
	).ToLocalChecked();
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<UnixTimestamp>(UnixTimestamp const data) {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const ctx = isolate->GetCurrentContext();

	auto epoch_ms = jval<double>(data.epoch_milliseconds);

	auto const global_this = ctx->Global();
	auto const temporal =
		global_this->Get(ctx, jstr_intern("Temporal")).As<v8::Object>().ToLocalChecked();
	auto const temporalInstant =
		temporal->Get(ctx, jstr_intern("Instant")).As<v8::Object>().ToLocalChecked();
	auto const temporalInstantFrom =
		temporalInstant->Get(ctx, jstr_intern("fromEpochMilliseconds")).As<v8::Function>().ToLocalChecked();

	return temporalInstantFrom->Call(ctx, temporalInstant, 1, &epoch_ms).ToLocalChecked();
}
