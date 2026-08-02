declare global {
	const enum TeleportToOptions {
		TELE_TO_GM_MODE             = 0x01,
		TELE_TO_NOT_LEAVE_TRANSPORT = 0x02,
		TELE_TO_NOT_LEAVE_COMBAT    = 0x04,
		TELE_TO_NOT_UNSUMMON_PET    = 0x08,
		TELE_TO_SPELL               = 0x10,
		TELE_TO_NOT_LEAVE_VEHICLE   = 0x20,
		TELE_TO_WITH_PET            = 0x40,
		TELE_TO_NOT_LEAVE_TAXI      = 0x80,
	}
}
export {};
