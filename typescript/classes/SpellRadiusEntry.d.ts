declare global {
	namespace Acore {
		class SpellRadiusEntry {
			private constructor();

			static byId(id: number): SpellRadiusEntry | undefined;

			readonly id: number;
			readonly radiusMin: number;
			readonly radiusPerLevel: number;
			readonly radiusMax: number;
		}
	}
}
export {};
