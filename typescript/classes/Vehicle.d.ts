declare global {
	namespace Acore {
		class Vehicle {
			readonly entry: number;
			readonly availableSeatCount: number;
			readonly owner: Unit;

			getPassenger(seat: number): WorldObject | undefined;
			isOnBoard(passenger: Unit): boolean;
			addPassenger(passenger: Unit, seatId?: number): void;
			removePassenger(passenger: Unit): void;
		}
	}
}
export {};
