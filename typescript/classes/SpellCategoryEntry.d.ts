declare global {
	namespace Acore {
		class SpellCategoryEntry {
			private constructor();

			static byId(id: number): SpellCategoryEntry | undefined;

			readonly id: number;
			readonly flags: SpellCategoryFlags;
		}
	}
}
export {};
