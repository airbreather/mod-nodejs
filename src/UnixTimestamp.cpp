#include "UnixTimestamp.h"

constexpr UnixTimestamp::UnixTimestamp(double t) : epoch_milliseconds(t) {}

UnixTimestamp UnixTimestamp::from_epoch_milliseconds(double t) {
	return UnixTimestamp{t};
}

UnixTimestamp UnixTimestamp::from_time_t_seconds(time_t seconds) {
	return UnixTimestamp{static_cast<double>(seconds) * 1e3};
}

time_t UnixTimestamp::to_time_t_seconds() const {
	return static_cast<time_t>(epoch_milliseconds / 1e3);
}
