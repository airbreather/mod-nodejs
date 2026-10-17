declare global {
	namespace Acore {
		class GuardPostData {
			private constructor();

			readonly creatureId: number;
			readonly charges: number;
		}
	}
}
export {};
