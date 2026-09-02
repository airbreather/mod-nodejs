#include "CtoJ.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(VehicleEntry const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<VehicleEntry const *>() {
	TypedTemplate<VehicleEntry const *> const ft = jctor();

	ft->SetClassName(jstr_intern("VehicleEntry"));

	reg_static_method(ft, "byId", [](uint32_t id) {
		return sVehicleStore.LookupEntry(id);
	});

	reg_prop_ro(ft, "id", [](VehicleEntry const * v) {
		return v->m_ID;
	});
	reg_prop_ro(ft, "flags", [](VehicleEntry const * v) {
		return v->m_flags;
	});
	reg_prop_ro(ft, "turnSpeed", [](VehicleEntry const * v) {
		return v->m_turnSpeed;
	});
	reg_prop_ro(ft, "pitchSpeed", [](VehicleEntry const * v) {
		return v->m_pitchSpeed;
	});
	reg_prop_ro(ft, "pitchMin", [](VehicleEntry const * v) {
		return v->m_pitchMin;
	});
	reg_prop_ro(ft, "pitchMax", [](VehicleEntry const * v) {
		return v->m_pitchMax;
	});
	reg_prop_ro(ft, "seatId0", [](VehicleEntry const * v) {
		return v->m_seatID[0];
	});
	reg_prop_ro(ft, "seatId1", [](VehicleEntry const * v) {
		return v->m_seatID[1];
	});
	reg_prop_ro(ft, "seatId2", [](VehicleEntry const * v) {
		return v->m_seatID[2];
	});
	reg_prop_ro(ft, "seatId3", [](VehicleEntry const * v) {
		return v->m_seatID[3];
	});
	reg_prop_ro(ft, "seatId4", [](VehicleEntry const * v) {
		return v->m_seatID[4];
	});
	reg_prop_ro(ft, "seatId5", [](VehicleEntry const * v) {
		return v->m_seatID[5];
	});
	reg_prop_ro(ft, "seatId6", [](VehicleEntry const * v) {
		return v->m_seatID[6];
	});
	reg_prop_ro(ft, "seatId7", [](VehicleEntry const * v) {
		return v->m_seatID[7];
	});
	reg_prop_ro(ft, "mouseLookOffsetPitch", [](VehicleEntry const * v) {
		return v->m_mouseLookOffsetPitch;
	});
	reg_prop_ro(ft, "cameraFadeDistScalarMin", [](VehicleEntry const * v) {
		return v->m_cameraFadeDistScalarMin;
	});
	reg_prop_ro(ft, "cameraFadeDistScalarMax", [](VehicleEntry const * v) {
		return v->m_cameraFadeDistScalarMax;
	});
	reg_prop_ro(ft, "cameraPitchOffset", [](VehicleEntry const * v) {
		return v->m_cameraPitchOffset;
	});
	reg_prop_ro(ft, "facingLimitRight", [](VehicleEntry const * v) {
		return v->m_facingLimitRight;
	});
	reg_prop_ro(ft, "facingLimitLeft", [](VehicleEntry const * v) {
		return v->m_facingLimitLeft;
	});
	reg_prop_ro(ft, "msslTrgtTurnLingering", [](VehicleEntry const * v) {
		return v->m_msslTrgtTurnLingering;
	});
	reg_prop_ro(ft, "msslTrgtPitchLingering", [](VehicleEntry const * v) {
		return v->m_msslTrgtPitchLingering;
	});
	reg_prop_ro(ft, "msslTrgtMouseLingering", [](VehicleEntry const * v) {
		return v->m_msslTrgtMouseLingering;
	});
	reg_prop_ro(ft, "msslTrgtEndOpacity", [](VehicleEntry const * v) {
		return v->m_msslTrgtEndOpacity;
	});
	reg_prop_ro(ft, "msslTrgtArcSpeed", [](VehicleEntry const * v) {
		return v->m_msslTrgtArcSpeed;
	});
	reg_prop_ro(ft, "msslTrgtArcRepeat", [](VehicleEntry const * v) {
		return v->m_msslTrgtArcRepeat;
	});
	reg_prop_ro(ft, "msslTrgtArcWidth", [](VehicleEntry const * v) {
		return v->m_msslTrgtArcWidth;
	});
	reg_prop_ro(ft, "msslTrgtImpactRadius0", [](VehicleEntry const * v) {
		return v->m_msslTrgtImpactRadius[0];
	});
	reg_prop_ro(ft, "msslTrgtImpactRadius1", [](VehicleEntry const * v) {
		return v->m_msslTrgtImpactRadius[1];
	});
	reg_prop_ro(ft, "msslTrgtArcTexture", [](VehicleEntry const * v) {
		return v->m_msslTrgtArcTexture;
	});
	reg_prop_ro(ft, "msslTrgtImpactTexture", [](VehicleEntry const * v) {
		return v->m_msslTrgtImpactTexture;
	});
	reg_prop_ro(ft, "msslTrgtImpactModel0", [](VehicleEntry const * v) {
		return v->m_msslTrgtImpactModel[0];
	});
	reg_prop_ro(ft, "msslTrgtImpactModel1", [](VehicleEntry const * v) {
		return v->m_msslTrgtImpactModel[1];
	});
	reg_prop_ro(ft, "cameraYawOffset", [](VehicleEntry const * v) {
		return v->m_cameraYawOffset;
	});
	reg_prop_ro(ft, "uiLocomotionType", [](VehicleEntry const * v) {
		return v->m_uiLocomotionType;
	});
	reg_prop_ro(ft, "msslTrgtImpactTexRadius", [](VehicleEntry const * v) {
		return v->m_msslTrgtImpactTexRadius;
	});
	reg_prop_ro(ft, "uiSeatIndicatorType", [](VehicleEntry const * v) {
		return v->m_uiSeatIndicatorType;
	});
	reg_prop_ro(ft, "powerDisplayId", [](VehicleEntry const * v) {
		return v->m_powerDisplayId;
	});

	return ft;
}
