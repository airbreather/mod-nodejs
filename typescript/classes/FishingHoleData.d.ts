declare global {
	namespace Acore {
		class FishingHoleData {
			private constructor();

			readonly radius: number;
			readonly lootId: number;
			readonly minSuccessOpens: number;
			readonly maxSuccessOpens: number;
			readonly lockId: number;
		}
	}
}
export {};
