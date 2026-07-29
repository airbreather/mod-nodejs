declare global {
	// -1 from client enchantment slot number
	const enum EnchantmentSlot {
		PERM_ENCHANTMENT_SLOT           = 0,
		TEMP_ENCHANTMENT_SLOT           = 1,
		SOCK_ENCHANTMENT_SLOT           = 2,
		SOCK_ENCHANTMENT_SLOT_2         = 3,
		SOCK_ENCHANTMENT_SLOT_3         = 4,
		BONUS_ENCHANTMENT_SLOT          = 5,
		PRISMATIC_ENCHANTMENT_SLOT      = 6,                    // added at apply special permanent enchantment
		MAX_INSPECTED_ENCHANTMENT_SLOT  = 7,

		PROP_ENCHANTMENT_SLOT_0         = 7,                    // used with RandomSuffix and RandomProperty
		PROP_ENCHANTMENT_SLOT_1         = 8,                    // used with RandomSuffix and RandomProperty
		PROP_ENCHANTMENT_SLOT_2         = 9,                    // used with RandomSuffix and RandomProperty
		PROP_ENCHANTMENT_SLOT_3         = 10,                   // used with RandomSuffix and RandomProperty
		PROP_ENCHANTMENT_SLOT_4         = 11,                   // used with RandomSuffix and RandomProperty
		MAX_ENCHANTMENT_SLOT            = 12,
	}
}
export {};
