declare global {
	namespace Acore {
		class AreaDamageData {
			private constructor();

			readonly lockId: number;
			readonly radius: number;
			readonly damageMin: number;
			readonly damageMax: number;
			// this is probably SpellSchools or SpellSchoolMask? can't validate.
			readonly damageSchool: number;
			readonly autoCloseTime: Temporal.Duration;
			readonly openTextId: number;
			readonly closeTextId: number;
		}
	}
}
export {};
