declare global {
	namespace Acore {
		class Spell {
			readonly spellInfo: number;
			readonly castTime: Temporal.Duration;
			readonly powerCost: number;
			readonly caster: number;
			readonly targetDest: number;
			readonly target: number;
			isAutoRepeat: boolean;

			cast(skipCheck?: boolean): void;
			cancel(): void;
			finish(): void;
		}
	}
}
export {};
