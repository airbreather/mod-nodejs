declare global {
	const enum SummonCategory {
		SUMMON_CATEGORY_WILD        = 0,
		SUMMON_CATEGORY_ALLY        = 1,
		SUMMON_CATEGORY_PET         = 2,
		SUMMON_CATEGORY_PUPPET      = 3,
		SUMMON_CATEGORY_VEHICLE     = 4,
		SUMMON_CATEGORY_UNK         = 5, // as of patch 3.3.5a only Bone Spike in Icecrown Citadel
		// uses this category
	}
}
export {};
