declare global {
	namespace Acore {
		class VendorItem {
			constructor(item: number, maxCount: number, incrTime: Temporal.Duration, extendedCost: number);

			item: number;
			maxCount: number;
			incrTime: Temporal.Duration;
			extendedCost: number;

			isGoldRequired(proto: ItemTemplate): boolean;
		}
	}
}
export {};
