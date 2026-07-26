declare global {
	interface Hooks {
		['nodejs:startup']: { readonly persistData?: string };
		['nodejs:before-shutdown']: { readonly reloading: false; } | { readonly reloading: true; persistData: string; };

		['account:login']: { readonly accountId: number; };
		['account:before-delete']: { readonly accountId: number; };
		['account:last-ip-update']: { readonly accountId: number; readonly ip: string; };
		['account:failed-login']: { readonly accountId: number; };
		['account:password-change']: { readonly accountId: number; };

		['battleground-queue:update-validity']: {
			readonly queue: Acore.BattlegroundQueue;
			readonly diff: number;
			readonly bgTypeId: BattlegroundTypeId;
			readonly bracketId: number;
			readonly arenaType: ArenaType;
			readonly isRated: boolean;
			readonly arenaRating: number;
			__return: boolean;
		};

		['player:before-send-chat-message']: { readonly player: Acore.Player; type: ChatMsg; lang: Language; msg: string; };
		['player:complete-quest']: { readonly player: Acore.Player; quest: Acore.Quest; };
		['player:login']: { readonly player: Acore.Player; };
		['player:before-logout']: { readonly player: Acore.Player; };
		['player:logout']: { readonly player: Acore.Player; };
		['misc:after-loot-template-process']: {
			readonly loot: Acore.Loot;
			readonly tab: Acore.LootTemplate;
			readonly lootOwner: Acore.Player;
			readonly personal: boolean;
			readonly noEmptyError: boolean;
			readonly lootMode: LootModes;
		};
	}

	type HooksConforming = {
		[K in keyof Hooks]: [Hooks[K]];
	};
}
export {};
