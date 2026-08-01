declare global {
	namespace Acore {
		class CharacterDatabaseTransaction {
			static runSync(fn: (trans: CharacterDatabaseTransaction) => void): void;

			appendRaw(raw: string): void;
		}
	}
}
export {};
