declare global {
	interface Hooks {
		['ticket:create']: { readonly ticket: Acore.GmTicket; };
		['ticket:update-last-change']: { readonly ticket: Acore.GmTicket; };
		['ticket:close']: { readonly ticket: Acore.GmTicket; };
		['ticket:status-update']: { readonly ticket: Acore.GmTicket; };
		['ticket:resolve']: { readonly ticket: Acore.GmTicket; };
	}
}
export {};
