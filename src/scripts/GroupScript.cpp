#include "GroupScript.h"

#include <string>

#include "Group.h"
#include "NodeJs.h"

class NODEJS_Group : public GroupScript {
public:
	NODEJS_Group() : GroupScript("NODEJS_Group") {
	}

	void OnAddMember(Group * group, ObjectGuid const guid) override {
		NodeJs::invoke_hook("group:add-member"
			, jprop("group", group), jprop("guid", guid));
	}
	void OnInviteMember(Group * group, ObjectGuid const guid) override {
		NodeJs::invoke_hook("group:invite-member"
			, jprop("group", group), jprop("guid", guid));
	}
	void OnRemoveMember(Group * group, ObjectGuid const guid, RemoveMethod const method, ObjectGuid const kicker, const char * reason) override {
		NodeJs::invoke_hook("group:remove-member"
			, jprop("group", group), jprop("guid", guid), jprop("method", method), jprop("kicker", kicker), jprop("reason", reason));
	}
	void OnChangeLeader(Group * group, ObjectGuid const newLeaderGuid, ObjectGuid const oldLeaderGuid) override {
		NodeJs::invoke_hook("group:change-leader"
			, jprop("group", group), jprop("newLeaderGuid", newLeaderGuid), jprop("oldLeaderGuid", oldLeaderGuid));
	}
	void OnDisband(Group * group) override {
		NodeJs::invoke_hook("group:disband"
			, jprop("group", group));
	}
	[[nodiscard]] bool CanGroupJoinBattlegroundQueue(Group const * group, Player * member, Battleground const * bgTemplate, uint32_t const MinPlayerCount, bool const isRated, uint32_t const arenaSlot) override {
		return NodeJs::invoke_hook_t("group:can-join-battleground-queue", GroupScript::CanGroupJoinBattlegroundQueue(group, member, bgTemplate, MinPlayerCount, isRated, arenaSlot)
			, jprop("group", group), jprop("member", member), jprop("bgTemplate", bgTemplate), jprop("minPlayerCount", MinPlayerCount), jprop("isRated", isRated), jprop("arenaSlot", arenaSlot));
	}
	void OnCreate(Group * group, Player * leader) override {
		NodeJs::invoke_hook("group:create"
			, jprop("group", group), jprop("leader", leader));
	}
};

void AddSC_Group() {
	new NODEJS_Group();
}
