declare global {
	interface Hooks {
		['guild:add-member']: {
			guild: Acore.Guild;
			player: Acore.Player;
			plRank: Acore.Box<number>;
		};
		['guild:remove-member']: {
			guild: Acore.Guild;
			player: Acore.Player;
			isDisbanding: boolean;
			isKicked: boolean;
		};
		['guild:motd-changed']: {
			guild: Acore.Guild;
			newMotd: string;
		};
		['guild:info-changed']: {
			guild: Acore.Guild;
			newInfo: string;
		};
		['guild:create']: {
			guild: Acore.Guild;
			leader: Acore.Player;
			name: string;
		};
		['guild:disband']: { guild: Acore.Guild; };
		['guild:member-withdraw-money']: {
			guild: Acore.Guild;
			player: Acore.Player;
			amount: Acore.Box<number>;
			isRepair: boolean;
		};
		['guild:member-deposit-money']: {
			guild: Acore.Guild;
			player: Acore.Player;
			amount: Acore.Box<number>;
		};
		['guild:item-move']: {
			guild: Acore.Guild;
			player: Acore.Player;
			item: Acore.Item;
			isSrcBank: boolean;
			srcContainer: number;
			srcSlotId: number;
			isDestBank: boolean;
			destContainer: number;
			destSlotId: number;
		};
		['guild:invite-player']: {
			guild: Acore.Guild;
			inviterGuid: bigint;
			inviteeGuid: bigint;
		};
		['guild:player-leave']: {
			guild: Acore.Guild;
			playerGuid: bigint;
		};
		['guild:uninvite-player']: {
			guild: Acore.Guild;
			uninviterGuid: bigint;
			uninviteeGuid: bigint;
		};
		['guild:demote-player']: {
			guild: Acore.Guild;
			demoterGuid: bigint;
			demoteeGuid: bigint;
			newRank: number;
		};
		['guild:promote-player']: {
			guild: Acore.Guild;
			promoterGuid: bigint;
			promoteeGuid: bigint;
			newRank: number;
		};
		['guild:generic-logged-event']: {
			guild: Acore.Guild;
			eventType: GuildEventLogTypes;
			playerGuid1: bigint;
			playerGuid2: bigint;
			newRank: number;
		};
		['guild:withdraw-bank-item']: {
			guild: Acore.Guild;
			srcTabId: number;
			playerGuid: bigint;
			itemEntry: number;
			count: number;
		};
		['guild:move-bank-item']: {
			guild: Acore.Guild;
			srcTabId: number;
			playerGuid: bigint;
			itemEntry: number;
			count: number;
			destTabId: number;
		};
		['guild:deposit-bank-item']: {
			guild: Acore.Guild;
			destTabId: number;
			playerGuid: bigint;
			itemEntry: number;
			count: number;
		};
		['guild:deposit-bank-money']: {
			guild: Acore.Guild;
			playerGuid: bigint;
			amount: number;
		};
		['guild:withdraw-bank-money']: {
			guild: Acore.Guild;
			playerGuid: bigint;
			amount: number;
		};
		['guild:repair-bank-money']: {
			guild: Acore.Guild;
			playerGuid: bigint;
			amount: number;
		};
		['guild:generic-logged-bank-event']: {
			guild: Acore.Guild;
			eventType: GuildBankEventLogTypes;
			tabId: number;
			playerGuid: bigint;
			itemOrMoney: number;
			itemStackCount: number;
			destTabId: number;
		};
		['guild:can-send-bank-list']: {
			guild: Acore.Guild;
			player: Acore.Player | undefined;
			tabId: number;
			sendAllSlots: boolean;
			__return: Acore.Box<boolean>;
		};
	}
}
export {};
