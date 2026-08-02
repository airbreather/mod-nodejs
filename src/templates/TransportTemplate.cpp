#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "Entities/Transport/Transport.h"

JVAL_CVAL_TMPLS_RW(Transport)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Transport *>() {
	TypedTemplate<Transport *> const ft = jctor();

	ft->SetClassName(jstr_intern("Transport"));
	ft.safe_inherit<GameObject *>();

	reg_prop_ro(ft, "isMotionTransport", [](Transport * transport) {
		return dynamic_cast<MotionTransport *>(transport) != nullptr;
	});
	reg_prop_ro(ft, "passengers", [](Transport * transport) {
		return jarr(transport->GetPassengers());
	});

	reg_method(ft, "addPassenger", [](Transport * t, WorldObject * passenger, std::optional<bool> const withAll) {
		t->AddPassenger(passenger, withAll.value_or(false));
	});
	reg_method(ft, "removePassenger", [](Transport * t, WorldObject * passenger, std::optional<bool> const withAll) {
		t->RemovePassenger(passenger, withAll.value_or(false));
	});
	reg_method(ft, "enableMovement", [](Transport * t, bool const enabled) {
		if (auto const motionTrans = dynamic_cast<MotionTransport *>(t)) {
			motionTrans->EnableMovement(enabled);
		}
	});

	return ft;
}
