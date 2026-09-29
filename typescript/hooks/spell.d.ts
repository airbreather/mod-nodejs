declare global {
	interface Hooks {
		['spell:calc-max-duration']: {
			aura: Acore.Aura;
			maxDuration: Acore.Box<number>;
		};
		['spell:check-cast']: {
			spell: Acore.Spell;
			strict: boolean;
			result: Acore.Box<SpellCastResult>;
		};
		['spell:can-prepare']: {
			spell: Acore.Spell;
			__return: Acore.Box<boolean>;
		};
		['spell:can-scaling-everything']: {
			spell: Acore.Spell;
			__return: Acore.Box<boolean>;
		};
		['spell:can-select-spec-talent']: {
			spell: Acore.Spell;
			__return: Acore.Box<boolean>;
		};
		['spell:scale-aura-unit-add']: {
			spell: Acore.Spell;
			target: Acore.Unit;
			effectMask: SpellEffIndexMask;
			checkIfValid: boolean;
			implicit: boolean;
			auraScaleMask: SpellEffIndexMask;
			// targetInfo: TargetInfo;
		};
		['spell:remove-aura-scale-targets']: {
			spell: Acore.Spell;
			// targetInfo: TargetInfo;
			auraScaleMask: SpellEffIndexMask;
			needErase: Acore.Box<boolean>;
		};
		['spell:before-aura-rank-for-level']: {
			spellInfo: Acore.SpellInfo;
			// setting this is not working right now because of what looks like a bug in Acore.
			latestSpellInfo: Acore.Box<Acore.SpellInfo>;
			level: number;
		};
		['spell:dummy-effect:game-object-target']: {
			caster: Acore.WorldObject;
			spellId: number;
			effIndex: SpellEffIndex;
			target: Acore.GameObject;
		};
		['spell:dummy-effect:creature-target']: {
			caster: Acore.WorldObject;
			spellId: number;
			effIndex: SpellEffIndex;
			target: Acore.Creature;
		};
		['spell:dummy-effect:item-target']: {
			caster: Acore.WorldObject;
			spellId: number;
			effIndex: SpellEffIndex;
			target: Acore.Item;
		};
		['spell:cast-cancel']: {
			spell: Acore.Spell;
			caster: Acore.Unit;
			spellInfo: Acore.SpellInfo;
			bySelf: boolean;
		};
		['spell:cast']: {
			spell: Acore.Spell;
			caster: Acore.Unit;
			spellInfo: Acore.SpellInfo;
			skipCheck: boolean;
		};
		['spell:prepare']: {
			spell: Acore.Spell;
			caster: Acore.Unit;
			spellInfo: Acore.SpellInfo;
		};
	}
}
export {};
