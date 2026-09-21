#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using FishingHoleData = decltype(GameObjectTemplate().fishinghole);
JVAL_CVAL_TMPLS_RO(FishingHoleData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<FishingHoleData const *>() {
	TypedTemplate<FishingHoleData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("FishingHoleData"));

	reg_prop_ro(ft, "radius", [](FishingHoleData const * h) {
		return h->radius;
	});
	reg_prop_ro(ft, "lootId", [](FishingHoleData const * h) {
		return h->lootId;
	});
	reg_prop_ro(ft, "minSuccessOpens", [](FishingHoleData const * h) {
		return h->minSuccessOpens;
	});
	reg_prop_ro(ft, "maxSuccessOpens", [](FishingHoleData const * h) {
		return h->maxSuccessOpens;
	});
	reg_prop_ro(ft, "lockId", [](FishingHoleData const * h) {
		return h->lockId;
	});

	return ft;
}
