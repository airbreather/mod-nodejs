declare global {
	interface PetSpell {
		active: ActiveStates;
		state: PetSpellState;
		type: PetSpellType;
	}
}
export {};
