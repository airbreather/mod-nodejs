declare global {
	interface Hooks {
		['misc:item-create']: {
			readonly item: Acore.Item;
			readonly proto: Acore.ItemTemplateNarrowable;
			readonly owner: Acore.Player;
		};
		['misc:can-apply-soulbound-flag']: {
			readonly item: Acore.Item;
			readonly proto: Acore.ItemTemplateNarrowable;
			__return: boolean;
		};
		['misc:can-item-apply-equip-spell']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			__return: boolean;
		};
		['misc:can-send-auction-hello']: {
			readonly player: Acore.Player;
			readonly guid: bigint;
			readonly creature: Acore.Creature;
			__return: boolean;
		};
		['misc:validate-spell-at-cast-spell']: {
			readonly player: Acore.Player;
			oldSpellId: number;
			spellId: number;
			castCount: number;
			castFlags: number; // shrug. not clearly documented in a way I can tell
		};
		['misc:validate-spell-at-cast-spell-result']: {
			readonly player: Acore.Player;
			readonly mover: Acore.Unit;
			readonly spell: Acore.Spell;
			readonly oldSpellId: number;
			readonly spellId: number;
		};
		['misc:after-loot-template-process']: {
			readonly loot: Acore.Loot;
			readonly tab: Acore.LootTemplate;
			readonly store: Acore.LootStore;
			readonly lootOwner: Acore.Player;
			readonly personal: boolean;
			readonly noEmptyError: boolean;
			readonly lootMode: LootModes;
		};
		// ['misc:instance-save']: unknown; // the one arg has no translation right now.
		['misc:get-dialog-status']: {
			readonly player: Acore.Player;
			readonly questGiver: Acore.Creature | Acore.GameObject;
		};
	}
}
export {};
