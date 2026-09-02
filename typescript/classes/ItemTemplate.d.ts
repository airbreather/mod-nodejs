declare global {
	namespace Acore {
		class ItemTemplate {
			private constructor();

			static byId(id: number): ItemTemplate | undefined;

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
			readonly itemStat0Type: ItemModType;
			readonly itemStat0Value: number;
			readonly itemStat1Type: ItemModType;
			readonly itemStat1Value: number;
			readonly itemStat2Type: ItemModType;
			readonly itemStat2Value: number;
			readonly itemStat3Type: ItemModType;
			readonly itemStat3Value: number;
			readonly itemStat4Type: ItemModType;
			readonly itemStat4Value: number;
			readonly itemStat5Type: ItemModType;
			readonly itemStat5Value: number;
			readonly itemStat6Type: ItemModType;
			readonly itemStat6Value: number;
			readonly itemStat7Type: ItemModType;
			readonly itemStat7Value: number;
			readonly itemStat8Type: ItemModType;
			readonly itemStat8Value: number;
			readonly itemStat9Type: ItemModType;
			readonly itemStat9Value: number;
			readonly scalingStatDistribution: number; // id from ScalingStatDistribution.dbc
			readonly scalingStatValue: number; // mask for selecting column in ScalingStatValues.dbc
			readonly damage0Min: number;
			readonly damage0Max: number;
			readonly damage0Type: SpellSchools;
			readonly damage1Min: number;
			readonly damage1Max: number;
			readonly damage1Type: SpellSchools;
			readonly armor: number;
			readonly holyRes: number;
			readonly fireRes: number;
			readonly natureRes: number;
			readonly frostRes: number;
			readonly shadowRes: number;
			readonly arcaneRes: number;
			readonly delay: Temporal.Duration;
			readonly ammoType: ItemSubclassProjectile;
			readonly rangedModRange: number;
			readonly spells0Id: number;
			readonly spells0Trigger: ItemSpelltriggerType;
			readonly spells0Charges: number;
			readonly spells0PPMRate: number;
			readonly spells0Cooldown: Temporal.Duration;
			readonly spells0Category: number;
			readonly spells0CategoryCooldown: Temporal.Duration;
			readonly spells1Id: number;
			readonly spells1Trigger: ItemSpelltriggerType;
			readonly spells1Charges: number;
			readonly spells1PPMRate: number;
			readonly spells1Cooldown: Temporal.Duration;
			readonly spells1Category: number;
			readonly spells1CategoryCooldown: Temporal.Duration;
			readonly spells2Id: number;
			readonly spells2Trigger: ItemSpelltriggerType;
			readonly spells2Charges: number;
			readonly spells2PPMRate: number;
			readonly spells2Cooldown: Temporal.Duration;
			readonly spells2Category: number;
			readonly spells2CategoryCooldown: Temporal.Duration;
			readonly spells3Id: number;
			readonly spells3Trigger: ItemSpelltriggerType;
			readonly spells3Charges: number;
			readonly spells3PPMRate: number;
			readonly spells3Cooldown: Temporal.Duration;
			readonly spells3Category: number;
			readonly spells3CategoryCooldown: Temporal.Duration;
			readonly spells4Id: number;
			readonly spells4Trigger: ItemSpelltriggerType;
			readonly spells4Charges: number;
			readonly spells4PPMRate: number;
			readonly spells4Cooldown: Temporal.Duration;
			readonly spells4Category: number;
			readonly spells4CategoryCooldown: Temporal.Duration;
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
			readonly socket0Color: SocketColor | 0;
			readonly socket0Content: number;
			readonly socket1Color: SocketColor | 0;
			readonly socket1Content: number;
			readonly socket2Color: SocketColor | 0;
			readonly socket2Content: number;
			readonly socketBonus: number; // id from SpellItemEnchantment.dbc
			readonly gemProperties: number; // id from GemProperties.dbc
			readonly requiredDisenchantSkill: number;
			readonly armorDamageModifier: number;
			readonly duration: Temporal.Duration;
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
