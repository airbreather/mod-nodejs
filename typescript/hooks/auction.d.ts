declare global {
	interface Hooks {
		['auction:add-auction']: {
			ah: Acore.AuctionHouse;
			auction: Acore.Auction;
		};
		['auction:remove-auction']: {
			ah: Acore.AuctionHouse;
			auction: Acore.Auction;
		};
		['auction:successful']: {
			ah: Acore.AuctionHouse;
			auction: Acore.Auction;
		};
		['auction:expire']: {
			ah: Acore.AuctionHouse;
			auction: Acore.Auction;
		};
		['auction:before-send-auction-won-mail']: {
			auction: Acore.Auction;
			bidder: Acore.Player | undefined;
			bidderAccId: Acore.Box<number>;
			sendNotification: Acore.Box<boolean>;
			updateAchievementCriteria: Acore.Box<boolean>;
			sendMail: Acore.Box<boolean>;
		};
		['auction:before-send-auction-sale-pending-mail']: {
			auction: Acore.Auction;
			owner: Acore.Player | undefined;
			ownerAccId: Acore.Box<number>;
			sendMail: Acore.Box<boolean>;
		};
		['auction:before-send-auction-successful-mail']: {
			auction: Acore.Auction;
			owner: Acore.Player | undefined;
			ownerAccId: Acore.Box<number>;
			profit: Acore.Box<number>;
			sendNotification: Acore.Box<boolean>;
			updateAchievementCriteria: Acore.Box<boolean>;
			sendMail: Acore.Box<boolean>;
		};
		['auction:before-send-auction-expired-mail']: {
			auction: Acore.Auction;
			owner: Acore.Player | undefined;
			ownerAccId: Acore.Box<number>;
			sendNotification: Acore.Box<boolean>;
			sendMail: Acore.Box<boolean>;
		};
		['auction:before-send-auction-outbidded-mail']: {
			auction: Acore.Auction;
			oldBidder: Acore.Player | undefined;
			oldBidderAccId: Acore.Box<number>;
			newBidder: Acore.Player; // can't be offline, they just placed the bid!
			newPrice: Acore.Box<number>;
			sendNotification: Acore.Box<boolean>;
			sendMail: Acore.Box<boolean>;
		};
		['auction:before-send-auction-cancelled-to-bidder-mail']: {
			auction: Acore.Auction;
			bidder: Acore.Player | undefined;
			bidderAccId: Acore.Box<number>;
			sendMail: Acore.Box<boolean>;
		};
		['auction:before-update']: object;
	}
}
export {};
