#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "DBCStructure.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellRadiusEntry const &>(SpellRadiusEntry const & p) {
	return jobj(
		jprop("id", p.ID),
		jprop("radiusMin", p.RadiusMin),
		jprop("radiusPerLevel", p.RadiusPerLevel),
		jprop("radiusMax", p.RadiusMax)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellRadiusEntry const>(SpellRadiusEntry const p) {
	return jval<SpellRadiusEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellRadiusEntry>(SpellRadiusEntry const p) {
	return jval<SpellRadiusEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellRadiusEntry const *>(SpellRadiusEntry const * p) {
	return p ? jval<SpellRadiusEntry const &>(*p) : jnull();
}
