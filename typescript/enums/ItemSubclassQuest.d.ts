declare global {
	const enum ItemSubclassQuest {
		ITEM_SUBCLASS_QUEST                         = 0,
	}
	// mod-nodejs invention
	const enum ItemSubclassMaskQuest {
		ITEM_SUBCLASS_MASK_QUEST                    = 1 << ItemSubclassQuest.ITEM_SUBCLASS_QUEST,
	}
}
export {};
