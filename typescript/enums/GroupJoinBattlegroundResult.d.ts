declare global {
	const enum GroupJoinBattlegroundResult {
		// positive values are indexes in BattlemasterList.dbc
		ERR_GROUP_JOIN_BATTLEGROUND_FAIL        = 0,            // Your group has joined a battleground queue, but you are not eligible (showed for non existing BattlemasterList.dbc indexes)
		ERR_BATTLEGROUND_NONE                   = -1,           // not show anything
		ERR_GROUP_JOIN_BATTLEGROUND_DESERTERS   = -2,           // You cannot join the battleground yet because you or one of your party members is flagged as a Deserter.
		ERR_ARENA_TEAM_PARTY_SIZE               = -3,           // Incorrect party size for this arena.
		ERR_BATTLEGROUND_TOO_MANY_QUEUES        = -4,           // You can only be queued for 2 battles at once
		ERR_BATTLEGROUND_CANNOT_QUEUE_FOR_RATED = -5,           // You cannot queue for a rated match while queued for other battles
		ERR_BATTLEGROUND_QUEUED_FOR_RATED       = -6,           // You cannot queue for another battle while queued for a rated arena match
		ERR_BATTLEGROUND_TEAM_LEFT_QUEUE        = -7,           // Your team has left the arena queue
		ERR_BATTLEGROUND_NOT_IN_BATTLEGROUND    = -8,           // You can't do that in a battleground.
		ERR_BATTLEGROUND_JOIN_XP_GAIN           = -9,           // doesn't exist in client...
		ERR_BATTLEGROUND_JOIN_RANGE_INDEX       = -10,          // Cannot join the queue unless all members of your party are in the same battleground level range.
		ERR_BATTLEGROUND_JOIN_TIMED_OUT         = -11,          // %s was unavailable to join the queue. (ObjectGuid guid exist in client cache)
		ERR_BATTLEGROUND_JOIN_FAILED            = -12,          // Join as a group failed (ObjectGuid guid doesn't exist in client cache)
		ERR_LFG_CANT_USE_BATTLEGROUND           = -13,          // You cannot queue for a battleground or arena while using the dungeon system.
		ERR_IN_RANDOM_BG                        = -14,          // Can't do that while in a Random Battleground queue.
		ERR_IN_NON_RANDOM_BG                    = -15,          // Can't queue for Random Battleground while in another Battleground queue.
	}
}
export {};
