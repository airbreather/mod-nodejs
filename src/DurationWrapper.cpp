#include "DurationWrapper.h"

constexpr DurationWrapper::DurationWrapper(double t) : milliseconds(t) {}

DurationWrapper DurationWrapper::from_milliseconds(double t) {
	return DurationWrapper{t};
}
