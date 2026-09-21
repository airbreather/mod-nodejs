declare global {
	namespace Acore {
		class GooberData {
			private constructor();

			readonly lockId: number;
			readonly questId: number;
			readonly eventId: number;
			readonly autoCloseTime: Temporal.Duration;
			readonly customAnim: boolean;
			readonly consumable: boolean;
			readonly cooldown: Temporal.Duration;
			readonly pageId: number;
			readonly language: Language;
			readonly pageMaterial: number;
			readonly spellId: number;
			readonly noDamageImmune: boolean;
			readonly linkedTrapId: number;
			readonly large: boolean;
			readonly openTextId: number;
			readonly closeTextId: number;
			readonly losOk: boolean;
			readonly allowMounted: boolean;
			readonly floatingTooltip: boolean;
			readonly gossipId: number;
			readonly worldStateSetsState: boolean;
		}
	}
}
export {};
