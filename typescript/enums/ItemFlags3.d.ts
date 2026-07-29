declare global {
	const enum ItemFlags3 {
		ITEM_FLAGS_CU_DURATION_REAL_TIME    = 0x0001,   // Item duration will tick even if player is offline
		ITEM_FLAGS_CU_IGNORE_QUEST_STATUS   = 0x0002,   // No quest status will be checked when this item drops
		ITEM_FLAGS_CU_FOLLOW_LOOT_RULES     = 0x0004,   // Item will always follow group/master/need before greed looting rules
	}

	/**
	 * @deprecated Use ItemFlags3 - the author of mod-nodejs is inserting their opinion that
	 * this probably shouldn't have been given such an inconsistent name in C++.
	 */
	type ItemFlagsCustom = ItemFlags3;
}
export {};
