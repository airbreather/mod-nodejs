declare global {
	interface Hooks {
		['account:login']: { readonly accountId: number; };
		['account:before-delete']: { readonly accountId: number; };
		['account:last-ip-update']: { readonly accountId: number; readonly ip: string; };
		['account:failed-login']: { readonly accountId: number; };
		['account:password-change']: { readonly accountId: number; };
	}
}
export {};
