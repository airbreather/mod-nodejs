declare global {
	const enum ItemFlags2 {
		ITEM_FLAG2_FACTION_HORDE                            = 0x00000001, // Only Horde can equip, loot, or buy back this item
		ITEM_FLAG2_FACTION_ALLIANCE                         = 0x00000002, // Only Alliance can equip, loot, or buy back this item
		ITEM_FLAG2_DONT_IGNORE_BUY_PRICE                    = 0x00000004, // when item uses extended cost, gold is also required
		ITEM_FLAG2_CLASSIFY_AS_CASTER                       = 0x00000008, // NYI - unused
		ITEM_FLAG2_CLASSIFY_AS_PHYSICAL                     = 0x00000010, // NYI
		ITEM_FLAG2_EVERYONE_CAN_ROLL_NEED                   = 0x00000020, // Anyone can roll need
		ITEM_FLAG2_NO_TRADE_BIND_ON_ACQUIRE                 = 0x00000040, // NYI - unused
		ITEM_FLAG2_CAN_TRADE_BIND_ON_ACQUIRE                = 0x00000080, // NYI - unused
		ITEM_FLAG2_CAN_ONLY_ROLL_GREED                      = 0x00000100, // Need rolls disallowed, only Greed / Disenchant / Pass
		ITEM_FLAG2_CASTER_WEAPON                            = 0x00000200, // NYI
		ITEM_FLAG2_DELETE_ON_LOGIN                          = 0x00000400, // NYI - unused
		ITEM_FLAG2_INTERNAL_ITEM                            = 0x00000800, // NYI - unused
		ITEM_FLAG2_NO_VENDOR_VALUE                          = 0x00001000, // NYI - unused
		ITEM_FLAG2_SHOW_BEFORE_DISCOVERED                   = 0x00002000, // NYI
		ITEM_FLAG2_OVERRIDE_GOLD_COST                       = 0x00004000, // NYI - unused
		ITEM_FLAG2_IGNORE_DEFAULT_RATED_BG_RESTRICTIONS     = 0x00008000, // NYI
		ITEM_FLAG2_NOT_USABLE_IN_RATED_BG                   = 0x00010000, // NYI
		ITEM_FLAG2_BNET_ACCOUNT_TRADE_OK                    = 0x00020000, // NYI
		ITEM_FLAG2_CONFIRM_BEFORE_USE                       = 0x00040000, // NYI - unused
		ITEM_FLAG2_REEVALUATE_BONDING_ON_TRANSFORM          = 0x00080000, // NYI - unused
		ITEM_FLAG2_NO_TRANSFORM_ON_CHARGE_DEPLETION         = 0x00100000, // NYI - unused
		ITEM_FLAG2_NO_ALTER_ITEM_VISUAL                     = 0x00200000, // NYI
		ITEM_FLAG2_NO_SOURCE_FOR_ITEM_VISUAL                = 0x00400000, // NYI
		ITEM_FLAG2_IGNORE_QUALITY_FOR_ITEM_VISUAL_SOURCE    = 0x00800000, // NYI - unused
		ITEM_FLAG2_NO_DURABILITY                            = 0x01000000, // NYI - unused
		ITEM_FLAG2_ROLE_TANK                                = 0x02000000, // NYI - unused
		ITEM_FLAG2_ROLE_HEALER                              = 0x04000000, // NYI - unused
		ITEM_FLAG2_ROLE_DAMAGE                              = 0x08000000, // NYI - unused
		ITEM_FLAG2_CAN_DROP_IN_CHALLENGE_MODE               = 0x10000000, // NYI - unused
		ITEM_FLAG2_NEVER_STACK_IN_LOOT_UI                   = 0x20000000, // NYI - unused
		ITEM_FLAG2_DISENCHANT_TO_LOOT_TABLE                 = 0x40000000, // NYI - unused
		ITEM_FLAG2_USED_IN_A_TRADESKILL                     = 0x80000000, // NYI - unused
	}
}
export {};
