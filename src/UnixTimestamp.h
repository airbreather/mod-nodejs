#ifndef MOD_NODEJS_UNIXTIMESTAMP_H
#define MOD_NODEJS_UNIXTIMESTAMP_H

#include <chrono>

#include "Duration.h"
#include "GameTime.h"

struct UnixTimestamp {
	double epoch_milliseconds = 0;

	UnixTimestamp() = default;
	explicit constexpr UnixTimestamp(double t);
	static UnixTimestamp from_epoch_milliseconds(double);
	static UnixTimestamp from_game_time_milliseconds(uint32_t);
	template <typename Duration = std::chrono::utc_clock::duration>
	static UnixTimestamp from_game_time(Duration t) {
		return from_chrono(GameTime::GetStartTime() + t);
	}

	static UnixTimestamp from_time_t_seconds(time_t);
	[[nodiscard]] time_t to_time_t_seconds() const;

	template <typename Duration = std::chrono::utc_clock::duration>
	static UnixTimestamp from_chrono(Duration t) {
		auto ms = std::chrono::duration_cast<Milliseconds>(t);
		return UnixTimestamp::from_epoch_milliseconds(ms.count());
	}
	template <typename Duration = std::chrono::utc_clock::duration>
	Duration to_chrono() const {
		auto ms = std::chrono::duration<double, std::milli>{epoch_milliseconds};
		return std::chrono::duration_cast<Duration>(ms);
	}
	template <typename Duration = std::chrono::utc_clock::duration>
	Duration::rep count() const {
		return to_chrono<Duration>().count();
	}
};

#endif //MOD_NODEJS_UNIXTIMESTAMP_H
