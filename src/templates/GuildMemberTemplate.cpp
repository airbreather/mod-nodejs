#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "Guild.h"
#include "NodePropertySystem.h"
#include "ObjectGuid.h"
#include "UnixTimestamp.h"

JVAL_CVAL_TMPLS_RW(Guild::Member)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Guild::Member *>() {
	TypedTemplate<Guild::Member *> const ft = jctor();

	ft->SetClassName(jstr_intern("GuildMember"));

	reg_prop_ro(ft, "playerGuid", [](Guild::Member * m) {
		return m->GetGUID();
	});
	reg_prop_ro(ft, "playerName", [](Guild::Member * m) {
		return m->GetName();
	});
	reg_prop_ro(ft, "clazz", [](Guild::Member * m) {
		return m->GetClass();
	});
	reg_prop_ro(ft, "level", [](Guild::Member * m) {
		return m->GetLevel();
	});
	reg_prop_ro(ft, "gender", [](Guild::Member * m) {
		return m->GetGender();
	});
	reg_prop_ro(ft, "accountId", [](Guild::Member * m) {
		return m->GetAccountId();
	});
	reg_prop_ro(ft, "logoutTime", [](Guild::Member * m) {
		return UnixTimestamp::from_chrono(
			std::chrono::seconds{m->GetLogoutTime()}
		);
	});
	reg_prop_ro(ft, "flags", [](Guild::Member * m) {
		// is it called "flags" or "status"? both are used interchangeably...
		return m->GetFlags();
	});
	reg_prop_ro(ft, "zoneId", [](Guild::Member * m) {
		return m->GetZoneId();
	});
	reg_prop_ro(ft, "isOnline", [](Guild::Member * m) {
		return m->IsOnline();
	});
	reg_prop_ro(ft, "remainingWithdrawalAllowedTodayTotal", [](Guild::Member * m) {
		return m->GetBankWithdrawValue(GUILD_BANK_MAX_TABS);
	});

	reg_method(ft, "remainingWithdrawalAllowedTodayOnTab", [](Guild::Member * m, uint8_t const tab) {
		return m->GetBankWithdrawValue(tab);
	});

	reg_prop(ft, "rankId",
		[](Guild::Member * m) { return m->GetRankId(); },
		[](Guild::Member * m, uint8_t const rank) { m->ChangeRank(rank); }
	);
	reg_prop(ft, "publicNote",
		[](Guild::Member * m) { return m->GetPublicNote(); },
		[](Guild::Member * m, std::string const note) { m->SetPublicNote(note); }
	);
	reg_prop(ft, "officerNote",
		[](Guild::Member * m) { return m->GetOfficerNote(); },
		[](Guild::Member * m, std::string const note) { m->SetOfficerNote(note); }
	);

	reg_method(ft, "refresh", [](Guild::Member * m) {
		if (auto const p = m->FindPlayer()) {
			m->SetStats(p);
		}
	});
	reg_method(ft, "updateLogoutTime", [](Guild::Member * m) {
		m->UpdateLogoutTime();
	});

	return ft;
}
