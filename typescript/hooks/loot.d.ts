declare global {
	interface GlobalHooks {
		['loot:money']: {
			readonly player: Acore.Player;
			readonly gold: number;
		};
	}
}
export {};
