#include "PlayerScript.h"

#include "DurationWrapper.h"
#include "Group.h"
#include "Guild.h"
#include "LootMgr.h"
#include "NodeJs.h"

class NODEJS_player : public PlayerScript {
public:
	NODEJS_player() : PlayerScript("NODEJS_player") {
	}

	void OnPlayerJustDied(Player * player) override {
		NodeJs::invoke_hook("player:just-died"
			, jprop("player", player));
	}
	void OnPlayerCalculateTalentsPoints(Player const * player, uint32_t & talentPointsForLevel) override {
		NodeJs::invoke_hook("player:calculate-talents-points"
			, jprop("player", player), jprop_box("talentPointsForLevel", talentPointsForLevel));
	}
	void OnPlayerReleasedGhost(Player * player) override {
		NodeJs::invoke_hook("player:released-ghost"
			, jprop("player", player));
	}
	void OnPlayerSendInitialPacketsBeforeAddToMap(Player * player, WorldPacket & data) override {
		NodeJs::invoke_hook("player:send-initial-packets-before-add-to-map"
			, jprop("player", player), jprop("data", &data));
	}
	void OnPlayerBattlegroundDesertion(Player * player, BattlegroundDesertionType const desertionType) override {
		NodeJs::invoke_hook("player:battleground-desertion"
			, jprop("player", player), jprop("desertionType", desertionType));
	}
	void OnPlayerCompleteQuest(Player * player, Quest const * quest_id) override {
		NodeJs::invoke_hook("player:complete-quest"
			, jprop("player", player), jprop("quest", quest_id));
	}
	void OnPlayerPVPKill(Player * killer, Player * killed) override {
		NodeJs::invoke_hook("player:pvp-kill"
			, jprop("killer", killer), jprop("killed", killed));
	}
	void OnPlayerPVPFlagChange(Player * player, bool const state) override {
		NodeJs::invoke_hook("player:pvp-flag-change"
			, jprop("player", player), jprop("state", state));
	}
	void OnPlayerCreatureKill(Player * killer, Creature * killed) override {
		NodeJs::invoke_hook("player:creature-kill"
			, jprop("killer", killer), jprop("killed", killed));
	}
	void OnPlayerCreatureKilledByPet(Player * PetOwner, Creature * killed) override {
		NodeJs::invoke_hook("player:creature-killed-by-pet"
			, jprop("petOwner", PetOwner), jprop("killed", killed));
	}
	void OnPlayerKilledByCreature(Creature * killer, Player * killed) override {
		NodeJs::invoke_hook("player:killed-by-creature"
			, jprop("killer", killer), jprop("killed", killed));
	}
	void OnPlayerLevelChanged(Player * player, uint8_t const oldlevel) override{
		NodeJs::invoke_hook("player:level-changed"
			, jprop("player", player), jprop("oldLevel", oldlevel));
	}
	void OnPlayerFreeTalentPointsChanged(Player * player, uint32_t const points) override {
		NodeJs::invoke_hook("player:free-talent-points-changed"
			, jprop("player", player), jprop("points", points));
	}
	void OnPlayerTalentsReset(Player * player, bool const noCost) override {
		NodeJs::invoke_hook("player:talents-reset"
			, jprop("player", player), jprop("noCost", noCost));
	}
	bool OnPlayerCanLearnTalent(Player * player, TalentEntry const * talent, uint32_t const rank) override {
		return NodeJs::invoke_hook_t("player:can-learn-talent", PlayerScript::OnPlayerCanLearnTalent(player, talent, rank)
			, jprop("player", player)/*, jprop("talent", talent)*/, jprop("rank", rank));
	}
	void OnPlayerAfterSpecSlotChanged(Player * player, uint8_t const newSlot) override {
		NodeJs::invoke_hook("player:after-spec-slot-changed"
			, jprop("player", player), jprop("newSlot", newSlot));
	}
	void OnPlayerBeforeUpdate(Player * player, uint32_t const p_time) override {
		NodeJs::invoke_hook("player:before-update"
			, jprop("player", player), jprop("diff", DurationWrapper::from_milliseconds(p_time)));
	}
	void OnPlayerUpdate(Player * player, uint32_t const p_time) override {
		NodeJs::invoke_hook("player:update"
			, jprop("player", player), jprop("diff", DurationWrapper::from_milliseconds(p_time)));
	}
	void OnPlayerMoneyChanged(Player * player, int32_t & amount) override {
		NodeJs::invoke_hook("player:money-changed"
			, jprop("player", player), jprop_box("amount", amount));
	}
	void OnPlayerBeforeLootMoney(Player * player, Loot * loot) override {
		NodeJs::invoke_hook("player:before-loot-money"
			, jprop("player", player), jprop("loot", loot));
	}
	void OnPlayerGiveXP(Player * player, uint32_t & amount, Unit * victim, uint8_t const xpSource) override {
		NodeJs::invoke_hook("player:give-xp"
			, jprop("player", player), jprop_box("amount", amount), jprop("victim", victim), jprop("xpSource", xpSource));
	}
	bool OnPlayerReputationChange(Player * player, uint32_t const factionID, int32_t & standing, bool const incremental) override {
		return NodeJs::invoke_hook_t("player:reputation-change", PlayerScript::OnPlayerReputationChange(player, factionID, standing, incremental)
			, jprop("player", player), jprop("factionId", factionID), jprop_box("standing", standing), jprop("incremental", incremental));
	}
	void OnPlayerReputationRankChange(Player * player, uint32_t const factionID, ReputationRank const newRank, ReputationRank const olRank, bool const increased) override {
		NodeJs::invoke_hook("player:reputation-rank-change"
			, jprop("player", player), jprop("factionId", factionID), jprop("newRank", newRank), jprop("oldRank", olRank), jprop("increased", increased));
	}
	void OnPlayerGiveReputation(Player * player, int32_t const factionID, float & amount, ReputationSource const repSource) override {
		NodeJs::invoke_hook("player:give-reputation"
			, jprop("player", player), jprop("factionId", factionID), jprop_box("amount", amount), jprop("repSource", repSource));
	}
	void OnPlayerLearnSpell(Player * player, uint32_t const spellID) override {
		NodeJs::invoke_hook("player:learn-spell"
			, jprop("player", player), jprop("spellId", spellID));
	}
	void OnPlayerForgotSpell(Player * player, uint32_t const spellID) override {
		NodeJs::invoke_hook("player:forgot-spell"
			, jprop("player", player), jprop("spellId", spellID));
	}
	void OnPlayerDuelRequest(Player * target, Player * challenger) override {
		NodeJs::invoke_hook("player:duel-request"
			, jprop("target", target), jprop("challenger", challenger));
	}
	void OnPlayerDuelStart(Player * player1, Player * player2) override {
		NodeJs::invoke_hook("player:duel-start"
			, jprop("player1", player1), jprop("player2", player2));
	}
	void OnPlayerDuelEnd(Player * winner, Player * loser, DuelCompleteType const type) override {
		NodeJs::invoke_hook("player:duel-end"
			, jprop("winner", winner), jprop("loser", loser), jprop("type", type));
	}
	void OnPlayerBeforeSendChatMessage(Player * player, uint32_t & type, uint32_t & lang, std::string & msg) override {
		NodeJs::invoke_hook("player:before-send-chat-message"
			, jprop("player", player), jprop_box("type", type), jprop_box("lang", lang), jprop_box("msg", msg));
	}
	void OnPlayerEmote(Player * player, uint32_t const emote) override {
		NodeJs::invoke_hook("player:emote"
			, jprop("player", player), jprop("emote", emote));
	}
	void OnPlayerTextEmote(Player * player, uint32_t const textEmote, uint32_t const emoteNum, ObjectGuid const guid) override {
		NodeJs::invoke_hook("player:text-emote"
			, jprop("player", player), jprop("textEmote", textEmote), jprop("emoteNum", emoteNum), jprop("guid", guid));
	}
	void OnPlayerSpellCast(Player * player, Spell * spell, bool const skipCheck) override {
		NodeJs::invoke_hook("player:spell-cast"
			, jprop("player", player), jprop("spell", spell), jprop("skipCheck", skipCheck));
	}
	void OnPlayerLoadFromDB(Player * player) override {
		NodeJs::invoke_hook("player:load-from-db"
			, jprop("player", player));
	}
	void OnPlayerLogin(Player * player) override {
		NodeJs::invoke_hook("player:login"
			, jprop("player", player));
	}
	void OnPlayerBeforeLogout(Player * player) override {
		NodeJs::invoke_hook("player:before-logout"
			, jprop("player", player));
	}
	void OnPlayerLogout(Player * player) override {
		NodeJs::invoke_hook("player:logout"
			, jprop("player", player));
	}
	void OnPlayerCreate(Player * player) override {
		NodeJs::invoke_hook("player:create"
			, jprop("player", player));
	}
	void OnPlayerDelete(ObjectGuid const guid, uint32_t const accountId) override {
		NodeJs::invoke_hook("player:delete"
			, jprop("guid", guid), jprop("accountId", accountId));
	}
	void OnPlayerFailedDelete(ObjectGuid const guid, uint32_t const accountId) override {
		NodeJs::invoke_hook("player:failed-delete"
			, jprop("guid", guid), jprop("accountId", accountId));
	}
	void OnPlayerSave(Player * player) override {
		NodeJs::invoke_hook("player:save"
			, jprop("player", player));
	}
	void OnPlayerBindToInstance(Player * player, Difficulty const difficulty, uint32_t const mapId, bool const permanent) override {
		NodeJs::invoke_hook("player:bind-to-instance"
			, jprop("player", player), jprop("difficulty", difficulty), jprop("mapId", mapId), jprop("permanent", permanent));
	}
	void OnPlayerUpdateZone(Player * player, uint32_t const newZone, uint32_t const newArea) override {
		NodeJs::invoke_hook("player:update-zone"
			, jprop("player", player), jprop("newZone", newZone), jprop("newArea", newArea));
	}
	void OnPlayerUpdateArea(Player * player, uint32_t const oldArea, uint32_t const newArea) override {
		NodeJs::invoke_hook("player:update-area"
			, jprop("player", player), jprop("oldArea", oldArea), jprop("newArea", newArea));
	}
	void OnPlayerMapChanged(Player * player) override {
		NodeJs::invoke_hook("player:map-changed"
			, jprop("player", player));
	}
	[[nodiscard]] bool OnPlayerBeforeTeleport(Player * player, uint32_t const mapid, float const x, float const y, float const z, float const orientation, uint32_t const options, Unit * target) override {
		return NodeJs::invoke_hook_t("player:before-teleport", PlayerScript::OnPlayerBeforeTeleport(player, mapid, x, y, z, orientation, options, target)
			, jprop("player", player), jprop("mapId", mapid), jprop("x", x), jprop("y", y), jprop("z", z), jprop("o", orientation), jprop("options", options), jprop("target", target));
	}
	void OnPlayerUpdateFaction(Player * player) override {
		NodeJs::invoke_hook("player:update-faction"
			, jprop("player", player));
	}
	void OnPlayerAddToBattleground(Player * player, Battleground * bg) override {
		NodeJs::invoke_hook("player:add-to-battleground"
			, jprop("player", player), jprop("bg", bg));
	}
	void OnPlayerQueueRandomDungeon(Player * player, uint32_t & rDungeonId) override {
		NodeJs::invoke_hook("player:queue-random-dungeon"
			, jprop("player", player), jprop_box("rDungeonId", rDungeonId));
	}
	void OnPlayerRemoveFromBattleground(Player * player, Battleground * bg) override {
		NodeJs::invoke_hook("player:remove-from-battleground"
			, jprop("player", player), jprop("bg", bg));
	}
	void OnPlayerAchievementComplete(Player * player, AchievementEntry const * achievement) override {
		NodeJs::invoke_hook("player:achievement-complete"
			, jprop("player", player), jprop("achievement", achievement));
	}
	bool OnPlayerBeforeAchievementComplete(Player * player, AchievementEntry const * achievement) override {
		return NodeJs::invoke_hook_t("player:before-achievement-complete", PlayerScript::OnPlayerBeforeAchievementComplete(player, achievement)
			, jprop("player", player), jprop("achievement", achievement));
	}
	void OnPlayerCriteriaProgress(Player * player, AchievementCriteriaEntry const * criteria) override {
		NodeJs::invoke_hook("player:criteria-progress"
			, jprop("player", player)/*, jprop("criteria", criteria)*/);
	}
	bool OnPlayerBeforeCriteriaProgress(Player * player, AchievementCriteriaEntry const * criteria) override {
		return NodeJs::invoke_hook_t("player:before-criteria-progress", PlayerScript::OnPlayerBeforeCriteriaProgress(player, criteria)
			, jprop("player", player)/*, jprop("criteria", criteria)*/);
	}
	void OnPlayerAchievementSave(CharacterDatabaseTransaction trans, Player * player, uint16_t const achId, CompletedAchievementData achiData) override {
		if (!NodeJs::hook_has_listeners("player:achievement-save")) {
			return;
		}
		auto & transaction_ref = current_transaction<Db::Character>();
		auto prev_trans = transaction_ref;
		transaction_ref = trans;
		try {
			NodeJs::invoke_hook("player:achievement-save"
				, jprop("player", player), jprop("achId", achId)/*, jprop("achiData", achiData)*/);
		} catch (std::logic_error const &) {
			transaction_ref = prev_trans;
			throw;
		}
		transaction_ref = prev_trans;
	}
	void OnPlayerCriteriaSave(CharacterDatabaseTransaction trans, Player * player, uint16_t const achId, CriteriaProgress criteriaData) override {
		if (!NodeJs::hook_has_listeners("player:criteria-save")) {
			return;
		}
		auto & transaction_ref = current_transaction<Db::Character>();
		auto prev_trans = transaction_ref;
		transaction_ref = trans;
		try {
			NodeJs::invoke_hook("player:criteria-save"
				, jprop("player", player), jprop("achId", achId)/*, jprop("criteriaData", criteriaData)*/);
		} catch (std::logic_error const &) {
			transaction_ref = prev_trans;
			throw;
		}
		transaction_ref = prev_trans;
	}
	void OnPlayerGossipSelect(Player * player, uint32_t const menu_id, uint32_t const sender, uint32_t const action) override {
		NodeJs::invoke_hook("player:gossip-select"
			, jprop("player", player), jprop("menuId", menu_id), jprop("sender", sender), jprop("action", action));
	}
	void OnPlayerGossipSelectCode(Player * player, uint32_t const menu_id, uint32_t const sender, uint32_t const action, const char * code) override {
		NodeJs::invoke_hook("player:gossip-select-code"
			, jprop("player", player), jprop("menuId", menu_id), jprop("sender", sender), jprop("action", action), jprop("code", code));
	}
	void OnPlayerBeingCharmed(Player * player, Unit * charmer, uint32_t const oldFactionId, uint32_t const newFactionId) override {
		NodeJs::invoke_hook("player:being-charmed"
			, jprop("player", player), jprop("charmer", charmer), jprop("oldFactionId", oldFactionId), jprop("newFactionId", newFactionId));
	}
	void OnPlayerAfterSetVisibleItemSlot(Player * player, uint8_t const slot, Item * item) override {
		NodeJs::invoke_hook("player:after-set-visible-item-slot"
			, jprop("player", player), jprop("slot", slot), jprop("item", item));
	}
	void OnPlayerAfterMoveItemFromInventory(Player * player, Item * it, uint8_t const bag, uint8_t const slot, bool const update) override {
		NodeJs::invoke_hook("player:after-move-item-from-inventory"
			, jprop("player", player), jprop("item", it), jprop("bag", bag), jprop("slot", slot), jprop("update", update));
	}
	void OnPlayerEquip(Player * player, Item * it, uint8_t const bag, uint8_t const slot, bool const update) override {
		NodeJs::invoke_hook("player:equip"
			, jprop("player", player), jprop("item", it), jprop("bag", bag), jprop("slot", slot), jprop("update", update));
	}
	void OnPlayerUnequip(Player * player, Item * it) override {
		NodeJs::invoke_hook("player:unequip"
			, jprop("player", player), jprop("item", it));
	}
	void OnPlayerJoinBG(Player * player) override {
		NodeJs::invoke_hook("player:join-bg"
			, jprop("player", player));
	}
	void OnPlayerJoinArena(Player * player) override {
		NodeJs::invoke_hook("player:join-arena"
			, jprop("player", player));
	}
	void OnPlayerGetMaxPersonalArenaRatingRequirement(Player const * player, uint32_t const minSlot, uint32_t & maxArenaRating) const override   {
		NodeJs::invoke_hook("player:get-max-personal-arena-rating-requirement"
			, jprop("player", player), jprop("minSlot", minSlot), jprop_box("maxArenaRating", maxArenaRating));
	}
	void OnPlayerLootItem(Player * player, Item * item, uint32_t const count, ObjectGuid const lootguid) override {
		NodeJs::invoke_hook("player:loot-item"
			, jprop("player", player), jprop("item", item), jprop("count", count), jprop("lootGuid", lootguid));
	}
	void OnPlayerBeforeFillQuestLootItem(Player * player, LootItem & item) override {
		// TOOD: undefined symbol: std::optional<LootItem> cval<LootItem>(v8::Local<v8::Value>)
		NodeJs::invoke_hook("player:before-fill-quest-loot-item"
			, jprop("player", player), jprop/*_inout*/("item", item));
	}
	void OnPlayerStoreNewItem(Player * player, Item * item, uint32_t const count) override {
		NodeJs::invoke_hook("player:store-new-item"
			, jprop("player", player), jprop("item", item), jprop("count", count));
	}
	void OnPlayerCreateItem(Player * player, Item * item, uint32_t const count) override {
		NodeJs::invoke_hook("player:create-item"
			, jprop("player", player), jprop("item", item), jprop("count", count));
	}
	void OnPlayerQuestRewardItem(Player * player, Item * item, uint32_t const count) override {
		NodeJs::invoke_hook("player:quest-reward-item"
			, jprop("player", player), jprop("item", item), jprop("count", count));
	}
	[[nodiscard]] bool OnPlayerCanPlaceAuctionBid(Player * player, AuctionEntry * auction) override {
		return NodeJs::invoke_hook_t("player:can-place-auction-bid", PlayerScript::OnPlayerCanPlaceAuctionBid(player, auction)
			, jprop("player", player), jprop("auction", auction));
	}
	void OnPlayerGroupRollRewardItem(Player * player, Item * item, uint32_t const count, RollVote const voteType, Roll * roll) override {
		NodeJs::invoke_hook("player:group-roll-reward-item"
			, jprop("player", player), jprop("item", item), jprop("count", count), jprop("voteType", voteType), jprop("roll", roll));
	}
	[[nodiscard]] bool OnPlayerBeforeOpenItem(Player * player, Item * item) override {
		return NodeJs::invoke_hook_t("player:before-open-item", PlayerScript::OnPlayerBeforeOpenItem(player, item)
			, jprop("player", player), jprop("item", item));
	}
	[[nodiscard]] bool OnPlayerBeforeQuestComplete(Player * player, uint32_t const quest_id) override {
		return NodeJs::invoke_hook_t("player:before-quest-complete", PlayerScript::OnPlayerBeforeQuestComplete(player, quest_id)
			, jprop("player", player), jprop("questId", quest_id));
	}
	void OnPlayerQuestComputeXP(Player * player, Quest const * quest, uint32_t & xpValue) override {
		NodeJs::invoke_hook("player:quest-compute-xp"
			, jprop("player", player), jprop("quest", quest), jprop_box("xpValue", xpValue));
	}
	void OnPlayerBeforeDurabilityRepair(Player * player, ObjectGuid const npcGUID, ObjectGuid const itemGUID, float &discountMod, uint8_t const guildBank) override {
		NodeJs::invoke_hook("player:before-durability-repair"
			, jprop("player", player), jprop("npcGuid", npcGUID), jprop("itemGuid", itemGUID), jprop_box("discountMod", discountMod), jprop("guildBank", guildBank != 0));
	}
	void OnPlayerBeforeBuyItemFromVendor(Player * player, ObjectGuid const vendorguid, uint32_t const vendorslot, uint32_t & item, uint8_t const count, uint8_t const bag, uint8_t const slot) override {
		NodeJs::invoke_hook("player:before-buy-item-from-vendor"
			, jprop("player", player), jprop("vendorGuid", vendorguid), jprop("vendorSlot", vendorslot), jprop_box("item", item), jprop("count", count), jprop("bag", bag), jprop("slot", slot));
	}
	void OnPlayerBeforeStoreOrEquipNewItem(Player * player, uint32_t const vendorslot, uint32_t & item, uint8_t const count, uint8_t const bag, uint8_t const slot, ItemTemplate const * pProto, Creature * pVendor, VendorItem const * crItem, bool const bStore) override {
		NodeJs::invoke_hook("player:before-store-or-equip-new-item"
			, jprop("player", player), jprop("vendorSlot", vendorslot), jprop_box("item", item), jprop("count", count), jprop("bag", bag), jprop("slot", slot), jprop("proto", pProto), jprop("vendor", pVendor)/*, jprop("crItem", crItem)*/, jprop("store", bStore));
	}
	void OnPlayerAfterStoreOrEquipNewItem(Player * player, uint32_t const vendorslot, Item * item, uint8_t const count, uint8_t const bag, uint8_t const slot, ItemTemplate const * pProto, Creature * pVendor, VendorItem const * crItem, bool const bStore) override {
		NodeJs::invoke_hook("player:after-store-or-equip-new-item"
			, jprop("player", player), jprop("vendorSlot", vendorslot), jprop("item", item), jprop("count", count), jprop("bag", bag), jprop("slot", slot), jprop("proto", pProto), jprop("vendor", pVendor)/*, jprop("crItem", crItem)*/, jprop("store", bStore));
	}
	void OnPlayerAfterUpdateMaxPower(Player * player, Powers & power, float & value) override {
		NodeJs::invoke_hook("player:after-update-max-power"
			, jprop("player", player), jprop_box("power", power), jprop_box("value", value));
	}
	void OnPlayerAfterUpdateMaxHealth(Player * player, float & value) override {
		NodeJs::invoke_hook("player:after-update-max-health"
			, jprop("player", player), jprop_box("value", value));
	}
	void OnPlayerBeforeUpdateAttackPowerAndDamage(Player * player, float & level, float & val2, bool const ranged) override {
		NodeJs::invoke_hook("player:before-update-attack-power-and-damage"
			, jprop("player", player), jprop_box("level", level), jprop_box("val2", val2), jprop("ranged", ranged));
	}
	void OnPlayerAfterUpdateAttackPowerAndDamage(Player * player, float & level, float & base_attPower, float & attPowerMod, float & attPowerMultiplier, bool const ranged) override {
		NodeJs::invoke_hook("player:after-update-attack-power-and-damage"
			, jprop("player", player), jprop_box("level", level), jprop_box("baseAttPower", base_attPower), jprop_box("attPowerMod", attPowerMod), jprop_box("attPowerMultiplier", attPowerMultiplier), jprop("ranged", ranged));
	}
	void OnPlayerBeforeInitTalentForLevel(Player * player, uint8_t & level, uint32_t & talentPointsForLevel) override {
		NodeJs::invoke_hook("player:before-init-talent-for-level"
			, jprop("player", player), jprop_box("level", level), jprop_box("talentPointsForLevel", talentPointsForLevel));
	}
	void OnPlayerFirstLogin(Player * player) override {
		NodeJs::invoke_hook("player:first-login"
			, jprop("player", player));
	}
	void OnPlayerSetMaxLevel(Player * player, uint32_t & maxPlayerLevel) override {
		NodeJs::invoke_hook("player:set-max-level"
			, jprop("player", player), jprop_box("maxPlayerLevel", maxPlayerLevel));
	}
	[[nodiscard]] bool OnPlayerCanJoinInBattlegroundQueue(Player * player, ObjectGuid const BattlemasterGuid, BattlegroundTypeId const BGTypeID, uint8_t const joinAsGroup, GroupJoinBattlegroundResult & err) override {
		return NodeJs::invoke_hook_t("player:can-join-in-battleground-queue", PlayerScript::OnPlayerCanJoinInBattlegroundQueue(player, BattlemasterGuid, BGTypeID, joinAsGroup, err)
			, jprop("player", player), jprop("battlemasterGuid", BattlemasterGuid), jprop("bgTypeId", BGTypeID), jprop("joinAsGroup", joinAsGroup != 0), jprop_box("err", err));
	}
	bool OnPlayerShouldBeRewardedWithMoneyInsteadOfExp(Player * player) override {
		return NodeJs::invoke_hook_t("player:should-be-rewarded-with-money-instead-of-exp", PlayerScript::OnPlayerShouldBeRewardedWithMoneyInsteadOfExp(player)
			, jprop("player", player));
	}
	void OnPlayerBeforeTempSummonInitStats(Player * player, TempSummon * tempSummon, uint32_t & duration) override {
		if (!NodeJs::hook_has_listeners("player:before-temp-summon-init-stats")) {
			return;
		}
		auto durationWrapper = DurationWrapper::from_milliseconds(duration);
		NodeJs::invoke_hook("player:before-temp-summon-init-stats"
			, jprop("player", player), jprop("tempSummon", tempSummon), jprop_box("duration", durationWrapper));
		duration = durationWrapper.count<Milliseconds>();
	}
	void OnPlayerBeforeGuardianInitStatsForLevel(Player * player, Guardian * guardian, CreatureTemplate const * cinfo, PetType & petType) override {
		NodeJs::invoke_hook("player:before-guardian-init-stats-for-level"
			, jprop("player", player), jprop("guardian", guardian), jprop("cInfo", cinfo), jprop_box("petType", petType));
	}
	void OnPlayerAfterGuardianInitStatsForLevel(Player * player, Guardian * guardian) override {
		NodeJs::invoke_hook("player:after-guardian-init-stats-for-level"
			, jprop("player", player), jprop("guardian", guardian));
	}
	void OnPlayerBeforeLoadPetFromDB(Player * player, uint32_t & petentry, uint32_t & petnumber, bool & current, bool & forceLoadFromDB) override {
		NodeJs::invoke_hook("player:before-load-pet-from-db"
			, jprop("player", player), jprop_box("petEntry", petentry), jprop_box("petNumber", petnumber), jprop_box("current", current), jprop_box("forceLoadFromDB", forceLoadFromDB));
	}
	[[nodiscard]] bool OnPlayerCanJoinInArenaQueue(Player * player, ObjectGuid const BattlemasterGuid, uint8_t const arenaslot, BattlegroundTypeId const BGTypeID, uint8_t const joinAsGroup, uint8_t const IsRated, GroupJoinBattlegroundResult & err) override {
		return NodeJs::invoke_hook_t("player:can-join-in-arena-queue", PlayerScript::OnPlayerCanJoinInArenaQueue(player, BattlemasterGuid, arenaslot, BGTypeID, joinAsGroup, IsRated, err)
			, jprop("player", player), jprop("battlemasterGuid", BattlemasterGuid), jprop("arenaSlot", arenaslot), jprop("bgTypeId", BGTypeID), jprop("joinAsGroup", joinAsGroup), jprop("isRated", IsRated), jprop_box("err", err));
	}
	[[nodiscard]] bool OnPlayerCanBattleFieldPort(Player * player, uint8_t const arenaType, BattlegroundTypeId const BGTypeID, uint8_t const action) override {
		return NodeJs::invoke_hook_t("player:can-battle-field-port", PlayerScript::OnPlayerCanBattleFieldPort(player, arenaType, BGTypeID, action)
			, jprop("player", player), jprop("arenaType", arenaType), jprop("bgTypeId", BGTypeID), jprop("action", action));
	}
	[[nodiscard]] bool OnPlayerCanGroupInvite(Player * player, std::string & membername) override {
		return NodeJs::invoke_hook_t("player:can-group-invite", PlayerScript::OnPlayerCanGroupInvite(player, membername)
			, jprop("player", player), jprop_box("memberName", membername));
	}
	[[nodiscard]] bool OnPlayerCanGroupAccept(Player * player, Group * group) override {
		return NodeJs::invoke_hook_t("player:can-group-accept", PlayerScript::OnPlayerCanGroupAccept(player, group)
			, jprop("player", player), jprop("group", group));
	}
	[[nodiscard]] bool OnPlayerCanSellItem(Player * player, Item * item, Creature * creature) override {
		return NodeJs::invoke_hook_t("player:can-sell-item", PlayerScript::OnPlayerCanSellItem(player, item, creature)
			, jprop("player", player), jprop("item", item), jprop("creature", creature));
	}
	[[nodiscard]] bool OnPlayerCanSendMail(Player * player, ObjectGuid const receiverGuid, ObjectGuid const mailbox, std::string & subject, std::string & body, uint32_t const money, uint32_t const COD, Item * item) override {
		return NodeJs::invoke_hook_t("player:can-send-mail", PlayerScript::OnPlayerCanSendMail(player, receiverGuid, mailbox, subject, body, money, COD, item)
			, jprop("player", player), jprop("receiverGuid", receiverGuid), jprop("mailbox", mailbox), jprop_box("subject", subject), jprop_box("body", body), jprop("money", money), jprop("cod", COD), jprop("item", item));
	}
	void OnPlayerPetitionBuy(Player * player, Creature * creature, uint32_t & charterid, uint32_t & cost, uint32_t & type) override {
		NodeJs::invoke_hook("player:petition-buy"
			, jprop("player", player), jprop("creature", creature), jprop_box("charterId", charterid), jprop_box("cost", cost), jprop_box("type", type));
	}
	void OnPlayerPetitionShowList(Player * player, Creature * creature, uint32_t & CharterEntry, uint32_t & CharterDispayID, uint32_t & CharterCost) override {
		NodeJs::invoke_hook("player:petition-show-list"
			, jprop("player", player), jprop("creature", creature), jprop_box("charterEntry", CharterEntry), jprop_box("charterDisplayId", CharterDispayID), jprop_box("charterCost", CharterCost));
	}
	void OnPlayerRewardKillRewarder(Player * player, KillRewarder * rewarder, bool const isDungeon, float & rate) override {
		NodeJs::invoke_hook("player:reward-kill-rewarder"
			, jprop("player", player)/*, jprop("rewarder", rewarder)*/, jprop("isDungeon", isDungeon), jprop_box("rate", rate));
	}
	[[nodiscard]] bool OnPlayerCanGiveMailRewardAtGiveLevel(Player * player, uint8_t const level) override {
		return NodeJs::invoke_hook_t("player:can-give-mail-reward-at-give-level", PlayerScript::OnPlayerCanGiveMailRewardAtGiveLevel(player, level)
			, jprop("player", player), jprop("level", level));
	}
	void OnPlayerDeleteFromDB(CharacterDatabaseTransaction trans, uint32_t const guid) override {
		if (!NodeJs::hook_has_listeners("player:delete-from-db")) {
			return;
		}
		auto & transaction_ref = current_transaction<Db::Character>();
		auto prev_trans = transaction_ref;
		transaction_ref = trans;
		try {
			NodeJs::invoke_hook("player:delete-from-db"
				, jprop("guid", guid));
		} catch (std::logic_error const &) {
			transaction_ref = prev_trans;
			throw;
		}
		transaction_ref = prev_trans;
	}
	[[nodiscard]] bool OnPlayerCanRepopAtGraveyard(Player * player) override {
		return NodeJs::invoke_hook_t("player:can-repop-at-graveyard", PlayerScript::OnPlayerCanRepopAtGraveyard(player)
			, jprop("player", player));
	}
	[[nodiscard]] Optional<bool> OnPlayerIsClass(Player const * player, Classes const playerClass, ClassContext const context) override {
		return NodeJs::invoke_hook_t("player:is-class", PlayerScript::OnPlayerIsClass(player, playerClass, context)
			, jprop("player", player), jprop("playerClass", playerClass), jprop("context", context));
	}
	void OnPlayerGetMaxSkillValue(Player * player, uint32_t const skill, int32_t & result, bool const IsPure) override {
		NodeJs::invoke_hook("player:get-max-skill-value"
			, jprop("player", player), jprop("skill", skill), jprop_box("result", result), jprop("isPure", IsPure));
	}
	[[nodiscard]] bool OnPlayerHasActivePowerType(Player const * player, Powers const power) override {
		return NodeJs::invoke_hook_t("player:has-active-power-type", PlayerScript::OnPlayerHasActivePowerType(player, power)
			, jprop("player", player), jprop("power", power));
	}
	void OnPlayerUpdateGatheringSkill(Player * player, uint32_t const skill_id, uint32_t const current, uint32_t const gray, uint32_t const green, uint32_t const yellow, uint32_t & gain) override {
		NodeJs::invoke_hook("player:update-gathering-skill"
			, jprop("player", player), jprop("skillId", skill_id), jprop("current", current), jprop("gray", gray), jprop("green", green), jprop("yellow", yellow), jprop_box("gain", gain));
	}
	void OnPlayerUpdateCraftingSkill(Player * player, SkillLineAbilityEntry const * skill, uint32_t const current_level, uint32_t & gain) override {
		NodeJs::invoke_hook("player:update-crafting-skill"
			, jprop("player", player)/*, jprop("skill", skill)*/, jprop("currentLevel", current_level), jprop_box("gain", gain));
	}
	[[nodiscard]] bool OnPlayerUpdateFishingSkill(Player * player, int32_t const skill, int32_t const zone_skill, int32_t const chance, int32_t const roll) override {
		return NodeJs::invoke_hook_t("player:update-fishing-skill", PlayerScript::OnPlayerUpdateFishingSkill(player, skill, zone_skill, chance, roll)
			, jprop("player", player), jprop("skill", skill), jprop("zoneSkill", zone_skill), jprop("chance", chance), jprop("roll", roll));
	}
	[[nodiscard]] bool OnPlayerCanAreaExploreAndOutdoor(Player * player) override {
		return NodeJs::invoke_hook_t("player:can-area-explore-and-outdoor", PlayerScript::OnPlayerCanAreaExploreAndOutdoor(player)
			, jprop("player", player));
	}
	void OnPlayerVictimRewardBefore(Player * player, Player * victim, uint32_t & killer_title, int32_t & victim_rank) override {
		NodeJs::invoke_hook("player:victim-reward-before"
			, jprop("player", player), jprop("victim", victim), jprop_box("killerTitle", killer_title), jprop_box("victimRank", victim_rank));
	}
	void OnPlayerVictimRewardAfter(Player * player, Player * victim, uint32_t & killer_title, int32_t & victim_rank, float & honor_f) override {
		NodeJs::invoke_hook("player:victim-reward-after"
			, jprop("player", player), jprop("victim", victim), jprop_box("killerTitle", killer_title), jprop_box("victimRank", victim_rank), jprop_box("honor", honor_f));
	}
	void OnPlayerCustomScalingStatValueBefore(Player * player, ItemTemplate const * proto, uint8_t const slot, bool const apply, uint32_t & CustomScalingStatValue) override {
		NodeJs::invoke_hook("player:custom-scaling-stat-value-before"
			, jprop("player", player), jprop("proto", proto), jprop("slot", slot), jprop("apply", apply), jprop_box("customScalingStatValue", CustomScalingStatValue));
	}
	void OnPlayerCustomScalingStatValue(Player * player, ItemTemplate const * proto, uint32_t & statType, int32_t & val, uint8_t const itemProtoStatNumber, uint32_t const ScalingStatValue, ScalingStatValuesEntry const * ssv) override {
		NodeJs::invoke_hook("player:custom-scaling-stat-value"
			, jprop("player", player), jprop("proto", proto), jprop_box("statType", statType), jprop_box("val", val), jprop("itemProtoStatNumber", itemProtoStatNumber), jprop("scalingStatValue", ScalingStatValue)/*, jprop("ssv", ssv)*/);
	}
	void OnPlayerApplyItemModsBefore(Player * player, uint8_t const slot, bool const apply, uint8_t const itemProtoStatNumber, uint32_t const statType, int32_t & val) override {
		NodeJs::invoke_hook("player:apply-item-mods-before"
			, jprop("player", player), jprop("slot", slot), jprop("apply", apply), jprop("itemProtoStatNumber", itemProtoStatNumber), jprop("statType", statType), jprop_box("val", val));
	}
	void OnPlayerApplyEnchantmentItemModsBefore(Player * player, Item * item, EnchantmentSlot const slot, bool const apply, uint32_t const enchant_spell_id, uint32_t & enchant_amount) override {
		NodeJs::invoke_hook("player:apply-enchantment-item-mods-before"
			, jprop("player", player), jprop("item", item), jprop("slot", slot), jprop("apply", apply), jprop("enchantSpellId", enchant_spell_id), jprop_box("enchantAmount", enchant_amount));
	}
	void OnPlayerApplyWeaponDamage(Player * player, uint8_t const slot, ItemTemplate const * proto, float & minDamage, float & maxDamage, uint8_t const damageIndex) override {
		NodeJs::invoke_hook("player:apply-weapon-damage"
			, jprop("player", player), jprop("slot", slot), jprop("proto", proto), jprop_box("minDamage", minDamage), jprop_box("maxDamage", maxDamage), jprop("damageIndex", damageIndex));
	}
	[[nodiscard]] bool OnPlayerCanArmorDamageModifier(Player * player) override {
		return NodeJs::invoke_hook_t("player:can-armor-damage-modifier", PlayerScript::OnPlayerCanArmorDamageModifier(player)
			, jprop("player", player));
	}
	void OnPlayerGetFeralApBonus(Player * player, int32_t & feral_bonus, int32_t const dpsMod, ItemTemplate const * proto, ScalingStatValuesEntry const * ssv) override {
		NodeJs::invoke_hook("player:get-feral-ap-bonus"
			, jprop("player", player), jprop_box("feralBonus", feral_bonus), jprop("dpsMod", dpsMod), jprop("proto", proto)/*, jprop("ssv", ssv)*/);
	}
	[[nodiscard]] bool OnPlayerCanApplyWeaponDependentAuraDamageMod(Player * player, Item * item, WeaponAttackType const attackType, AuraEffect const * aura, bool const apply) override {
		return NodeJs::invoke_hook_t("player:can-apply-weapon-dependent-aura-damage-mod", PlayerScript::OnPlayerCanApplyWeaponDependentAuraDamageMod(player, item, attackType, aura, apply)
			, jprop("player", player), jprop("item", item), jprop("attackType", attackType), jprop("aura", aura), jprop("apply", apply));
	}
	[[nodiscard]] bool OnPlayerCanApplyEquipSpell(Player * player, SpellInfo const * spellInfo, Item * item, bool const apply, bool const form_change) override {
		return NodeJs::invoke_hook_t("player:can-apply-equip-spell", PlayerScript::OnPlayerCanApplyEquipSpell(player, spellInfo, item, apply, form_change)
			, jprop("player", player), jprop("spellInfo", spellInfo), jprop("item", item), jprop("apply", apply), jprop("formChange", form_change));
	}
	[[nodiscard]] bool OnPlayerCanApplyEquipSpellsItemSet(Player * player, ItemSetEffect * eff) override {
		return NodeJs::invoke_hook_t("player:can-apply-equip-spells-item-set", PlayerScript::OnPlayerCanApplyEquipSpellsItemSet(player, eff)
			, jprop("player", player)/*, jprop("eff", eff)*/);
	}
	[[nodiscard]] bool OnPlayerCanCastItemCombatSpell(Player * player, Unit * target, WeaponAttackType const attType, uint32_t const procVictim, uint32_t const procEx, Item * item, ItemTemplate const * proto) override {
		return NodeJs::invoke_hook_t("player:can-cast-item-combat-spell", PlayerScript::OnPlayerCanCastItemCombatSpell(player, target, attType, procVictim, procEx, item, proto)
			, jprop("player", player), jprop("target", target), jprop("attType", attType), jprop("procVictim", procVictim), jprop("procEx", procEx), jprop("item", item), jprop("proto", proto));
	}
	[[nodiscard]] bool OnPlayerCanCastItemUseSpell(Player * player, Item * item, SpellCastTargets const & targets, uint8_t const cast_count, uint32_t const glyphIndex) override {
		return NodeJs::invoke_hook_t("player:can-cast-item-use-spell", PlayerScript::OnPlayerCanCastItemUseSpell(player, item, targets, cast_count, glyphIndex)
			, jprop("player", player), jprop("item", item)/*, jprop("targets", targets)*/, jprop("castCount", cast_count), jprop("glyphIndex", glyphIndex));
	}
	void OnPlayerApplyAmmoBonuses(Player * player, ItemTemplate const * proto, float & currentAmmoDPS) override {
		NodeJs::invoke_hook("player:apply-ammo-bonuses"
			, jprop("player", player), jprop("proto", proto), jprop_box("currentAmmoDps", currentAmmoDPS));
	}
	[[nodiscard]] bool OnPlayerCanEquipItem(Player * player, uint8_t const slot, uint16_t & dest, Item * pItem, bool const swap, bool const not_loading) override {
		return NodeJs::invoke_hook_t("player:can-equip-item", PlayerScript::OnPlayerCanEquipItem(player, slot, dest, pItem, swap, not_loading)
			, jprop("player", player), jprop("slot", slot), jprop_box("dest", dest), jprop("item", pItem), jprop("swap", swap), jprop("notLoading", not_loading));
	}
	[[nodiscard]] bool OnPlayerCanUnequipItem(Player * player, uint16_t const pos, bool const swap) override {
		return NodeJs::invoke_hook_t("player:can-unequip-item", PlayerScript::OnPlayerCanUnequipItem(player, pos, swap)
			, jprop("player", player), jprop("pos", pos), jprop("swap", swap));
	}
	[[nodiscard]] bool OnPlayerCanUseItem(Player * player, ItemTemplate const * proto, InventoryResult & result) override {
		return NodeJs::invoke_hook_t("player:can-use-item", PlayerScript::OnPlayerCanUseItem(player, proto, result)
			, jprop("player", player), jprop("proto", proto), jprop_box("result", result));
	}
	[[nodiscard]] bool OnPlayerCanSaveEquipNewItem(Player * player, Item * item, uint16_t const pos, bool const update) override {
		return NodeJs::invoke_hook_t("player:can-save-equip-new-item", PlayerScript::OnPlayerCanSaveEquipNewItem(player, item, pos, update)
			, jprop("player", player), jprop("item", item), jprop("pos", pos), jprop("update", update));
	}
	[[nodiscard]] bool OnPlayerCanApplyEnchantment(Player * player, Item * item, EnchantmentSlot const slot, bool const apply, bool const apply_dur, bool const ignore_condition) override {
		return NodeJs::invoke_hook_t("player:can-apply-enchantment", PlayerScript::OnPlayerCanApplyEnchantment(player, item, slot, apply, apply_dur, ignore_condition)
			, jprop("player", player), jprop("item", item), jprop("slot", slot), jprop("apply", apply), jprop("applyDur", apply_dur), jprop("ignoreCondition", ignore_condition));
	}
	void OnPlayerGetQuestRate(Player * player, float & result) override {
		NodeJs::invoke_hook("player:get-quest-rate"
			, jprop("player", player), jprop_box("result", result));
	}
	[[nodiscard]] bool OnPlayerPassedQuestKilledMonsterCredit(Player * player, Quest const * qinfo, uint32_t const entry, uint32_t const real_entry, ObjectGuid const guid) override {
		return NodeJs::invoke_hook_t("player:passed-quest-killed-monster-credit", PlayerScript::OnPlayerPassedQuestKilledMonsterCredit(player, qinfo, entry, real_entry, guid)
			, jprop("player", player), jprop("qInfo", qinfo), jprop("entry", entry), jprop("realEntry", real_entry), jprop("guid", guid));
	}
	[[nodiscard]] bool OnPlayerCheckItemInSlotAtLoadInventory(Player * player, Item * item, uint8_t const slot, uint8_t & err, uint16_t & dest) override {
		return NodeJs::invoke_hook_t("player:check-item-in-slot-at-load-inventory", PlayerScript::OnPlayerCheckItemInSlotAtLoadInventory(player, item, slot, err, dest)
			, jprop("player", player), jprop("item", item), jprop("slot", slot), jprop_box("err", err), jprop_box("dest", dest));
	}
	[[nodiscard]] bool OnPlayerNotAvoidSatisfy(Player * player, DungeonProgressionRequirements const * ar, uint32_t const target_map, bool const report) override {
		return NodeJs::invoke_hook_t("player:not-avoid-satisfy", PlayerScript::OnPlayerNotAvoidSatisfy(player, ar, target_map, report)
			, jprop("player", player)/*, jprop("ar", ar)*/, jprop("targetMap", target_map), jprop("report", report));
	}
	[[nodiscard]] bool OnPlayerNotVisibleGloballyFor(Player * player, Player const * u) override {
		return NodeJs::invoke_hook_t("player:not-visible-globally-for", PlayerScript::OnPlayerNotVisibleGloballyFor(player, u)
			, jprop("player", player), jprop("u", u));
	}
	void OnPlayerGetArenaPersonalRating(Player * player, uint8_t const slot, uint32_t & result) override {
		NodeJs::invoke_hook("player:get-arena-personal-rating"
			, jprop("player", player), jprop("slot", slot), jprop_box("result", result));
	}
	void OnPlayerGetArenaTeamId(Player * player, uint8_t const slot, uint32_t & result) override {
		NodeJs::invoke_hook("player:get-arena-team-id"
			, jprop("player", player), jprop("slot", slot), jprop_box("result", result));
	}
	void OnPlayerIsFFAPvP(Player * player, bool & result) override {
		NodeJs::invoke_hook("player:is-ffa-pvp"
			, jprop("player", player), jprop_box("result", result));
	}
	void OnPlayerFfaPvpStateUpdate(Player * player, bool const result) override {
		NodeJs::invoke_hook("player:ffa-pvp-state-update"
			, jprop("player", player), jprop("result", result));
	}
	void OnPlayerIsPvP(Player * player, bool & result) override {
		NodeJs::invoke_hook("player:is-pvp"
			, jprop("player", player), jprop_box("result", result));
	}
	void OnPlayerGetMaxSkillValueForLevel(Player * player, uint16_t & result) override {
		NodeJs::invoke_hook("player:get-max-skill-value-for-level"
			, jprop("player", player), jprop_box("result", result));
	}
	[[nodiscard]] bool OnPlayerNotSetArenaTeamInfoField(Player * player, uint8_t const slot, ArenaTeamInfoType const type, uint32_t const value) override {
		return NodeJs::invoke_hook_t("player:not-set-arena-team-info-field", PlayerScript::OnPlayerNotSetArenaTeamInfoField(player, slot, type, value)
			, jprop("player", player), jprop("slot", slot), jprop("type", type), jprop("value", value));
	}
	[[nodiscard]] bool OnPlayerCanJoinLfg(Player * player, uint8_t const roles, std::set<uint32_t> & dungeons, const std::string & comment) override {
		return NodeJs::invoke_hook_t("player:can-join-lfg", PlayerScript::OnPlayerCanJoinLfg(player, roles, dungeons, comment)
			, jprop("player", player), jprop("roles", roles)/*, jprop_box("dungeons", dungeons)*/, jprop("comment", comment));
	}
	[[nodiscard]] bool OnPlayerCanEnterMap(Player * player, MapEntry const * entry, InstanceTemplate const * instance, MapDifficulty const * mapDiff, bool const loginCheck) override {
		return NodeJs::invoke_hook_t("player:can-enter-map", PlayerScript::OnPlayerCanEnterMap(player, entry, instance, mapDiff, loginCheck)
			, jprop("player", player)/*, jprop("entry", entry)*//*, jprop("instance", instance)*//*, jprop("mapDiff", mapDiff)*/, jprop("loginCheck", loginCheck));
	}
	[[nodiscard]] bool OnPlayerCanInitTrade(Player * player, Player * target) override {
		return NodeJs::invoke_hook_t("player:can-init-trade", PlayerScript::OnPlayerCanInitTrade(player, target)
			, jprop("player", player), jprop("target", target));
	}
	[[nodiscard]] bool OnPlayerCanSetTradeItem(Player * player, Item * tradedItem, uint8_t const tradeSlot) override {
		return NodeJs::invoke_hook_t("player:can-set-trade-item", PlayerScript::OnPlayerCanSetTradeItem(player, tradedItem, tradeSlot)
			, jprop("player", player), jprop("tradedItem", tradedItem), jprop("tradeSlot", tradeSlot));
	}
	void OnPlayerSetServerSideVisibility(Player * player, ServerSideVisibilityType & type, AccountTypes & sec) override {
		NodeJs::invoke_hook("player:set-server-side-visibility"
			, jprop("player", player), jprop_box("type", type), jprop_box("sec", sec));
	}
	void OnPlayerSetServerSideVisibilityDetect(Player * player, ServerSideVisibilityType & type, AccountTypes & sec) override {
		NodeJs::invoke_hook("player:set-server-side-visibility-detect"
			, jprop("player", player), jprop_box("type", type), jprop_box("sec", sec));
	}
	void OnPlayerResurrect(Player * player, float const restore_percent, bool & applySickness) override {
		NodeJs::invoke_hook("player:resurrect"
			, jprop("player", player), jprop("restorePercent", restore_percent), jprop_box("applySickness", applySickness));
	}
	void OnPlayerBeforeChooseGraveyard(Player * player, TeamId const teamId, bool const nearCorpse, uint32_t & graveyardOverride) override {
		NodeJs::invoke_hook("player:before-choose-graveyard"
			, jprop("player", player), jprop("teamId", teamId), jprop("nearCorpse", nearCorpse), jprop_box("graveyardOverride", graveyardOverride));
	}
	[[nodiscard]] bool OnPlayerCanUseChat(Player * player, uint32_t const type, uint32_t const language, std::string & msg) override {
		return NodeJs::invoke_hook_t("player:can-use-chat", PlayerScript::OnPlayerCanUseChat(player, type, language, msg)
			, jprop("player", player), jprop("type", type), jprop("lang", language), jprop_box("msg", msg));
	}
	[[nodiscard]] bool OnPlayerCanUseChat(Player * player, uint32_t const type, uint32_t const language, std::string & msg, Player * receiver) override {
		return NodeJs::invoke_hook_t("player:can-use-chat:player", PlayerScript::OnPlayerCanUseChat(player, type, language, msg, receiver)
			, jprop("player", player), jprop("type", type), jprop("lang", language), jprop_box("msg", msg), jprop("receiver", receiver));
	}
	[[nodiscard]] bool OnPlayerCanUseChat(Player * player, uint32_t const type, uint32_t const language, std::string & msg, Group * group) override {
		return NodeJs::invoke_hook_t("player:can-use-chat:group", PlayerScript::OnPlayerCanUseChat(player, type, language, msg, group)
			, jprop("player", player), jprop("type", type), jprop("lang", language), jprop_box("msg", msg), jprop("group", group));
	}
	[[nodiscard]] bool OnPlayerCanUseChat(Player * player, uint32_t const type, uint32_t const language, std::string & msg, Guild * guild) override {
		return NodeJs::invoke_hook_t("player:can-use-chat:guild", PlayerScript::OnPlayerCanUseChat(player, type, language, msg, guild)
			, jprop("player", player), jprop("type", type), jprop("lang", language), jprop_box("msg", msg), jprop("guild", guild));
	}
	[[nodiscard]] bool OnPlayerCanUseChat(Player * player, uint32_t const type, uint32_t const language, std::string & msg, Channel * channel) override {
		return NodeJs::invoke_hook_t("player:can-use-chat:channel", PlayerScript::OnPlayerCanUseChat(player, type, language, msg, channel)
			, jprop("player", player), jprop("type", type), jprop("lang", language), jprop_box("msg", msg), jprop("channel", channel));
	}
	void OnPlayerLearnTalents(Player * player, uint32_t const talentId, uint32_t const talentRank, uint32_t const spellid) override {
		NodeJs::invoke_hook("player:learn-talents"
			, jprop("player", player), jprop("talentId", talentId), jprop("talentRank", talentRank), jprop("spellId", spellid));
	}
	void OnPlayerEnterCombat(Player * player, Unit * enemy) override {
		NodeJs::invoke_hook("player:enter-combat"
			, jprop("player", player), jprop("enemy", enemy));
	}
	void OnPlayerLeaveCombat(Player * player) override {
		NodeJs::invoke_hook("player:leave-combat"
			, jprop("player", player));
	}
	void OnPlayerQuestAbandon(Player * player, uint32_t const questId) override {
		NodeJs::invoke_hook("player:quest-abandon"
			, jprop("player", player), jprop("questId", questId));
	}
	void OnPlayerQuestAccept(Player * player, Quest const * quest) override {
		NodeJs::invoke_hook("player:quest-accept"
			, jprop("player", player), jprop("quest", quest));
	}
	[[nodiscard]] bool OnPlayerCanFlyInZone(Player * player, uint32_t const mapId, uint32_t const zoneId, SpellInfo const * bySpell) override {
		return NodeJs::invoke_hook_t("player:can-fly-in-zone", PlayerScript::OnPlayerCanFlyInZone(player, mapId, zoneId, bySpell)
			, jprop("player", player), jprop("mapId", mapId), jprop("zoneId", zoneId), jprop("bySpell", bySpell));
	}
	void AnticheatSetCanFlybyServer(Player * player, bool const apply) override {
		NodeJs::invoke_hook("player:anticheat:set-can-flyby-server"
			, jprop("player", player), jprop("apply", apply));
	}
	void AnticheatSetUnderACKmount(Player * player) override {
		NodeJs::invoke_hook("player:anticheat:set-under-ack-mount"
			, jprop("player", player));
	}
	void AnticheatSetRootACKUpd(Player * player) override {
		NodeJs::invoke_hook("player:anticheat:set-root-ack-upd"
			, jprop("player", player));
	}
	void AnticheatSetJumpingbyOpcode(Player * player, bool const jump) override {
		NodeJs::invoke_hook("player:anticheat:set-jumping-by-opcode"
			, jprop("player", player), jprop("jump", jump));
	}
	void AnticheatUpdateMovementInfo(Player * player, MovementInfo const & movementInfo) override {
		NodeJs::invoke_hook("player:anticheat:update-movement-info"
			, jprop("player", player)/*, jprop("movementInfo", movementInfo)*/);
	}
	[[nodiscard]] bool AnticheatHandleDoubleJump(Player * player, Unit * mover) override {
		return NodeJs::invoke_hook_t("player:anticheat-handle-double-jump", PlayerScript::AnticheatHandleDoubleJump(player, mover)
			, jprop("player", player), jprop("mover", mover));
	}
	[[nodiscard]] bool AnticheatCheckMovementInfo(Player * player, MovementInfo const & movementInfo, Unit * mover, bool const jump) override {
		return NodeJs::invoke_hook_t("player:anticheat-check-movement-info", PlayerScript::AnticheatCheckMovementInfo(player, movementInfo, mover, jump)
			, jprop("player", player)/*, jprop("movementInfo", movementInfo)*/, jprop("mover", mover), jprop("jump", jump));
	}
	bool OnPlayerCanSendErrorAlreadyLooted(Player * player) override {
		return NodeJs::invoke_hook_t("player:can-send-error-already-looted", PlayerScript::OnPlayerCanSendErrorAlreadyLooted(player)
			, jprop("player", player));
	}
	void OnPlayerAfterCreatureLoot(Player * player) override {
		NodeJs::invoke_hook("player:after-creature-loot"
			, jprop("player", player));
	}
	void OnPlayerAfterCreatureLootMoney(Player * player) override {
		NodeJs::invoke_hook("player:after-creature-loot-money"
			, jprop("player", player));
	}
	bool OnPlayerCanUpdateSkill(Player * player, uint32_t const skillId) override {
		return NodeJs::invoke_hook_t("player:can-update-skill", PlayerScript::OnPlayerCanUpdateSkill(player, skillId)
			, jprop("player", player), jprop("skillId", skillId));
	}
	void OnPlayerBeforeUpdateSkill(Player * player, uint32_t const skillId, uint32_t & value, uint32_t const max, uint32_t const step) override {
		NodeJs::invoke_hook("player:before-update-skill"
			, jprop("player", player), jprop("skillId", skillId), jprop_box("value", value), jprop("max", max), jprop("step", step));
	}
	void OnPlayerUpdateSkill(Player * player, uint32_t const skillId, uint32_t const value, uint32_t const max, uint32_t const step, uint32_t const newValue) override {
		NodeJs::invoke_hook("player:update-skill"
			, jprop("player", player), jprop("skillId", skillId), jprop("value", value), jprop("max", max), jprop("step", step), jprop("newValue", newValue));
	}
	void OnPlayerSetSkill(Player * player, uint32_t const skillId, uint32_t const value, uint32_t const max, uint32_t const step, uint32_t const newValue) override {
		NodeJs::invoke_hook("player:set-skill"
			, jprop("player", player), jprop("skillId", skillId), jprop("value", value), jprop("max", max), jprop("step", step), jprop("newValue", newValue));
	}
	bool OnPlayerCanResurrect(Player * player) override {
		return NodeJs::invoke_hook_t("player:can-resurrect", PlayerScript::OnPlayerCanResurrect(player)
			, jprop("player", player));
	}
	bool OnPlayerCanGiveLevel(Player * player, uint8_t const newLevel) override {
		return NodeJs::invoke_hook_t("player:can-give-level", PlayerScript::OnPlayerCanGiveLevel(player, newLevel)
			, jprop("player", player), jprop("newLevel", newLevel));
	}
	void OnPlayerSendListInventory(Player * player, ObjectGuid const vendorGuid, uint32_t & vendorEntry) override {
		NodeJs::invoke_hook("player:send-list-inventory"
			, jprop("player", player), jprop("vendorGuid", vendorGuid), jprop_box("vendorEntry", vendorEntry));
	}
	void OnPlayerGetReputationPriceDiscount(Player const * player, Creature const * creature, float & discount) override {
		NodeJs::invoke_hook("player:get-reputation-price-discount:by-creature"
			, jprop("player", player), jprop("creature", creature), jprop_box("discount", discount));
	}
	void OnPlayerGetReputationPriceDiscount(Player const * player, FactionTemplateEntry const * factionTemplate, float & discount) override {
		NodeJs::invoke_hook("player:get-reputation-price-discount"
			, jprop("player", player)/*, jprop("factionTemplate", factionTemplate)*/, jprop_box("discount", discount));
	}
	void OnPlayerLearnTaxiNode(Player const * player, uint32_t const nodeId) override {
		NodeJs::invoke_hook("player:learn-taxi-node"
			, jprop("player", player), jprop("nodeId", nodeId));
	}
	void OnPlayerBeforeGetLevelForXPGain(Player const * player, uint8_t & level) override {
		NodeJs::invoke_hook("player:before-get-level-for-xp-gain"
			, jprop("player", player), jprop_box("level", level));
	}
};

void AddSC_Player() {
	new NODEJS_player();
}
