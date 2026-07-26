#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "ItemTemplate.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_Damage const &>(_Damage const & v) {
	return jobj(
		jprop("min", v.DamageMin),
		jprop("max", v.DamageMax),
		jprop("type", v.DamageType)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_Damage const>(_Damage const v) {
	return jval<_Damage const &>(v);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_Damage>(_Damage const v) {
	return jval<_Damage const &>(v);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_Damage const *>(_Damage const * v) {
	return v ? jval<_Damage const &>(*v) : jnull();
}
