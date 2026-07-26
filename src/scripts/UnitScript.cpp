#include "UnitScript.h"

#include <string>

#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_Unit : public UnitScript {
public:
	NODEJS_Unit() : UnitScript("NODEJS_Unit") {
	}

	void OnHeal(Unit * healer, Unit * reciever, uint32_t & gain) override {
		NodeJs::invoke_hook("unit:heal", jarg("healer", healer), jarg("receiver", reciever), jarg_inout("amount", gain));
	}
	void OnDamage(Unit * attacker, Unit * victim, uint32_t & damage) override {
		NodeJs::invoke_hook("unit:damage", jarg("attacker", attacker), jarg("victim", victim), jarg_inout("amount", damage));
	}
	void ModifyPeriodicDamageAurasTick(Unit * target, Unit * attacker, uint32_t & damage, SpellInfo const * spellInfo) override {
		NodeJs::invoke_hook("unit:modify-periodic-damage-auras-tick", jarg("target", target), jarg("attacker", attacker), jarg_inout("amount", damage), jarg("spellInfo", spellInfo));
	}
	void ModifyMeleeDamage(Unit * target, Unit * attacker, uint32_t & damage) override {
		NodeJs::invoke_hook("unit:modify-melee-damage", jarg("target", target), jarg("attacker", attacker), jarg_inout("amount", damage));
	}
	void ModifySpellDamageTaken(Unit* target, Unit * attacker, int32_t & damage, SpellInfo const * spellInfo) override {
		NodeJs::invoke_hook("unit:modify-spell-damage-taken", jarg("target", target), jarg("attacker", attacker), jarg_inout("amount", damage), jarg("spellInfo", spellInfo));
	}
	void ModifyHealReceived(Unit * target, Unit * healer, uint32_t & heal, SpellInfo const * spellInfo) override {
		NodeJs::invoke_hook("unit:modify-heal-received", jarg("target", target), jarg("healer", healer), jarg_inout("amount", heal), jarg("spellInfo", spellInfo));
	}
	uint32_t DealDamage(Unit * AttackerUnit, Unit * pVictim, uint32_t const damage, DamageEffectType const damagetype) override {
		return NodeJs::invoke_hook_t("unit:deal-damage", UnitScript::DealDamage(AttackerUnit, pVictim, damage, damagetype)
			, jarg("attacker", AttackerUnit), jarg("victim", pVictim), jarg("amount", damage), jarg("damageType", damagetype));
	}
	void OnBeforeRollMeleeOutcomeAgainst(Unit const * attacker, Unit const * victim, WeaponAttackType const attType, int32_t & attackerMaxSkillValueForLevel, int32_t & victimMaxSkillValueForLevel, int32_t & attackerWeaponSkill, int32_t & victimDefenseSkill, int32_t & crit_chance, int32_t & miss_chance, int32_t & dodge_chance, int32_t & parry_chance, int32_t & block_chance ) override {
		NodeJs::invoke_hook("unit:before-roll-melee-outcome-against", jarg("attacker", attacker), jarg("victim", victim), jarg("attType", attType), jarg_inout("attackerMaxSkillValueForLevel", attackerMaxSkillValueForLevel), jarg_inout("victimMaxSkillValueForLevel", victimMaxSkillValueForLevel), jarg_inout("attackerWeaponSkill", attackerWeaponSkill), jarg_inout("victimDefenseSkill", victimDefenseSkill), jarg_inout("critChance", crit_chance), jarg_inout("missChance", miss_chance), jarg_inout("dodgeChance", dodge_chance), jarg_inout("parryChance", parry_chance), jarg_inout("blockChance", block_chance));
	}
	void OnAuraApply(Unit * unit, Aura * aura) override {
		NodeJs::invoke_hook("unit:aura-apply", jarg("unit", unit), jarg("aura", aura));
	}
	void OnAuraRemove(Unit * unit, AuraApplication * aurApp, AuraRemoveMode const mode) override {
		NodeJs::invoke_hook("unit:aura-remove", jarg("unit", unit)/*, jarg("aurApp", aurApp)*/, jarg("mode", mode));
	}
	[[nodiscard]] bool IfNormalReaction(Unit const * unit, Unit const * target, ReputationRank & repRank) override {
		return NodeJs::invoke_hook_t("unit:if-normal-reaction", UnitScript::IfNormalReaction(unit, target, repRank)
			, jarg("unit", unit), jarg("target", target), jarg_inout("repRank", repRank));
	}
	[[nodiscard]] bool CanSetPhaseMask(Unit const * unit, uint32_t const newPhaseMask, bool const update) override {
		return NodeJs::invoke_hook_t("unit:can-set-phase-mask", UnitScript::CanSetPhaseMask(unit, newPhaseMask, update)
			, jarg("unit", unit), jarg("newPhaseMask", newPhaseMask), jarg("update", update));
	}
	[[nodiscard]] bool IsCustomBuildValuesUpdate(Unit const * unit, uint8_t const updateType, ByteBuffer & fieldBuffer, Player const * target, uint16_t const index) override {
		return NodeJs::invoke_hook_t("unit:is-custom-build-values-update", UnitScript::IsCustomBuildValuesUpdate(unit, updateType, fieldBuffer, target, index)
			, jarg("unit", unit), jarg("updateType", updateType)/*, jarg_inout("fieldBuffer", fieldBuffer)*/, jarg("target", target), jarg("index", index));
	}
	[[nodiscard]] bool ShouldTrackValuesUpdatePosByIndex(Unit const * unit, uint8_t const updateType, uint16_t const index) override {
		return NodeJs::invoke_hook_t("unit:should-track-values-update-pos-by-index", UnitScript::ShouldTrackValuesUpdatePosByIndex(unit, updateType, index)
			, jarg("unit", unit), jarg("updateType", updateType), jarg("index", index));
	}
	void OnPatchValuesUpdate(Unit const * unit, ByteBuffer & valuesUpdateBuf, BuildValuesCachePosPointers & posPointers, Player * target) override {
		NodeJs::invoke_hook("unit:patch-values-update", jarg("unit", unit)/*, jarg_inout("valuesUpdateBuf", valuesUpdateBuf)*//*, jarg_inout("posPointers", posPointers)*/, jarg("target", target));
	}
	void OnUnitUpdate(Unit * unit, uint32_t const diff) override {
		NodeJs::invoke_hook("unit:update", jarg("unit", unit), jarg("diff", diff));
	}
	void OnDisplayIdChange(Unit * unit, uint32_t const displayId) override {
		NodeJs::invoke_hook("unit:display-id-change", jarg("unit", unit), jarg("displayId", displayId));
	}
	void OnUnitEnterEvadeMode(Unit * unit, uint8_t const evadeReason) override {
		NodeJs::invoke_hook("unit:enter-evade-mode", jarg("unit", unit), jarg("evadeReason", evadeReason));
	}
	void OnUnitEnterCombat(Unit * unit, Unit * victim) override {
		NodeJs::invoke_hook("unit:enter-combat", jarg("unit", unit), jarg("victim", victim));
	}
	void OnUnitDeath(Unit * unit, Unit * killer) override {
		NodeJs::invoke_hook("unit:death", jarg("unit", unit), jarg("killer", killer));
	}
	void OnUnitSetShapeshiftForm(Unit * unit, uint8_t const form) override {
		NodeJs::invoke_hook("unit:set-shapeshift-form", jarg("unit", unit), jarg("form", form));
	}
};

void AddSC_Unit() {
	new NODEJS_Unit();
}
