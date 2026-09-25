#include "CtoJ.h"
#include "DurationWrapper.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using TransportData = decltype(GameObjectTemplate().transport);
JVAL_CVAL_TMPLS_RO(TransportData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<TransportData const *>() {
	TypedTemplate<TransportData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("TransportData"));

	reg_prop_ro(ft, "pauseAtTime", [](TransportData const * t) {
		return DurationWrapper::from_milliseconds(t->pauseAtTime);
	});
	reg_prop_ro(ft, "startOpen", [](TransportData const * t) {
		return t->startOpen != 0;
	});
	reg_prop_ro(ft, "autoCloseTime", [](TransportData const * t) {
		return DurationWrapper::from_milliseconds(t->autoCloseTime);
	});
	reg_prop_ro(ft, "pause1EventId", [](TransportData const * t) {
		return t->pause1EventID;
	});
	reg_prop_ro(ft, "pause2EventId", [](TransportData const * t) {
		return t->pause2EventID;
	});

	return ft;
}
