declare global {
	namespace Acore {
		class LootTemplate {
			process(loot: Loot, lootStore: LootStore | LootStoreType, lootMode: LootModes, player: Player, groupId?: number, isTopLevel?: boolean): void;
		}
	}
}
export {};
