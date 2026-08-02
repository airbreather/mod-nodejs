declare global {
	const enum ItemSubclassGeneric {
		ITEM_SUBCLASS_GENERIC                       = 0,
	}
	// mod-nodejs invention
	const enum ItemSubclassMaskGeneric {
		ITEM_SUBCLASS_MASK_GENERIC                  = 1 << ItemSubclassGeneric.ITEM_SUBCLASS_GENERIC,
	}
}
export {};
