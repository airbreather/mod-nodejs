#include <v8-local-handle.h>

#include "CtoJ.h"
#include "Group.h"
#include "MotionMaster.h"
#include "NodeJPropHelpers.h"

template<>
std::optional<ChaseRange> cval<ChaseRange>(v8::Local<v8::Value> const v) {
	if (auto const distance_only = cval<float>(v)) {
		return std::optional{ChaseRange(*distance_only)};
	}
	if (v->IsObject()) {
		auto const obj = v.As<v8::Object>();
		auto const min_range = cval<float>(obj, "minRange");
		auto const max_range = cval<float>(obj, "maxRange");
		auto const min_tolerance = cval<float>(obj, "minTolerance");
		auto const max_tolerance = cval<float>(obj, "maxTolerance");
		if (min_range && max_range) {
			if (min_tolerance && max_tolerance) {
				return std::optional{ChaseRange(*min_range, *max_range, *min_tolerance, *max_tolerance)};
			}
			return std::optional{ChaseRange(*min_range, *max_range)};
		}
	}
	return std::nullopt;
}
