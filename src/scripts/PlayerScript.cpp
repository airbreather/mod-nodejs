#include "PlayerScript.h"

#include "DurationWrapper.h"
#include "Group.h"
#include "Guild.h"
#include "LootMgr.h"
#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_player : public PlayerScript {
public:
	NODEJS_player() : PlayerScript("NODEJS_player") {
	}

	void OnPlayerJustDied(Player * player) override {
		NodeJs::invoke_hook("player:just-died", jarg("player", player));
	}
	void OnPlayerCalculateTalentsPoints(Player const * player, uint32_t & talentPointsForLevel) override {
		NodeJs::invoke_hook("player:calculate-talents-points", jarg("player", player), jarg_inout("talentPointsForLevel", talentPointsForLevel));
	}
	void OnPlayerReleasedGhost(Player * player) override {
		NodeJs::invoke_hook("player:released-ghost", jarg("player", player));
	}
	void OnPlayerSendInitialPacketsBeforeAddToMap(Player * player, WorldPacket & data) override {
		// TODO: undefined symbol: v8::Local<v8::Value> jval<WorldPacket>(WorldPacket)
		// TODO: undefined symbol: std::optional<WorldPacket> cval<WorldPacket>(v8::Local<v8::Value>)
		NodeJs::invoke_hook("player:send-initial-packets-before-add-to-map", jarg("player", player)/*, jarg_inout("data", data)*/);
	}
	void OnPlayerBattlegroundDesertion(Player * player, BattlegroundDesertionType const desertionType) override {
		NodeJs::invoke_hook("player:battleground-desertion", jarg("player", player), jarg("desertionType", desertionType));
	}
	void OnPlayerCompleteQuest(Player * player, Quest const * quest_id) override {
		NodeJs::invoke_hook("player:complete-quest", jarg("player", player), jarg("quest", quest_id));
	}
	void OnPlayerPVPKill(Player * killer, Player * killed) override {
		NodeJs::invoke_hook("player:pvp-kill", jarg("killer", killer), jarg("killed", killed));
	}
	void OnPlayerPVPFlagChange(Player * player, bool const state) override {
		NodeJs::invoke_hook("player:pvp-flag-change", jarg("player", player), jarg("state", state));
	}
	void OnPlayerCreatureKill(Player * killer, Creature * killed) override {
		NodeJs::invoke_hook("player:creature-kill", jarg("killer", killer), jarg("killed", killed));
	}
	void OnPlayerCreatureKilledByPet(Player * PetOwner, Creature * killed) override {
		NodeJs::invoke_hook("player:creature-killed-by-pet", jarg("petOwner", PetOwner), jarg("killed", killed));
	}
	void OnPlayerKilledByCreature(Creature * killer, Player * killed) override {
		NodeJs::invoke_hook("player:killed-by-creature", jarg("killer", killer), jarg("killed", killed));
	}
	void OnPlayerLevelChanged(Player * player, uint8_t const oldlevel) override{
		NodeJs::invoke_hook("player:level-changed", jarg("player", player), jarg("oldLevel", oldlevel));
	}
	void OnPlayerFreeTalentPointsChanged(Player * player, uint32_t const points) override {
		NodeJs::invoke_hook("player:free-talent-points-changed", jarg("player", player), jarg("points", points));
	}
	void OnPlayerTalentsReset(Player * player, bool const noCost) override {
		NodeJs::invoke_hook("player:talents-reset", jarg("player", player), jarg("noCost", noCost));
	}
	bool OnPlayerCanLearnTalent(Player * player, TalentEntry const * talent, uint32_t const rank) override {
		return NodeJs::invoke_hook_t("player:can-learn-talent", PlayerScript::OnPlayerCanLearnTalent(player, talent, rank)
			, jarg("player", player)/*, jarg("talent", talent)*/, jarg("rank", rank));
	}
	void OnPlayerAfterSpecSlotChanged(Player * player, uint8_t const newSlot) override {
		NodeJs::invoke_hook("player:after-spec-slot-changed", jarg("player", player), jarg("newSlot", newSlot));
	}
	void OnPlayerBeforeUpdate(Player * player, uint32_t const p_time) override {
		NodeJs::invoke_hook("player:before-update", jarg("player", player), jarg("diff", DurationWrapper::from_milliseconds(p_time)));
	}
	void OnPlayerUpdate(Player * player, uint32_t const p_time) override {
		NodeJs::invoke_hook("player:update", jarg("player", player), jarg("diff", DurationWrapper::from_milliseconds(p_time)));
	}
	void OnPlayerMoneyChanged(Player * player, int32_t & amount) override {
		NodeJs::invoke_hook("player:money-changed", jarg("player", player), jarg_inout("amount", amount));
	}
	void OnPlayerBeforeLootMoney(Player * player, Loot * loot) override {
		NodeJs::invoke_hook("player:before-loot-money", jarg("player", player), jarg("loot", loot));
	}
	void OnPlayerGiveXP(Player * player, uint32_t & amount, Unit * victim, uint8_t const xpSource) override {
		NodeJs::invoke_hook("player:give-xp", jarg("player", player), jarg_inout("amount", amount), jarg("victim", victim), jarg("xpSource", xpSource));
	}
	bool OnPlayerReputationChange(Player * player, uint32_t const factionID, int32_t & standing, bool const incremental) override {
		return NodeJs::invoke_hook_t("player:reputation-change", PlayerScript::OnPlayerReputationChange(player, factionID, standing, incremental)
			, jarg("player", player), jarg("factionId", factionID), jarg_inout("standing", standing), jarg("incremental", incremental));
	}
	void OnPlayerReputationRankChange(Player * player, uint32_t const factionID, ReputationRank const newRank, ReputationRank const olRank, bool const increased) override {
		NodeJs::invoke_hook("player:reputation-rank-change", jarg("player", player), jarg("factionId", factionID), jarg("newRank", newRank), jarg("oldRank", olRank), jarg("increased", increased));
	}
	void OnPlayerGiveReputation(Player * player, int32_t const factionID, float & amount, ReputationSource const repSource) override {
		NodeJs::invoke_hook("player:give-reputation", jarg("player", player), jarg("factionId", factionID), jarg_inout("amount", amount), jarg("repSource", repSource));
	}
	void OnPlayerLearnSpell(Player * player, uint32_t const spellID) override {
		NodeJs::invoke_hook("player:learn-spell", jarg("player", player), jarg("spellId", spellID));
	}
	void OnPlayerForgotSpell(Player * player, uint32_t const spellID) override {
		NodeJs::invoke_hook("player:forgot-spell", jarg("player", player), jarg("spellId", spellID));
	}
	void OnPlayerDuelRequest(Player * target, Player * challenger) override {
		NodeJs::invoke_hook("player:duel-request", jarg("target", target), jarg("challenger", challenger));
	}
	void OnPlayerDuelStart(Player * player1, Player * player2) override {
		NodeJs::invoke_hook("player:duel-start", jarg("player1", player1), jarg("player2", player2));
	}
	void OnPlayerDuelEnd(Player * winner, Player * loser, DuelCompleteType const type) override {
		NodeJs::invoke_hook("player:duel-end", jarg("winner", winner), jarg("loser", loser), jarg("type", type));
	}
	void OnPlayerBeforeSendChatMessage(Player * player, uint32_t & type, uint32_t & lang, std::string & msg) override {
		NodeJs::invoke_hook("player:before-send-chat-message", jarg("player", player), jarg_inout("type", type), jarg_inout("lang", lang), jarg_inout("msg", msg));
	}
	void OnPlayerEmote(Player * player, uint32_t const emote) override {
		NodeJs::invoke_hook("player:emote", jarg("player", player), jarg("emote", emote));
	}
	void OnPlayerTextEmote(Player * player, uint32_t const textEmote, uint32_t const emoteNum, ObjectGuid const guid) override {
		NodeJs::invoke_hook("player:text-emote", jarg("player", player), jarg("textEmote", textEmote), jarg("emoteNum", emoteNum), jarg("guid", guid));
	}
	void OnPlayerSpellCast(Player * player, Spell * spell, bool const skipCheck) override {
		NodeJs::invoke_hook("player:spell-cast", jarg("player", player), jarg("spell", spell), jarg("skipCheck", skipCheck));
	}
	void OnPlayerLoadFromDB(Player * player) override {
		NodeJs::invoke_hook("player:load-from-db", jarg("player", player));
	}
	void OnPlayerLogin(Player * player) override {
		NodeJs::invoke_hook("player:login", jarg("player", player));
	}
	void OnPlayerBeforeLogout(Player * player) override {
		NodeJs::invoke_hook("player:before-logout", jarg("player", player));
	}
	void OnPlayerLogout(Player * player) override {
		NodeJs::invoke_hook("player:logout", jarg("player", player));
	}
	void OnPlayerCreate(Player * player) override {
		NodeJs::invoke_hook("player:create", jarg("player", player));
	}
	void OnPlayerDelete(ObjectGuid const guid, uint32_t const accountId) override {
		NodeJs::invoke_hook("player:delete", jarg("guid", guid), jarg("accountId", accountId));
	}
	void OnPlayerFailedDelete(ObjectGuid const guid, uint32_t const accountId) override {
		NodeJs::invoke_hook("player:failed-delete", jarg("guid", guid), jarg("accountId", accountId));
	}
	void OnPlayerSave(Player * player) override {
		NodeJs::invoke_hook("player:save", jarg("player", player));
	}
	void OnPlayerBindToInstance(Player * player, Difficulty const difficulty, uint32_t const mapId, bool const permanent) override {
		NodeJs::invoke_hook("player:bind-to-instance", jarg("player", player), jarg("difficulty", difficulty), jarg("mapId", mapId), jarg("permanent", permanent));
	}
	void OnPlayerUpdateZone(Player * player, uint32_t const newZone, uint32_t const newArea) override {
		NodeJs::invoke_hook("player:update-zone", jarg("player", player), jarg("newZone", newZone), jarg("newArea", newArea));
	}
	void OnPlayerUpdateArea(Player * player, uint32_t const oldArea, uint32_t const newArea) override {
		NodeJs::invoke_hook("player:update-area", jarg("player", player), jarg("oldArea", oldArea), jarg("newArea", newArea));
	}
	void OnPlayerMapChanged(Player * player) override {
		NodeJs::invoke_hook("player:map-changed", jarg("player", player));
	}
	[[nodiscard]] bool OnPlayerBeforeTeleport(Player * player, uint32_t const mapid, float const x, float const y, float const z, float const orientation, uint32_t const options, Unit * target) override {
		return NodeJs::invoke_hook_t("player:before-teleport", PlayerScript::OnPlayerBeforeTeleport(player, mapid, x, y, z, orientation, options, target)
			, jarg("player", player), jarg("mapId", mapid), jarg("x", x), jarg("y", y), jarg("z", z), jarg("o", orientation), jarg("options", options), jarg("target", target));
	}
	void OnPlayerUpdateFaction(Player * player) override {
		NodeJs::invoke_hook("player:update-faction", jarg("player", player));
	}
	void OnPlayerAddToBattleground(Player * player, Battleground * bg) override {
		NodeJs::invoke_hook("player:add-to-battleground", jarg("player", player), jarg("bg", bg));
	}
	void OnPlayerQueueRandomDungeon(Player * player, uint32_t & rDungeonId) override {
		NodeJs::invoke_hook("player:queue-random-dungeon", jarg("player", player), jarg_inout("rDungeonId", rDungeonId));
	}
	void OnPlayerRemoveFromBattleground(Player * player, Battleground * bg) override {
		NodeJs::invoke_hook("player:remove-from-battleground", jarg("player", player), jarg("bg", bg));
	}
	void OnPlayerAchievementComplete(Player * player, AchievementEntry const * achievement) override {
		NodeJs::invoke_hook("player:achievement-complete", jarg("player", player), jarg("achievement", achievement));
	}
	bool OnPlayerBeforeAchievementComplete(Player * player, AchievementEntry const * achievement) override {
		return NodeJs::invoke_hook_t("player:before-achievement-complete", PlayerScript::OnPlayerBeforeAchievementComplete(player, achievement)
			, jarg("player", player), jarg("achievement", achievement));
	}
	void OnPlayerCriteriaProgress(Player * player, AchievementCriteriaEntry const * criteria) override {
		NodeJs::invoke_hook("player:criteria-progress", jarg("player", player)/*, jarg("criteria", criteria)*/);
	}
	bool OnPlayerBeforeCriteriaProgress(Player * player, AchievementCriteriaEntry const * criteria) override {
		return NodeJs::invoke_hook_t("player:before-criteria-progress", PlayerScript::OnPlayerBeforeCriteriaProgress(player, criteria)
			, jarg("player", player)/*, jarg("criteria", criteria)*/);
	}
	void OnPlayerAchievementSave(CharacterDatabaseTransaction trans, Player * player, uint16_t const achId, CompletedAchievementData achiData) override {
		// TODO: should "trans" become the current transaction thingy? hmm...
		NodeJs::invoke_hook("player:achievement-save"/*, jarg("trans", trans)*/, jarg("player", player), jarg("achId", achId)/*, jarg("achiData", achiData)*/);
	}
	void OnPlayerCriteriaSave(CharacterDatabaseTransaction trans, Player * player, uint16_t const achId, CriteriaProgress criteriaData) override {
		NodeJs::invoke_hook("player:criteria-save"/*, jarg("trans", trans)*/, jarg("player", player), jarg("achId", achId)/*, jarg("criteriaData", criteriaData)*/);
	}
	void OnPlayerGossipSelect(Player * player, uint32_t const menu_id, uint32_t const sender, uint32_t const action) override {
		NodeJs::invoke_hook("player:gossip-select", jarg("player", player), jarg("menuId", menu_id), jarg("sender", sender), jarg("action", action));
	}
	void OnPlayerGossipSelectCode(Player * player, uint32_t const menu_id, uint32_t const sender, uint32_t const action, const char * code) override {
		NodeJs::invoke_hook("player:gossip-select-code", jarg("player", player), jarg("menuId", menu_id), jarg("sender", sender), jarg("action", action), jarg("code", code));
	}
	void OnPlayerBeingCharmed(Player * player, Unit * charmer, uint32_t const oldFactionId, uint32_t const newFactionId) override {
		NodeJs::invoke_hook("player:being-charmed", jarg("player", player), jarg("charmer", charmer), jarg("oldFactionId", oldFactionId), jarg("newFactionId", newFactionId));
	}
	void OnPlayerAfterSetVisibleItemSlot(Player * player, uint8_t const slot, Item * item) override {
		NodeJs::invoke_hook("player:after-set-visible-item-slot", jarg("player", player), jarg("slot", slot), jarg("item", item));
	}
	void OnPlayerAfterMoveItemFromInventory(Player * player, Item * it, uint8_t const bag, uint8_t const slot, bool const update) override {
		NodeJs::invoke_hook("player:after-move-item-from-inventory", jarg("player", player), jarg("item", it), jarg("bag", bag), jarg("slot", slot), jarg("update", update));
	}
	void OnPlayerEquip(Player * player, Item * it, uint8_t const bag, uint8_t const slot, bool const update) override {
		NodeJs::invoke_hook("player:equip", jarg("player", player), jarg("item", it), jarg("bag", bag), jarg("slot", slot), jarg("update", update));
	}
	void OnPlayerUnequip(Player * player, Item * it) override {
		NodeJs::invoke_hook("player:unequip", jarg("player", player), jarg("item", it));
	}
	void OnPlayerJoinBG(Player * player) override {
		NodeJs::invoke_hook("player:join-bg", jarg("player", player));
	}
	void OnPlayerJoinArena(Player * player) override {
		NodeJs::invoke_hook("player:join-arena", jarg("player", player));
	}
	void OnPlayerGetMaxPersonalArenaRatingRequirement(Player const * player, uint32_t const minSlot, uint32_t & maxArenaRating) const override   {
		NodeJs::invoke_hook("player:get-max-personal-arena-rating-requirement", jarg("player", player), jarg("minSlot", minSlot), jarg_inout("maxArenaRating", maxArenaRating));
	}
	void OnPlayerLootItem(Player * player, Item * item, uint32_t const count, ObjectGuid const lootguid) override {
		NodeJs::invoke_hook("player:loot-item", jarg("player", player), jarg("item", item), jarg("count", count), jarg("lootGuid", lootguid));
	}
	void OnPlayerBeforeFillQuestLootItem(Player * player, LootItem & item) override {
		// TOOD: undefined symbol: std::optional<LootItem> cval<LootItem>(v8::Local<v8::Value>)
		NodeJs::invoke_hook("player:before-fill-quest-loot-item", jarg("player", player), jarg/*_inout*/("item", item));
	}
	void OnPlayerStoreNewItem(Player * player, Item * item, uint32_t const count) override {
		NodeJs::invoke_hook("player:store-new-item", jarg("player", player), jarg("item", item), jarg("count", count));
	}
	void OnPlayerCreateItem(Player * player, Item * item, uint32_t const count) override {
		NodeJs::invoke_hook("player:create-item", jarg("player", player), jarg("item", item), jarg("count", count));
	}
	void OnPlayerQuestRewardItem(Player * player, Item * item, uint32_t const count) override {
		NodeJs::invoke_hook("player:quest-reward-item", jarg("player", player), jarg("item", item), jarg("count", count));
	}
	[[nodiscard]] bool OnPlayerCanPlaceAuctionBid(Player * player, AuctionEntry * auction) override {
		return NodeJs::invoke_hook_t("player:can-place-auction-bid", PlayerScript::OnPlayerCanPlaceAuctionBid(player, auction)
			, jarg("player", player), jarg("auction", auction));
	}
	void OnPlayerGroupRollRewardItem(Player * player, Item * item, uint32_t const count, RollVote const voteType, Roll * roll) override {
		NodeJs::invoke_hook("player:group-roll-reward-item", jarg("player", player), jarg("item", item), jarg("count", count), jarg("voteType", voteType), jarg("roll", roll));
	}
	[[nodiscard]] bool OnPlayerBeforeOpenItem(Player * player, Item * item) override {
		return NodeJs::invoke_hook_t("player:before-open-item", PlayerScript::OnPlayerBeforeOpenItem(player, item)
			, jarg("player", player), jarg("item", item));
	}
	[[nodiscard]] bool OnPlayerBeforeQuestComplete(Player * player, uint32_t const quest_id) override {
		return NodeJs::invoke_hook_t("player:before-quest-complete", PlayerScript::OnPlayerBeforeQuestComplete(player, quest_id)
			, jarg("player", player), jarg("questId", quest_id));
	}
	void OnPlayerQuestComputeXP(Player * player, Quest const * quest, uint32_t & xpValue) override {
		NodeJs::invoke_hook("player:quest-compute-xp", jarg("player", player), jarg("quest", quest), jarg_inout("xpValue", xpValue));
	}
	void OnPlayerBeforeDurabilityRepair(Player * player, ObjectGuid const npcGUID, ObjectGuid const itemGUID, float &discountMod, uint8_t const guildBank) override {
		NodeJs::invoke_hook("player:before-durability-repair", jarg("player", player), jarg("npcGuid", npcGUID), jarg("itemGuid", itemGUID), jarg_inout("discountMod", discountMod), jarg("guildBank", guildBank != 0));
	}
	void OnPlayerBeforeBuyItemFromVendor(Player * player, ObjectGuid const vendorguid, uint32_t const vendorslot, uint32_t & item, uint8_t const count, uint8_t const bag, uint8_t const slot) override {
		NodeJs::invoke_hook("player:before-buy-item-from-vendor", jarg("player", player), jarg("vendorGuid", vendorguid), jarg("vendorSlot", vendorslot), jarg_inout("item", item), jarg("count", count), jarg("bag", bag), jarg("slot", slot));
	}
	void OnPlayerBeforeStoreOrEquipNewItem(Player * player, uint32_t const vendorslot, uint32_t & item, uint8_t const count, uint8_t const bag, uint8_t const slot, ItemTemplate const * pProto, Creature * pVendor, VendorItem const * crItem, bool const bStore) override {
		NodeJs::invoke_hook("player:before-store-or-equip-new-item", jarg("player", player), jarg("vendorSlot", vendorslot), jarg_inout("item", item), jarg("count", count), jarg("bag", bag), jarg("slot", slot), jarg("proto", pProto), jarg("vendor", pVendor)/*, jarg("crItem", crItem)*/, jarg("store", bStore));
	}
	void OnPlayerAfterStoreOrEquipNewItem(Player * player, uint32_t const vendorslot, Item * item, uint8_t const count, uint8_t const bag, uint8_t const slot, ItemTemplate const * pProto, Creature * pVendor, VendorItem const * crItem, bool const bStore) override {
		NodeJs::invoke_hook("player:after-store-or-equip-new-item", jarg("player", player), jarg("vendorSlot", vendorslot), jarg("item", item), jarg("count", count), jarg("bag", bag), jarg("slot", slot), jarg("proto", pProto), jarg("vendor", pVendor)/*, jarg("crItem", crItem)*/, jarg("store", bStore));
	}
	void OnPlayerAfterUpdateMaxPower(Player * player, Powers & power, float & value) override {
		NodeJs::invoke_hook("player:after-update-max-power", jarg("player", player), jarg_inout("power", power), jarg_inout("value", value));
	}
	void OnPlayerAfterUpdateMaxHealth(Player * player, float & value) override {
		NodeJs::invoke_hook("player:after-update-max-health", jarg("player", player), jarg_inout("value", value));
	}
	void OnPlayerBeforeUpdateAttackPowerAndDamage(Player * player, float & level, float & val2, bool const ranged) override {
		NodeJs::invoke_hook("player:before-update-attack-power-and-damage", jarg("player", player), jarg_inout("level", level), jarg_inout("val2", val2), jarg("ranged", ranged));
	}
	void OnPlayerAfterUpdateAttackPowerAndDamage(Player * player, float & level, float & base_attPower, float & attPowerMod, float & attPowerMultiplier, bool const ranged) override {
		NodeJs::invoke_hook("player:after-update-attack-power-and-damage", jarg("player", player), jarg_inout("level", level), jarg_inout("baseAttPower", base_attPower), jarg_inout("attPowerMod", attPowerMod), jarg_inout("attPowerMultiplier", attPowerMultiplier), jarg("ranged", ranged));
	}
	void OnPlayerBeforeInitTalentForLevel(Player * player, uint8_t & level, uint32_t & talentPointsForLevel) override {
		NodeJs::invoke_hook("player:before-init-talent-for-level", jarg("player", player), jarg_inout("level", level), jarg_inout("talentPointsForLevel", talentPointsForLevel));
	}
	void OnPlayerFirstLogin(Player * player) override {
		NodeJs::invoke_hook("player:first-login", jarg("player", player));
	}
	void OnPlayerSetMaxLevel(Player * player, uint32_t & maxPlayerLevel) override {
		NodeJs::invoke_hook("player:set-max-level", jarg("player", player), jarg_inout("maxPlayerLevel", maxPlayerLevel));
	}
	[[nodiscard]] bool OnPlayerCanJoinInBattlegroundQueue(Player * player, ObjectGuid const BattlemasterGuid, BattlegroundTypeId const BGTypeID, uint8_t const joinAsGroup, GroupJoinBattlegroundResult & err) override {
		return NodeJs::invoke_hook_t("player:can-join-in-battleground-queue", PlayerScript::OnPlayerCanJoinInBattlegroundQueue(player, BattlemasterGuid, BGTypeID, joinAsGroup, err)
			, jarg("player", player), jarg("battlemasterGuid", BattlemasterGuid), jarg("bgTypeId", BGTypeID), jarg("joinAsGroup", joinAsGroup != 0), jarg_inout("err", err));
	}
	bool OnPlayerShouldBeRewardedWithMoneyInsteadOfExp(Player * player) override {
		return NodeJs::invoke_hook_t("player:should-be-rewarded-with-money-instead-of-exp", PlayerScript::OnPlayerShouldBeRewardedWithMoneyInsteadOfExp(player)
			, jarg("player", player));
	}
	void OnPlayerBeforeTempSummonInitStats(Player * player, TempSummon * tempSummon, uint32_t & duration) override {
		if (!NodeJs::hook_has_listeners("player:before-temp-summon-init-stats")) {
			return;
		}
		auto durationWrapper = DurationWrapper::from_milliseconds(duration);
		NodeJs::invoke_hook("player:before-temp-summon-init-stats", jarg("player", player), jarg("tempSummon", tempSummon), jarg_inout("duration", durationWrapper));
		duration = durationWrapper.count<Milliseconds>();
	}
	void OnPlayerBeforeGuardianInitStatsForLevel(Player * player, Guardian * guardian, CreatureTemplate const * cinfo, PetType & petType) override {
		NodeJs::invoke_hook("player:before-guardian-init-stats-for-level", jarg("player", player), jarg("guardian", guardian), jarg("cinfo", cinfo), jarg_inout("petType", petType));
	}
	void OnPlayerAfterGuardianInitStatsForLevel(Player * player, Guardian * guardian) override {
		NodeJs::invoke_hook("player:after-guardian-init-stats-for-level", jarg("player", player), jarg("guardian", guardian));
	}
	void OnPlayerBeforeLoadPetFromDB(Player * player, uint32_t & petentry, uint32_t & petnumber, bool & current, bool & forceLoadFromDB) override {
		NodeJs::invoke_hook("player:before-load-pet-from-db", jarg("player", player), jarg_inout("petEntry", petentry), jarg_inout("petNumber", petnumber), jarg_inout("current", current), jarg_inout("forceLoadFromDB", forceLoadFromDB));
	}
	[[nodiscard]] bool OnPlayerCanJoinInArenaQueue(Player * player, ObjectGuid const BattlemasterGuid, uint8_t const arenaslot, BattlegroundTypeId const BGTypeID, uint8_t const joinAsGroup, uint8_t const IsRated, GroupJoinBattlegroundResult & err) override {
		return NodeJs::invoke_hook_t("player:can-join-in-arena-queue", PlayerScript::OnPlayerCanJoinInArenaQueue(player, BattlemasterGuid, arenaslot, BGTypeID, joinAsGroup, IsRated, err)
			, jarg("player", player), jarg("battlemasterGuid", BattlemasterGuid), jarg("arenaSlot", arenaslot), jarg("bgTypeId", BGTypeID), jarg("joinAsGroup", joinAsGroup), jarg("isRated", IsRated), jarg_inout("err", err));
	}
	[[nodiscard]] bool OnPlayerCanBattleFieldPort(Player * player, uint8_t const arenaType, BattlegroundTypeId const BGTypeID, uint8_t const action) override {
		return NodeJs::invoke_hook_t("player:can-battle-field-port", PlayerScript::OnPlayerCanBattleFieldPort(player, arenaType, BGTypeID, action)
			, jarg("player", player), jarg("arenaType", arenaType), jarg("bgTypeId", BGTypeID), jarg("action", action));
	}
	[[nodiscard]] bool OnPlayerCanGroupInvite(Player * player, std::string & membername) override {
		return NodeJs::invoke_hook_t("player:can-group-invite", PlayerScript::OnPlayerCanGroupInvite(player, membername)
			, jarg("player", player), jarg_inout("memberName", membername));
	}
	[[nodiscard]] bool OnPlayerCanGroupAccept(Player * player, Group * group) override {
		return NodeJs::invoke_hook_t("player:can-group-accept", PlayerScript::OnPlayerCanGroupAccept(player, group)
			, jarg("player", player), jarg("group", group));
	}
	[[nodiscard]] bool OnPlayerCanSellItem(Player * player, Item * item, Creature * creature) override {
		return NodeJs::invoke_hook_t("player:can-sell-item", PlayerScript::OnPlayerCanSellItem(player, item, creature)
			, jarg("player", player), jarg("item", item), jarg("creature", creature));
	}
	[[nodiscard]] bool OnPlayerCanSendMail(Player * player, ObjectGuid const receiverGuid, ObjectGuid const mailbox, std::string & subject, std::string & body, uint32_t const money, uint32_t const COD, Item * item) override {
		return NodeJs::invoke_hook_t("player:can-send-mail", PlayerScript::OnPlayerCanSendMail(player, receiverGuid, mailbox, subject, body, money, COD, item)
			, jarg("player", player), jarg("receiverGuid", receiverGuid), jarg("mailbox", mailbox), jarg_inout("subject", subject), jarg_inout("body", body), jarg("money", money), jarg("cod", COD), jarg("item", item));
	}
	void OnPlayerPetitionBuy(Player * player, Creature * creature, uint32_t & charterid, uint32_t & cost, uint32_t & type) override {
		NodeJs::invoke_hook("player:petition-buy", jarg("player", player), jarg("creature", creature), jarg_inout("charterId", charterid), jarg_inout("cost", cost), jarg_inout("type", type));
	}
	void OnPlayerPetitionShowList(Player * player, Creature * creature, uint32_t & CharterEntry, uint32_t & CharterDispayID, uint32_t & CharterCost) override {
		NodeJs::invoke_hook("player:petition-show-list", jarg("player", player), jarg("creature", creature), jarg_inout("charterEntry", CharterEntry), jarg_inout("charterDisplayId", CharterDispayID), jarg_inout("charterCost", CharterCost));
	}
	void OnPlayerRewardKillRewarder(Player * player, KillRewarder * rewarder, bool const isDungeon, float & rate) override {
		NodeJs::invoke_hook("player:reward-kill-rewarder", jarg("player", player)/*, jarg("rewarder", rewarder)*/, jarg("isDungeon", isDungeon), jarg_inout("rate", rate));
	}
	[[nodiscard]] bool OnPlayerCanGiveMailRewardAtGiveLevel(Player * player, uint8_t const level) override {
		return NodeJs::invoke_hook_t("player:can-give-mail-reward-at-give-level", PlayerScript::OnPlayerCanGiveMailRewardAtGiveLevel(player, level)
			, jarg("player", player), jarg("level", level));
	}
	void OnPlayerDeleteFromDB(CharacterDatabaseTransaction trans, uint32_t const guid) override {
		NodeJs::invoke_hook("player:delete-from-db"/*, jarg("trans", trans)*/, jarg("guid", guid));
	}
	[[nodiscard]] bool OnPlayerCanRepopAtGraveyard(Player * player) override {
		return NodeJs::invoke_hook_t("player:can-repop-at-graveyard", PlayerScript::OnPlayerCanRepopAtGraveyard(player)
			, jarg("player", player));
	}
	[[nodiscard]] Optional<bool> OnPlayerIsClass(Player const * player, Classes const playerClass, ClassContext const context) override {
		return NodeJs::invoke_hook_t("player:is-class", PlayerScript::OnPlayerIsClass(player, playerClass, context)
			, jarg("player", player), jarg("playerClass", playerClass), jarg("context", context));
	}
	void OnPlayerGetMaxSkillValue(Player * player, uint32_t const skill, int32_t & result, bool const IsPure) override {
		NodeJs::invoke_hook("player:get-max-skill-value", jarg("player", player), jarg("skill", skill), jarg_inout("result", result), jarg("isPure", IsPure));
	}
	[[nodiscard]] bool OnPlayerHasActivePowerType(Player const * player, Powers const power) override {
		return NodeJs::invoke_hook_t("player:has-active-power-type", PlayerScript::OnPlayerHasActivePowerType(player, power)
			, jarg("player", player), jarg("power", power));
	}
	void OnPlayerUpdateGatheringSkill(Player * player, uint32_t const skill_id, uint32_t const current, uint32_t const gray, uint32_t const green, uint32_t const yellow, uint32_t & gain) override {
		NodeJs::invoke_hook("player:update-gathering-skill", jarg("player", player), jarg("skillId", skill_id), jarg("current", current), jarg("gray", gray), jarg("green", green), jarg("yellow", yellow), jarg_inout("gain", gain));
	}
	void OnPlayerUpdateCraftingSkill(Player * player, SkillLineAbilityEntry const * skill, uint32_t const current_level, uint32_t & gain) override {
		NodeJs::invoke_hook("player:update-crafting-skill", jarg("player", player)/*, jarg("skill", skill)*/, jarg("currentLevel", current_level), jarg_inout("gain", gain));
	}
	[[nodiscard]] bool OnPlayerUpdateFishingSkill(Player * player, int32_t const skill, int32_t const zone_skill, int32_t const chance, int32_t const roll) override {
		return NodeJs::invoke_hook_t("player:update-fishing-skill", PlayerScript::OnPlayerUpdateFishingSkill(player, skill, zone_skill, chance, roll)
			, jarg("player", player), jarg("skill", skill), jarg("zoneSkill", zone_skill), jarg("chance", chance), jarg("roll", roll));
	}
	[[nodiscard]] bool OnPlayerCanAreaExploreAndOutdoor(Player * player) override {
		return NodeJs::invoke_hook_t("player:can-area-explore-and-outdoor", PlayerScript::OnPlayerCanAreaExploreAndOutdoor(player)
			, jarg("player", player));
	}
	void OnPlayerVictimRewardBefore(Player * player, Player * victim, uint32_t & killer_title, int32_t & victim_rank) override {
		NodeJs::invoke_hook("player:victim-reward-before", jarg("player", player), jarg("victim", victim), jarg_inout("killerTitle", killer_title), jarg_inout("victimRank", victim_rank));
	}
	void OnPlayerVictimRewardAfter(Player * player, Player * victim, uint32_t & killer_title, int32_t & victim_rank, float & honor_f) override {
		NodeJs::invoke_hook("player:victim-reward-after", jarg("player", player), jarg("victim", victim), jarg_inout("killerTitle", killer_title), jarg_inout("victimRank", victim_rank), jarg_inout("honor", honor_f));
	}
	void OnPlayerCustomScalingStatValueBefore(Player * player, ItemTemplate const * proto, uint8_t const slot, bool const apply, uint32_t & CustomScalingStatValue) override {
		NodeJs::invoke_hook("player:custom-scaling-stat-value-before", jarg("player", player), jarg("proto", proto), jarg("slot", slot), jarg("apply", apply), jarg_inout("customScalingStatValue", CustomScalingStatValue));
	}
	void OnPlayerCustomScalingStatValue(Player * player, ItemTemplate const * proto, uint32_t & statType, int32_t & val, uint8_t const itemProtoStatNumber, uint32_t const ScalingStatValue, ScalingStatValuesEntry const * ssv) override {
		NodeJs::invoke_hook("player:custom-scaling-stat-value", jarg("player", player), jarg("proto", proto), jarg_inout("statType", statType), jarg_inout("val", val), jarg("itemProtoStatNumber", itemProtoStatNumber), jarg("scalingStatValue", ScalingStatValue)/*, jarg("ssv", ssv)*/);
	}
	void OnPlayerApplyItemModsBefore(Player * player, uint8_t const slot, bool const apply, uint8_t const itemProtoStatNumber, uint32_t const statType, int32_t & val) override {
		NodeJs::invoke_hook("player:apply-item-mods-before", jarg("player", player), jarg("slot", slot), jarg("apply", apply), jarg("itemProtoStatNumber", itemProtoStatNumber), jarg("statType", statType), jarg_inout("val", val));
	}
	void OnPlayerApplyEnchantmentItemModsBefore(Player * player, Item * item, EnchantmentSlot const slot, bool const apply, uint32_t const enchant_spell_id, uint32_t & enchant_amount) override {
		NodeJs::invoke_hook("player:apply-enchantment-item-mods-before", jarg("player", player), jarg("item", item), jarg("slot", slot), jarg("apply", apply), jarg("enchantSpellId", enchant_spell_id), jarg_inout("enchantAmount", enchant_amount));
	}
	void OnPlayerApplyWeaponDamage(Player * player, uint8_t const slot, ItemTemplate const * proto, float & minDamage, float & maxDamage, uint8_t const damageIndex) override {
		NodeJs::invoke_hook("player:apply-weapon-damage", jarg("player", player), jarg("slot", slot), jarg("proto", proto), jarg_inout("minDamage", minDamage), jarg_inout("maxDamage", maxDamage), jarg("damageIndex", damageIndex));
	}
	[[nodiscard]] bool OnPlayerCanArmorDamageModifier(Player * player) override {
		return NodeJs::invoke_hook_t("player:can-armor-damage-modifier", PlayerScript::OnPlayerCanArmorDamageModifier(player)
			, jarg("player", player));
	}
	void OnPlayerGetFeralApBonus(Player * player, int32_t & feral_bonus, int32_t const dpsMod, ItemTemplate const * proto, ScalingStatValuesEntry const * ssv) override {
		NodeJs::invoke_hook("player:get-feral-ap-bonus", jarg("player", player), jarg_inout("feralBonus", feral_bonus), jarg("dpsMod", dpsMod), jarg("proto", proto)/*, jarg("ssv", ssv)*/);
	}
	[[nodiscard]] bool OnPlayerCanApplyWeaponDependentAuraDamageMod(Player * player, Item * item, WeaponAttackType const attackType, AuraEffect const * aura, bool const apply) override {
		return NodeJs::invoke_hook_t("player:can-apply-weapon-dependent-aura-damage-mod", PlayerScript::OnPlayerCanApplyWeaponDependentAuraDamageMod(player, item, attackType, aura, apply)
			, jarg("player", player), jarg("item", item), jarg("attackType", attackType), jarg("aura", aura), jarg("apply", apply));
	}
	[[nodiscard]] bool OnPlayerCanApplyEquipSpell(Player * player, SpellInfo const * spellInfo, Item * item, bool const apply, bool const form_change) override {
		return NodeJs::invoke_hook_t("player:can-apply-equip-spell", PlayerScript::OnPlayerCanApplyEquipSpell(player, spellInfo, item, apply, form_change)
			, jarg("player", player), jarg("spellInfo", spellInfo), jarg("item", item), jarg("apply", apply), jarg("formChange", form_change));
	}
	[[nodiscard]] bool OnPlayerCanApplyEquipSpellsItemSet(Player * player, ItemSetEffect * eff) override {
		return NodeJs::invoke_hook_t("player:can-apply-equip-spells-item-set", PlayerScript::OnPlayerCanApplyEquipSpellsItemSet(player, eff)
			, jarg("player", player)/*, jarg("eff", eff)*/);
	}
	[[nodiscard]] bool OnPlayerCanCastItemCombatSpell(Player * player, Unit * target, WeaponAttackType const attType, uint32_t const procVictim, uint32_t const procEx, Item * item, ItemTemplate const * proto) override {
		return NodeJs::invoke_hook_t("player:can-cast-item-combat-spell", PlayerScript::OnPlayerCanCastItemCombatSpell(player, target, attType, procVictim, procEx, item, proto)
			, jarg("player", player), jarg("target", target), jarg("attType", attType), jarg("procVictim", procVictim), jarg("procEx", procEx), jarg("item", item), jarg("proto", proto));
	}
	[[nodiscard]] bool OnPlayerCanCastItemUseSpell(Player * player, Item * item, SpellCastTargets const & targets, uint8_t const cast_count, uint32_t const glyphIndex) override {
		return NodeJs::invoke_hook_t("player:can-cast-item-use-spell", PlayerScript::OnPlayerCanCastItemUseSpell(player, item, targets, cast_count, glyphIndex)
			, jarg("player", player), jarg("item", item)/*, jarg("targets", targets)*/, jarg("castCount", cast_count), jarg("glyphIndex", glyphIndex));
	}
	void OnPlayerApplyAmmoBonuses(Player * player, ItemTemplate const * proto, float & currentAmmoDPS) override {
		NodeJs::invoke_hook("player:apply-ammo-bonuses", jarg("player", player), jarg("proto", proto), jarg_inout("currentAmmoDps", currentAmmoDPS));
	}
	[[nodiscard]] bool OnPlayerCanEquipItem(Player * player, uint8_t const slot, uint16_t & dest, Item * pItem, bool const swap, bool const not_loading) override {
		return NodeJs::invoke_hook_t("player:can-equip-item", PlayerScript::OnPlayerCanEquipItem(player, slot, dest, pItem, swap, not_loading)
			, jarg("player", player), jarg("slot", slot), jarg_inout("dest", dest), jarg("item", pItem), jarg("swap", swap), jarg("notLoading", not_loading));
	}
	[[nodiscard]] bool OnPlayerCanUnequipItem(Player * player, uint16_t const pos, bool const swap) override {
		return NodeJs::invoke_hook_t("player:can-unequip-item", PlayerScript::OnPlayerCanUnequipItem(player, pos, swap)
			, jarg("player", player), jarg("pos", pos), jarg("swap", swap));
	}
	[[nodiscard]] bool OnPlayerCanUseItem(Player * player, ItemTemplate const * proto, InventoryResult & result) override {
		return NodeJs::invoke_hook_t("player:can-use-item", PlayerScript::OnPlayerCanUseItem(player, proto, result)
			, jarg("player", player), jarg("proto", proto), jarg_inout("result", result));
	}
	[[nodiscard]] bool OnPlayerCanSaveEquipNewItem(Player * player, Item * item, uint16_t const pos, bool const update) override {
		return NodeJs::invoke_hook_t("player:can-save-equip-new-item", PlayerScript::OnPlayerCanSaveEquipNewItem(player, item, pos, update)
			, jarg("player", player), jarg("item", item), jarg("pos", pos), jarg("update", update));
	}
	[[nodiscard]] bool OnPlayerCanApplyEnchantment(Player * player, Item * item, EnchantmentSlot const slot, bool const apply, bool const apply_dur, bool const ignore_condition) override {
		return NodeJs::invoke_hook_t("player:can-apply-enchantment", PlayerScript::OnPlayerCanApplyEnchantment(player, item, slot, apply, apply_dur, ignore_condition)
			, jarg("player", player), jarg("item", item), jarg("slot", slot), jarg("apply", apply), jarg("applyDur", apply_dur), jarg("ignoreCondition", ignore_condition));
	}
	void OnPlayerGetQuestRate(Player * player, float & result) override {
		NodeJs::invoke_hook("player:get-quest-rate", jarg("player", player), jarg_inout("result", result));
	}
	[[nodiscard]] bool OnPlayerPassedQuestKilledMonsterCredit(Player * player, Quest const * qinfo, uint32_t const entry, uint32_t const real_entry, ObjectGuid const guid) override {
		return NodeJs::invoke_hook_t("player:passed-quest-killed-monster-credit", PlayerScript::OnPlayerPassedQuestKilledMonsterCredit(player, qinfo, entry, real_entry, guid)
			, jarg("player", player), jarg("qInfo", qinfo), jarg("entry", entry), jarg("realEntry", real_entry), jarg("guid", guid));
	}
	[[nodiscard]] bool OnPlayerCheckItemInSlotAtLoadInventory(Player * player, Item * item, uint8_t const slot, uint8_t & err, uint16_t & dest) override {
		return NodeJs::invoke_hook_t("player:check-item-in-slot-at-load-inventory", PlayerScript::OnPlayerCheckItemInSlotAtLoadInventory(player, item, slot, err, dest)
			, jarg("player", player), jarg("item", item), jarg("slot", slot), jarg_inout("err", err), jarg_inout("dest", dest));
	}
	[[nodiscard]] bool OnPlayerNotAvoidSatisfy(Player * player, DungeonProgressionRequirements const * ar, uint32_t const target_map, bool const report) override {
		return NodeJs::invoke_hook_t("player:not-avoid-satisfy", PlayerScript::OnPlayerNotAvoidSatisfy(player, ar, target_map, report)
			, jarg("player", player)/*, jarg("ar", ar)*/, jarg("targetMap", target_map), jarg("report", report));
	}
	[[nodiscard]] bool OnPlayerNotVisibleGloballyFor(Player * player, Player const * u) override {
		return NodeJs::invoke_hook_t("player:not-visible-globally-for", PlayerScript::OnPlayerNotVisibleGloballyFor(player, u)
			, jarg("player", player), jarg("u", u));
	}
	void OnPlayerGetArenaPersonalRating(Player * player, uint8_t const slot, uint32_t & result) override {
		NodeJs::invoke_hook("player:get-arena-personal-rating", jarg("player", player), jarg("slot", slot), jarg_inout("result", result));
	}
	void OnPlayerGetArenaTeamId(Player * player, uint8_t const slot, uint32_t & result) override {
		NodeJs::invoke_hook("player:get-arena-team-id", jarg("player", player), jarg("slot", slot), jarg_inout("result", result));
	}
	void OnPlayerIsFFAPvP(Player * player, bool & result) override {
		NodeJs::invoke_hook("player:is-ffa-pvp", jarg("player", player), jarg_inout("result", result));
	}
	void OnPlayerFfaPvpStateUpdate(Player * player, bool const result) override {
		NodeJs::invoke_hook("player:ffa-pvp-state-update", jarg("player", player), jarg("result", result));
	}
	void OnPlayerIsPvP(Player * player, bool & result) override {
		NodeJs::invoke_hook("player:is-pvp", jarg("player", player), jarg_inout("result", result));
	}
	void OnPlayerGetMaxSkillValueForLevel(Player * player, uint16_t & result) override {
		NodeJs::invoke_hook("player:get-max-skill-value-for-level", jarg("player", player), jarg_inout("result", result));
	}
	[[nodiscard]] bool OnPlayerNotSetArenaTeamInfoField(Player * player, uint8_t const slot, ArenaTeamInfoType const type, uint32_t const value) override {
		return NodeJs::invoke_hook_t("player:not-set-arena-team-info-field", PlayerScript::OnPlayerNotSetArenaTeamInfoField(player, slot, type, value)
			, jarg("player", player), jarg("slot", slot), jarg("type", type), jarg("value", value));
	}
	[[nodiscard]] bool OnPlayerCanJoinLfg(Player * player, uint8_t const roles, std::set<uint32_t> & dungeons, const std::string & comment) override {
		return NodeJs::invoke_hook_t("player:can-join-lfg", PlayerScript::OnPlayerCanJoinLfg(player, roles, dungeons, comment)
			, jarg("player", player), jarg("roles", roles)/*, jarg_inout("dungeons", dungeons)*/, jarg("comment", comment));
	}
	[[nodiscard]] bool OnPlayerCanEnterMap(Player * player, MapEntry const * entry, InstanceTemplate const * instance, MapDifficulty const * mapDiff, bool const loginCheck) override {
		return NodeJs::invoke_hook_t("player:can-enter-map", PlayerScript::OnPlayerCanEnterMap(player, entry, instance, mapDiff, loginCheck)
			, jarg("player", player)/*, jarg("entry", entry)*//*, jarg("instance", instance)*//*, jarg("mapDiff", mapDiff)*/, jarg("loginCheck", loginCheck));
	}
	[[nodiscard]] bool OnPlayerCanInitTrade(Player * player, Player * target) override {
		return NodeJs::invoke_hook_t("player:can-init-trade", PlayerScript::OnPlayerCanInitTrade(player, target)
			, jarg("player", player), jarg("target", target));
	}
	[[nodiscard]] bool OnPlayerCanSetTradeItem(Player * player, Item * tradedItem, uint8_t const tradeSlot) override {
		return NodeJs::invoke_hook_t("player:can-set-trade-item", PlayerScript::OnPlayerCanSetTradeItem(player, tradedItem, tradeSlot)
			, jarg("player", player), jarg("tradedItem", tradedItem), jarg("tradeSlot", tradeSlot));
	}
	void OnPlayerSetServerSideVisibility(Player * player, ServerSideVisibilityType & type, AccountTypes & sec) override {
		NodeJs::invoke_hook("player:set-server-side-visibility", jarg("player", player), jarg_inout("type", type), jarg_inout("sec", sec));
	}
	void OnPlayerSetServerSideVisibilityDetect(Player * player, ServerSideVisibilityType & type, AccountTypes & sec) override {
		NodeJs::invoke_hook("player:set-server-side-visibility-detect", jarg("player", player), jarg_inout("type", type), jarg_inout("sec", sec));
	}
	void OnPlayerResurrect(Player * player, float const restore_percent, bool & applySickness) override {
		NodeJs::invoke_hook("player:resurrect", jarg("player", player), jarg("restorePercent", restore_percent), jarg_inout("applySickness", applySickness));
	}
	void OnPlayerBeforeChooseGraveyard(Player * player, TeamId const teamId, bool const nearCorpse, uint32_t & graveyardOverride) override {
		NodeJs::invoke_hook("player:before-choose-graveyard", jarg("player", player), jarg("teamId", teamId), jarg("nearCorpse", nearCorpse), jarg_inout("graveyardOverride", graveyardOverride));
	}
	[[nodiscard]] bool OnPlayerCanUseChat(Player * player, uint32_t const type, uint32_t const language, std::string & msg) override {
		return NodeJs::invoke_hook_t("player:can-use-chat", PlayerScript::OnPlayerCanUseChat(player, type, language, msg)
			, jarg("player", player), jarg("type", type), jarg("lang", language), jarg_inout("msg", msg));
	}
	[[nodiscard]] bool OnPlayerCanUseChat(Player * player, uint32_t const type, uint32_t const language, std::string & msg, Player * receiver) override {
		return NodeJs::invoke_hook_t("player:can-use-chat:player", PlayerScript::OnPlayerCanUseChat(player, type, language, msg, receiver)
			, jarg("player", player), jarg("type", type), jarg("lang", language), jarg_inout("msg", msg), jarg("receiver", receiver));
	}
	[[nodiscard]] bool OnPlayerCanUseChat(Player * player, uint32_t const type, uint32_t const language, std::string & msg, Group * group) override {
		return NodeJs::invoke_hook_t("player:can-use-chat:group", PlayerScript::OnPlayerCanUseChat(player, type, language, msg, group)
			, jarg("player", player), jarg("type", type), jarg("lang", language), jarg_inout("msg", msg), jarg("group", group));
	}
	[[nodiscard]] bool OnPlayerCanUseChat(Player * player, uint32_t const type, uint32_t const language, std::string & msg, Guild * guild) override {
		return NodeJs::invoke_hook_t("player:can-use-chat:guild", PlayerScript::OnPlayerCanUseChat(player, type, language, msg, guild)
			, jarg("player", player), jarg("type", type), jarg("lang", language), jarg_inout("msg", msg), jarg("guild", guild));
	}
	[[nodiscard]] bool OnPlayerCanUseChat(Player * player, uint32_t const type, uint32_t const language, std::string & msg, Channel * channel) override {
		return NodeJs::invoke_hook_t("player:can-use-chat:channel", PlayerScript::OnPlayerCanUseChat(player, type, language, msg, channel)
			, jarg("player", player), jarg("type", type), jarg("lang", language), jarg_inout("msg", msg)/*, jarg("channel", channel)*/);
	}
	void OnPlayerLearnTalents(Player * player, uint32_t const talentId, uint32_t const talentRank, uint32_t const spellid) override {
		NodeJs::invoke_hook("player:learn-talents", jarg("player", player), jarg("talentId", talentId), jarg("talentRank", talentRank), jarg("spellId", spellid));
	}
	void OnPlayerEnterCombat(Player * player, Unit * enemy) override {
		NodeJs::invoke_hook("player:enter-combat", jarg("player", player), jarg("enemy", enemy));
	}
	void OnPlayerLeaveCombat(Player * player) override {
		NodeJs::invoke_hook("player:leave-combat", jarg("player", player));
	}
	void OnPlayerQuestAbandon(Player * player, uint32_t const questId) override {
		NodeJs::invoke_hook("player:quest-abandon", jarg("player", player), jarg("questId", questId));
	}
	void OnPlayerQuestAccept(Player * player, Quest const * quest) override {
		NodeJs::invoke_hook("player:quest-accept", jarg("player", player), jarg("quest", quest));
	}
	[[nodiscard]] bool OnPlayerCanFlyInZone(Player * player, uint32_t const mapId, uint32_t const zoneId, SpellInfo const * bySpell) override {
		return NodeJs::invoke_hook_t("player:can-fly-in-zone", PlayerScript::OnPlayerCanFlyInZone(player, mapId, zoneId, bySpell)
			, jarg("player", player), jarg("mapId", mapId), jarg("zoneId", zoneId), jarg("bySpell", bySpell));
	}
	void AnticheatSetCanFlybyServer(Player * player, bool const apply) override {
		NodeJs::invoke_hook("player:anticheat:set-can-flyby-server", jarg("player", player), jarg("apply", apply));
	}
	void AnticheatSetUnderACKmount(Player * player) override {
		NodeJs::invoke_hook("player:anticheat:set-under-ack-mount", jarg("player", player));
	}
	void AnticheatSetRootACKUpd(Player * player) override {
		NodeJs::invoke_hook("player:anticheat:set-root-ack-upd", jarg("player", player));
	}
	void AnticheatSetJumpingbyOpcode(Player * player, bool const jump) override {
		NodeJs::invoke_hook("player:anticheat:set-jumping-by-opcode", jarg("player", player), jarg("jump", jump));
	}
	void AnticheatUpdateMovementInfo(Player * player, MovementInfo const & movementInfo) override {
		NodeJs::invoke_hook("player:anticheat:update-movement-info", jarg("player", player)/*, jarg("movementInfo", movementInfo)*/);
	}
	[[nodiscard]] bool AnticheatHandleDoubleJump(Player * player, Unit * mover) override {
		return NodeJs::invoke_hook_t("player:anticheat-handle-double-jump", PlayerScript::AnticheatHandleDoubleJump(player, mover)
			, jarg("player", player), jarg("mover", mover));
	}
	[[nodiscard]] bool AnticheatCheckMovementInfo(Player * player, MovementInfo const & movementInfo, Unit * mover, bool const jump) override {
		return NodeJs::invoke_hook_t("player:anticheat-check-movement-info", PlayerScript::AnticheatCheckMovementInfo(player, movementInfo, mover, jump)
			, jarg("player", player)/*, jarg("movementInfo", movementInfo)*/, jarg("mover", mover), jarg("jump", jump));
	}
	bool OnPlayerCanSendErrorAlreadyLooted(Player * player) override {
		return NodeJs::invoke_hook_t("player:can-send-error-already-looted", PlayerScript::OnPlayerCanSendErrorAlreadyLooted(player)
			, jarg("player", player));
	}
	void OnPlayerAfterCreatureLoot(Player * player) override {
		NodeJs::invoke_hook("player:after-creature-loot", jarg("player", player));
	}
	void OnPlayerAfterCreatureLootMoney(Player * player) override {
		NodeJs::invoke_hook("player:after-creature-loot-money", jarg("player", player));
	}
	bool OnPlayerCanUpdateSkill(Player * player, uint32_t const skillId) override {
		return NodeJs::invoke_hook_t("player:can-update-skill", PlayerScript::OnPlayerCanUpdateSkill(player, skillId)
			, jarg("player", player), jarg("skillId", skillId));
	}
	void OnPlayerBeforeUpdateSkill(Player * player, uint32_t const skillId, uint32_t & value, uint32_t const max, uint32_t const step) override {
		NodeJs::invoke_hook("player:before-update-skill", jarg("player", player), jarg("skillId", skillId), jarg_inout("value", value), jarg("max", max), jarg("step", step));
	}
	void OnPlayerUpdateSkill(Player * player, uint32_t const skillId, uint32_t const value, uint32_t const max, uint32_t const step, uint32_t const newValue) override {
		NodeJs::invoke_hook("player:update-skill", jarg("player", player), jarg("skillId", skillId), jarg("value", value), jarg("max", max), jarg("step", step), jarg("newValue", newValue));
	}
	void OnPlayerSetSkill(Player * player, uint32_t const skillId, uint32_t const value, uint32_t const max, uint32_t const step, uint32_t const newValue) override {
		NodeJs::invoke_hook("player:set-skill", jarg("player", player), jarg("skillId", skillId), jarg("value", value), jarg("max", max), jarg("step", step), jarg("newValue", newValue));
	}
	bool OnPlayerCanResurrect(Player * player) override {
		return NodeJs::invoke_hook_t("player:can-resurrect", PlayerScript::OnPlayerCanResurrect(player)
			, jarg("player", player));
	}
	bool OnPlayerCanGiveLevel(Player * player, uint8_t const newLevel) override {
		return NodeJs::invoke_hook_t("player:can-give-level", PlayerScript::OnPlayerCanGiveLevel(player, newLevel)
			, jarg("player", player), jarg("newLevel", newLevel));
	}
	void OnPlayerSendListInventory(Player * player, ObjectGuid const vendorGuid, uint32_t & vendorEntry) override {
		NodeJs::invoke_hook("player:send-list-inventory", jarg("player", player), jarg("vendorGuid", vendorGuid), jarg_inout("vendorEntry", vendorEntry));
	}
	void OnPlayerGetReputationPriceDiscount(Player const * player, Creature const * creature, float & discount) override {
		NodeJs::invoke_hook("player:get-reputation-price-discount:by-creature", jarg("player", player), jarg("creature", creature), jarg_inout("discount", discount));
	}
	void OnPlayerGetReputationPriceDiscount(Player const * player, FactionTemplateEntry const * factionTemplate, float & discount) override {
		NodeJs::invoke_hook("player:get-reputation-price-discount", jarg("player", player)/*, jarg("factionTemplate", factionTemplate)*/, jarg_inout("discount", discount));
	}
	void OnPlayerLearnTaxiNode(Player const * player, uint32_t const nodeId) override {
		NodeJs::invoke_hook("player:learn-taxi-node", jarg("player", player), jarg("nodeId", nodeId));
	}
	void OnPlayerBeforeGetLevelForXPGain(Player const * player, uint8_t & level) override {
		NodeJs::invoke_hook("player:before-get-level-for-xp-gain", jarg("player", player), jarg_inout("level", level));
	}
};

void AddSC_Player() {
	new NODEJS_player();
}
