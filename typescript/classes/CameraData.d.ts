declare global {
	namespace Acore {
		class CameraData {
			private constructor();

			readonly lockId: number;
			readonly cinematicId: number;
			readonly eventId: number;
			readonly openTextId: number;
		}
	}
}
export {};
