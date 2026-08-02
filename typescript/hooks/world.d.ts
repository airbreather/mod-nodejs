declare global {
	interface Hooks {
		['world:startup']: object;
		['world:shutdown']: object;
	}
}
export {};
