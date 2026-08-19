declare global {
	namespace Acore {
		class VendorItemData {
			constructor();

			readonly empty: boolean;
			readonly itemCount: number;
			readonly items: readonly VendorItem[];

			clone(): VendorItemData;
			append(vendorItem: VendorItem): void;
			addItem(item: number, maxCount: number, incrTime: Temporal.Duration, extendedCost: number): void;
			removeItem(item: number): boolean;
			findItemCostPair(item: number, extendedCost: number): VendorItem | undefined;
			clear(): void;
		}

		type ReadonlyVendorItemData = Omit<VendorItemData,
			| 'append'
			| 'addItem'
			| 'removeItem'
			| 'clear'
		>;
	}
}
export {};
