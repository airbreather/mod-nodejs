declare global {
	interface Hooks {
		['nodejs:startup']: {
			reloaded: boolean;
			persistData: string;
		};
		['nodejs:before-shutdown']: {
			reloading: boolean;
			persistData: Acore.Box<string>;
		};
	}
}
export {};
