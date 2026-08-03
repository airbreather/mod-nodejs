declare global {
	interface Hooks {
		['unit:heal']: {
			readonly healer: Acore.Unit;
			readonly receiver: Acore.Unit;
			amount: number;
		};
		['unit:damage']: {
			readonly attacker: Acore.Unit;
			readonly victim: Acore.Unit;
			amount: number;
		};
		['unit:modify-periodic-damage-auras-tick']: {
			readonly target: Acore.Unit;
			readonly attacker: Acore.Unit;
			amount: number;
			readonly spellInfo: Acore.SpellInfo;
		};
		['unit:modify-melee-damage']: {
			readonly target: Acore.Unit;
			readonly attacker: Acore.Unit;
			amount: number;
		};
		['unit:modify-spell-damage-taken']: {
			readonly target: Acore.Unit;
			readonly attacker: Acore.Unit;
			amount: number;
			readonly spellInfo: Acore.SpellInfo;
		};
		['unit:modify-heal-received']: {
			readonly target: Acore.Unit;
			readonly healer: Acore.Unit;
			amount: number;
			readonly spellInfo: Acore.SpellInfo;
		};
		['unit:deal-damage']: {
			readonly attacker: Acore.Unit;
			readonly victim: Acore.Unit;
			readonly damage: number;
			readonly damageType: DamageEffectType;
			__return: number;
		};
		['unit:before-roll-melee-outcome-against']: {
			readonly attacker: Acore.Unit;
			readonly victim: Acore.Unit;
			readonly attType: WeaponAttackType;
			attackerMaxSkillValueForLevel: number;
			victimMaxSkillValueForLevel: number;
			attackerWeaponSkill: number;
			victimDefenseSkill: number;
			critChance: number;
			missChance: number;
			dodgeChance: number;
			parryChance: number;
			blockChance: number;
		};
		['unit:aura-apply']: {
			readonly unit: Acore.Unit;
			readonly aura: Acore.Aura;
		};
		['unit:aura-remove']: {
			readonly unit: Acore.Unit;
			readonly aurApp: Acore.AuraApplication;
			readonly mode: AuraRemoveMode;
		};
		['unit:if-normal-reaction']: {
			readonly unit: Acore.Unit;
			readonly target: Acore.Unit;
			repRank: ReputationRank;
			__return: boolean;
		};
		['unit:can-set-phase-mask']: {
			readonly unit: Acore.Unit;
			readonly newPhaseMask: number;
			readonly update: boolean;
			__return: boolean;
		};
		// ['unit:is-custom-build-values-update']: unknown; // I think this isn't actually ever used.
		['unit:should-track-values-update-pos-by-index']: {
			readonly unit: Acore.Unit;
			readonly updateType: OBJECT_UPDATE_TYPE;
			readonly index: number;
			__return: boolean;
		};
		['unit:patch-values-update']: {
			readonly unit: Acore.Unit;
			// valuesUpdateBuf: Acore.ByteBuffer;
			// posPointers: Acore.BuildValuesCachePosPointers;
			readonly target: Acore.Player;
		};
		['unit:update']: {
			readonly unit: Acore.Unit;
			readonly diff: Temporal.Duration;
		};
		['unit:display-id-change']: {
			readonly unit: Acore.Unit;
			readonly displayId: number;
		};
		['unit:enter-evade-mode']: {
			readonly unit: Acore.Unit;
			readonly evadeReason: EvadeReason;
		};
		['unit:enter-combat']: {
			readonly unit: Acore.Unit;
			readonly victim: Acore.Unit;
		};
		['unit:death']: {
			readonly unit: Acore.Unit;
			readonly killer: Acore.Unit | undefined;
		};
		['unit:set-shapeshift-form']: {
			readonly unit: Acore.Unit;
			readonly form: ShapeshiftForm;
		};
	}
}
export {};
