declare global {
	namespace Acore {
		class BattlegroundQueue {
			readonly queuedPlayers: Map<number, GroupQueueInfo>;

			getAverageQueueWaitTime(teamId: TeamId, bracketId: number): Temporal.Duration;
			getAverageArenaQueueWaitTime(arenaType: number, isRated: boolean, bracketId: number): Temporal.Duration;
			checkPremadeMatch(bracketId: number, minPlayersPerTeam: number, maxPlayersPerTeam: number): boolean;
		}
	}
}
export {};
