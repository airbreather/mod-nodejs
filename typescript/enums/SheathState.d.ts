declare global {
	// low byte (0 from 0..3) of UNIT_FIELD_BYTES_2
	const enum SheathState {
		SHEATH_STATE_UNARMED                = 0,        // non prepared weapon
		SHEATH_STATE_MELEE                  = 1,        // prepared melee weapon
		SHEATH_STATE_RANGED                 = 2,        // prepared ranged weapon
	}
}
export {};
