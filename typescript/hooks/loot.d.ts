declare global {
	interface Hooks {
		['loot:money']: {
			readonly player: Acore.Player;
			readonly gold: number;
		};
	}
}
export {};
