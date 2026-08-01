#include <optional>
#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "Player.h"

JVAL_CVAL_TMPLS_RW(MailDraft)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<MailDraft *>() {
	TypedTemplate<MailDraft *> const ft = jctor([](std::string subject, std::string text) {
		return new MailDraft(std::move(subject), std::move(text));
	});

	ft->SetClassName(jstr_intern("MailDraft"));

	reg_method(ft, "addMoney", [](MailDraft * m, uint32_t money) {
		m->AddMoney(money);
		return m;
	});
	reg_method(ft, "addCOD", [](MailDraft * m, uint32_t cod) {
		m->AddCOD(cod);
		return m;
	});
	reg_method(ft, "addItem", [](MailDraft * m, Item * item) {
		m->AddItem(item);
		return m;
	});
	reg_method(ft, "createAndAddItem", [](MailDraft * m, uint32_t entry, std::optional<uint32_t> const amount) {
		auto const item = Item::CreateItem(entry, amount.value_or(1));
		NodeJs::transactional(CharacterDatabase, [item](auto trans) {
			item->SaveToDB(std::move(trans));
		});
		m->AddItem(item);
		return item->GetGUID();
	});
	reg_method(ft, "send", [](MailDraft * m, ObjectGuid receiver_guid, MailSender const * sender, std::optional<MailCheckMask> checked, std::optional<uint32_t> deliver_delay, std::optional<uint32_t> custom_expiration) {
		NodeJs::transactional(CharacterDatabase, [m, receiver_guid, sender, checked, deliver_delay, custom_expiration](auto trans) {
			// if the receiver is online, they'll need to get a packet, but you can send mail to players
			// even if they're offline, so this is a less-common instance where null is perfectly fine.
			auto const receiver_player = ObjectAccessor::FindConnectedPlayer(receiver_guid);
			m->SendMailTo(
				std::move(trans),
				MailReceiver(receiver_player, receiver_guid.GetCounter()),
				*sender,
				checked.value_or(MAIL_CHECK_MASK_NONE),
				deliver_delay.value_or(0),
				custom_expiration.value_or(0)
			);
		});
	});
	reg_method(ft, "sendReturnToSender", [](MailDraft * m, uint32_t sender_acc, ObjectGuid sender_guid, ObjectGuid receiver_guid) {
		NodeJs::transactional(CharacterDatabase, [m, sender_acc, sender_guid, receiver_guid](auto trans) {
			m->SendReturnToSender(sender_acc, sender_guid.GetCounter(), receiver_guid.GetCounter(), std::move(trans));
		});
	});

	return ft;
}
