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
			roundRobinPlayer: ObjectGuid | undefined;
			lootOwnerGuid: ObjectGuid | undefined;
			containerGuid: ObjectGuid | undefined;
			sourceWorldObjectGuid: ObjectGuid | undefined;

			getMaxSlotForPlayer(player: Player): number;
			hasItem(itemId?: number, count?: number): boolean;
			addItem(itemId: number, minCount: number, maxCount: number, chance: number, lootMode: LootModes, needsQuest?: boolean, allowStacking?: boolean, maxStackSize?: number): void;
			removeItem(itemId: number, count?: number): void;
			clear(): void;
			generateMoney(min: number, max: number): void;
			setItemLooted(itemId: number, count: number, looted: boolean): void;
			addLooter(looter: ObjectGuid): void;
			removeLooter(looter: ObjectGuid): void;
		}
	}
}
export {};
