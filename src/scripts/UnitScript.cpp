#include "UnitScript.h"

#include <string>

#include "DurationWrapper.h"
#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_Unit : public UnitScript {
public:
	NODEJS_Unit() : UnitScript("NODEJS_Unit") {
	}

	void OnHeal(Unit * healer, Unit * reciever, uint32_t & gain) override {
		NodeJs::invoke_hook("unit:heal"
			, jprop("healer", healer), jprop("receiver", reciever), jprop_box("amount", gain));
	}
	void OnDamage(Unit * attacker, Unit * victim, uint32_t & damage) override {
		NodeJs::invoke_hook("unit:damage"
			, jprop("attacker", attacker), jprop("victim", victim), jprop_box("amount", damage));
	}
	void ModifyPeriodicDamageAurasTick(Unit * target, Unit * attacker, uint32_t & damage, SpellInfo const * spellInfo) override {
		NodeJs::invoke_hook("unit:modify-periodic-damage-auras-tick"
			, jprop("target", target), jprop("attacker", attacker), jprop_box("amount", damage), jprop("spellInfo", spellInfo));
	}
	void ModifyMeleeDamage(Unit * target, Unit * attacker, uint32_t & damage) override {
		NodeJs::invoke_hook("unit:modify-melee-damage"
			, jprop("target", target), jprop("attacker", attacker), jprop_box("amount", damage));
	}
	void ModifySpellDamageTaken(Unit* target, Unit * attacker, int32_t & damage, SpellInfo const * spellInfo) override {
		NodeJs::invoke_hook("unit:modify-spell-damage-taken"
			, jprop("target", target), jprop("attacker", attacker), jprop_box("amount", damage), jprop("spellInfo", spellInfo));
	}
	void ModifyHealReceived(Unit * target, Unit * healer, uint32_t & heal, SpellInfo const * spellInfo) override {
		NodeJs::invoke_hook("unit:modify-heal-received"
			, jprop("target", target), jprop("healer", healer), jprop_box("amount", heal), jprop("spellInfo", spellInfo));
	}
	uint32_t DealDamage(Unit * AttackerUnit, Unit * pVictim, uint32_t const damage, DamageEffectType const damagetype) override {
		return NodeJs::invoke_hook_t("unit:deal-damage", UnitScript::DealDamage(AttackerUnit, pVictim, damage, damagetype)
			, jprop("attacker", AttackerUnit), jprop("victim", pVictim), jprop("amount", damage), jprop("damageType", damagetype));
	}
	void OnBeforeRollMeleeOutcomeAgainst(Unit const * attacker, Unit const * victim, WeaponAttackType const attType, int32_t & attackerMaxSkillValueForLevel, int32_t & victimMaxSkillValueForLevel, int32_t & attackerWeaponSkill, int32_t & victimDefenseSkill, int32_t & crit_chance, int32_t & miss_chance, int32_t & dodge_chance, int32_t & parry_chance, int32_t & block_chance ) override {
		NodeJs::invoke_hook("unit:before-roll-melee-outcome-against"
			, jprop("attacker", attacker), jprop("victim", victim), jprop("attType", attType), jprop_box("attackerMaxSkillValueForLevel", attackerMaxSkillValueForLevel), jprop_box("victimMaxSkillValueForLevel", victimMaxSkillValueForLevel), jprop_box("attackerWeaponSkill", attackerWeaponSkill), jprop_box("victimDefenseSkill", victimDefenseSkill), jprop_box("critChance", crit_chance), jprop_box("missChance", miss_chance), jprop_box("dodgeChance", dodge_chance), jprop_box("parryChance", parry_chance), jprop_box("blockChance", block_chance));
	}
	void OnAuraApply(Unit * unit, Aura * aura) override {
		NodeJs::invoke_hook("unit:aura-apply"
			, jprop("unit", unit), jprop("aura", aura));
	}
	void OnAuraRemove(Unit * unit, AuraApplication * aurApp, AuraRemoveMode const mode) override {
		NodeJs::invoke_hook("unit:aura-remove"
			, jprop("unit", unit), jprop("aurApp", aurApp), jprop("mode", mode));
	}
	[[nodiscard]] bool IfNormalReaction(Unit const * unit, Unit const * target, ReputationRank & repRank) override {
		return NodeJs::invoke_hook_t("unit:if-normal-reaction", UnitScript::IfNormalReaction(unit, target, repRank)
			, jprop("unit", unit), jprop("target", target), jprop_box("repRank", repRank));
	}
	[[nodiscard]] bool CanSetPhaseMask(Unit const * unit, uint32_t const newPhaseMask, bool const update) override {
		return NodeJs::invoke_hook_t("unit:can-set-phase-mask", UnitScript::CanSetPhaseMask(unit, newPhaseMask, update)
			, jprop("unit", unit), jprop("newPhaseMask", newPhaseMask), jprop("update", update));
	}
	[[nodiscard]] bool ShouldTrackValuesUpdatePosByIndex(Unit const * unit, uint8_t const updateType, uint16_t const index) override {
		return NodeJs::invoke_hook_t("unit:should-track-values-update-pos-by-index", UnitScript::ShouldTrackValuesUpdatePosByIndex(unit, updateType, index)
			, jprop("unit", unit), jprop("updateType", updateType), jprop("index", index));
	}
	void OnPatchValuesUpdate(Unit const * unit, ByteBuffer & valuesUpdateBuf, BuildValuesCachePosPointers & posPointers, Player * target) override {
		NodeJs::invoke_hook("unit:patch-values-update"
			, jprop("unit", unit)/*, jprop_box("valuesUpdateBuf", valuesUpdateBuf)*//*, jprop_box("posPointers", posPointers)*/, jprop("target", target));
	}
	void OnUnitUpdate(Unit * unit, uint32_t const diff) override {
		NodeJs::invoke_hook("unit:update"
			, jprop("unit", unit), jprop("diff", DurationWrapper::from_milliseconds(diff)));
	}
	void OnDisplayIdChange(Unit * unit, uint32_t const displayId) override {
		NodeJs::invoke_hook("unit:display-id-change"
			, jprop("unit", unit), jprop("displayId", displayId));
	}
	void OnUnitEnterEvadeMode(Unit * unit, uint8_t const evadeReason) override {
		NodeJs::invoke_hook("unit:enter-evade-mode"
			, jprop("unit", unit), jprop("evadeReason", evadeReason));
	}
	void OnUnitEnterCombat(Unit * unit, Unit * victim) override {
		NodeJs::invoke_hook("unit:enter-combat"
			, jprop("unit", unit), jprop("victim", victim));
	}
	void OnUnitDeath(Unit * unit, Unit * killer) override {
		NodeJs::invoke_hook("unit:death"
			, jprop("unit", unit), jprop("killer", killer));
	}
	void OnUnitSetShapeshiftForm(Unit * unit, uint8_t const form) override {
		NodeJs::invoke_hook("unit:set-shapeshift-form"
			, jprop("unit", unit), jprop("form", form));
	}
};

void AddSC_Unit() {
	new NODEJS_Unit();
}
