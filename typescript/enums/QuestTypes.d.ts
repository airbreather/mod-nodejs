declare global {
	// values based at QuestInfo.dbc
	const enum QuestTypes {
		QUEST_TYPE_ELITE               = 1,
		QUEST_TYPE_LIFE                = 21,
		QUEST_TYPE_PVP                 = 41,
		QUEST_TYPE_RAID                = 62,
		QUEST_TYPE_DUNGEON             = 81,
		QUEST_TYPE_WORLD_EVENT         = 82,
		QUEST_TYPE_LEGENDARY           = 83,
		QUEST_TYPE_ESCORT              = 84,
		QUEST_TYPE_HEROIC              = 85,
		QUEST_TYPE_RAID_10             = 88,
		QUEST_TYPE_RAID_25             = 89,
	}
}
export {};
