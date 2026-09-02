declare global {
	namespace Acore {
		class SummonPropertiesEntry {
			private constructor();

			static byId(id: number): SummonPropertiesEntry | undefined;

			readonly id: number;
			readonly category: SummonCategory;
			readonly faction: number;
			readonly type: SummonType;
			readonly slot: number;
			readonly flags: SummonPropFlags;
		}
	}
}
export {};
