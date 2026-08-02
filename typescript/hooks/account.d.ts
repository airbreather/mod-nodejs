declare global {
	interface Hooks {
		['account:login']: { readonly accountId: number; };
		['account:before-delete']: { readonly accountId: number; };
		['account:last-ip-update']: { readonly accountId: number; readonly ip: string; };
		['account:failed-login']: { readonly accountId: number; };
		['account:email-change']: { readonly accountId: number; };
		['account:failed-email-change']: { readonly accountId: number; };
		['account:password-change']: { readonly accountId: number; };
		['account:failed-password-change']: { readonly accountId: number; };
		['account:can-create-character']: {
			readonly accountId: number;
			readonly race: Races;
			readonly clazz: Classes;
			__return: boolean;
		};
	}
}
export {};
