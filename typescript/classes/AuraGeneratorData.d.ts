declare global {
	namespace Acore {
		class AuraGeneratorData {
			private constructor();

			readonly startOpen: boolean;
			readonly radius: number;
			readonly auraId1: number;
			readonly conditionId1: number;
			readonly auraId2: number;
			readonly conditionId2: number;
			readonly serverOnly: number;
		}
	}
}
export {};
