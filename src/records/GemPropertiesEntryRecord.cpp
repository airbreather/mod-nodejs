#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "DBCStructure.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<GemPropertiesEntry const &>(GemPropertiesEntry const & v) {
	return jobj(
		jprop("id", v.ID),
		jprop("spellItemEnchantment", v.spellitemenchantement),
		jprop("color", v.color)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<GemPropertiesEntry const>(GemPropertiesEntry const v) {
	return jval<GemPropertiesEntry const &>(v);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<GemPropertiesEntry>(GemPropertiesEntry const v) {
	return jval<GemPropertiesEntry const &>(v);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<GemPropertiesEntry const *>(GemPropertiesEntry const * v) {
	return v ? jval<GemPropertiesEntry const &>(*v) : jnull();
}
