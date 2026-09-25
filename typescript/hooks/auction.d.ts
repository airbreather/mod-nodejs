declare global {
	interface GlobalHooks {
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
			readonly bidderAccId: Acore.Box<number>;
			readonly sendNotification: Acore.Box<boolean>;
			readonly updateAchievementCriteria: Acore.Box<boolean>;
			readonly sendMail: Acore.Box<boolean>;
		};
		['auction:before-send-auction-sale-pending-mail']: {
			readonly auction: Acore.Auction;
			readonly owner: Acore.Player | undefined;
			readonly ownerAccId: Acore.Box<number>;
			readonly sendMail: Acore.Box<boolean>;
		};
		['auction:before-send-auction-successful-mail']: {
			readonly auction: Acore.Auction;
			readonly owner: Acore.Player | undefined;
			readonly ownerAccId: Acore.Box<number>;
			readonly profit: Acore.Box<number>;
			readonly sendNotification: Acore.Box<boolean>;
			readonly updateAchievementCriteria: Acore.Box<boolean>;
			readonly sendMail: Acore.Box<boolean>;
		};
		['auction:before-send-auction-expired-mail']: {
			readonly auction: Acore.Auction;
			readonly owner: Acore.Player | undefined;
			readonly ownerAccId: Acore.Box<number>;
			readonly sendNotification: Acore.Box<boolean>;
			readonly sendMail: Acore.Box<boolean>;
		};
		['auction:before-send-auction-outbidded-mail']: {
			readonly auction: Acore.Auction;
			readonly oldBidder: Acore.Player | undefined;
			readonly oldBidderAccId: Acore.Box<number>;
			readonly newBidder: Acore.Player; // can't be offline, they just placed the bid!
			readonly newPrice: Acore.Box<number>;
			readonly sendNotification: Acore.Box<boolean>;
			readonly sendMail: Acore.Box<boolean>;
		};
		['auction:before-send-auction-cancelled-to-bidder-mail']: {
			readonly auction: Acore.Auction;
			readonly bidder: Acore.Player | undefined;
			readonly bidderAccId: Acore.Box<number>;
			readonly sendMail: Acore.Box<boolean>;
		};
		['auction:before-update']: object;
	}
}
export {};
