#include <v8-local-handle.h>

#include "CtoJ.h"
#include "JtoC.h"
#include "MotionMaster.h"

template<>
std::optional<ChaseAngle> cval<ChaseAngle>(v8::Local<v8::Value> const v) {
	if (auto const angle_only = cval<float>(v)) {
		return std::optional{ChaseAngle(*angle_only)};
	}
	if (v->IsObject()) {
		auto const obj = v.As<v8::Object>();
		auto const angle = cval<float>(obj, "angle");
		auto const tolerance = cval<float>(obj, "tolerance");
		if (angle) {
			return std::optional{ChaseAngle(*angle, tolerance.value_or(M_PI_4))};
		}
	}
	return std::nullopt;
}
