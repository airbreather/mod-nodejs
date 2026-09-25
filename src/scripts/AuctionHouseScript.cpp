#include "AuctionHouseScript.h"

#include <string>

#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_AuctionHouse : public AuctionHouseScript {
public:
	NODEJS_AuctionHouse() : AuctionHouseScript("NODEJS_AuctionHouse") {
	}

	void OnAuctionAdd(AuctionHouseObject * ah, AuctionEntry * entry) override {
		NodeJs::invoke_hook("auction:add-auction"
			, jprop("ah", ah), jprop("auction", entry));
	}
	void OnAuctionRemove(AuctionHouseObject * ah, AuctionEntry * entry) override {
		NodeJs::invoke_hook("auction:remove-auction"
			, jprop("ah", ah), jprop("auction", entry));
	}
	void OnAuctionSuccessful(AuctionHouseObject * ah, AuctionEntry * entry) override {
		NodeJs::invoke_hook("auction:successful"
			, jprop("ah", ah), jprop("auction", entry));
	}
	void OnAuctionExpire(AuctionHouseObject * ah, AuctionEntry * entry) override {
		NodeJs::invoke_hook("auction:expire"
			, jprop("ah", ah), jprop("auction", entry));
	}
	void OnBeforeAuctionHouseMgrSendAuctionWonMail(AuctionHouseMgr *, AuctionEntry * auction, Player * bidder, uint32_t & bidder_accId, bool & sendNotification, bool & updateAchievementCriteria, bool & sendMail) override {
		NodeJs::invoke_hook("auction:before-send-auction-won-mail"
			, jprop("auction", auction), jprop("bidder", bidder), jprop_box("bidderAccId", bidder_accId), jprop_box("sendNotification", sendNotification), jprop_box("updateAchievementCriteria", updateAchievementCriteria), jprop_box("sendMail", sendMail));
	}
	void OnBeforeAuctionHouseMgrSendAuctionSalePendingMail(AuctionHouseMgr *, AuctionEntry * auction, Player * owner, uint32_t & owner_accId, bool & sendMail) override {
		NodeJs::invoke_hook("auction:before-send-auction-sale-pending-mail"
			, jprop("auction", auction), jprop("owner", owner), jprop_box("ownerAccId", owner_accId), jprop_box("sendMail", sendMail));
	}
	void OnBeforeAuctionHouseMgrSendAuctionSuccessfulMail(AuctionHouseMgr *, AuctionEntry * auction, Player * owner, uint32_t & owner_accId, uint32_t & profit, bool & sendNotification, bool & updateAchievementCriteria, bool & sendMail) override {
		NodeJs::invoke_hook("auction:before-send-auction-successful-mail"
			, jprop("auction", auction), jprop("owner", owner), jprop_box("ownerAccId", owner_accId), jprop_box("profit", profit), jprop_box("sendNotification", sendNotification), jprop_box("updateAchievementCriteria", updateAchievementCriteria), jprop_box("sendMail", sendMail));
	}
	void OnBeforeAuctionHouseMgrSendAuctionExpiredMail(AuctionHouseMgr *, AuctionEntry * auction, Player * owner, uint32_t & owner_accId, bool & sendNotification, bool & sendMail) override {
		NodeJs::invoke_hook("auction:before-send-auction-expired-mail"
			, jprop("auction", auction), jprop("owner", owner), jprop_box("ownerAccId", owner_accId), jprop_box("sendNotification", sendNotification), jprop_box("sendMail", sendMail));
	}
	void OnBeforeAuctionHouseMgrSendAuctionOutbiddedMail(AuctionHouseMgr *, AuctionEntry * auction, Player * oldBidder, uint32_t & oldBidder_accId, Player * newBidder, uint32_t & newPrice, bool & sendNotification, bool & sendMail) override {
		NodeJs::invoke_hook("auction:before-send-auction-outbidded-mail"
			, jprop("auction", auction), jprop("oldBidder", oldBidder), jprop_box("oldBidderAccId", oldBidder_accId), jprop("newBidder", newBidder), jprop_box("newPrice", newPrice), jprop_box("sendNotification", sendNotification), jprop_box("sendMail", sendMail));
	}
	void OnBeforeAuctionHouseMgrSendAuctionCancelledToBidderMail(AuctionHouseMgr *, AuctionEntry * auction, Player * bidder, uint32_t & bidder_accId, bool & sendMail) override {
		NodeJs::invoke_hook("auction:before-send-auction-cancelled-to-bidder-mail"
			, jprop("auction", auction), jprop("bidder", bidder), jprop_box("bidderAccId", bidder_accId), jprop_box("sendMail", sendMail));
	}
	void OnBeforeAuctionHouseMgrUpdate() override {
		NodeJs::invoke_hook("auction:before-update"
			);
	}
};

void AddSC_AuctionHouse() {
	new NODEJS_AuctionHouse();
}
