declare global {
	interface CreatureMovementData {
		ground: CreatureGroundMovementType;
		flight: CreatureFlightMovementType;
		swim: boolean;
		rooted: boolean;
		chase: CreatureChaseMovementType;
		random: CreatureRandomMovementType;
		interactionPauseTimer: Temporal.Instant;
	}
}
export {};
