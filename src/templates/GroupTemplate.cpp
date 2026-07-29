#include <list>
#include <optional>
#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "Group.h"
#include "LFG.h"
#include "NodePropertySystem.h"
#include "ObjectGuid.h"
#include "Player.h"
#include "SharedDefines.h"

JVAL_CVAL_TMPLS_RW(Group)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Group *>() {
	TypedTemplate<Group *> const ft = jctor();

	ft->SetClassName(jstr_intern("Group"));

	reg_prop_ro(ft, "isRaid", [](Group * grp) {
		return grp->isRaidGroup();
	});
	reg_prop_ro(ft, "isLFG", [](Group * grp) {
		return grp->isLFGGroup();
	});
	reg_prop_ro(ft, "isBG", [](Group * grp) {
		return grp->isBGGroup();
	});
	reg_prop_ro(ft, "isFull", [](Group * grp) {
		return grp->IsFull();
	});
	reg_prop_ro(ft, "leaderName", [](Group * grp) {
		return grp->GetLeaderName();
	});
	reg_prop_ro(ft, "guid", [](Group * grp) {
		return grp->GetGUID();
	});
	reg_prop_ro(ft, "memberCount", [](Group * grp) {
		return grp->GetMembersCount();
	});
	reg_prop_ro(ft, "groupType", [](Group * grp) {
		return grp->GetGroupType();
	});
	reg_prop_ro(ft, "members", [](Group * grp) {
		return jarr(grp->GetMemberSlots());
	});

	reg_method(ft, "hasFreeSlotInSubgroup", [](Group * grp, uint8_t const subgroup) {
		return grp->HasFreeSlotSubGroup(subgroup);
	});

	reg_prop(ft, "leaderGuid",
		[](Group * grp) { return grp->GetLeaderGUID(); },
		[](Group * grp, ObjectGuid const guid) { grp->ChangeLeader(guid); }
	);

	reg_method(ft, "disband", [](Group * grp) {
		grp->Disband();
	});
	reg_method(ft, "convertToRaid", [](Group * grp) {
		grp->ConvertToRaid();
	});
	reg_method(ft, "changeSubgroup", [](Group * grp, ObjectGuid const guid, uint8_t const subgroup) {
		grp->ChangeMembersGroup(guid, subgroup);
	});
	reg_method(ft, "setTargetIcon", [](Group * grp, uint8_t const icon, ObjectGuid const setter, ObjectGuid target) {
		grp->SetTargetIcon(icon, setter, target);
	});
	reg_method(ft, "addMember", [](Group * grp, Player * player, std::optional<lfg::LfgRoles> roles) {
		auto const success = grp->AddMember(player, roles.value_or(lfg::PLAYER_ROLE_NONE));
		if (success) {
			grp->BroadcastGroupUpdate();
		}
		return success;
	});
	reg_method(ft, "removeMember", [](Group * grp, ObjectGuid const member, std::optional<RemoveMethod> const method, std::optional<ObjectGuid> const kicker, std::optional<std::string> reason) {
		grp->RemoveMember(member, method.value_or(GROUP_REMOVEMETHOD_DEFAULT), kicker.value_or(ObjectGuid::Empty), reason ? reason->data(): nullptr);
	});
	reg_method(ft, "setAssistant", [](Group * grp, ObjectGuid const player) {
		grp->SetGroupMemberFlag(player, true, MEMBER_FLAG_ASSISTANT);
	});
	reg_method(ft, "removeAssistant", [](Group * grp, ObjectGuid const player) {
		grp->SetGroupMemberFlag(player, false, MEMBER_FLAG_ASSISTANT);
	});
	reg_method(ft, "sendPacket", [](Group * grp, WorldPacket * pkt, std::optional<bool> const ignore_players_in_bg, std::optional<uint8_t> const subgroup, std::optional<ObjectGuid> const ignore) {
		grp->BroadcastPacket(pkt, ignore_players_in_bg.value_or(false), subgroup ? *subgroup : -1, ignore.value_or(ObjectGuid::Empty));
	});

	return ft;
}
