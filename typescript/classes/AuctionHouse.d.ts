declare global {
	namespace Acore {
		class AuctionHouse {
			static forId(id: AuctionHouseId): AuctionHouse;
			static getAuctionDeposit(id: AuctionHouseId, time: Temporal.Duration, item: Item, count: number): number;
			static getAItem(guid: ObjectGuid): Item | undefined;

			readonly auctionCount: number;
			readonly allAuctions: Auction[];

			addAuction(auction: Auction, item: Item): void;
			getAuction(id: number): Auction | undefined;
			removeAuction(auction: Auction): boolean;
			update(): void;
		}
	}
}
export {};
