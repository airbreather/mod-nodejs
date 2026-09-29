declare global {
	interface Hooks {
		['loot:money']: {
			player: Acore.Player;
			gold: number;
		};
	}
}
export {};
