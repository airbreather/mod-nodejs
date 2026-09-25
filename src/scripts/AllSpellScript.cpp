#include "AllSpellScript.h"

#include <string>

#include "JBox.h"
#include "NodeJs.h"

class NODEJS_AllSpell : public AllSpellScript {
public:
	NODEJS_AllSpell() : AllSpellScript("NODEJS_AllSpell") {
	}

	void OnCalcMaxDuration(Aura const * aura, int32_t & maxDuration) override {
		NodeJs::invoke_hook("spell:calc-max-duration"
			, jprop("aura", aura), jprop_box("maxDuration", maxDuration));
	}
	void OnSpellCheckCast(Spell * spell, bool const strict, SpellCastResult & res) override {
		NodeJs::invoke_hook("spell:check-cast"
			, jprop("spell", spell), jprop("strict", strict), jprop_box("result", res));
	}
	[[nodiscard]] bool CanPrepare(Spell * spell, SpellCastTargets const * targets, AuraEffect const * triggeredByAura) override {
		return NodeJs::invoke_hook_t("spell:can-prepare", AllSpellScript::CanPrepare(spell, targets, triggeredByAura)
			, jprop("spell", spell)/*, jprop("target", targets)*//*, jprop("triggeredByAura", triggeredByAura)*/);
	}
	[[nodiscard]] bool CanScalingEverything(Spell * spell) override {
		return NodeJs::invoke_hook_t("spell:can-scaling-everything", AllSpellScript::CanScalingEverything(spell)
			, jprop("spell", spell));
	}
	[[nodiscard]] bool CanSelectSpecTalent(Spell * spell) override {
		return NodeJs::invoke_hook_t("spell:can-select-spec-talent", AllSpellScript::CanSelectSpecTalent(spell)
			, jprop("spell", spell));
	}
	void OnScaleAuraUnitAdd(Spell * spell, Unit * target, uint32_t const effectMask, bool const checkIfValid, bool const implicit, uint8_t const auraScaleMask, TargetInfo & targetInfo) override {
		NodeJs::invoke_hook("spell:scale-aura-unit-add"
			, jprop("spell", spell), jprop("target", target), jprop("effectMask", effectMask), jprop("checkIfValid", checkIfValid), jprop("implicit", implicit), jprop("auraScaleMask", auraScaleMask)/*, jprop_box("targetInfo", targetInfo)*/);
	}
	void OnRemoveAuraScaleTargets(Spell * spell, TargetInfo & targetInfo, uint8_t const auraScaleMask, bool & needErase) override {
		NodeJs::invoke_hook("spell:remove-aura-scale-targets"
			, jprop("spell", spell)/*, jprop_box("targetInfo", targetInfo)*/, jprop("auraScaleMask", auraScaleMask), jprop_box("needErase", needErase));
	}
	void OnBeforeAuraRankForLevel(SpellInfo const * spellInfo, SpellInfo const * latestSpellInfo, uint8_t const level) override {
		NodeJs::invoke_hook("spell:before-aura-rank-for-level"
			, jprop("spellInfo", spellInfo), jprop("latestSpellInfo", latestSpellInfo), jprop("level", level));
	}
	void OnDummyEffect(WorldObject * caster, uint32_t const spellID, SpellEffIndex const effIndex, GameObject * gameObjTarget) override {
		NodeJs::invoke_hook("spell:dummy-effect:game-object-target"
			, jprop("caster", caster), jprop("spellId", spellID), jprop("effIndex", effIndex), jprop("target", gameObjTarget));
	}
	void OnDummyEffect(WorldObject * caster, uint32_t const spellID, SpellEffIndex const effIndex, Creature * creatureTarget) override {
		NodeJs::invoke_hook("spell:dummy-effect:creature-target"
			, jprop("caster", caster), jprop("spellId", spellID), jprop("effIndex", effIndex), jprop("target", creatureTarget));
	}
	void OnDummyEffect(WorldObject * caster, uint32_t const spellID, SpellEffIndex const effIndex, Item * itemTarget) override {
		NodeJs::invoke_hook("spell:dummy-effect:item-target"
			, jprop("caster", caster), jprop("spellId", spellID), jprop("effIndex", effIndex), jprop("target", itemTarget));
	}
	void OnSpellCastCancel(Spell * spell, Unit * caster, SpellInfo const * spellInfo, bool const bySelf) override {
		NodeJs::invoke_hook("spell:cast-cancel"
			, jprop("spell", spell), jprop("caster", caster), jprop("spellInfo", spellInfo), jprop("bySelf", bySelf));
	}
	void OnSpellCast(Spell * spell, Unit * caster, SpellInfo const * spellInfo, bool const skipCheck) override {
		NodeJs::invoke_hook("spell:cast"
			, jprop("spell", spell), jprop("caster", caster), jprop("spellInfo", spellInfo), jprop("skipCheck", skipCheck));
	}
	void OnSpellPrepare(Spell* spell, Unit* caster, SpellInfo const* spellInfo) override {
		NodeJs::invoke_hook("spell:prepare"
			, jprop("spell", spell), jprop("caster", caster), jprop("spellInfo", spellInfo));
	}
};

void AddSC_AllSpell() {
	new NODEJS_AllSpell();
}
