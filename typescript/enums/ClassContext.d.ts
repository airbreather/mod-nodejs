declare global {
	// Used for IsClass hook
	const enum ClassContext {
		CLASS_CONTEXT_NONE                  = 0,    // Default
		CLASS_CONTEXT_INIT                  = 1,
		CLASS_CONTEXT_TELEPORT              = 2,
		CLASS_CONTEXT_QUEST                 = 3,
		CLASS_CONTEXT_STATS                 = 4,
		CLASS_CONTEXT_TAXI                  = 5,
		CLASS_CONTEXT_SKILL                 = 6,
		CLASS_CONTEXT_TALENT_POINT_CALC     = 7,
		CLASS_CONTEXT_ABILITY               = 8,
		CLASS_CONTEXT_ABILITY_REACTIVE      = 9,
		CLASS_CONTEXT_PET                   = 10,
		CLASS_CONTEXT_PET_CHARM             = 11,
		CLASS_CONTEXT_EQUIP_RELIC           = 12,
		CLASS_CONTEXT_EQUIP_SHIELDS         = 13,
		CLASS_CONTEXT_EQUIP_ARMOR_CLASS     = 14,
		CLASS_CONTEXT_WEAPON_SWAP           = 15,
		CLASS_CONTEXT_GRAVEYARD             = 16,
		CLASS_CONTEXT_CLASS_TRAINER         = 17,
	}
}
export {};
