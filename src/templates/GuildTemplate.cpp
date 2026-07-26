#include <optional>
#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "DatabaseWorkerPool.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "NodePropertySystem.h"
#include "ObjectGuid.h"
#include "Database/DatabaseEnv.h"

JVAL_CVAL_TMPLS_RW(Guild)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Guild *>() {
	TypedTemplate<Guild *> const ft = jctor();

	ft->SetClassName(jstr_intern("Guild"));

	reg_prop_ro(ft, "id", [](Guild * guild) {
		return guild->GetId();
	});
	reg_prop_ro(ft, "leaderGuid", [](Guild * guild) {
		return guild->GetLeaderGUID();
	});
	reg_prop_ro(ft, "memberCount", [](Guild * guild) {
		return guild->GetMemberCount();
	});
	reg_prop_ro(ft, "members", [](Guild * guild) {
		return jmap(guild->GetUnorderedMembers());
	});
	reg_prop_ro(ft, "totalBankMoney", [](Guild * guild) {
		return guild->GetTotalBankMoney();
	});
	reg_prop_ro(ft, "createdDate", [](Guild * guild) {
		return UnixTimestamp(guild->GetCreatedDate());
	});

	reg_method(ft, "getMemberByGuid", [](Guild * guild, ObjectGuid const guid) {
		return guild->GetMember(guid);
	});
	reg_method(ft, "getMemberByName", [](Guild * guild, std::string const name) {
		return guild->GetMember(name);
	});

	reg_static_method(ft, "byLeaderGuid", [](ObjectGuid const guid) {
		return sGuildMgr->GetGuildByLeader(guid);
	});
	reg_static_method(ft, "byName", [](std::string name) {
		return sGuildMgr->GetGuildByName(name);
	});
	reg_static_method(ft, "byId", [](uint32_t const id) {
		return sGuildMgr->GetGuildById(id);
	});

	reg_prop(ft, "name",
		[](Guild * g) { return g->GetName(); },
		[](Guild * g, std::string const name) { g->SetName(name); }
	);
	reg_prop(ft, "motd",
		[](Guild * g) { return g->GetMOTD(); },
		[](Guild * g, std::string const motd) { g->SetMOTD(motd); }
	);
	reg_prop(ft, "info",
		[](Guild * g) { return g->GetInfo(); },
		[](Guild * g, std::string const info) { g->SetInfo(info); }
	);

	reg_method(ft, "addMember", [](Guild * g, ObjectGuid const guid, std::optional<uint8_t> const rank) {
		g->AddMember(guid, rank.value_or(GUILD_RANK_NONE));
	});
	reg_method(ft, "removeMember", [](Guild * g, ObjectGuid const guid, std::optional<bool> const kicked) {
		g->DeleteMember(guid, false, kicked.value_or(false));
	});
	reg_method(ft, "disband", [](Guild * g) {
		g->Disband();
	});
	reg_method(ft, "getMemberByGuid", [](Guild * guild, ObjectGuid const guid) {
		return guild->GetMember(guid);
	});
	reg_method(ft, "getMemberByName", [](Guild * guild, std::string const name) {
		return guild->GetMember(name);
	});
	reg_method(ft, "modifyBankMoney", [](Guild * guild, int64_t const money) {
		auto const trans = CharacterDatabase.BeginTransaction();
		auto const success = guild->ModifyBankMoney(trans, static_cast<uint64_t>(money), money >= 0);
		CharacterDatabase.CommitTransaction(trans);
		return success;
	});
	// TODO: there was more here, some of which I haven't even gotten around to
	// considering whether or not to pull back in, and how they should look if so:
	// - changeMemberRank
	// - setLeader
	// - setBankTabText
	// - sendPacket
	// - sendPacketToRanked
	// - updateMemberData
	// - sendMessage
	// - massInviteToEvent
	// - swapItems
	// - swapItemsWithInventory
	// - resetTimes

	return ft;
}
