declare global {
	interface Hooks {
		['pet:init-stats-for-level']: {
			pet: Acore.Guardian;
			petLevel: number;
		};
		['pet:calculate-max-talent-points-for-level']: {
			pet: Acore.Pet;
			level: number;
			points: Acore.Box<number>;
		};
		['pet:can-unlearn-spell-set']: {
			pet: Acore.Pet;
			level: number;
			spell: number;
			__return: Acore.Box<boolean>;
		};
		['pet:can-unlearn-spell-default']: {
			pet: Acore.Pet;
			spellInfo: Acore.SpellInfo;
			__return: Acore.Box<boolean>;
		};
		['pet:can-reset-talents']: {
			pet: Acore.Pet;
			__return: Acore.Box<boolean>;
		};
		['pet:add-to-world']: { pet: Acore.Pet; };
	}
}
export {};
