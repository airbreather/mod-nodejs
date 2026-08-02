declare global {
	interface SummonPropertiesEntry {
		id: number;
		category: SummonCategory;
		faction: number;
		type: SummonType;
		slot: number;
		flags: SummonPropFlags;
	}
}
export {};
