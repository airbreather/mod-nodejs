// TODO: this should be 2x 32-bit fields because JavaScript is goofy sometimes.
type MechanicsMask = bigint;

// TODO: this should be 3x 32-bit fields like many other things are.
// bonus points for making a realistic attempt at making enums for each
type SpellFamilyFlagsMask = bigint;

declare global {
	namespace Acore {
		class SpellInfo {
			static bySpellId(id: number): SpellInfo;

			readonly spellId: number;
			readonly categoryEntry: SpellCategoryEntry | undefined;
			readonly dispel: DispelType;
			readonly mechanic: Mechanics;
			readonly attributes: SpellAttr0;
			readonly attributesEx: SpellAttr1;
			readonly attributesEx2: SpellAttr2;
			readonly attributesEx3: SpellAttr3;
			readonly attributesEx4: SpellAttr4;
			readonly attributesEx5: SpellAttr5;
			readonly attributesEx6: SpellAttr6;
			readonly attributesEx7: SpellAttr7;
			readonly attributesCu: SpellCustomAttributes;
			readonly stances: number;
			readonly stancesNot: number;
			readonly targets: SpellCastTargetFlags;
			readonly targetCreatureType: CreatureTypeMask;
			readonly requiresSpellFocus: number; // SpellFocusObject.dbc id
			readonly facingCasterFlags: SpellFacingFlags;
			readonly casterAuraState: AuraStateType;
			readonly targetAuraState: AuraStateType;
			readonly casterAuraStateNot: AuraStateType;
			readonly targetAuraStateNot: AuraStateType;
			readonly casterAuraSpell: number;
			readonly targetAuraSpell: number;
			readonly excludeCasterAuraSpell: number;
			readonly excludeTargetAuraSpell: number;
			readonly castTimeEntry: SpellCastTimesEntry | undefined;
			// favor recoveryTime, which yields categoryRecoveryTime if that's longer
			readonly recoveryTimeRaw: number;
			readonly categoryRecoveryTime: number;
			readonly startRecoveryCategory: number;
			readonly startRecoveryTime: number;
			readonly interruptFlags: SpellInterruptFlags;
			readonly auraInterruptFlags: SpellAuraInterruptFlags;
			readonly channelInterruptFlags: SpellAuraInterruptFlags;
			readonly procFlags: ProcFlags;
			readonly procChance: number;
			readonly procCharges: number;
			readonly maxLevel: number;
			readonly baseLevel: number;
			readonly spellLevel: number;
			readonly durationEntry: SpellDurationEntry | undefined;
			readonly powerType: Powers;
			readonly manaCost: number;
			readonly manaCostPerlevel: number;
			readonly manaPerSecond: number;
			readonly manaPerSecondPerLevel: number;
			readonly manaCostPercentage: number;
			readonly runeCostID: number;
			readonly rangeEntry: SpellRangeEntry | undefined;
			readonly speed: number;
			readonly stackAmount: number;
			readonly totem: number[];
			readonly reagent: number[];
			readonly reagentCount: number[];
			readonly equippedItemClass: ItemClass;
			readonly equippedItemSubClassMask: ItemSubclassMask;
			readonly equippedItemInventoryTypeMask: InventoryTypeMask;
			readonly totemCategory: number[];
			readonly spellVisual: number[];
			readonly spellIconID: number;
			readonly activeIconID: number;
			readonly spellPriority: number;
			readonly spellName: string[];
			readonly rankName: string[];
			readonly maxTargetLevel: number;
			readonly maxAffectedTargets: number;
			readonly spellFamilyName: SpellFamilyNames;
			readonly spellFamilyFlags: SpellFamilyFlagsMask;
			readonly dmgClass: SpellDmgClass;
			readonly preventionType: SpellPreventionType;
			readonly areaGroupId: number;
			readonly schoolMask: SpellSchoolMask;
			readonly effects: SpellEffectInfo[];
			readonly explicitTargetMask: SpellCastTargetFlags;
			readonly chainEntry: SpellChainNode | undefined;
			readonly category: number; // 0 if categoryEntry is undefined
			readonly isExplicitDiscovery: boolean;
			readonly isLootCrafting: boolean;
			readonly isQuestTame: boolean;
			readonly isProfessionOrRiding: boolean;
			readonly isProfession: boolean;
			readonly isPrimaryProfession: boolean;
			readonly isPrimaryProfessionFirstRank: boolean;
			readonly isAbilityLearnedWithProfession: boolean;
			readonly isAffectingArea: boolean;
			readonly isTargetingArea: boolean;
			readonly needsExplicitUnitTarget: boolean;
			readonly isChannelCategorySpell: boolean;
			readonly isSelfCast: boolean;
			readonly isPassive: boolean;
			readonly isAutocastable: boolean;
			readonly isCritCapable: boolean;
			readonly requireCooldownInfo: boolean;
			readonly isStackableWithRanks: boolean;
			readonly isPassiveStackableWithRanks: boolean;
			readonly isMultiSlotAura: boolean;
			readonly isCooldownStartedOnEvent: boolean;
			readonly isDeathPersistent: boolean;
			readonly isRequiringDeadTarget: boolean;
			readonly isAllowingDeadTarget: boolean;
			readonly isUsableInCombat: boolean;
			readonly isPositive: boolean;
			readonly isChanneled: boolean;
			readonly isActionAllowedChannel: boolean;
			readonly needsComboPoints: boolean;
			readonly isBreakingStealth: boolean;
			readonly isRangedWeaponSpell: boolean;
			readonly isAutoRepeatRangedSpell: boolean;
			readonly hasInitialAggro: boolean;
			readonly isAffectedBySpellMods: boolean;
			readonly isSingleTarget: boolean;
			readonly allEffectsMechanicMask: MechanicsMask;
			readonly hasAnyEffectMechanic: boolean;
			readonly dispelMask: DispelTypeMask;
			readonly auraState: AuraStateType;
			readonly spellSpecific: SpellSpecificType;
			readonly duration: number;
			readonly maxDuration: number;
			readonly maxTicks: number;
			readonly recoveryTime: number;
			readonly isRanked: boolean;
			readonly rank: number;
			readonly firsRankSpell: SpellInfo | undefined;
			readonly lastRankSpell: SpellInfo | undefined;
			readonly nextRankSpell: SpellInfo | undefined;
			readonly prevRankSpell: SpellInfo | undefined;
			readonly hasAreaAuraEffect: boolean;

			hasEffect(effect: SpellEffects): boolean;
			hasAura(aura: AuraType): boolean;
			isAbilityOfSkillType(skill: SkillType): boolean;
			needsToBeTriggeredByCaster(trigger: SpellInfo, effectIndex?: SpellEffIndex): boolean;
			isPositiveEffect(effectIndex: SpellEffIndex): boolean;
			isAffected(familyName: SpellFamilyNames, familyFlags: SpellFamilyFlagsMask): boolean;
			isAffectedBySpellMod(mod: SpellModifier): boolean;
			canPierceImmuneAura(auraSpell: SpellInfo): boolean;
			canDispelAura(auraSpell: SpellInfo): boolean;
			applyAllSpellImmunitiesTo(target: Unit, effect: SpellEffectInfo, apply: boolean): void;
			canSpellProvideImmunityAgainstAura(aura: SpellInfo): boolean;
			canSpellCastOverrideAuraEffect(effect: AuraEffect): boolean;
			isAuraExclusiveBySpecificWith(other: SpellInfo): boolean;
			isAuraExclusiveBySpecificPerCasterWith(other: SpellInfo): boolean;
			checkShapeshift(other: ShapeshiftForm): SpellCastResult;
			checkLocation(mapId: number, zoneId: number, areaId: number, player?: Player, strict?: boolean): SpellCastResult;
			checkTarget(caster: Unit, target: WorldObject, implicit?: boolean): SpellCastResult;
			checkExplicitTarget(caster: Unit, target: WorldObject, itemTarget?: Item): SpellCastResult;
			checkTargetCreatureType(target: Unit): boolean;
			isAuraEffectEqual(other: SpellInfo): boolean;
			validateAttribute6SpellDamageMods(caster: Unit, eff: AuraEffect, isDot: boolean): boolean;
			getEffectMechanicMask(effectIndex: SpellEffIndex): MechanicsMask;
			getSpellMechanicMaskByEffectMask(effectMask: SpellEffIndexMask): MechanicsMask;
			getEffectMechanic(effectIndex: SpellEffIndex): Mechanics;
			getImmunityInfo(effectIndex: SpellEffIndex): ImmunityInfo;
			getMinRange(positive?: boolean): number;
			getMaxRange(positive?: boolean, caster?: Unit, spell?: Spell): number;
			calcCastTime(caster?: Unit, spell?: Spell): number;
			calcPowerCost(caster: Unit, schoolMask: SpellSchoolMask, spell?: Spell): number;
			getAuraRankForLevel(level: number): number;
			isRankOf(other: SpellInfo): boolean;
			isDifferentRankOf(other: SpellInfo): boolean;
			isHighRankOf(other: SpellInfo): boolean;
			getEffect(i: SpellEffIndex): SpellEffectInfo | undefined;
		}

		type SpellInfoNarrowable = SpellInfo & (
			| { equippedItemClass: ItemClass.ITEM_CLASS_ARMOR; equippedItemSubClassMask: ItemSubclassMaskArmor }
			| { equippedItemClass: ItemClass.ITEM_CLASS_CONSUMABLE; equippedItemSubClassMask: ItemSubclassMaskConsumable }
			| { equippedItemClass: ItemClass.ITEM_CLASS_CONTAINER; equippedItemSubClassMask: ItemSubclassMaskContainer }
			| { equippedItemClass: ItemClass.ITEM_CLASS_GEM; equippedItemSubClassMask: ItemSubclassMaskGem }
			| { equippedItemClass: ItemClass.ITEM_CLASS_GENERIC; equippedItemSubClassMask: ItemSubclassMaskGeneric }
			| { equippedItemClass: ItemClass.ITEM_CLASS_GLYPH; equippedItemSubClassMask: ItemSubclassMaskGlyph }
			| { equippedItemClass: ItemClass.ITEM_CLASS_MISC; equippedItemSubClassMask: ItemSubclassMaskJunk }
			| { equippedItemClass: ItemClass.ITEM_CLASS_KEY; equippedItemSubClassMask: ItemSubclassMaskKey }
			| { equippedItemClass: ItemClass.ITEM_CLASS_MONEY; equippedItemSubClassMask: ItemSubclassMaskMoney }
			| { equippedItemClass: ItemClass.ITEM_CLASS_PERMANENT; equippedItemSubClassMask: ItemSubclassMaskPermanent }
			| { equippedItemClass: ItemClass.ITEM_CLASS_PROJECTILE; equippedItemSubClassMask: ItemSubclassMaskProjectile }
			| { equippedItemClass: ItemClass.ITEM_CLASS_QUEST; equippedItemSubClassMask: ItemSubclassMaskQuest }
			| { equippedItemClass: ItemClass.ITEM_CLASS_QUIVER; equippedItemSubClassMask: ItemSubclassMaskQuiver }
			| { equippedItemClass: ItemClass.ITEM_CLASS_REAGENT; equippedItemSubClassMask: ItemSubclassMaskReagent }
			| { equippedItemClass: ItemClass.ITEM_CLASS_RECIPE; equippedItemSubClassMask: ItemSubclassMaskRecipe }
			| { equippedItemClass: ItemClass.ITEM_CLASS_TRADE_GOODS; equippedItemSubClassMask: ItemSubclassMaskTradeGoods }
			| { equippedItemClass: ItemClass.ITEM_CLASS_WEAPON; equippedItemSubClassMask: ItemSubclassMaskWeapon }
		)
	}
}
export {};
