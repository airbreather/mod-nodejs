declare global {
	const enum SpellInterruptFlags {
		SPELL_INTERRUPT_FLAG_MOVEMENT     = 0x01, // why need this for instant?
		SPELL_INTERRUPT_FLAG_PUSH_BACK    = 0x02, // push back
		SPELL_INTERRUPT_FLAG_UNK3         = 0x04, // any info?
		SPELL_INTERRUPT_FLAG_INTERRUPT    = 0x08, // interrupt
		SPELL_INTERRUPT_FLAG_ABORT_ON_DMG = 0x10,               // _complete_ interrupt on direct damage
		SPELL_INTERRUPT_UNK               = 0x20,               // unk, 564 of 727 spells having this spell start with "Glyph"
	}
}
export {};
