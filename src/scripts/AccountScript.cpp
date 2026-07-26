#include "AccountScript.h"

#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_Account : public AccountScript {
public:
	NODEJS_Account() : AccountScript("NODEJS_Account") {
	}

	void OnAccountLogin(uint32_t const accountId) override {
		NodeJs::invoke_hook("account:login", jarg("accountId", accountId));
	}
	void OnBeforeAccountDelete(uint32_t const accountId) override {
		NodeJs::invoke_hook("account:before-delete", jarg("accountId", accountId));
	}
	void OnLastIpUpdate(uint32_t const accountId, std::string const ip) override {
		NodeJs::invoke_hook("account:last-ip-update", jarg("accountId", accountId), jarg("ip", ip));
	}
	void OnFailedAccountLogin(uint32_t const accountId) override {
		NodeJs::invoke_hook("account:failed-login", jarg("accountId", accountId));
	}
	void OnEmailChange(uint32_t const accountId) override {
		NodeJs::invoke_hook("account:email-change", jarg("accountId", accountId));
	}
	void OnFailedEmailChange(uint32_t const accountId) override {
		NodeJs::invoke_hook("account:failed-email-change", jarg("accountId", accountId));
	}
	void OnPasswordChange(uint32_t const accountId) override {
		NodeJs::invoke_hook("account:password-change", jarg("accountId", accountId));
	}
	void OnFailedPasswordChange(uint32_t const accountId) override {
		NodeJs::invoke_hook("account:failed-password-change", jarg("accountId", accountId));
	}
	[[nodiscard]] bool CanAccountCreateCharacter(uint32_t const accountId, uint8_t const charRace, uint8_t const charClass) override {
		return NodeJs::invoke_hook_t("account:can-create-character", AccountScript::CanAccountCreateCharacter(accountId, charRace, charClass)
			, jarg("accountId", accountId), jarg("race", charRace), jarg("clazz", charClass));
	}
};

void AddSC_Account() {
	new NODEJS_Account();
}
