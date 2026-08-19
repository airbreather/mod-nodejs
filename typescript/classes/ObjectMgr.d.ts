declare global {
	namespace Acore {
		class ObjectMgr {
			private constructor();

			static getNpcVendorItemList(vendor: number): ReadonlyVendorItemData | undefined;
			static setNpcVendorItemList(vendor: number, data: VendorItemData): void;
			static addVendorItem(vendor: number, item: number, maxCount: number, incrTime: Temporal.Duration, extendedCost: number, persist?: boolean): void;
			static removeVendorItem(vendor: number, item: number, persist?: boolean): void;
		}
	}
}
export {};
