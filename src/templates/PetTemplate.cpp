#include <chrono>
#include <optional>
#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CharmInfo.h"
#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "PetDefines.h"
#include "SharedDefines.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"

JVAL_CVAL_TMPLS_RW(Pet)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Pet *>() {
	TypedTemplate<Pet *> const ft = jctor();

	ft->SetClassName(jstr_intern("Pet"));
	ft.safe_inherit<Guardian *>();

	reg_prop_ro(ft, "isHappy", [](Pet * pet) {
		return pet->GetHappinessState() == HAPPY;
	});
	reg_prop_ro(ft, "owner", [](Pet * pet) {
		// ...why does Pet shadow Minion's perfectly usable GetOwner()?
		// ...why does Minion shadow Unit's perfectly usable GetOwner()?
		return pet->GetOwner();
	});
	reg_prop_ro(ft, "isControlled", [](Pet * pet) {
		return pet->isControlled();
	});
	reg_prop_ro(ft, "isTemporary", [](Pet * pet) {
		return pet->isTemporarySummoned();
	});
	reg_prop_ro(ft, "hasTempSpell", [](Pet * pet) {
		return pet->HasTempSpell();
	});
	reg_prop_ro(ft, "autoSpellSize", [](Pet * pet) {
		return pet->GetPetAutoSpellSize();
	});
	reg_prop_ro(ft, "generateActionBarData", [](Pet * pet) {
		return pet->GenerateActionBarData();
	});
	reg_prop_ro(ft, "owner", [](Pet * pet) {
		return pet->GetOwner();
	});
	reg_prop_ro(ft, "petInfo", [](Pet * pet) {
		PetStable::PetInfo info;
		pet->FillPetInfo(&info);
		return info;
	});
	reg_prop_ro(ft, "spells", [](Pet * pet) {
		return jmap(pet->m_spells);
	});
	reg_prop_ro(ft, "autospells", [](Pet * pet) {
		return jarr(pet->m_autospells);
	});
	reg_prop_ro(ft, "usedTalentCount", [](Pet * pet) {
		// this is technically settable, but it looks like it really shouldn't have been.
		return pet->m_usedTalentCount;
	});
	reg_prop_ro(ft, "declinedNames", [](Pet * pet) {
		return jarr(pet->GetDeclinedNames()->name);
	});

	reg_method(ft, "isPermanentPetFor", [](Pet * pet, Player * owner) {
		return pet->IsPermanentPetFor(owner);
	});
	reg_method(ft, "getCurrentFoodBenefitLevel", [](Pet * pet, uint32_t const itemLevel) {
		return pet->GetCurrentFoodBenefitLevel(itemLevel);
	});
	reg_method(ft, "getAutoSpellOnPos", [](Pet * pet, uint32_t const pos) {
		return pet->GetPetAutoSpellOnPos(pos);
	});
	reg_method(ft, "haveInDiet", [](Pet * pet, ItemTemplate const * item) {
		return pet->HaveInDiet(item);
	});

	reg_prop(ft, "petType",
		[](Pet * pet) { return pet->getPetType(); },
		[](Pet * pet, PetType const type) { pet->setPetType(type); }
	);
	reg_prop(ft, "isBeingLoaded",
		[](Pet * pet) { return pet->isBeingLoaded(); },
		[](Pet * pet, auto v) { pet->SetLoading(v); }
	);
	reg_prop(ft, "durationMilliseconds",
		[](Pet * pet) { return pet->GetDuration().count(); },
		[](Pet * pet, std::chrono::seconds::rep const ms) { pet->SetDuration(std::chrono::milliseconds(ms)); }
	);
	reg_prop(ft, "freeTalentPoints",
		[](Pet * pet) { return pet->GetFreeTalentPoints(); },
		[](Pet * pet, uint8_t const points) { pet->SetFreeTalentPoints(points); }
	);
	reg_prop(ft, "happinessState",
		[](Pet * pet) { return pet->GetHappinessState(); },
		[](Pet * pet, HappinessState const h) { pet->SetPower(POWER_HAPPINESS, h * HAPPINESS_LEVEL_SIZE - 1); }
	);
	reg_prop(ft, "auraUpdateMaskForRaid",
		[](Pet * pet) { return pet->GetAuraUpdateMaskForRaid(); },
		[](Pet * pet, auto v) { pet->SetAuraUpdateMaskForRaid(v); }
	);

	reg_method(ft, "createBaseAtCreature", [](Pet * pet, Creature * creature) {
		return pet->CreateBaseAtCreature(creature);
	});
	reg_method(ft, "givePetXP", [](Pet * pet, uint32_t const xp) {
		pet->GivePetXP(xp);
	});
	reg_method(ft, "givePetLevel", [](Pet * pet, uint8_t const level) {
		pet->GivePetLevel(level);
	});
	reg_method(ft, "synchronizeLevelWithOwner", [](Pet * pet) {
		pet->SynchronizeLevelWithOwner();
	});
	reg_method(ft, "toggleAutocast", [](Pet * pet, SpellInfo const * spellInfo, bool const apply) {
		pet->ToggleAutocast(spellInfo, apply);
	});
	reg_method(ft, "learnPetPassives", [](Pet * pet) {
		pet->LearnPetPassives();
	});
	reg_method(ft, "castWhenWillAvailable", [](Pet * pet, uint32_t const spellId, Unit * target, ObjectGuid const oldTarget, std::optional<bool> const isPositive) {
		pet->CastWhenWillAvailable(spellId, target, oldTarget, isPositive.value_or(false));
	});
	reg_method(ft, "clearCastWhenWillAvailable", [](Pet * pet) {
		pet->ClearCastWhenWillAvailable();
	});
	reg_method(ft, "removeSpellCooldown", [](Pet * pet, uint32_t const spell_id, bool const update) {
		pet->RemoveSpellCooldown(spell_id, update);
	});
	reg_method(ft, "addSpell", [](Pet * pet, uint32_t const spellId, std::optional<ActiveStates> const activeOpt, std::optional<PetSpellState> const stateOpt, std::optional<PetSpellType> const typeOpt) {
		return pet->addSpell(spellId, activeOpt.value_or(ACT_DECIDE), stateOpt.value_or(PETSPELL_NEW), typeOpt.value_or(PETSPELL_NORMAL));
	});
	reg_method(ft, "learnSpell", [](Pet * pet, uint32_t const spellId) {
		return pet->learnSpell(spellId);
	});
	reg_method(ft, "learnSpellHighRank", [](Pet * pet, uint32_t const spellId) {
		pet->learnSpellHighRank(spellId);
	});
	reg_method(ft, "initLevelupSpellsForLevel", [](Pet * pet) {
		pet->InitLevelupSpellsForLevel();
	});
	reg_method(ft, "unlearnSpell", [](Pet * pet, uint32_t const spellId, bool const learnPrev, std::optional<bool> const clearAb) {
		return pet->unlearnSpell(spellId, learnPrev, clearAb.value_or(true));
	});
	reg_method(ft, "removeSpell", [](Pet * pet, uint32_t const spellId, bool const learnPrev, std::optional<bool> const clearAb) {
		return pet->removeSpell(spellId, learnPrev, clearAb.value_or(true));
	});
	reg_method(ft, "cleanupActionBar", [](Pet * pet) {
		pet->CleanupActionBar();
	});
	reg_method(ft, "initPetCreateSpells", [](Pet * pet) {
		pet->InitPetCreateSpells();
	});
	reg_method(ft, "resetTalents", [](Pet * pet) {
		return pet->resetTalents();
	});
	reg_method(ft, "initTalentForLevel", [](Pet * pet) {
		pet->InitTalentForLevel();
	});
	reg_method(ft, "savePetToDB", [](Pet * pet, PetSaveMode const mode) {
		pet->SavePetToDB(mode);
	});
	reg_method(ft, "loseHappiness", [](Pet * pet) {
		pet->LoseHappiness();
	});
	reg_method(ft, "remove", [](Pet * pet, PetSaveMode const mode, std::optional<bool> const returnReagent) {
		pet->Remove(mode, returnReagent.value_or(false));
	});
	reg_method(ft, "toggleAutocast", [](Pet * pet, SpellInfo const * spellInfo, bool const apply) {
		pet->ToggleAutocast(spellInfo, apply);
	});
	reg_method(ft, "castPetAuras", [](Pet * pet, bool const current) {
		pet->CastPetAuras(current);
	});
	reg_method(ft, "getMaxTalentPointsForLevel", [](Pet * pet, uint8_t const level) {
		pet->GetMaxTalentPointsForLevel(level);
	});
	reg_method(ft, "resetAuraUpdateMaskForRaid", [](Pet * pet) {
		pet->ResetAuraUpdateMaskForRaid();
	});

	return ft;
}
