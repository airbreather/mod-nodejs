declare global {
	const enum ItemSubclassGem {
		ITEM_SUBCLASS_GEM_RED                       = 0,
		ITEM_SUBCLASS_GEM_BLUE                      = 1,
		ITEM_SUBCLASS_GEM_YELLOW                    = 2,
		ITEM_SUBCLASS_GEM_PURPLE                    = 3,
		ITEM_SUBCLASS_GEM_GREEN                     = 4,
		ITEM_SUBCLASS_GEM_ORANGE                    = 5,
		ITEM_SUBCLASS_GEM_META                      = 6,
		ITEM_SUBCLASS_GEM_SIMPLE                    = 7,
		ITEM_SUBCLASS_GEM_PRISMATIC                 = 8,
	}
	// mod-nodejs invention
	const enum ItemSubclassMaskGem {
		ITEM_SUBCLASS_MASK_GEM_RED                  = 1 << ItemSubclassGem.ITEM_SUBCLASS_GEM_RED,
		ITEM_SUBCLASS_MASK_GEM_BLUE                 = 1 << ItemSubclassGem.ITEM_SUBCLASS_GEM_BLUE,
		ITEM_SUBCLASS_MASK_GEM_YELLOW               = 1 << ItemSubclassGem.ITEM_SUBCLASS_GEM_YELLOW,
		ITEM_SUBCLASS_MASK_GEM_PURPLE               = 1 << ItemSubclassGem.ITEM_SUBCLASS_GEM_PURPLE,
		ITEM_SUBCLASS_MASK_GEM_GREEN                = 1 << ItemSubclassGem.ITEM_SUBCLASS_GEM_GREEN,
		ITEM_SUBCLASS_MASK_GEM_ORANGE               = 1 << ItemSubclassGem.ITEM_SUBCLASS_GEM_ORANGE,
		ITEM_SUBCLASS_MASK_GEM_META                 = 1 << ItemSubclassGem.ITEM_SUBCLASS_GEM_META,
		ITEM_SUBCLASS_MASK_GEM_SIMPLE               = 1 << ItemSubclassGem.ITEM_SUBCLASS_GEM_SIMPLE,
		ITEM_SUBCLASS_MASK_GEM_PRISMATIC            = 1 << ItemSubclassGem.ITEM_SUBCLASS_GEM_PRISMATIC,
	}
}
export {};
