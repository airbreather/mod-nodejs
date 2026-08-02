declare global {
	const enum BattlegroundDesertionType {
		BG_DESERTION_TYPE_LEAVE_BG           = 0, // player leaves the BG
		BG_DESERTION_TYPE_OFFLINE            = 1, // player is kicked from BG because offline
		BG_DESERTION_TYPE_LEAVE_QUEUE        = 2, // player is invited to join and refuses to do it
		BG_DESERTION_TYPE_NO_ENTER_BUTTON    = 3, // player is invited to join and do nothing (time expires)
		BG_DESERTION_TYPE_INVITE_LOGOUT      = 4, // player is invited to join and logs out
		ARENA_DESERTION_TYPE_LEAVE_BG        = 5, // player leaves the Arena
		ARENA_DESERTION_TYPE_LEAVE_QUEUE     = 6, // player is invited to join arena and refuses to do it
		ARENA_DESERTION_TYPE_NO_ENTER_BUTTON = 7, // player is invited to join arena and do nothing (time expires)
		ARENA_DESERTION_TYPE_INVITE_LOGOUT   = 8, // player is invited to join arena and logs out
	}
}
export {};
