declare global {
	namespace Acore {
		class DoorData {
			private constructor();

			readonly startOpen: boolean;
			readonly lockId: number;
			readonly autoCloseTime: Temporal.Duration;
			readonly noDamageImmune: boolean;
			readonly openTextId: number;
			readonly closeTextId: number;
			readonly ignoredByPathing: -1 | 0 | 1;
		}
	}
}
export {};
