declare global {
	const enum ProcFlagsHit {
		PROC_HIT_NONE                = 0x0000000, // no value - PROC_HIT_NORMAL | PROC_HIT_CRITICAL for TAKEN proc type, PROC_HIT_NORMAL | PROC_HIT_CRITICAL | PROC_HIT_ABSORB for DONE
		PROC_HIT_NORMAL              = 0x0000001, // non-critical hits
		PROC_HIT_CRITICAL            = 0x0000002,
		PROC_HIT_MISS                = 0x0000004,
		PROC_HIT_FULL_RESIST         = 0x0000008,
		PROC_HIT_DODGE               = 0x0000010,
		PROC_HIT_PARRY               = 0x0000020,
		PROC_HIT_BLOCK               = 0x0000040, // partial or full block
		PROC_HIT_EVADE               = 0x0000080,
		PROC_HIT_IMMUNE              = 0x0000100,
		PROC_HIT_DEFLECT             = 0x0000200,
		PROC_HIT_ABSORB              = 0x0000400, // partial or full absorb
		PROC_HIT_REFLECT             = 0x0000800,
		PROC_HIT_INTERRUPT           = 0x0001000, // (not used atm)
		PROC_HIT_FULL_BLOCK          = 0x0002000,
		PROC_HIT_MASK_ALL            = 0x0002FFF,
	}
}
export {};
