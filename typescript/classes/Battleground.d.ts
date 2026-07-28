declare global {
	namespace Acore {
		class Battleground {
			readonly name: string;
			readonly instanceId: number;
			readonly mapId: number;
			readonly battlegroundTypeId: BattlegroundTypeId;
			readonly playerScores: Map<number, BattlegroundScore>;
			isRandom: boolean;

			getPlayersCountByTeam(teamId: TeamId): number;
			getAlivePlayersCountByTeam(teamId: TeamId): number;
		}
	}
}
export {};
