declare global {
	interface ItemSpell {
		spellId: number;
		spellTrigger: ItemSpelltriggerType;
		spellCharges: number;
		spellPPMRate: number;
		spellCooldown: Temporal.Duration;
		spellCategory: number;
		spellCategoryCooldown: Temporal.Duration;
	}
}
export {};
