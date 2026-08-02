declare global {
	const enum SummonType {
		SUMMON_TYPE_NONE        = 0,
		SUMMON_TYPE_PET         = 1,
		SUMMON_TYPE_GUARDIAN    = 2,
		SUMMON_TYPE_MINION      = 3,
		SUMMON_TYPE_TOTEM       = 4,
		SUMMON_TYPE_MINIPET     = 5,
		SUMMON_TYPE_GUARDIAN2   = 6,
		SUMMON_TYPE_WILD2       = 7,
		SUMMON_TYPE_WILD3       = 8,    // Related to phases and DK prequest line (3.3.5a)
		SUMMON_TYPE_VEHICLE     = 9,
		SUMMON_TYPE_VEHICLE2    = 10,   // Oculus and Argent Tournament vehicles (3.3.5a)
		SUMMON_TYPE_LIGHTWELL   = 11,
		SUMMON_TYPE_JEEVES      = 12,
	}
}
export {};
