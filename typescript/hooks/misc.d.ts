declare global {
	interface Hooks {
		['misc:after-loot-template-process']: {
			readonly loot: Acore.Loot;
			readonly tab: Acore.LootTemplate;
			readonly lootOwner: Acore.Player;
			readonly personal: boolean;
			readonly noEmptyError: boolean;
			readonly lootMode: LootModes;
		};
	}
}
export {};
