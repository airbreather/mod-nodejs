declare global {
	// PLAYER_FIELD_ARENA_TEAM_INFO_1_1 offsets
	const enum ArenaTeamInfoType {
		ARENA_TEAM_ID                = 0,
		ARENA_TEAM_TYPE              = 1,                       // new in 3.2 - team type?
		ARENA_TEAM_MEMBER            = 2,                       // 0 - captain, 1 - member
		ARENA_TEAM_GAMES_WEEK        = 3,
		ARENA_TEAM_GAMES_SEASON      = 4,
		ARENA_TEAM_WINS_SEASON       = 5,
		ARENA_TEAM_PERSONAL_RATING   = 6,
		ARENA_TEAM_END               = 7,
	}
}
export {};
