declare global {
	interface AchievementEntry {
		id: number;
		requiredFaction: number;
		mapId: number;
		name: string[];
		categoryId: number;
		points: number;
		flags: AchievementFlags;
		count: number;
		refAchievement: number;
	}
}
export {};
