declare global {
	interface GlobalHooks {
		['world:startup']: object;
		['world:shutdown']: object;
		['world:update-early']: object;
		['world:update-late']: object;
	}
}
export {};
