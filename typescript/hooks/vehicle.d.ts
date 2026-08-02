declare global {
	interface Hooks {
		['vehicle:install']: { readonly vehicle: Acore.Vehicle; };
		['vehicle:uninstall']: { readonly vehicle: Acore.Vehicle; };
		['vehicle:reset']: { readonly vehicle: Acore.Vehicle; };
		['vehicle:install-accessory']: {
			readonly vehicle: Acore.Vehicle;
			readonly accessory: Acore.Creature;
		};
		['vehicle:add-passenger']: {
			readonly vehicle: Acore.Vehicle;
			readonly passenger: Acore.Unit;
			readonly seatId: number;
		};
		['vehicle:remove-passenger']: {
			readonly vehicle: Acore.Vehicle;
			readonly passenger: Acore.Unit;
		};
	}
}
export {};
