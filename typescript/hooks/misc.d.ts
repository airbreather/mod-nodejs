declare global {
	interface GlobalHooks {
		['misc:item-create']: {
			readonly item: Acore.Item;
			readonly proto: Acore.ItemTemplateNarrowable;
			readonly owner: Acore.Player;
		};
		['misc:can-apply-soulbound-flag']: {
			readonly item: Acore.Item;
			readonly proto: Acore.ItemTemplateNarrowable;
			readonly __return: Acore.Box<boolean>;
		};
		['misc:can-item-apply-equip-spell']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly __return: Acore.Box<boolean>;
		};
		['misc:can-send-auction-hello']: {
			readonly player: Acore.Player;
			readonly guid: bigint;
			readonly creature: Acore.Creature;
			readonly __return: Acore.Box<boolean>;
		};
		['misc:validate-spell-at-cast-spell']: {
			readonly player: Acore.Player;
			readonly oldSpellId: Acore.Box<number>;
			readonly spellId: Acore.Box<number>;
			readonly castCount: Acore.Box<number>;
			readonly castFlags: Acore.Box<number>; // shrug. not clearly documented in a way I can tell
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
