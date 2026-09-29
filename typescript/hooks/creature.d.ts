declare global {
	interface Hooks {
		['creature:update']: {
			creature: Acore.Creature;
			diff: Temporal.Duration;
		};
		['creature:before-select-level']: {
			cInfo: Acore.CreatureTemplate;
			creature: Acore.Creature;
			level: Acore.Box<number>;
		};
		['creature:select-level']: {
			cInfo: Acore.CreatureTemplate;
			creature: Acore.Creature;
		};
		['creature:add-world']: { creature: Acore.Creature; };
		['creature:remove-world']: { creature: Acore.Creature; };
		['creature:save-to-db']: { creature: Acore.Creature; };
		['creature:can-gossip-hello']: {
			player: Acore.Player;
			creature: Acore.Creature;
			__return: Acore.Box<boolean>;
		};
		['creature:can-gossip-select']: {
			player: Acore.Player;
			creature: Acore.Creature;
			sender: GossipSender;
			action: number;
			__return: Acore.Box<boolean>;
		};
		['creature:can-gossip-select-code']: {
			player: Acore.Player;
			creature: Acore.Creature;
			sender: GossipSender;
			action: number;
			code: string;
			__return: Acore.Box<boolean>;
		};
		['creature:can-quest-accept']: {
			player: Acore.Player;
			creature: Acore.Creature;
			quest: Acore.Quest;
			__return: Acore.Box<boolean>;
		};
		['creature:can-quest-reward']: {
			player: Acore.Player;
			creature: Acore.Creature;
			quest: Acore.Quest;
			opt: number;
			__return: Acore.Box<boolean>;
		};
		['creature:ffa-pvp-state-update']: {
			creature: Acore.Creature;
			inPvp: boolean;
		};
	}
}
export {};
