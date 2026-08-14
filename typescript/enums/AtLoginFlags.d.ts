declare global {
	const enum AtLoginFlags {
		AT_LOGIN_NONE              = 0x00,
		AT_LOGIN_RENAME            = 0x01,
		AT_LOGIN_RESET_SPELLS      = 0x02,
		AT_LOGIN_RESET_TALENTS     = 0x04,
		AT_LOGIN_CUSTOMIZE         = 0x08,
		AT_LOGIN_RESET_PET_TALENTS = 0x10,
		AT_LOGIN_FIRST             = 0x20,
		AT_LOGIN_CHANGE_FACTION    = 0x40,
		AT_LOGIN_CHANGE_RACE       = 0x80,
		AT_LOGIN_RESET_AP          = 0x100,
		AT_LOGIN_RESET_ARENA       = 0x200,
		AT_LOGIN_CHECK_ACHIEVS     = 0x400,
		AT_LOGIN_RESURRECT         = 0x800,
	}
}
export {};
