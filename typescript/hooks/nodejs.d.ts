declare global {
	interface Hooks {
		['nodejs:startup']: { readonly persistData?: string };
		['nodejs:before-shutdown']: { readonly reloading: false; } | { readonly reloading: true; persistData: string; };
	}
}
export {};
