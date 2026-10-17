declare global {
	namespace Acore {
		class SummoningRitualData {
			private constructor();

			readonly reqParticipants: number;
			readonly spellId: number;
			readonly animSpell: number;
			readonly ritualPersistent: boolean;
			readonly casterTargetSpell: number;
			readonly casterTargetSpellTargets: number;
			readonly castersGrouped: boolean;
			readonly ritualNoTargetCheck: boolean;
		}
	}
}
export {};
