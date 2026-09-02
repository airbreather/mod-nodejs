declare global {
	namespace Acore {
		class AchievementEntry {
			private constructor();

			static byId(id: number): AchievementEntry | undefined;

			readonly id: number;
			readonly requiredFaction: number;
			readonly mapId: number;
			readonly name: string[];
			readonly categoryId: number;
			readonly points: number;
			readonly flags: AchievementFlags;
			readonly count: number;
			readonly refAchievement: number;
		}
	}
}
export {};
