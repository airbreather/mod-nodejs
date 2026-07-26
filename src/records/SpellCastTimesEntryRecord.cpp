#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "DBCStructure.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellCastTimesEntry const &>(SpellCastTimesEntry const & p) {
	return jobj(
		jprop("id", p.ID),
		jprop("flags", p.CastTime)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellCastTimesEntry const>(SpellCastTimesEntry const p) {
	return jval<SpellCastTimesEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellCastTimesEntry>(SpellCastTimesEntry const p) {
	return jval<SpellCastTimesEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellCastTimesEntry const *>(SpellCastTimesEntry const * p) {
	return p ? jval<SpellCastTimesEntry const &>(*p) : jnull();
}
