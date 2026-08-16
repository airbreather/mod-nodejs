#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "Unit.h"
#include "Vehicle.h"

JVAL_CVAL_TMPLS_RW(Vehicle)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Vehicle *>() {
	TypedTemplate<Vehicle *> const ft = jctor();

	ft->SetClassName(jstr_intern("Vehicle"));

	reg_prop_ro(ft, "vehicleInfo", [](Vehicle * v) {
		return v->GetVehicleInfo();
	});
	reg_prop_ro(ft, "availableSeatCount", [](Vehicle * v) {
		return v->GetAvailableSeatCount();
	});
	reg_prop_ro(ft, "owner", [](Vehicle * v) {
		return v->GetBase();
	});

	reg_method(ft, "getPassenger", [](Vehicle * v, int8_t const seatId) {
		return v->GetPassenger(seatId);
	});
	reg_method(ft, "isOnBoard", [](Vehicle * v, Unit * passenger) {
		return passenger->IsOnVehicle(v->GetBase());
	});
	reg_method(ft, "addPassenger", [](Vehicle * v, Unit * passenger, std::optional<int8_t> const seatIdOpt) {
		v->AddPassenger(passenger, seatIdOpt.value_or(-1));
	});
	reg_method(ft, "removePassenger", [](Vehicle * v, Unit * passenger) {
		v->RemovePassenger(passenger);
	});

	return ft;
}
