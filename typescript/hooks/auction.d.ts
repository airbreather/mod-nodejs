declare global {
	interface Hooks {
		['auction:add-auction']: {
			readonly ah: Acore.AuctionHouse;
			readonly auction: Acore.Auction;
		};
		['auction:remove-auction']: {
			readonly ah: Acore.AuctionHouse;
			readonly auction: Acore.Auction;
		};
		['auction:successful']: {
			readonly ah: Acore.AuctionHouse;
			readonly auction: Acore.Auction;
		};
		['auction:expire']: {
			readonly ah: Acore.AuctionHouse;
			readonly auction: Acore.Auction;
		};
		['auction:before-send-auction-won-mail']: {
			readonly auction: Acore.Auction;
			readonly bidder: Acore.Player | undefined;
			bidderAccId: number;
			sendNotification: boolean;
			updateAchievementCriteria: boolean;
			sendMail: boolean;
		};
		['auction:before-send-auction-sale-pending-mail']: {
			readonly auction: Acore.Auction;
			readonly owner: Acore.Player | undefined;
			ownerAccId: number;
			sendMail: boolean;
		};
		['auction:before-send-auction-successful-mail']: {
			readonly auction: Acore.Auction;
			readonly owner: Acore.Player | undefined;
			ownerAccId: number;
			profit: number;
			sendNotification: boolean;
			updateAchievementCriteria: boolean;
			sendMail: boolean;
		};
		['auction:before-send-auction-expired-mail']: {
			readonly auction: Acore.Auction;
			readonly owner: Acore.Player | undefined;
			ownerAccId: number;
			sendNotification: boolean;
			sendMail: boolean;
		};
		['auction:before-send-auction-outbidded-mail']: {
			readonly auction: Acore.Auction;
			readonly oldBidder: Acore.Player | undefined;
			oldBidderAccId: number;
			readonly newBidder: Acore.Player; // can't be offline, they just placed the bid!
			newPrice: number;
			sendNotification: boolean;
			sendMail: boolean;
		};
		['auction:before-send-auction-cancelled-to-bidder-mail']: {
			readonly auction: Acore.Auction;
			readonly bidder: Acore.Player | undefined;
			bidderAccId: number;
			sendMail: boolean;
		};
		['auction:before-update']: object;
	}
}
export {};
