declare global {
	namespace Acore {
		class SpellEffectInfo {
			readonly effectIndex: SpellEffIndex;
			readonly effect: SpellEffects;
			readonly applyAuraName: AuraType;
			readonly amplitude: number;
			readonly dieSides: number;
			readonly realPointsPerLevel: number;
			readonly basePoints: number;
			readonly pointsPerComboPoint: number;
			readonly valueMultiplier: number;
			readonly damageMultiplier: number;
			readonly bonusMultiplier: number;
			readonly miscValue: number;
			readonly miscValueB: number;
			readonly mechanic: Mechanics;
			readonly targetA: SpellImplicitTargetInfo;
			readonly targetB: SpellImplicitTargetInfo;
			readonly radiusEntry: SpellRadiusEntry;
			readonly chainTarget: number;
			readonly itemType: number; // item id
			readonly triggerSpell: number; // spell id
			readonly spellClassMask: bigint; // flag96
			readonly implicitTargetConditions: Condition[] | undefined;
			readonly isEffect: boolean;
			readonly isAura: boolean;
			readonly isTargetingArea: boolean;
			readonly isAreaAuraEffect: boolean;
			readonly isFarUnitTargetEffect: boolean;
			readonly isFarDestTargetEffect: boolean;
			readonly isUnitOwnedAuraEffect: boolean;
			readonly hasRadius: boolean;
			readonly providedTargetMask: SpellCastTargetFlags;
			readonly implicitTargetType: SpellEffectImplicitTargetTypes;
			readonly usedTargetObjectType: SpellTargetObjectTypes;
			readonly immunityInfo: ImmunityInfo;

			hasEffectOf(effect: SpellEffects): boolean;
			appliesAura(aura: AuraType): boolean;
			calcValue(caster?: Unit, basePoints?: number, target?: Unit): number;
			calcBaseValue(value: number): number;
			calcValueMultiplier(caster: Unit, spell?: Spell): number;
			calcDamageMultiplier(caster: Unit, spell?: Spell): number;
			calcRadius(caster: Unit, spell?: Spell): number;
			getMissingTargetMask(srcSet?: boolean, destSet?: boolean, mask?: SpellCastTargetFlags): SpellCastTargetFlags;
		}
	}
}
export {};
