#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using MoTransportData = decltype(GameObjectTemplate().moTransport);
JVAL_CVAL_TMPLS_RO(MoTransportData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<MoTransportData const *>() {
	TypedTemplate<MoTransportData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("MoTransportData"));

	reg_prop_ro(ft, "taxiPathId", [](MoTransportData const * t) {
		return t->taxiPathId;
	});
	reg_prop_ro(ft, "moveSpeed", [](MoTransportData const * t) {
		return t->moveSpeed;
	});
	reg_prop_ro(ft, "accelRate", [](MoTransportData const * t) {
		return t->accelRate;
	});
	reg_prop_ro(ft, "startEventId", [](MoTransportData const * t) {
		return t->startEventID;
	});
	reg_prop_ro(ft, "stopEventId", [](MoTransportData const * t) {
		return t->stopEventID;
	});
	reg_prop_ro(ft, "transportPhysics", [](MoTransportData const * t) {
		return t->transportPhysics;
	});
	reg_prop_ro(ft, "mapId", [](MoTransportData const * t) {
		return t->mapID;
	});
	reg_prop_ro(ft, "worldState1", [](MoTransportData const * t) {
		return t->worldState1;
	});
	reg_prop_ro(ft, "canBeStopped", [](MoTransportData const * t) {
		return t->canBeStopped != 0;
	});

	return ft;
}
