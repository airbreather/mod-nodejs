#include <v8-local-handle.h>
#include <v8-template.h>

#include "AuctionHouseMgr.h"
#include "CtoJ.h"
#include "DBCStructure.h"
#include "DurationWrapper.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RW(AuctionHouseObject)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<AuctionHouseObject *>() {
	TypedTemplate<AuctionHouseObject *> const ft = jctor();

	ft->SetClassName(jstr_intern("AuctionHouse"));

	reg_static_method(ft, "forId", [](AuctionHouseId id) {
		return sAuctionMgr->GetAuctionsMapByHouseId(id);
	});
	// TODO: only the ItemTemplate is used, and only its sell price at that.
	// so we shouldn't need a fully realized Item object to call this.
	reg_static_method(ft, "getAuctionDeposit", [](AuctionHouseId id, DurationWrapper time, Item * item, uint32_t count) {
		auto ah = sAuctionMgr->GetAuctionHouseEntryFromHouse(id);
		return sAuctionMgr->GetAuctionDeposit(ah, time.count<Seconds>(), item, count);
	});
	reg_static_method(ft, "getAItem", [](ObjectGuid guid) {
		return sAuctionMgr->GetAItem(guid);
	});

	reg_prop_ro(ft, "auctionCount", [](AuctionHouseObject * ah) {
		return ah->Getcount();
	});
	reg_prop_ro(ft, "allAuctions", [](AuctionHouseObject * ah) {
		return jarr(ah->GetAuctions() | std::ranges::views::values);
	});

	reg_method(ft, "addAuction", [](AuctionHouseObject * ah, AuctionEntry * auction, Item * item) {
		sAuctionMgr->AddAItem(item);
		ah->AddAuction(auction);
	});
	reg_method(ft, "getAuction", [](AuctionHouseObject * ah, uint32_t id) {
		return ah->GetAuction(id);
	});
	reg_method(ft, "removeAuction", [](AuctionHouseObject * ah, AuctionEntry * auction) {
		return ah->RemoveAuction(auction);
	});
	reg_method(ft, "update", [](AuctionHouseObject * ah) {
		ah->Update();
	});

	return ft;
}
