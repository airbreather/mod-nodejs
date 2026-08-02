declare global {
	const enum ItemSubclassReagent {
		ITEM_SUBCLASS_REAGENT                       = 0,
	}
	// mod-nodejs invention
	const enum ItemSubclassMaskReagent {
		ITEM_SUBCLASS_MASK_REAGENT                  = 1 << ItemSubclassReagent.ITEM_SUBCLASS_REAGENT,
	}
}
export {};
