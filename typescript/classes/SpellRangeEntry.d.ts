declare global {
	namespace Acore {
		class SpellRangeEntry {
			private constructor();

			static byId(id: number): SpellRangeEntry | undefined;

			readonly id: number;
			readonly minHostile: number;
			readonly minFriendly: number;
			readonly maxHostile: number;
			readonly maxFriendly: number;
			readonly flags: SpellRangeFlag;
		}
	}
}
export {};
