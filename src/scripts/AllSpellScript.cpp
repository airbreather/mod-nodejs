#include "AllSpellScript.h"

#include <string>

#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_AllSpell : public AllSpellScript {
public:
	NODEJS_AllSpell() : AllSpellScript("NODEJS_AllSpell") {
	}

	void OnCalcMaxDuration(Aura const * aura, int32_t & maxDuration) override {
		NodeJs::invoke_hook("spell:calc-max-duration", jarg("aura", aura), jarg_inout("maxDuration", maxDuration));
	}
	void OnSpellCheckCast(Spell * spell, bool const strict, SpellCastResult & res) override {
		NodeJs::invoke_hook("spell:check-cast", jarg("spell", spell), jarg("strict", strict), jarg_inout("result", res));
	}
	[[nodiscard]] bool CanPrepare(Spell * spell, SpellCastTargets const * targets, AuraEffect const * triggeredByAura) override {
		return NodeJs::invoke_hook_t("spell:can-prepare", AllSpellScript::CanPrepare(spell, targets, triggeredByAura)
			, jarg("spell", spell)/*, jarg("target", targets)*//*, jarg("triggeredByAura", triggeredByAura)*/);
	}
	[[nodiscard]] bool CanScalingEverything(Spell * spell) override {
		return NodeJs::invoke_hook_t("spell:can-scaling-everything", AllSpellScript::CanScalingEverything(spell)
			, jarg("spell", spell));
	}
	[[nodiscard]] bool CanSelectSpecTalent(Spell * spell) override {
		return NodeJs::invoke_hook_t("spell:can-select-spec-talent", AllSpellScript::CanSelectSpecTalent(spell)
			, jarg("spell", spell));
	}
	void OnScaleAuraUnitAdd(Spell * spell, Unit * target, uint32_t const effectMask, bool const checkIfValid, bool const implicit, uint8_t const auraScaleMask, TargetInfo & targetInfo) override {
		NodeJs::invoke_hook("spell:scale-aura-unit-add", jarg("spell", spell), jarg("target", target), jarg("effectMask", effectMask), jarg("checkIfValid", checkIfValid), jarg("implicit", implicit), jarg("auraScaleMask", auraScaleMask)/*, jarg_inout("targetInfo", targetInfo)*/);
	}
	void OnRemoveAuraScaleTargets(Spell * spell, TargetInfo & targetInfo, uint8_t const auraScaleMask, bool & needErase) override {
		NodeJs::invoke_hook("spell:remove-aura-scale-targets", jarg("spell", spell)/*, jarg_inout("targetInfo", targetInfo)*/, jarg("auraScaleMask", auraScaleMask), jarg_inout("needErase", needErase));
	}
	void OnBeforeAuraRankForLevel(SpellInfo const * spellInfo, SpellInfo const * latestSpellInfo, uint8_t const level) override {
		NodeJs::invoke_hook("spell:before-aura-rank-for-level", jarg("spellInfo", spellInfo), jarg("latestSpellInfo", latestSpellInfo), jarg("level", level));
	}
	void OnDummyEffect(WorldObject * caster, uint32_t const spellID, SpellEffIndex const effIndex, GameObject * gameObjTarget) override {
		NodeJs::invoke_hook("spell:dummy-effect:game-object-target", jarg("caster", caster), jarg("spellId", spellID), jarg("effIndex", effIndex), jarg("target", gameObjTarget));
	}
	void OnDummyEffect(WorldObject * caster, uint32_t const spellID, SpellEffIndex const effIndex, Creature * creatureTarget) override {
		NodeJs::invoke_hook("spell:dummy-effect:creature-target", jarg("caster", caster), jarg("spellId", spellID), jarg("effIndex", effIndex), jarg("target", creatureTarget));
	}
	void OnDummyEffect(WorldObject * caster, uint32_t const spellID, SpellEffIndex const effIndex, Item * itemTarget) override {
		NodeJs::invoke_hook("spell:dummy-effect:item-target", jarg("caster", caster), jarg("spellId", spellID), jarg("effIndex", effIndex), jarg("target", itemTarget));
	}
	void OnSpellCastCancel(Spell * spell, Unit * caster, SpellInfo const * spellInfo, bool const bySelf) override {
		NodeJs::invoke_hook("spell:cast-cancel", jarg("spell", spell), jarg("caster", caster), jarg("spellInfo", spellInfo), jarg("bySelf", bySelf));
	}
	void OnSpellCast(Spell * spell, Unit * caster, SpellInfo const * spellInfo, bool const skipCheck) override {
		NodeJs::invoke_hook("spell:cast", jarg("spell", spell), jarg("caster", caster), jarg("spellInfo", spellInfo), jarg("skipCheck", skipCheck));
	}
	void OnSpellPrepare(Spell* spell, Unit* caster, SpellInfo const* spellInfo) override {
		NodeJs::invoke_hook("spell:prepare", jarg("spell", spell), jarg("caster", caster), jarg("spellInfo", spellInfo));
	}
};

void AddSC_AllSpell() {
	new NODEJS_AllSpell();
}
