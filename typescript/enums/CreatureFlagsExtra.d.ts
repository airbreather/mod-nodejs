declare global {
	const enum CreatureFlagsExtra {
		CREATURE_FLAG_EXTRA_INSTANCE_BIND                   = 0x00000001,   // creature kill bind instance with killer and killer's group
		CREATURE_FLAG_EXTRA_CIVILIAN                        = 0x00000002,   // not aggro (ignore faction/reputation hostility)
		CREATURE_FLAG_EXTRA_NO_PARRY                        = 0x00000004,   // creature can't parry
		CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN                 = 0x00000008,   // creature can't counter-attack at parry
		CREATURE_FLAG_EXTRA_NO_BLOCK                        = 0x00000010,   // creature can't block
		CREATURE_FLAG_EXTRA_NO_CRUSHING_BLOWS               = 0x00000020,   // creature can't do crush attacks
		CREATURE_FLAG_EXTRA_NO_XP                           = 0x00000040,   // creature kill does not provide XP
		CREATURE_FLAG_EXTRA_TRIGGER                         = 0x00000080,   // trigger creature
		CREATURE_FLAG_EXTRA_NO_TAUNT                        = 0x00000100,   // creature is immune to taunt auras and 'attack me' effects
		CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE            = 0x00000200,   // creature won't update movement flags
		CREATURE_FLAG_EXTRA_GHOST_VISIBILITY                = 0x00000400,   // creature will only be visible to dead players
		CREATURE_FLAG_EXTRA_USE_OFFHAND_ATTACK              = 0x00000800,   // creature will use offhand attacks
		CREATURE_FLAG_EXTRA_NO_SELL_VENDOR                  = 0x00001000,   // players can't sell items to this vendor
		CREATURE_FLAG_EXTRA_CANNOT_ENTER_COMBAT             = 0x00002000,   // creature is not allowed to enter combat
		CREATURE_FLAG_EXTRA_WORLDEVENT                      = 0x00004000,   // custom flag for world event creatures (left room for merging)
		CREATURE_FLAG_EXTRA_GUARD                           = 0x00008000,   // Creature is guard
		CREATURE_FLAG_EXTRA_IGNORE_FEIGN_DEATH              = 0x00010000,   // creature ignores feign death
		CREATURE_FLAG_EXTRA_NO_CRIT                         = 0x00020000,   // creature can't do critical strikes
		CREATURE_FLAG_EXTRA_NO_SKILL_GAINS                  = 0x00040000,   // creature won't increase weapon skills
		CREATURE_FLAG_EXTRA_OBEYS_TAUNT_DIMINISHING_RETURNS = 0x00080000,   // Taunt is subject to diminishing returns on this creature
		CREATURE_FLAG_EXTRA_ALL_DIMINISH                    = 0x00100000,   // creature is subject to all diminishing returns as players are
		CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ            = 0x00200000,   // creature does not need to take player damage for kill credit
		CREATURE_FLAG_EXTRA_AVOID_AOE                       = 0x00400000,   // pussywizard: ignored by aoe attacks (for icc blood prince council npc - Dark Nucleus)
		CREATURE_FLAG_EXTRA_NO_DODGE                        = 0x00800000,   // xinef: target cannot dodge
		CREATURE_FLAG_EXTRA_MODULE                          = 0x01000000,
		CREATURE_FLAG_EXTRA_DONT_CALL_ASSISTANCE            = 0x02000000,   // Prevent creatures from calling for assistance on initial aggro
		CREATURE_FLAG_EXTRA_IGNORE_ALL_ASSISTANCE_CALLS     = 0x04000000,   // Prevents creature from responding to assistance calls
		CREATURE_FLAG_EXTRA_DONT_OVERRIDE_ENTRY_SAI         = 0x08000000,   // Load both ENTRY and GUID specific SAI
		CREATURE_FLAG_EXTRA_DUNGEON_BOSS                    = 0x10000000,   // creature is a dungeon boss (SET DYNAMICALLY, DO NOT ADD IN DB)
		CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING              = 0x20000000,   // creature ignore pathfinding
		CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK              = 0x40000000,   // creature is immune to knockback effects
		CREATURE_FLAG_EXTRA_HARD_RESET                      = 0x80000000,

		// Masks
		CREATURE_FLAG_EXTRA_DB_ALLOWED                      = (0xFFFFFFFF & ~CREATURE_FLAG_EXTRA_DUNGEON_BOSS), // SKIP
	}
}
export {};
