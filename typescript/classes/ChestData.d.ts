declare global {
	namespace Acore {
		class ChestData {
			private constructor();

			readonly lockId: number;
			readonly lootId: number;
			readonly chestRestockTime: Temporal.Duration;
			readonly consumable: boolean;
			readonly minSuccessOpens: number;
			readonly maxSuccessOpens: number;
			readonly eventId: number;
			readonly linkedTrapId: number;
			readonly questId: number;
			readonly level: number;
			readonly losOk: boolean;
			readonly leaveLoot: boolean;
			readonly notInCombat: boolean;
			readonly logLoot: boolean;
			readonly openTextId: number;
			readonly groupLootRules: boolean;
			readonly floatingTooltip: boolean;
		}
	}
}
export {};
