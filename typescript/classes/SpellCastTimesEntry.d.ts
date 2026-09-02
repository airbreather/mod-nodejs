declare global {
	namespace Acore {
		class SpellCastTimesEntry {
			private constructor();

			static byId(id: number): SpellCastTimesEntry | undefined;

			readonly id: number;
			readonly castTime: Temporal.Duration;
		}
	}
}
export {};
