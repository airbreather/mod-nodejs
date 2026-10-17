declare global {
	namespace Acore {
		class CapturePointData {
			private constructor();

			readonly radius: number;
			readonly spell: number;
			readonly worldState1: number;
			readonly worldstate2: number;
			readonly winEventId1: number;
			readonly winEventId2: number;
			readonly contestedEventId1: number;
			readonly contestedEventId2: number;
			readonly progressEventId1: number;
			readonly progressEventId2: number;
			readonly neutralEventId1: number;
			readonly neutralEventId2: number;
			readonly neutralPercent: number;
			readonly worldstate3: number;
			readonly minSuperiority: number;
			readonly maxSuperiority: number;
			readonly minTime: Temporal.Duration;
			readonly maxTime: Temporal.Duration;
			readonly large: boolean;
			readonly highlight: boolean;
			readonly startingValue: number;
			readonly unidirectional: boolean;
		}
	}
}
export {};
