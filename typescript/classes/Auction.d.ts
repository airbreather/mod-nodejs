declare global {
	namespace Acore {
		class Auction {
			constructor();

			readonly id: number;
			readonly factionId: number;
			readonly depositPercent: number;
			readonly cutPercent: number;
			readonly cut: number;
			readonly outBid: number;

			houseId: AuctionHouseId;
			itemGuid: ObjectGuidNative;
			itemTemplate: number;
			itemCount: number;
			ownerGuid: ObjectGuidNative;
			startBid: number;
			currentBid: number;
			buyout: number;
			expireTime: Temporal.Instant;
			bidder: ObjectGuidNative | undefined;
			deposit: number;

			static calculateAuctionOutBid(bid: number): number;

			deleteFromDB(): void;
			saveToDB(): void;
			saveToDB(): void;
			sendAuctionWonMail(sendNotification?: boolean, updateAchievementCriteria?: boolean): void;
			sendAuctionSalePendingMail(): void;
			sendAuctionSuccessfulMail(sendNotification?: boolean, updateAchievementCriteria?: boolean): void;
			sendAuctionExpiredMail(sendNotification?: boolean): void;
			sendAuctionOutbiddedMail(newPrice: number, newBidder: Player, sendNotification?: boolean): void;
			sendAuctionCancelledToBidderMail(): void;
		}
	}
}
export {};
