declare global {
	interface Hooks {
		['item:can-quest-accept']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly quest: Acore.Quest;
			__return: boolean;
		};
		['item:can-use']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			// readonly targets: Acore.SpellCastTargets;
			__return: boolean;
		};
		['item:can-remove']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			__return: boolean;
		};
		['item:can-expire']: {
			readonly player: Acore.Player;
			readonly proto: Acore.ItemTemplateNarrowable;
			__return: boolean;
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
