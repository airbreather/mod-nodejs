declare global {
	interface Hooks {
		['game-object:add-world']: { gameObject: Acore.GameObject; };
		['game-object:remove-world']: { gameObject: Acore.GameObject; };
		['game-object:save-to-db']: { gameObject: Acore.GameObject; };
		['game-object:update']: {
			gameObject: Acore.GameObject;
			diff: Temporal.Duration;
		};
		['game-object:can-gossip-hello']: {
			player: Acore.Player;
			gameObject: Acore.GameObject;
			__return: Acore.Box<boolean>;
		};
		['game-object:can-gossip-select']: {
			player: Acore.Player;
			gameObject: Acore.GameObject;
			sender: GossipSender;
			action: number;
			__return: Acore.Box<boolean>;
		};
		['game-object:can-gossip-select-code']: {
			player: Acore.Player;
			gameObject: Acore.GameObject;
			sender: GossipSender;
			action: number;
			code: string;
			__return: Acore.Box<boolean>;
		};
		['game-object:can-quest-accept']: {
			player: Acore.Player;
			gameObject: Acore.GameObject;
			quest: Acore.Quest;
			__return: Acore.Box<boolean>;
		};
		['game-object:can-quest-reward']: {
			player: Acore.Player;
			gameObject: Acore.GameObject;
			quest: Acore.Quest;
			opt: number;
			__return: Acore.Box<boolean>;
		};
		['game-object:destroyed']: {
			gameObject: Acore.GameObject;
			player: Acore.Player;
		};
		['game-object:damaged']: {
			gameObject: Acore.GameObject;
			player: Acore.Player;
		};
		['game-object:modify-health']: {
			gameObject: Acore.GameObject;
			attackerOrHealer: Acore.Unit;
			change: Acore.Box<number>;
			spellInfo: Acore.SpellInfo;
		};
		['game-object:loot-state-changed']: {
			gameObject: Acore.GameObject;
			state: LootState;
			unit: Acore.Unit;
		};
		['game-object:state-changed']: {
			gameObject: Acore.GameObject;
			state: GOState;
		};
	}
}
export {};
