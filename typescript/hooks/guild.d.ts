declare global {
	interface Hooks {
		['guild:add-member']: {
			readonly guild: Acore.Guild;
			readonly player: Acore.Player;
			plRank: number;
		};
		['guild:remove-member']: {
			readonly guild: Acore.Guild;
			readonly player: Acore.Player;
			readonly isDisbanding: boolean;
			readonly isKicked: boolean;
		};
		['guild:motd-changed']: {
			readonly guild: Acore.Guild;
			readonly newMotd: string;
		};
		['guild:info-changed']: {
			readonly guild: Acore.Guild;
			readonly newInfo: string;
		};
		['guild:create']: {
			readonly guild: Acore.Guild;
			readonly leader: Acore.Player;
			readonly name: string;
		};
		['guild:disband']: { readonly guild: Acore.Guild; };
		['guild:member-withdraw-money']: {
			readonly guild: Acore.Guild;
			readonly player: Acore.Player;
			amount: number;
			readonly isRepair: boolean;
		};
		['guild:member-deposit-money']: {
			readonly guild: Acore.Guild;
			readonly player: Acore.Player;
			amount: number;
		};
		['guild:item-move']: {
			readonly guild: Acore.Guild;
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly isSrcBank: boolean;
			readonly srcContainer: number;
			readonly srcSlotId: number;
			readonly isDestBank: boolean;
			readonly destContainer: number;
			readonly destSlotId: number;
		};
		['guild:invite-player']: {
			readonly guild: Acore.Guild;
			readonly inviterGuid: bigint;
			readonly inviteeGuid: bigint;
		};
		['guild:player-leave']: {
			readonly guild: Acore.Guild;
			readonly playerGuid: bigint;
		};
		['guild:uninvite-player']: {
			readonly guild: Acore.Guild;
			readonly uninviterGuid: bigint;
			readonly uninviteeGuid: bigint;
		};
		['guild:demote-player']: {
			readonly guild: Acore.Guild;
			readonly demoterGuid: bigint;
			readonly demoteeGuid: bigint;
			readonly newRank: number;
		};
		['guild:promote-player']: {
			readonly guild: Acore.Guild;
			readonly promoterGuid: bigint;
			readonly promoteeGuid: bigint;
			readonly newRank: number;
		};
		['guild:generic-logged-event']: {
			readonly guild: Acore.Guild;
			readonly eventType: GuildEventLogTypes;
			readonly playerGuid1: bigint;
			readonly playerGuid2: bigint;
			readonly newRank: number;
		};
		['guild:withdraw-bank-item']: {
			readonly guild: Acore.Guild;
			readonly srcTabId: number;
			readonly playerGuid: bigint;
			readonly itemEntry: number;
			readonly count: number;
		};
		['guild:move-bank-item']: {
			readonly guild: Acore.Guild;
			readonly srcTabId: number;
			readonly playerGuid: bigint;
			readonly itemEntry: number;
			readonly count: number;
			readonly destTabId: number;
		};
		['guild:deposit-bank-item']: {
			readonly guild: Acore.Guild;
			readonly destTabId: number;
			readonly playerGuid: bigint;
			readonly itemEntry: number;
			readonly count: number;
		};
		['guild:deposit-bank-money']: {
			readonly guild: Acore.Guild;
			readonly playerGuid: bigint;
			readonly amount: number;
		};
		['guild:withdraw-bank-money']: {
			readonly guild: Acore.Guild;
			readonly playerGuid: bigint;
			readonly amount: number;
		};
		['guild:repair-bank-money']: {
			readonly guild: Acore.Guild;
			readonly playerGuid: bigint;
			readonly amount: number;
		};
		['guild:generic-logged-bank-event']: {
			readonly guild: Acore.Guild;
			readonly eventType: GuildBankEventLogTypes;
			readonly tabId: number;
			readonly playerGuid: bigint;
			readonly itemOrMoney: number;
			readonly itemStackCount: number;
			readonly destTabId: number;
		};
		['guild:can-send-bank-list']: {
			readonly guild: Acore.Guild;
			readonly player: Acore.Player | undefined;
			readonly tabId: number;
			readonly sendAllSlots: boolean;
			__return: boolean;
		};
	}
}
export {};
