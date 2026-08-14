#include <optional>
#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "JtoC.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<CharTitlesEntry const &>(CharTitlesEntry const & a) {
	return jobj(
		jprop("id", a.ID),
		jprop("nameMale", jarr(a.nameMale)),
		jprop("nameFemale", jarr(a.nameFemale)),
		jprop("bitIndex", a.bit_index)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<CharTitlesEntry const>(CharTitlesEntry const p) {
	return jval<CharTitlesEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<CharTitlesEntry>(CharTitlesEntry const p) {
	return jval<CharTitlesEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<CharTitlesEntry const *>(CharTitlesEntry const * p) {
	return p ? jval<CharTitlesEntry const &>(*p) : jnull();
}

template<>
[[nodiscard]] std::optional<CharTitlesEntry const *> cval<CharTitlesEntry const *>(v8::Local<v8::Value> const v) {
	return centry_lookup(v, sCharTitlesStore);
}
