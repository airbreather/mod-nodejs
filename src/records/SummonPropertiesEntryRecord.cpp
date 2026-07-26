#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "DBCStructure.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SummonPropertiesEntry const &>(SummonPropertiesEntry const & p) {
	return jobj(
		jprop("id", p.Id),
		jprop("category", p.Category),
		jprop("faction", p.Faction),
		jprop("type", p.Type),
		jprop("slot", p.Slot),
		jprop("flags", p.Flags)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SummonPropertiesEntry const>(SummonPropertiesEntry const p) {
	return jval<SummonPropertiesEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SummonPropertiesEntry>(SummonPropertiesEntry const p) {
	return jval<SummonPropertiesEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SummonPropertiesEntry const *>(SummonPropertiesEntry const * p) {
	return p ? jval<SummonPropertiesEntry const &>(*p) : jnull();
}
