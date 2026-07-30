#include <v8-local-handle.h>
#include <v8-template.h>

#include "AuctionHouseMgr.h"
#include "CtoJ.h"
#include "DBCStructure.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RW(AuctionHouseObject)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<AuctionHouseObject *>() {
	TypedTemplate<AuctionHouseObject *> const ft = jctor();

	ft->SetClassName(jstr_intern("AuctionHouseObject"));

	reg_static_method(ft, "forId", [](AuctionHouseId id) {
		return sAuctionMgr->GetAuctionsMapByHouseId(id);
	});

	reg_prop_ro(ft, "auctionCount", [](AuctionHouseObject * ah) {
		return ah->Getcount();
	});
	reg_prop_ro(ft, "allAuctions", [](AuctionHouseObject * ah) {
		return jarr(ah->GetAuctions() | std::ranges::views::values);
	});

	reg_method(ft, "addAuction", [](AuctionHouseObject * ah, AuctionEntry * auction) {
		ah->AddAuction(auction);
	});
	reg_method(ft, "removeAuction", [](AuctionHouseObject * ah, AuctionEntry * auction) {
		return ah->RemoveAuction(auction);
	});

	return ft;
}
