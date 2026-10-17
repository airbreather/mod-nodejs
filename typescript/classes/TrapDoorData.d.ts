declare global {
	namespace Acore {
		class TrapDoorData {
			private constructor();

			readonly whenToPause: number;
			readonly startOpen: boolean;
			readonly autoClose: boolean;
		}
	}
}
export {};
