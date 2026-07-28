#include <v8-local-handle.h>
#include <v8-template.h>

#include "Config.h"
#include "CtoJ.h"
#include "NodePropertySystem.h"

// static methods only
template<>
v8::Local<v8::FunctionTemplate> jcreate_template<ConfigMgr const *>() {
	auto const ft = jctor();
	ft->SetClassName(jstr_intern("Config"));

	reg_static_method(ft, "getArguments", [] {
		return jarr(sConfigMgr->GetArguments());
	});
	reg_static_method(ft, "getConfigPath", [] {
		return sConfigMgr->GetConfigPath();
	});
	reg_static_method(ft, "getFilename", [] {
		return sConfigMgr->GetFilename();
	});
	reg_static_method(ft, "getKeysStartingWith", [] (std::string const prefix) {
		return jarr(sConfigMgr->GetKeysByString(prefix));
	});
	reg_static_method(ft, "getBool", [] (std::string const key, std::optional<bool> const def, std::optional<bool> const show_logs) {
		return sConfigMgr->GetOption(key, def.value_or(false), show_logs.value_or(true));
	});
	reg_static_method(ft, "getString", [] (std::string const key, std::optional<std::string> const def, std::optional<bool> const show_logs) {
		return sConfigMgr->GetOption(key, def.value_or(""), show_logs.value_or(true));
	});
	reg_static_method(ft, "getFloat", [] (std::string const key, std::optional<float> const def, std::optional<bool> const show_logs) {
		return sConfigMgr->GetOption(key, def.value_or(0), show_logs.value_or(true));
	});
	reg_static_method(ft, "getU8", [] (std::string const key, std::optional<uint8_t> const def, std::optional<bool> const show_logs) {
		return sConfigMgr->GetOption(key, def.value_or(0), show_logs.value_or(true));
	});
	reg_static_method(ft, "getI8", [] (std::string const key, std::optional<int8_t> const def, std::optional<bool> const show_logs) {
		return sConfigMgr->GetOption(key, def.value_or(0), show_logs.value_or(true));
	});
	reg_static_method(ft, "getU16", [] (std::string const key, std::optional<uint16_t> const def, std::optional<bool> const show_logs) {
		return sConfigMgr->GetOption(key, def.value_or(0), show_logs.value_or(true));
	});
	reg_static_method(ft, "getI16", [] (std::string const key, std::optional<int16_t> const def, std::optional<bool> const show_logs) {
		return sConfigMgr->GetOption(key, def.value_or(0), show_logs.value_or(true));
	});
	reg_static_method(ft, "getU32", [] (std::string const key, std::optional<uint32_t> const def, std::optional<bool> const show_logs) {
		return sConfigMgr->GetOption(key, def.value_or(0), show_logs.value_or(true));
	});
	reg_static_method(ft, "getI32", [] (std::string const key, std::optional<int32_t> const def, std::optional<bool> const show_logs) {
		return sConfigMgr->GetOption(key, def.value_or(0), show_logs.value_or(true));
	});
	reg_static_method(ft, "getU64", [] (std::string const key, std::optional<uint64_t> const def, std::optional<bool> const show_logs) {
		return sConfigMgr->GetOption(key, def.value_or(0), show_logs.value_or(true));
	});
	reg_static_method(ft, "getI64", [] (std::string const key, std::optional<int64_t> const def, std::optional<bool> const show_logs) {
		return sConfigMgr->GetOption(key, def.value_or(0), show_logs.value_or(true));
	});

	return ft;
}
