#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using DestructibleBuildingData = decltype(GameObjectTemplate().building);
JVAL_CVAL_TMPLS_RO(DestructibleBuildingData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<DestructibleBuildingData const *>() {
	TypedTemplate<DestructibleBuildingData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("DestructibleBuildingData"));
	reg_prop_ro(ft, "intactNumHits", [](DestructibleBuildingData const * b) {
		return b->intactNumHits;
	});
	reg_prop_ro(ft, "creditProxyCreature", [](DestructibleBuildingData const * b) {
		return b->creditProxyCreature;
	});
	reg_prop_ro(ft, "state1Name", [](DestructibleBuildingData const * b) {
		return b->state1Name;
	});
	reg_prop_ro(ft, "intactEvent", [](DestructibleBuildingData const * b) {
		return b->intactEvent;
	});
	reg_prop_ro(ft, "damagedDisplayId", [](DestructibleBuildingData const * b) {
		return b->damagedDisplayId;
	});
	reg_prop_ro(ft, "damagedNumHits", [](DestructibleBuildingData const * b) {
		return b->damagedNumHits;
	});
	reg_prop_ro(ft, "empty3", [](DestructibleBuildingData const * b) {
		return b->empty3;
	});
	reg_prop_ro(ft, "empty4", [](DestructibleBuildingData const * b) {
		return b->empty4;
	});
	reg_prop_ro(ft, "empty5", [](DestructibleBuildingData const * b) {
		return b->empty5;
	});
	reg_prop_ro(ft, "damagedEvent", [](DestructibleBuildingData const * b) {
		return b->damagedEvent;
	});
	reg_prop_ro(ft, "destroyedDisplayId", [](DestructibleBuildingData const * b) {
		return b->destroyedDisplayId;
	});
	reg_prop_ro(ft, "empty7", [](DestructibleBuildingData const * b) {
		return b->empty7;
	});
	reg_prop_ro(ft, "empty8", [](DestructibleBuildingData const * b) {
		return b->empty8;
	});
	reg_prop_ro(ft, "empty9", [](DestructibleBuildingData const * b) {
		return b->empty9;
	});
	reg_prop_ro(ft, "destroyedEvent", [](DestructibleBuildingData const * b) {
		return b->destroyedEvent;
	});
	reg_prop_ro(ft, "empty10", [](DestructibleBuildingData const * b) {
		return b->empty10;
	});
	reg_prop_ro(ft, "debuildingTimeSecs", [](DestructibleBuildingData const * b) {
		return b->debuildingTimeSecs;
	});
	reg_prop_ro(ft, "empty11", [](DestructibleBuildingData const * b) {
		return b->empty11;
	});
	reg_prop_ro(ft, "destructibleData", [](DestructibleBuildingData const * b) {
		return b->destructibleData;
	});
	reg_prop_ro(ft, "rebuildingEvent", [](DestructibleBuildingData const * b) {
		return b->rebuildingEvent;
	});
	reg_prop_ro(ft, "empty12", [](DestructibleBuildingData const * b) {
		return b->empty12;
	});
	reg_prop_ro(ft, "empty13", [](DestructibleBuildingData const * b) {
		return b->empty13;
	});
	reg_prop_ro(ft, "damageEvent", [](DestructibleBuildingData const * b) {
		return b->damageEvent;
	});
	reg_prop_ro(ft, "empty14", [](DestructibleBuildingData const * b) {
		return b->empty14;
	});

	return ft;
}
