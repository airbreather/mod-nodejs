declare global {
	namespace Acore {
		class QuestGiverData {
			private constructor();

			readonly lockId: number;
			readonly questList: number;
			readonly pageMaterial: number;
			readonly gossipId: number;
			readonly customAnim: number;
			readonly noDamageImmune: boolean;
			readonly openTextId: number;
			readonly losOk: boolean;
			readonly allowMounted: boolean;
			readonly large: boolean;
		}
	}
}
export {};
