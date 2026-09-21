#include "CtoJ.h"
#include "DurationWrapper.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using CapturePointData = decltype(GameObjectTemplate().capturePoint);
JVAL_CVAL_TMPLS_RO(CapturePointData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<CapturePointData const *>() {
	TypedTemplate<CapturePointData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("CapturePointData"));

	reg_prop_ro(ft, "radius", [](CapturePointData const * c) {
		return c->radius;
	});
	reg_prop_ro(ft, "spell", [](CapturePointData const * c) {
		return c->spell;
	});
	reg_prop_ro(ft, "worldState1", [](CapturePointData const * c) {
		return c->worldState1;
	});
	reg_prop_ro(ft, "worldstate2", [](CapturePointData const * c) {
		return c->worldstate2;
	});
	reg_prop_ro(ft, "winEventId1", [](CapturePointData const * c) {
		return c->winEventID1;
	});
	reg_prop_ro(ft, "winEventId2", [](CapturePointData const * c) {
		return c->winEventID2;
	});
	reg_prop_ro(ft, "contestedEventId1", [](CapturePointData const * c) {
		return c->contestedEventID1;
	});
	reg_prop_ro(ft, "contestedEventId2", [](CapturePointData const * c) {
		return c->contestedEventID2;
	});
	reg_prop_ro(ft, "progressEventId1", [](CapturePointData const * c) {
		return c->progressEventID1;
	});
	reg_prop_ro(ft, "progressEventId2", [](CapturePointData const * c) {
		return c->progressEventID2;
	});
	reg_prop_ro(ft, "neutralEventId1", [](CapturePointData const * c) {
		return c->neutralEventID1;
	});
	reg_prop_ro(ft, "neutralEventId2", [](CapturePointData const * c) {
		return c->neutralEventID2;
	});
	reg_prop_ro(ft, "neutralPercent", [](CapturePointData const * c) {
		return c->neutralPercent;
	});
	reg_prop_ro(ft, "worldstate3", [](CapturePointData const * c) {
		return c->worldstate3;
	});
	reg_prop_ro(ft, "minSuperiority", [](CapturePointData const * c) {
		return c->minSuperiority;
	});
	reg_prop_ro(ft, "maxSuperiority", [](CapturePointData const * c) {
		return c->maxSuperiority;
	});
	reg_prop_ro(ft, "minTime", [](CapturePointData const * c) {
		return DurationWrapper::from_chrono(Seconds(c->minTime));
	});
	reg_prop_ro(ft, "maxTime", [](CapturePointData const * c) {
		return DurationWrapper::from_chrono(Seconds(c->maxTime));
	});
	reg_prop_ro(ft, "large", [](CapturePointData const * c) {
		return c->large != 0;
	});
	reg_prop_ro(ft, "highlight", [](CapturePointData const * c) {
		return c->highlight != 0;
	});
	reg_prop_ro(ft, "startingValue", [](CapturePointData const * c) {
		return c->startingValue;
	});
	reg_prop_ro(ft, "unidirectional", [](CapturePointData const * c) {
		return c->unidirectional != 0;
	});

	return ft;
}
