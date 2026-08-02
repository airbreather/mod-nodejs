declare global {
	const enum ItemSubclassKey {
		ITEM_SUBCLASS_KEY                           = 0,
		ITEM_SUBCLASS_LOCKPICK                      = 1,
	}
	// mod-nodejs invention
	const enum ItemSubclassMaskKey {
		ITEM_SUBCLASS_MASK_KEY                      = 1 << ItemSubclassKey.ITEM_SUBCLASS_KEY,
		ITEM_SUBCLASS_MASK_LOCKPICK                 = 1 << ItemSubclassKey.ITEM_SUBCLASS_LOCKPICK,
	}
}
export {};
