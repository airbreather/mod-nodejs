declare global {
	// SummonProperties.dbc, col 5
	const enum SummonPropFlags {
		SUMMON_PROP_FLAG_NONE                            = 0x00000000,          // 1342 spells in 3.0.3
		SUMMON_PROP_FLAG_ATTACK_SUMMONER                 = 0x00000001,          /// @todo: NYI 75 spells in 3.0.3, something unfriendly
		SUMMON_PROP_FLAG_ASSIST_COMBAT_SUMMON            = 0x00000002,          /// @todo: NYI 616 spells in 3.0.3, something friendly
		SUMMON_PROP_FLAG_USE_LEVEL_OFFSET                = 0x00000004,          /// @todo: NYI 22 spells in 3.0.3, no idea...
		SUMMON_PROP_FLAG_DESPAWN_ON_SUMMONER_DEATH       = 0x00000008,          /// @todo: NYI 49 spells in 3.0.3, some mounts
		SUMMON_PROP_FLAG_ONLY_VISIBLE_TO_SUMMONER        = 0x00000010,          // 25 spells in 3.0.3, quest related?
		SUMMON_PROP_FLAG_CANNOT_DISMISS_PET              = 0x00000020,          /// @todo: NYI 0 spells in 3.3.5, unused
		SUMMON_PROP_FLAG_USE_DEMON_TIMEOUT               = 0x00000040,          /// @todo: NYI 12 spells in 3.0.3, no idea
		SUMMON_PROP_FLAG_UNLIMITED_SUMMONS               = 0x00000080,          /// @todo: NYI 4 spells in 3.0.3, no idea
		SUMMON_PROP_FLAG_USE_CREATURE_LEVEL              = 0x00000100,          /// @todo: NYI 51 spells in 3.0.3, no idea, many quest related
		SUMMON_PROP_FLAG_JOIN_SUMMONER_SPAWN_GROUP       = 0x00000200,          /// @todo: NYI 51 spells in 3.0.3, something defensive
		SUMMON_PROP_FLAG_DO_NOT_TOGGLE                   = 0x00000400,          /// @todo: NYI 3 spells, requires something near?
		SUMMON_PROP_FLAG_DESPAWN_WHEN_EXPIRED            = 0x00000800,          /// @todo: NYI 30 spells in 3.0.3, no idea
		SUMMON_PROP_FLAG_USE_SUMMONER_FACTION            = 0x00001000,          /// Lightwell, Jeeves, Gnomish Alarm-o-bot, Build vehicles(wintergrasp)
		SUMMON_PROP_FLAG_DO_NOT_FOLLOW_MOUNTED_SUMMONER  = 0x00002000,          /// @todo: NYI Guides, player follows
		SUMMON_PROP_FLAG_SAVE_PET_AUTOCAST               = 0x00004000,          /// @todo: NYI Force of Nature, Shadowfiend, Feral Spirit, Summon Water Elemental
		SUMMON_PROP_FLAG_IGNORE_SUMMONER_PHASE           = 0x00008000,          /// @todo: NYI Light/Dark Bullet, Soul/Fiery Consumption, Twisted Visage, Twilight Whelp. Phase related?
	}
}
export {};
