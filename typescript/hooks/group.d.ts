declare global {
	interface Hooks {
		['group:add-member']: {
			readonly group: Acore.Group;
			readonly guid: ObjectGuidNative;
		};
		['group:invite-member']: {
			readonly group: Acore.Group;
			readonly guid: ObjectGuidNative;
		};
		['group:remove-member']: {
			readonly group: Acore.Group;
			readonly guid: ObjectGuidNative;
			readonly method: RemoveMethod;
			readonly kicker: ObjectGuidNative | undefined;
			readonly reason: string;
		};
		['group:change-leader']: {
			readonly group: Acore.Group;
			readonly newLeaderGuid: ObjectGuidNative;
			readonly oldLeaderGuid: ObjectGuidNative;
		};
		['group:disband']: { readonly group: Acore.Group; };
		['group:can-join-battleground-queue']: {
			readonly group: Acore.Group;
			readonly member: Acore.Player;
			readonly bgTemplate: Acore.Battleground;
			readonly minPlayerCount: number;
			readonly isRated: boolean;
			readonly arenaSlot: number; // TODO: is this actually ArenaType?
			__return: boolean;
		};
		['group:create']: {
			readonly group: Acore.Group;
			readonly leader: Acore.Player;
		};
	}
}
export {};
