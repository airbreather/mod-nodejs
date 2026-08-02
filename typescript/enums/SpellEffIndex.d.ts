declare global {
	const enum SpellEffIndex {
		EFFECT_0 = 0,
		EFFECT_1 = 1,
		EFFECT_2 = 2,
	}
	// mod-nodejs invention -- I wasn't going to bother with this file until the mask idea came up.
	const enum SpellEffIndexMask {
		EFFECT_MASK_0 = 1 << SpellEffIndex.EFFECT_0,
		EFFECT_MASK_1 = 1 << SpellEffIndex.EFFECT_1,
		EFFECT_MASK_2 = 1 << SpellEffIndex.EFFECT_2,
	}
}
export {};
