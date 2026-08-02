declare global {
	const enum ItemSubclassJunk {
		ITEM_SUBCLASS_JUNK                          = 0,
		ITEM_SUBCLASS_JUNK_REAGENT                  = 1,
		ITEM_SUBCLASS_JUNK_PET                      = 2,
		ITEM_SUBCLASS_JUNK_HOLIDAY                  = 3,
		ITEM_SUBCLASS_JUNK_OTHER                    = 4,
		ITEM_SUBCLASS_JUNK_MOUNT                    = 5,
	}
	// mod-nodejs invention
	const enum ItemSubclassMaskJunk {
		ITEM_SUBCLASS_MASK_JUNK                     = 1 << ItemSubclassJunk.ITEM_SUBCLASS_JUNK,
		ITEM_SUBCLASS_MASK_JUNK_REAGENT             = 1 << ItemSubclassJunk.ITEM_SUBCLASS_JUNK_REAGENT,
		ITEM_SUBCLASS_MASK_JUNK_PET                 = 1 << ItemSubclassJunk.ITEM_SUBCLASS_JUNK_PET,
		ITEM_SUBCLASS_MASK_JUNK_HOLIDAY             = 1 << ItemSubclassJunk.ITEM_SUBCLASS_JUNK_HOLIDAY,
		ITEM_SUBCLASS_MASK_JUNK_OTHER               = 1 << ItemSubclassJunk.ITEM_SUBCLASS_JUNK_OTHER,
		ITEM_SUBCLASS_MASK_JUNK_MOUNT               = 1 << ItemSubclassJunk.ITEM_SUBCLASS_JUNK_MOUNT,
	}
}
export {};
