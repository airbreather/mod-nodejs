declare global {
	namespace Acore {
		class PvPDifficultyEntry {
			private constructor();

			readonly mapId: number;
			readonly bracketId: number;
			readonly minLevel: number;
			readonly maxLevel: number;
			readonly difficulty: number; // probably NOT the Difficulty enum, if I had to guess.
		}
	}
}
export {};
