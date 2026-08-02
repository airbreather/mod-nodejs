#include "AllBattlegroundScript.h"

#include <string>

#include "BattlegroundQueue.h"
#include "DurationWrapper.h"
#include "Group.h"
#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_AllBattleground : public AllBattlegroundScript {
public:
	NODEJS_AllBattleground() : AllBattlegroundScript("NODEJS_AllBattleground") {
	}

	void OnBattlegroundStart(Battleground * bg) override {
		NodeJs::invoke_hook("battleground:start", jarg("bg", bg));
	}
	void OnBattlegroundEndReward(Battleground * bg, Player * player, TeamId const winnerTeamId) override {
		NodeJs::invoke_hook("battleground:end-reward", jarg("bg", bg), jarg("player", player), jarg("winnerTeamId", winnerTeamId));
	}
	void OnBattlegroundUpdate(Battleground * bg, uint32_t const diff) override {
		NodeJs::invoke_hook("battleground:update", jarg("bg", bg), jarg("diff", DurationWrapper::from_milliseconds(diff)));
	}
	void OnBattlegroundAddPlayer(Battleground * bg, Player * player) override {
		NodeJs::invoke_hook("battleground:add-player", jarg("bg", bg), jarg("player", player));
	}
	void OnBattlegroundBeforeAddPlayer(Battleground * bg, Player * player) override {
		NodeJs::invoke_hook("battleground:before-add-player", jarg("bg", bg), jarg("player", player));
	}
	void OnBattlegroundRemovePlayerAtLeave(Battleground * bg, Player * player) override {
		NodeJs::invoke_hook("battleground:remove-player-at-leave", jarg("bg", bg), jarg("player", player));
	}
	void OnQueueUpdate(BattlegroundQueue * queue, uint32_t const diff, BattlegroundTypeId const bgTypeId, BattlegroundBracketId const bracket_id, uint8_t const arenaType, bool const isRated, uint32_t const arenaRating) override {
		NodeJs::invoke_hook("battleground-queue:update", jarg("queue", queue), jarg("diff", DurationWrapper::from_milliseconds(diff)), jarg("bgTypeId", bgTypeId), jarg("bracketId", bracket_id), jarg("arenaType", arenaType), jarg("isRated", isRated), jarg("arenaRating", arenaRating));
	}
	[[nodiscard]] bool OnQueueUpdateValidity(BattlegroundQueue * queue, uint32_t const diff, BattlegroundTypeId const bgTypeId, BattlegroundBracketId const bracket_id, uint8_t const arenaType, bool const isRated, uint32_t const arenaRating) override {
		return NodeJs::invoke_hook_t("battleground-queue:update-validity", AllBattlegroundScript::OnQueueUpdateValidity(queue, diff, bgTypeId, bracket_id, arenaType, isRated, arenaRating)
			, jarg("queue", queue), jarg("diff", DurationWrapper::from_milliseconds(diff)), jarg("bgTypeId", bgTypeId), jarg("bracketId", bracket_id), jarg("arenaType", arenaType), jarg("isRated", isRated), jarg("arenaRating", arenaRating));
	 }
	void OnAddGroup(BattlegroundQueue * queue, GroupQueueInfo * ginfo, uint32_t & index, Player* leader, Group * group, BattlegroundTypeId const bgTypeId, PvPDifficultyEntry const * bracketEntry, uint8_t const arenaType, bool const isRated, bool const isPremade, uint32_t const arenaRating, uint32_t const matchmakerRating, uint32_t const arenaTeamId, uint32_t const opponentsArenaTeamId) override {
		NodeJs::invoke_hook("battleground-queue:add-group", jarg("queue", queue), jarg("gInfo", ginfo), jarg_inout("index", index), jarg("leader", leader), jarg("group", group), jarg("bgTypeId", bgTypeId), jarg("bracketEntry", bracketEntry), jarg("arenaType", arenaType), jarg("isRated", isRated), jarg("isPremade", isPremade), jarg("arenaRating", arenaRating), jarg("matchmakerRating", matchmakerRating), jarg("arenaTeamId", arenaTeamId), jarg("opponentsArenaTeamId", opponentsArenaTeamId));
	}
	[[nodiscard]] bool CanFillPlayersToBG(BattlegroundQueue * queue, Battleground * bg, BattlegroundBracketId const bracket_id) override {
		return NodeJs::invoke_hook_t("battleground-queue:can-fill-players", AllBattlegroundScript::CanFillPlayersToBG(queue, bg, bracket_id)
			, jarg("queue", queue), jarg("bg", bg), jarg("bracketId", bracket_id));
	}
	[[nodiscard]] bool IsCheckNormalMatch(BattlegroundQueue * queue, Battleground * bgTemplate, BattlegroundBracketId const bracket_id, uint32_t const minPlayers, uint32_t const maxPlayers) override {
		return NodeJs::invoke_hook_t("battleground-queue:is-check-normal-match", AllBattlegroundScript::IsCheckNormalMatch(queue, bgTemplate, bracket_id, minPlayers, maxPlayers)
			, jarg("queue", queue), jarg("bgTemplate", bgTemplate), jarg("bracketId", bracket_id), jarg("minPlayers", minPlayers), jarg("maxPlayers", maxPlayers));
	}
	[[nodiscard]] bool CanSendMessageBGQueue(BattlegroundQueue * queue, Player * leader, Battleground * bg, PvPDifficultyEntry const * bracketEntry) override {
		return NodeJs::invoke_hook_t("battleground-queue:can-send-message", AllBattlegroundScript::CanSendMessageBGQueue(queue, leader, bg, bracketEntry)
			, jarg("queue", queue), jarg("leader", leader), jarg("bg", bg), jarg("bracketEntry", bracketEntry));
	}
	[[nodiscard]] bool OnBeforeSendJoinMessageArenaQueue(BattlegroundQueue * queue, Player * leader, GroupQueueInfo * ginfo, PvPDifficultyEntry const * bracketEntry, bool const isRated) override {
		return NodeJs::invoke_hook_t("battleground-queue:before-send-join-message-arena", AllBattlegroundScript::OnBeforeSendJoinMessageArenaQueue(queue, leader, ginfo, bracketEntry, isRated)
			, jarg("queue", queue), jarg("leader", leader), jarg("gInfo", ginfo), jarg("bracketEntry", bracketEntry), jarg("isRated", isRated));
	}
	[[nodiscard]] bool OnBeforeSendExitMessageArenaQueue(BattlegroundQueue * queue, GroupQueueInfo * ginfo) override {
		return NodeJs::invoke_hook_t("battleground-queue:before-send-exit-message-arena", AllBattlegroundScript::OnBeforeSendExitMessageArenaQueue(queue, ginfo)
			, jarg("queue", queue), jarg("gInfo", ginfo));
	}
	void OnBattlegroundEnd(Battleground * bg, TeamId const winner_team) override {
		NodeJs::invoke_hook("battleground:end", jarg("bg", bg), jarg("winnerTeam", winner_team));
	}
	void OnBattlegroundDestroy(Battleground* bg) override {
		NodeJs::invoke_hook("battleground:destroy", jarg("bg", bg));
	}
	void OnBattlegroundCreate(Battleground* bg) override {
		NodeJs::invoke_hook("battleground:create", jarg("bg", bg));
	}
	[[nodiscard]] bool CanAddGroupToMatchingPool(BattlegroundQueue * queue, GroupQueueInfo * group, uint32_t const poolPlayerCount, Battleground * bg, BattlegroundBracketId const bracketId) override {
		return NodeJs::invoke_hook_t("battleground-queue:can-add-group-to-matching-pool", AllBattlegroundScript::CanAddGroupToMatchingPool(queue, group, poolPlayerCount, bg, bracketId)
			, jarg("queue", queue), jarg("gInfo", group), jarg("poolPlayerCount", poolPlayerCount), jarg("bg", bg), jarg("bracketId", bracketId));
	}
	[[nodiscard]] bool GetPlayerMatchmakingRating(ObjectGuid const playerGuid, BattlegroundTypeId const bgTypeId, float & outRating) override {
		return NodeJs::invoke_hook_t("battleground-queue:get-player-matchmaking-rating", AllBattlegroundScript::GetPlayerMatchmakingRating(playerGuid, bgTypeId, outRating)
			, jarg("playerGuid", playerGuid), jarg("bgTypeId", bgTypeId), jarg_inout("outRating", outRating));
	}
};

void AddSC_AllBattleground() {
	new NODEJS_AllBattleground();
}
