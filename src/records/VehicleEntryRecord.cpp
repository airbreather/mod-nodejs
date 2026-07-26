#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<VehicleEntry const &>(VehicleEntry const & p) {
	return jobj(
		jprop("id", p.m_ID),
		jprop("flags", p.m_flags),
		jprop("turnSpeed", p.m_turnSpeed),
		jprop("pitchSpeed", p.m_pitchSpeed),
		jprop("pitchMin", p.m_pitchMin),
		jprop("pitchMax", p.m_pitchMax),
		jprop("seatId", jarr(p.m_seatID)),
		jprop("mouseLookOffsetPitch", p.m_mouseLookOffsetPitch),
		jprop("cameraFadeDistScalarMin", p.m_cameraFadeDistScalarMin),
		jprop("cameraFadeDistScalarMax", p.m_cameraFadeDistScalarMax),
		jprop("cameraPitchOffset", p.m_cameraPitchOffset),
		jprop("facingLimitRight", p.m_facingLimitRight),
		jprop("facingLimitLeft", p.m_facingLimitLeft),
		jprop("msslTrgtTurnLingering", p.m_msslTrgtTurnLingering),
		jprop("msslTrgtPitchLingering", p.m_msslTrgtPitchLingering),
		jprop("msslTrgtMouseLingering", p.m_msslTrgtMouseLingering),
		jprop("msslTrgtEndOpacity", p.m_msslTrgtEndOpacity),
		jprop("msslTrgtArcSpeed", p.m_msslTrgtArcSpeed),
		jprop("msslTrgtArcRepeat", p.m_msslTrgtArcRepeat),
		jprop("msslTrgtArcWidth", p.m_msslTrgtArcWidth),
		jprop("msslTrgtImpactRadius", jarr(p.m_msslTrgtImpactRadius)),
		jprop("msslTrgtArcTexture", p.m_msslTrgtArcTexture),
		jprop("msslTrgtImpactTexture", p.m_msslTrgtImpactTexture),
		jprop("msslTrgtImpactModel", jarr(p.m_msslTrgtImpactModel)),
		jprop("cameraYawOffset", p.m_cameraYawOffset),
		jprop("uiLocomotionType", p.m_uiLocomotionType),
		jprop("msslTrgtImpactTexRadius", p.m_msslTrgtImpactTexRadius),
		jprop("uiSeatIndicatorType", p.m_uiSeatIndicatorType),
		jprop("powerDisplayId", p.m_powerDisplayId)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<VehicleEntry const>(VehicleEntry const p) {
	return jval<VehicleEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<VehicleEntry>(VehicleEntry const p) {
	return jval<VehicleEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<VehicleEntry const *>(VehicleEntry const * p) {
	return p ? jval<VehicleEntry const &>(*p) : jnull();
}

template<>
[[nodiscard]] std::optional<VehicleEntry const *> cval<VehicleEntry const *>(v8::Local<v8::Value> const v) {
	return centry_lookup(v, sVehicleStore);
}
