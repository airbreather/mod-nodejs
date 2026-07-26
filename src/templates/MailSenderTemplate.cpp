#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "Define.h"
#include "NodePropertySystem.h"
#include "Player.h"

enum AuctionHouseId : uint8_t;

JVAL_CVAL_TMPLS_RW(MailSender)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<MailSender *>() {
	TypedTemplate<MailSender *> const ft = jctor([](MailMessageType messageType, uint32 sender_guidlow_or_entry, std::optional<MailStationery> stationery) {
		return new MailSender(messageType, sender_guidlow_or_entry, stationery.value_or(MAIL_STATIONERY_DEFAULT));
	});

	ft->SetClassName(jstr_intern("MailSender"));

	reg_prop_ro(ft, "messageType", [](MailSender * s) {
		return s->GetMailMessageType();
	});
	reg_prop_ro(ft, "senderId", [](MailSender * s) {
		return s->GetSenderId();
	});
	reg_prop_ro(ft, "stationery", [](MailSender * s) {
		return s->GetStationery();
	});

	reg_static_method(ft, "forCreature", [](uint32_t entry, std::optional<MailStationery> stationery) {
		return jnew<MailSender *>(MAIL_CREATURE, entry, stationery.value_or(MAIL_STATIONERY_DEFAULT));
	});
	reg_static_method(ft, "forPlayer", [](ObjectGuid guid, std::optional<MailStationery> stationery) {
		return jnew<MailSender *>(MAIL_NORMAL, guid.GetCounter(), stationery.value_or(MAIL_STATIONERY_DEFAULT));
	});
	reg_static_method(ft, "forGameObject", [](uint32_t entry, std::optional<MailStationery> stationery) {
		return jnew<MailSender *>(MAIL_GAMEOBJECT, entry, stationery.value_or(MAIL_STATIONERY_DEFAULT));
	});
	reg_static_method(ft, "forAuctionHouse", [](AuctionHouseId house, std::optional<MailStationery> stationery) {
		return jnew<MailSender *>(MAIL_AUCTION, house, stationery.value_or(MAIL_STATIONERY_AUCTION));
	});
	reg_static_method(ft, "forCalendarEvent", [](uint32_t entry, std::optional<MailStationery> stationery) {
		return jnew<MailSender *>(MAIL_CALENDAR, entry, stationery.value_or(MAIL_STATIONERY_DEFAULT));
	});

	return ft;
}
