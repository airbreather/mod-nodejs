declare global {
	const enum AccountOpResult {
		AOR_OK,
		AOR_NAME_TOO_LONG,
		AOR_PASS_TOO_LONG,
		AOR_EMAIL_TOO_LONG,
		AOR_NAME_ALREADY_EXIST,
		AOR_NAME_NOT_EXIST,
		AOR_DB_INTERNAL_ERROR,
	}
}
export {};
