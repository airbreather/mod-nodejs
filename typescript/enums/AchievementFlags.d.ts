declare global {
	const enum AchievementFlags {
		ACHIEVEMENT_FLAG_COUNTER           = 0x00000001,        // Just count statistic (never stop and complete)
		ACHIEVEMENT_FLAG_HIDDEN            = 0x00000002,        // Not sent to client - internal use only
		ACHIEVEMENT_FLAG_STORE_MAX_VALUE   = 0x00000004,        // Store only max value? used only in "Reach level xx"
		ACHIEVEMENT_FLAG_SUMM              = 0x00000008,        // Use summ criteria value from all reqirements (and calculate max value)
		ACHIEVEMENT_FLAG_MAX_USED          = 0x00000010,        // Show max criteria (and calculate max value ??)
		ACHIEVEMENT_FLAG_REQ_COUNT         = 0x00000020,        // Use not zero req count (and calculate max value)
		ACHIEVEMENT_FLAG_AVERAGE           = 0x00000040,        // Show as average value (value / time_in_days) depend from other flag (by def use last criteria value)
		ACHIEVEMENT_FLAG_BAR               = 0x00000080,        // Show as progress bar (value / max vale) depend from other flag (by def use last criteria value)
		ACHIEVEMENT_FLAG_REALM_FIRST_REACH = 0x00000100,        //
		ACHIEVEMENT_FLAG_REALM_FIRST_KILL  = 0x00000200,        //
	}
}
export {};
