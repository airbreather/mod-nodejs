declare global {
	// mod-nodejs invention to make it easier to refer to one of the static values.
	const enum LootStoreType {
		LootTemplates_Creature =          0,
		LootTemplates_Disenchant =        1,
		LootTemplates_Fishing =           2,
		LootTemplates_Gameobject =        3,
		LootTemplates_Item =              4,
		LootTemplates_Mail =              5,
		LootTemplates_Milling =           6,
		LootTemplates_Pickpocketing =     7,
		LootTemplates_Prospecting =       8,
		LootTemplates_Reference =         9,
		LootTemplates_Skinning =         10,
		LootTemplates_Spell =            11,
		LootTemplates_Player =           12,
	}
}
export {};
