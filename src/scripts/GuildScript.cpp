#include "GuildScript.h"

#include "Guild.h"
#include "NodeJPropHelpers.h"
#include "NodeJs.h"
#include "WorldSession.h"

class NODEJS_Guild : public GuildScript {
public:
	NODEJS_Guild() : GuildScript("NODEJS_Guild") {
	}

	void OnAddMember(Guild* guild, Player* player, uint8_t & plRank) override {
		NodeJs::invoke_hook("guild:add-member", jarg("guild", guild), jarg("player", player), jarg_inout("plRank", plRank));
	}
	void OnRemoveMember(Guild * guild, Player * player, bool const isDisbanding, bool const isKicked) override {
		NodeJs::invoke_hook("guild:remove-member", jarg("guild", guild), jarg("player", player), jarg("isDisbanding", isDisbanding), jarg("isKicked", isKicked));
	}
	void OnMOTDChanged(Guild * guild, std::string const & newMotd) override {
		NodeJs::invoke_hook("guild:motd-changed", jarg("guild", guild), jarg("newMotd", newMotd));
	}
	void OnInfoChanged(Guild * guild, std::string const & newInfo) override {
		NodeJs::invoke_hook("guild:info-changed", jarg("guild", guild), jarg("newInfo", newInfo));
	}
	void OnCreate(Guild * guild, Player * leader, std::string const & name) override {
		NodeJs::invoke_hook("guild:create", jarg("guild", guild), jarg("leader", leader), jarg("name", name));
	}
	void OnDisband(Guild * guild) override {
		NodeJs::invoke_hook("guild:disband", jarg("guild", guild));
	}
	void OnMemberWitdrawMoney(Guild * guild, Player * player, uint32_t & amount, bool const isRepair) override {
		NodeJs::invoke_hook("guild:member-withdraw-money", jarg("guild", guild), jarg("player", player), jarg_inout("amount", amount), jarg("isRepair", isRepair));
	}
	void OnMemberDepositMoney(Guild * guild, Player * player, uint32_t & amount) override {
		NodeJs::invoke_hook("guild:member-deposit-money", jarg("guild", guild), jarg("player", player), jarg_inout("amount", amount));
	}
	void OnItemMove(Guild * guild, Player * player, Item * pItem, bool const isSrcBank, uint8_t const srcContainer, uint8_t const srcSlotId, bool const isDestBank, uint8_t const destContainer, uint8_t const destSlotId) override {
		NodeJs::invoke_hook("guild:item-move", jarg("guild", guild), jarg("player", player), jarg("item", pItem), jarg("isSrcBank", isSrcBank), jarg("srcContainer", srcContainer), jarg("srcSlotId", srcSlotId), jarg("isDestBank", isDestBank), jarg("destContainer", destContainer), jarg("destSlotId", destSlotId));
	}
	void OnEvent(Guild * guild, uint8_t const eventType, ObjectGuid::LowType const playerGuid1, ObjectGuid::LowType const playerGuid2, uint8_t const newRank) override {
		ObjectGuid fullPlayerGuid1(HighGuid::Player, playerGuid1);
		ObjectGuid fullPlayerGuid2(HighGuid::Player, playerGuid2);
		// some of these events have well-known IDs. let's be at least a little helpful if it's one of those.
		switch (eventType) {
			case GUILD_EVENT_LOG_INVITE_PLAYER:
				NodeJs::invoke_hook("guild:invite-player", jarg("guild", guild), jarg("inviterGuid", fullPlayerGuid1), jarg("inviteeGuid", fullPlayerGuid2));
				break;

			case GUILD_EVENT_LOG_LEAVE_GUILD:
				NodeJs::invoke_hook("guild:player-leave", jarg("guild", guild), jarg("playerGuid", fullPlayerGuid1));
				break;

			case GUILD_EVENT_LOG_UNINVITE_PLAYER:
				NodeJs::invoke_hook("guild:uninvite-player", jarg("guild", guild), jarg("uninviterGuid", fullPlayerGuid1), jarg("uninviteeGuid", fullPlayerGuid2));
				break;

			case GUILD_EVENT_LOG_DEMOTE_PLAYER:
				NodeJs::invoke_hook("guild:demote-player", jarg("guild", guild), jarg("demoterGuid", fullPlayerGuid1), jarg("demoteeGuid", fullPlayerGuid2), jarg("newRank", newRank));
				break;

			case GUILD_EVENT_LOG_PROMOTE_PLAYER:
				NodeJs::invoke_hook("guild:promote-player", jarg("guild", guild), jarg("promoterGuid", fullPlayerGuid1), jarg("promoteeGuid", fullPlayerGuid2), jarg("newRank", newRank));
				break;
		}
		// regardless of if we logged something else or not, always invoke this generic one
		// just in case there's a specific reason for it, or if someone's blindly porting their existing code.
		NodeJs::invoke_hook("guild:generic-logged-event", jarg("guild", guild), jarg("eventType", eventType), jarg("playerGuid1", fullPlayerGuid1), jarg("playerGuid2", fullPlayerGuid2), jarg("newRank", newRank));
	}
	void OnBankEvent(Guild * guild, uint8_t const eventType, uint8_t const tabId, ObjectGuid::LowType const playerGuid, uint32_t const itemOrMoney, uint16_t const itemStackCount, uint8_t const destTabId) override {
		ObjectGuid fullPlayerGuid(HighGuid::Player, playerGuid);
		// some of these events have well-known IDs. let's be at least a little helpful if it's one of those.
		switch (eventType) {
			case GUILD_BANK_LOG_WITHDRAW_ITEM:
				NodeJs::invoke_hook("guild:withdraw-bank-item", jarg("guild", guild), jarg("srcTabId", tabId), jarg("playerGuid", fullPlayerGuid), jarg("itemEntry", itemOrMoney), jarg("count", itemStackCount));
				break;

			case GUILD_BANK_LOG_MOVE_ITEM:
				NodeJs::invoke_hook("guild:move-bank-item", jarg("guild", guild), jarg("srcTabId", tabId), jarg("playerGuid", fullPlayerGuid), jarg("itemEntry", itemOrMoney), jarg("count", itemStackCount), jarg("destTabId", destTabId));
				break;

			case GUILD_BANK_LOG_DEPOSIT_ITEM:
				NodeJs::invoke_hook("guild:deposit-bank-item", jarg("guild", guild), jarg("destTabId", tabId), jarg("playerGuid", fullPlayerGuid), jarg("itemEntry", itemOrMoney), jarg("count", itemStackCount));
				break;

			case GUILD_BANK_LOG_DEPOSIT_MONEY:
				NodeJs::invoke_hook("guild:deposit-bank-money", jarg("guild", guild), jarg("playerGuid", fullPlayerGuid), jarg("amount", itemOrMoney));
				break;

			case GUILD_BANK_LOG_WITHDRAW_MONEY:
				NodeJs::invoke_hook("guild:withdraw-bank-money", jarg("guild", guild), jarg("playerGuid", fullPlayerGuid), jarg("amount", itemOrMoney));
				break;

			case GUILD_BANK_LOG_REPAIR_MONEY:
				NodeJs::invoke_hook("guild:repair-bank-money", jarg("guild", guild), jarg("playerGuid", fullPlayerGuid), jarg("amount", itemOrMoney));
				break;
		}

		// regardless of if we logged something else or not, always invoke this generic one
		// just in case there's a specific reason for it, or if someone's blindly porting their existing code.
		NodeJs::invoke_hook("guild:generic-logged-bank-event", jarg("guild", guild), jarg("eventType", eventType), jarg("tabId", tabId), jarg("playerGuid", fullPlayerGuid), jarg("itemOrMoney", itemOrMoney), jarg("itemStackCount", itemStackCount), jarg("destTabId", destTabId));
	}
	[[nodiscard]] bool CanGuildSendBankList(Guild const * guild, WorldSession * session, uint8_t const tabId, bool const sendAllSlots) override {
		// TODO: not sure what could cause GetPlayer() to return null for a session that's still working
		return NodeJs::invoke_hook_t("guild:can-send-bank-list", GuildScript::CanGuildSendBankList(guild, session, tabId, sendAllSlots)
			, jarg("guild", guild), jarg("player", session ? session->GetPlayer() : nullptr), jarg("tabId", tabId), jarg("sendAllSlots", sendAllSlots));
	}
};

void AddSC_Guild() {
	new NODEJS_Guild();
}
