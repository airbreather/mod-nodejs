#include <array>
#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "Player.h"
#include "SharedDefines.h"
#include "SpellAuraDefines.h"
#include "SpellMgr.h"
#include "Spells/SpellInfo.h"

JVAL_CVAL_TMPLS_RO(SpellInfo const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<SpellInfo const *>() {
	TypedTemplate<SpellInfo const *> const ft = jctor();

	ft->SetClassName(jstr_intern("SpellInfo"));

	reg_static_method(ft, "bySpellId", [](uint32_t const id) {
		return sSpellMgr->GetSpellInfo(id);
	});

	reg_prop_ro(ft, "spellId", [](SpellInfo const * si) {
		return si->Id;
	});
	reg_prop_ro(ft, "categoryEntry", [](SpellInfo const * si) {
		return si->CategoryEntry;
	});
	reg_prop_ro(ft, "dispel", [](SpellInfo const * si) {
		return si->Dispel;
	});
	reg_prop_ro(ft, "mechanic", [](SpellInfo const * si) {
		return si->Mechanic;
	});
	reg_prop_ro(ft, "attributes", [](SpellInfo const * si) {
		return si->Attributes;
	});
	reg_prop_ro(ft, "attributesEx", [](SpellInfo const * si) {
		return si->AttributesEx;
	});
	reg_prop_ro(ft, "attributesEx2", [](SpellInfo const * si) {
		return si->AttributesEx2;
	});
	reg_prop_ro(ft, "attributesEx3", [](SpellInfo const * si) {
		return si->AttributesEx3;
	});
	reg_prop_ro(ft, "attributesEx4", [](SpellInfo const * si) {
		return si->AttributesEx4;
	});
	reg_prop_ro(ft, "attributesEx5", [](SpellInfo const * si) {
		return si->AttributesEx5;
	});
	reg_prop_ro(ft, "attributesEx6", [](SpellInfo const * si) {
		return si->AttributesEx6;
	});
	reg_prop_ro(ft, "attributesEx7", [](SpellInfo const * si) {
		return si->AttributesEx7;
	});
	reg_prop_ro(ft, "attributesCu", [](SpellInfo const * si) {
		return si->AttributesCu;
	});
	reg_prop_ro(ft, "stances", [](SpellInfo const * si) {
		return si->Stances;
	});
	reg_prop_ro(ft, "stancesNot", [](SpellInfo const * si) {
		return si->StancesNot;
	});
	reg_prop_ro(ft, "targets", [](SpellInfo const * si) {
		return si->Targets;
	});
	reg_prop_ro(ft, "targetCreatureType", [](SpellInfo const * si) {
		return si->TargetCreatureType;
	});
	reg_prop_ro(ft, "requiresSpellFocus", [](SpellInfo const * si) {
		return si->RequiresSpellFocus;
	});
	reg_prop_ro(ft, "facingCasterFlags", [](SpellInfo const * si) {
		return si->FacingCasterFlags;
	});
	reg_prop_ro(ft, "casterAuraState", [](SpellInfo const * si) {
		return si->CasterAuraState;
	});
	reg_prop_ro(ft, "targetAuraState", [](SpellInfo const * si) {
		return si->TargetAuraState;
	});
	reg_prop_ro(ft, "casterAuraStateNot", [](SpellInfo const * si) {
		return si->CasterAuraStateNot;
	});
	reg_prop_ro(ft, "targetAuraStateNot", [](SpellInfo const * si) {
		return si->TargetAuraStateNot;
	});
	reg_prop_ro(ft, "casterAuraSpell", [](SpellInfo const * si) {
		return si->CasterAuraSpell;
	});
	reg_prop_ro(ft, "targetAuraSpell", [](SpellInfo const * si) {
		return si->TargetAuraSpell;
	});
	reg_prop_ro(ft, "excludeCasterAuraSpell", [](SpellInfo const * si) {
		return si->ExcludeCasterAuraSpell;
	});
	reg_prop_ro(ft, "excludeTargetAuraSpell", [](SpellInfo const * si) {
		return si->ExcludeTargetAuraSpell;
	});
	reg_prop_ro(ft, "castTimeEntry", [](SpellInfo const * si) {
		return si->CastTimeEntry;
	});
	reg_prop_ro(ft, "recoveryTime", [](SpellInfo const * si) {
		return si->RecoveryTime;
	});
	reg_prop_ro(ft, "categoryRecoveryTime", [](SpellInfo const * si) {
		return si->CategoryRecoveryTime;
	});
	reg_prop_ro(ft, "startRecoveryCategory", [](SpellInfo const * si) {
		return si->StartRecoveryCategory;
	});
	reg_prop_ro(ft, "startRecoveryTime", [](SpellInfo const * si) {
		return si->StartRecoveryTime;
	});
	reg_prop_ro(ft, "interruptFlags", [](SpellInfo const * si) {
		return si->InterruptFlags;
	});
	reg_prop_ro(ft, "auraInterruptFlags", [](SpellInfo const * si) {
		return si->AuraInterruptFlags;
	});
	reg_prop_ro(ft, "channelInterruptFlags", [](SpellInfo const * si) {
		return si->ChannelInterruptFlags;
	});
	reg_prop_ro(ft, "procFlags", [](SpellInfo const * si) {
		return si->ProcFlags;
	});
	reg_prop_ro(ft, "procChance", [](SpellInfo const * si) {
		return si->ProcChance;
	});
	reg_prop_ro(ft, "procCharges", [](SpellInfo const * si) {
		return si->ProcCharges;
	});
	reg_prop_ro(ft, "maxLevel", [](SpellInfo const * si) {
		return si->MaxLevel;
	});
	reg_prop_ro(ft, "baseLevel", [](SpellInfo const * si) {
		return si->BaseLevel;
	});
	reg_prop_ro(ft, "spellLevel", [](SpellInfo const * si) {
		return si->SpellLevel;
	});
	reg_prop_ro(ft, "durationEntry", [](SpellInfo const * si) {
		return si->DurationEntry;
	});
	reg_prop_ro(ft, "powerType", [](SpellInfo const * si) {
		return si->PowerType;
	});
	reg_prop_ro(ft, "manaCost", [](SpellInfo const * si) {
		return si->ManaCost;
	});
	reg_prop_ro(ft, "manaCostPerlevel", [](SpellInfo const * si) {
		return si->ManaCostPerlevel;
	});
	reg_prop_ro(ft, "manaPerSecond", [](SpellInfo const * si) {
		return si->ManaPerSecond;
	});
	reg_prop_ro(ft, "manaPerSecondPerLevel", [](SpellInfo const * si) {
		return si->ManaPerSecondPerLevel;
	});
	reg_prop_ro(ft, "manaCostPercentage", [](SpellInfo const * si) {
		return si->ManaCostPercentage;
	});
	reg_prop_ro(ft, "runeCostID", [](SpellInfo const * si) {
		return si->RuneCostID;
	});
	reg_prop_ro(ft, "rangeEntry", [](SpellInfo const * si) {
		return si->RangeEntry;
	});
	reg_prop_ro(ft, "speed", [](SpellInfo const * si) {
		return si->Speed;
	});
	reg_prop_ro(ft, "stackAmount", [](SpellInfo const * si) {
		return si->StackAmount;
	});
	reg_prop_ro(ft, "totem", [](SpellInfo const * si) {
		return jarr(si->Totem);
	});
	reg_prop_ro(ft, "reagent", [](SpellInfo const * si) {
		return jarr(si->Reagent);
	});
	reg_prop_ro(ft, "reagentCount", [](SpellInfo const * si) {
		return jarr(si->ReagentCount);
	});
	reg_prop_ro(ft, "equippedItemClass", [](SpellInfo const * si) {
		return si->EquippedItemClass;
	});
	reg_prop_ro(ft, "equippedItemSubClassMask", [](SpellInfo const * si) {
		return si->EquippedItemSubClassMask;
	});
	reg_prop_ro(ft, "equippedItemInventoryTypeMask", [](SpellInfo const * si) {
		return si->EquippedItemInventoryTypeMask;
	});
	reg_prop_ro(ft, "totemCategory", [](SpellInfo const * si) {
		return jarr(si->TotemCategory);
	});
	reg_prop_ro(ft, "spellVisual", [](SpellInfo const * si) {
		return jarr(si->SpellVisual);
	});
	reg_prop_ro(ft, "spellIconID", [](SpellInfo const * si) {
		return si->SpellIconID;
	});
	reg_prop_ro(ft, "activeIconID", [](SpellInfo const * si) {
		return si->ActiveIconID;
	});
	reg_prop_ro(ft, "spellPriority", [](SpellInfo const * si) {
		return si->SpellPriority;
	});
	reg_prop_ro(ft, "spellName", [](SpellInfo const * si) {
		return jarr(si->SpellName);
	});
	reg_prop_ro(ft, "rankName", [](SpellInfo const * si) {
		return jarr(si->Rank);
	});
	reg_prop_ro(ft, "maxTargetLevel", [](SpellInfo const * si) {
		return si->MaxTargetLevel;
	});
	reg_prop_ro(ft, "maxAffectedTargets", [](SpellInfo const * si) {
		return si->MaxAffectedTargets;
	});
	reg_prop_ro(ft, "spellFamilyName", [](SpellInfo const * si) {
		return si->SpellFamilyName;
	});
	reg_prop_ro(ft, "spellFamilyFlags", [](SpellInfo const * si) {
		return si->SpellFamilyFlags;
	});
	reg_prop_ro(ft, "dmgClass", [](SpellInfo const * si) {
		return si->DmgClass;
	});
	reg_prop_ro(ft, "preventionType", [](SpellInfo const * si) {
		return si->PreventionType;
	});
	reg_prop_ro(ft, "areaGroupId", [](SpellInfo const * si) {
		return si->AreaGroupId;
	});
	reg_prop_ro(ft, "schoolMask", [](SpellInfo const * si) {
		return si->SchoolMask;
	});
	reg_prop_ro(ft, "effects", [](SpellInfo const * si) {
		return jarr(si->Effects
			| std::ranges::views::transform([](SpellEffectInfo const & eff) { return &eff; })
		);
	});
	reg_prop_ro(ft, "explicitTargetMask", [](SpellInfo const * si) {
		return si->ExplicitTargetMask;
	});
	reg_prop_ro(ft, "chainEntry", [](SpellInfo const * si) {
		return si->ChainEntry;
	});
	reg_prop_ro(ft, "category", [](SpellInfo const * si) {
		return si->GetCategory();
	});
	reg_prop_ro(ft, "isExplicitDiscovery", [](SpellInfo const * si) {
		return si->IsExplicitDiscovery();
	});
	reg_prop_ro(ft, "isLootCrafting", [](SpellInfo const * si) {
		return si->IsLootCrafting();
	});
	reg_prop_ro(ft, "isQuestTame", [](SpellInfo const * si) {
		return si->IsQuestTame();
	});
	reg_prop_ro(ft, "isProfessionOrRiding", [](SpellInfo const * si) {
		return si->IsProfessionOrRiding();
	});
	reg_prop_ro(ft, "isProfession", [](SpellInfo const * si) {
		return si->IsProfession();
	});
	reg_prop_ro(ft, "isPrimaryProfession", [](SpellInfo const * si) {
		return si->IsPrimaryProfession();
	});
	reg_prop_ro(ft, "isPrimaryProfessionFirstRank", [](SpellInfo const * si) {
		return si->IsPrimaryProfessionFirstRank();
	});
	reg_prop_ro(ft, "isAbilityLearnedWithProfession", [](SpellInfo const * si) {
		return si->IsAbilityLearnedWithProfession();
	});
	reg_prop_ro(ft, "isAffectingArea", [](SpellInfo const * si) {
		return si->IsAffectingArea();
	});
	reg_prop_ro(ft, "isTargetingArea", [](SpellInfo const * si) {
		return si->IsTargetingArea();
	});
	reg_prop_ro(ft, "needsExplicitUnitTarget", [](SpellInfo const * si) {
		return si->NeedsExplicitUnitTarget();
	});
	reg_prop_ro(ft, "isChannelCategorySpell", [](SpellInfo const * si) {
		return si->IsChannelCategorySpell();
	});
	reg_prop_ro(ft, "isSelfCast", [](SpellInfo const * si) {
		return si->IsSelfCast();
	});
	reg_prop_ro(ft, "isPassive", [](SpellInfo const * si) {
		return si->IsPassive();
	});
	reg_prop_ro(ft, "isAutocastable", [](SpellInfo const * si) {
		return si->IsAutocastable();
	});
	reg_prop_ro(ft, "isCritCapable", [](SpellInfo const * si) {
		return si->IsCritCapable();
	});
	reg_prop_ro(ft, "requireCooldownInfo", [](SpellInfo const * si) {
		return si->RequireCooldownInfo();
	});
	reg_prop_ro(ft, "isStackableWithRanks", [](SpellInfo const * si) {
		return si->IsStackableWithRanks();
	});
	reg_prop_ro(ft, "isPassiveStackableWithRanks", [](SpellInfo const * si) {
		return si->IsPassiveStackableWithRanks();
	});
	reg_prop_ro(ft, "isMultiSlotAura", [](SpellInfo const * si) {
		return si->IsMultiSlotAura();
	});
	reg_prop_ro(ft, "isCooldownStartedOnEvent", [](SpellInfo const * si) {
		return si->IsCooldownStartedOnEvent();
	});
	reg_prop_ro(ft, "isDeathPersistent", [](SpellInfo const * si) {
		return si->IsDeathPersistent();
	});
	reg_prop_ro(ft, "isRequiringDeadTarget", [](SpellInfo const * si) {
		return si->IsRequiringDeadTarget();
	});
	reg_prop_ro(ft, "isAllowingDeadTarget", [](SpellInfo const * si) {
		return si->IsAllowingDeadTarget();
	});
	reg_prop_ro(ft, "isUsableInCombat", [](SpellInfo const * si) {
		return si->CanBeUsedInCombat();
	});
	reg_prop_ro(ft, "isPositive", [](SpellInfo const * si) {
		return si->IsPositive();
	});
	reg_prop_ro(ft, "isChanneled", [](SpellInfo const * si) {
		return si->IsChanneled();
	});
	reg_prop_ro(ft, "isActionAllowedChannel", [](SpellInfo const * si) {
		return si->IsActionAllowedChannel();
	});
	reg_prop_ro(ft, "needsComboPoints", [](SpellInfo const * si) {
		return si->NeedsComboPoints();
	});
	reg_prop_ro(ft, "isBreakingStealth", [](SpellInfo const * si) {
		return si->IsBreakingStealth();
	});
	reg_prop_ro(ft, "isRangedWeaponSpell", [](SpellInfo const * si) {
		return si->IsRangedWeaponSpell();
	});
	reg_prop_ro(ft, "isAutoRepeatRangedSpell", [](SpellInfo const * si) {
		return si->IsAutoRepeatRangedSpell();
	});
	reg_prop_ro(ft, "hasInitialAggro", [](SpellInfo const * si) {
		return si->HasInitialAggro();
	});
	reg_prop_ro(ft, "isAffectedBySpellMods", [](SpellInfo const * si) {
		return si->IsAffectedBySpellMods();
	});
	reg_prop_ro(ft, "isSingleTarget", [](SpellInfo const * si) {
		return si->IsSingleTarget();
	});
	reg_prop_ro(ft, "allEffectsMechanicMask", [](SpellInfo const * si) {
		return si->GetAllEffectsMechanicMask();
	});
	reg_prop_ro(ft, "hasAnyEffectMechanic", [](SpellInfo const * si) {
		return si->HasAnyEffectMechanic();
	});
	reg_prop_ro(ft, "dispelMask", [](SpellInfo const * si) {
		return si->GetDispelMask();
	});
	reg_prop_ro(ft, "auraState", [](SpellInfo const * si) {
		return si->GetAuraState();
	});
	reg_prop_ro(ft, "spellSpecific", [](SpellInfo const * si) {
		return si->GetSpellSpecific();
	});
	reg_prop_ro(ft, "duration", [](SpellInfo const * si) {
		return si->GetDuration();
	});
	reg_prop_ro(ft, "maxDuration", [](SpellInfo const * si) {
		return si->GetMaxDuration();
	});
	reg_prop_ro(ft, "maxTicks", [](SpellInfo const * si) {
		return si->GetMaxTicks();
	});
	reg_prop_ro(ft, "recoveryTime", [](SpellInfo const * si) {
		return si->GetRecoveryTime();
	});
	reg_prop_ro(ft, "isRanked", [](SpellInfo const * si) {
		return si->IsRanked();
	});
	reg_prop_ro(ft, "rank", [](SpellInfo const * si) {
		return si->GetRank();
	});
	reg_prop_ro(ft, "firsRankSpell", [](SpellInfo const * si) {
		return si->GetFirstRankSpell();
	});
	reg_prop_ro(ft, "lastRankSpell", [](SpellInfo const * si) {
		return si->GetLastRankSpell();
	});
	reg_prop_ro(ft, "nextRankSpell", [](SpellInfo const * si) {
		return si->GetNextRankSpell();
	});
	reg_prop_ro(ft, "prevRankSpell", [](SpellInfo const * si) {
		return si->GetPrevRankSpell();
	});
	reg_prop_ro(ft, "hasAreaAuraEffect", [](SpellInfo const * si) {
		return si->HasAreaAuraEffect();
	});

	reg_method(ft, "hasEffect", [](SpellInfo const * si, SpellEffects const effect) {
		return si->HasEffect(effect);
	});
	reg_method(ft, "hasAura", [](SpellInfo const * si, AuraType const aura) {
		return si->HasAura(aura);
	});
	reg_method(ft, "isAbilityOfSkillType", [](SpellInfo const * si, uint32_t const skillType) {
		return si->IsAbilityOfSkillType(skillType);
	});
	reg_method(ft, "needsToBeTriggeredByCaster", [](SpellInfo const * si, SpellInfo const * trigger, std::optional<uint8_t> eff_index) {
		return si->NeedsToBeTriggeredByCaster(trigger, eff_index.value_or(3));
	});
	reg_method(ft, "isPositiveEffect", [](SpellInfo const * si, uint8_t const effIndex) {
		return si->IsPositiveEffect(effIndex);
	});
	reg_method(ft, "isAffected", [](SpellInfo const * si, uint32_t const family_name, flag96 const family_flags) {
		return si->IsAffected(family_name, family_flags);
	});
	reg_method(ft, "isAffectedBySpellMod", [](SpellInfo const * si, SpellModifier const mod) {
		return si->IsAffectedBySpellMod(&mod);
	});
	reg_method(ft, "canPierceImmuneAura", [](SpellInfo const * si, SpellInfo const * auraSpell) {
		return si->CanPierceImmuneAura(auraSpell);
	});
	reg_method(ft, "canDispelAura", [](SpellInfo const * si, SpellInfo const * auraSpell) {
		return si->CanDispelAura(auraSpell);
	});
	reg_method(ft, "applyAllSpellImmunitiesTo", [](SpellInfo const * si, Unit * target, SpellEffectInfo const * effect, bool const apply) {
		si->ApplyAllSpellImmunitiesTo(target, effect, apply);
	});
	reg_method(ft, "canSpellProvideImmunityAgainstAura", [](SpellInfo const * si, SpellInfo const * aura) {
		return si->CanSpellProvideImmunityAgainstAura(aura);
	});
	reg_method(ft, "canSpellCastOverrideAuraEffect", [](SpellInfo const * si, AuraEffect const * eff) {
		return si->CanSpellCastOverrideAuraEffect(eff);
	});
	reg_method(ft, "isAuraExclusiveBySpecificWith", [](SpellInfo const * si, SpellInfo const * other) {
		return si->IsAuraExclusiveBySpecificWith(other);
	});
	reg_method(ft, "isAuraExclusiveBySpecificPerCasterWith", [](SpellInfo const * si, SpellInfo const * other) {
		return si->IsAuraExclusiveBySpecificPerCasterWith(other);
	});
	reg_method(ft, "checkShapeshift", [](SpellInfo const * si, uint32_t const form) {
		return si->CheckShapeshift(form);
	});
	reg_method(ft, "checkLocation", [](SpellInfo const * si, uint32_t const mapId, uint32_t const zoneId, uint32_t const areaId, std::optional<Player *> const player, std::optional<bool> const strict) {
		return si->CheckLocation(mapId, zoneId, areaId, player.value_or(nullptr), strict.value_or(true));
	});
	reg_method(ft, "checkTarget", [](SpellInfo const * si, Unit * caster, WorldObject const * target, std::optional<bool> const implicit) {
		return si->CheckTarget(caster, target, implicit.value_or(true));
	});
	reg_method(ft, "checkExplicitTarget", [](SpellInfo const * si, Unit * caster, WorldObject const * target, std::optional<Item *> const itemTarget) {
		return si->CheckExplicitTarget(caster, target, itemTarget.value_or(nullptr));
	});
	reg_method(ft, "checkTargetCreatureType", [](SpellInfo const * si, Unit * target) {
		return si->CheckTargetCreatureType(target);
	});
	reg_method(ft, "isAuraEffectEqual", [](SpellInfo const * si, SpellInfo const * other) {
		return si->IsAuraEffectEqual(other);
	});
	reg_method(ft, "validateAttribute6SpellDamageMods", [](SpellInfo const * si, Unit * caster, AuraEffect const * eff, bool const is_dot) {
		return si->ValidateAttribute6SpellDamageMods(caster, eff, is_dot);
	});
	reg_method(ft, "getEffectMechanicMask", [](SpellInfo const * si, uint8_t const effIndex) {
		return si->GetEffectMechanicMask(effIndex);
	});
	reg_method(ft, "getSpellMechanicMaskByEffectMask", [](SpellInfo const * si, uint32_t const effectMask) {
		return si->GetSpellMechanicMaskByEffectMask(effectMask);
	});
	reg_method(ft, "getEffectMechanic", [](SpellInfo const * si, uint8_t const effIndex) {
		return si->GetEffectMechanic(effIndex);
	});
	reg_method(ft, "getImmunityInfo", [](SpellInfo const * si, uint8_t const eff_index) {
		return si->GetImmunityInfo(eff_index);
	});
	reg_method(ft, "getMinRange", [](SpellInfo const * si, std::optional<bool> const positive) {
		return si->GetMinRange(positive.value_or(false));
	});
	reg_method(ft, "getMaxRange", [](SpellInfo const * si, std::optional<bool> const positive, std::optional<Unit *> const caster, std::optional<Spell *> const spell) {
		return si->GetMaxRange(positive.value_or(false), caster.value_or(nullptr), spell.value_or(nullptr));
	});
	reg_method(ft, "calcCastTime", [](SpellInfo const * si, std::optional<Unit *> const caster, std::optional<Spell *> const spell) {
		return si->CalcCastTime(caster.value_or(nullptr), spell.value_or(nullptr));
	});
	reg_method(ft, "calcPowerCost", [](SpellInfo const * si, Unit * caster, SpellSchoolMask const school_mask, std::optional<Spell *> const spell) {
		return si->CalcPowerCost(caster, school_mask, spell.value_or(nullptr));
	});
	reg_method(ft, "getAuraRankForLevel", [](SpellInfo const * si, uint8_t const level) {
		return si->GetAuraRankForLevel(level);
	});
	reg_method(ft, "isRankOf", [](SpellInfo const * si, SpellInfo const * other) {
		return si->IsRankOf(other);
	});
	reg_method(ft, "isDifferentRankOf", [](SpellInfo const * si, SpellInfo const * other) {
		return si->IsDifferentRankOf(other);
	});
	reg_method(ft, "isHighRankOf", [](SpellInfo const * si, SpellInfo const * other) {
		return si->IsHighRankOf(other);
	});
	reg_method(ft, "getEffect", [](SpellInfo const * si, SpellEffIndex const i) {
		return &si->GetEffect(i);
	});
	return ft;
}
