declare global {
	interface Hooks {
		['world-object:destroy']: { readonly obj: Acore.WorldObject; };
		['world-object:create']: { readonly obj: Acore.WorldObject; };
		['world-object:set-map']: {
			readonly obj: Acore.WorldObject;
			readonly map: Acore.ACMap;
		};
		['world-object:reset-map']: { readonly obj: Acore.WorldObject; };
		['world-object:update']: {
			readonly obj: Acore.WorldObject;
			readonly diff: Temporal.Duration;
		};
	}
}
export {};
