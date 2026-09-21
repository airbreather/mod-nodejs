declare global {
	namespace Acore {
		class AreaDamageData {
			private constructor();

			readonly lockId: number;
			readonly radius: number;
			readonly damageMin: number;
			readonly damageMax: number;
			readonly damageSchool: SpellSchools;
			readonly autoCloseTime: Temporal.Duration;
			readonly openTextId: number;
			readonly closeTextId: number;
		}
	}
}
export {};
