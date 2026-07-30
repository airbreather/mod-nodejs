#include <v8-local-handle.h>
#include <v8-template.h>

#include "AuctionHouseMgr.h"
#include "CtoJ.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RW(AuctionEntry)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<AuctionEntry *>() {
	TypedTemplate<AuctionEntry *> const ft = jctor();

	ft->SetClassName(jstr_intern("AuctionEntry"));

	return ft;
}
