#include "AccountMgr.h"
#include "AccountWrapper.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(AccountWrapper);

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<AccountWrapper *>() {
	TypedTemplate<AccountWrapper *> const ft = jctor<AccountWrapper *>();

	ft->SetClassName(jstr_intern("Account"));

	reg_static_method(ft, "byId", [](uint32_t id) {
		// don't proactively spend a database hit to look it up. exists() is there if they need it, and all noteworthy
		// operations look it up implicitly no matter what anyway.
		return jmove(new AccountWrapper{id});
	});
	reg_static_method(ft, "byName", [](std::string name) {
		// don't proactively spend a database hit to look it up. exists() is there if they need it, and all noteworthy
		// operations look it up implicitly no matter what anyway.
		//
		// admittedly, this is not as compelling for "byName" as it is for "byId", but it's still marginally useful to
		// have an object that makes no database queries on conditional branches that happen to only check the name.
		return jmove(new AccountWrapper{std::move(name)});
	});
	reg_static_method(ft, "create", [](std::string name, std::string password, std::optional<std::string> email) -> v8::Local<v8::Value> {
		switch (auto res = sAccountMgr->CreateAccount(name, std::move(password), email ? std::move(*email) : "")) {
			case AOR_OK:
				return jmove(new AccountWrapper{std::move(name)});
			default:
				return jval(res);
		}
	});

	reg_prop_ro(ft, "exists", [](AccountWrapper * a) {
		return a->get_id(true) != nullptr;
	});
	reg_prop_ro(ft, "id", [](AccountWrapper * a) {
		if (auto id = a->get_id()) {
			return *id;
		}
		jthrow("account does not exist!");
		return 0u;
	});
	reg_prop_ro(ft, "name", [](AccountWrapper * a) -> std::string const & {
		if (auto name = a->get_name()) {
			return *name;
		}
		jthrow("account does not exist!");
		static std::string s{};
		return s;
	});
	reg_prop_ro(ft, "securityLevel", [](AccountWrapper * a) {
		if (auto id = a->get_id()) {
			return sAccountMgr->GetSecurity(*id);
		}
		// throw here: "account has player-level security" fallback could mean "account is a player". not graceful.
		jthrow("account does not exist!");
		return 0u;
	});
	reg_prop_ro(ft, "characterCount", [](AccountWrapper * a) {
		if (auto id = a->get_id()) {
			return sAccountMgr->GetCharactersCount(*id);
		}
		// throw here: "account has no characters" fallback could mean "account has room for more". not graceful.
		jthrow("account does not exist!");
		return 0u;
	});

	reg_method(ft, "delete", [](AccountWrapper * a) {
		if (auto id = a->get_id()) {
			auto ret = sAccountMgr->DeleteAccount(*id);
			if (ret == AOR_OK) {
				a->invalidate_cache();
			}
			return ret;
		}
		return AOR_NAME_NOT_EXIST;
	});
	reg_method(ft, "changeName", [](AccountWrapper * a, std::string new_name, std::string new_password) {
		auto ret = AOR_NAME_NOT_EXIST;
		if (auto id = a->get_id()) {
			ret = sAccountMgr->ChangeUsername(*id, new_name, std::move(new_password));
			if (ret == AOR_OK) {
				if (std::holds_alternative<std::string>(a->query_by)) {
					std::variant<std::string, uint32_t> v{std::move(new_name)};
					a->query_by.swap(v);
				} else {
					// if we've looked up the name before, it's *definitely* stale now.
					a->invalidate_cache();
				}
			}
		}
		return ret;
	});
	reg_method(ft, "changePassword", [](AccountWrapper * a, std::string new_password) {
		if (auto id = a->get_id()) {
			return sAccountMgr->ChangePassword(*id, std::move(new_password));
		}
		return AOR_NAME_NOT_EXIST;
	});
	reg_method(ft, "changeEmail", [](AccountWrapper * a, std::string new_email) {
		if (auto id = a->get_id()) {
			return sAccountMgr->ChangeEmail(*id, std::move(new_email));
		}
		return AOR_NAME_NOT_EXIST;
	});
	reg_method(ft, "checkPassword", [](AccountWrapper * a, std::string password) {
		if (auto id = a->get_id()) {
			return sAccountMgr->CheckPassword(*id, std::move(password));
		}
		// no need to throw here: "password is invalid" is a very graceful fallback.
		//jthrow("account does not exist!");
		return false;
	});
	reg_method(ft, "securityLevelOnRealm", [](AccountWrapper * a, int32_t realm_id) {
		if (auto id = a->get_id()) {
			return sAccountMgr->GetSecurity(*id, realm_id);
		}
		// throw here: "account has player-level security" fallback could mean "account is a player". not graceful.
		jthrow("account does not exist!");
		return 0u;
	});
	reg_method(ft, "hasPermissionOnRealm", [](AccountWrapper * a, uint32_t permission_id, uint32_t realm_id) {
		if (auto id = a->get_id()) {
			return sAccountMgr->HasPermission(*id, permission_id, realm_id);
		}
		// no need to throw here: "does not have permission" is a very graceful fallback.
		//jthrow("account does not exist!");
		return false;
	});
	reg_method(ft, "invalidateCache", [](AccountWrapper * a) {
		a->invalidate_cache();
	});

	return ft;
}
