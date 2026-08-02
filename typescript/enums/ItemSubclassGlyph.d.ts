declare global {
	const enum ItemSubclassGlyph {
		ITEM_SUBCLASS_GLYPH_WARRIOR                 = 1,
		ITEM_SUBCLASS_GLYPH_PALADIN                 = 2,
		ITEM_SUBCLASS_GLYPH_HUNTER                  = 3,
		ITEM_SUBCLASS_GLYPH_ROGUE                   = 4,
		ITEM_SUBCLASS_GLYPH_PRIEST                  = 5,
		ITEM_SUBCLASS_GLYPH_DEATH_KNIGHT            = 6,
		ITEM_SUBCLASS_GLYPH_SHAMAN                  = 7,
		ITEM_SUBCLASS_GLYPH_MAGE                    = 8,
		ITEM_SUBCLASS_GLYPH_WARLOCK                 = 9,
		ITEM_SUBCLASS_GLYPH_DRUID                   = 11,
	}
	// mod-nodejs invention
	const enum ItemSubclassMaskGlyph {
		ITEM_SUBCLASS_MASK_GLYPH_WARRIOR            = 1 << ItemSubclassGlyph.ITEM_SUBCLASS_GLYPH_WARRIOR,
		ITEM_SUBCLASS_MASK_GLYPH_PALADIN            = 1 << ItemSubclassGlyph.ITEM_SUBCLASS_GLYPH_PALADIN,
		ITEM_SUBCLASS_MASK_GLYPH_HUNTER             = 1 << ItemSubclassGlyph.ITEM_SUBCLASS_GLYPH_HUNTER,
		ITEM_SUBCLASS_MASK_GLYPH_ROGUE              = 1 << ItemSubclassGlyph.ITEM_SUBCLASS_GLYPH_ROGUE,
		ITEM_SUBCLASS_MASK_GLYPH_PRIEST             = 1 << ItemSubclassGlyph.ITEM_SUBCLASS_GLYPH_PRIEST,
		ITEM_SUBCLASS_MASK_GLYPH_DEATH_KNIGHT       = 1 << ItemSubclassGlyph.ITEM_SUBCLASS_GLYPH_DEATH_KNIGHT,
		ITEM_SUBCLASS_MASK_GLYPH_SHAMAN             = 1 << ItemSubclassGlyph.ITEM_SUBCLASS_GLYPH_SHAMAN,
		ITEM_SUBCLASS_MASK_GLYPH_MAGE               = 1 << ItemSubclassGlyph.ITEM_SUBCLASS_GLYPH_MAGE,
		ITEM_SUBCLASS_MASK_GLYPH_WARLOCK            = 1 << ItemSubclassGlyph.ITEM_SUBCLASS_GLYPH_WARLOCK,
		ITEM_SUBCLASS_MASK_GLYPH_DRUID              = 1 << ItemSubclassGlyph.ITEM_SUBCLASS_GLYPH_DRUID,
	}
}
export {};
