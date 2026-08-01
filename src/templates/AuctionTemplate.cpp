#include <v8-local-handle.h>
#include <v8-template.h>

#include "AuctionHouseMgr.h"
#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "UnixTimestamp.h"

JVAL_CVAL_TMPLS_RW(AuctionEntry)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<AuctionEntry *>() {
	TypedTemplate<AuctionEntry *> const ft = jctor();

	ft->SetClassName(jstr_intern("AuctionEntry"));

	reg_prop_ro(ft, "id", [](AuctionEntry * auction) {
		return auction->Id;
	});
	reg_prop_ro(ft, "houseId", [](AuctionEntry * auction) {
		return auction->houseId;
	});
	reg_prop_ro(ft, "itemGuid", [](AuctionEntry * auction) {
		return auction->item_guid;
	});
	reg_prop_ro(ft, "itemTemplate", [](AuctionEntry * auction) {
		return auction->item_template;
	});
	reg_prop_ro(ft, "itemCount", [](AuctionEntry * auction) {
		return auction->itemCount;
	});
	reg_prop_ro(ft, "ownerGuid", [](AuctionEntry * auction) {
		return auction->owner;
	});
	reg_prop_ro(ft, "startBid", [](AuctionEntry * auction) {
		return auction->startbid;
	});
	reg_prop_ro(ft, "currentBid", [](AuctionEntry * auction) {
		return auction->bid;
	});
	reg_prop_ro(ft, "buyout", [](AuctionEntry * auction) {
		return auction->buyout;
	});
	reg_prop_ro(ft, "expireTime", [](AuctionEntry * auction) {
		return UnixTimestamp::from_time_t_seconds(auction->expire_time);
	});
	reg_prop_ro(ft, "bidder", [](AuctionEntry * auction) {
		return auction->bidder;
	});
	reg_prop_ro(ft, "deposit", [](AuctionEntry * auction) {
		return auction->deposit;
	});
	reg_prop_ro(ft, "deposit", [](AuctionEntry * auction) {
		return auction->deposit;
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

	reg_static_method(ft, "calculateAuctionOutBid", [](uint32_t bid) {
		return AuctionEntry::CalculateAuctionOutBid(bid);
	});

	reg_method(ft, "deleteFromDB", [](AuctionEntry * auction) {
		NodeJs::transactional(CharacterDatabase, [auction](auto trans) {
			auction->DeleteFromDB(std::move(trans));
		});
	});
	reg_method(ft, "saveToDB", [](AuctionEntry * auction) {
		NodeJs::transactional(CharacterDatabase, [auction](auto trans) {
			auction->SaveToDB(std::move(trans));
		});
	});

	return ft;
}
