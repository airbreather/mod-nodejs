declare global {
	namespace Acore {
		class TransportData {
			private constructor();

			readonly pauseAtTime: Temporal.Duration;
			readonly startOpen: boolean;
			readonly autoCloseTime: Temporal.Duration;
			readonly pause1EventId: number;
			readonly pause2EventId: number;
		}
	}
}
export {};
