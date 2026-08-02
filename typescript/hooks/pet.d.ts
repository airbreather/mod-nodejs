declare global {
	interface Hooks {
		['pet:init-stats-for-level']: {
			readonly pet: Acore.Guardian;
			readonly petLevel: number;
		};
		['pet:calculate-max-talent-points-for-level']: {
			readonly pet: Acore.Pet;
			readonly level: number;
			points: number;
		};
		['pet:can-unlearn-spell-set']: {
			readonly pet: Acore.Pet;
			readonly level: number;
			readonly spell: number;
			__return: boolean;
		};
		['pet:can-unlearn-spell-default']: {
			readonly pet: Acore.Pet;
			readonly spell: Acore.SpellInfo;
			__return: boolean;
		};
		['pet:can-reset-talents']: {
			readonly pet: Acore.Pet;
			__return: boolean;
		};
		['pet:add-to-world']: { readonly pet: Acore.Pet; };
	}
}
export {};
