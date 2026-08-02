declare global {
	// Spell dispel type
	const enum DispelType {
		DISPEL_NONE         = 0,
		DISPEL_MAGIC        = 1,
		DISPEL_CURSE        = 2,
		DISPEL_DISEASE      = 3,
		DISPEL_POISON       = 4,
		DISPEL_STEALTH      = 5,
		DISPEL_INVISIBILITY = 6,
		DISPEL_ALL          = 7,
		DISPEL_SPE_NPC_ONLY = 8,
		DISPEL_ENRAGE       = 9,
		DISPEL_ZG_TICKET    = 10,
		DESPEL_OLD_UNUSED   = 11,
		DISPEL_MAX,
	}
	// mod-nodejs invention
	const enum DispelTypeMask {
		DISPEL_MASK_NONE         = 1 << DispelType.DISPEL_NONE,
		DISPEL_MASK_MAGIC        = 1 << DispelType.DISPEL_MAGIC,
		DISPEL_MASK_CURSE        = 1 << DispelType.DISPEL_CURSE,
		DISPEL_MASK_DISEASE      = 1 << DispelType.DISPEL_DISEASE,
		DISPEL_MASK_POISON       = 1 << DispelType.DISPEL_POISON,
		DISPEL_MASK_STEALTH      = 1 << DispelType.DISPEL_STEALTH,
		DISPEL_MASK_INVISIBILITY = 1 << DispelType.DISPEL_INVISIBILITY,
		DISPEL_MASK_ALL          = DISPEL_MASK_MAGIC | DISPEL_MASK_CURSE | DISPEL_MASK_DISEASE | DISPEL_MASK_POISON,
		DISPEL_MASK_SPE_NPC_ONLY = 1 << DispelType.DISPEL_SPE_NPC_ONLY,
		DISPEL_MASK_ENRAGE       = 1 << DispelType.DISPEL_ENRAGE,
		DISPEL_MASK_ZG_TICKET    = 1 << DispelType.DISPEL_ZG_TICKET,
		DESPEL_MASK_OLD_UNUSED   = 1 << DispelType.DESPEL_OLD_UNUSED,
	}
}
export {};
