declare global {
	namespace Acore {
		class GemPropertiesEntry {
			private constructor();

			static byId(id: number): GemPropertiesEntry | undefined;

			readonly id: number;
			readonly spellItemEnchantment: number;
			readonly color: SocketColor;
		}
	}
}
export {};
