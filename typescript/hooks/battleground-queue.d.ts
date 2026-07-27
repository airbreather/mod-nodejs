declare global {
	interface Hooks {
		['battleground-queue:update-validity']: {
			readonly queue: Acore.BattlegroundQueue;
			readonly diff: number;
			readonly bgTypeId: BattlegroundTypeId;
			readonly bracketId: number;
			readonly arenaType: ArenaType;
			readonly isRated: boolean;
			readonly arenaRating: number;
			__return: boolean;
		};
	}
}
export {};
