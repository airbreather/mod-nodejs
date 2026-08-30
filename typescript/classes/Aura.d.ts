declare global {
	namespace Acore {
		class Aura {
			readonly caster: Unit;
			readonly casterGuid: bigint;
			readonly castItemGuid: bigint | undefined;
			readonly castItemEntry: number;
			readonly owner: WorldObject;
			readonly casterLevel: number;
			readonly spellId: number;
			readonly spellInfo: SpellInfo;
			readonly type: AuraType;
			readonly charges: number;
			readonly isExpired: boolean;
			readonly isPermanent: boolean;
			duration: Temporal.Duration;
			maxDuration: Temporal.Duration;
			stackAmount: number;

			setDurationWithMods(duration: Temporal.Duration): void;
			remove(): void;
		}
	}
}
export {};
