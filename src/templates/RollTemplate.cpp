#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "Group.h"
#include "NodePropertySystem.h"
#include "ObjectGuid.h"

JVAL_CVAL_TMPLS_RW(Roll)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Roll *>() {
	TypedTemplate<Roll *> const ft = jctor();

	ft->SetClassName(jstr_intern("Roll"));

	reg_prop_ro(ft, "rollId", [](Roll * r) {
		return r->itemGUID.GetCounter();
	});
	reg_prop_ro(ft, "rollType", [](Roll * r) {
		return r->rollVoteMask;
	});
	reg_prop_ro(ft, "itemId", [](Roll * r) {
		return r->itemid;
	});
	reg_prop_ro(ft, "itemRandomPropId", [](Roll * r) {
		return r->itemRandomPropId;
	});
	reg_prop_ro(ft, "itemSuffix", [](Roll * r) {
		return r->itemRandomSuffix;
	});
	reg_prop_ro(ft, "itemCount", [](Roll * r) {
		return r->itemCount;
	});
	reg_prop_ro(ft, "isRollInProgress", [](Roll * r) {
		return !r->playerVote.empty();
	});

	return ft;
}
