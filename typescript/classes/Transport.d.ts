declare global {
	namespace Acore {
		class Transport extends GameObject {
			readonly isMotionTransport: boolean;
			readonly passengers: WorldObject[];
		}
	}
}
export {};
