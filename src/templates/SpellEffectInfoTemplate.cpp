#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "SharedDefines.h"
#include "Spells/SpellInfo.h"

JVAL_CVAL_TMPLS_RO(SpellEffectInfo const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<SpellEffectInfo const *>() {
	TypedTemplate<SpellEffectInfo const *> const ft = jctor();

	ft->SetClassName(jstr_intern("SpellEffectInfo"));

	reg_prop_ro(ft, "effectIndex", [](SpellEffectInfo const * eff) {
		return eff->EffectIndex;
	});
	reg_prop_ro(ft, "effect", [](SpellEffectInfo const * eff) {
		return eff->Effect;
	});
	reg_prop_ro(ft, "applyAuraName", [](SpellEffectInfo const * eff) {
		return eff->ApplyAuraName;
	});
	reg_prop_ro(ft, "amplitude", [](SpellEffectInfo const * eff) {
		return eff->Amplitude;
	});
	reg_prop_ro(ft, "dieSides", [](SpellEffectInfo const * eff) {
		return eff->DieSides;
	});
	reg_prop_ro(ft, "realPointsPerLevel", [](SpellEffectInfo const * eff) {
		return eff->RealPointsPerLevel;
	});
	reg_prop_ro(ft, "basePoints", [](SpellEffectInfo const * eff) {
		return eff->BasePoints;
	});
	reg_prop_ro(ft, "pointsPerComboPoint", [](SpellEffectInfo const * eff) {
		return eff->PointsPerComboPoint;
	});
	reg_prop_ro(ft, "valueMultiplier", [](SpellEffectInfo const * eff) {
		return eff->ValueMultiplier;
	});
	reg_prop_ro(ft, "damageMultiplier", [](SpellEffectInfo const * eff) {
		return eff->DamageMultiplier;
	});
	reg_prop_ro(ft, "bonusMultiplier", [](SpellEffectInfo const * eff) {
		return eff->BonusMultiplier;
	});
	reg_prop_ro(ft, "miscValue", [](SpellEffectInfo const * eff) {
		return eff->MiscValue;
	});
	reg_prop_ro(ft, "miscValueB", [](SpellEffectInfo const * eff) {
		return eff->MiscValueB;
	});
	reg_prop_ro(ft, "mechanic", [](SpellEffectInfo const * eff) {
		return eff->Mechanic;
	});
	reg_prop_ro(ft, "targetA", [](SpellEffectInfo const * eff) {
		return &eff->TargetA;
	});
	reg_prop_ro(ft, "targetB", [](SpellEffectInfo const * eff) {
		return &eff->TargetB;
	});
	reg_prop_ro(ft, "radiusEntry", [](SpellEffectInfo const * eff) {
		return eff->RadiusEntry;
	});
	reg_prop_ro(ft, "chainTarget", [](SpellEffectInfo const * eff) {
		return eff->ChainTarget;
	});
	reg_prop_ro(ft, "itemType", [](SpellEffectInfo const * eff) {
		return eff->ItemType;
	});
	reg_prop_ro(ft, "triggerSpell", [](SpellEffectInfo const * eff) {
		return eff->TriggerSpell;
	});
	reg_prop_ro(ft, "spellClassMask", [](SpellEffectInfo const * eff) {
		return eff->SpellClassMask;
	});
	reg_prop_ro(ft, "implicitTargetConditions", [](SpellEffectInfo const * eff) {
		return eff->ImplicitTargetConditions ? jarr(*eff->ImplicitTargetConditions) : jnull();
	});
	reg_prop_ro(ft, "isEffect", [](SpellEffectInfo const * eff) {
		return eff->IsEffect();
	});
	reg_prop_ro(ft, "isAura", [](SpellEffectInfo const * eff) {
		return eff->IsAura();
	});
	reg_prop_ro(ft, "isTargetingArea", [](SpellEffectInfo const * eff) {
		return eff->IsTargetingArea();
	});
	reg_prop_ro(ft, "isAreaAuraEffect", [](SpellEffectInfo const * eff) {
		return eff->IsAreaAuraEffect();
	});
	reg_prop_ro(ft, "isFarUnitTargetEffect", [](SpellEffectInfo const * eff) {
		return eff->IsFarUnitTargetEffect();
	});
	reg_prop_ro(ft, "isFarDestTargetEffect", [](SpellEffectInfo const * eff) {
		return eff->IsFarDestTargetEffect();
	});
	reg_prop_ro(ft, "isUnitOwnedAuraEffect", [](SpellEffectInfo const * eff) {
		return eff->IsUnitOwnedAuraEffect();
	});
	reg_prop_ro(ft, "hasRadius", [](SpellEffectInfo const * eff) {
		return eff->HasRadius();
	});
	reg_prop_ro(ft, "providedTargetMask", [](SpellEffectInfo const * eff) {
		return eff->GetProvidedTargetMask();
	});
	reg_prop_ro(ft, "implicitTargetType", [](SpellEffectInfo const * eff) {
		return eff->GetImplicitTargetType();
	});
	reg_prop_ro(ft, "usedTargetObjectType", [](SpellEffectInfo const * eff) {
		return eff->GetUsedTargetObjectType();
	});
	reg_prop_ro(ft, "immunityInfo", [](SpellEffectInfo const * eff) {
		return eff->GetImmunityInfo();
	});

	reg_method(ft, "hasEffectOf", [](SpellEffectInfo const * eff, SpellEffects const effect_name) {
		return eff->IsEffect(effect_name);
	});
	reg_method(ft, "appliesAura", [](SpellEffectInfo const * eff, AuraType const aura) {
		return eff->IsAura(aura);
	});
	reg_method(ft, "calcValue", [](SpellEffectInfo const * eff, std::optional<Unit *> const caster, std::optional<int32_t> const base_points, std::optional<Unit *> const target) {
		auto const base_points_l = base_points.value_or(0);
		return eff->CalcValue(caster.value_or(nullptr), base_points ? &base_points_l : nullptr, target.value_or(nullptr));
	});
	reg_method(ft, "calcBaseValue", [](SpellEffectInfo const * eff, int32_t const value) {
		return eff->CalcBaseValue(value);
	});
	reg_method(ft, "calcValueMultiplier", [](SpellEffectInfo const * eff, Unit * caster, std::optional<Spell *> const spell) {
		return eff->CalcValueMultiplier(caster, spell.value_or(nullptr));
	});
	reg_method(ft, "calcDamageMultiplier", [](SpellEffectInfo const * eff, Unit * caster, std::optional<Spell *> const spell) {
		return eff->CalcDamageMultiplier(caster, spell.value_or(nullptr));
	});
	reg_method(ft, "calcRadius", [](SpellEffectInfo const * eff, std::optional<Unit *> const caster, std::optional<Spell *> const spell) {
		return eff->CalcRadius(caster.value_or(nullptr), spell.value_or(nullptr));
	});
	reg_method(ft, "getMissingTargetMask", [](SpellEffectInfo const * eff, std::optional<bool> const src_set, std::optional<bool> const dest_set, std::optional<uint32_t> const mask) {
		return eff->GetMissingTargetMask(src_set.value_or(false), dest_set.value_or(false), mask.value_or(0));
	});

	return ft;
}
