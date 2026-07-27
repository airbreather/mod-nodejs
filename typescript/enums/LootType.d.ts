declare global {
	const enum LootType {
		LOOT_NONE                           = 0,

		LOOT_CORPSE                         = 1,
		LOOT_PICKPOCKETING                  = 2,
		LOOT_FISHING                        = 3,
		LOOT_DISENCHANTING                  = 4,
		// ignored always by client
		LOOT_SKINNING                       = 6,
		LOOT_PROSPECTING                    = 7,
		LOOT_MILLING                        = 8,

		LOOT_FISHINGHOLE                    = 20,   // unsupported by client, sending LOOT_FISHING instead
		LOOT_INSIGNIA                       = 21,   // unsupported by client, sending LOOT_CORPSE instead
		LOOT_FISHING_JUNK                   = 22,   // unsupported by client, sending LOOT_FISHING instead
	}
}
export {};
