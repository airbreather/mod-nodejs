#include "DBCStores.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(AchievementEntry const);

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<AchievementEntry const *>() {
	TypedTemplate<AchievementEntry const *> const ft = jctor();

	ft->SetClassName(jstr_intern("AchievementEntry"));

	reg_static_method(ft, "byId", [](uint32_t const id) {
		return sAchievementStore.LookupEntry(id);
	});

	reg_prop_ro(ft, "id", [](AchievementEntry const * a) {
		return a->ID;
	});
	reg_prop_ro(ft, "requiredFaction", [](AchievementEntry const * a) {
		return a->requiredFaction;
	});
	reg_prop_ro(ft, "mapId", [](AchievementEntry const * a) {
		return a->mapID;
	});
	reg_prop_ro(ft, "name", [](AchievementEntry const * a) {
		return jarr(a->name);
	});
	reg_prop_ro(ft, "categoryId", [](AchievementEntry const * a) {
		return a->categoryId;
	});
	reg_prop_ro(ft, "points", [](AchievementEntry const * a) {
		return a->points;
	});
	reg_prop_ro(ft, "flags", [](AchievementEntry const * a) {
		return a->flags;
	});
	reg_prop_ro(ft, "count", [](AchievementEntry const * a) {
		return a->count;
	});
	reg_prop_ro(ft, "refAchievement", [](AchievementEntry const * a) {
		return a->refAchievement;
	});

	return ft;
}
