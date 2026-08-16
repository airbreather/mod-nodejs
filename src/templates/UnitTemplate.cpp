#include <optional>
#include <string>
#include <unordered_map>
#include <v8-local-handle.h>
#include <v8-template.h>
#include <vector>

#include "CastSpellBuilder.h"
#include "Cell.h"
#include "Chat.h"
#include "CtoJ.h"
#include "DBCStores.h"
#include "DurationWrapper.h"
#include "GridNotifiers.h"
#include "MotionMaster.h"
#include "NodePropertySystem.h"
#include "Object.h"
#include "ObjectGuid.h"
#include "Player.h"
#include "SharedDefines.h"
#include "Spell.h"
#include "SpellAuraDefines.h"
#include "SpellInfo.h"
#include "ThreatManager.h"
#include "Unit.h"
#include "UnitDefines.h"
#include "UpdateFields.h"
#include "WorldPacket.h"
#include "WorldSession.h"

JVAL_CVAL_TMPLS_RW(Unit)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Unit *>() {
	TypedTemplate<Unit *> const ft = jctor();

	ft->SetClassName(jstr_intern("Unit"));
	ft.safe_inherit<WorldObject *>();

	reg_prop_ro(ft, "gender", [](Unit * u) {
		return u->getGender();
	});
	reg_prop_ro(ft, "creatureType", [](Unit * u) {
		return u->GetCreatureType();
	});
	reg_prop_ro(ft, "healthPct", [](Unit * u) {
		return u->GetHealthPct();
	});
	reg_prop_ro(ft, "movementType", [](Unit * u) {
		return u->GetMotionMaster()->GetCurrentMovementGeneratorType();
	});
	reg_prop_ro(ft, "mountId", [](Unit * u) {
		return u->GetMountID();
	});
	reg_prop_ro(ft, "vehicle", [](Unit * u) {
		return u->GetVehicleKit();
	});
	reg_prop_ro(ft, "isDying", [](Unit * u) {
		return u->GetHealth() == 0;
	});
	reg_prop_ro(ft, "victim", [](Unit * u) {
		return u->GetVictim();
	});
	reg_prop_ro(ft, "isAttackingPlayer", [](Unit * u) {
		return u->isAttackingPlayer();
	});
	reg_prop_ro(ft, "isStandState", [](Unit * u) {
		return u->IsStandState();
	});
	reg_prop_ro(ft, "charmGuid", [](Unit * u) {
		return u->GetCharmGUID();
	});
	reg_prop_ro(ft, "charmerGuid", [](Unit * u) {
		return u->GetCharmerGUID();
	});
	reg_prop_ro(ft, "charmerOrOwnerGuid", [](Unit * u) {
		return u->GetCharmerOrOwnerGUID();
	});
	reg_prop_ro(ft, "charmerOrOwnerOrOwnGuid", [](Unit * u) {
		return u->GetCharmerOrOwnerOrOwnGUID();
	});
	reg_prop_ro(ft, "owner", [](Unit * u) {
		// ...why does Pet shadow Minion's perfectly usable GetOwner()?
		// ...why does Minion shadow Unit's perfectly usable GetOwner()?
		return u->GetOwner();
	});
	reg_prop_ro(ft, "followAngle", [](Unit * u) {
		return u->GetFollowAngle();
	});
	reg_prop_ro(ft, "isAlive", [](Unit * u) {
		return u->IsAlive();
	});
	reg_prop_ro(ft, "isDead", [](Unit * u) {
		return !u->IsAlive();
	});
	reg_prop_ro(ft, "isInCombat", [](Unit * u) {
		return u->IsInCombat();
	});
	reg_prop_ro(ft, "isMounted", [](Unit * u) {
		return u->IsMounted();
	});
	reg_prop_ro(ft, "isInWater", [](Unit * u) {
		return u->IsInWater();
	});
	reg_prop_ro(ft, "isUnderWater", [](Unit * u) {
		return u->IsUnderWater();
	});
	reg_prop_ro(ft, "isFlying", [](Unit * u) {
		return u->IsFlying();
	});
	reg_prop_ro(ft, "isFalling", [](Unit * u) {
		return u->IsFalling();
	});
	reg_prop_ro(ft, "isStopped", [](Unit * u) {
		return u->IsStopped();
	});
	reg_prop_ro(ft, "isCharmed", [](Unit * u) {
		return u->IsCharmed();
	});
	reg_prop_ro(ft, "isFullHealth", [](Unit * u) {
		return u->IsFullHealth();
	});
	reg_prop_ro(ft, "isPvP", [](Unit * u) {
		return u->IsPvP();
	});
	reg_prop_ro(ft, "isOnVehicle", [](Unit * u) {
		return u->GetVehicle() != nullptr;
	});
	reg_prop_ro(ft, "isArmorer", [](Unit * u) {
		return u->IsArmorer();
	});
	reg_prop_ro(ft, "isAuctioneer", [](Unit * u) {
		return u->IsAuctioner();
	});
	reg_prop_ro(ft, "isBanker", [](Unit * u) {
		return u->IsBanker();
	});
	reg_prop_ro(ft, "isBattleMaster", [](Unit * u) {
		return u->IsBattleMaster();
	});
	reg_prop_ro(ft, "isGossip", [](Unit * u) {
		return u->IsGossip();
	});
	reg_prop_ro(ft, "isGuildMaster", [](Unit * u) {
		return u->IsGuildMaster();
	});
	reg_prop_ro(ft, "isInnkeeper", [](Unit * u) {
		return u->IsInnkeeper();
	});
	reg_prop_ro(ft, "isQuestGiver", [](Unit * u) {
		return u->IsQuestGiver();
	});
	reg_prop_ro(ft, "isServiceProvider", [](Unit * u) {
		return u->IsServiceProvider();
	});
	reg_prop_ro(ft, "isSpiritGuide", [](Unit * u) {
		return u->IsSpiritGuide();
	});
	reg_prop_ro(ft, "isSpiritHealer", [](Unit * u) {
		return u->IsSpiritHealer();
	});
	reg_prop_ro(ft, "isSpiritService", [](Unit * u) {
		return u->IsSpiritService();
	});
	reg_prop_ro(ft, "isTabardDesigner", [](Unit * u) {
		return u->IsTabardDesigner();
	});
	reg_prop_ro(ft, "isTaxi", [](Unit * u) {
		return u->IsTaxi();
	});
	reg_prop_ro(ft, "isTrainer", [](Unit * u) {
		return u->IsTrainer();
	});
	reg_prop_ro(ft, "isVendor", [](Unit * u) {
		return u->IsVendor();
	});
	reg_prop_ro(ft, "comboTarget", [](Unit * u) {
		return u->GetComboTarget();
	});
	reg_prop_ro(ft, "isMoving", [](Unit * u) {
		return u->HasUnitState(UNIT_STATE_MOVING);
	});
	reg_prop_ro(ft, "comboPoints", [](Unit * u) {
		return u->GetComboPoints();
	});
	reg_prop_ro(ft, "attackers", [](Unit * u) {
		return jarr(u->getAttackers());
	});
	reg_prop_ro(ft, "unorderedThreatList", [](Unit * u) {
		return jarr(u->GetThreatMgr().GetThreatenedByMeList() | std::ranges::views::values);
	});
	reg_prop_ro(ft, "hasIncreaseMountedFlightSpeedAura", [](Unit * u) {
		return u->HasIncreaseMountedFlightSpeedAura();
	});
	reg_prop_ro(ft, "hasFlyAura", [](Unit * u) {
		return u->HasFlyAura();
	});

	reg_method(ft, "getCurrentSpell", [](Unit * u, std::optional<CurrentSpellTypes> spell_type) {
		return u->GetCurrentSpell(spell_type.value_or(CURRENT_MELEE_SPELL));
	});
	reg_method(ft, "isNonMeleeSpellCast", [](Unit * u, bool with_delayed, std::optional<bool> skip_channeled, std::optional<bool> skip_autorepeat, std::optional<bool> is_autoshoot, std::optional<bool> skip_instant) {
		return u->IsNonMeleeSpellCast(
			with_delayed,
			skip_channeled.value_or(false),
			skip_autorepeat.value_or(false),
			is_autoshoot.value_or(false),
			skip_instant.value_or(true)
		);
	});
	reg_method(ft, "getComboPointsOn", [](Unit * u, Unit * who) {
		return u->GetComboPoints(who);
	});
	reg_method(ft, "getAura", [](Unit * u, uint32_t spell_id, std::optional<ObjectGuid> caster, std::optional<ObjectGuid> item_caster, std::optional<uint8_t> required_effect_mask) {
		return u->GetAura(spell_id, caster.value_or(ObjectGuid::Empty), item_caster.value_or(ObjectGuid::Empty), required_effect_mask.value_or(0));
	});
	reg_method(ft, "getStat", [](Unit * u, Stats const stat) {
		return u->GetStat(stat);
	});
	reg_method(ft, "getPower", [](Unit * u, Powers const pType) {
		return u->GetPower(pType);
	});
	reg_method(ft, "getMaxPower", [](Unit * u, Powers const pType) {
		return u->GetMaxPower(pType);
	});
	reg_method(ft, "getPowerPct", [](Unit * u, Powers const pType) {
		auto const max = u->GetMaxPower(pType);
		return max > 0 ? u->GetPower(pType) * 100.0 / max : 0;
	});
	reg_method(ft, "getSpeed", [](Unit * u, UnitMoveType const mType) {
		return u->GetSpeed(mType);
	});
	reg_method(ft, "getSpeedRate", [](Unit * u, UnitMoveType const mType) {
		return u->GetSpeedRate(mType);
	});
	reg_method(ft, "getThreat", [](Unit * u, Unit * target, std::optional<bool> include_offline) {
		return u->GetThreatMgr().GetThreat(target, include_offline.value_or(false));
	});
	reg_method(ft, "isInAccessiblePlaceFor", [](Unit * u, Creature const * creature) {
		return u->isInAccessiblePlaceFor(creature);
	});
	reg_method(ft, "getFriendlyUnitsInRange", [](Unit * u, float const range) {
		std::vector<Unit *> list;
		Acore::AnyFriendlyUnitInObjectRangeCheck checker(u, u, range);
		Acore::UnitListSearcher searcher(u, list, checker);
		Cell::VisitObjects(u, searcher, range);
		return jarr(list);
	});
	reg_method(ft, "getUnfriendlyUnitsInRange", [](Unit * u, float const range) {
		std::vector<Unit *> list;
		Acore::AnyUnfriendlyUnitInObjectRangeCheck checker(u, u, range);
		Acore::UnitListSearcher searcher(u, list, checker);
		Cell::VisitObjects(u, searcher, range);
		return jarr(list);
	});
	reg_method(ft, "hasAura", [](Unit * u, uint32_t spell_id, std::optional<ObjectGuid> caster, std::optional<ObjectGuid> item_caster, std::optional<uint8_t> required_effect_mask) {
		return u->HasAura(spell_id, caster.value_or(ObjectGuid::Empty), item_caster.value_or(ObjectGuid::Empty), required_effect_mask.value_or(0));
	});
	reg_method(ft, "healthAbovePct", [](Unit * u, int32_t const pct) {
		return u->HealthAbovePct(pct);
	});
	reg_method(ft, "healthBelowPct", [](Unit * u, int32_t const pct) {
		return u->HealthBelowPct(pct);
	});
	reg_method(ft, "countPctFromCurHealth", [](Unit * u, int32_t const amount) {
		return u->CountPctFromCurHealth(amount);
	});
	reg_method(ft, "countPctFromMaxHealth", [](Unit * u, int32_t const amount) {
		return u->CountPctFromMaxHealth(amount);
	});
	reg_method(ft, "getBaseSpellPower", [](Unit * u, SpellSchools const spell_school) {
		return u->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + static_cast<uint64_t>(spell_school));
	});
	reg_method(ft, "hasUnitState", [](Unit * u, UnitState const state) {
		return u->HasUnitState(state);
	});
	reg_method(ft, "sendChatMessageToPlayer", [](Unit * u, ChatMsg const type, Language const lang, std::string const msg, Player * target) {
		WorldPacket data;
		ChatHandler::BuildChatPacket(data, type, lang, u, target, msg);
		target->GetSession()->SendPacket(&data);
	});

	reg_prop(ft, "faction",
		[](Unit * u) { return u->GetFaction(); },
		[](Unit * u, uint32_t const val) { u->SetFaction(val); }
	);
	reg_prop(ft, "health",
		[](Unit * u) { return u->GetHealth(); },
		[](Unit * u, uint32_t const val) { u->SetHealth(val); }
	);
	reg_prop(ft, "maxHealth",
		[](Unit * u) { return u->GetMaxHealth(); },
		[](Unit * u, uint32_t const val) { u->SetMaxHealth(val); }
	);
	reg_prop(ft, "displayId",
		[](Unit * unit) { return unit->GetDisplayId(); },
		[](Unit * unit, uint32_t const id) { unit->SetDisplayId(id); }
	);
	reg_prop(ft, "nativeDisplayId",
		[](Unit * u) { return u->GetNativeDisplayId(); },
		[](Unit * u, uint32_t const id) { u->SetNativeDisplayId(id); }
	);
	reg_prop(ft, "sheath",
		[](Unit * u) { return u->GetSheath(); },
		[](Unit * u, SheathState const val) { u->SetSheath(val); }
	);
	reg_prop(ft, "speedWalk",
		[](Unit * unit) { return unit->GetSpeedRate(MOVE_WALK); },
		[](Unit * unit, float const rate) { unit->SetSpeedRate(MOVE_WALK, rate); }
	);
	reg_prop(ft, "speedRun",
		[](Unit * unit) { return unit->GetSpeedRate(MOVE_RUN); },
		[](Unit * unit, float const rate) { unit->SetSpeedRate(MOVE_RUN, rate); }
	);
	reg_prop(ft, "speedSwim",
		[](Unit * unit) { return unit->GetSpeedRate(MOVE_SWIM); },
		[](Unit * unit, float const rate) { unit->SetSpeedRate(MOVE_SWIM, rate); }
	);
	reg_prop(ft, "speedTurn",
		[](Unit * unit) { return unit->GetSpeedRate(MOVE_TURN_RATE); },
		[](Unit * unit, float const rate) { unit->SetSpeedRate(MOVE_TURN_RATE, rate); }
	);
	reg_prop(ft, "level",
		[](Unit * unit) { return unit->GetLevel(); },
		[](Unit * unit, uint8_t const lvl) { unit->SetLevel(lvl); }
	);
	reg_prop(ft, "powerType",
		[](Unit * unit) { return unit->getPowerType(); },
		[](Unit * unit, Powers const pt) { unit->setPowerType(pt); }
	);
	reg_prop(ft, "isPvPFlagged",
		[](Unit * u) { return u->IsPvP(); },
		[](Unit * u, bool const apply) { u->SetPvP(apply); }
	);
	reg_prop(ft, "standState",
		[](Unit * u) { return u->getStandState(); },
		[](Unit * u, uint8_t const state) { u->SetStandState(state); }
	);
	reg_prop(ft, "creatorGuid",
		[](Unit * u) { return u->GetCreatorGUID(); },
		[](Unit * u, ObjectGuid const g) { u->SetCreatorGUID(g); }
	);
	reg_prop(ft, "critterGuid",
		[](Unit * u) { return u->GetCritterGUID(); },
		[](Unit * u, ObjectGuid const g) { u->SetCritterGUID(g); }
	);
	reg_prop(ft, "ownerGuid",
		[](Unit * u) { return u->GetOwnerGUID(); },
		[](Unit * u, ObjectGuid const g) { u->SetOwnerGUID(g); }
	);
	reg_prop(ft, "petGuid",
		[](Unit * u) { return u->GetPetGUID(); },
		[](Unit * u, ObjectGuid const g) { u->SetPetGUID(g); }
	);
	reg_prop(ft, "isFFA",
		[](Unit * u) { return u->IsFFAPvP(); },
		[](Unit * u, bool const state) {
			if (state) {
				u->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);
			} else {
				u->RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);
			}
		}
	);
	reg_prop(ft, "isInSanctuary",
		[](Unit * u) { return u->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY); },
		[](Unit * u, auto const state) {
			if (state) {
				u->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY);
			} else {
				u->RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY);
			}
		}
	);
	reg_prop(ft, "isRooted",
		[](Unit * u) { return u->IsRooted(); },
		[](Unit * u, auto const state) {
			if (state) {
				u->AddUnitState(UNIT_STATE_ROOT);
			} else {
				u->ClearUnitState(UNIT_STATE_ROOT);
			}
		}
	);
	reg_prop(ft, "isConfused",
		[](Unit * u) { return u->HasUnitState(UNIT_STATE_CONFUSED); },
		[](Unit * u, auto const state) {
			if (state) {
				u->AddUnitState(UNIT_STATE_CONFUSED);
			} else {
				u->ClearUnitState(UNIT_STATE_CONFUSED);
			}
		}
	);
	reg_prop(ft, "isFleeing",
		[](Unit * u) { return u->HasUnitState(UNIT_STATE_FLEEING); },
		[](Unit * u, auto const state) {
			if (state) {
				u->AddUnitState(UNIT_STATE_FLEEING);
			} else {
				u->ClearUnitState(UNIT_STATE_FLEEING);
			}
		}
	);
	reg_prop(ft, "emoteState",
		[](Unit * u) { return static_cast<Emote>(u->GetUInt32Value(UNIT_NPC_EMOTESTATE)); },
		[](Unit * u, auto state) { u->SetUInt32Value(UNIT_NPC_EMOTESTATE, state); }
	);
	reg_prop(ft, "canFly",
		[](Unit * u) { return u->CanFly(); },
		[](Unit * u, bool const state) { u->SetCanFly(state); }
	);

	reg_method(ft, "demorph", [](Unit * u) {
		u->RemoveAurasByType(SPELL_AURA_TRANSFORM);
	});
	reg_method(ft, "dismount", [](Unit * u) {
		u->Dismount();
	});
	reg_method(ft, "performEmote", [](Unit * u, uint32_t const emote) {
		u->HandleEmoteCommand(emote);
	});
	reg_method(ft, "mount", [](Unit * u, uint32_t const mount_id, std::optional<uint32_t> vehicle_id, std::optional<uint32_t> creature_entry) {
		u->Mount(mount_id, vehicle_id.value_or(0), creature_entry.value_or(0));
	});
	reg_method(ft, "stopSpellCast", [](Unit * u, std::optional<uint32_t> except_spell_id, std::optional<bool> with_instant) {
		u->CastStop(except_spell_id.value_or(0), with_instant.value_or(true));
	});
	reg_method(ft, "interruptNonMeleeSpells", [](Unit * u, bool with_delayed, std::optional<uint32> spell_id, std::optional<bool> with_instant, std::optional<bool> by_self) {
		u->InterruptNonMeleeSpells(
			with_delayed,
			spell_id.value_or(0),
			with_instant.value_or(true),
			by_self.value_or(false)
		);
	});
	reg_method(ft, "removeAllAuras", [](Unit * u) {
		u->RemoveAllAuras();
	});
	reg_method(ft, "removeArenaAuras", [](Unit * u) {
		u->RemoveArenaAuras();
	});
	reg_method(ft, "setFacingToObject", [](Unit * u, WorldObject * target, std::optional<DurationWrapper> timed) {
		if (timed) {
			u->SetFacingToObject(target, timed->to_chrono<Milliseconds>());
		} else {
			u->SetFacingToObject(target);
		}
	});
	reg_method(ft, "setInCombatWith", [](Unit * u, Unit * target, std::optional<bool> add_second_unit_suppressed) {
		u->SetInCombatWith(target, add_second_unit_suppressed.value_or(false));
	});
	reg_method(ft, "clearThreatList", [](Unit * u) {
		u->GetThreatMgr().ResetAllThreat();
	});
	reg_method(ft, "addUnitState", [](Unit * u, uint32_t const state) {
		u->AddUnitState(state);
	});
	reg_method(ft, "clearUnitState", [](Unit * u, uint32_t const state) {
		u->ClearUnitState(state);
	});
	reg_method(ft, "nearTeleportTo", [](Unit * u, float const x, float const y, float const z, std::optional<float> o, std::optional<bool> casting, std::optional<bool> vehicle_teleport, std::optional<bool> with_pet, std::optional<bool> remove_transport) {
		u->NearTeleportTo(x, y, z, o.value_or(u->GetOrientation()), casting.value_or(false), vehicle_teleport.value_or(false), with_pet.value_or(false), remove_transport.value_or(false));
	});
	reg_method(ft, "addThreat", [](Unit * u, Unit * target, float const amount, std::optional<SpellInfo const *> spell, std::optional<bool> ignore_modifiers, std::optional<bool> ignore_redirects) {
		u->GetThreatMgr().AddThreat(target, amount, spell.value_or(nullptr), ignore_modifiers.value_or(false), ignore_redirects.value_or(false));
	});
	reg_method(ft, "modifyThreatByPercent", [](Unit * u, Unit * target, int32_t const pct) {
		u->GetThreatMgr().ModifyThreatByPercent(target, pct);
	});
	reg_method(ft, "resetThreat", [](Unit * u, Unit * target) {
		u->GetThreatMgr().ResetThreat(target);
	});
	reg_method(ft, "resetAllThreat", [](Unit * u) {
		u->GetThreatMgr().ResetAllThreat();
	});
	reg_method(ft, "modifyPower", [](Unit * u, Powers const power_type, int32_t const amount, std::optional<bool> with_power_update) {
		u->ModifyPower(power_type, amount, with_power_update.value_or(true));
	});
	reg_method(ft, "moveStop", [](Unit * u) {
		u->GetMotionMaster()->Initialize();
	});
	reg_method(ft, "moveExpire", [](Unit * u, std::optional<bool> reset) {
		u->GetMotionMaster()->MovementExpired(reset.value_or(true));
	});
	reg_method(ft, "moveClear", [](Unit * u, std::optional<bool> const reset) {
		u->GetMotionMaster()->Clear(reset.value_or(true));
	});
	reg_method(ft, "moveFollow", [](Unit * u, Unit * target, std::optional<float> const distance, std::optional<float> const angle, std::optional<MovementSlot> slot, std::optional<bool> inherit_walk_state, std::optional<bool> inherit_speed) {
		u->GetMotionMaster()->MoveFollow(target, distance.value_or(0), angle.value_or(0), slot.value_or(MOTION_SLOT_ACTIVE), inherit_walk_state.value_or(true), inherit_speed.value_or(true));
	});
	reg_method(ft, "moveChase", [](Unit * u, Unit * target, std::optional<ChaseRange> const distance, std::optional<ChaseAngle> const angle) {
		u->GetMotionMaster()->MoveChase(target, distance, angle);
	});
	reg_method(ft, "moveFleeing", [](Unit * u, Unit * enemy, std::optional<uint32_t> const time) {
		u->GetMotionMaster()->MoveFleeing(enemy, time.value_or(0));
	});
	reg_method(ft, "moveJump", [](Unit * u, float const x, float const y, float const z, float vel_xy, float vel_z, std::optional<uint32_t> id, std::optional<Unit *> target) {
		u->GetMotionMaster()->MoveJump(x, y, z, vel_xy, vel_z, id.value_or(0), target.value_or(nullptr));
	});
	reg_method(ft, "moveConfused", [](Unit * u) {
		u->GetMotionMaster()->MoveConfused();
	});
	reg_method(ft, "moveTargetedHome", [](Unit * u, std::optional<bool> walk) {
		u->GetMotionMaster()->MoveTargetedHome(walk.value_or(false));
	});
	reg_method(ft, "moveIdle", [](Unit * u) {
		u->GetMotionMaster()->MoveIdle();
	});
	reg_method(ft, "moveRandom", [](Unit * u, std::optional<float> wander_distance) {
		u->GetMotionMaster()->MoveRandom(wander_distance.value_or(0));
	});
	reg_method(ft, "clearComboPoints", [](Unit * u) {
		u->ClearComboPoints();
	});
	reg_method(ft, "addComboPoints", [](Unit * u, int8_t const count) {
		u->AddComboPoints(count);
	});
	reg_method(ft, "buildCastSpell", [](Unit * unit, SpellInfo const * spell) {
		return jmove(new CastSpellBuilder(unit, spell));
	});
	reg_method(ft, "addAura", [](Unit * u, uint32_t const spellId, Unit * target) {
		u->AddAura(spellId, target);
	});
	reg_method(ft, "removeAura", [](Unit * u, uint32_t spell_id, std::optional<ObjectGuid> caster, std::optional<uint8_t> required_effect_mask, std::optional<AuraRemoveMode> remove_mode) {
		u->RemoveAura(spell_id, caster.value_or(ObjectGuid::Empty), required_effect_mask.value_or(0), remove_mode.value_or(AURA_REMOVE_BY_DEFAULT));
	});
	reg_method(ft, "kill", [](Unit * u, Unit * target, std::optional<bool> const durability_loss, std::optional<WeaponAttackType> const attack_type, std::optional<SpellInfo const *> const spell_proto, std::optional<Spell const *> const spell) {
		Unit::Kill(
			u,
			target,
			durability_loss.value_or(true),
			attack_type.value_or(BASE_ATTACK),
			spell_proto.value_or(nullptr),
			spell.value_or(nullptr)
		);
	});
	reg_method(ft, "clearInCombat", [](Unit * u) {
		u->ClearInCombat();
	});
	reg_method(ft, "applySpellImmune", [](Unit * u, uint32_t spell_id, SpellImmunity op, uint32_t type, bool apply, std::optional<SpellImmuneBlockType> blockType) {
		u->ApplySpellImmune(spell_id, op, type, apply, blockType.value_or(SPELL_BLOCK_TYPE_ALL));
	});
	reg_method(ft, "setMaxPower", [](Unit * u, uint32_t const amt, std::optional<Powers> const type) {
		u->SetMaxPower(type ? *type : u->getPowerType(), amt);
	});
	reg_method(ft, "setPower", [](Unit * u, uint32_t const amt, std::optional<Powers> const type) {
		u->SetPower(type ? *type : u->getPowerType(), amt);
	});
	reg_method(ft, "setSpeed", [](Unit * u, UnitMoveType const type, float const rate, std::optional<bool> const forced) {
		u->SetSpeed(type, rate, forced.value_or(false));
	});
	reg_method(ft, "setSpeedRate", [](Unit * u, UnitMoveType const type, float const rate) {
		u->SetSpeedRate(type, rate);
	});
	reg_method(ft, "attack", [](Unit * u, Unit * target, bool melee_attack) {
		return u->Attack(target, melee_attack);
	});
	reg_method(ft, "attackStop", [](Unit * u) {
		return u->AttackStop();
	});
	reg_method(ft, "getFlatModifierValue", [](Unit * u, UnitMods const stat, UnitModifierFlatType const type) {
		return u->GetFlatModifierValue(stat, type);
	});
	reg_method(ft, "getPctModifierValue", [](Unit * u, UnitMods const stat, UnitModifierPctType const type) {
		return u->GetPctModifierValue(stat, type);
	});
	reg_method(ft, "setStatFlatModifier", [](Unit * u, UnitMods const stat, UnitModifierFlatType const type, float const value) {
		u->SetStatFlatModifier(stat, type, value);
	});
	reg_method(ft, "setStatPctModifier", [](Unit * u, UnitMods const stat, UnitModifierPctType const type, float const value) {
		u->SetStatPctModifier(stat, type, value);
	});
	reg_method(ft, "handleStatFlatModifier", [](Unit * u, UnitMods const stat, UnitModifierFlatType const type, float const value, bool apply) {
		return u->HandleStatFlatModifier(stat, type, value, apply);
	});
	reg_method(ft, "applyStatPctModifier", [](Unit * u, UnitMods const stat, UnitModifierPctType const type, float const value) {
		u->ApplyStatPctModifier(stat, type, value);
	});
	reg_method(ft, "sendUnitEmote", [](Unit * u, std::string const msg, std::optional<Unit *> const receiver, std::optional<bool> const bossEmote) {
		u->TextEmote(msg, receiver.value_or(nullptr), bossEmote.value_or(false));
	});
	reg_method(ft, "say", [](Unit * u, std::string const msg, Language const lang) {
		if (!msg.empty()) {
			u->Say(msg, lang, u);
		}
	});
	reg_method(ft, "whisper", [](Unit * u, std::string const msg, Language const lang, Player * target) {
		if (!msg.empty()) {
			u->Whisper(msg, lang, target, false);
		}
	});
	reg_method(ft, "bossWhisper", [](Unit * u, std::string const msg, Language const lang, Player * target) {
		if (!msg.empty()) {
			u->Whisper(msg, lang, target, true);
		}
	});
	reg_method(ft, "yell", [](Unit * u, std::string const msg, Language const lang) {
		if (!msg.empty()) {
			u->Yell(msg, lang, u);
		}
	});
	reg_method(ft, "setDeathState", [](Unit * unit, DeathState const s, std::optional<bool> despawn) {
		unit->setDeathState(s, despawn.value_or(false));
	});
	reg_method(ft, "setWalk", [](Unit * unit, bool enable) {
		unit->SetWalk(enable);
	});
	reg_method(ft, "setDisableGravity", [](Unit * unit, bool disable) {
		unit->SetDisableGravity(disable);
	});
	reg_method(ft, "setSwim", [](Unit * unit, bool enable) {
		unit->SetSwim(enable);
	});
	reg_method(ft, "setWaterWalking", [](Unit * u, bool enable) {
		u->SetWaterWalking(enable);
	});
	reg_method(ft, "setFeatherFall", [](Unit * u, bool enable) {
		u->SetFeatherFall(enable);
	});
	reg_method(ft, "setHover", [](Unit * u, bool enable) {
		u->SetHover(enable);
	});
	reg_method(ft, "summonPlayer", [](Unit * u, Player * player) {
		float x, y, z;
		u->GetPosition(x, y, z);
		player->SetSummonPoint(u->GetMapId(), x, y, z);

		WorldPacket data(SMSG_SUMMON_REQUEST, 8 + 4 + 4);
		data << u->GetGUID();
		data << uint32_t { u->GetZoneId() };
		data << uint32_t { MAX_PLAYER_SUMMON_DELAY * IN_MILLISECONDS };
		player->GetSession()->SendPacket(&data);
	});
	reg_method(ft, "dealDamage", [](Unit * u, Unit * target, uint32_t const amount, std::optional<DamageEffectType> const type, std::optional<SpellSchoolMask> const spell_school_mask, std::optional<SpellInfo const *> const spell_proto, std::optional<bool> const durability_loss, std::optional<bool> const allow_gm, std::optional<Spell const *> const spell) {
		return Unit::DealDamage(
			u,
			target,
			amount,
			nullptr,
			type.value_or(DIRECT_DAMAGE),
			spell_school_mask.value_or(SPELL_SCHOOL_MASK_NORMAL),
			spell_proto.value_or(nullptr),
			durability_loss.value_or(true),
			allow_gm.value_or(false),
			spell.value_or(nullptr)
		);
	});

	return ft;
}
