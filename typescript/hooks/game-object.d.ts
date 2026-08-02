declare global {
	interface Hooks {
		['game-object:add-world']: { readonly gameObject: Acore.GameObject; };
		['game-object:remove-world']: { readonly gameObject: Acore.GameObject; };
		['game-object:save-to-db']: { readonly gameObject: Acore.GameObject; };
		['game-object:update']: {
			readonly gameObject: Acore.GameObject;
			readonly diff: Temporal.Duration;
		};
		['game-object:can-gossip-hello']: {
			readonly player: Acore.Player;
			readonly gameObject: Acore.GameObject;
			__return: boolean;
		};
		['game-object:can-gossip-select']: {
			readonly player: Acore.Player;
			readonly gameObject: Acore.GameObject;
			readonly sender: GossipSender;
			readonly action: GossipAction;
			__return: boolean;
		};
		['game-object:can-gossip-select-code']: {
			readonly player: Acore.Player;
			readonly gameObject: Acore.GameObject;
			readonly sender: GossipSender;
			readonly action: GossipAction;
			readonly code: string;
			__return: boolean;
		};
		['game-object:can-quest-accept']: {
			readonly player: Acore.Player;
			readonly gameObject: Acore.GameObject;
			readonly quest: Acore.Quest;
			__return: boolean;
		};
		['game-object:can-quest-reward']: {
			readonly player: Acore.Player;
			readonly gameObject: Acore.GameObject;
			readonly quest: Acore.Quest;
			readonly opt: number;
			__return: boolean;
		};
		['game-object:destroyed']: {
			readonly gameObject: Acore.GameObject;
			readonly player: Acore.Player;
		};
		['game-object:damaged']: {
			readonly gameObject: Acore.GameObject;
			readonly player: Acore.Player;
		};
		['game-object:modify-health']: {
			readonly gameObject: Acore.GameObject;
			readonly attackerOrHealer: Acore.Unit;
			change: number;
			readonly spellInfo: Acore.SpellInfo;
		};
		['game-object:loot-state-changed']: {
			readonly gameObject: Acore.GameObject;
			readonly state: LootState;
			readonly unit: Acore.Unit;
		};
		['game-object:state-changed']: {
			readonly gameObject: Acore.GameObject;
			readonly state: GOState;
		};
	}
}
export {};
