declare global {
	namespace Acore {
		class LootStore {
			readonly name: string;
			readonly entryName: string;
			readonly ratesAllowed: boolean;

			haveLootFor(lootId: number): boolean;
			haveQuestLootFor(lootId: number, player?: Player): boolean;
			getLootFor(lootId: number): LootTemplate;
		}
	}
}
export {};
