#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "Channel.h"
#include "ChannelMgr.h"
#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "UnixTimestamp.h"
#include "Chat/Chat.h"

class Player;

JVAL_CVAL_TMPLS_RW(Channel)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Channel *>() {
	TypedTemplate<Channel *> const ft = jctor([](std::string name, uint32_t channel_id, uint32_t channel_db_id, std::optional<TeamId> team_id, std::optional<bool> announce, std::optional<bool> ownership) {
		return new Channel(name, channel_id, channel_db_id, team_id.value_or(TEAM_NEUTRAL), announce.value_or(true), ownership.value_or(true));
	});

	ft->SetClassName(jstr_intern("Channel"));

	reg_static_method(ft, "byName", [](std::string name, TeamId team_id) {
		return ChannelMgr::forTeam(team_id)->GetChannel(name, nullptr, false);
	});

	reg_prop_ro(ft, "name", [](Channel * c) {
		return c->GetName();
	});
	reg_prop_ro(ft, "channelId", [](Channel * c) {
		return c->GetChannelId();
	});
	reg_prop_ro(ft, "channelDBId", [](Channel * c) {
		return c->GetChannelDBId();
	});
	reg_prop_ro(ft, "isConstant", [](Channel * c) {
		return c->IsConstant();
	});
	reg_prop_ro(ft, "isAnnounce", [](Channel * c) {
		return c->IsAnnounce();
	});
	reg_prop_ro(ft, "isLFG", [](Channel * c) {
		return c->IsLFG();
	});
	reg_prop_ro(ft, "numPlayers", [](Channel * c) {
		return c->GetNumPlayers();
	});
	reg_prop_ro(ft, "flags", [](Channel * c) {
		return c->GetFlags();
	});

	reg_prop(ft, "password",
		[](Channel * c) { return c->GetPassword(); },
		[](Channel * c, auto val) { c->SetPassword(val); }
	);

	reg_method(ft, "hasFlag", [](Channel * c, uint8_t flag) {
		return c->HasFlag(flag);
	});
	reg_method(ft, "joinChannel", [](Channel * c, Player * player, std::string pass) {
		c->JoinChannel(player, pass);
	});
	reg_method(ft, "leaveChannel", [](Channel * c, Player * player, std::optional<bool> send) {
		c->LeaveChannel(player, send.value_or(true));
	});
	reg_method(ft, "kick", [](Channel * c, Player * player, std::string badname) {
		c->Kick(player, badname);
	});
	reg_method(ft, "ban", [](Channel * c, Player * player, std::string badname) {
		c->Ban(player, badname);
	});
	reg_method(ft, "addBan", [](Channel * c, ObjectGuid guid, UnixTimestamp time) {
		c->AddBan(guid, time.count<Seconds>());
	});
	reg_method(ft, "unBan", [](Channel * c, Player * player, std::string badname) {
		c->UnBan(player, badname);
	});
	reg_method(ft, "unBanById", [](Channel * c, ObjectGuid guid) {
		c->UnBan(guid);
	});
	reg_method(ft, "changePassword", [](Channel * c, Player * player, std::string pass) {
		c->Password(player, pass);
	});
	reg_method(ft, "setModerator", [](Channel * c, Player * player, std::string newname) {
		c->SetModerator(player, newname);
	});
	reg_method(ft, "unsetModerator", [](Channel * c, Player * player, std::string newname) {
		c->UnsetModerator(player, newname);
	});
	reg_method(ft, "setMute", [](Channel * c, Player * player, std::string newname) {
		c->SetMute(player, newname);
	});
	reg_method(ft, "unsetMute", [](Channel * c, Player * player, std::string newname) {
		c->UnsetMute(player, newname);
	});
	reg_method(ft, "list", [](Channel * c, Player * player) {
		c->List(player);
	});
	reg_method(ft, "announce", [](Channel * c, Player * player) {
		c->Announce(player);
	});
	reg_method(ft, "say", [](Channel * c, ObjectGuid guid, std::string what, uint32_t lang) {
		c->Say(guid, what, lang);
	});
	reg_method(ft, "invite", [](Channel * c, Player * player, std::string newp) {
		c->Invite(player, newp);
	});
	reg_method(ft, "voice", [](Channel * c, ObjectGuid guid1, ObjectGuid guid2) {
		c->Voice(guid1, guid2);
	});
	reg_method(ft, "deVoice", [](Channel * c, ObjectGuid guid1, ObjectGuid guid2) {
		c->DeVoice(guid1, guid2);
	});
	reg_method(ft, "joinNotify", [](Channel * c, Player * p) {
		c->JoinNotify(p);
	});
	reg_method(ft, "leaveNotify", [](Channel * c, Player * p) {
		c->LeaveNotify(p);
	});
	reg_method(ft, "flagsNotify", [](Channel * c, Player * p) {
		c->FlagsNotify(p);
	});
	reg_method(ft, "toggleModeration", [](Channel * c, Player * p) {
		c->ToggleModeration(p);
	});
	reg_method(ft, "addWatching", [](Channel * c, Player * p) {
		c->AddWatching(p);
	});
	reg_method(ft, "removeWatching", [](Channel * c, Player * p) {
		c->RemoveWatching(p);
	});

	return ft;
}
