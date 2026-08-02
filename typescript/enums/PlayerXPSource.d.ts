declare global {
	// Used for OnGiveXP PlayerScript hook
	const enum PlayerXPSource {
		XPSOURCE_KILL = 0,
		XPSOURCE_QUEST = 1,
		XPSOURCE_QUEST_DF = 2,
		XPSOURCE_EXPLORE = 3,
		XPSOURCE_BATTLEGROUND = 4,
	}
}
export {};
