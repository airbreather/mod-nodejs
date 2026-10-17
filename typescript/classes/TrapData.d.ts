declare global {
	namespace Acore {
		class TrapData {
			private constructor();

			readonly lockId: number;
			readonly level: number;
			readonly diameter: number;
			readonly spellId: number;
			readonly type: TrapType;
			readonly cooldown: Temporal.Duration;
			readonly autoCloseTime: Temporal.Duration;
			readonly startDelay: Temporal.Duration;
			readonly serverOnly: boolean;
			readonly stealthed: boolean;
			readonly large: boolean;
			readonly invisible: boolean;
			readonly openTextId: number;
			readonly closeTextId: number;
			readonly ignoreTotems: boolean;
		}
	}
}
export {};
