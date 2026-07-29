declare global {
	interface LootItem {
		itemid: number;
		index: number;
		count: number;
		needs_quest: boolean;
		is_looted: boolean;
		randomSuffix: number;
		randomPropertyId: number;
	}
}
export {};
