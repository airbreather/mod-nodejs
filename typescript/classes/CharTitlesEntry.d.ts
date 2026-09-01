declare global {
	namespace Acore {
		class CharTitlesEntry {
			private constructor();

			static byId(id: number): CharTitlesEntry | undefined;

			readonly id: number;
			readonly nameMale: string[];
			readonly nameFemale: string[];
			readonly bitIndex: number;
		}
	}
}
export {};
