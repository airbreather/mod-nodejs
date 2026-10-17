declare global {
	namespace Acore {
		class SpellcasterData {
			private constructor();

			readonly spellId: number;
			readonly charges: number;
			readonly partyOnly: boolean;
			readonly allowMounted: boolean;
			readonly large: boolean;
		}
	}
}
export {};
