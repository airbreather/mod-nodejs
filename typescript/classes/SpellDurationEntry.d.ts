declare global {
	namespace Acore {
		class SpellDurationEntry {
			private constructor();

			static byId(id: number): SpellDurationEntry | undefined;

			readonly id: number;
			readonly duration0: Temporal.Duration;
			readonly duration1: Temporal.Duration;
			readonly duration2: Temporal.Duration;
		}
	}
}
export {};
