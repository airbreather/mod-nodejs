declare global {
	interface GlobalHooks {
		['unit:heal']: {
			readonly healer: Acore.Unit;
			readonly receiver: Acore.Unit;
			readonly amount: Acore.Box<number>;
		};
		['unit:damage']: {
			readonly attacker: Acore.Unit;
			readonly victim: Acore.Unit;
			readonly amount: Acore.Box<number>;
		};
		['unit:modify-periodic-damage-auras-tick']: {
			readonly target: Acore.Unit;
			readonly attacker: Acore.Unit;
			readonly amount: Acore.Box<number>;
			readonly spellInfo: Acore.SpellInfo;
		};
		['unit:modify-melee-damage']: {
			readonly target: Acore.Unit;
			readonly attacker: Acore.Unit;
			readonly amount: Acore.Box<number>;
		};
		['unit:modify-spell-damage-taken']: {
			readonly target: Acore.Unit;
			readonly attacker: Acore.Unit;
			readonly amount: Acore.Box<number>;
			readonly spellInfo: Acore.SpellInfo;
		};
		['unit:modify-heal-received']: {
			readonly target: Acore.Unit;
			readonly healer: Acore.Unit;
			readonly amount: Acore.Box<number>;
			readonly spellInfo: Acore.SpellInfo;
		};
		['unit:deal-damage']: {
			readonly attacker: Acore.Unit;
			readonly victim: Acore.Unit;
			readonly amount: number;
			readonly damageType: DamageEffectType;
			readonly __return: Acore.Box<number>;
		};
		['unit:before-roll-melee-outcome-against']: {
			readonly attacker: Acore.Unit;
			readonly victim: Acore.Unit;
			readonly attType: WeaponAttackType;
			readonly attackerMaxSkillValueForLevel: Acore.Box<number>;
			readonly victimMaxSkillValueForLevel: Acore.Box<number>;
			readonly attackerWeaponSkill: Acore.Box<number>;
			readonly victimDefenseSkill: Acore.Box<number>;
			readonly critChance: Acore.Box<number>;
			readonly missChance: Acore.Box<number>;
			readonly dodgeChance: Acore.Box<number>;
			readonly parryChance: Acore.Box<number>;
			readonly blockChance: Acore.Box<number>;
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
			readonly repRank: Acore.Box<ReputationRank>;
			readonly __return: Acore.Box<boolean>;
		};
		['unit:can-set-phase-mask']: {
			readonly unit: Acore.Unit;
			readonly newPhaseMask: number;
			readonly update: boolean;
			readonly __return: Acore.Box<boolean>;
		};
		['unit:should-track-values-update-pos-by-index']: {
			readonly unit: Acore.Unit;
			readonly updateType: OBJECT_UPDATE_TYPE;
			readonly index: number;
			readonly __return: Acore.Box<boolean>;
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
