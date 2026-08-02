declare global {
	const enum ItemSubclassMoney {
		ITEM_SUBCLASS_MONEY                         = 0,
	}
	// mod-nodejs invention
	const enum ItemSubclassMaskMoney {
		ITEM_SUBCLASS_MASK_MONEY                    = 1 << ItemSubclassMoney.ITEM_SUBCLASS_MONEY,
	}
}
export {};
