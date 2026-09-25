declare global {
	namespace Acore {
		class MoTransportData {
			private constructor();

			readonly taxiPathId: number;
			readonly moveSpeed: number;
			readonly accelRate: number;
			readonly startEventId: number;
			readonly stopEventId: number;
			readonly transportPhysics: number;
			readonly mapId: number;
			readonly worldState1: number;
			readonly canBeStopped: boolean;
		}
	}
}
export {};
