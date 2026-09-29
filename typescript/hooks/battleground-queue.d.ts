declare global {
	interface Hooks {
		['battleground-queue:update']: {
			queue: Acore.BattlegroundQueue;
			diff: Temporal.Duration;
			bgTypeId: BattlegroundTypeId;
			bracketId: number;
			arenaType: ArenaType;
			isRated: boolean;
			arenaRating: number;
		};
		['battleground-queue:update-validity']: {
			queue: Acore.BattlegroundQueue;
			diff: Temporal.Duration;
			bgTypeId: BattlegroundTypeId;
			bracketId: number;
			arenaType: ArenaType;
			isRated: boolean;
			arenaRating: number;
			__return: Acore.Box<boolean>;
		};
		['battleground-queue:add-group']: {
			queue: Acore.BattlegroundQueue;
			gInfo: GroupQueueInfo;
			index: Acore.Box<number>;
			leader: Acore.Player;
			group: Acore.Group;
			bgTypeId: BattlegroundTypeId;
			bracketEntry: Acore.PvPDifficultyEntry;
			arenaType: ArenaType;
			isRated: boolean;
			isPremade: boolean;
			arenaRating: number;
			matchmakerRating: number;
			arenaTeamId: number;
			opponentsArenaTeamId: number;
		};
		['battleground-queue:can-fill-players']: {
			queue: Acore.BattlegroundQueue;
			bg: Acore.Battleground;
			bracketId: number;
			__return: Acore.Box<boolean>;
		};
		['battleground-queue:is-check-normal-match']: {
			queue: Acore.BattlegroundQueue;
			bgTemplate: Acore.Battleground;
			bracketId: number;
			minPlayers: number;
			maxPlayers: number;
			__return: Acore.Box<boolean>;
		};
		['battleground-queue:can-send-message']: {
			queue: Acore.BattlegroundQueue;
			leader: Acore.Player;
			bg: Acore.Battleground;
			bracketEntry: Acore.PvPDifficultyEntry;
			__return: Acore.Box<boolean>;
		};
		['battleground-queue:before-send-join-message-arena']: {
			queue: Acore.BattlegroundQueue;
			leader: Acore.Player;
			gInfo: GroupQueueInfo;
			bracketEntry: Acore.PvPDifficultyEntry;
			isRated: boolean;
			__return: Acore.Box<boolean>;
		};
		['battleground-queue:before-send-exit-message-arena']: {
			queue: Acore.BattlegroundQueue;
			gInfo: GroupQueueInfo;
			__return: Acore.Box<boolean>;
		};
		['battleground-queue:can-add-group-to-matching-pool']: {
			queue: Acore.BattlegroundQueue;
			gInfo: GroupQueueInfo;
			poolPlayerCount: number;
			bg: Acore.Battleground;
			bracketId: number;
			__return: Acore.Box<boolean>;
		};
		['battleground-queue:get-player-matchmaking-rating']: {
			playerGuid: bigint;
			bgTypeId: BattlegroundTypeId;
			outRating: Acore.Box<number>;
			__return: Acore.Box<boolean>;
		};
	}
}
export {};
