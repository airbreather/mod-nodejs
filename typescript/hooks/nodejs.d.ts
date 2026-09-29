declare global {
	interface Hooks {
		['nodejs:startup']: {
			persistData?: string;
		};
		['nodejs:before-shutdown']:
			| { reloading: false; }
			| { reloading: true; persistData: Acore.Box<string>; };
	}
}
export {};
