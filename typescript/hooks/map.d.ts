declare global {
	interface Hooks {
		['map:player-enter']: {
			map: Acore.ACMap;
			player: Acore.Player;
		};
		['map:player-leave']: {
			map: Acore.ACMap;
			player: Acore.Player;
		};
		['map:before-create-instance']: {
			instanceMap: Acore.ACMap; // Acore.InstanceMap
			// instanceData: Acore.InstanceScript;
			load: boolean;
			data: string;
			completedEncounterMask: number;
		};
		['map:destroy-instance']: {
			mapInstanced: Acore.ACMap; // Acore.MapInstanced
			map: Acore.ACMap; // Acore.MapInstanced
		};
		['map:create']: { map: Acore.ACMap; };
		['map:destroy']: { map: Acore.ACMap; };
		['map:update']: {
			map: Acore.ACMap;
			diff: Temporal.Duration;
		};
	}
}
export {};
