declare global {
	namespace Acore {
		class ItemTemplate {
			readonly itemId: number;
			readonly clazz: ItemClass;
			readonly subClass: ItemSubclass;
			readonly soundOverrideSubclass: number; // < 0: id from ItemSubClass.dbc, used to override weapon sound from actual SubClass
			readonly name1: string;
			readonly displayInfoId: number; // id from ItemDisplayInfo.dbc
			readonly quality: ItemQualities;
			readonly flags: ItemFlags;
			readonly flags2: ItemFlags2;
			readonly buyCount: number;
			readonly buyPrice: number;
			readonly sellPrice: number;
			readonly inventoryType: InventoryType;
			readonly allowableClass: number; // bitmask of (1 << Classes) values
			readonly allowableRace: number; // bitmask of (1 << Races) values
			readonly itemLevel: number;
			readonly requiredLevel: number;
			readonly requiredSkill: number; // id from SkillLine.dbc
			readonly requiredSkillRank: number;
			readonly requiredSpell: number; // id from Spell.dbc
			readonly requiredHonorRank: number;
			readonly requiredCityRank: number;
			readonly requiredReputationFaction: number; // id from Faction.dbc
			readonly requiredReputationRank: ReputationRank;
			readonly maxCount: number; // <= 0: no limit
			readonly stackable: number; // 0: not allowed, -1: put in player coin info tab and don't limit stacking (so 1 slot)
			readonly containerSlots: number;
			readonly statsCount: number;
			readonly itemStat: ItemStat[];
			readonly scalingStatDistribution: number; // id from ScalingStatDistribution.dbc
			readonly scalingStatValue: number; // mask for selecting column in ScalingStatValues.dbc
			readonly damage: ItemDamage[];
			readonly armor: number;
			readonly holyRes: number;
			readonly fireRes: number;
			readonly natureRes: number;
			readonly frostRes: number;
			readonly shadowRes: number;
			readonly arcaneRes: number;
			readonly delay: number;
			readonly ammoType: ItemSubclassProjectile;
			readonly rangedModRange: number;
			readonly spells: ItemSpell[];
			readonly bonding: ItemBondingType;
			readonly description: string;
			readonly pageText: number;
			readonly languageId: number;
			readonly pageMaterial: number;
			readonly startQuest: number; // id from QuestCache.wdb
			readonly lockId: number;
			readonly material: number; // id from Material.dbc
			readonly sheath: number; // MIGHT be the enum SheathTypes? unsure
			readonly randomProperty: number; // id from ItemRandomProperties.dbc
			readonly randomSuffix: number; // id from ItemRandomSuffix.dbc
			readonly block: number;
			readonly itemSet: number; // id from ItemSet.dbc
			readonly maxDurability: number;
			readonly area: number; // id from AreaTable.dbc
			readonly map: number; // id from Map.dbc
			readonly bagFamily: BAG_FAMILY_MASK; // bit mask (1 << id from ItemBagFamily.dbc)
			readonly totemCategory: number; // id from TotemCategory.dbc
			readonly socket: ItemSocket[];
			readonly socketBonus: number; // id from SpellItemEnchantment.dbc
			readonly gemProperties: number; // id from GemProperties.dbc
			readonly requiredDisenchantSkill: number;
			readonly armorDamageModifier: number;
			readonly duration: number;
			readonly itemLimitCategory: number; // id from ItemLimitCategory.dbc
			readonly holidayId: HolidayIds;
			readonly scriptId: number;
			readonly disenchantID: number;
			readonly foodType: PetDiet;
			readonly minMoneyLoot: number;
			readonly maxMoneyLoot: number;
			readonly flagsCu: ItemFlagsCustom;
			readonly hasSignature: boolean;
			readonly canChangeEquipStateInCombat: boolean;
			readonly isCurrencyToken: boolean;
			readonly maxStackSize: number;
			readonly dps: number;
			readonly skill: SkillType; // TODO: separate enum for the subset that this can ACTUALLY return
			readonly isPotion: boolean;
			readonly isWeaponVellum: boolean;
			readonly isArmorVellum: boolean;
			readonly isConjuredConsumable: boolean;
			readonly hasSpellPowerStat: boolean;

			getFeralBonus(extraDps?: number): number;
			getItemLevelIncludingQuality(playerLevel: number): number;
			hasStat(stat: ItemModType): boolean;
			hasFlag(flag: ItemFlags): boolean;
			hasFlag2(flag: ItemFlags2): boolean;
			hasFlagCu(flag: ItemFlagsCustom): boolean;
		}

		// technically there's only ItemTemplate at runtime, but the subclasses have overlapping values
		// with different meanings depending on the class value - which is something that TypeScript has
		// a very specific, very powerful tool to help use it correctly.
		type ItemTemplateNarrowable = ItemTemplate & (
			| { clazz: ItemClass.ITEM_CLASS_ARMOR; subclass: ItemSubclassArmor }
			| { clazz: ItemClass.ITEM_CLASS_CONSUMABLE; subclass: ItemSubclassConsumable }
			| { clazz: ItemClass.ITEM_CLASS_CONTAINER; subclass: ItemSubclassContainer }
			| { clazz: ItemClass.ITEM_CLASS_GEM; subclass: ItemSubclassGem }
			| { clazz: ItemClass.ITEM_CLASS_GENERIC; subclass: ItemSubclassGeneric }
			| { clazz: ItemClass.ITEM_CLASS_GLYPH; subclass: ItemSubclassGlyph }
			| { clazz: ItemClass.ITEM_CLASS_MISC; subclass: ItemSubclassJunk }
			| { clazz: ItemClass.ITEM_CLASS_KEY; subclass: ItemSubclassKey }
			| { clazz: ItemClass.ITEM_CLASS_MONEY; subclass: ItemSubclassMoney }
			| { clazz: ItemClass.ITEM_CLASS_PERMANENT; subclass: ItemSubclassPermanent }
			| { clazz: ItemClass.ITEM_CLASS_PROJECTILE; subclass: ItemSubclassProjectile }
			| { clazz: ItemClass.ITEM_CLASS_QUEST; subclass: ItemSubclassQuest }
			| { clazz: ItemClass.ITEM_CLASS_QUIVER; subclass: ItemSubclassQuiver }
			| { clazz: ItemClass.ITEM_CLASS_REAGENT; subclass: ItemSubclassReagent }
			| { clazz: ItemClass.ITEM_CLASS_RECIPE; subclass: ItemSubclassRecipe }
			| { clazz: ItemClass.ITEM_CLASS_TRADE_GOODS; subclass: ItemSubclassTradeGoods }
			| { clazz: ItemClass.ITEM_CLASS_WEAPON; subclass: ItemSubclassWeapon }
		);
	}
}
export {};
