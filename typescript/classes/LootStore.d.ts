declare global {
	namespace Acore {
		class LootStoreObject {
			readonly name: string;
			readonly entryName: string;
			readonly ratesAllowed: boolean;

			haveLootFor(lootId: number): boolean;
			haveQuestLootFor(lootId: number, player?: Player): boolean;
			getLootFor(lootId: number): LootTemplate;
		}

		type LootStore = Acore.LootStoreObject | LootStoreType;
	}
}
export {};
