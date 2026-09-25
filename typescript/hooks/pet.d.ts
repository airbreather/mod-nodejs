declare global {
	interface GlobalHooks {
		['pet:init-stats-for-level']: {
			readonly pet: Acore.Guardian;
			readonly petLevel: number;
		};
		['pet:calculate-max-talent-points-for-level']: {
			readonly pet: Acore.Pet;
			readonly level: number;
			readonly points: Acore.Box<number>;
		};
		['pet:can-unlearn-spell-set']: {
			readonly pet: Acore.Pet;
			readonly level: number;
			readonly spell: number;
			readonly __return: Acore.Box<boolean>;
		};
		['pet:can-unlearn-spell-default']: {
			readonly pet: Acore.Pet;
			readonly spellInfo: Acore.SpellInfo;
			readonly __return: Acore.Box<boolean>;
		};
		['pet:can-reset-talents']: {
			readonly pet: Acore.Pet;
			readonly __return: Acore.Box<boolean>;
		};
		['pet:add-to-world']: { readonly pet: Acore.Pet; };
	}
}
export {};
