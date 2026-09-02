declare global {
	namespace Acore {
		class GlyphPropertiesEntry {
			private constructor();

			static byId(id: number): GlyphPropertiesEntry | undefined;

			readonly id: number;
			readonly spellId: number;
			readonly typeFlags: number;
			// readonly spellIconID: number;                                      // GlyphIconId (SpellIcon.dbc)
		}
	}
}
export {};
