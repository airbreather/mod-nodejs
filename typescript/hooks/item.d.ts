declare global {
	interface Hooks {
		['item:can-quest-accept']: {
			player: Acore.Player;
			item: Acore.Item;
			quest: Acore.Quest;
			__return: Acore.Box<boolean>;
		};
		['item:can-use']: {
			player: Acore.Player;
			item: Acore.Item;
			// targets: Acore.SpellCastTargets;
			__return: Acore.Box<boolean>;
		};
		['item:can-remove']: {
			player: Acore.Player;
			item: Acore.Item;
			__return: Acore.Box<boolean>;
		};
		['item:can-expire']: {
			player: Acore.Player;
			proto: Acore.ItemTemplateNarrowable;
			__return: Acore.Box<boolean>;
		};
		['item:gossip-select']: {
			player: Acore.Player;
			item: Acore.Item;
			sender: GossipSender;
			action: number;
		};
		['item:gossip-select-code']: {
			player: Acore.Player;
			item: Acore.Item;
			sender: GossipSender;
			action: number;
			code: string;
		};
	}
}
export {};
