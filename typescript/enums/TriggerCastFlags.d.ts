declare global {
	const enum TriggerCastFlags {
		TRIGGERED_NONE                                  = 0x00000000,   //! Not triggered
		TRIGGERED_IGNORE_GCD                            = 0x00000001,   //! Will ignore GCD
		TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD          = 0x00000002,   //! Will ignore Spell and Category cooldowns
		TRIGGERED_IGNORE_POWER_AND_REAGENT_COST         = 0x00000004,   //! Will ignore power and reagent cost
		TRIGGERED_IGNORE_CAST_ITEM                      = 0x00000008,   //! Will not take away cast item or update related achievement criteria
		TRIGGERED_IGNORE_AURA_SCALING                   = 0x00000010,   //! Will ignore aura scaling
		TRIGGERED_IGNORE_CAST_IN_PROGRESS               = 0x00000020,   //! Will not check if a current cast is in progress
		TRIGGERED_IGNORE_COMBO_POINTS                   = 0x00000040,   //! Will ignore combo point requirement
		TRIGGERED_CAST_DIRECTLY                         = 0x00000080,   //! In Spell::prepare, will be cast directly without setting containers for executed spell
		TRIGGERED_IGNORE_AURA_INTERRUPT_FLAGS           = 0x00000100,   //! Will ignore interruptible aura's at cast
		TRIGGERED_IGNORE_SET_FACING                     = 0x00000200,   //! Will not adjust facing to target (if any)
		TRIGGERED_IGNORE_SHAPESHIFT                     = 0x00000400,   //! Will ignore shapeshift checks
		TRIGGERED_IGNORE_CASTER_AURASTATE               = 0x00000800,   //! Will ignore caster aura states including combat requirements and death state
		TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE   = 0x00002000,   //! Will ignore mounted/on vehicle restrictions
		TRIGGERED_IGNORE_CASTER_AURAS                   = 0x00010000,   //! Will ignore caster aura restrictions or requirements
		TRIGGERED_DISALLOW_PROC_EVENTS                  = 0x00020000,   //! Disallows proc events from triggered spell (default)
		TRIGGERED_DONT_REPORT_CAST_ERROR                = 0x00040000,   //! Will return SPELL_FAILED_DONT_REPORT in CheckCast functions
		TRIGGERED_FULL_MASK                             = 0x0007FFFF,   //! Used when doing CastSpell with triggered == true
		TRIGGERED_IGNORE_EQUIPPED_ITEM_REQUIREMENT      = 0x00080000,   //! Will ignore equipped item requirements
		TRIGGERED_NO_PERIODIC_RESET                     = 0x00100000,   //! Periodic aura tick wont be reset on override
		TRIGGERED_IGNORE_EFFECTS                        = 0x00200000,   //! Ignore spell effects - used for ritual portals
		TRIGGERED_FULL_DEBUG_MASK                       = 0xFFFFFFFF,
	}
}
export {};
