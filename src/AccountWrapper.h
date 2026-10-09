#ifndef MOD_NODEJS_ACCOUNTWRAPPER_H
#define MOD_NODEJS_ACCOUNTWRAPPER_H

#include <cstdint>
#include <optional>
#include <string>
#include <variant>

struct AccountWrapper {
	std::variant<std::string, uint32_t> query_by;

	explicit AccountWrapper(uint32_t id) : query_by(id) {}
	explicit AccountWrapper(std::string name) : query_by(std::move(name)) {}

	std::string const * get_name(bool only_if_valid = false);
	uint32_t const * get_id(bool only_if_valid = false);

	void invalidate_cache();

private:
	std::optional<std::pair<std::string, uint32_t>> resolved{};

	bool resolve_cached();
	bool resolve();
};

#endif //MOD_NODEJS_ACCOUNTWRAPPER_H
