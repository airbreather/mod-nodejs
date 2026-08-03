declare global {
	interface Hooks {
		['spell:calc-max-duration']: {
			readonly aura: Acore.Aura;
			maxDuration: number;
		};
		['spell:check-cast']: {
			readonly spell: Acore.Spell;
			readonly strict: boolean;
			result: SpellCastResult;
		};
		['spell:can-prepare']: {
			readonly spell: Acore.Spell;
			__return: boolean;
		};
		['spell:can-scaling-everything']: {
			readonly spell: Acore.Spell;
			__return: boolean;
		};
		['spell:can-select-spec-talent']: {
			readonly spell: Acore.Spell;
			__return: boolean;
		};
		['spell:scale-aura-unit-add']: {
			readonly spell: Acore.Spell;
			readonly target: Acore.Unit;
			readonly effectMask: SpellEffIndexMask;
			readonly checkIfValid: boolean;
			readonly implicit: boolean;
			readonly auraScaleMask: SpellEffIndexMask;
			// targetInfo: TargetInfo;
		};
		['spell:remove-aura-scale-targets']: {
			readonly spell: Acore.Spell;
			// targetInfo: TargetInfo;
			readonly auraScaleMask: SpellEffIndexMask;
			needErase: boolean;
		};
		['spell:before-aura-rank-for-level']: {
			readonly spellInfo: Acore.SpellInfo;
			// setting this is not working right now because of what looks like a bug in Acore.
			latestSpellInfo: Acore.SpellInfo;
			readonly level: number;
		};
		['spell:dummy-effect:game-object-target']: {
			readonly caster: Acore.WorldObject;
			readonly spellId: number;
			readonly effIndex: SpellEffIndex;
			readonly target: Acore.GameObject;
		};
		['spell:dummy-effect:creature-target']: {
			readonly caster: Acore.WorldObject;
			readonly spellId: number;
			readonly effIndex: SpellEffIndex;
			readonly target: Acore.Creature;
		};
		['spell:dummy-effect:item-target']: {
			readonly caster: Acore.WorldObject;
			readonly spellId: number;
			readonly effIndex: SpellEffIndex;
			readonly target: Acore.Item;
		};
		['spell:cast-cancel']: {
			readonly spell: Acore.Spell;
			readonly caster: Acore.Unit;
			readonly spellInfo: Acore.SpellInfo;
			readonly bySelf: boolean;
		};
		['spell:cast']: {
			readonly spell: Acore.Spell;
			readonly caster: Acore.Unit;
			readonly spellInfo: Acore.SpellInfo;
			readonly skipCheck: boolean;
		};
		['spell:prepare']: {
			readonly spell: Acore.Spell;
			readonly caster: Acore.Unit;
			readonly spellInfo: Acore.SpellInfo;
		};
	}
}
export {};
