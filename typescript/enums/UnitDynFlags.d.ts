declare global {
	const enum UnitDynFlags {
		UNIT_DYNFLAG_NONE                       = 0x0000,
		UNIT_DYNFLAG_LOOTABLE                   = 0x0001,
		UNIT_DYNFLAG_TRACK_UNIT                 = 0x0002,
		UNIT_DYNFLAG_TAPPED                     = 0x0004,       // Lua_UnitIsTapped
		UNIT_DYNFLAG_TAPPED_BY_PLAYER           = 0x0008,       // Lua_UnitIsTappedByPlayer
		UNIT_DYNFLAG_SPECIALINFO                = 0x0010,
		UNIT_DYNFLAG_DEAD                       = 0x0020,
		UNIT_DYNFLAG_REFER_A_FRIEND             = 0x0040,
		UNIT_DYNFLAG_TAPPED_BY_ALL_THREAT_LIST  = 0x0080,       // Lua_UnitIsTappedByAllThreatList
	}
}
export {};
