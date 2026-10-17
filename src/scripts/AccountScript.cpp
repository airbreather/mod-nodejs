#include "AccountScript.h"

#include "NodeJs.h"

class NODEJS_Account : public AccountScript {
public:
	NODEJS_Account() : AccountScript("NODEJS_Account") {
	}

	void OnAccountLogin(uint32_t const accountId) override {
		NodeJs::invoke_hook("account:login"
			, jprop("accountId", accountId));
	}
	void OnBeforeAccountDelete(uint32_t const accountId) override {
		NodeJs::invoke_hook("account:before-delete"
			, jprop("accountId", accountId));
	}
	void OnLastIpUpdate(uint32_t const accountId, std::string const ip) override {
		NodeJs::invoke_hook("account:last-ip-update"
			, jprop("accountId", accountId), jprop("ip", ip));
	}
	void OnFailedAccountLogin(uint32_t const accountId) override {
		NodeJs::invoke_hook("account:failed-login"
			, jprop("accountId", accountId));
	}
	void OnEmailChange(uint32_t const accountId) override {
		NodeJs::invoke_hook("account:email-change"
			, jprop("accountId", accountId));
	}
	void OnFailedEmailChange(uint32_t const accountId) override {
		NodeJs::invoke_hook("account:failed-email-change"
			, jprop("accountId", accountId));
	}
	void OnPasswordChange(uint32_t const accountId) override {
		NodeJs::invoke_hook("account:password-change"
			, jprop("accountId", accountId));
	}
	void OnFailedPasswordChange(uint32_t const accountId) override {
		NodeJs::invoke_hook("account:failed-password-change"
			, jprop("accountId", accountId));
	}
	[[nodiscard]] bool CanAccountCreateCharacter(uint32_t const accountId, uint8_t const charRace, uint8_t const charClass) override {
		return NodeJs::invoke_hook_t("account:can-create-character", AccountScript::CanAccountCreateCharacter(accountId, charRace, charClass)
			, jprop("accountId", accountId), jprop("race", charRace), jprop("clazz", charClass));
	}
};

void AddSC_Account() {
	new NODEJS_Account();
}
