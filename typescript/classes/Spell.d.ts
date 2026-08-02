declare global {
	namespace Acore {
		class Spell {
			readonly spellInfo: SpellInfo;
			readonly castTime: Temporal.Duration;
			readonly powerCost: number;
			readonly caster: Unit;
			readonly targetDest: Position;
			readonly target: WorldObject | Item | undefined;
			isAutoRepeat: boolean;

			cast(skipCheck?: boolean): void;
			cancel(): void;
			finish(): void;
		}
	}
}
export {};
