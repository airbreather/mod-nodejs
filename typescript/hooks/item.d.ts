declare global {
	interface GlobalHooks {
		['item:can-quest-accept']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly quest: Acore.Quest;
			readonly __return: Acore.Box<boolean>;
		};
		['item:can-use']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			// readonly targets: Acore.SpellCastTargets;
			readonly __return: Acore.Box<boolean>;
		};
		['item:can-remove']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly __return: Acore.Box<boolean>;
		};
		['item:can-expire']: {
			readonly player: Acore.Player;
			readonly proto: Acore.ItemTemplateNarrowable;
			readonly __return: Acore.Box<boolean>;
		};
		['item:gossip-select']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly sender: GossipSender;
			readonly action: GossipAction;
		};
		['item:gossip-select-code']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly sender: GossipSender;
			readonly action: GossipAction;
			readonly code: string;
		};
	}
}
export {};
