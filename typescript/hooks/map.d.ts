declare global {
	interface Hooks {
		['map:player-enter']: {
			readonly map: Acore.ACMap;
			readonly player: Acore.Player;
		};
		['map:player-leave']: {
			readonly map: Acore.ACMap;
			readonly player: Acore.Player;
		};
		['map:before-create-instance']: {
			readonly instanceMap: Acore.ACMap; // Acore.InstanceMap
			// readonly instanceData: Acore.InstanceScript;
			readonly load: boolean;
			readonly data: string;
			readonly completedEncounterMask: number;
		};
		['map:destroy-instance']: {
			readonly mapInstanced: Acore.ACMap; // Acore.MapInstanced
			readonly map: Acore.ACMap; // Acore.MapInstanced
		};
		['map:create']: { readonly map: Acore.ACMap; };
		['map:destroy']: { readonly map: Acore.ACMap; };
		['map:update']: {
			readonly map: Acore.ACMap;
			readonly diff: Temporal.Duration;
		};
	}
}
export {};
