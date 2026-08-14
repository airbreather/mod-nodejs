declare global {
	const enum PlayerFlags {
		PLAYER_FLAGS_GROUP_LEADER      = 0x00000001,
		PLAYER_FLAGS_AFK               = 0x00000002,
		PLAYER_FLAGS_DND               = 0x00000004,
		PLAYER_FLAGS_GM                = 0x00000008,
		PLAYER_FLAGS_GHOST             = 0x00000010,
		PLAYER_FLAGS_RESTING           = 0x00000020,
		PLAYER_FLAGS_UNK6              = 0x00000040,
		PLAYER_FLAGS_UNK7              = 0x00000080,               // pre-3.0.3 PLAYER_FLAGS_FFA_PVP flag for FFA PVP state
		PLAYER_FLAGS_CONTESTED_PVP     = 0x00000100,               // Player has been involved in a PvP combat and will be attacked by contested guards
		PLAYER_FLAGS_IN_PVP            = 0x00000200,
		PLAYER_FLAGS_HIDE_HELM         = 0x00000400,
		PLAYER_FLAGS_HIDE_CLOAK        = 0x00000800,
		PLAYER_FLAGS_PARTIAL_PLAY_TIME = 0x00001000,               // played long time
		PLAYER_FLAGS_NO_PLAY_TIME      = 0x00002000,               // played too long time
		PLAYER_FLAGS_IS_OUT_OF_BOUNDS  = 0x00004000,
		PLAYER_FLAGS_DEVELOPER         = 0x00008000,               // <Dev> prefix for something?
		PLAYER_FLAGS_UNK16             = 0x00010000,               // pre-3.0.3 PLAYER_FLAGS_SANCTUARY flag for player entered sanctuary
		PLAYER_FLAGS_TAXI_BENCHMARK    = 0x00020000,               // taxi benchmark mode (on/off) (2.0.1)
		PLAYER_FLAGS_PVP_TIMER         = 0x00040000,               // 3.0.2, pvp timer active (after you disable pvp manually)
		PLAYER_FLAGS_UBER              = 0x00080000,
		PLAYER_FLAGS_UNK20             = 0x00100000,
		PLAYER_FLAGS_UNK21             = 0x00200000,
		PLAYER_FLAGS_COMMENTATOR2      = 0x00400000,
		PLAYER_ALLOW_ONLY_ABILITY      = 0x00800000,                // used by bladestorm and killing spree, allowed only spells with SPELL_ATTR0_USES_RANGED_SLOT, SPELL_EFFECT_ATTACK, checked only for active player
		PLAYER_FLAGS_UNK24             = 0x01000000,                // disabled all melee ability on tab include autoattack
		PLAYER_FLAGS_NO_XP_GAIN        = 0x02000000,
		PLAYER_FLAGS_UNK26             = 0x04000000,
		PLAYER_FLAGS_UNK27             = 0x08000000,
		PLAYER_FLAGS_UNK28             = 0x10000000,
		PLAYER_FLAGS_UNK29             = 0x20000000,
		PLAYER_FLAGS_UNK30             = 0x40000000,
		PLAYER_FLAGS_UNK31             = 0x80000000,
	}
}
export {};
