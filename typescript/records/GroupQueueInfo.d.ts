declare global {
	interface GroupQueueInfo {
		players: bigint[];
		teamId: TeamId;
		realTeamID: TeamId; // TODO: consistent casing plz
		bgTypeId: BattlegroundTypeId;
		isRated: boolean;
		arenaType: ArenaType;
		arenaTeamId: number;
		joinTime: number;
		removeInviteTime: number;
		isInvitedToBGInstanceGUID: number; // TODO: consistent casing plz
		arenaTeamRating: number;
		arenaMatchmakerRating: number;
		opponentsTeamRating: number;
		opponentsMatchmakerRating: number;
		previousOpponentsTeamId: number;
		bracketId: number; // C++ enum BattlegroundBracketId just documents that this value is in [0,16)
		groupType: BattlegroundQueueGroupTypes;
	}
}
export {};
