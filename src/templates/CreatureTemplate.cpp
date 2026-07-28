#include <optional>
#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "Creature.h"
#include "CreatureAI.h"
#include "CreatureData.h"
#include "CtoJ.h"
#include "Duration.h"
#include "Group.h"
#include "IteratorPair.h"
#include "MotionMaster.h"
#include "NodePropertySystem.h"
#include "ObjectMgr.h"
#include "ThreatManager.h"
#include "Unit.h"
#include "UnitDefines.h"
#include "UpdateFields.h"

class Player;

JVAL_CVAL_TMPLS_RW(Creature)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Creature *>() {
	TypedTemplate<Creature *> const ft = jctor();

	ft->SetClassName(jstr_intern("Creature"));
	ft.safe_inherit<Unit *>();

	reg_prop_ro(ft, "spawnId", [](Creature * c) {
		return c->GetSpawnId();
	});
	reg_prop_ro(ft, "template", [](Creature * c) {
		return c->GetCreatureTemplate();
	});
	reg_prop_ro(ft, "shieldBlockValue", [](Creature * c) {
		return c->GetShieldBlockValue();
	});
	reg_prop_ro(ft, "isInEvadeMode", [](Creature * c) {
		return c->IsInEvadeMode();
	});
	reg_prop_ro(ft, "isElite", [](Creature * c) {
		// differs from what would be on CreatureTemplateTemplate because it excludes pets.
		return c->isElite();
	});
	reg_prop_ro(ft, "isGuard", [](Creature * c) {
		// probably belongs on CreatureTemplateTemplate instead.
		return c->IsGuard();
	});
	reg_prop_ro(ft, "isCivilian", [](Creature * c) {
		// probably belongs on CreatureTemplateTemplate instead.
		return c->IsCivilian();
	});
	reg_prop_ro(ft, "isRacialLeader", [](Creature * c) {
		// probably belongs on CreatureTemplateTemplate instead.
		return c->IsRacialLeader();
	});
	reg_prop_ro(ft, "isDungeonBoss", [](Creature * c) {
		// differs from what would be on CreatureTemplateTemplate because it excludes owned units.
		return c->IsDungeonBoss();
	});
	reg_prop_ro(ft, "isWorldBoss", [](Creature * c) {
		// differs from what would be on CreatureTemplateTemplate because it excludes pets.
		return c->isWorldBoss();
	});
	reg_prop_ro(ft, "isTrigger", [](Creature * c) {
		// probably belongs on CreatureTemplateTemplate instead.
		return c->IsTrigger();
	});
	reg_prop_ro(ft, "isDamageEnoughForLootingAndReward", [](Creature * c) {
		return c->IsDamageEnoughForLootingAndReward();
	});
	reg_prop_ro(ft, "canSwim", [](Creature * c) {
		return c->CanSwim();
	});
	reg_prop_ro(ft, "canWalk", [](Creature * c) {
		return c->CanWalk();
	});
	reg_prop_ro(ft, "canFly", [](Creature * c) {
		return c->CanFly();
	});
	reg_prop_ro(ft, "hasSearchedAssistance", [](Creature * c) {
		return c->HasSearchedAssistance();
	});
	reg_prop_ro(ft, "hasLootRecipient", [](Creature * c) {
		return c->hasLootRecipient();
	});
	reg_prop_ro(ft, "canAggro", [](Creature * c) {
		return !c->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
	});
	reg_prop_ro(ft, "waypointPath", [](Creature * c) {
		return c->GetWaypointPath();
	});
	reg_prop_ro(ft, "currentWaypointId", [](Creature * c) {
		return c->GetCurrentWaypointID();
	});
	reg_prop_ro(ft, "scriptName", [](Creature * c) {
		return c->GetScriptName();
	});
	reg_prop_ro(ft, "aiName", [](Creature * c) {
		return c->GetAIName();
	});
	reg_prop_ro(ft, "scriptId", [](Creature * c) {
		return c->GetScriptId();
	});
	reg_prop_ro(ft, "lootRecipientGuid", [](Creature * c) {
		return c->GetLootRecipientGUID();
	});
	reg_prop_ro(ft, "lootRecipient", [](Creature * c) {
		return c->GetLootRecipient();
	});
	reg_prop_ro(ft, "lootRecipientGroupId", [](Creature * c) {
		// not actually an ObjectGuid
		return c->GetLootRecipientGroupGUID();
	});
	reg_prop_ro(ft, "lootRecipientGroup", [](Creature * c) {
		return c->GetLootRecipientGroup();
	});
	reg_prop_ro(ft, "homePosition", [](Creature * c) {
		return c->GetHomePosition();
	});

	reg_method(ft, "canCompleteQuest", [](Creature * c, uint32_t quest_id) {
		return c->hasInvolvedQuest(quest_id);
	});
	reg_method(ft, "canAssistTo", [](Creature * c, Unit * fren, Unit * enemy, std::optional<bool> const check_faction) {
		return c->CanAssistTo(fren, enemy, check_faction.value_or(true));
	});
	reg_method(ft, "isTappedBy", [](Creature * c, Player * player) {
		return c->isTappedBy(player);
	});
	reg_method(ft, "isTargetableForAttack", [](Creature * c, std::optional<bool> const must_be_dead, std::optional<Unit *> by_whom) {
		return c->isTargetableForAttack(must_be_dead.value_or(false), by_whom.value_or(nullptr));
	});
	reg_method(ft, "canStartAttack", [](Creature * c, Unit * target, std::optional<bool> force) {
		return c->CanStartAttack(target, force.value_or(false));
	});
	reg_method(ft, "getAggroRange", [](Creature * c, Unit * target) {
		return c->GetAggroRange(target);
	});
	reg_method(ft, "hasSpell", [](Creature * c, uint32_t spell_id) {
		return c->HasSpell(spell_id);
	});
	reg_method(ft, "hasSpellCooldown", [](Creature * c, uint32_t spell_id) {
		return c->HasSpellCooldown(spell_id);
	});
	reg_method(ft, "getSpellCooldown", [](Creature * c, uint32_t spell_id) {
		return c->GetSpellCooldown(spell_id);
	});
	reg_method(ft, "hasQuest", [](Creature * c, uint32_t quest_id) {
		return c->hasQuest(quest_id);
	});
	reg_method(ft, "hasLootMode", [](Creature * c, uint16_t const lootMode) {
		return c->HasLootMode(lootMode);
	});
	reg_method(ft, "getAITargets", [](Creature * c) {
		auto const & threatMgr = c->GetThreatMgr();
		auto const list = threatMgr.GetSortedThreatList();
		return jarr(list.begin(), list.end());
	});
	reg_method(ft, "getAITargetsCount", [](Creature * c) {
		return c->GetThreatMgr().GetThreatListSize();
	});
	reg_method(ft, "setInCombatWithZone", [](Creature * c) {
		if (c->IsAIEnabled) {
			c->AI()->DoZoneInCombat();
		}
	});
	reg_method(ft, "attackStart", [](Creature * c, Unit * target) {
		c->AI()->AttackStart(target);
	});

	reg_prop(ft, "regeneratingHealth",
		[](Creature * c) { return c->isRegeneratingHealth(); },
		[](Creature * c, bool const val) { c->SetRegeneratingHealth(val); }
	);
	reg_prop(ft, "reputationGainDisabled",
		[](Creature * c) { return c->IsReputationRewardDisabled(); },
		[](Creature * c, bool const val) { c->SetReputationRewardDisabled(val); }
	);
	reg_prop(ft, "respawnDelay",
		[](Creature * c) { return c->GetRespawnDelay(); },
		[](Creature * c, uint32_t const val) { c->SetRespawnDelay(val); }
	);
	reg_prop(ft, "wanderRadius",
		[](Creature * c) { return c->GetWanderDistance(); },
		[](Creature * c, float const val) { c->SetWanderDistance(val); }
	);
	reg_prop(ft, "corpseDelay",
		[](Creature * c) { return c->GetCorpseDelay(); },
		[](Creature * c, uint32_t const val) { c->SetCorpseDelay(val); }
	);
	reg_prop(ft, "defaultMovementType",
		[](Creature * c) { return c->GetDefaultMovementType(); },
		[](Creature * c, MovementGeneratorType const val) { c->SetDefaultMovementType(val); }
	);
	reg_prop(ft, "npcFlags",
		[](Creature * c) { return c->GetUInt32Value(UNIT_NPC_FLAGS); },
		[](Creature * c, uint32_t const val) { c->SetUInt32Value(UNIT_NPC_FLAGS, val); }
	);
	reg_prop(ft, "unitFlags",
		[](Creature * c) { return c->GetUInt32Value(UNIT_FIELD_FLAGS); },
		[](Creature * c, uint32_t const val) { c->SetUInt32Value(UNIT_FIELD_FLAGS, val); }
	);
	reg_prop(ft, "unitFlags2",
		[](Creature * c) { return c->GetUInt32Value(UNIT_FIELD_FLAGS_2); },
		[](Creature * c, uint32_t const val) { c->SetUInt32Value(UNIT_FIELD_FLAGS_2, val); }
	);
	reg_prop(ft, "reactState",
		[](Creature * c) { return c->GetReactState(); },
		[](Creature * c, ReactStates const val) { c->SetReactState(val); }
	);
	reg_prop(ft, "lootMode",
		[](Creature * c) { return c->GetLootMode(); },
		[](Creature * c, uint16_t const val) { c->SetLootMode(val); }
	);

	reg_method(ft, "setHomePosition", [](Creature * c, float const x, float const y, float const z, float const o) {
		c->SetHomePosition(x, y, z, o);
	});
	reg_method(ft, "setAggroEnabled", [](Creature * c, std::optional<bool> const allow) {
		if (allow.value_or(true)) {
			c->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
		} else {
			c->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
		}
	});
	reg_method(ft, "setEquipmentSlots", [](Creature * c, uint32_t const mainHand, uint32_t const offHand, uint32_t const ranged) {
		c->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, mainHand);
		c->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, offHand);
		c->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, ranged);
	});
	reg_method(ft, "setNoSearchAssistance", [](Creature * c, std::optional<bool> const val) {
		c->SetNoSearchAssistance(val.value_or(true));
	});
	reg_method(ft, "setNoCallAssistance", [](Creature * c, std::optional<bool> const val) {
		c->SetNoCallAssistance(val.value_or(true));
	});
	reg_method(ft, "despawnOrUnsummon", [](Creature * c, std::optional<uint32_t> const ms_time_to_despawn, std::optional<uint32_t> forced_respawn_timer) {
		c->DespawnOrUnsummon(Milliseconds(ms_time_to_despawn.value_or(0)), Seconds(forced_respawn_timer.value_or(0)));
	});
	reg_method(ft, "respawn", [](Creature * c, std::optional<bool> force) {
		c->Respawn(force.value_or(false));
	});
	reg_method(ft, "removeCorpse", [](Creature * c, std::optional<bool> set_spawn_time, std::optional<bool> skip_visibility) {
		c->RemoveCorpse(set_spawn_time.value_or(true), skip_visibility.value_or(false));
	});
	reg_method(ft, "allLootRemovedFromCorpse", [](Creature * c) {
		c->AllLootRemovedFromCorpse();
	});
	reg_method(ft, "saveToDB", [](Creature * c) {
		c->SaveToDB();
	});
	reg_method(ft, "moveWaypoint", [](Creature * c) {
		c->GetMotionMaster()->MoveWaypoint(c->GetWaypointPath(), true);
	});
	reg_method(ft, "callAssistance", [](Creature * c, std::optional<Unit *> target) {
		c->CallAssistance(target.value_or(nullptr));
	});
	reg_method(ft, "callForHelp", [](Creature * c, float const radius, std::optional<Unit *> target) {
		c->CallForHelp(radius, target.value_or(nullptr));
	});
	reg_method(ft, "fleeToGetAssistance", [](Creature * c) {
		c->DoFleeToGetAssistance();
	});
	reg_method(ft, "selectVictim", [](Creature * c) {
		return c->SelectVictim();
	});
	reg_method(ft, "updateEntry", [](Creature * c, uint32_t const entry, std::optional<uint32_t> const spawn_id, std::optional<bool> change_level, std::optional<bool> update_ai) {
		auto const data = spawn_id ? sObjectMgr->GetCreatureData(spawn_id.value()) : nullptr;
		c->UpdateEntry(entry, data, change_level.value_or(true), update_ai.value_or(false));
	});
	reg_method(ft, "resetLootMode", [](Creature * c) {
		c->ResetLootMode();
	});
	reg_method(ft, "removeLootMode", [](Creature * c, uint16_t const lootMode) {
		c->RemoveLootMode(lootMode);
	});
	reg_method(ft, "addLootMode", [](Creature * c, uint16_t const lootMode) {
		c->AddLootMode(lootMode);
	});

	return ft;
}
