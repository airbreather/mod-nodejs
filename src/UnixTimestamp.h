#ifndef MOD_NODEJS_UNIXTIMESTAMP_H
#define MOD_NODEJS_UNIXTIMESTAMP_H

#include <chrono>

struct UnixTimestamp {
	double epoch_milliseconds = 0;

	UnixTimestamp() = default;
	explicit constexpr UnixTimestamp(double t);
	static UnixTimestamp from_epoch_milliseconds(double t);

	static UnixTimestamp from_time_t_seconds(time_t seconds);
	[[nodiscard]] time_t to_time_t_seconds() const;

	template <typename Duration = std::chrono::utc_clock::duration>
	static UnixTimestamp from_chrono(Duration t) {
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(t);
		return UnixTimestamp::from_epoch_milliseconds(ms.count());
	}
	template <typename Duration = std::chrono::utc_clock::duration>
	static Duration to_chrono(UnixTimestamp t) {
		auto ms = std::chrono::duration<double, std::milli>{t.epoch_milliseconds};
		return std::chrono::duration_cast<Duration>(ms);
	}
};

#endif //MOD_NODEJS_UNIXTIMESTAMP_H
