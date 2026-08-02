declare global {
	const enum DamageEffectType {
		DIRECT_DAMAGE           = 0,                            // used for normal weapon damage (not for class abilities or spells)
		SPELL_DIRECT_DAMAGE     = 1,                            // spell/class abilities damage
		DOT                     = 2,
		HEAL                    = 3,
		NODAMAGE                = 4,                            // used also in case when damage applied to health but not applied to spell channelInterruptFlags/etc
		SELF_DAMAGE             = 5,
	}
}
export {};
