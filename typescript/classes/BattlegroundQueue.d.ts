declare global {
	namespace Acore {
		class BattlegroundQueue {
			readonly queuedPlayers: Map<number, GroupQueueInfo>;

			getAverageQueueWaitTime(teamId: TeamId, bracketId: number): number;
			getAverageArenaQueueWaitTime(arenaType: number, isRated: boolean, bracketId: number): number;
			checkPremadeMatch(bracketId: number, minPlayersPerTeam: number, maxPlayersPerTeam: number): boolean;
		}
	}
}
export {};
