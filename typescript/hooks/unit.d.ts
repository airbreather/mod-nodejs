declare global {
	interface Hooks {
		['unit:heal']: {
			healer: Acore.Unit;
			receiver: Acore.Unit;
			amount: Acore.Box<number>;
		};
		['unit:damage']: {
			attacker: Acore.Unit;
			victim: Acore.Unit;
			amount: Acore.Box<number>;
		};
		['unit:modify-periodic-damage-auras-tick']: {
			target: Acore.Unit;
			attacker: Acore.Unit;
			amount: Acore.Box<number>;
			spellInfo: Acore.SpellInfo;
		};
		['unit:modify-melee-damage']: {
			target: Acore.Unit;
			attacker: Acore.Unit;
			amount: Acore.Box<number>;
		};
		['unit:modify-spell-damage-taken']: {
			target: Acore.Unit;
			attacker: Acore.Unit;
			amount: Acore.Box<number>;
			spellInfo: Acore.SpellInfo;
		};
		['unit:modify-heal-received']: {
			target: Acore.Unit;
			healer: Acore.Unit;
			amount: Acore.Box<number>;
			spellInfo: Acore.SpellInfo;
		};
		['unit:deal-damage']: {
			attacker: Acore.Unit;
			victim: Acore.Unit;
			amount: number;
			damageType: DamageEffectType;
			__return: Acore.Box<number>;
		};
		['unit:before-roll-melee-outcome-against']: {
			attacker: Acore.Unit;
			victim: Acore.Unit;
			attType: WeaponAttackType;
			attackerMaxSkillValueForLevel: Acore.Box<number>;
			victimMaxSkillValueForLevel: Acore.Box<number>;
			attackerWeaponSkill: Acore.Box<number>;
			victimDefenseSkill: Acore.Box<number>;
			critChance: Acore.Box<number>;
			missChance: Acore.Box<number>;
			dodgeChance: Acore.Box<number>;
			parryChance: Acore.Box<number>;
			blockChance: Acore.Box<number>;
		};
		['unit:aura-apply']: {
			unit: Acore.Unit;
			aura: Acore.Aura;
		};
		['unit:aura-remove']: {
			unit: Acore.Unit;
			aurApp: Acore.AuraApplication;
			mode: AuraRemoveMode;
		};
		['unit:if-normal-reaction']: {
			unit: Acore.Unit;
			target: Acore.Unit;
			repRank: Acore.Box<ReputationRank>;
			__return: Acore.Box<boolean>;
		};
		['unit:can-set-phase-mask']: {
			unit: Acore.Unit;
			newPhaseMask: number;
			update: boolean;
			__return: Acore.Box<boolean>;
		};
		['unit:should-track-values-update-pos-by-index']: {
			unit: Acore.Unit;
			updateType: OBJECT_UPDATE_TYPE;
			index: number;
			__return: Acore.Box<boolean>;
		};
		['unit:patch-values-update']: {
			unit: Acore.Unit;
			// valuesUpdateBuf: Acore.ByteBuffer;
			// posPointers: Acore.BuildValuesCachePosPointers;
			target: Acore.Player;
		};
		['unit:update']: {
			unit: Acore.Unit;
			diff: Temporal.Duration;
		};
		['unit:display-id-change']: {
			unit: Acore.Unit;
			displayId: number;
		};
		['unit:enter-evade-mode']: {
			unit: Acore.Unit;
			evadeReason: EvadeReason;
		};
		['unit:enter-combat']: {
			unit: Acore.Unit;
			victim: Acore.Unit;
		};
		['unit:death']: {
			unit: Acore.Unit;
			killer: Acore.Unit | undefined;
		};
		['unit:set-shapeshift-form']: {
			unit: Acore.Unit;
			form: ShapeshiftForm;
		};
	}
}
export {};
