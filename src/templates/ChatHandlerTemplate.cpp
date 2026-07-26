#include <optional>
#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "ObjectGuid.h"
#include "Chat/Chat.h"

JVAL_CVAL_TMPLS_RW(ChatHandler)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<ChatHandler *>() {
	TypedTemplate<ChatHandler *> const ft = jctor();

	ft->SetClassName(jstr_intern("ChatHandler"));

	reg_prop_ro(ft, "player", [](ChatHandler * ch) {
		return ch->GetPlayer();
	});
	reg_prop_ro(ft, "selectedPlayer", [](ChatHandler * ch) {
		return ch->getSelectedPlayer();
	});
	reg_prop_ro(ft, "selectedPlayerOrSelf", [](ChatHandler * ch) {
		return ch->getSelectedPlayerOrSelf();
	});
	reg_prop_ro(ft, "selectedCreature", [](ChatHandler * ch) {
		return ch->getSelectedCreature();
	});
	reg_prop_ro(ft, "selectedUnit", [](ChatHandler * ch) {
		return ch->getSelectedUnit();
	});
	reg_prop_ro(ft, "selectedObject", [](ChatHandler * ch) {
		return ch->getSelectedObject();
	});
	reg_prop_ro(ft, "isConsole", [](ChatHandler * ch) {
		return ch->IsConsole();
	});
	reg_prop_ro(ft, "hasSentErrorMessage", [](ChatHandler * ch) {
		return ch->HasSentErrorMessage();
	});

	reg_method(ft, "isAvailable", [](ChatHandler * h, uint32_t const securityLevel) {
		return h->IsAvailable(securityLevel);
	});

	reg_method(ft, "sendSysMessageStored", [](ChatHandler * h, uint32_t const entryId) {
		h->PSendSysMessage(entryId);
	});
	reg_method(ft, "sendSysMessageInline", [](ChatHandler * h, std::string text) {
		h->SendSysMessage(text);
	});
	reg_method(ft, "sendGlobalSysMessage", [](ChatHandler * h, std::string text) {
		h->SendGlobalSysMessage(text.c_str());
	});
	reg_method(ft, "sendGlobalGMSysMessage", [](ChatHandler * h, std::string text) {
		h->SendGlobalGMSysMessage(text.c_str());
	});
	reg_method(ft, "hasLowerSecurity", [](ChatHandler * h, Player * player, std::optional<ObjectGuid> guid, std::optional<bool> const strong) {
		return h->HasLowerSecurity(player, guid.value_or(ObjectGuid::Empty), strong.value_or(false));
	});
	reg_method(ft, "hasLowerSecurityAccount", [](ChatHandler * h, uint32_t const account, std::optional<bool> const strong) {
		return h->HasLowerSecurityAccount(nullptr, account, strong.value_or(false));
	});

	return ft;
}
