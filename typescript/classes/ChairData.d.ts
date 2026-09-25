declare global {
	namespace Acore {
		class ChairData {
			private constructor();

			readonly slots: number;
			readonly height: number;
			readonly onlyCreatorUse: boolean;
			readonly triggeredEvent: number;
		}
	}
}
export {};
