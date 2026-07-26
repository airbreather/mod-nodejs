#include "AuctionHouseScript.h"

#include <string>

#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_AuctionHouse : public AuctionHouseScript {
public:
	NODEJS_AuctionHouse() : AuctionHouseScript("NODEJS_AuctionHouse") {
	}

	void OnAuctionAdd(AuctionHouseObject * ah, AuctionEntry * entry) override {
		NodeJs::invoke_hook("auction-house:add-auction"/*, jarg("ah", ah)*//*, jarg("auction", entry)*/);
	}
	void OnAuctionRemove(AuctionHouseObject * ah, AuctionEntry * entry) override {
		NodeJs::invoke_hook("auction-house:remove-auction"/*, jarg("ah", ah)*//*, jarg("auction", entry)*/);
	}
	void OnAuctionSuccessful(AuctionHouseObject * ah, AuctionEntry * entry) override {
		NodeJs::invoke_hook("auction-house:successful"/*, jarg("ah", ah)*//*, jarg("auction", entry)*/);
	}
	void OnAuctionExpire(AuctionHouseObject * ah, AuctionEntry * entry) override {
		NodeJs::invoke_hook("auction-house:expire"/*, jarg("ah", ah)*//*, jarg("auction", entry)*/);
	}
	void OnBeforeAuctionHouseMgrSendAuctionWonMail(AuctionHouseMgr * auctionHouseMgr, AuctionEntry * auction, Player * bidder, uint32_t & bidder_accId, bool & sendNotification, bool & updateAchievementCriteria, bool & sendMail) override {
		NodeJs::invoke_hook("auction-house:before-send-auction-won-mail"/*, jarg("auctionHouseMgr", auctionHouseMgr)*//*, jarg("auction", auction)*/, jarg("bidder", bidder), jarg_inout("bidderAccId", bidder_accId), jarg_inout("sendNotification", sendNotification), jarg_inout("updateAchievementCriteria", updateAchievementCriteria), jarg_inout("sendMail", sendMail));
	}
	void OnBeforeAuctionHouseMgrSendAuctionSalePendingMail(AuctionHouseMgr * auctionHouseMgr, AuctionEntry * auction, Player * owner, uint32_t & owner_accId, bool & sendMail) override {
		NodeJs::invoke_hook("auction-house:before-send-auction-sale-pending-mail"/*, jarg("auctionHouseMgr", auctionHouseMgr)*//*, jarg("auction", auction)*/, jarg("owner", owner), jarg_inout("ownerAccId", owner_accId), jarg_inout("sendMail", sendMail));
	}
	void OnBeforeAuctionHouseMgrSendAuctionSuccessfulMail(AuctionHouseMgr * auctionHouseMgr, AuctionEntry * auction, Player * owner, uint32_t & owner_accId, uint32_t & profit, bool & sendNotification, bool & updateAchievementCriteria, bool & sendMail) override {
		NodeJs::invoke_hook("auction-house:before-send-auction-successful-mail"/*, jarg("auctionHouseMgr", auctionHouseMgr)*//*, jarg("auction", auction)*/, jarg("owner", owner), jarg_inout("ownerAccId", owner_accId), jarg_inout("profit", profit), jarg_inout("sendNotification", sendNotification), jarg_inout("updateAchievementCriteria", updateAchievementCriteria), jarg_inout("sendMail", sendMail));
	}
	void OnBeforeAuctionHouseMgrSendAuctionExpiredMail(AuctionHouseMgr * auctionHouseMgr, AuctionEntry * auction, Player * owner, uint32_t & owner_accId, bool & sendNotification, bool & sendMail) override {
		NodeJs::invoke_hook("auction-house:before-send-auction-expired-mail"/*, jarg("auctionHouseMgr", auctionHouseMgr)*//*, jarg("auction", auction)*/, jarg("owner", owner), jarg_inout("ownerAccId", owner_accId), jarg_inout("sendNotification", sendNotification), jarg_inout("sendMail", sendMail));
	}
	void OnBeforeAuctionHouseMgrSendAuctionOutbiddedMail(AuctionHouseMgr * auctionHouseMgr, AuctionEntry * auction, Player * oldBidder, uint32_t & oldBidder_accId, Player * newBidder, uint32_t & newPrice, bool & sendNotification, bool & sendMail) override {
		NodeJs::invoke_hook("auction-house:before-send-auction-outbidded-mail"/*, jarg("auctionHouseMgr", auctionHouseMgr)*//*, jarg("auction", auction)*/, jarg("oldBidder", oldBidder), jarg_inout("oldBidderAccId", oldBidder_accId), jarg("newBidder", newBidder), jarg_inout("newPrice", newPrice), jarg_inout("sendNotification", sendNotification), jarg_inout("sendMail", sendMail));
	}
	void OnBeforeAuctionHouseMgrSendAuctionCancelledToBidderMail(AuctionHouseMgr * auctionHouseMgr, AuctionEntry * auction, Player * bidder, uint32_t & bidder_accId, bool & sendMail) override {
		NodeJs::invoke_hook("auction-house:before-send-auction-cancelled-to-bidder-mail"/*, jarg("auctionHouseMgr", auctionHouseMgr)*//*, jarg("auction", auction)*/, jarg("bidder", bidder), jarg_inout("bidderAccId", bidder_accId), jarg_inout("sendMail", sendMail));
	}
	void OnBeforeAuctionHouseMgrUpdate() override {
		NodeJs::invoke_hook("auction-house:before-update");
	}
};

void AddSC_AuctionHouse() {
	new NODEJS_AuctionHouse();
}
