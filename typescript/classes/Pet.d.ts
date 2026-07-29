declare global {
	namespace Acore {
		class Pet extends Guardian {
			readonly isHappy: boolean;
			readonly owner: Player;
			readonly isControlled: boolean;
			readonly isTemporary: boolean;
			readonly hasTempSpell: boolean;
			readonly autoSpellSize: number;
			readonly petInfo: PetInfo;
			readonly spells: Map<number, PetSpellState>;
			readonly autospells: number[];
			readonly usedTalentCount: number;
			readonly declinedNames: string[];
		}
	}
}
export {};
