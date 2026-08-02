declare global {
	interface Hooks {
		['creature:update']: {
			readonly creature: Acore.Creature;
			readonly diff: Temporal.Duration;
		};
		['creature:before-select-level']: {
			readonly cInfo: Acore.CreatureTemplate;
			readonly creature: Acore.Creature;
			level: number;
		};
		['creature:select-level']: {
			readonly cInfo: Acore.CreatureTemplate;
			readonly creature: Acore.Creature;
		};
		['creature:add-world']: { readonly creature: Acore.Creature; };
		['creature:remove-world']: { readonly creature: Acore.Creature; };
		['creature:save-to-db']: { readonly creature: Acore.Creature; };
		['creature:can-gossip-hello']: {
			readonly player: Acore.Player;
			readonly creature: Acore.Creature;
			__return: boolean;
		};
		['creature:can-gossip-select']: {
			readonly player: Acore.Player;
			readonly creature: Acore.Creature;
			readonly sender: GossipSender;
			readonly action: GossipAction;
			__return: boolean;
		};
		['creature:can-gossip-select-code']: {
			readonly player: Acore.Player;
			readonly creature: Acore.Creature;
			readonly sender: GossipSender;
			readonly action: GossipAction;
			readonly code: string;
			__return: boolean;
		};
		['creature:can-quest-accept']: {
			readonly player: Acore.Player;
			readonly creature: Acore.Creature;
			readonly quest: Acore.Quest;
			__return: boolean;
		};
		['creature:can-quest-reward']: {
			readonly player: Acore.Player;
			readonly creature: Acore.Creature;
			readonly quest: Acore.Quest;
			readonly opt: number;
			__return: boolean;
		};
		['creature:ffa-pvp-state-update']: {
			readonly creature: Acore.Creature;
			readonly inPvp: boolean;
		};
	}
}
export {};
