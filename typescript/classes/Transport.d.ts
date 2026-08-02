declare global {
	namespace Acore {
		class Transport extends GameObject {
			readonly isMotionTransport: boolean;
			readonly passengers: WorldObject[];

			addPassenger(passenger: WorldObject, withAll?: boolean): void;
			removePassenger(passenger: WorldObject, withAll?: boolean): void;
			enableMovement(enabled: boolean): void;
		}
	}
}
export {};
