declare global {
	const enum ItemSubclassArmor {
		ITEM_SUBCLASS_ARMOR_MISC                    = 0,
		ITEM_SUBCLASS_ARMOR_CLOTH                   = 1,
		ITEM_SUBCLASS_ARMOR_LEATHER                 = 2,
		ITEM_SUBCLASS_ARMOR_MAIL                    = 3,
		ITEM_SUBCLASS_ARMOR_PLATE                   = 4,
		ITEM_SUBCLASS_ARMOR_BUCKLER                 = 5,
		ITEM_SUBCLASS_ARMOR_SHIELD                  = 6,
		ITEM_SUBCLASS_ARMOR_LIBRAM                  = 7,
		ITEM_SUBCLASS_ARMOR_IDOL                    = 8,
		ITEM_SUBCLASS_ARMOR_TOTEM                   = 9,
		ITEM_SUBCLASS_ARMOR_SIGIL                   = 10,
	}
	// mod-nodejs invention
	const enum ItemSubclassMaskArmor {
		ITEM_SUBCLASS_MASK_ARMOR_MISC               = 1 << ItemSubclassArmor.ITEM_SUBCLASS_ARMOR_MISC,
		ITEM_SUBCLASS_MASK_ARMOR_CLOTH              = 1 << ItemSubclassArmor.ITEM_SUBCLASS_ARMOR_CLOTH,
		ITEM_SUBCLASS_MASK_ARMOR_LEATHER            = 1 << ItemSubclassArmor.ITEM_SUBCLASS_ARMOR_LEATHER,
		ITEM_SUBCLASS_MASK_ARMOR_MAIL               = 1 << ItemSubclassArmor.ITEM_SUBCLASS_ARMOR_MAIL,
		ITEM_SUBCLASS_MASK_ARMOR_PLATE              = 1 << ItemSubclassArmor.ITEM_SUBCLASS_ARMOR_PLATE,
		ITEM_SUBCLASS_MASK_ARMOR_BUCKLER            = 1 << ItemSubclassArmor.ITEM_SUBCLASS_ARMOR_BUCKLER,
		ITEM_SUBCLASS_MASK_ARMOR_SHIELD             = 1 << ItemSubclassArmor.ITEM_SUBCLASS_ARMOR_SHIELD,
		ITEM_SUBCLASS_MASK_ARMOR_LIBRAM             = 1 << ItemSubclassArmor.ITEM_SUBCLASS_ARMOR_LIBRAM,
		ITEM_SUBCLASS_MASK_ARMOR_IDOL               = 1 << ItemSubclassArmor.ITEM_SUBCLASS_ARMOR_IDOL,
		ITEM_SUBCLASS_MASK_ARMOR_TOTEM              = 1 << ItemSubclassArmor.ITEM_SUBCLASS_ARMOR_TOTEM,
		ITEM_SUBCLASS_MASK_ARMOR_SIGIL              = 1 << ItemSubclassArmor.ITEM_SUBCLASS_ARMOR_SIGIL,
	}
}
export {};
