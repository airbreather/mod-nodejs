declare global {
	interface GlobalHooks {
		['battleground-queue:update']: {
			readonly queue: Acore.BattlegroundQueue;
			readonly diff: Temporal.Duration;
			readonly bgTypeId: BattlegroundTypeId;
			readonly bracketId: number;
			readonly arenaType: ArenaType;
			readonly isRated: boolean;
			readonly arenaRating: number;
		};
		['battleground-queue:update-validity']: {
			readonly queue: Acore.BattlegroundQueue;
			readonly diff: Temporal.Duration;
			readonly bgTypeId: BattlegroundTypeId;
			readonly bracketId: number;
			readonly arenaType: ArenaType;
			readonly isRated: boolean;
			readonly arenaRating: number;
			readonly __return: Acore.Box<boolean>;
		};
		['battleground-queue:add-group']: {
			readonly queue: Acore.BattlegroundQueue;
			readonly gInfo: GroupQueueInfo;
			readonly index: Acore.Box<number>;
			readonly leader: Acore.Player;
			readonly group: Acore.Group;
			readonly bgTypeId: BattlegroundTypeId;
			readonly bracketEntry: Acore.PvPDifficultyEntry;
			readonly arenaType: ArenaType;
			readonly isRated: boolean;
			readonly isPremade: boolean;
			readonly arenaRating: number;
			readonly matchmakerRating: number;
			readonly arenaTeamId: number;
			readonly opponentsArenaTeamId: number;
		};
		['battleground-queue:can-fill-players']: {
			readonly queue: Acore.BattlegroundQueue;
			readonly bg: Acore.Battleground;
			readonly bracketId: number;
			readonly __return: Acore.Box<boolean>;
		};
		['battleground-queue:is-check-normal-match']: {
			readonly queue: Acore.BattlegroundQueue;
			readonly bgTemplate: Acore.Battleground;
			readonly bracketId: number;
			readonly minPlayers: number;
			readonly maxPlayers: number;
			readonly __return: Acore.Box<boolean>;
		};
		['battleground-queue:can-send-message']: {
			readonly queue: Acore.BattlegroundQueue;
			readonly leader: Acore.Player;
			readonly bg: Acore.Battleground;
			readonly bracketEntry: Acore.PvPDifficultyEntry;
			readonly __return: Acore.Box<boolean>;
		};
		['battleground-queue:before-send-join-message-arena']: {
			readonly queue: Acore.BattlegroundQueue;
			readonly leader: Acore.Player;
			readonly gInfo: GroupQueueInfo;
			readonly bracketEntry: Acore.PvPDifficultyEntry;
			readonly isRated: boolean;
			readonly __return: Acore.Box<boolean>;
		};
		['battleground-queue:before-send-exit-message-arena']: {
			readonly queue: Acore.BattlegroundQueue;
			readonly gInfo: GroupQueueInfo;
			readonly __return: Acore.Box<boolean>;
		};
		['battleground-queue:can-add-group-to-matching-pool']: {
			readonly queue: Acore.BattlegroundQueue;
			readonly gInfo: GroupQueueInfo;
			readonly poolPlayerCount: number;
			readonly bg: Acore.Battleground;
			readonly bracketId: number;
			readonly __return: Acore.Box<boolean>;
		};
		['battleground-queue:get-player-matchmaking-rating']: {
			readonly playerGuid: bigint;
			readonly bgTypeId: BattlegroundTypeId;
			readonly outRating: Acore.Box<number>;
			readonly __return: Acore.Box<boolean>;
		};
	}
}
export {};
