declare global {
	interface Hooks {
		['world-object:destroy']: { obj: Acore.WorldObject; };
		['world-object:create']: { obj: Acore.WorldObject; };
		['world-object:set-map']: {
			obj: Acore.WorldObject;
			map: Acore.ACMap;
		};
		['world-object:reset-map']: { obj: Acore.WorldObject; };
		['world-object:update']: {
			obj: Acore.WorldObject;
			diff: Temporal.Duration;
		};
	}
}
export {};
