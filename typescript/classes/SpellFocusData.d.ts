declare global {
	namespace Acore {
		class SpellFocusData {
			private constructor();

			readonly focusId: number;
			readonly dist: number;
			readonly linkedTrapId: number;
			readonly serverOnly: boolean;
			readonly questId: number;
			readonly large: boolean;
			readonly floatingTooltip: number;
		}
	}
}
export {};
