declare global {
	namespace Acore {
		class Minion extends TempSummon {
			readonly owner: Unit;
			readonly isPetGhoul: boolean;
			readonly isGuardianPet: boolean;

			followAngle: number;
		}
	}
}
export {};
