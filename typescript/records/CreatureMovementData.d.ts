declare global {
	interface CreatureMovementData {
		ground: CreatureGroundMovementType;
		flight: CreatureFlightMovementType;
		swim: boolean;
		rooted: boolean;
		chase: CreatureChaseMovementType;
		random: CreatureRandomMovementType;
		interactionPauseTimer: number;
	}
}
export {};
