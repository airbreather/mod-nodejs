declare global {
	const enum ItemSubclassConsumable {
		ITEM_SUBCLASS_CONSUMABLE                    = 0,
		ITEM_SUBCLASS_POTION                        = 1,
		ITEM_SUBCLASS_ELIXIR                        = 2,
		ITEM_SUBCLASS_FLASK                         = 3,
		ITEM_SUBCLASS_SCROLL                        = 4,
		ITEM_SUBCLASS_FOOD                          = 5,
		ITEM_SUBCLASS_ITEM_ENHANCEMENT              = 6,
		ITEM_SUBCLASS_BANDAGE                       = 7,
		ITEM_SUBCLASS_CONSUMABLE_OTHER              = 8,
	}
	// mod-nodejs invention
	const enum ItemSubclassMaskConsumable {
		ITEM_SUBCLASS_MASK_CONSUMABLE               = 1 << ItemSubclassConsumable.ITEM_SUBCLASS_CONSUMABLE,
		ITEM_SUBCLASS_MASK_POTION                   = 1 << ItemSubclassConsumable.ITEM_SUBCLASS_POTION,
		ITEM_SUBCLASS_MASK_ELIXIR                   = 1 << ItemSubclassConsumable.ITEM_SUBCLASS_ELIXIR,
		ITEM_SUBCLASS_MASK_FLASK                    = 1 << ItemSubclassConsumable.ITEM_SUBCLASS_FLASK,
		ITEM_SUBCLASS_MASK_SCROLL                   = 1 << ItemSubclassConsumable.ITEM_SUBCLASS_SCROLL,
		ITEM_SUBCLASS_MASK_FOOD                     = 1 << ItemSubclassConsumable.ITEM_SUBCLASS_FOOD,
		ITEM_SUBCLASS_MASK_ITEM_ENHANCEMENT         = 1 << ItemSubclassConsumable.ITEM_SUBCLASS_ITEM_ENHANCEMENT,
		ITEM_SUBCLASS_MASK_BANDAGE                  = 1 << ItemSubclassConsumable.ITEM_SUBCLASS_BANDAGE,
		ITEM_SUBCLASS_MASK_CONSUMABLE_OTHER         = 1 << ItemSubclassConsumable.ITEM_SUBCLASS_CONSUMABLE_OTHER,
	}
}
export {};
