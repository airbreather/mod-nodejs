#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "DBCStructure.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellCategoryEntry const &>(SpellCategoryEntry const & p) {
	return jobj(
		jprop("id", p.Id),
		jprop("flags", p.Flags)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellCategoryEntry const>(SpellCategoryEntry const p) {
	return jval<SpellCategoryEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellCategoryEntry>(SpellCategoryEntry const p) {
	return jval<SpellCategoryEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellCategoryEntry const *>(SpellCategoryEntry const * p) {
	return p ? jval<SpellCategoryEntry const &>(*p) : jnull();
}
