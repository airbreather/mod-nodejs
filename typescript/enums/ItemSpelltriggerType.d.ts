declare global {
	const enum ItemSpelltriggerType {
		ITEM_SPELLTRIGGER_ON_USE          = 0,  // use after equip cooldown
		ITEM_SPELLTRIGGER_ON_EQUIP        = 1,
		ITEM_SPELLTRIGGER_CHANCE_ON_HIT   = 2,
		ITEM_SPELLTRIGGER_SOULSTONE       = 4,
		/*
		 * ItemSpelltriggerType 5 might have changed on 2.4.3/3.0.3: Such auras
		 * will be applied on item pickup and removed on item loss - maybe on the
		 * other hand the item is destroyed if the aura is removed ("removed on
		 * death" of spell 57348 makes me think so)
		 */
		ITEM_SPELLTRIGGER_ON_NO_DELAY_USE = 5,  // no equip cooldown
		ITEM_SPELLTRIGGER_LEARN_SPELL_ID  = 6,  // used in item_template.spell_2 with spell_id with SPELL_GENERIC_LEARN in spell_1
	}
}
export {};
