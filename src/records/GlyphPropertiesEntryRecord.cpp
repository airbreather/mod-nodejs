#include <optional>
#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "JtoC.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<GlyphPropertiesEntry const &>(GlyphPropertiesEntry const & a) {
	return jobj(
		jprop("id", a.Id),
		jprop("spellId", a.SpellId),
		jprop("typeFlags", a.TypeFlags)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<GlyphPropertiesEntry const>(GlyphPropertiesEntry const p) {
	return jval<GlyphPropertiesEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<GlyphPropertiesEntry>(GlyphPropertiesEntry const p) {
	return jval<GlyphPropertiesEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<GlyphPropertiesEntry const *>(GlyphPropertiesEntry const * p) {
	return p ? jval<GlyphPropertiesEntry const &>(*p) : jnull();
}

template<>
[[nodiscard]] std::optional<GlyphPropertiesEntry const *> cval<GlyphPropertiesEntry const *>(v8::Local<v8::Value> const v) {
	return centry_lookup(v, sGlyphPropertiesStore);
}
