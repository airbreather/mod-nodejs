declare global {
	namespace Acore {
		class TrainerSpell {
			constructor();

			spellId: number;
			usable: TrainerSpellState;
			moneyCost: number;
			isPrimaryProfessionFirstRank: boolean;
			reqLevel: number;
			reqSkillLine: SkillType;
			reqSkillRank: number;
			// spell ID
			reqAbility0: number;
			// spell ID
			reqAbility1: number;
			// spell ID
			reqAbility2: number;
		}
	}
}
export {};
