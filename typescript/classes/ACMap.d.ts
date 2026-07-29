declare global {
	namespace Acore {
		class ACMap {
			static nonInstancedById(id: number): ACMap;
			static instancedById(id: number, instanceId: number): ACMap;
			static entrancePosById(id: number): Position;

			readonly mapId: number;
			readonly instanceId: number;
			readonly isDungeon: boolean;
			readonly isRaid: boolean;
			readonly isBattleground: boolean;
			readonly isArena: boolean;
			readonly is25ManRaid: boolean;
			readonly isEmpty: boolean;
			readonly isHeroic: boolean;
			readonly difficulty: Difficulty;
			readonly playerCount: number;
			readonly alivePlayerCount: number;
			readonly name: string;
			readonly players: Player[];

			getPlayersInTeam(teamId: TeamId): Player[];
			getHeightAt(x: number, y: number, z: number, phaseMask?: number, vmap?: boolean, maxSearchDist?: number): number;
			getAreaIdAt(x: number, y: number, z: number, phaseMask?: number): number;
		}
	}
}
export {};
