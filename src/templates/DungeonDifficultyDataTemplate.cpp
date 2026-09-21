#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using DungeonDifficultyData = decltype(GameObjectTemplate().dungeonDifficulty);
JVAL_CVAL_TMPLS_RO(DungeonDifficultyData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<DungeonDifficultyData const *>() {
	TypedTemplate<DungeonDifficultyData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("DungeonDifficultyData"));

	reg_prop_ro(ft, "mapId", [](DungeonDifficultyData const * d) {
		return d->mapID;
	});
	reg_prop_ro(ft, "difficulty", [](DungeonDifficultyData const * d) {
		return d->difficulty;
	});

	return ft;
}
