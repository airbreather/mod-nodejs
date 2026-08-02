declare global {
	const enum AURA_FLAGS {
		AFLAG_NONE                   = 0x00,
		AFLAG_EFF_INDEX_0            = 0x01,
		AFLAG_EFF_INDEX_1            = 0x02,
		AFLAG_EFF_INDEX_2            = 0x04,
		AFLAG_CASTER                 = 0x08,
		AFLAG_POSITIVE               = 0x10,
		AFLAG_DURATION               = 0x20,
		AFLAG_ANY_EFFECT_AMOUNT_SENT = 0x40, // used with AFLAG_EFF_INDEX_0/1/2
		AFLAG_NEGATIVE               = 0x80,
	}
}
export {};
