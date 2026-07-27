declare global {
	interface Hooks {
		['player:before-send-chat-message']: { readonly player: Acore.Player; type: ChatMsg; lang: Language; msg: string; };
		['player:complete-quest']: { readonly player: Acore.Player; quest: Acore.Quest; };
		['player:login']: { readonly player: Acore.Player; };
		['player:before-logout']: { readonly player: Acore.Player; };
		['player:logout']: { readonly player: Acore.Player; };
	}
}
export {};
