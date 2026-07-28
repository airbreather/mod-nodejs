declare global {
	namespace Acore {
		class BattlegroundQueue {
			readonly queuedPlayers: Map<number, GroupQueueInfo>;

			getAverageQueueWaitTime(teamId: TeamId, bracketId: number): number;
			getAverageArenaQueueWaitTime(arenaType: 2 | 3 | 5, isRated: boolean, bracketId: number): number;
			checkPremadeMatch(bracketId: number, minPlayersPerTeam: number, maxPlayersPerTeam: number): boolean;
		}
	}
}
export {};
