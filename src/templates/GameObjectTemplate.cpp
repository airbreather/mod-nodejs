#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "GameObject.h"
#include "GameObjectData.h"
#include "GameTime.h"
#include "NodePropertySystem.h"
#include "Object.h"
#include "QuestDef.h"

class Unit;

JVAL_CVAL_TMPLS_RW(GameObject)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<GameObject *>() {
	TypedTemplate<GameObject *> const ft = jctor();

	ft->SetClassName(jstr_intern("GameObject"));
	ft.safe_inherit<WorldObject *>();

	reg_prop_ro(ft, "isSpawned", [](GameObject * go) {
		return go->isSpawned();
	});
	reg_prop_ro(ft, "isTransport", [](GameObject * go) {
		return go->IsTransport();
	});
	reg_prop_ro(ft, "isActive", [](GameObject * go) {
		return go->isActiveObject();
	});
	reg_prop_ro(ft, "displayId", [](GameObject * go) {
		return go->GetDisplayId();
	});
	reg_prop_ro(ft, "goState", [](GameObject * go) {
		return go->GetGoState();
	});
	reg_prop_ro(ft, "lootState", [](GameObject * go) {
		return go->getLootState();
	});
	reg_prop_ro(ft, "spawnId", [](GameObject * go) {
		return go->GetSpawnId();
	});
	reg_prop_ro(ft, "lootRecipient", [](GameObject * go) {
		return go->GetLootRecipient();
	});
	reg_prop_ro(ft, "lootRecipientGroup", [](GameObject * go) {
		return go->GetLootRecipientGroup();
	});
	reg_prop_ro(ft, "nextAbsoluteRespawnTime", [](GameObject * go) {
		return go->GetRespawnTimeEx();
	});

	reg_method(ft, "hasQuest", [](GameObject * go, Quest const * quest) {
		return go->hasQuest(quest->GetQuestId());
	});

	reg_prop(ft, "goState",
		[](GameObject * go) { return go->GetGoState(); },
		[](GameObject * go, GOState const go_state) { go->SetGoState(go_state); }
	);
	reg_prop(ft, "nextAbsoluteRespawnTime",
		[](GameObject * go) { return go->GetRespawnTimeEx(); },
		[](GameObject * go, time_t const respawn) { go->SetRespawnTime(static_cast<int32_t>(respawn - GameTime::GetGameTime().count())); }
	);

	reg_method(ft, "setLootState", [](GameObject * go, LootState const state, std::optional<Unit *> const unit) {
		go->SetLootState(state, unit ? *unit : nullptr);
	});
	reg_method(ft, "useDoorOrButton", [](GameObject * go, std::optional<uint32_t> const delay) {
		go->UseDoorOrButton(delay.value_or(0u));
	});
	reg_method(ft, "despawn", [](GameObject * go) {
		go->SetLootState(GO_JUST_DEACTIVATED);
	});
	reg_method(ft, "respawn", [](GameObject * go) {
		go->Respawn();
	});
	reg_method(ft, "setSecondsUntilNextRespawn", [](GameObject * go, int32_t const delay) {
		auto const old_delay = go->GetRespawnDelay();
		go->SetRespawnTime(delay);
		go->SetRespawnDelay(static_cast<int32_t>(old_delay));
	});
	reg_method(ft, "setSecondsBetweenRespawns", [](GameObject * go, int32_t const delay) {
		go->SetRespawnDelay(delay);
	});
	reg_method(ft, "saveToDB", [](GameObject * go) {
		go->SaveToDB();
	});

	return ft;
}
