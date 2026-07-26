#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "DBCStructure.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellRangeEntry const &>(SpellRangeEntry const & p) {
	return jobj(
		jprop("id", p.ID),
		jprop("minHostile", p.RangeMin[0]),
		jprop("minFriendly", p.RangeMin[1]),
		jprop("maxHostile", p.RangeMax[0]),
		jprop("maxFriendly", p.RangeMax[1]),
		jprop("flags", p.Flags)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellRangeEntry const>(SpellRangeEntry const p) {
	return jval<SpellRangeEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellRangeEntry>(SpellRangeEntry const p) {
	return jval<SpellRangeEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellRangeEntry const *>(SpellRangeEntry const * p) {
	return p ? jval<SpellRangeEntry const &>(*p) : jnull();
}
