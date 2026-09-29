declare global {
	interface Hooks {
		['group:add-member']: {
			group: Acore.Group;
			guid: bigint;
		};
		['group:invite-member']: {
			group: Acore.Group;
			guid: bigint;
		};
		['group:remove-member']: {
			group: Acore.Group;
			guid: bigint;
			method: RemoveMethod;
			kicker: bigint | undefined;
			reason: string;
		};
		['group:change-leader']: {
			group: Acore.Group;
			newLeaderGuid: bigint;
			oldLeaderGuid: bigint;
		};
		['group:disband']: { group: Acore.Group; };
		['group:can-join-battleground-queue']: {
			group: Acore.Group;
			member: Acore.Player;
			bgTemplate: Acore.Battleground;
			minPlayerCount: number;
			isRated: boolean;
			arenaSlot: number; // TODO: is this actually ArenaType?
			__return: Acore.Box<boolean>;
		};
		['group:create']: {
			group: Acore.Group;
			leader: Acore.Player;
		};
	}
}
export {};
