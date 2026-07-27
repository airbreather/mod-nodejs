declare global {
	// loot modes for creatures and gameobjects, bitmask!
	const enum LootModes {
		LOOT_MODE_DEFAULT                  = 0x01,
		LOOT_MODE_HARD_MODE_1              = 0x02,
		LOOT_MODE_HARD_MODE_2              = 0x04,
		LOOT_MODE_HARD_MODE_3              = 0x08,
		LOOT_MODE_HARD_MODE_4              = 0x10,
		LOOT_MODE_JUNK_FISH                = 0x8000,
	}
}
export {};
