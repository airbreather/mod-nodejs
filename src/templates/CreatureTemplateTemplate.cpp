#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CreatureAI.h"
#include "CreatureData.h"
#include "CtoJ.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(CreatureTemplate)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<CreatureTemplate const *>() {
	TypedTemplate<CreatureTemplate const *> const ft = jctor();

	ft->SetClassName(jstr_intern("CreatureTemplate"));

	reg_prop_ro(ft, "entry", [](CreatureTemplate const * ct) {
		return ct->Entry;
	});
	reg_prop_ro(ft, "difficultyEntry", [](CreatureTemplate const * ct) {
		return jarr(ct->DifficultyEntry);
	});
	reg_prop_ro(ft, "killCredit", [](CreatureTemplate const * ct) {
		return jarr(ct->KillCredit);
	});
	reg_prop_ro(ft, "models", [](CreatureTemplate const * ct) {
		return jarr(ct->Models);
	});
	reg_prop_ro(ft, "name", [](CreatureTemplate const * ct) {
		return ct->Name;
	});
	reg_prop_ro(ft, "subName", [](CreatureTemplate const * ct) {
		return ct->SubName;
	});
	reg_prop_ro(ft, "iconName", [](CreatureTemplate const * ct) {
		return ct->IconName;
	});
	reg_prop_ro(ft, "gossipMenuId", [](CreatureTemplate const * ct) {
		return ct->GossipMenuId;
	});
	reg_prop_ro(ft, "minLevel", [](CreatureTemplate const * ct) {
		return ct->minlevel;
	});
	reg_prop_ro(ft, "maxLevel", [](CreatureTemplate const * ct) {
		return ct->maxlevel;
	});
	reg_prop_ro(ft, "expansion", [](CreatureTemplate const * ct) {
		return ct->expansion;
	});
	reg_prop_ro(ft, "faction", [](CreatureTemplate const * ct) {
		return ct->faction;
	});
	reg_prop_ro(ft, "npcFlag", [](CreatureTemplate const * ct) {
		return ct->npcflag;
	});
	reg_prop_ro(ft, "speedWalk", [](CreatureTemplate const * ct) {
		return ct->speed_walk;
	});
	reg_prop_ro(ft, "speedRun", [](CreatureTemplate const * ct) {
		return ct->speed_run;
	});
	reg_prop_ro(ft, "speedSwim", [](CreatureTemplate const * ct) {
		return ct->speed_swim;
	});
	reg_prop_ro(ft, "speedFlight", [](CreatureTemplate const * ct) {
		return ct->speed_flight;
	});
	reg_prop_ro(ft, "detectionRange", [](CreatureTemplate const * ct) {
		return ct->detection_range;
	});
	reg_prop_ro(ft, "rank", [](CreatureTemplate const * ct) {
		return ct->rank;
	});
	reg_prop_ro(ft, "dmgSchool", [](CreatureTemplate const * ct) {
		return ct->dmgschool;
	});
	reg_prop_ro(ft, "damageModifier", [](CreatureTemplate const * ct) {
		return ct->DamageModifier;
	});
	reg_prop_ro(ft, "baseAttackTime", [](CreatureTemplate const * ct) {
		return ct->BaseAttackTime;
	});
	reg_prop_ro(ft, "rangeAttackTime", [](CreatureTemplate const * ct) {
		return ct->RangeAttackTime;
	});
	reg_prop_ro(ft, "baseVariance", [](CreatureTemplate const * ct) {
		return ct->BaseVariance;
	});
	reg_prop_ro(ft, "rangeVariance", [](CreatureTemplate const * ct) {
		return ct->RangeVariance;
	});
	reg_prop_ro(ft, "unitClass", [](CreatureTemplate const * ct) {
		return ct->unit_class;
	});
	reg_prop_ro(ft, "unitFlags", [](CreatureTemplate const * ct) {
		return ct->unit_flags;
	});
	reg_prop_ro(ft, "unitFlags2", [](CreatureTemplate const * ct) {
		return ct->unit_flags2;
	});
	reg_prop_ro(ft, "dynamicFlags", [](CreatureTemplate const * ct) {
		return ct->dynamicflags;
	});
	reg_prop_ro(ft, "family", [](CreatureTemplate const * ct) {
		return ct->family;
	});
	reg_prop_ro(ft, "creatureType", [](CreatureTemplate const * ct) {
		// renamed because "type" is a keyword in TypeScript.
		return ct->type;
	});
	reg_prop_ro(ft, "creatureTypeFlags", [](CreatureTemplate const * ct) {
		// renamed to be consistent with "creatureType".
		return ct->type_flags;
	});
	reg_prop_ro(ft, "lootId", [](CreatureTemplate const * ct) {
		return ct->lootid;
	});
	reg_prop_ro(ft, "pickpocketLootId", [](CreatureTemplate const * ct) {
		return ct->pickpocketLootId;
	});
	reg_prop_ro(ft, "skinLootId", [](CreatureTemplate const * ct) {
		return ct->SkinLootId;
	});
	reg_prop_ro(ft, "resistance", [](CreatureTemplate const * ct) {
		return jarr(ct->resistance);
	});
	reg_prop_ro(ft, "spells", [](CreatureTemplate const * ct) {
		return jarr(ct->spells);
	});
	reg_prop_ro(ft, "petSpellDataId", [](CreatureTemplate const * ct) {
		return ct->PetSpellDataId;
	});
	reg_prop_ro(ft, "vehicleId", [](CreatureTemplate const * ct) {
		return ct->VehicleId;
	});
	reg_prop_ro(ft, "minGold", [](CreatureTemplate const * ct) {
		return ct->mingold;
	});
	reg_prop_ro(ft, "maxGold", [](CreatureTemplate const * ct) {
		return ct->maxgold;
	});
	reg_prop_ro(ft, "movementType", [](CreatureTemplate const * ct) {
		return ct->MovementType;
	});
	reg_prop_ro(ft, "movement", [](CreatureTemplate const * ct) {
		return ct->Movement;
	});
	reg_prop_ro(ft, "hoverHeight", [](CreatureTemplate const * ct) {
		return ct->HoverHeight;
	});
	reg_prop_ro(ft, "modHealth", [](CreatureTemplate const * ct) {
		return ct->ModHealth;
	});
	reg_prop_ro(ft, "modMana", [](CreatureTemplate const * ct) {
		return ct->ModMana;
	});
	reg_prop_ro(ft, "modArmor", [](CreatureTemplate const * ct) {
		return ct->ModArmor;
	});
	reg_prop_ro(ft, "modExperience", [](CreatureTemplate const * ct) {
		return ct->ModExperience;
	});
	reg_prop_ro(ft, "racialLeader", [](CreatureTemplate const * ct) {
		return ct->RacialLeader;
	});
	reg_prop_ro(ft, "movementId", [](CreatureTemplate const * ct) {
		return ct->movementId;
	});
	reg_prop_ro(ft, "regenHealth", [](CreatureTemplate const * ct) {
		return ct->RegenHealth;
	});
	reg_prop_ro(ft, "creatureImmunitiesId", [](CreatureTemplate const * ct) {
		return ct->CreatureImmunitiesId;
	});
	reg_prop_ro(ft, "flagsExtra", [](CreatureTemplate const * ct) {
		return ct->flags_extra;
	});
	reg_prop_ro(ft, "scriptId", [](CreatureTemplate const * ct) {
		return ct->ScriptID;
	});
	reg_prop_ro(ft, "requiredLootSkill", [](CreatureTemplate const * ct) {
		return ct->GetRequiredLootSkill();
	});
	reg_prop_ro(ft, "isExotic", [](CreatureTemplate const * ct) {
		return ct->IsExotic();
	});

	reg_method(ft, "getModelByIdx", [](CreatureTemplate const * ct, uint32_t idx) {
		return ct->GetModelByIdx(idx);
	});
	reg_method(ft, "getRandomValidModel", [](CreatureTemplate const * ct) {
		return ct->GetRandomValidModel();
	});
	reg_method(ft, "getFirstValidModel", [](CreatureTemplate const * ct) {
		return ct->GetFirstValidModel();
	});
	reg_method(ft, "getModelWithDisplayId", [](CreatureTemplate const * ct, uint32_t display_id) {
		return ct->GetModelWithDisplayId(display_id);
	});
	reg_method(ft, "getFirstInvisibleModel", [](CreatureTemplate const * ct) {
		return ct->GetFirstInvisibleModel();
	});
	reg_method(ft, "getFirstVisibleModel", [](CreatureTemplate const * ct) {
		return ct->GetFirstVisibleModel();
	});
	reg_method(ft, "isTameable", [](CreatureTemplate const * ct, bool exotic) {
		return ct->IsTameable(exotic);
	});
	reg_method(ft, "hasFlagsExtra", [](CreatureTemplate const * ct, uint32_t flag) {
		return ct->HasFlagsExtra(flag);
	});

	return ft;
}
