declare global {
	interface PetInfo {
		name: string;
		actionBar: string;
		petNumber: number;
		creatureId: number;
		displayId: number;
		experience: number;
		health: number;
		mana: number;
		happiness: number;
		lastSaveTime: Temporal.Instant;
		createdBySpellId: number;
		level: number;
		reactState: ReactStates;
		type: PetType;
		wasRenamed: boolean;
	}
}
export {};
