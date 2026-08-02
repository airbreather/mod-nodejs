#ifndef MOD_NODEJS_DURATIONWRAPPER_H
#define MOD_NODEJS_DURATIONWRAPPER_H

#include <chrono>

struct DurationWrapper {
	double milliseconds = 0;

	DurationWrapper() = default;
	explicit constexpr DurationWrapper(double t);
	static DurationWrapper from_milliseconds(double t);

	template <typename Duration = std::chrono::utc_clock::duration>
	static DurationWrapper from_chrono(Duration t) {
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(t);
		return DurationWrapper::from_milliseconds(ms.count());
	}
	template <typename Duration = std::chrono::utc_clock::duration>
	Duration to_chrono() const {
		auto ms = std::chrono::duration<double, std::milli>{milliseconds};
		return std::chrono::duration_cast<Duration>(ms);
	}
	template <typename Duration = std::chrono::utc_clock::duration>
	Duration::rep count() const {
		return to_chrono<Duration>().count();
	}
};

#endif //MOD_NODEJS_DURATIONWRAPPER_H
