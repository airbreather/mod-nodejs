declare global {
	const enum RollMask {
		ROLL_FLAG_TYPE_PASS                 = 0x01,
		ROLL_FLAG_TYPE_NEED                 = 0x02,
		ROLL_FLAG_TYPE_GREED                = 0x04,
		ROLL_FLAG_TYPE_DISENCHANT           = 0x08,

		ROLL_ALL_TYPE_NO_DISENCHANT         = 0x07,
		ROLL_ALL_TYPE_MASK                  = 0x0F,
	}
}
export {};
