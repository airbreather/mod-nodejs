declare global {
	interface PvPDifficultyEntry {
		mapId: number;
		bracketId: number;
		minLevel: number;
		maxLevel: number;
		difficulty: number; // probably NOT the Difficulty enum, if I had to guess.
	}
}
export {};
