declare global {
	namespace Acore {
		class FlagStandData {
			private constructor();

			readonly lockId: number;
			readonly pickupSpell: number;
			readonly radius: number;
			readonly returnAura: number;
			readonly returnSpell: number;
			readonly noDamageImmune: boolean;
			readonly openTextId: number;
			readonly losOk: boolean;
		}
	}
}
export {};
