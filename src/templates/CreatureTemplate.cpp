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
#include "QuestDef.h"
#include "SpellInfo.h"
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

	reg_prop_ro(ft, "spawnId", [](Creature * creature) {
		return creature->GetSpawnId();
	});
	reg_prop_ro(ft, "rank", [](Creature * creature) {
		return creature->GetCreatureTemplate()->rank;
	});
	reg_prop_ro(ft, "shieldBlockValue", [](Creature * creature) {
		return creature->GetShieldBlockValue();
	});
	reg_prop_ro(ft, "creatureFamily", [](Creature * creature) {
		auto const entry = creature->GetEntry();
		auto const cInfo = sObjectMgr->GetCreatureTemplate(entry);
		return cInfo ? cInfo->family : 0u;
	});
	reg_prop_ro(ft, "extraFlags", [](Creature * creature) {
		return creature->GetCreatureTemplate()->flags_extra;
	});
	reg_prop_ro(ft, "isInEvadeMode", [](Creature * creature) {
		return creature->IsInEvadeMode();
	});
	reg_prop_ro(ft, "isElite", [](Creature * creature) {
		return creature->isElite();
	});
	reg_prop_ro(ft, "isGuard", [](Creature * creature) {
		return creature->IsGuard();
	});
	reg_prop_ro(ft, "isCivilian", [](Creature * creature) {
		return creature->IsCivilian();
	});
	reg_prop_ro(ft, "isRacialLeader", [](Creature * creature) {
		return creature->IsRacialLeader();
	});
	reg_prop_ro(ft, "isDungeonBoss", [](Creature * creature) {
		return creature->IsDungeonBoss();
	});
	reg_prop_ro(ft, "isWorldBoss", [](Creature * creature) {
		return creature->isWorldBoss();
	});
	reg_prop_ro(ft, "isTrigger", [](Creature * creature) {
		return creature->IsTrigger();
	});
	reg_prop_ro(ft, "isDamageEnoughForLootingAndReward", [](Creature * creature) {
		return creature->IsDamageEnoughForLootingAndReward();
	});
	reg_prop_ro(ft, "canSwim", [](Creature * creature) {
		return creature->CanSwim();
	});
	reg_prop_ro(ft, "canWalk", [](Creature * creature) {
		return creature->CanWalk();
	});
	reg_prop_ro(ft, "canFly", [](Creature * creature) {
		return creature->CanFly();
	});
	reg_prop_ro(ft, "hasSearchedAssistance", [](Creature * creature) {
		return creature->HasSearchedAssistance();
	});
	reg_prop_ro(ft, "hasLootRecipient", [](Creature * creature) {
		return creature->hasLootRecipient();
	});
	reg_prop_ro(ft, "canAggro", [](Creature * creature) {
		return !creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
	});
	reg_prop_ro(ft, "waypointPath", [](Creature * creature) {
		return creature->GetWaypointPath();
	});
	reg_prop_ro(ft, "currentWaypointId", [](Creature * creature) {
		return creature->GetCurrentWaypointID();
	});
	reg_prop_ro(ft, "scriptName", [](Creature * creature) {
		return creature->GetScriptName();
	});
	reg_prop_ro(ft, "aiName", [](Creature * creature) {
		return creature->GetAIName();
	});
	reg_prop_ro(ft, "scriptId", [](Creature * creature) {
		return creature->GetScriptId();
	});
	reg_prop_ro(ft, "lootRecipient", [](Creature * creature) {
		return creature->GetLootRecipient();
	});
	reg_prop_ro(ft, "lootRecipientGroup", [](Creature * creature) {
		return creature->GetLootRecipientGroup();
	});
	reg_prop_ro(ft, "homePosition", [](Creature * creature) {
		return creature->GetHomePosition();
	});

	reg_method(ft, "canCompleteQuest", [](Creature * creature, Quest const * quest) {
		return creature->hasInvolvedQuest(quest->GetQuestId());
	});
	reg_method(ft, "canAssistTo", [](Creature * creature, Unit * fren, Unit * enemy, std::optional<bool> const checkFaction) {
		return creature->CanAssistTo(fren, enemy, checkFaction.value_or(true));
	});
	reg_method(ft, "isTappedBy", [](Creature * creature, Player * player) {
		return creature->isTappedBy(player);
	});
	reg_method(ft, "isTargetableForAttack", [](Creature * creature, std::optional<bool> const mustBeDead) {
		return creature->isTargetableForAttack(mustBeDead.value_or(false));
	});
	reg_method(ft, "canStartAttack", [](Creature * creature, Unit * target) {
		return creature->CanStartAttack(target);
	});
	reg_method(ft, "getAggroRange", [](Creature * creature, Unit * target) {
		return creature->GetAggroRange(target);
	});
	reg_method(ft, "hasSpell", [](Creature * creature, SpellInfo const * si) {
		return creature->HasSpell(si->Id);
	});
	reg_method(ft, "hasSpellCooldown", [](Creature * creature, SpellInfo const * si) {
		return creature->HasSpellCooldown(si->Id);
	});
	reg_method(ft, "hasCategoryCooldown", [](Creature * creature, SpellInfo const * si) {
		return si->GetCategory() && creature->HasSpellCooldown(si->Id);
	});
	reg_method(ft, "getSpellCooldownDelayMilliseconds", [](Creature * creature, SpellInfo const * si) {
		return creature->GetSpellCooldown(si->Id);
	});
	reg_method(ft, "hasQuest", [](Creature * creature, Quest const * quest) {
		return creature->hasQuest(quest->GetQuestId());
	});
	reg_method(ft, "hasLootMode", [](Creature * creature, uint16_t const lootMode) {
		return creature->HasLootMode(lootMode);
	});
	reg_method(ft, "getAITargets", [](Creature * creature) {
		auto const & threatMgr = creature->GetThreatMgr();
		auto const list = threatMgr.GetSortedThreatList();
		return jarr(list.begin(), list.end());
	});
	reg_method(ft, "getAITargetsCount", [](Creature * creature) {
		return creature->GetThreatMgr().GetThreatListSize();
	});
	reg_method(ft, "setInCombatWithZone", [](Creature * creature) {
		if (creature->IsAIEnabled) {
			creature->AI()->DoZoneInCombat();
		}
	});
	reg_method(ft, "attackStart", [](Creature * creature, Unit * target) {
		creature->AI()->AttackStart(target);
	});

	reg_prop(ft, "regeneratingHealth",
		[](Creature * creature) { return creature->isRegeneratingHealth(); },
		[](Creature * creature, bool const val) { creature->SetRegeneratingHealth(val); }
	);
	reg_prop(ft, "reputationGainDisabled",
		[](Creature * creature) { return creature->IsReputationRewardDisabled(); },
		[](Creature * creature, bool const val) { creature->SetReputationRewardDisabled(val); }
	);
	reg_prop(ft, "respawnDelay",
		[](Creature * creature) { return creature->GetRespawnDelay(); },
		[](Creature * creature, uint32_t const val) { creature->SetRespawnDelay(val); }
	);
	reg_prop(ft, "wanderRadius",
		[](Creature * creature) { return creature->GetWanderDistance(); },
		[](Creature * creature, float const val) { creature->SetWanderDistance(val); }
	);
	reg_prop(ft, "corpseDelay",
		[](Creature * creature) { return creature->GetCorpseDelay(); },
		[](Creature * creature, uint32_t const val) { creature->SetCorpseDelay(val); }
	);
	reg_prop(ft, "defaultMovementType",
		[](Creature * creature) { return creature->GetDefaultMovementType(); },
		[](Creature * creature, MovementGeneratorType const val) { creature->SetDefaultMovementType(val); }
	);
	reg_prop(ft, "npcFlags",
		[](Creature * creature) { return creature->GetUInt32Value(UNIT_NPC_FLAGS); },
		[](Creature * creature, uint32_t const val) { creature->SetUInt32Value(UNIT_NPC_FLAGS, val); }
	);
	reg_prop(ft, "unitFlags",
		[](Creature * creature) { return creature->GetUInt32Value(UNIT_FIELD_FLAGS); },
		[](Creature * creature, uint32_t const val) { creature->SetUInt32Value(UNIT_FIELD_FLAGS, val); }
	);
	reg_prop(ft, "unitFlags2",
		[](Creature * creature) { return creature->GetUInt32Value(UNIT_FIELD_FLAGS_2); },
		[](Creature * creature, uint32_t const val) { creature->SetUInt32Value(UNIT_FIELD_FLAGS_2, val); }
	);
	reg_prop(ft, "reactState",
		[](Creature * creature) { return creature->GetReactState(); },
		[](Creature * creature, ReactStates const val) { creature->SetReactState(val); }
	);
	reg_prop(ft, "lootMode",
		[](Creature * creature) { return creature->GetLootMode(); },
		[](Creature * creature, uint16_t const val) { creature->SetLootMode(val); }
	);

	reg_method(ft, "setHomePosition", [](Creature * creature, float const x, float const y, float const z, float const o) {
		creature->SetHomePosition(x, y, z, o);
	});
	reg_method(ft, "setAggroEnabled", [](Creature * creature, std::optional<bool> const allow) {
		if (allow.value_or(true)) {
			creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
		} else {
			creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
		}
	});
	reg_method(ft, "setEquipmentSlots", [](Creature * creature, uint32_t const mainHand, uint32_t const offHand, uint32_t const ranged) {
		creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, mainHand);
		creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, offHand);
		creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, ranged);
	});
	reg_method(ft, "setNoSearchAssistance", [](Creature * creature, std::optional<bool> const val) {
		creature->SetNoSearchAssistance(val.value_or(true));
	});
	reg_method(ft, "setNoCallAssistance", [](Creature * creature, std::optional<bool> const val) {
		creature->SetNoCallAssistance(val.value_or(true));
	});
	reg_method(ft, "despawnOrUnsummon", [](Creature * creature, std::optional<uint32_t> const ms) {
		creature->DespawnOrUnsummon(Milliseconds(ms.value_or(0)));
	});
	reg_method(ft, "respawn", [](Creature * creature) {
		creature->Respawn();
	});
	reg_method(ft, "removeCorpse", [](Creature * creature) {
		creature->RemoveCorpse();
	});
	reg_method(ft, "allLootRemovedFromCorpse", [](Creature * creature) {
		creature->AllLootRemovedFromCorpse();
	});
	reg_method(ft, "saveToDB", [](Creature * creature) {
		creature->SaveToDB();
	});
	reg_method(ft, "moveWaypoint", [](Creature * creature) {
		creature->GetMotionMaster()->MoveWaypoint(creature->GetWaypointPath(), true);
	});
	reg_method(ft, "callAssistance", [](Creature * creature) {
		creature->CallAssistance();
	});
	reg_method(ft, "callForHelp", [](Creature * creature, float const radius) {
		creature->CallForHelp(radius);
	});
	reg_method(ft, "fleeToGetAssistance", [](Creature * creature) {
		creature->DoFleeToGetAssistance();
	});
	reg_method(ft, "selectVictim", [](Creature * creature) {
		return creature->SelectVictim();
	});
	reg_method(ft, "updateEntry", [](Creature * creature, uint32_t const entry, std::optional<uint32_t> const spawn_id, std::optional<bool> change_level, std::optional<bool> update_ai) {
		auto const data = spawn_id ? sObjectMgr->GetCreatureData(spawn_id.value()) : nullptr;
		creature->UpdateEntry(entry, data, change_level.value_or(true), update_ai.value_or(false));
	});
	reg_method(ft, "resetLootMode", [](Creature * creature) {
		creature->ResetLootMode();
	});
	reg_method(ft, "removeLootMode", [](Creature * creature, uint16_t const lootMode) {
		creature->RemoveLootMode(lootMode);
	});
	reg_method(ft, "addLootMode", [](Creature * creature, uint16_t const lootMode) {
		creature->AddLootMode(lootMode);
	});

	return ft;
}
