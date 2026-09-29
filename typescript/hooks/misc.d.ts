declare global {
	interface Hooks {
		['misc:item-create']: {
			item: Acore.Item;
			proto: Acore.ItemTemplateNarrowable;
			owner: Acore.Player;
		};
		['misc:can-apply-soulbound-flag']: {
			item: Acore.Item;
			proto: Acore.ItemTemplateNarrowable;
			__return: Acore.Box<boolean>;
		};
		['misc:can-item-apply-equip-spell']: {
			player: Acore.Player;
			item: Acore.Item;
			__return: Acore.Box<boolean>;
		};
		['misc:can-send-auction-hello']: {
			player: Acore.Player;
			guid: bigint;
			creature: Acore.Creature;
			__return: Acore.Box<boolean>;
		};
		['misc:validate-spell-at-cast-spell']: {
			player: Acore.Player;
			oldSpellId: Acore.Box<number>;
			spellId: Acore.Box<number>;
			castCount: Acore.Box<number>;
			castFlags: Acore.Box<number>; // shrug. not clearly documented in a way I can tell
		};
		['misc:validate-spell-at-cast-spell-result']: {
			player: Acore.Player;
			mover: Acore.Unit;
			spell: Acore.Spell;
			oldSpellId: number;
			spellId: number;
		};
		['misc:after-loot-template-process']: {
			loot: Acore.Loot;
			tab: Acore.LootTemplate;
			store: Acore.LootStore;
			lootOwner: Acore.Player;
			personal: boolean;
			noEmptyError: boolean;
			lootMode: LootModes;
		};
		// ['misc:instance-save']: unknown; // the one arg has no translation right now.
		['misc:get-dialog-status']: {
			player: Acore.Player;
			questGiver: Acore.Creature | Acore.GameObject;
		};
	}
}
export {};
