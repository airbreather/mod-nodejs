#include "AllBattlegroundScript.h"

#include <string>

#include "BattlegroundQueue.h"
#include "DurationWrapper.h"
#include "Group.h"
#include "NodeJs.h"

class NODEJS_AllBattleground : public AllBattlegroundScript {
public:
	NODEJS_AllBattleground() : AllBattlegroundScript("NODEJS_AllBattleground") {
	}

	void OnBattlegroundStart(Battleground * bg) override {
		NodeJs::invoke_hook("battleground:start"
			, jprop("bg", bg));
	}
	void OnBattlegroundEndReward(Battleground * bg, Player * player, TeamId const winnerTeamId) override {
		NodeJs::invoke_hook("battleground:end-reward"
			, jprop("bg", bg), jprop("player", player), jprop("winnerTeamId", winnerTeamId));
	}
	void OnBattlegroundUpdate(Battleground * bg, uint32_t const diff) override {
		NodeJs::invoke_hook("battleground:update"
			, jprop("bg", bg), jprop("diff", DurationWrapper::from_milliseconds(diff)));
	}
	void OnBattlegroundAddPlayer(Battleground * bg, Player * player) override {
		NodeJs::invoke_hook("battleground:add-player"
			, jprop("bg", bg), jprop("player", player));
	}
	void OnBattlegroundBeforeAddPlayer(Battleground * bg, Player * player) override {
		NodeJs::invoke_hook("battleground:before-add-player"
			, jprop("bg", bg), jprop("player", player));
	}
	void OnBattlegroundRemovePlayerAtLeave(Battleground * bg, Player * player) override {
		NodeJs::invoke_hook("battleground:remove-player-at-leave"
			, jprop("bg", bg), jprop("player", player));
	}
	void OnQueueUpdate(BattlegroundQueue * queue, uint32_t const diff, BattlegroundTypeId const bgTypeId, BattlegroundBracketId const bracket_id, uint8_t const arenaType, bool const isRated, uint32_t const arenaRating) override {
		NodeJs::invoke_hook("battleground-queue:update"
			, jprop("queue", queue), jprop("diff", DurationWrapper::from_milliseconds(diff)), jprop("bgTypeId", bgTypeId), jprop("bracketId", bracket_id), jprop("arenaType", arenaType), jprop("isRated", isRated), jprop("arenaRating", arenaRating));
	}
	[[nodiscard]] bool OnQueueUpdateValidity(BattlegroundQueue * queue, uint32_t const diff, BattlegroundTypeId const bgTypeId, BattlegroundBracketId const bracket_id, uint8_t const arenaType, bool const isRated, uint32_t const arenaRating) override {
		return NodeJs::invoke_hook_t("battleground-queue:update-validity", AllBattlegroundScript::OnQueueUpdateValidity(queue, diff, bgTypeId, bracket_id, arenaType, isRated, arenaRating)
			, jprop("queue", queue), jprop("diff", DurationWrapper::from_milliseconds(diff)), jprop("bgTypeId", bgTypeId), jprop("bracketId", bracket_id), jprop("arenaType", arenaType), jprop("isRated", isRated), jprop("arenaRating", arenaRating));
	 }
	void OnAddGroup(BattlegroundQueue * queue, GroupQueueInfo * ginfo, uint32_t & index, Player* leader, Group * group, BattlegroundTypeId const bgTypeId, PvPDifficultyEntry const * bracketEntry, uint8_t const arenaType, bool const isRated, bool const isPremade, uint32_t const arenaRating, uint32_t const matchmakerRating, uint32_t const arenaTeamId, uint32_t const opponentsArenaTeamId) override {
		NodeJs::invoke_hook("battleground-queue:add-group"
			, jprop("queue", queue), jprop("gInfo", ginfo), jprop_box("index", index), jprop("leader", leader), jprop("group", group), jprop("bgTypeId", bgTypeId), jprop("bracketEntry", bracketEntry), jprop("arenaType", arenaType), jprop("isRated", isRated), jprop("isPremade", isPremade), jprop("arenaRating", arenaRating), jprop("matchmakerRating", matchmakerRating), jprop("arenaTeamId", arenaTeamId), jprop("opponentsArenaTeamId", opponentsArenaTeamId));
	}
	[[nodiscard]] bool CanFillPlayersToBG(BattlegroundQueue * queue, Battleground * bg, BattlegroundBracketId const bracket_id) override {
		return NodeJs::invoke_hook_t("battleground-queue:can-fill-players", AllBattlegroundScript::CanFillPlayersToBG(queue, bg, bracket_id)
			, jprop("queue", queue), jprop("bg", bg), jprop("bracketId", bracket_id));
	}
	[[nodiscard]] bool IsCheckNormalMatch(BattlegroundQueue * queue, Battleground * bgTemplate, BattlegroundBracketId const bracket_id, uint32_t const minPlayers, uint32_t const maxPlayers) override {
		return NodeJs::invoke_hook_t("battleground-queue:is-check-normal-match", AllBattlegroundScript::IsCheckNormalMatch(queue, bgTemplate, bracket_id, minPlayers, maxPlayers)
			, jprop("queue", queue), jprop("bgTemplate", bgTemplate), jprop("bracketId", bracket_id), jprop("minPlayers", minPlayers), jprop("maxPlayers", maxPlayers));
	}
	[[nodiscard]] bool CanSendMessageBGQueue(BattlegroundQueue * queue, Player * leader, Battleground * bg, PvPDifficultyEntry const * bracketEntry) override {
		return NodeJs::invoke_hook_t("battleground-queue:can-send-message", AllBattlegroundScript::CanSendMessageBGQueue(queue, leader, bg, bracketEntry)
			, jprop("queue", queue), jprop("leader", leader), jprop("bg", bg), jprop("bracketEntry", bracketEntry));
	}
	[[nodiscard]] bool OnBeforeSendJoinMessageArenaQueue(BattlegroundQueue * queue, Player * leader, GroupQueueInfo * ginfo, PvPDifficultyEntry const * bracketEntry, bool const isRated) override {
		return NodeJs::invoke_hook_t("battleground-queue:before-send-join-message-arena", AllBattlegroundScript::OnBeforeSendJoinMessageArenaQueue(queue, leader, ginfo, bracketEntry, isRated)
			, jprop("queue", queue), jprop("leader", leader), jprop("gInfo", ginfo), jprop("bracketEntry", bracketEntry), jprop("isRated", isRated));
	}
	[[nodiscard]] bool OnBeforeSendExitMessageArenaQueue(BattlegroundQueue * queue, GroupQueueInfo * ginfo) override {
		return NodeJs::invoke_hook_t("battleground-queue:before-send-exit-message-arena", AllBattlegroundScript::OnBeforeSendExitMessageArenaQueue(queue, ginfo)
			, jprop("queue", queue), jprop("gInfo", ginfo));
	}
	void OnBattlegroundEnd(Battleground * bg, TeamId const winner_team) override {
		NodeJs::invoke_hook("battleground:end"
			, jprop("bg", bg), jprop("winnerTeam", winner_team));
	}
	void OnBattlegroundDestroy(Battleground* bg) override {
		NodeJs::invoke_hook("battleground:destroy"
			, jprop("bg", bg));
	}
	void OnBattlegroundCreate(Battleground* bg) override {
		NodeJs::invoke_hook("battleground:create"
			, jprop("bg", bg));
	}
	[[nodiscard]] bool CanAddGroupToMatchingPool(BattlegroundQueue * queue, GroupQueueInfo * group, uint32_t const poolPlayerCount, Battleground * bg, BattlegroundBracketId const bracketId) override {
		return NodeJs::invoke_hook_t("battleground-queue:can-add-group-to-matching-pool", AllBattlegroundScript::CanAddGroupToMatchingPool(queue, group, poolPlayerCount, bg, bracketId)
			, jprop("queue", queue), jprop("gInfo", group), jprop("poolPlayerCount", poolPlayerCount), jprop("bg", bg), jprop("bracketId", bracketId));
	}
	[[nodiscard]] bool GetPlayerMatchmakingRating(ObjectGuid const playerGuid, BattlegroundTypeId const bgTypeId, float & outRating) override {
		return NodeJs::invoke_hook_t("battleground-queue:get-player-matchmaking-rating", AllBattlegroundScript::GetPlayerMatchmakingRating(playerGuid, bgTypeId, outRating)
			, jprop("playerGuid", playerGuid), jprop("bgTypeId", bgTypeId), jprop_box("outRating", outRating));
	}
};

void AddSC_AllBattleground() {
	new NODEJS_AllBattleground();
}
