#include <chrono>
#include <map>
#include <optional>
#include <ranges>
#include <string>
#include <unordered_map>
#include <utility>
#include <v8-function-callback.h>
#include <v8-isolate.h>
#include <v8-local-handle.h>
#include <v8-template.h>
#include <vector>

#include "AccountMgr.h"
#include "AuctionHouseMgr.h"
#include "Bag.h"
#include "ByteBuffer.h"
#include "Chat.h"
#include "Common.h"
#include "Creature.h"
#include "CtoJ.h"
#include "DBCEnums.h"
#include "DBCStore.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "Duration.h"
#include "DurationWrapper.h"
#include "EnumFlag.h"
#include "GameObject.h"
#include "GossipDef.h"
#include "Guild.h"
#include "InstanceSaveMgr.h"
#include "Item.h"
#include "MotionMaster.h"
#include "NodeJPropHelpers.h"
#include "NodePropertySystem.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Pet.h"
#include "PetDefines.h"
#include "Player.h"
#include "PlayerSettings.h"
#include "PlayerTaxi.h"
#include "Position.h"
#include "QuestDef.h"
#include "SharedDefines.h"
#include "Unit.h"
#include "UnitDefines.h"
#include "UnixTimestamp.h"
#include "UpdateFields.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Achievements/AchievementMgr.h"
#include "Groups/Group.h"
#include "Groups/GroupMgr.h"
#include "Guilds/GuildMgr.h"
#include "Reputation/ReputationMgr.h"
#include "Time/GameTime.h"

JVAL_CVAL_TMPLS_RW(Player)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Player *>() {
	TypedTemplate<Player *> const ft = jctor();

	ft->SetClassName(jstr_intern("Player"));
	ft.safe_inherit<Unit *>();

	reg_static_method(ft, "byGuid", [](ObjectGuid const guid) {
		return ObjectAccessor::FindConnectedPlayer(guid);
	});
	reg_static_method(ft, "byName", [](std::string const name) {
		return ObjectAccessor::FindPlayerByName(name);
	});
	reg_static_method(ft, "allInWorld", [] {
		std::shared_lock lock(*HashMapHolder<Player>::GetLock());
		auto & player_map = ObjectAccessor::GetPlayers();
		return jarr(player_map | std::ranges::views::values);
	});
	reg_static_method(ft, "xpForLevel", [](uint8_t level) {
		return sObjectMgr->GetXPForLevel(level);
	});

	reg_prop_ro(ft, "race", [](Player * player) {
		return player->getRace();
	});
	reg_prop_ro(ft, "clazz", [](Player * player) {
		return player->getClass();
	});
	reg_prop_ro(ft, "raceMask", [](Player * player) {
		return player->getRaceMask();
	});
	reg_prop_ro(ft, "classMask", [](Player * player) {
		return player->getClassMask();
	});
	reg_prop_ro(ft, "teamId", [](Player * player) {
		return player->GetTeamId();
	});
	reg_prop_ro(ft, "guildId", [](Player * player) {
		return player->GetGuildId();
	});
	reg_prop_ro(ft, "isInGroup", [](Player * player) {
		return player->GetGroup() != nullptr;
	});
	reg_prop_ro(ft, "isInGuild", [](Player * player) {
		return player->GetGuildId() != 0;
	});
	reg_prop_ro(ft, "isRested", [](Player * player) {
		return player->GetRestBonus() > 0.0f;
	});
	reg_prop_ro(ft, "hasCorpse", [](Player * player) {
		return player->HasCorpse();
	});
	reg_prop_ro(ft, "isMaxLevel", [](Player * player) {
		return player->IsMaxLevel();
	});
	reg_prop_ro(ft, "activeSpec", [](Player * player) {
		return player->GetActiveSpec();
	});
	reg_prop_ro(ft, "specsCount", [](Player * player) {
		return player->GetSpecsCount();
	});
	reg_prop_ro(ft, "restBonus", [](Player * player) {
		return player->GetRestBonus();
	});
	reg_prop_ro(ft, "xp", [](Player * player) {
		return player->GetUInt32Value(PLAYER_XP);
	});
	reg_prop_ro(ft, "battlegroundTypeId", [](Player * player) {
		return player->GetBattlegroundTypeId();
	});
	reg_prop_ro(ft, "gmRank", [](Player * player) {
		return player->GetSession()->GetSecurity();
	});
	reg_prop_ro(ft, "accountId", [](Player * player) {
		return player->GetSession()->GetAccountId();
	});
	reg_prop_ro(ft, "accountFlags", [](Player * player) {
		return player->GetSession()->GetAccountFlags();
	});
	reg_prop_ro(ft, "accountName", [](Player * player) {
		auto const accId = player->GetSession()->GetAccountId();
		if (std::string accName; AccountMgr::GetName(accId, accName)) {
			return accName;
		}
		return std::string{};
	});
	reg_prop_ro(ft, "completedQuestsCount", [](Player * player) {
		return player->GetRewardedQuestCount();
	});
	reg_prop_ro(ft, "corpse", [](Player * player) {
		return player->GetCorpse();
	});
	reg_prop_ro(ft, "playerIP", [](Player * player) {
		return player->GetSession()->GetRemoteAddress();
	});
	reg_prop_ro(ft, "mailCount", [](Player * player) {
		return player->GetMailSize();
	});
	reg_prop_ro(ft, "mostPointsTalentTree", [](Player * player) {
		return player->GetMostPointsTalentTree();
	});
	reg_prop_ro(ft, "group", [](Player * player) {
		return player->GetGroup();
	});
	reg_prop_ro(ft, "difficulty", [](Player * player) {
		return player->GetDungeonDifficulty();
	});
	reg_prop_ro(ft, "inventoryFreeSlots", [](Player * player) {
		uint32_t freeSlots = 0;
		for (uint8_t i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i) {
			if (!player->GetItemByPos(INVENTORY_SLOT_BAG_0, i)) {
				++freeSlots;
			}
		}
		for (uint8_t i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i) {
			if (Bag const * bag = player->GetBagByPos(i)) {
				for (uint32_t j = 0; j < bag->GetBagSize(); ++j) {
					if (!player->GetItemByPos(i, j)) {
						++freeSlots;
					}
				}
			}
		}
		return freeSlots;
	});
	reg_prop_ro(ft, "canSpeak", [](Player * player) {
		return player->CanSpeak();
	});
	reg_prop_ro(ft, "canUninviteFromGroup", [](Player * player) {
		return player->CanUninviteFromGroup() == ERR_PARTY_RESULT_OK;
	});
	reg_prop_ro(ft, "inBattlegroundQueue", [](Player * player) {
		return player->InBattlegroundQueue();
	});
	reg_prop_ro(ft, "inArena", [](Player * player) {
		return player->InArena();
	});
	reg_prop_ro(ft, "inBattleground", [](Player * player) {
		return player->InBattleground();
	});
	reg_prop_ro(ft, "hasTankSpec", [](Player * player) {
		return player->HasTankSpec();
	});
	reg_prop_ro(ft, "hasMeleeSpec", [](Player * player) {
		return player->HasMeleeSpec();
	});
	reg_prop_ro(ft, "hasCasterSpec", [](Player * player) {
		return player->HasCasterSpec();
	});
	reg_prop_ro(ft, "hasHealSpec", [](Player * player) {
		return player->HasHealSpec();
	});
	reg_prop_ro(ft, "hasPet", [](Player * player) {
		return player->GetPet() != nullptr;
	});
	reg_prop_ro(ft, "canTameExoticPets", [](Player * player) {
		return player->CanTameExoticPets();
	});
	reg_prop_ro(ft, "canPetResurrect", [](Player * player) {
		return player->CanPetResurrect();
	});
	reg_prop_ro(ft, "canResummonPet", [](Player * player) {
		Pet const * pet = player->GetPet();
		return pet && player->CanResummonPet(0);
	});
	reg_prop_ro(ft, "inRandomLfgDungeon", [](Player * player) {
		return player->inRandomLfgDungeon();
	});
	reg_prop_ro(ft, "isUsingLfg", [](Player * player) {
		return player->IsUsingLfg();
	});
	reg_prop_ro(ft, "achievementPoints", [](Player * player) {
		uint32_t count = 0;
		for (
			auto const & completedAchievements = player->GetAchievementMgr()->GetCompletedAchievements();
			auto const & key : completedAchievements | std::views::keys
		) {
			if (auto const achievement = sAchievementStore.LookupEntry(key)) {
				count += achievement->points;
			}
		}
		return count;
	});
	reg_prop_ro(ft, "dodgeFromAgility", [](Player * player) {
		auto diminishing = 0.0f, nondiminishing = 0.0f;
		player->GetDodgeFromAgility(diminishing, nondiminishing);
		return diminishing + nondiminishing;
	});
	reg_prop_ro(ft, "meleeCritFromAgility", [](Player * player) {
		return player->GetMeleeCritFromAgility();
	});
	reg_prop_ro(ft, "spellCritFromIntellect", [](Player * player) {
		return player->GetSpellCritFromIntellect();
	});
	reg_prop_ro(ft, "ammoDPS", [](Player * player) {
		return player->GetAmmoDPS();
	});
	reg_prop_ro(ft, "canSeeDKPet", [](Player * player) {
		return player->CanSeeDKPet();
	});
	reg_prop_ro(ft, "isImmuneToDamage", [](Player * player) {
		return player->isTotalImmune();
	});
	reg_prop_ro(ft, "battlegroundId", [](Player * player) {
		return player->GetBattlegroundId();
	});
	reg_prop_ro(ft, "championingFactionId", [](Player * player) {
		return player->GetChampioningFaction();
	});
	reg_prop_ro(ft, "chatTag", [](Player * player) {
		return player->GetChatTag();
	});
	reg_prop_ro(ft, "dbLocaleIndex", [](Player * player) {
		return player->GetSession()->GetSessionDbLocaleIndex();
	});
	reg_prop_ro(ft, "dbcLocale", [](Player * player) {
		return player->GetSession()->GetSessionDbcLocale();
	});
	reg_prop_ro(ft, "latency", [](Player * player) {
		return DurationWrapper::from_milliseconds(player->GetSession()->GetLatency());
	});
	reg_prop_ro(ft, "groupInvite", [](Player * player) {
		return player->GetGroupInvite();
	});
	reg_prop_ro(ft, "inGameTime", [](Player * player) {
		return player->GetInGameTime();
	});
	reg_prop_ro(ft, "loginTimestamp", [](Player * player) {
		return UnixTimestamp::from_game_time_milliseconds(player->GetInGameTime());
	});
	reg_prop_ro(ft, "healthBonusFromStamina", [](Player * player) {
		return player->GetHealthBonusFromStamina();
	});
	reg_prop_ro(ft, "manaBonusFromIntellect", [](Player * player) {
		return player->GetManaBonusFromIntellect();
	});
	reg_prop_ro(ft, "originalGroup", [](Player * player) {
		return player->GetOriginalGroup();
	});
	reg_prop_ro(ft, "originalSubGroup", [](Player * player) {
		return player->GetOriginalSubGroup();
	});
	reg_prop_ro(ft, "phaseMaskForSpawn", [](Player * player) {
		return player->GetPhaseMaskForSpawn();
	});
	reg_prop_ro(ft, "selectedPlayer", [](Player * player) {
		return player->GetSelectedPlayer();
	});
	reg_prop_ro(ft, "selectedUnit", [](Player * player) {
		return player->GetSelectedUnit();
	});
	reg_prop_ro(ft, "shield", [](Player * player) {
		return player->GetShield();
	});
	reg_prop_ro(ft, "shieldBlockValue", [](Player * player) {
		return player->GetShieldBlockValue();
	});
	reg_prop_ro(ft, "subGroup", [](Player * player) {
		return player->GetSubGroup();
	});
	reg_prop_ro(ft, "todayHonorPoints", [](Player * player) {
		return player->GetUInt32Value(PLAYER_FIELD_TODAY_CONTRIBUTION);
	});
	reg_prop_ro(ft, "todayKills", [](Player * player) {
		return player->GetUInt32Value(PLAYER_FIELD_KILLS);
	});
	reg_prop_ro(ft, "trader", [](Player * player) {
		return player->GetTrader();
	});
	reg_prop_ro(ft, "yesterdayHonorPoints", [](Player * player) {
		return player->GetUInt32Value(PLAYER_FIELD_YESTERDAY_CONTRIBUTION);
	});
	reg_prop_ro(ft, "yesterdayKills", [](Player * player) {
		return player->GetUInt32Value(PLAYER_FIELD_KILLS + 1);
	});
	reg_prop_ro(ft, "recruiterId", [](Player * player) {
		return player->GetSession()->GetAccountId();
	});
	reg_prop_ro(ft, "bankFreeSlots", [](Player * player) {
		uint32_t freeSlots = 0;
		for (uint8_t i = BANK_SLOT_ITEM_START; i < BANK_SLOT_ITEM_END; ++i) {
			if (!player->GetItemByPos(INVENTORY_SLOT_BAG_0, i)) {
				++freeSlots;
			}
		}
		for (uint8_t i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i) {
			if (Bag const * bag = player->GetBagByPos(i)) {
				for (uint32_t j = 0; j < bag->GetBagSize(); ++j) {
					if (!player->GetItemByPos(i, j)) {
						++freeSlots;
					}
				}
			}
		}
		return freeSlots;
	});
	reg_prop_ro(ft, "levelPlayedTime", [](Player * player) {
		return DurationWrapper::from_chrono(Seconds{player->GetLevelPlayedTime()});
	});
	reg_prop_ro(ft, "averageItemLevel", [](Player * player) {
		return player->GetAverageItemLevel();
	});
	reg_prop_ro(ft, "totalPlayedTime", [](Player * player) {
		return DurationWrapper::from_chrono(Seconds{player->GetTotalPlayedTime()});
	});
	reg_prop_ro(ft, "guildName", [](Player * player) {
		return player->GetGuildId() ? player->GetGuildName() : "";
	});
	reg_prop_ro(ft, "runesState", [](Player * player) {
		return player->IsClass(CLASS_DEATH_KNIGHT, CLASS_CONTEXT_ABILITY)
			? player->GetRunesState()
			: 0;
	});
	reg_prop_ro(ft, "isBot", [](Player * player) {
		#ifdef MOD_PLAYERBOTS
			return player->GetSession()->IsBot();
		#else
			return false;
		#endif
	});
	reg_prop_ro(ft, "isHorde", [](Player * player) {
		return player->GetTeamId() == TEAM_HORDE;
	});
	reg_prop_ro(ft, "isAlliance", [](Player * player) {
		return player->GetTeamId() == TEAM_ALLIANCE;
	});
	reg_prop_ro(ft, "isInArena", [](Player * player) {
		return player->InArena();
	});
	reg_prop_ro(ft, "isInBattleground", [](Player * player) {
		return player->InBattleground();
	});
	reg_prop_ro(ft, "isInBattlegroundQueue", [](Player * player) {
		return player->InBattlegroundQueue();
	});
	reg_prop_ro(ft, "canTitanGrip", [](Player * player) {
		return player->CanTitanGrip();
	});
	reg_prop_ro(ft, "pet", [](Player * player) {
		return player->GetPet();
	});
	reg_prop_ro(ft, "homebind", [](Player * player) {
		return jobj(
			jprop("mapId", player->m_homebindMapId),
			jprop("areaId", player->m_homebindAreaId),
			jprop("x", player->m_homebindX),
			jprop("y", player->m_homebindY),
			jprop("z", player->m_homebindZ)
		);
	});
	reg_prop_ro(ft, "talentTreePoints", [](Player * player) {
		uint8_t specPoints[3] = {0, 0, 0};
		player->GetTalentTreePoints(specPoints);
		return jarr(specPoints);
	});
	reg_prop_ro(ft, "completedAchievementsCount", [](Player * player) {
		return player->GetAchievementMgr()->GetCompletedAchievements().size();
	});
	reg_prop_ro(ft, "completedAchievementsCountExcludingFeatsOfStrength", [](Player * player) {
		uint32_t count = 0;
		for (
			auto const & completedAchievements = player->GetAchievementMgr()->GetCompletedAchievements();
			auto const & key : completedAchievements | std::views::keys) {
			if (
				auto const achievement = sAchievementStore.LookupEntry(key);
				achievement && (achievement->categoryId != 81)
			) {
				count++;
			}
		}
		return count;
	});
	reg_prop_ro(ft, "currentQuestIds", [](Player * player) {
		std::vector<uint32_t> ids;
		ids.reserve(MAX_QUEST_LOG_SIZE);
		for (uint16_t i = 0; i < MAX_QUEST_LOG_SIZE; ++i) {
			if (uint32_t id = player->GetQuestSlotQuestId(i)) {
				ids.push_back(id);
			}
		}
		return jarr(ids);
	});
	reg_prop_ro(ft, "spells", [](Player * player) {
		return jarr(player->GetSpellMap() | std::views::keys);
	});
	reg_prop_ro(ft, "knownTaxiNodes", [](Player * player) {
		ByteBuffer data;
		player->m_taxi.AppendTaximaskTo(data, false);
		std::vector<uint32_t> nodes(TaxiMaskSize);
		for (uint8_t i = 0; i < TaxiMaskSize; i++) {
			uint32_t mask;
			data >> mask;
			for (uint8_t bit = 0; bit < 32; bit++) {
				if (mask & 1u << bit) {
					nodes.push_back(i * 32 + bit + 1);
				}
			}
		}
		return jarr(nodes);
	});

	reg_method(ft, "hasAccountFlag", [](Player * player, AccountFlag flag) {
		return player->GetSession()->HasAccountFlag(flag);
	});
	reg_method(ft, "setAccountFlag", [](Player * player, AccountFlag flag) {
		return player->GetSession()->UpdateAccountFlag(flag, /* remove = */ false);
	});
	reg_method(ft, "clearAccountFlag", [](Player * player, AccountFlag flag) {
		return player->GetSession()->UpdateAccountFlag(flag, /* remove = */ true);
	});
	reg_method(ft, "resetTalentsCost", [](Player * player) {
		return player->resetTalentsCost();
	});
	reg_method(ft, "getRaceAsString", [](Player * player, std::optional<uint32_t> const localeOpt) {
		auto const entry = sChrRacesStore.LookupEntry(player->getRace());
		return entry ? entry->name[localeOpt.value_or(DEFAULT_LOCALE)] : "";
	});
	reg_method(ft, "getClassAsString", [](Player * player, std::optional<uint32_t> const localeOpt) {
		auto const entry = sChrClassesStore.LookupEntry(player->getClass());
		return entry ? entry->name[localeOpt.value_or(DEFAULT_LOCALE)] : "";
	});
	reg_method(ft, "hasSpell", [](Player * player, uint32_t const spellId) {
		return player->HasSpell(spellId);
	});
	reg_method(ft, "hasQuest", [](Player * player, uint32_t const questId) {
		return player->HasQuest(questId);
	});
	reg_method(ft, "hasItemCount", [](Player * player, uint32_t const itemId, std::optional<uint32_t> const count, std::optional<bool> const checkBank) {
		return player->HasItemCount(itemId, count.value_or(1), checkBank.value_or(false));
	});
	reg_method(ft, "getItemCount", [](Player * player, uint32_t const itemId, std::optional<bool> const checkBank) {
		return player->GetItemCount(itemId, checkBank.value_or(false));
	});
	reg_method(ft, "getReputationWith", [](Player * player, uint32_t const faction) {
		return player->GetReputation(faction);
	});
	reg_method(ft, "getReputationRankWith", [](Player * player, uint32_t const faction) {
		return player->GetReputationRank(faction);
	});
	reg_method(ft, "getQuestStatus", [](Player * player, uint32_t const questId) {
		return player->GetQuestStatus(questId);
	});
	// TODO: verify correctness
	reg_method(ft, "getEquippedItemBySlot", [](Player * player, uint8_t const slot) {
		return player->GetItemByPos(slot << 8);
	});
	reg_method(ft, "getBarberShopCost", [](Player * player, uint8_t const hairstyle, uint8_t const haircolor, uint8_t const facialhair, std::optional<uint8_t> skincolor) {
		// not 100% sure why the skin color comes in like this instead of like the others...
		BarberShopStyleEntry skincolor_entry {
			.Id = 0,
			.type = 0,
			.race = 0,
			.gender = 0,
			.hair_id = skincolor.value_or(0),
		};
		return player->GetBarberShopCost(hairstyle, haircolor, facialhair, skincolor ? &skincolor_entry : nullptr);
	});
	reg_method(ft, "getSkillValue", [](Player * player, SkillType const skill) {
		return player->GetSkillValue(skill);
	});
	reg_method(ft, "getMaxSkillValue", [](Player * player, SkillType const skill) {
		return player->GetMaxSkillValue(skill);
	});
	// TODO: verify correctness
	reg_method(ft, "getInventoryItem", [](Player * player, uint8_t const slot) {
		return player->GetItemByPos(slot << 8);
	});
	// TODO: verify correctness
	reg_method(ft, "getBankItem", [](Player * player, uint8_t const slot) {
		auto const pos = static_cast<uint16_t>(BANK_SLOT_ITEM_START + slot);
		return player->GetItemByPos(pos << 8);
	});
	reg_method(ft, "hasTalent", [](Player * player, uint32_t const talent, std::optional<uint8_t> spec) {
		return player->HasTalent(talent, spec.value_or(player->GetActiveSpec()));
	});
	reg_method(ft, "hasAchieved", [](Player * player, uint32_t const id) {
		return player->HasAchieved(id);
	});
	reg_method(ft, "hasQuestForItem", [](Player * player, uint32_t const item_id, std::optional<uint32_t> exclude_quest_id, std::optional<bool> turn_in, std::optional<v8::Local<v8::Value>> show_in_loot) {
		// TODO: should Box<T> be easier to use on the C++ side? if so, should that simplification
		// also apply to hook args that are passed by reference so there's just one pattern?
		auto show_in_loot_val = false;
		auto has_show_in_loot_val = false;
		if (show_in_loot && (*show_in_loot)->IsObject()) {
			if (auto boxed = cval<bool>(show_in_loot->As<v8::Object>(), "boxed")) {
				show_in_loot_val = *boxed;
				has_show_in_loot_val = true;
			}
		}
		if (show_in_loot && !has_show_in_loot_val) {
			v8::Isolate::GetCurrent()->ThrowError("showInLoot must be an object with a bool 'boxed' property");
			return false;
		}
		auto res = player->HasQuestForItem(item_id, exclude_quest_id.value_or(0), turn_in.value_or(false), has_show_in_loot_val ? &show_in_loot_val : nullptr);
		if (has_show_in_loot_val) {
			auto const isolate = v8::Isolate::GetCurrent();
			auto const ctx = isolate->GetCurrentContext();
			show_in_loot->As<v8::Object>()->Set(ctx, jstr_intern("boxed"), jval(show_in_loot_val)).Check();
		}
		return res;
	});
	reg_method(ft, "canUseItem", [](Player * player, uint32_t const itemId) {
		auto const temp = sObjectMgr->GetItemTemplate(itemId);
		return temp && player->CanUseItem(temp) == EQUIP_ERR_OK;
	});
	reg_method(ft, "hasSpellCooldown", [](Player * player, uint32_t const spellId) {
		return player->HasSpellCooldown(spellId);
	});
	reg_method(ft, "canShareQuest", [](Player * player, uint32_t const questId) {
		return player->CanShareQuest(questId);
	});
	reg_method(ft, "isGroupVisibleFor", [](Player * player, Player * target) {
		return player->IsGroupVisibleFor(target);
	});
	reg_method(ft, "isInSameRaidWith", [](Player * player, Player * target) {
		return player->IsInSameRaidWith(target);
	});
	reg_method(ft, "isInSameGroupWith", [](Player * player, Player * target) {
		return player->GetGroup() == target->GetGroup();
	});
	reg_method(ft, "isHonorOrXPTarget", [](Player * player, Unit * target) {
		return player->isHonorOrXPTarget(target);
	});
	reg_method(ft, "isVisibleFor", [](Player * player, Player * target) {
		return player->IsVisibleGloballyFor(target);
	});
	reg_method(ft, "hasKnownTaxiNode", [](Player * player, uint32_t const nodeId) {
		return player->m_taxi.IsTaximaskNodeKnown(nodeId);
	});
	reg_method(ft, "isAtGroupRewardDistanceFor", [](Player * player, Unit * target) {
		return player->IsAtGroupRewardDistance(target);
	});
	reg_method(ft, "isAtLootRewardDistanceFor", [](Player * player, Unit * target) {
		return player->IsAtLootRewardDistance(target);
	});
	reg_method(ft, "canEquipItemByEntry", [](Player * player, uint32_t const itemId, uint8_t const slot, bool swap) {
		uint16_t dest;
		return sObjectMgr->GetItemTemplate(itemId)
			&& slot >= EQUIPMENT_SLOT_START
			&& slot < EQUIPMENT_SLOT_END
			&& player->CanEquipNewItem(slot, dest, itemId, swap) == EQUIP_ERR_OK;
	});
	reg_method(ft, "isDailyQuestDone", [](Player * player, Quest const * quest) {
		return player->IsDailyQuestDone(quest->GetQuestId());
	});
	reg_method(ft, "canSeeStartQuest", [](Player * player, Quest const * quest) {
		return player->CanSeeStartQuest(quest);
	});
	reg_method(ft, "canInteractWithQuestGiver", [](Player * player, WorldObject * target) {
		return player->CanInteractWithQuestGiver(target);
	});
	reg_method(ft, "hasArmorProficiency", [](Player * player, ItemSubclassArmor const proficiency) {
		return (player->GetArmorProficiency() & (1 << proficiency)) == 1 << proficiency;
	});
	reg_method(ft, "hasWeaponProficiency", [](Player * player, ItemSubclassWeapon const proficiency) {
		return (player->GetWeaponProficiency() & (1 << proficiency)) == 1 << proficiency;
	});
	reg_method(ft, "getGlyph", [](Player * player, uint32_t const slot_index) -> GlyphPropertiesEntry const * {
		if (auto glyph_id = player->GetGlyph(slot_index)) {
			return sGlyphPropertiesStore.LookupEntry(glyph_id);
		}
		return nullptr;
	});
	reg_method(ft, "getBaseSkillValue", [](Player * player, SkillType const skill) {
		return player->GetBaseSkillValue(skill);
	});
	reg_method(ft, "getPureSkillValue", [](Player * player, SkillType const skill) {
		return player->GetPureSkillValue(skill);
	});
	reg_method(ft, "getPureMaxSkillValue", [](Player * player, SkillType const skill) {
		return player->GetPureMaxSkillValue(skill);
	});
	reg_method(ft, "getSkillPermBonusValue", [](Player * player, SkillType const skill) {
		return player->GetSkillPermBonusValue(skill);
	});
	reg_method(ft, "getSkillTempBonusValue", [](Player * player, SkillType const skill) {
		return player->GetSkillTempBonusValue(skill);
	});
	reg_method(ft, "hasQuestFor", [](Player * player, GameObject const * game_object) {
		return player->HasQuestForGO(game_object->GetGUID().GetEntry());
	});
	reg_method(ft, "getQuestLevel", [](Player * player, Quest const * quest) {
		return player->GetQuestLevel(quest);
	});
	reg_method(ft, "getQuestSlotQuestId", [](Player * player, uint16_t const slotIndex) {
		return player->GetQuestSlotQuestId(slotIndex);
	});
	reg_method(ft, "hasTitle", [](Player * player, uint32_t const titleId) {
		auto const e = sCharTitlesStore.LookupEntry(titleId);
		return e && player->HasTitle(e->bit_index);
	});
	reg_method(ft, "hasTitleByIndex", [](Player * player, uint32_t const bitIndex) {
		return player->HasTitle(bitIndex);
	});
	reg_method(ft, "hasItem", [](Player * player, uint32_t const entryId, std::optional<uint32_t> const count) {
		return player->HasItemCount(entryId, count.value_or(1));
	});
	reg_method(ft, "getItemByEntry", [](Player * player, uint32_t const entryId) {
		return player->GetItemByEntry(entryId);
	});
	reg_method(ft, "getItemByGUID", [](Player * player, ObjectGuid const guid) {
		return player->GetItemByGuid(guid);
	});
	reg_method(ft, "getItemByPos", [](Player * player, uint8_t const bag, uint8_t const slot) {
		return player->GetItemByPos(bag, slot);
	});
	reg_method(ft, "calculateReputationGain", [](Player * player, ReputationSource const source, uint32_t const creatureOrQuestLevel, float const rep, int32_t const faction, std::optional<bool> const noQuestBonus) {
		return player->CalculateReputationGain(source, creatureOrQuestLevel, rep, faction, noQuestBonus.value_or(false));
	});
	reg_method(ft, "getNearbyGameObject", [](Player * player, uint32_t const entryId, float const range) {
		return player->FindNearestGameObject(entryId, range);
	});
	reg_method(ft, "getNextRandomRaidMember", [](Player * player, float const radius) {
		return player->GetNextRandomRaidMember(radius);
	});
	reg_method(ft, "getReqKillOrCastCurrentCount", [](Player * player, uint32_t const questId, int32_t const entry) {
		return player->GetReqKillOrCastCurrentCount(questId, entry);
	});
	reg_method(ft, "getQuestRewardStatus", [](Player * player, uint32_t const questId) {
		return player->GetQuestRewardStatus(questId);
	});
	reg_method(ft, "getSpellCooldownDelay", [](Player * player, uint32_t const spellId) {
		return player->GetSpellCooldownDelay(spellId);
	});
	reg_method(ft, "hasAtLoginFlag", [](Player * player, AtLoginFlags const flag) {
		return player->HasAtLoginFlag(flag);
	});
	reg_method(ft, "hasSkill", [](Player * player, SkillType const skill) {
		return player->HasSkill(skill);
	});
	reg_method(ft, "getAchievementCriteriaProgress", [](Player * player, uint32_t const criteriaId) {
		if (auto const criteria = sAchievementCriteriaStore.LookupEntry(criteriaId)) {
			if (CriteriaProgress const * progress = player->GetAchievementMgr()->GetCriteriaProgress(criteria)) {
				return progress->counter;
			}
		}
		return 0u;
	});

	reg_prop(ft, "money",
		[](Player * player) { return player->GetMoney(); },
		[](Player * player, uint32_t const val) { player->SetMoney(val); }
	);
	reg_prop(ft, "drunkValue",
		[](Player * player) { return player->GetDrunkValue(); },
		[](Player * player, uint8_t const val) { player->SetDrunkValue(val); }
	);
	reg_prop(ft, "freeTalentPoints",
		[](Player * player) { return player->GetFreeTalentPoints(); },
		[](Player * player, uint32_t const pts) { player->SetFreeTalentPoints(pts); }
	);
	reg_prop(ft, "arenaPoints",
		[](Player * player) { return player->GetArenaPoints(); },
		[](Player * player, uint32_t const pts) { player->SetArenaPoints(pts); }
	);
	reg_prop(ft, "honorPoints",
		[](Player * player) { return player->GetHonorPoints(); },
		[](Player * player, uint32_t const pts) { player->SetHonorPoints(pts); }
	);
	reg_prop(ft, "lifetimeKills",
		[](Player * player) { return player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS); },
		[](Player * player, uint32_t const val) { player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, val); }
	);
	reg_prop(ft, "taxiCheat",
		[](Player * player) { return player->isTaxiCheater(); },
		[](Player * player, bool const on) { player->SetTaxiCheater(on); }
	);
	reg_prop(ft, "gmChat",
		[](Player * player) { return player->isGMChat(); },
		[](Player * player, bool const on) { player->SetGMChat(on); }
	);

	reg_prop(ft, "isPvP",
		[](Player * player) { return player->IsPvP(); },
		[](Player * player, bool const state) { player->SetPvP(state); }
	);
	// isFFAPvP — Player::IsFFAPvP() shadows Unit::IsFFAPvP()
	reg_prop_ro(ft, "isFFAPvP", [](Player * player) {
		return player->IsFFAPvP();
	});
	reg_prop_ro(ft, "isInArenaTeam", [](Player * player) {
		return player->GetArenaTeamId(0) || player->GetArenaTeamId(1) || player->GetArenaTeamId(2);
	});
	reg_prop(ft, "bonusTalentCount",
		[](Player * player) { return player->GetBonusTalentCount(); },
		[](Player * player, uint32_t const count) { player->SetBonusTalentCount(count); }
	);
	reg_prop(ft, "canTeleport",
		[](Player * player) { return player->CanTeleport(); },
		[](Player * player, bool const value) { player->SetCanTeleport(value); }
	);
	reg_prop(ft, "lastPetNumber",
		[](Player * player) { return player->GetLastPetNumber(); },
		[](Player * player, uint32_t const val) { player->SetLastPetNumber(val); }
	);
	reg_prop(ft, "lastPetSpell",
		[](Player * player) { return player->GetLastPetSpell(); },
		[](Player * player, uint32_t const val) { player->SetLastPetSpell(val); }
	);
	reg_prop(ft, "temporaryUnsummonedPetNumber",
		[](Player * player) { return player->GetTemporaryUnsummonedPetNumber(); },
		[](Player * player, uint32_t const val) { player->SetTemporaryUnsummonedPetNumber(val); }
	);
	reg_prop(ft, "acceptWhispers",
		[](Player * player) { return player->isAcceptWhispers(); },
		[](Player * player, bool const on) { player->SetAcceptWhispers(on); }
	);
	reg_prop(ft, "gmVisible",
		[](Player * player) { return player->isGMVisible(); },
		[](Player * player, bool const on) { player->SetGMVisible(on); }
	);
	reg_prop(ft, "creationTime",
		[](Player * player) { return UnixTimestamp::from_chrono(player->GetCreationTime()); },
		[](Player * player, UnixTimestamp const val) { player->SetCreationTime(val.to_chrono<Seconds>()); }
	);
	reg_prop(ft, "guildRank",
		[](Player * player) {
			if (auto const guildId = player->GetGuildId(); guildId && sGuildMgr->GetGuildById(guildId)) {
				return player->GetRank();
			}
			return uint8_t{0};
		},
		[](Player * player, uint8_t const rank) {
			if (player->GetGuildId()) {
				player->SetRank(rank);
			} else {
				v8::Isolate::GetCurrent()->ThrowError("not in a guild!");
			}
		}
	);
	reg_prop(ft, "isGM",
		[](Player * player) { return player->IsGameMaster(); },
		[](Player * player, bool const on) { player->SetGameMaster(on); }
	);
	reg_prop(ft, "afk",
		[](Player * player) { return player->isAFK(); },
		[](Player * player, bool const requested) {
			if (player->isAFK() != requested) {
				player->ToggleAFK();
			}
		}
	);
	reg_prop(ft, "dnd",
		[](Player * player) { return player->isDND(); },
		[](Player * player, bool const requested) {
			if (player->isDND() != requested) {
				player->ToggleDND();
			}
		}
	);
	reg_prop(ft, "isSpectator",
		[](Player * player) { return player->IsSpectator(); },
		[](Player * player, bool const state) { player->SetIsSpectator(state); }
	);
	reg_prop(ft, "canBlock",
		[](Player * player) { return player->CanBlock(); },
		[](Player * player, bool const state) { player->SetCanBlock(state); }
	);
	reg_prop(ft, "canParry",
		[](Player * player) { return player->CanParry(); },
		[](Player * player, bool const state) { player->SetCanParry(state); }
	);
	reg_prop(ft, "viewpoint",
		[](Player * player) { return player->GetViewpoint(); },
		[](Player * player, WorldObject * newVal) {
			if (auto const current = player->GetViewpoint()) {
				player->SetViewpoint(current, false);
			}
			if (newVal) {
				player->SetViewpoint(newVal, true);
			}
		}
	);

	// the setter we inherited from Unit doesn't call the player-specific GiveLevel method,
	// which does more things that just about every caller will need.
	reg_prop(ft, "level",
		[](Player * player) { return player->GetLevel(); },
		[](Player * player, uint8_t const lvl) { player->GiveLevel(lvl); }
	);
	reg_prop(ft, "gossipMenuId",
		[](Player * player) { return player->PlayerTalkClass->GetGossipMenu().GetMenuId(); },
		[](Player * player, uint32_t id) { player->PlayerTalkClass->GetGossipMenu().SetMenuId(id); }
	);

	reg_method(ft, "sendSystemMessage", [](Player * player, std::string const msg) {
		player->SendSystemMessage(msg);
	});
	reg_method(ft, "learnSpell", [](Player * player, uint32_t const spellId, std::optional<bool> temporary, std::optional<bool> learn_from_skill) {
		player->learnSpell(spellId, temporary.value_or(false), learn_from_skill.value_or(false));
	});
	reg_method(ft, "removeSpell", [](Player * player, uint32_t const spellId, std::optional<uint8_t> remove_spec_mask, std::optional<bool> only_temporary) {
		player->removeSpell(spellId, remove_spec_mask.value_or(SPEC_MASK_ALL), only_temporary.value_or(false));
	});
	reg_method(ft, "modifyMoney", [](Player * player, int32_t const amount) {
		return player->ModifyMoney(amount, true);
	});
	reg_method(ft, "teleport", [](Player * player, uint32_t const mapId, float const x, float const y, float const z, float const o, std::optional<uint32_t> options, std::optional<Unit *> target, std::optional<bool> new_instance) {
		if (player->IsInFlight()) {
			player->GetMotionMaster()->MovementExpired();
			player->m_taxi.ClearTaxiDestinations();
		}
		return player->TeleportTo(mapId, x, y, z, o, options.value_or(0), target.value_or(nullptr), new_instance.value_or(false));
	});
	reg_method(ft, "resurrect", [](Player * player, std::optional<float> const restore_pct, std::optional<bool> apply_sickness) {
		player->ResurrectPlayer(restore_pct.value_or(1.0f), apply_sickness.value_or(false));
	});
	reg_method(ft, "equipItem", [](Player * player, uint32_t const itemId, uint8_t const slot) -> Item * {
		if (auto const item = Item::CreateItem(itemId, 1, player)) {
			if (uint16_t dest; player->CanEquipItem(slot, dest, item, false, false) == EQUIP_ERR_OK) {
				return player->EquipItem(slot, item, true);
			}
		}
		return nullptr;
	});
	reg_method(ft, "mute", [](Player * player, DurationWrapper time) {
		player->GetSession()->m_muteTime = GameTime::GetGameTime().count() + time.count<Seconds>();
	});
	reg_method(ft, "giveXP", [](Player * player, uint32_t const amount, std::optional<Unit *> target, std::optional<float> const group_rate, std::optional<bool> const is_lfg_reward) {
		player->GiveXP(amount, target.value_or(nullptr), group_rate.value_or(1), is_lfg_reward.value_or(false));
	});
	reg_method(ft, "toggleDND", [](Player * player) {
		player->ToggleDND();
	});
	reg_method(ft, "toggleAFK", [](Player * player) {
		player->ToggleAFK();
	});
	reg_method(ft, "resetTalents", [](Player * player, std::optional<bool> const no_reset_cost) {
		player->resetTalents(no_reset_cost.value_or(false));
	});
	reg_method(ft, "talkedToCreature", [](Player * player, uint32_t entry, ObjectGuid guid) {
		player->TalkedToCreature(entry, guid);
	});
	reg_method(ft, "killedMonsterCredit", [](Player * player, uint32_t entry, std::optional<ObjectGuid> guid) {
		player->KilledMonsterCredit(entry, guid.value_or({}));
	});
	reg_method(ft, "addQuest", [](Player * player, Quest const * quest, std::optional<Object *> const quest_giver) {
		player->AddQuest(quest, quest_giver.value_or(nullptr));
	});
	reg_method(ft, "removeQuest", [](Player * player, uint32_t quest_id) {
		for (uint8_t slot = 0; slot < MAX_QUEST_LOG_SIZE; ++slot) {
			if (auto const log_quest = player->GetQuestSlotQuestId(slot); log_quest == quest_id) {
				player->SetQuestSlot(slot, 0);
				player->TakeQuestSourceItem(log_quest, false);
				break;
			}
		}
	});
	reg_method(ft, "completeQuest", [](Player * player, uint32_t quest_id) {
		player->CompleteQuest(quest_id);
	});
	reg_method(ft, "failQuest", [](Player * player, uint32_t quest_id) {
		player->FailQuest(quest_id);
	});
	reg_method(ft, "incompleteQuest", [](Player * player, uint32_t quest_id) {
		player->IncompleteQuest(quest_id);
	});
	reg_method(ft, "abandonQuest", [](Player * player, uint32_t quest_id) {
		player->AbandonQuest(quest_id);
	});
	reg_method(ft, "addItem", [](Player * player, uint32_t const itemId, std::optional<uint32_t> const count) {
		return player->AddItem(itemId, count.value_or(1));
	});
	reg_method(ft, "removeItem", [](Player * player, uint32_t const itemId, std::optional<uint32_t> const count) {
		player->DestroyItemCount(itemId, count.value_or(1), true, true);
	});
	reg_method(ft, "resetSpellCooldown", [](Player * player, uint32_t const spellId, Unit * target) {
		player->SendClearCooldown(spellId, target);
	});
	reg_method(ft, "resetAllCooldowns", [](Player * player) {
		for (
			auto & cooldowns = player->GetSpellCooldownMap();
			auto const key : cooldowns | std::views::keys
		) {
			player->RemoveSpellCooldown(key, true);
		}
	});
	reg_method(ft, "sendNotification", [](Player * player, std::string const msg) {
		ChatHandler(player->GetSession()).SendNotification(msg);
	});
	reg_method(ft, "sendAreaTriggerMessage", [](Player * player, std::string const msg) {
		player->GetSession()->SendAreaTriggerMessage(msg);
	});
	reg_method(ft, "sendAddonMessage", [](Player * player, std::string const prefix, std::string const msg) {
		auto const fullmsg = prefix + "\t" + msg;
		WorldPacket data(SMSG_MESSAGECHAT, 1 + 4 + 8 + 4 + 8 + 4 + 1 + fullmsg.length() + 1);
		data << uint8_t{CHAT_MSG_WHISPER};
		data << static_cast<uint32_t>(LANG_ADDON);
		data << uint64_t{0};
		data << uint32_t{0};
		data << uint64_t{0};
		data << static_cast<uint32_t>(fullmsg.length() + 1);
		data << fullmsg;
		data << uint8_t{0};
		player->GetSession()->SendPacket(&data);
	});
	reg_method(ft, "durabilityRepairAll", [](Player * player, bool cost, float discount_mod, bool guild_bank) {
		return player->DurabilityRepairAll(cost, discount_mod, guild_bank);
	});
	reg_method(ft, "durabilityRepair", [](Player * player, uint16_t const slot, bool cost, float discount_mod, bool guild_bank) {
		return player->DurabilityRepair(slot, cost, discount_mod, guild_bank);
	});
	reg_method(ft, "durabilityLossAll", [](Player * player, double percent, bool inventory) {
		player->DurabilityLossAll(percent, inventory);
	});
	reg_method(ft, "durabilityPointsLossAll", [](Player * player, int32_t points, bool inventory) {
		player->DurabilityPointsLossAll(points, inventory);
	});
	reg_method(ft, "advanceSkillsToMax", [](Player * player) {
		player->UpdateSkillsToMaxSkillsForLevel();
	});
	reg_method(ft, "advanceAllSkills", [](Player * player, uint32_t const step) {
		for (uint32_t i = 0; i < sSkillLineStore.GetNumRows(); ++i) {
			if (auto const entry = sSkillLineStore.LookupEntry(i)) {
				if (entry->categoryId == SKILL_CATEGORY_LANGUAGES || entry->categoryId == SKILL_CATEGORY_GENERIC) {
					continue;
				}
				if (player->HasSkill(entry->id)) {
					player->UpdateSkill(entry->id, step);
				}
			}
		}
	});
	reg_method(ft, "advanceSkill", [](Player * player, SkillType const skillId, uint32_t const step) {
		return player->HasSkill(skillId) && player->UpdateSkill(skillId, step);
	});
	reg_method(ft, "summonPet", [](Player * player, uint32_t const entry, float const x, float const y, float const z, float const angle, std::optional<PetType> const petType, std::optional<DurationWrapper> const duration, std::optional<uint32_t> const healthPct) {
		auto const dur = duration
			? duration->to_chrono<Milliseconds>()
			: 0ms;
		return player->SummonPet(entry, x, y, z, angle, petType.value_or(HUNTER_PET), dur, healthPct.value_or(0));
	});
	reg_method(ft, "createPet", [](Player * player, uint32_t const entry, std::optional<uint32_t> const spellId) {
		return player->CreatePet(entry, spellId.value_or(0));
	});
	reg_method(ft, "removePet", [](Player * player, std::optional<PetSaveMode> const mode, std::optional<bool> return_reagent) {
		if (auto const pet = player->GetPet()) {
			player->RemovePet(pet, mode.value_or(PET_SAVE_AS_DELETED), return_reagent.value_or(false));
		}
	});
	reg_method(ft, "unsummonPetTemporarilyIfAny", [](Player * player) {
		player->UnsummonPetTemporaryIfAny();
	});
	reg_method(ft, "resummonPetIfTemporarilyUnsummoned", [](Player * player) {
		player->ResummonPetTemporaryUnSummonedIfAny();
	});
	reg_method(ft, "inviteToGroup", [](Player * player, Player * target) {
		if (target->GetGroup() || target->GetGroupInvite()) {
			return false;
		}
		auto group = player->GetGroup();
		auto created_group_here = false;
		if (!group) {
			group = new Group;
			created_group_here = true;
		}
		if (group->isBGGroup()) {
			group = player->GetOriginalGroup();
		}
		if (group->IsFull() || !group->AddInvite(target)) {
			if (created_group_here) {
				delete group;
			}
			return false;
		}
		WorldPacket data(SMSG_GROUP_INVITE, 10);
		data << uint8_t{1};
		data << player->GetName();
		data << uint32_t{0};
		data << uint8_t{0};
		data << uint32_t{0};
		target->GetSession()->SendPacket(&data);
		return true;
	});
	reg_method(ft, "createGroupWith", [](Player * player, Player * target) -> Group * {
		if (target->GetGroup() || target->GetGroupInvite()) {
			return nullptr;
		}
		auto const group = new Group;
		if (!group->AddLeaderInvite(player)) {
			delete group;
			return nullptr;
		}
		if (!group->IsCreated()) {
			group->RemoveInvite(player);
			group->Create(player);
			sGroupMgr->AddGroup(group);
		}
		if (!group->AddMember(target)) {
			delete group;
			return nullptr;
		}
		group->BroadcastGroupUpdate();
		return group;
	});
	reg_method(ft, "removeFromGroup", [](Player * player, std::optional<RemoveMethod> method) {
		player->RemoveFromGroup(method.value_or(GROUP_REMOVEMETHOD_DEFAULT));
	});
	reg_method(ft, "addLifetimeKills", [](Player * player, uint32_t const kills) {
		auto const currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
		player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, currentKills + kills);
	});
	reg_method(ft, "removeLifetimeKills", [](Player * player, uint32_t const kills) {
		auto const currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
		auto removeKills = kills;
		if (removeKills > currentKills) {
			removeKills = currentKills;
		}
		player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, currentKills - removeKills);
	});
	reg_method(ft, "sendTaxiMenu", [](Player * player, Creature * creature) {
		player->GetSession()->SendTaxiMenu(creature);
	});
	reg_method(ft, "sendSpiritResurrect", [](Player * player) {
		player->GetSession()->SendSpiritResurrect();
	});
	reg_method(ft, "sendShowBank", [](Player * player, ObjectGuid banker) {
		player->GetSession()->SendShowBank(banker);
	});
	reg_method(ft, "sendAuctionMenu", [](Player * player, Creature * auctioneer) {
		if (auto const ahEntry = AuctionHouseMgr::GetAuctionHouseEntryFromFactionTemplate(auctioneer->GetFaction())) {
			WorldPacket data(MSG_AUCTION_HELLO, 12);
			data << auctioneer->GetGUID();
			data << ahEntry->houseId;
			data << uint8_t{1};
			player->GetSession()->SendPacket(&data);
		}
	});
	reg_method(ft, "unbindInstance", [](Player * player, uint32_t const instanceId, std::optional<Difficulty> const diff) {
		sInstanceSaveMgr->PlayerUnbindInstance(player->GetGUID(), instanceId, diff.value_or(REGULAR_DIFFICULTY), true, player);
	});
	reg_method(ft, "unbindAllInstances", [](Player * player) {
		for (uint8_t i = 0; i < MAX_DIFFICULTY; ++i) {
			auto const & binds = sInstanceSaveMgr->PlayerGetBoundInstances(player->GetGUID(), Difficulty{i});
			for (auto itr = binds.begin(); itr != binds.end();) {
				if (itr->first != player->GetMapId()) {
					sInstanceSaveMgr->PlayerUnbindInstance(player->GetGUID(), itr->first, Difficulty{i}, true, player);
					itr = binds.begin();
				} else {
					++itr;
				}
			}
		}
	});
	reg_method(ft, "leaveBattleground", [](Player * player) {
		player->LeaveBattleground();
	});
	reg_method(ft, "logoutPlayer", [](Player * player, std::optional<bool> const save) {
		player->GetSession()->LogoutPlayer(save.value_or(true));
	});
	reg_method(ft, "saveToDB", [](Player * player) {
		player->SaveToDB(false, false);
	});
	reg_method(ft, "modifyArenaPoints", [](Player * player, int32_t const pts) {
		player->ModifyArenaPoints(pts);
	});
	reg_method(ft, "modifyHonorPoints", [](Player * player, int const pts) {
		player->ModifyHonorPoints(pts);
	});
	reg_method(ft, "setGender", [](Player * player, uint8_t const gender) {
		player->SetByteValue(UNIT_FIELD_BYTES_1, 1, gender);
	});
	reg_method(ft, "setPlayerLock", [](Player * player, std::optional<bool> const apply) {
		if (apply.value_or(true)) {
			player->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_SILENCED);
			player->SetClientControl(player, false);
		} else {
			player->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_SILENCED);
			player->SetClientControl(player, true);
		}
	});
	reg_method(ft, "setAtLoginFlag", [](Player * player, AtLoginFlags const flag) {
		player->SetAtLoginFlag(flag);
	});
	reg_method(ft, "doRandomRoll", [](Player * player, uint32_t const min, uint32_t const max) {
		return player->DoRandomRoll(min, max);
	});
	reg_method(ft, "sendCinematicStart", [](Player * player, uint32_t const cinematicId) {
		player->SendCinematicStart(cinematicId);
	});
	reg_method(ft, "sendMovieStart", [](Player * player, uint32_t const movieId) {
		player->SendMovieStart(movieId);
	});
	reg_method(ft, "sendTrainerList", [](Player * player, Creature * trainer) {
		player->GetSession()->SendTrainerList(trainer);
	});
	reg_method(ft, "sendListInventory", [](Player * player, WorldObject * vendor, std::optional<uint32_t> const override_entry) {
		auto const creature = vendor->ToCreature();
		auto addedVendorFlag = false;
		if (override_entry && creature && !creature->HasNpcFlag(UNIT_NPC_FLAG_VENDOR)) {
			creature->SetNpcFlag(UNIT_NPC_FLAG_VENDOR);
			addedVendorFlag = true;
		}

		player->GetSession()->SendListInventory(vendor->GetGUID(), override_entry.value_or(0));

		if (addedVendorFlag) {
			creature->RemoveNpcFlag(UNIT_NPC_FLAG_VENDOR);
		}
	});
	reg_method(ft, "sendGuildInvite", [](Player * player, std::string const name) {
		if (auto const guild = player->GetGuild()) {
			guild->HandleInviteMember(player->GetSession(), name);
		}
	});
	reg_method(ft, "sendShowMailBox", [](Player * player, GameObject const * mailbox) {
		player->GetSession()->SendShowMailBox(mailbox->GetGUID());
	});
	reg_method(ft, "areaExploredOrEventHappens", [](Player * player, uint32_t const eventId) {
		player->AreaExploredOrEventHappens(eventId);
	});
	reg_method(ft, "groupEventHappens", [](Player * player, uint32_t quest_id, std::optional<WorldObject *> event_object) {
		player->GroupEventHappens(quest_id, event_object.value_or(nullptr));
	});
	reg_method(ft, "takeEnvironmentalDamage", [](Player * player, EnviromentalDamage const type, uint32_t const damage) {
		return player->EnvironmentalDamage(type, damage);
	});
	reg_method(ft, "canCompleteRepeatableQuest", [](Player * player, Quest const * quest) {
		return player->CanCompleteRepeatableQuest(quest);
	});
	reg_method(ft, "canRewardQuest", [](Player * player, Quest const * quest, bool const msg) {
		return player->CanRewardQuest(quest, msg);
	});
	reg_method(ft, "canCompleteQuest", [](Player * player, uint32_t quest_id) {
		return player->CanCompleteQuest(quest_id);
	});
	reg_method(ft, "canTakeQuest", [](Player * player, Quest const * quest, bool const msg) {
		return player->CanTakeQuest(quest, msg);
	});
	reg_method(ft, "canAddQuest", [](Player * player, Quest const * quest, bool const msg) {
		return player->CanAddQuest(quest, msg);
	});
	reg_method(ft, "addArmorProficiency", [](Player * player, uint32_t const proficiency) {
		player->AddArmorProficiency(proficiency);
	});
	reg_method(ft, "addBonusTalent", [](Player * player, uint32_t const count) {
		player->AddBonusTalent(count);
	});
	reg_method(ft, "learnTalent", [](Player * player, uint32_t const talentId, std::optional<uint32_t> const rank) {
		player->LearnTalent(talentId, rank.value_or(1));
		player->SendTalentsInfoData(false);
	});
	reg_method(ft, "addWeaponProficiency", [](Player * player, uint32_t const proficiency) {
		player->AddWeaponProficiency(proficiency);
	});
	reg_method(ft, "learnPetTalent", [](Player * player, uint32_t const talentId, uint32_t const talentRank) {
		player->LearnPetTalent(player->GetPetGUID(), talentId, talentRank);
	});
	reg_method(ft, "resetPetTalents", [](Player * player) {
		player->ResetPetTalents();
	});
	reg_method(ft, "setGlyph", [](Player * player, uint32_t const glyphId, uint32_t const slotIndex) {
		player->SetGlyph(slotIndex, glyphId, true);
		player->SendTalentsInfoData(false);
	});
	reg_method(ft, "completedAchievement", [](Player * player, AchievementEntry const * achievement) {
		player->CompletedAchievement(achievement);
	});
	reg_method(ft, "resetAchievements", [](Player * player) {
		player->ResetAchievements();
	});
	reg_method(ft, "bindToInstance", [](Player * player) {
		player->BindToInstance();
	});
	reg_method(ft, "kickPlayer", [](Player * player) {
		player->GetSession()->KickPlayer();
	});
	reg_method(ft, "runCommand", [](Player * player, std::string const command) {
		auto cmd = command;
		if (!cmd.empty() && (cmd[0] == '.' || cmd[0] == '!')) {
			cmd = cmd.substr(1);
		}
		ChatHandler handler(player->GetSession());
		handler._ParseCommands(cmd);
	});
	reg_method(ft, "removeFromBattlegroundRaid", [](Player * player) {
		player->RemoveFromBattlegroundOrBattlefieldRaid();
	});
	reg_method(ft, "gossipAddQuests", [](Player * player, WorldObject const * source) {
		if (source->IsCreature()) {
			if (source->GetUInt32Value(UNIT_NPC_FLAGS) & UNIT_NPC_FLAG_QUESTGIVER) {
				player->PrepareQuestMenu(source->GetGUID());
			}
		} else if (source->IsGameObject()) {
			if (source->ToGameObject()->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER) {
				player->PrepareQuestMenu(source->GetGUID());
			}
		}
	});
	reg_method(ft, "gossipClearMenu", [](Player * player) {
		player->PlayerTalkClass->ClearMenus();
	});
	reg_method(ft, "gossipComplete", [](Player * player) {
		player->PlayerTalkClass->SendCloseGossip();
	});
	reg_method(ft, "gossipMenuAddItem", [](Player * player, int32_t menu_item_id, uint8_t icon, std::string message, uint32_t sender, uint32_t action, std::string box_message, uint32_t box_money, std::optional<bool> coded) {
		player->PlayerTalkClass->GetGossipMenu().AddMenuItem(menu_item_id, icon, message, sender, action, box_message, box_money, coded.value_or(false));
	});
	reg_method(ft, "gossipSendMenuToCreature", [](Player * player, uint32_t title_text_id, ObjectGuid creature) {
		player->PlayerTalkClass->SendGossipMenu(title_text_id, creature);
	});
	reg_method(ft, "gossipSendPOI", [](Player * player, uint32_t const poiId) {
		player->PlayerTalkClass->SendPointOfInterest(poiId);
	});
	reg_method(ft, "setSkill", [](Player * player, SkillType const skill, uint16_t const value) {
		player->SetSkill(skill, value, value, player->GetMaxSkillValue(skill));
	});
	reg_method(ft, "applyRatingMod", [](Player * player, CombatRating const rating, int32_t const value) {
		// don't propagate the bool... callers can type the `-` sign themselves.
		player->ApplyRatingMod(rating, value, true);
	});
	reg_method(ft, "setQuestStatus", [](Player * player, uint32_t quest_id, QuestStatus status) {
		player->SetQuestStatus(quest_id, status);
	});
	reg_method(ft, "removeRewardedQuest", [](Player * player, uint32_t quest_id) {
		player->RemoveRewardedQuest(quest_id);
	});
	reg_method(ft, "rewardQuest", [](Player * player, Quest const * quest, std::optional<uint32_t> const reward, std::optional<Object *> const quest_giver, std::optional<bool> const announce, std::optional<bool> const is_lfg_reward) {
		player->RewardQuest(
			quest,
			reward.value_or(0),
			quest_giver.value_or(nullptr),
			announce.value_or(true),
			is_lfg_reward.value_or(false)
		);
	});
	reg_method(ft, "removeActiveQuest", [](Player * player, uint32_t quest_id) {
		player->RemoveActiveQuest(quest_id);
	});
	reg_method(ft, "setKnownTitle", [](Player * player, uint32_t bit_index) {
		// only the bit index is read, so we can just ask for that
		CharTitlesEntry entry{};
		entry.bit_index = bit_index;
		player->SetTitle(&entry, false);
	});
	reg_method(ft, "unsetKnownTitle", [](Player * player, uint32_t bit_index) {
		// only the bit index is read, so we can just ask for that
		CharTitlesEntry entry{};
		entry.bit_index = bit_index;
		player->SetTitle(&entry, true);
	});
	reg_method(ft, "initTaxiNodesForLevel", [](Player * player) {
		player->InitTaxiNodesForLevel();
	});
	reg_method(ft, "startTaxiByTaxiPathId", [](Player * player, uint32_t id, std::optional<uint32_t> spell_id) {
		return player->ActivateTaxiPathTo(id, spell_id.value_or(1));
	});
	reg_method(ft, "startTaxiByNodes", [](Player * player, std::vector<std::uint32_t> nodes_vec, std::optional<Creature *> npc, std::optional<uint32_t> spell_id) {
		return player->ActivateTaxiPathTo(nodes_vec, npc.value_or(nullptr), spell_id.value_or(1));
	});
	reg_method(ft, "toggleInstantFlight", [](Player * player) {
		player->ToggleInstantFlight();
	});
	reg_method(ft, "removeAmmo", [](Player * player) {
		player->RemoveAmmo();
	});
	reg_method(ft, "setAmmo", [](Player * player, uint32_t const itemEntry) {
		player->SetAmmo(itemEntry);
	});
	reg_method(ft, "spawnBones", [](Player * player) {
		player->SpawnCorpseBones();
	});
	reg_method(ft, "gainSpellComboPoints", [](Player * player, int8_t const count) {
		player->AddComboPoints(count);
	});
	reg_method(ft, "applySpellPowerBonus", [](Player * player, int32_t const value, std::optional<bool> const apply) {
		player->ApplySpellPowerBonus(value, apply.value_or(false));
	});
	reg_method(ft, "resetTypeCooldowns", [](Player * player, uint32_t const type) {
		player->RemoveCategoryCooldown(type);
	});
	reg_method(ft, "removeArenaSpellCooldowns", [](Player * player) {
		player->RemoveArenaSpellCooldowns();
	});
	reg_method(ft, "setShowDKPet", [](Player * player, bool const show) {
		player->SetByteFlag(UNIT_FIELD_BYTES_1, 1, show ? 0x8 : 0);
	});
	reg_method(ft, "setPvPDeath", [](Player * player, bool const isPvPDeath) {
		player->SetPvPDeath(isPvPDeath);
	});
	reg_method(ft, "setPlayerFlag", [](Player * player, PlayerFlags const flag) {
		player->SetPlayerFlag(flag);
	});
	reg_method(ft, "removePlayerFlag", [](Player * player, PlayerFlags const flag) {
		player->RemovePlayerFlag(flag);
	});
	reg_method(ft, "getPlayerSettingValue", [](Player * player, std::string const source, uint32_t const index) {
		return player->GetPlayerSetting(source, index).value;
	});
	reg_method(ft, "getXPRestBonus", [](Player * player, uint32_t const xp) {
		return player->GetXPRestBonus(xp);
	});
	reg_method(ft, "setBindPoint", [](Player * player, float const x, float const y, float const z, uint32_t const mapId, uint32_t const areaId) {
		const WorldLocation loc(mapId, x, y, z);
		player->SetHomebind(loc, areaId);
	});
	reg_method(ft, "setFactionForRace", [](Player * player, uint8_t const race) {
		player->SetFactionForRace(race);
	});
	reg_method(ft, "setKnownTaxiNodes", [](Player * player, std::vector<uint32_t> nodes) {
		for (auto i : nodes) {
			player->m_taxi.SetTaximaskNode(i);
		}
	});
	reg_method(ft, "setReputation", [](Player * player, FactionEntry const * faction, float const value) {
		player->GetReputationMgr().SetReputation(faction, value);
	});
	reg_method(ft, "setRestState", [](Player * player, uint32_t const restState) {
		player->SetRestState(restState);
	});
	reg_method(ft, "updatePlayerSetting", [](Player * player, std::string const source, uint32_t const index, uint32_t const value) {
		player->UpdatePlayerSetting(source, index, value);
	});
	reg_method(ft, "durabilityLoss", [](Player * player, Item * item, float const amount) {
		player->DurabilityLoss(item, amount);
	});
	reg_method(ft, "durabilityPointLossForEquipSlot", [](Player * player, EquipmentSlots const slot) {
		player->DurabilityPointLossForEquipSlot(slot);
	});
	reg_method(ft, "durabilityPointsLoss", [](Player * player, Item * item, int32_t const points) {
		player->DurabilityPointsLoss(item, points);
	});
	reg_method(ft, "sendQuestTemplate", [](Player * player, ObjectGuid quest_giver, Quest const * quest, std::optional<bool> activate_accept) {
		player->PlayerTalkClass->SendQuestGiverQuestDetails(quest, quest_giver, activate_accept.value_or(true));
	});
	reg_method(ft, "sendTabardVendorActivate", [](Player * player, ObjectGuid creature) {
		player->GetSession()->SendTabardVendorActivate(creature);
	});
	reg_method(ft, "sendUpdateWorldState", [](Player * player, uint32_t const dataId, int32_t const value) {
		player->SendUpdateWorldState(dataId, value);
	});
	reg_method(ft, "removedInsignia", [](Player * player, Player * looter) {
		player->RemovedInsignia(looter);
	});
	reg_method(ft, "killPlayer", [](Player * player) {
		player->KillPlayer();
	});
	reg_method(ft, "textEmote", [](Player * player, std::string const text) {
		player->TextEmote(text);
	});
	reg_method(ft, "removeBonusTalent", [](Player * player, uint32_t const count) {
		player->RemoveBonusTalent(count);
	});
	reg_method(ft, "storeNewItemInBestSlots", [](Player * player, uint32_t item_id, uint32_t item_count) {
		return player->StoreNewItemInBestSlots(item_id, item_count);
	});
	reg_method(ft, "sendDirectMessage", [](Player * player, WorldPacket * packet) {
		player->SendDirectMessage(packet);
	});
	reg_method(ft, "addRestXP", [](Player * player, float xp) {
		auto new_bonus = player->GetRestBonus() + xp;
		player->SetRestBonus(new_bonus);
		return new_bonus - player->GetRestBonus();
	});

	return ft;
}
