declare global {
	namespace Acore {
		class Account {
			private constructor();

			// always returns an Account, even if it doesn't exist in the DB.
			// check {@link exists} before using (or handle errors appropriately).
			static byId(id: number): Account;
			// always returns an Account, even if it doesn't exist in the DB.
			// check {@link exists} before using (or handle errors appropriately).
			static byName(name: string): Account;
			static create(name: string, password: string, email?: string): Account | Exclude<AccountOpResult, AccountOpResult.AOR_OK>;

			// false results will cache nothing. otherwise the result and corresponding {@link name}
			// or {@link id} get cached, whichever wasn't authoritative in creating the object.
			// @see {@link invalidateCache}
			readonly exists: boolean;
			// throws if created {@link byName by a name} that doesn't {@link exists exist}.
			// if this wasn't authoritative in creating the object, then the result gets cached.
			readonly id: number;
			// throws if created {@link byId by an ID} that doesn't {@link exists exist}.
			// if this wasn't authoritative in creating the object, then the result gets cached.
			readonly name: string;
			// throws if it doesn't {@link exists exist}.
			// you probably want {@link securityLevelOnRealm} instead of this.
			// @see {@link securityLevelOnRealm}
			readonly securityLevel: AccountTypes;
			// throws if it doesn't {@link exists exist}.
			readonly characterCount: AccountTypes;

			// invalidates the caches that one should expect it to.
			delete(): AccountOpResult;
			// invalidates the caches that one should expect it to.
			// the password hash incorporates the name, so a new password must be provided as well.
			// @see {@link changePassword}
			changeName(newName: string, newPassword: string): AccountOpResult;
			//
			// @see {@link changeName}
			changePassword(newPassword: string): AccountOpResult;
			changeEmail(newEmail: string): AccountOpResult;
			// if the account doesn't {@link exists exist}, this will return false.
			checkPassword(password: string): boolean;
			// throws if it doesn't {@link exists exist}.
			// @see {@link securityLevel}
			securityLevelOnRealm(realmId: number): AccountTypes;
			// if the account doesn't {@link exists exist}, this will return false.
			hasPermissionOnRealm(permissionId: number, realmId: number): boolean;
			invalidateCache(): void;
		}
	}
}
export {};
