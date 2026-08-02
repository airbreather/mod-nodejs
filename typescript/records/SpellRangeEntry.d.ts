declare global {
	interface SpellRangeEntry {
		id: number;
		minHostile: number;
		minFriendly: number;
		maxHostile: number;
		maxFriendly: number;
		flags: SpellRangeFlag;
	}
}
export {};
