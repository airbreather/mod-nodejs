declare global {
	namespace Acore {
		class AuraEffect {
			readonly caster: Unit | undefined;
			readonly casterGuid: ObjectGuidNative;
			readonly base: Aura;
			readonly targetList: Unit[];
			readonly applicationList: AuraApplication[];
			readonly spellModifier: SpellModifier;
			readonly spellInfo: SpellInfo;
			readonly id: number;
			readonly effIndex: number;
			readonly baseAmount: number;
			readonly dieSides: number;
			readonly amplitude: number;
			readonly miscValue: number;
			readonly miscValueB: number;
			readonly auraType: AuraType;
			readonly forcedAmount: number;
			readonly tickNumber: number;
			readonly totalTicks: number;
			readonly hasSpellClassMask: boolean;
			readonly casterLevel: number;
			readonly canApplyResilience: boolean;

			amount: number;
			periodicTimer: number;
			canBeRecalculated: boolean;
			isPeriodic: boolean;
			critChance: number;
			pctMods: number;
			oldAmount: number;
			isEnabled: boolean;

			calculatePeriodic(caster: Unit, create?: boolean, load?: boolean): void;
			calculatePeriodicData(): void;
			calculateSpellMod(): void;
			changeAmount(newAmount: number, mark?: boolean, onStackOrReapply?: boolean): void;
			recalculateAmount(caster?: Unit): void;
			handleEffect(target: Unit, mode: number, apply: boolean): void;
			handleEffect(auraApplication: AuraApplication, mode: number, apply: boolean): void;
		}
	}
}
export {};
