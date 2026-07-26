#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "DBCStructure.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(SpellEntry const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<SpellEntry const *>() {
	TypedTemplate<SpellEntry const *> const ft = jctor();

	ft->SetClassName(jstr_intern("SpellEntry"));

	reg_prop_ro(ft, "id", [](SpellEntry const * se) {
		return se->Id;
	});
	reg_prop_ro(ft, "category", [](SpellEntry const * se) {
		return se->Category;
	});
	reg_prop_ro(ft, "dispel", [](SpellEntry const * se) {
		return se->Dispel;
	});
	reg_prop_ro(ft, "mechanic", [](SpellEntry const * se) {
		return se->Mechanic;
	});
	reg_prop_ro(ft, "attributes", [](SpellEntry const * se) {
		return se->Attributes;
	});
	reg_prop_ro(ft, "attributesEx", [](SpellEntry const * se) {
		return se->AttributesEx;
	});
	reg_prop_ro(ft, "attributesEx2", [](SpellEntry const * se) {
		return se->AttributesEx2;
	});
	reg_prop_ro(ft, "attributesEx3", [](SpellEntry const * se) {
		return se->AttributesEx3;
	});
	reg_prop_ro(ft, "attributesEx4", [](SpellEntry const * se) {
		return se->AttributesEx4;
	});
	reg_prop_ro(ft, "attributesEx5", [](SpellEntry const * se) {
		return se->AttributesEx5;
	});
	reg_prop_ro(ft, "attributesEx6", [](SpellEntry const * se) {
		return se->AttributesEx6;
	});
	reg_prop_ro(ft, "attributesEx7", [](SpellEntry const * se) {
		return se->AttributesEx7;
	});
	reg_prop_ro(ft, "stances", [](SpellEntry const * se) {
		return se->Stances;
	});
	reg_prop_ro(ft, "stancesNot", [](SpellEntry const * se) {
		return se->StancesNot;
	});
	reg_prop_ro(ft, "targets", [](SpellEntry const * se) {
		return se->Targets;
	});
	reg_prop_ro(ft, "targetCreatureType", [](SpellEntry const * se) {
		return se->TargetCreatureType;
	});
	reg_prop_ro(ft, "requiresSpellFocus", [](SpellEntry const * se) {
		return se->RequiresSpellFocus;
	});
	reg_prop_ro(ft, "facingCasterFlags", [](SpellEntry const * se) {
		return se->FacingCasterFlags;
	});
	reg_prop_ro(ft, "casterAuraState", [](SpellEntry const * se) {
		return se->CasterAuraState;
	});
	reg_prop_ro(ft, "targetAuraState", [](SpellEntry const * se) {
		return se->TargetAuraState;
	});
	reg_prop_ro(ft, "casterAuraStateNot", [](SpellEntry const * se) {
		return se->CasterAuraStateNot;
	});
	reg_prop_ro(ft, "targetAuraStateNot", [](SpellEntry const * se) {
		return se->TargetAuraStateNot;
	});
	reg_prop_ro(ft, "casterAuraSpell", [](SpellEntry const * se) {
		return se->CasterAuraSpell;
	});
	reg_prop_ro(ft, "targetAuraSpell", [](SpellEntry const * se) {
		return se->TargetAuraSpell;
	});
	reg_prop_ro(ft, "excludeCasterAuraSpell", [](SpellEntry const * se) {
		return se->ExcludeCasterAuraSpell;
	});
	reg_prop_ro(ft, "excludeTargetAuraSpell", [](SpellEntry const * se) {
		return se->ExcludeTargetAuraSpell;
	});
	reg_prop_ro(ft, "castingTimeIndex", [](SpellEntry const * se) {
		return se->CastingTimeIndex;
	});
	reg_prop_ro(ft, "recoveryTime", [](SpellEntry const * se) {
		return se->RecoveryTime;
	});
	reg_prop_ro(ft, "categoryRecoveryTime", [](SpellEntry const * se) {
		return se->CategoryRecoveryTime;
	});
	reg_prop_ro(ft, "interruptFlags", [](SpellEntry const * se) {
		return se->InterruptFlags;
	});
	reg_prop_ro(ft, "auraInterruptFlags", [](SpellEntry const * se) {
		return se->AuraInterruptFlags;
	});
	reg_prop_ro(ft, "channelInterruptFlags", [](SpellEntry const * se) {
		return se->ChannelInterruptFlags;
	});
	reg_prop_ro(ft, "procFlags", [](SpellEntry const * se) {
		return se->ProcFlags;
	});
	reg_prop_ro(ft, "procChance", [](SpellEntry const * se) {
		return se->ProcChance;
	});
	reg_prop_ro(ft, "procCharges", [](SpellEntry const * se) {
		return se->ProcCharges;
	});
	reg_prop_ro(ft, "maxLevel", [](SpellEntry const * se) {
		return se->MaxLevel;
	});
	reg_prop_ro(ft, "baseLevel", [](SpellEntry const * se) {
		return se->BaseLevel;
	});
	reg_prop_ro(ft, "spellLevel", [](SpellEntry const * se) {
		return se->SpellLevel;
	});
	reg_prop_ro(ft, "durationIndex", [](SpellEntry const * se) {
		return se->DurationIndex;
	});
	reg_prop_ro(ft, "powerType", [](SpellEntry const * se) {
		return se->PowerType;
	});
	reg_prop_ro(ft, "manaCost", [](SpellEntry const * se) {
		return se->ManaCost;
	});
	reg_prop_ro(ft, "manaCostPerlevel", [](SpellEntry const * se) {
		return se->ManaCostPerlevel;
	});
	reg_prop_ro(ft, "manaPerSecond", [](SpellEntry const * se) {
		return se->ManaPerSecond;
	});
	reg_prop_ro(ft, "manaPerSecondPerLevel", [](SpellEntry const * se) {
		return se->ManaPerSecondPerLevel;
	});
	reg_prop_ro(ft, "rangeIndex", [](SpellEntry const * se) {
		return se->RangeIndex;
	});
	reg_prop_ro(ft, "speed", [](SpellEntry const * se) {
		return se->Speed;
	});
	reg_prop_ro(ft, "stackAmount", [](SpellEntry const * se) {
		return se->StackAmount;
	});
	reg_prop_ro(ft, "manaCostPercentage", [](SpellEntry const * se) {
		return se->ManaCostPercentage;
	});
	reg_prop_ro(ft, "startRecoveryCategory", [](SpellEntry const * se) {
		return se->StartRecoveryCategory;
	});
	reg_prop_ro(ft, "startRecoveryTime", [](SpellEntry const * se) {
		return se->StartRecoveryTime;
	});
	reg_prop_ro(ft, "maxTargetLevel", [](SpellEntry const * se) {
		return se->MaxTargetLevel;
	});
	reg_prop_ro(ft, "spellFamilyName", [](SpellEntry const * se) {
		return se->SpellFamilyName;
	});
	reg_prop_ro(ft, "maxAffectedTargets", [](SpellEntry const * se) {
		return se->MaxAffectedTargets;
	});
	reg_prop_ro(ft, "dmgClass", [](SpellEntry const * se) {
		return se->DmgClass;
	});
	reg_prop_ro(ft, "preventionType", [](SpellEntry const * se) {
		return se->PreventionType;
	});
	reg_prop_ro(ft, "areaGroupId", [](SpellEntry const * se) {
		return se->AreaGroupId;
	});
	reg_prop_ro(ft, "schoolMask", [](SpellEntry const * se) {
		return se->SchoolMask;
	});
	reg_prop_ro(ft, "spellIconID", [](SpellEntry const * se) {
		return se->SpellIconID;
	});
	reg_prop_ro(ft, "activeIconID", [](SpellEntry const * se) {
		return se->ActiveIconID;
	});
	reg_prop_ro(ft, "spellPriority", [](SpellEntry const * se) {
		return se->SpellPriority;
	});
	reg_prop_ro(ft, "equippedItemClass", [](SpellEntry const * se) {
		return se->EquippedItemClass;
	});
	reg_prop_ro(ft, "equippedItemSubClassMask", [](SpellEntry const * se) {
		return se->EquippedItemSubClassMask;
	});
	reg_prop_ro(ft, "equippedItemInventoryTypeMask", [](SpellEntry const * se) {
		return se->EquippedItemInventoryTypeMask;
	});
	reg_prop_ro(ft, "spellFamilyFlags", [](SpellEntry const * se) {
		return se->SpellFamilyFlags;
	});
	reg_prop_ro(ft, "totem", [](SpellEntry const * se) {
		return jarr(se->Totem);
	});
	reg_prop_ro(ft, "reagent", [](SpellEntry const * se) {
		return jarr(se->Reagent);
	});
	reg_prop_ro(ft, "reagentCount", [](SpellEntry const * se) {
		return jarr(se->ReagentCount);
	});
	reg_prop_ro(ft, "effect", [](SpellEntry const * se) {
		return jarr(se->Effect);
	});
	reg_prop_ro(ft, "effectDieSides", [](SpellEntry const * se) {
		return jarr(se->EffectDieSides);
	});
	reg_prop_ro(ft, "effectRealPointsPerLevel", [](SpellEntry const * se) {
		return jarr(se->EffectRealPointsPerLevel);
	});
	reg_prop_ro(ft, "effectBasePoints", [](SpellEntry const * se) {
		return jarr(se->EffectBasePoints);
	});
	reg_prop_ro(ft, "effectMechanic", [](SpellEntry const * se) {
		return jarr(se->EffectMechanic);
	});
	reg_prop_ro(ft, "effectImplicitTargetA", [](SpellEntry const * se) {
		return jarr(se->EffectImplicitTargetA);
	});
	reg_prop_ro(ft, "effectImplicitTargetB", [](SpellEntry const * se) {
		return jarr(se->EffectImplicitTargetB);
	});
	reg_prop_ro(ft, "effectRadiusIndex", [](SpellEntry const * se) {
		return jarr(se->EffectRadiusIndex);
	});
	reg_prop_ro(ft, "effectApplyAuraName", [](SpellEntry const * se) {
		return jarr(se->EffectApplyAuraName);
	});
	reg_prop_ro(ft, "effectAmplitude", [](SpellEntry const * se) {
		return jarr(se->EffectAmplitude);
	});
	reg_prop_ro(ft, "effectValueMultiplier", [](SpellEntry const * se) {
		return jarr(se->EffectValueMultiplier);
	});
	reg_prop_ro(ft, "effectChainTarget", [](SpellEntry const * se) {
		return jarr(se->EffectChainTarget);
	});
	reg_prop_ro(ft, "effectItemType", [](SpellEntry const * se) {
		return jarr(se->EffectItemType);
	});
	reg_prop_ro(ft, "effectMiscValue", [](SpellEntry const * se) {
		return jarr(se->EffectMiscValue);
	});
	reg_prop_ro(ft, "effectMiscValueB", [](SpellEntry const * se) {
		return jarr(se->EffectMiscValueB);
	});
	reg_prop_ro(ft, "effectTriggerSpell", [](SpellEntry const * se) {
		return jarr(se->EffectTriggerSpell);
	});
	reg_prop_ro(ft, "effectPointsPerComboPoint", [](SpellEntry const * se) {
		return jarr(se->EffectPointsPerComboPoint);
	});
	reg_prop_ro(ft, "effectDamageMultiplier", [](SpellEntry const * se) {
		return jarr(se->EffectDamageMultiplier);
	});
	reg_prop_ro(ft, "spellVisual", [](SpellEntry const * se) {
		return jarr(se->SpellVisual);
	});
	reg_prop_ro(ft, "spellName", [](SpellEntry const * se) {
		return jarr(se->SpellName);
	});
	reg_prop_ro(ft, "rank", [](SpellEntry const * se) {
		return jarr(se->Rank);
	});
	reg_prop_ro(ft, "totemCategory", [](SpellEntry const * se) {
		return jarr(se->TotemCategory);
	});
	reg_prop_ro(ft, "effectSpellClassMask", [](SpellEntry const * se) {
		return jarr(se->EffectSpellClassMask);
	});

	return ft;
}
