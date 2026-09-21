declare global {
	namespace Acore {
		class FlagDropData {
			private constructor();

			readonly lockId: number;
			readonly eventId: number;
			readonly pickupSpell: number;
			readonly noDamageImmune: boolean;
			readonly openTextId: number;
		}
	}
}
export {};
