#include <v8-local-handle.h>
#include <v8-template.h>

#include "AuctionHouseMgr.h"
#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "ObjectMgr.h"
#include "UnixTimestamp.h"

JVAL_CVAL_TMPLS_RW(AuctionEntry)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<AuctionEntry *>() {
	TypedTemplate<AuctionEntry *> const ft = jctor([] {
		auto a = new AuctionEntry;
		a->Id = sObjectMgr->GenerateAuctionID();
		// start it off as Neutral just so it's valid - the user can change it later.
		a->houseId = AuctionHouseId::Neutral;
		a->auctionHouseEntry = AuctionHouseMgr::GetAuctionHouseEntryFromHouse(AuctionHouseId::Neutral);
		return a;
	});

	ft->SetClassName(jstr_intern("Auction"));

	reg_static_method(ft, "calculateAuctionOutBid", [](uint32_t bid) {
		return AuctionEntry::CalculateAuctionOutBid(bid);
	});

	reg_prop_ro(ft, "id", [](AuctionEntry * auction) {
		return auction->Id;
	});
	reg_prop_ro(ft, "factionId", [](AuctionEntry * auction) {
		return auction->auctionHouseEntry->faction;
	});
	reg_prop_ro(ft, "depositPercent", [](AuctionEntry * auction) {
		return auction->auctionHouseEntry->depositPercent;
	});
	reg_prop_ro(ft, "cutPercent", [](AuctionEntry * auction) {
		return auction->auctionHouseEntry->cutPercent;
	});
	reg_prop_ro(ft, "cut", [](AuctionEntry * auction) {
		return auction->GetAuctionCut();
	});
	reg_prop_ro(ft, "outBid", [](AuctionEntry * auction) {
		return auction->GetAuctionOutBid();
	});

	reg_prop(ft, "houseId",
		[](AuctionEntry * auction) { return auction->houseId; },
		[](AuctionEntry * auction, auto v) {
			auction->houseId = v;
			auction->auctionHouseEntry = AuctionHouseMgr::GetAuctionHouseEntryFromHouse(v);
		}
	);
	reg_prop(ft, "itemGuid",
		[](AuctionEntry * auction) { return auction->item_guid; },
		[](AuctionEntry * auction, auto v) { auction->item_guid = v; }
	);
	reg_prop(ft, "itemTemplate",
		[](AuctionEntry * auction) { return auction->item_template; },
		[](AuctionEntry * auction, auto v) { auction->item_template = v; }
	);
	reg_prop(ft, "itemCount",
		[](AuctionEntry * auction) { return auction->itemCount; },
		[](AuctionEntry * auction, auto v) { auction->itemCount = v; }
	);
	reg_prop(ft, "ownerGuid",
		[](AuctionEntry * auction) { return auction->owner; },
		[](AuctionEntry * auction, auto v) { auction->owner = v; }
	);
	reg_prop(ft, "startBid",
		[](AuctionEntry * auction) { return auction->startbid; },
		[](AuctionEntry * auction, auto v) { auction->startbid = v; }
	);
	reg_prop(ft, "currentBid",
		[](AuctionEntry * auction) { return auction->bid; },
		[](AuctionEntry * auction, auto v) { auction->bid = v; }
	);
	reg_prop(ft, "buyout",
		[](AuctionEntry * auction) { return auction->buyout; },
		[](AuctionEntry * auction, auto v) { auction->buyout = v; }
	);
	reg_prop(ft, "expireTime",
		[](AuctionEntry * auction) { return UnixTimestamp::from_time_t_seconds(auction->expire_time); },
		[](AuctionEntry * auction, auto v) { auction->expire_time = v.to_time_t_seconds(); }
	);
	reg_prop(ft, "bidder",
		[](AuctionEntry * auction) { return auction->bidder; },
		[](AuctionEntry * auction, auto v) { auction->bidder = v; }
	);
	reg_prop(ft, "deposit",
		[](AuctionEntry * auction) { return auction->deposit; },
		[](AuctionEntry * auction, auto v) { auction->deposit = v; }
	);

	reg_method(ft, "deleteFromDB", [](AuctionEntry * auction) {
		db<Db::Character>().transactional([auction](auto trans) {
			auction->DeleteFromDB(std::move(trans));
		});
	});
	reg_method(ft, "saveToDB", [](AuctionEntry * auction) {
		db<Db::Character>().transactional([auction](auto trans) {
			auction->SaveToDB(std::move(trans));
		});
	});
	reg_method(ft, "sendAuctionWonMail", [](AuctionEntry * auction, std::optional<bool> send_notification, std::optional<bool> update_achievement_criteria) {
		db<Db::Character>().transactional([auction, send_notification, update_achievement_criteria](auto trans) {
			sAuctionMgr->SendAuctionWonMail(auction, std::move(trans), send_notification.value_or(true), update_achievement_criteria.value_or(true));
		});
	});
	reg_method(ft, "sendAuctionSalePendingMail", [](AuctionEntry * auction) {
		db<Db::Character>().transactional([auction](auto trans) {
			sAuctionMgr->SendAuctionSalePendingMail(auction, std::move(trans));
		});
	});
	reg_method(ft, "sendAuctionSuccessfulMail", [](AuctionEntry * auction, std::optional<bool> send_notification, std::optional<bool> update_achievement_criteria) {
		db<Db::Character>().transactional([auction, send_notification, update_achievement_criteria](auto trans) {
			sAuctionMgr->SendAuctionSuccessfulMail(auction, std::move(trans), send_notification.value_or(true), update_achievement_criteria.value_or(true));
		});
	});
	reg_method(ft, "sendAuctionExpiredMail", [](AuctionEntry * auction, std::optional<bool> send_notification) {
		db<Db::Character>().transactional([auction, send_notification](auto trans) {
			sAuctionMgr->SendAuctionExpiredMail(auction, std::move(trans), send_notification.value_or(true));
		});
	});
	reg_method(ft, "sendAuctionOutbiddedMail", [](AuctionEntry * auction, uint32_t new_price, Player * new_bidder, std::optional<bool> send_notification) {
		db<Db::Character>().transactional([auction, new_price, new_bidder, send_notification](auto trans) {
			sAuctionMgr->SendAuctionOutbiddedMail(auction, new_price, new_bidder, std::move(trans), send_notification.value_or(true));
		});
	});
	reg_method(ft, "sendAuctionCancelledToBidderMail", [](AuctionEntry * auction) {
		db<Db::Character>().transactional([auction](auto trans) {
			sAuctionMgr->SendAuctionCancelledToBidderMail(auction, std::move(trans));
		});
	});

	return ft;
}
