declare global {
	const enum ItemFlags {
		ITEM_FLAG_NO_PICKUP                         = 0x00000001,
		ITEM_FLAG_CONJURED                          = 0x00000002, // Conjured item
		ITEM_FLAG_HAS_LOOT                          = 0x00000004, // Item can be right clicked to open for loot
		ITEM_FLAG_HEROIC_TOOLTIP                    = 0x00000008, // Makes green "Heroic" text appear on item
		ITEM_FLAG_DEPRECATED                        = 0x00000010, // Cannot equip or use
		ITEM_FLAG_NO_USER_DESTROY                   = 0x00000020, // Item can not be destroyed, except by using spell (item can be reagent for spell)
		ITEM_FLAG_PLAYERCAST                        = 0x00000040, // Item's spells are castable by players
		ITEM_FLAG_NO_EQUIP_COOLDOWN                 = 0x00000080, // No default 30 seconds cooldown when equipped
		ITEM_FLAG_MULTI_LOOT_QUEST                  = 0x00000100, // NYI
		ITEM_FLAG_IS_WRAPPER                        = 0x00000200, // Item can wrap other items
		ITEM_FLAG_USES_RESOURCES                    = 0x00000400, // NYI
		ITEM_FLAG_MULTI_DROP                        = 0x00000800, // Looting this item does not remove it from available loot
		ITEM_FLAG_ITEM_PURCHASE_RECORD              = 0x00001000, // Item can be returned to vendor for its original cost (extended cost)
		ITEM_FLAG_PETITION                          = 0x00002000, // Item is guild or arena charter
		ITEM_FLAG_HAS_TEXT                          = 0x00004000, // Only readable items have this (but not all)
		ITEM_FLAG_NO_DISENCHANT                     = 0x00008000, // NYI
		ITEM_FLAG_REAL_DURATION                     = 0x00010000, // NYI
		ITEM_FLAG_NO_CREATOR                        = 0x00020000,
		ITEM_FLAG_IS_PROSPECTABLE                   = 0x00040000, // Item can be prospected
		ITEM_FLAG_UNIQUE_EQUIPPABLE                 = 0x00080000, // You can only equip one of these
		ITEM_FLAG_IGNORE_FOR_AURAS                  = 0x00100000, // NYI
		ITEM_FLAG_IGNORE_DEFAULT_ARENA_RESTRICTIONS = 0x00200000, // Item can be used during arena match
		ITEM_FLAG_NO_DURABILITY_LOSS                = 0x00400000, // Some Thrown weapons have it (and only Thrown) but not all
		ITEM_FLAG_USE_WHEN_SHAPESHIFTED             = 0x00800000, // Item can be used in shapeshift forms
		ITEM_FLAG_HAS_QUEST_GLOW                    = 0x01000000, // NYI
		ITEM_FLAG_HIDE_UNUSABLE_RECIPE              = 0x02000000, // Profession recipes: can only be looted if you meet requirements and don't already know it
		ITEM_FLAG_NOT_USEABLE_IN_ARENA              = 0x04000000, // Item cannot be used in arena
		ITEM_FLAG_IS_BOUND_TO_ACCOUNT               = 0x08000000, // Item binds to account and can be sent only to your own characters
		ITEM_FLAG_NO_REAGENT_COST                   = 0x10000000, // Spell is cast ignoring reagents
		ITEM_FLAG_IS_MILLABLE                       = 0x20000000, // Item can be milled
		ITEM_FLAG_REPORT_TO_GUILD_CHAT              = 0x40000000, // NYI
		ITEM_FLAG_NO_PROGRESSIVE_LOOT               = 0x80000000, // NYI
	}
}
export {};
