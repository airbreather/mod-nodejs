declare global {
	const enum UnitFlags2 {
		UNIT_FLAG2_NONE                         = 0x00000000,
		UNIT_FLAG2_FEIGN_DEATH                  = 0x00000001,
		UNIT_FLAG2_HIDE_BODY                    = 0x00000002,       // Hide unit model (show only player equip)
		UNIT_FLAG2_IGNORE_REPUTATION            = 0x00000004,
		UNIT_FLAG2_COMPREHEND_LANG              = 0x00000008,
		UNIT_FLAG2_MIRROR_IMAGE                 = 0x00000010,
		UNIT_FLAG2_DO_NOT_FADE_IN               = 0x00000020,       // Unit model instantly appears when summoned (does not fade in)
		UNIT_FLAG2_FORCE_MOVEMENT               = 0x00000040,
		UNIT_FLAG2_DISARM_OFFHAND               = 0x00000080,
		UNIT_FLAG2_DISABLE_PRED_STATS           = 0x00000100,       // Player has disabled predicted stats (Used by raid frames)
		UNIT_FLAG2_DISARM_RANGED                = 0x00000400,       // this does not disable ranged weapon display (maybe additional flag needed?)
		UNIT_FLAG2_REGENERATE_POWER             = 0x00000800,
		UNIT_FLAG2_RESTRICT_PARTY_INTERACTION   = 0x00001000,       // Restrict interaction to party or raid
		UNIT_FLAG2_PREVENT_SPELL_CLICK          = 0x00002000,       // Prevent spellclick
		UNIT_FLAG2_ALLOW_ENEMY_INTERACT         = 0x00004000,
		UNIT_FLAG2_CANNOT_TURN                  = 0x00008000,
		UNIT_FLAG2_UNK2                         = 0x00010000,
		UNIT_FLAG2_PLAY_DEATH_ANIM              = 0x00020000,       // Plays special death animation upon death
		UNIT_FLAG2_ALLOW_CHEAT_SPELLS           = 0x00040000,       // Allows casting spells with AttributesEx7 & SPELL_ATTR7_DEBUG_SPELL
		UNIT_FLAG2_UNUSED_6                     = 0x01000000,
	}
}
export {};
