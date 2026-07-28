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
#include "UnixTimestamp.h"

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
	reg_prop_ro(ft, "lootState", [](GameObject * go) {
		return go->getLootState();
	});
	reg_prop_ro(ft, "spawnId", [](GameObject * go) {
		return go->GetSpawnId();
	});
	// reg_prop_ro(ft, "lootRecipientGuid", [](GameObject * go) {
	// 	return go->GetLootRecipientGUID();
	// });
	reg_prop_ro(ft, "lootRecipient", [](GameObject * go) {
		return go->GetLootRecipient();
	});
	// reg_prop_ro(ft, "lootRecipientGroupId", [](GameObject * go) {
	// 	return go->GetLootRecipientGroupGUID();
	// });
	reg_prop_ro(ft, "lootRecipientGroup", [](GameObject * go) {
		return go->GetLootRecipientGroup();
	});

	reg_method(ft, "hasQuest", [](GameObject * go, Quest const * quest) {
		return go->hasQuest(quest->GetQuestId());
	});

	reg_prop(ft, "goState",
		[](GameObject * go) { return go->GetGoState(); },
		[](GameObject * go, GOState const go_state) { go->SetGoState(go_state); }
	);
	reg_prop(ft, "nextAbsoluteRespawnTime",
		[](GameObject * go) { return UnixTimestamp::from_time_t_seconds(go->GetRespawnTimeEx()); },
		[](GameObject * go, UnixTimestamp const respawn) {
			// set ONLY the NEXT respawn time without modifying the delay between future respawns.
			auto const old_delay = go->GetRespawnDelay();
			go->SetRespawnTime(static_cast<int32_t>(respawn.to_time_t_seconds() - GameTime::GetGameTime().count()));
			go->SetRespawnDelay(static_cast<int32_t>(old_delay));
		}
	);
	reg_prop(ft, "ownerGuid",
		[](GameObject * go) { return go->GetOwnerGUID(); },
		[](GameObject * go, ObjectGuid g) { go->SetOwnerGUID(g); }
	);
	reg_prop(ft, "spellId",
		[](GameObject * go) { return go->GetSpellId(); },
		[](GameObject * go, uint32_t id) { go->SetSpellId(id); }
	);
	reg_prop(ft, "isSpawnedByDefault",
		[](GameObject * go) { return go->isSpawnedByDefault(); },
		[](GameObject * go, bool spawned) { go->SetSpawnedByDefault(spawned); }
	);

	reg_method(ft, "setLootState", [](GameObject * go, LootState const state, std::optional<Unit *> const unit) {
		go->SetLootState(state, unit ? *unit : nullptr);
	});
	reg_method(ft, "useDoorOrButton", [](GameObject * go, std::optional<uint32_t> const time_to_restore, std::optional<bool> alternative, std::optional<Unit *> user) {
		go->UseDoorOrButton(time_to_restore.value_or(0), alternative.value_or(false), user.value_or(nullptr));
	});
	reg_method(ft, "despawn", [](GameObject * go) {
		go->SetLootState(GO_JUST_DEACTIVATED);
	});
	reg_method(ft, "despawnOrUnsummon", [](GameObject * go, std::optional<uint32_t> const ms_time_to_despawn, std::optional<uint32_t> forced_respawn_timer) {
		go->DespawnOrUnsummon(Milliseconds(ms_time_to_despawn.value_or(0)), Seconds(forced_respawn_timer.value_or(0)));
	});
	reg_method(ft, "respawn", [](GameObject * go) {
		go->Respawn();
	});
	reg_method(ft, "refresh", [](GameObject * go) {
		go->Refresh();
	});
	reg_method(ft, "setSecondsUntilNextRespawn", [](GameObject * go, int32_t const delay) {
		// set ONLY the NEXT respawn time without modifying the delay between future respawns.
		auto const old_delay = go->GetRespawnDelay();
		go->SetRespawnTime(delay);
		go->SetRespawnDelay(static_cast<int32_t>(old_delay));
	});
	reg_method(ft, "setSecondsBetweenRespawns", [](GameObject * go, int32_t const delay) {
		go->SetRespawnDelay(delay);
	});
	reg_method(ft, "saveToDB", [](GameObject * go, std::optional<bool> save_addon) {
		go->SaveToDB(save_addon.value_or(false));
	});
	reg_method(ft, "saveToDBExtra", [](GameObject * go, uint32_t map_id, uint8_t spawn_mask, uint32_t phase_mask, std::optional<bool> save_addon) {
		go->SaveToDB(map_id, spawn_mask, phase_mask, save_addon.value_or(false));
	});
	reg_method(ft, "delete", [](GameObject * go) {
		go->Delete();
	});
	reg_method(ft, "deleteFromDB", [](GameObject * go) {
		go->DeleteFromDB();
	});
	reg_method(ft, "getFishLoot", [](GameObject * go, Player * loot_owner, std::optional<bool> junk) {
		auto loot = new Loot();
		go->GetFishLoot(loot, loot_owner, junk.value_or(false));
		return jmove(loot);
	});
	// TODO: there's a LOT more that GameObject has on it which seems VERY potentially useful.
	// just scanning through the first several:
	// - GetDynamicFlags and related
	// - GetGOInfo
	// - GetTemplateAddon
	// - GetGameObjectData
	// - GetGOValue
	// - IsTransport
	// - IsDestructibleBuilding
	// - SetWorldRotationAngles
	// - Get/SetWorldRotation
	// - SetTransportPathRotation
	// - GetPackedWorldRotation
	// - GetFinalWorldRotation
	// - LoadGameObjectFromDB (probably static method) and related like SaveToDB overloads.

	return ft;
}
