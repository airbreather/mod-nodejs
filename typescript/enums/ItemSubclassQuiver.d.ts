declare global {
	const enum ItemSubclassQuiver {
		ITEM_SUBCLASS_QUIVER0                       = 0,        // ABS
		ITEM_SUBCLASS_QUIVER1                       = 1,        // ABS
		ITEM_SUBCLASS_QUIVER                        = 2,
		ITEM_SUBCLASS_AMMO_POUCH                    = 3,
	}
	// mod-nodejs invention
	const enum ItemSubclassMaskQuiver {
		ITEM_SUBCLASS_MASK_QUIVER0                  = 1 << ItemSubclassQuiver.ITEM_SUBCLASS_QUIVER0,
		ITEM_SUBCLASS_MASK_QUIVER1                  = 1 << ItemSubclassQuiver.ITEM_SUBCLASS_QUIVER1,
		ITEM_SUBCLASS_MASK_QUIVER                   = 1 << ItemSubclassQuiver.ITEM_SUBCLASS_QUIVER,
		ITEM_SUBCLASS_MASK_AMMO_POUCH               = 1 << ItemSubclassQuiver.ITEM_SUBCLASS_AMMO_POUCH,
	}
}
export {};
