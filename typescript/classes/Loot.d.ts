declare global {
	namespace Acore {
		class Loot {
			readonly itemCount: number;
			readonly isLooted: boolean;
			readonly isEmpty: boolean;
			readonly hasQuestItems: boolean;
			readonly hasItemForAll: boolean;
			readonly hasOverThresholdItem: boolean;
			readonly items: LootItem[];
			readonly questItems: LootItem[];
			lootType: LootType;
			unlootedCount: number;
			gold: number;
			// SOME of these `| undefined` MAY be incorrect. SOME of them are DEFINITELY correct.
			roundRobinPlayer: ObjectGuidNative | undefined;
			lootOwnerGuid: ObjectGuidNative | undefined;
			containerGuid: ObjectGuidNative | undefined;
			sourceWorldObjectGuid: ObjectGuidNative | undefined;

			addItem(itemId: number, minCount: number, maxCount: number, chance: number, lootMode: LootModes, needsQuest?: boolean, allowStacking?: boolean, maxStackSize?: number): void;
			clear(): void;
			generateMoney(min: number, max: number): void;
			addLooter(looter: ObjectGuid): void;
			removeLooter(looter: ObjectGuid): void;
		}
	}
}
export {};
