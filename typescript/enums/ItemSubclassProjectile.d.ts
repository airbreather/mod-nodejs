declare global {
	const enum ItemSubclassProjectile {
		ITEM_SUBCLASS_WAND                          = 0,        // ABS
		ITEM_SUBCLASS_BOLT                          = 1,        // ABS
		ITEM_SUBCLASS_ARROW                         = 2,
		ITEM_SUBCLASS_BULLET                        = 3,
		ITEM_SUBCLASS_THROWN                        = 4,        // ABS
	}
	// mod-nodejs invention
	const enum ItemSubclassMaskProjectile {
		ITEM_SUBCLASS_MASK_WAND                     = 1 << ItemSubclassProjectile.ITEM_SUBCLASS_WAND,
		ITEM_SUBCLASS_MASK_BOLT                     = 1 << ItemSubclassProjectile.ITEM_SUBCLASS_BOLT,
		ITEM_SUBCLASS_MASK_ARROW                    = 1 << ItemSubclassProjectile.ITEM_SUBCLASS_ARROW,
		ITEM_SUBCLASS_MASK_BULLET                   = 1 << ItemSubclassProjectile.ITEM_SUBCLASS_BULLET,
		ITEM_SUBCLASS_MASK_THROWN                   = 1 << ItemSubclassProjectile.ITEM_SUBCLASS_THROWN,
	}
}
export {};
