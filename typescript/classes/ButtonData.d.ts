declare global {
	namespace Acore {
		class ButtonData {
			private constructor();

			readonly startOpen: boolean;
			readonly lockId: number;
			readonly autoCloseTime: Temporal.Duration;
			readonly linkedTrap: number;
			readonly noDamageImmune: boolean;
			readonly large: boolean;
			readonly openTextId: number;
			readonly closeTextId: number;
			readonly losOk: boolean;
		}
	}
}
export {};
