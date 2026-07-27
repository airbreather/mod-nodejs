declare global {
	namespace Acore {
		class Loot {
			readonly lootType: LootType;
			readonly itemCount: number;
			readonly unlootedCount: number;
			readonly gold: number;
			// SOME of these `| undefined` MAY be incorrect. SOME of them are DEFINITELY correct.
			readonly roundRobinPlayer: ObjectGuidNative | undefined;
			readonly lootOwnerGuid: ObjectGuidNative | undefined;
			readonly containerGuid: ObjectGuidNative | undefined;
			readonly sourceWorldObjectGuid: ObjectGuidNative | undefined;

			addItem(itemId: number, minCount: number, maxCount: number, chance: number, lootMode: LootModes, needsQuest?: boolean, allowStacking?: boolean, maxStackSize?: number): void;
			clear(): void;
			generateMoney(min: number, max: number): void;
			addLooter(looter: ObjectGuid): void;
			removeLooter(looter: ObjectGuid): void;
		}
	}
}
export {};
