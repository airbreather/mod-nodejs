declare global {
	interface Hooks {
		['vehicle:install']: { vehicle: Acore.Vehicle; };
		['vehicle:uninstall']: { vehicle: Acore.Vehicle; };
		['vehicle:reset']: { vehicle: Acore.Vehicle; };
		['vehicle:install-accessory']: {
			vehicle: Acore.Vehicle;
			accessory: Acore.Creature;
		};
		['vehicle:add-passenger']: {
			vehicle: Acore.Vehicle;
			passenger: Acore.Unit;
			seatId: number;
		};
		['vehicle:remove-passenger']: {
			vehicle: Acore.Vehicle;
			passenger: Acore.Unit;
		};
	}
}
export {};
