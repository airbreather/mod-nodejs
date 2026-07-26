#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "DBCStructure.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<PvPDifficultyEntry const &>(PvPDifficultyEntry const & p) {
	return jobj(
		jprop("mapId", p.mapId),
		jprop("bracketId", p.bracketId),
		jprop("minLevel", p.minLevel),
		jprop("maxLevel", p.maxLevel),
		jprop("difficulty", p.difficulty)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<PvPDifficultyEntry const>(PvPDifficultyEntry const p) {
	return jval<PvPDifficultyEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<PvPDifficultyEntry>(PvPDifficultyEntry const p) {
	return jval<PvPDifficultyEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<PvPDifficultyEntry const *>(PvPDifficultyEntry const * p) {
	return p ? jval<PvPDifficultyEntry const &>(*p) : jnull();
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<PvPDifficultyEntry *>(PvPDifficultyEntry * p) {
	return p ? jval<PvPDifficultyEntry const &>(*p) : jnull();
}
