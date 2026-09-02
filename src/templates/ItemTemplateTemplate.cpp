#include "CtoJ.h"
#include "DurationWrapper.h"
#include "ItemTemplate.h"
#include "NodePropertySystem.h"
#include "ObjectMgr.h"

JVAL_CVAL_TMPLS_RO(ItemTemplate const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<ItemTemplate const *>() {
	TypedTemplate<ItemTemplate const *> const ft = jctor();

	ft->SetClassName(jstr_intern("ItemTemplate"));

	reg_static_method(ft, "byId", [](uint32_t id) {
		return sObjectMgr->GetItemTemplate(id);
	});

	reg_prop_ro(ft, "itemId", [](ItemTemplate const * it) {
		return it->ItemId;
	});
	reg_prop_ro(ft, "clazz", [](ItemTemplate const * it) {
		return it->Class;
	});
	reg_prop_ro(ft, "subClass", [](ItemTemplate const * it) {
		return it->SubClass;
	});
	reg_prop_ro(ft, "soundOverrideSubclass", [](ItemTemplate const * it) {
		return it->SoundOverrideSubclass;
	});
	reg_prop_ro(ft, "name1", [](ItemTemplate const * it) {
		return it->Name1;
	});
	reg_prop_ro(ft, "displayInfoId", [](ItemTemplate const * it) {
		return it->DisplayInfoID;
	});
	reg_prop_ro(ft, "quality", [](ItemTemplate const * it) {
		return it->Quality;
	});
	reg_prop_ro(ft, "flags", [](ItemTemplate const * it) {
		return it->Flags;
	});
	reg_prop_ro(ft, "flags2", [](ItemTemplate const * it) {
		return it->Flags2;
	});
	reg_prop_ro(ft, "buyCount", [](ItemTemplate const * it) {
		return it->BuyCount;
	});
	reg_prop_ro(ft, "buyPrice", [](ItemTemplate const * it) {
		return it->BuyPrice;
	});
	reg_prop_ro(ft, "sellPrice", [](ItemTemplate const * it) {
		return it->SellPrice;
	});
	reg_prop_ro(ft, "inventoryType", [](ItemTemplate const * it) {
		return it->InventoryType;
	});
	reg_prop_ro(ft, "allowableClass", [](ItemTemplate const * it) {
		return it->AllowableClass;
	});
	reg_prop_ro(ft, "allowableRace", [](ItemTemplate const * it) {
		return it->AllowableRace;
	});
	reg_prop_ro(ft, "itemLevel", [](ItemTemplate const * it) {
		return it->ItemLevel;
	});
	reg_prop_ro(ft, "requiredLevel", [](ItemTemplate const * it) {
		return it->RequiredLevel;
	});
	reg_prop_ro(ft, "requiredSkill", [](ItemTemplate const * it) {
		return it->RequiredSkill;
	});
	reg_prop_ro(ft, "requiredSkillRank", [](ItemTemplate const * it) {
		return it->RequiredSkillRank;
	});
	reg_prop_ro(ft, "requiredSpell", [](ItemTemplate const * it) {
		return it->RequiredSpell;
	});
	reg_prop_ro(ft, "requiredHonorRank", [](ItemTemplate const * it) {
		return it->RequiredHonorRank;
	});
	reg_prop_ro(ft, "requiredCityRank", [](ItemTemplate const * it) {
		return it->RequiredCityRank;
	});
	reg_prop_ro(ft, "requiredReputationFaction", [](ItemTemplate const * it) {
		return it->RequiredReputationFaction;
	});
	reg_prop_ro(ft, "requiredReputationRank", [](ItemTemplate const * it) {
		return it->RequiredReputationRank;
	});
	reg_prop_ro(ft, "maxCount", [](ItemTemplate const * it) {
		return it->MaxCount;
	});
	reg_prop_ro(ft, "stackable", [](ItemTemplate const * it) {
		return it->Stackable;
	});
	reg_prop_ro(ft, "containerSlots", [](ItemTemplate const * it) {
		return it->ContainerSlots;
	});
	reg_prop_ro(ft, "statsCount", [](ItemTemplate const * it) {
		return it->StatsCount;
	});
	reg_prop_ro(ft, "itemStat0Type", [](ItemTemplate const * it) {
		return it->ItemStat[0].ItemStatType;
	});
	reg_prop_ro(ft, "itemStat0Value", [](ItemTemplate const * it) {
		return it->ItemStat[0].ItemStatValue;
	});
	reg_prop_ro(ft, "itemStat1Type", [](ItemTemplate const * it) {
		return it->ItemStat[1].ItemStatType;
	});
	reg_prop_ro(ft, "itemStat1Value", [](ItemTemplate const * it) {
		return it->ItemStat[1].ItemStatValue;
	});
	reg_prop_ro(ft, "itemStat2Type", [](ItemTemplate const * it) {
		return it->ItemStat[2].ItemStatType;
	});
	reg_prop_ro(ft, "itemStat2Value", [](ItemTemplate const * it) {
		return it->ItemStat[2].ItemStatValue;
	});
	reg_prop_ro(ft, "itemStat3Type", [](ItemTemplate const * it) {
		return it->ItemStat[3].ItemStatType;
	});
	reg_prop_ro(ft, "itemStat3Value", [](ItemTemplate const * it) {
		return it->ItemStat[3].ItemStatValue;
	});
	reg_prop_ro(ft, "itemStat4Type", [](ItemTemplate const * it) {
		return it->ItemStat[4].ItemStatType;
	});
	reg_prop_ro(ft, "itemStat4Value", [](ItemTemplate const * it) {
		return it->ItemStat[4].ItemStatValue;
	});
	reg_prop_ro(ft, "itemStat5Type", [](ItemTemplate const * it) {
		return it->ItemStat[5].ItemStatType;
	});
	reg_prop_ro(ft, "itemStat5Value", [](ItemTemplate const * it) {
		return it->ItemStat[5].ItemStatValue;
	});
	reg_prop_ro(ft, "itemStat6Type", [](ItemTemplate const * it) {
		return it->ItemStat[6].ItemStatType;
	});
	reg_prop_ro(ft, "itemStat6Value", [](ItemTemplate const * it) {
		return it->ItemStat[6].ItemStatValue;
	});
	reg_prop_ro(ft, "itemStat7Type", [](ItemTemplate const * it) {
		return it->ItemStat[7].ItemStatType;
	});
	reg_prop_ro(ft, "itemStat7Value", [](ItemTemplate const * it) {
		return it->ItemStat[7].ItemStatValue;
	});
	reg_prop_ro(ft, "itemStat8Type", [](ItemTemplate const * it) {
		return it->ItemStat[8].ItemStatType;
	});
	reg_prop_ro(ft, "itemStat8Value", [](ItemTemplate const * it) {
		return it->ItemStat[8].ItemStatValue;
	});
	reg_prop_ro(ft, "itemStat9Type", [](ItemTemplate const * it) {
		return it->ItemStat[9].ItemStatType;
	});
	reg_prop_ro(ft, "itemStat9Value", [](ItemTemplate const * it) {
		return it->ItemStat[9].ItemStatValue;
	});
	reg_prop_ro(ft, "scalingStatDistribution", [](ItemTemplate const * it) {
		return it->ScalingStatDistribution;
	});
	reg_prop_ro(ft, "scalingStatValue", [](ItemTemplate const * it) {
		return it->ScalingStatValue;
	});
	reg_prop_ro(ft, "damage0Min", [](ItemTemplate const * it) {
		return it->Damage[0].DamageMin;
	});
	reg_prop_ro(ft, "damage0Max", [](ItemTemplate const * it) {
		return it->Damage[0].DamageMax;
	});
	reg_prop_ro(ft, "damage0Type", [](ItemTemplate const * it) {
		return it->Damage[0].DamageType;
	});
	reg_prop_ro(ft, "damage1Min", [](ItemTemplate const * it) {
		return it->Damage[1].DamageMin;
	});
	reg_prop_ro(ft, "damage1Max", [](ItemTemplate const * it) {
		return it->Damage[1].DamageMax;
	});
	reg_prop_ro(ft, "damage1Type", [](ItemTemplate const * it) {
		return it->Damage[1].DamageType;
	});
	reg_prop_ro(ft, "armor", [](ItemTemplate const * it) {
		return it->Armor;
	});
	reg_prop_ro(ft, "holyRes", [](ItemTemplate const * it) {
		return it->HolyRes;
	});
	reg_prop_ro(ft, "fireRes", [](ItemTemplate const * it) {
		return it->FireRes;
	});
	reg_prop_ro(ft, "natureRes", [](ItemTemplate const * it) {
		return it->NatureRes;
	});
	reg_prop_ro(ft, "frostRes", [](ItemTemplate const * it) {
		return it->FrostRes;
	});
	reg_prop_ro(ft, "shadowRes", [](ItemTemplate const * it) {
		return it->ShadowRes;
	});
	reg_prop_ro(ft, "arcaneRes", [](ItemTemplate const * it) {
		return it->ArcaneRes;
	});
	reg_prop_ro(ft, "delay", [](ItemTemplate const * it) {
		return DurationWrapper::from_milliseconds(it->Delay);
	});
	reg_prop_ro(ft, "ammoType", [](ItemTemplate const * it) {
		return it->AmmoType;
	});
	reg_prop_ro(ft, "rangedModRange", [](ItemTemplate const * it) {
		return it->RangedModRange;
	});
	reg_prop_ro(ft, "spells0Id", [](ItemTemplate const * it) {
		return it->Spells[0].SpellId;
	});
	reg_prop_ro(ft, "spells0Trigger", [](ItemTemplate const * it) {
		return it->Spells[0].SpellTrigger;
	});
	reg_prop_ro(ft, "spells0Charges", [](ItemTemplate const * it) {
		return it->Spells[0].SpellCharges;
	});
	reg_prop_ro(ft, "spells0PPMRate", [](ItemTemplate const * it) {
		return it->Spells[0].SpellPPMRate;
	});
	reg_prop_ro(ft, "spells0Cooldown", [](ItemTemplate const * it) {
		return DurationWrapper::from_milliseconds(it->Spells[0].SpellCooldown);
	});
	reg_prop_ro(ft, "spells0Category", [](ItemTemplate const * it) {
		return it->Spells[0].SpellCategory;
	});
	reg_prop_ro(ft, "spells0CategoryCooldown", [](ItemTemplate const * it) {
		return DurationWrapper::from_milliseconds(it->Spells[0].SpellCategoryCooldown);
	});
	reg_prop_ro(ft, "spells1Id", [](ItemTemplate const * it) {
		return it->Spells[1].SpellId;
	});
	reg_prop_ro(ft, "spells1Trigger", [](ItemTemplate const * it) {
		return it->Spells[1].SpellTrigger;
	});
	reg_prop_ro(ft, "spells1Charges", [](ItemTemplate const * it) {
		return it->Spells[1].SpellCharges;
	});
	reg_prop_ro(ft, "spells1PPMRate", [](ItemTemplate const * it) {
		return it->Spells[1].SpellPPMRate;
	});
	reg_prop_ro(ft, "spells1Cooldown", [](ItemTemplate const * it) {
		return DurationWrapper::from_milliseconds(it->Spells[1].SpellCooldown);
	});
	reg_prop_ro(ft, "spells1Category", [](ItemTemplate const * it) {
		return it->Spells[1].SpellCategory;
	});
	reg_prop_ro(ft, "spells1CategoryCooldown", [](ItemTemplate const * it) {
		return DurationWrapper::from_milliseconds(it->Spells[1].SpellCategoryCooldown);
	});
	reg_prop_ro(ft, "spells2Id", [](ItemTemplate const * it) {
		return it->Spells[2].SpellId;
	});
	reg_prop_ro(ft, "spells2Trigger", [](ItemTemplate const * it) {
		return it->Spells[2].SpellTrigger;
	});
	reg_prop_ro(ft, "spells2Charges", [](ItemTemplate const * it) {
		return it->Spells[2].SpellCharges;
	});
	reg_prop_ro(ft, "spells2PPMRate", [](ItemTemplate const * it) {
		return it->Spells[2].SpellPPMRate;
	});
	reg_prop_ro(ft, "spells2Cooldown", [](ItemTemplate const * it) {
		return DurationWrapper::from_milliseconds(it->Spells[2].SpellCooldown);
	});
	reg_prop_ro(ft, "spells2Category", [](ItemTemplate const * it) {
		return it->Spells[2].SpellCategory;
	});
	reg_prop_ro(ft, "spells2CategoryCooldown", [](ItemTemplate const * it) {
		return DurationWrapper::from_milliseconds(it->Spells[2].SpellCategoryCooldown);
	});
	reg_prop_ro(ft, "spells3Id", [](ItemTemplate const * it) {
		return it->Spells[3].SpellId;
	});
	reg_prop_ro(ft, "spells3Trigger", [](ItemTemplate const * it) {
		return it->Spells[3].SpellTrigger;
	});
	reg_prop_ro(ft, "spells3Charges", [](ItemTemplate const * it) {
		return it->Spells[3].SpellCharges;
	});
	reg_prop_ro(ft, "spells3PPMRate", [](ItemTemplate const * it) {
		return it->Spells[3].SpellPPMRate;
	});
	reg_prop_ro(ft, "spells3Cooldown", [](ItemTemplate const * it) {
		return DurationWrapper::from_milliseconds(it->Spells[3].SpellCooldown);
	});
	reg_prop_ro(ft, "spells3Category", [](ItemTemplate const * it) {
		return it->Spells[3].SpellCategory;
	});
	reg_prop_ro(ft, "spells3CategoryCooldown", [](ItemTemplate const * it) {
		return DurationWrapper::from_milliseconds(it->Spells[3].SpellCategoryCooldown);
	});
	reg_prop_ro(ft, "spells4Id", [](ItemTemplate const * it) {
		return it->Spells[4].SpellId;
	});
	reg_prop_ro(ft, "spells4Trigger", [](ItemTemplate const * it) {
		return it->Spells[4].SpellTrigger;
	});
	reg_prop_ro(ft, "spells4Charges", [](ItemTemplate const * it) {
		return it->Spells[4].SpellCharges;
	});
	reg_prop_ro(ft, "spells4PPMRate", [](ItemTemplate const * it) {
		return it->Spells[4].SpellPPMRate;
	});
	reg_prop_ro(ft, "spells4Cooldown", [](ItemTemplate const * it) {
		return DurationWrapper::from_milliseconds(it->Spells[4].SpellCooldown);
	});
	reg_prop_ro(ft, "spells4Category", [](ItemTemplate const * it) {
		return it->Spells[4].SpellCategory;
	});
	reg_prop_ro(ft, "spells4CategoryCooldown", [](ItemTemplate const * it) {
		return DurationWrapper::from_milliseconds(it->Spells[4].SpellCategoryCooldown);
	});
	reg_prop_ro(ft, "bonding", [](ItemTemplate const * it) {
		return it->Bonding;
	});
	reg_prop_ro(ft, "description", [](ItemTemplate const * it) {
		return it->Description;
	});
	reg_prop_ro(ft, "pageText", [](ItemTemplate const * it) {
		return it->PageText;
	});
	reg_prop_ro(ft, "languageId", [](ItemTemplate const * it) {
		return it->LanguageID;
	});
	reg_prop_ro(ft, "pageMaterial", [](ItemTemplate const * it) {
		return it->PageMaterial;
	});
	reg_prop_ro(ft, "startQuest", [](ItemTemplate const * it) {
		return it->StartQuest;
	});
	reg_prop_ro(ft, "lockId", [](ItemTemplate const * it) {
		return it->LockID;
	});
	reg_prop_ro(ft, "material", [](ItemTemplate const * it) {
		return it->Material;
	});
	reg_prop_ro(ft, "sheath", [](ItemTemplate const * it) {
		return it->Sheath;
	});
	reg_prop_ro(ft, "randomProperty", [](ItemTemplate const * it) {
		return it->RandomProperty;
	});
	reg_prop_ro(ft, "randomSuffix", [](ItemTemplate const * it) {
		return it->RandomSuffix;
	});
	reg_prop_ro(ft, "block", [](ItemTemplate const * it) {
		return it->Block;
	});
	reg_prop_ro(ft, "itemSet", [](ItemTemplate const * it) {
		return it->ItemSet;
	});
	reg_prop_ro(ft, "maxDurability", [](ItemTemplate const * it) {
		return it->MaxDurability;
	});
	reg_prop_ro(ft, "area", [](ItemTemplate const * it) {
		return it->Area;
	});
	reg_prop_ro(ft, "map", [](ItemTemplate const * it) {
		return it->Map;
	});
	reg_prop_ro(ft, "bagFamily", [](ItemTemplate const * it) {
		return it->BagFamily;
	});
	reg_prop_ro(ft, "totemCategory", [](ItemTemplate const * it) {
		return it->TotemCategory;
	});
	reg_prop_ro(ft, "socket0Color", [](ItemTemplate const * it) {
		return it->Socket[0].Color;
	});
	reg_prop_ro(ft, "socket0Content", [](ItemTemplate const * it) {
		return it->Socket[0].Content;
	});
	reg_prop_ro(ft, "socket1Color", [](ItemTemplate const * it) {
		return it->Socket[1].Color;
	});
	reg_prop_ro(ft, "socket1Content", [](ItemTemplate const * it) {
		return it->Socket[1].Content;
	});
	reg_prop_ro(ft, "socket2Color", [](ItemTemplate const * it) {
		return it->Socket[2].Color;
	});
	reg_prop_ro(ft, "socket2Content", [](ItemTemplate const * it) {
		return it->Socket[2].Content;
	});
	reg_prop_ro(ft, "socketBonus", [](ItemTemplate const * it) {
		return it->socketBonus;
	});
	reg_prop_ro(ft, "gemProperties", [](ItemTemplate const * it) {
		return it->GemProperties;
	});
	reg_prop_ro(ft, "requiredDisenchantSkill", [](ItemTemplate const * it) {
		return it->RequiredDisenchantSkill;
	});
	reg_prop_ro(ft, "armorDamageModifier", [](ItemTemplate const * it) {
		return it->ArmorDamageModifier;
	});
	reg_prop_ro(ft, "duration", [](ItemTemplate const * it) {
		return DurationWrapper::from_chrono(Seconds{it->Duration});
	});
	reg_prop_ro(ft, "itemLimitCategory", [](ItemTemplate const * it) {
		return it->ItemLimitCategory;
	});
	reg_prop_ro(ft, "holidayId", [](ItemTemplate const * it) {
		return it->HolidayId;
	});
	reg_prop_ro(ft, "scriptId", [](ItemTemplate const * it) {
		return it->ScriptId;
	});
	reg_prop_ro(ft, "disenchantID", [](ItemTemplate const * it) {
		return it->DisenchantID;
	});
	reg_prop_ro(ft, "foodType", [](ItemTemplate const * it) {
		return it->FoodType;
	});
	reg_prop_ro(ft, "minMoneyLoot", [](ItemTemplate const * it) {
		return it->MinMoneyLoot;
	});
	reg_prop_ro(ft, "maxMoneyLoot", [](ItemTemplate const * it) {
		return it->MaxMoneyLoot;
	});
	reg_prop_ro(ft, "flagsCu", [](ItemTemplate const * it) {
		return it->FlagsCu;
	});
	reg_prop_ro(ft, "hasSignature", [](ItemTemplate const * it) {
		return it->HasSignature();
	});
	reg_prop_ro(ft, "canChangeEquipStateInCombat", [](ItemTemplate const * it) {
		return it->CanChangeEquipStateInCombat();
	});
	reg_prop_ro(ft, "isCurrencyToken", [](ItemTemplate const * it) {
		return it->IsCurrencyToken();
	});
	reg_prop_ro(ft, "maxStackSize", [](ItemTemplate const * it) {
		return it->GetMaxStackSize();
	});
	reg_prop_ro(ft, "dps", [](ItemTemplate const * it) {
		return it->getDPS();
	});
	reg_prop_ro(ft, "skill", [](ItemTemplate const * it) {
		return it->GetSkill();
	});
	reg_prop_ro(ft, "isPotion", [](ItemTemplate const * it) {
		return it->IsPotion();
	});
	reg_prop_ro(ft, "isWeaponVellum", [](ItemTemplate const * it) {
		return it->IsWeaponVellum();
	});
	reg_prop_ro(ft, "isArmorVellum", [](ItemTemplate const * it) {
		return it->IsArmorVellum();
	});
	reg_prop_ro(ft, "isConjuredConsumable", [](ItemTemplate const * it) {
		return it->IsConjuredConsumable();
	});
	reg_prop_ro(ft, "hasSpellPowerStat", [](ItemTemplate const * it) {
		return it->HasSpellPowerStat();
	});

	reg_method(ft, "getFeralBonus", [](ItemTemplate const * it, std::optional<int32_t> const extra_dps) {
		return it->getFeralBonus(extra_dps.value_or(0));
	});
	reg_method(ft, "getItemLevelIncludingQuality", [](ItemTemplate const * it, uint32_t const p_level) {
		return it->GetItemLevelIncludingQuality(p_level);
	});
	reg_method(ft, "hasStat", [](ItemTemplate const * it, ItemModType const stat) {
		return it->HasStat(stat);
	});
	reg_method(ft, "hasFlag", [](ItemTemplate const * it, ItemFlags const flag) {
		return it->HasFlag(flag);
	});
	reg_method(ft, "hasFlag2", [](ItemTemplate const * it, ItemFlags2 const flag) {
		return it->HasFlag2(flag);
	});
	reg_method(ft, "hasFlagCu", [](ItemTemplate const * it, ItemFlagsCustom const flag) {
		return it->HasFlagCu(flag);
	});

	return ft;
}
