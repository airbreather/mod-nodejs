declare global {
	const enum ItemSubclassTradeGoods {
		ITEM_SUBCLASS_TRADE_GOODS                   = 0,
		ITEM_SUBCLASS_PARTS                         = 1,
		ITEM_SUBCLASS_EXPLOSIVES                    = 2,
		ITEM_SUBCLASS_DEVICES                       = 3,
		ITEM_SUBCLASS_JEWELCRAFTING                 = 4,
		ITEM_SUBCLASS_CLOTH                         = 5,
		ITEM_SUBCLASS_LEATHER                       = 6,
		ITEM_SUBCLASS_METAL_STONE                   = 7,
		ITEM_SUBCLASS_MEAT                          = 8,
		ITEM_SUBCLASS_HERB                          = 9,
		ITEM_SUBCLASS_ELEMENTAL                     = 10,
		ITEM_SUBCLASS_TRADE_GOODS_OTHER             = 11,
		ITEM_SUBCLASS_ENCHANTING                    = 12,
		ITEM_SUBCLASS_MATERIAL                      = 13,
		ITEM_SUBCLASS_ARMOR_ENCHANTMENT             = 14,
		ITEM_SUBCLASS_WEAPON_ENCHANTMENT            = 15,
	}
	// mod-nodejs invention
	const enum ItemSubclassMaskTradeGoods {
		ITEM_SUBCLASS_MASK_TRADE_GOODS              = 1 << ItemSubclassTradeGoods.ITEM_SUBCLASS_TRADE_GOODS,
		ITEM_SUBCLASS_MASK_PARTS                    = 1 << ItemSubclassTradeGoods.ITEM_SUBCLASS_PARTS,
		ITEM_SUBCLASS_MASK_EXPLOSIVES               = 1 << ItemSubclassTradeGoods.ITEM_SUBCLASS_EXPLOSIVES,
		ITEM_SUBCLASS_MASK_DEVICES                  = 1 << ItemSubclassTradeGoods.ITEM_SUBCLASS_DEVICES,
		ITEM_SUBCLASS_MASK_JEWELCRAFTING            = 1 << ItemSubclassTradeGoods.ITEM_SUBCLASS_JEWELCRAFTING,
		ITEM_SUBCLASS_MASK_CLOTH                    = 1 << ItemSubclassTradeGoods.ITEM_SUBCLASS_CLOTH,
		ITEM_SUBCLASS_MASK_LEATHER                  = 1 << ItemSubclassTradeGoods.ITEM_SUBCLASS_LEATHER,
		ITEM_SUBCLASS_MASK_METAL_STONE              = 1 << ItemSubclassTradeGoods.ITEM_SUBCLASS_METAL_STONE,
		ITEM_SUBCLASS_MASK_MEAT                     = 1 << ItemSubclassTradeGoods.ITEM_SUBCLASS_MEAT,
		ITEM_SUBCLASS_MASK_HERB                     = 1 << ItemSubclassTradeGoods.ITEM_SUBCLASS_HERB,
		ITEM_SUBCLASS_MASK_ELEMENTAL                = 1 << ItemSubclassTradeGoods.ITEM_SUBCLASS_ELEMENTAL,
		ITEM_SUBCLASS_MASK_TRADE_GOODS_OTHER        = 1 << ItemSubclassTradeGoods.ITEM_SUBCLASS_TRADE_GOODS_OTHER,
		ITEM_SUBCLASS_MASK_ENCHANTING               = 1 << ItemSubclassTradeGoods.ITEM_SUBCLASS_ENCHANTING,
		ITEM_SUBCLASS_MASK_MATERIAL                 = 1 << ItemSubclassTradeGoods.ITEM_SUBCLASS_MATERIAL,
		ITEM_SUBCLASS_MASK_ARMOR_ENCHANTMENT        = 1 << ItemSubclassTradeGoods.ITEM_SUBCLASS_ARMOR_ENCHANTMENT,
		ITEM_SUBCLASS_MASK_WEAPON_ENCHANTMENT       = 1 << ItemSubclassTradeGoods.ITEM_SUBCLASS_WEAPON_ENCHANTMENT,
	}
}
export {};
