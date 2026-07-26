#include <optional>
#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "JtoC.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<AchievementEntry const &>(AchievementEntry const & a) {
	return jobj(
		jprop("id", a.ID),
		jprop("requiredFaction", a.requiredFaction),
		jprop("mapId", a.mapID),
		jprop("name", jarr(a.name)),
		jprop("categoryId", a.categoryId),
		jprop("points", a.points),
		jprop("flags", a.flags),
		jprop("count", a.count),
		jprop("refAchievement", a.refAchievement)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<AchievementEntry const>(AchievementEntry const p) {
	return jval<AchievementEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<AchievementEntry>(AchievementEntry const p) {
	return jval<AchievementEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<AchievementEntry const *>(AchievementEntry const * p) {
	return p ? jval<AchievementEntry const &>(*p) : jnull();
}

template<>
[[nodiscard]] std::optional<AchievementEntry const *> cval<AchievementEntry const *>(v8::Local<v8::Value> const v) {
	return centry_lookup(v, sAchievementStore);
}
