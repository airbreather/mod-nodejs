declare global {
	interface Hooks {
		['account:login']: { accountId: number; };
		['account:before-delete']: { accountId: number; };
		['account:last-ip-update']: { accountId: number; ip: string; };
		['account:failed-login']: { accountId: number; };
		['account:email-change']: { accountId: number; };
		['account:failed-email-change']: { accountId: number; };
		['account:password-change']: { accountId: number; };
		['account:failed-password-change']: { accountId: number; };
		['account:can-create-character']: {
			accountId: number;
			race: Races;
			clazz: Classes;
			__return: Acore.Box<boolean>;
		};
	}
}
export {};
