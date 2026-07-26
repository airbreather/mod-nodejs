#include "GroupScript.h"

#include <string>

#include "Group.h"
#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_Group : public GroupScript {
public:
	NODEJS_Group() : GroupScript("NODEJS_Group") {
	}

	void OnAddMember(Group * group, ObjectGuid const guid) override {
		NodeJs::invoke_hook("group:add-member", jarg("group", group), jarg("guid", guid.GetRawValue()));
	}
	void OnInviteMember(Group * group, ObjectGuid const guid) override {
		NodeJs::invoke_hook("group:invite-member", jarg("group", group), jarg("guid", guid.GetRawValue()));
	}
	void OnRemoveMember(Group * group, ObjectGuid const guid, RemoveMethod const method, ObjectGuid const kicker, const char * reason) override {
		NodeJs::invoke_hook("group:remove-member", jarg("group", group), jarg("guid", guid.GetRawValue()), jarg("method", method), jarg("kicker", kicker.GetRawValue()), jarg("reason", reason));
	}
	void OnChangeLeader(Group * group, ObjectGuid const newLeaderGuid, ObjectGuid const oldLeaderGuid) override {
		NodeJs::invoke_hook("group:change-leader", jarg("group", group), jarg("newLeaderGuid", newLeaderGuid.GetRawValue()), jarg("oldLeaderGuid", oldLeaderGuid.GetRawValue()));
	}
	void OnDisband(Group * group) override {
		NodeJs::invoke_hook("group:disband", jarg("group", group));
	}
	[[nodiscard]] bool CanGroupJoinBattlegroundQueue(Group const * group, Player * member, Battleground const * bgTemplate, uint32_t const MinPlayerCount, bool const isRated, uint32_t const arenaSlot) override {
		return NodeJs::invoke_hook_t("group:can-join-battleground-queue", GroupScript::CanGroupJoinBattlegroundQueue(group, member, bgTemplate, MinPlayerCount, isRated, arenaSlot)
			, jarg("group", group), jarg("member", member), jarg("bgTemplate", bgTemplate), jarg("minPlayerCount", MinPlayerCount), jarg("isRated", isRated), jarg("arenaSlot", arenaSlot));
	}
	void OnCreate(Group * group, Player * leader) override {
		NodeJs::invoke_hook("group:create", jarg("group", group), jarg("leader", leader));
	}
};

void AddSC_Group() {
	new NODEJS_Group();
}
