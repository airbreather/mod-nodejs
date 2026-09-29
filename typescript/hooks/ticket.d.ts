declare global {
	interface Hooks {
		['ticket:create']: { ticket: Acore.GmTicket; };
		['ticket:update-last-change']: { ticket: Acore.GmTicket; };
		['ticket:close']: { ticket: Acore.GmTicket; };
		['ticket:status-update']: { ticket: Acore.GmTicket; };
		['ticket:resolve']: { ticket: Acore.GmTicket; };
	}
}
export {};
