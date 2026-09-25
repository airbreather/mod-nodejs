declare global {
	namespace Acore {
		class TextData {
			private constructor();

			readonly pageId: number;
			readonly language: Language;
			readonly pageMaterial: number;
			readonly allowMounted: boolean;
		}
	}
}
export {};
