declare global {
	const enum ItemSubclassPermanent {
		ITEM_SUBCLASS_PERMANENT                     = 0,
	}
	// mod-nodejs invention
	const enum ItemSubclassMaskPermanent {
		ITEM_SUBCLASS_MASK_PERMANENT                = 1 << ItemSubclassPermanent.ITEM_SUBCLASS_PERMANENT,
	}
}
export {};
