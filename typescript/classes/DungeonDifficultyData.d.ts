declare global {
	namespace Acore {
		class DungeonDifficultyData {
			private constructor();

			readonly mapId: number;
			readonly difficulty: Difficulty;
		}
	}
}
export {};
