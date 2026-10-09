#include "AccountWrapper.h"

#include "AccountMgr.h"

std::string const * AccountWrapper::get_name(bool only_if_valid) {
	if (!only_if_valid && std::holds_alternative<std::string>(query_by)) {
		return &std::get<std::string>(query_by);
	}
	return resolve_cached() ? &resolved->first : nullptr;
}

uint32_t const * AccountWrapper::get_id(bool only_if_valid) {
	if (!only_if_valid && std::holds_alternative<uint32_t>(query_by)) {
		return &std::get<uint32_t>(query_by);
	}
	return resolve_cached() ? &resolved->second : nullptr;
}

void AccountWrapper::invalidate_cache() {
	resolved.reset();
}

bool AccountWrapper::resolve_cached() {
	return resolved || resolve();
}

bool AccountWrapper::resolve() {
	if (std::holds_alternative<std::string>(query_by)) {
		auto name = std::get<std::string>(query_by);
		if (auto id = sAccountMgr->GetId(name)) {
			resolved = { name, id };
			return true;
		}
	} else if (std::holds_alternative<uint32_t>(query_by)) {
		auto id = std::get<uint32_t>(query_by);
		if (std::string name; sAccountMgr->GetName(id, name)) {
			resolved = { std::move(name), id };
			return true;
		}
	}
	return false;
}
