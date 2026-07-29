declare global {
	interface ItemSpell {
		spellId: number;
		spellTrigger: ItemSpelltriggerType;
		spellCharges: number;
		spellPPMRate: number;
		spellCooldown: number;
		spellCategory: number;
		spellCategoryCooldown: number;
	}
}
export {};
