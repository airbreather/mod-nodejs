#include <optional>
#include <v8-isolate.h>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "Guild.h"
#include "JtoC.h"
#include "NodeJs.h"
#include "NodePropertySystem.h"

class AuctionHouseObject;
class Aura;
class AuraApplication;
class AuraEffect;
class Battleground;
class BattlegroundQueue;
class ByteBuffer;
class Channel;
class ChatCommandBuilderBuilder;
class ChatHandler;
class ConfigMgr;
class Corpse;
class Creature;
class DynamicObject;
class GameObject;
class GmTicket;
class Group;
class Guardian;
class Item;
class LootStore;
class LootTemplate;
class MailDraft;
class MailSender;
class Map;
class Minion;
class Object;
class ObjectMgr;
class Pet;
class Player;
class Quest;
class ResultSet;
class Roll;
class Spell;
class SpellEffectInfo;
class SpellImplicitTargetInfo;
class SpellInfo;
class TempSummon;
class ThreatReference;
class Transport;
class Unit;
class Vehicle;
class WorldObject;
class WorldPacket;
struct AchievementEntry;
struct AuctionEntry;
struct CastSpellBuilder;
struct CharTitlesEntry;
struct Condition;
struct ConditionSourceInfo;
struct CreatureTemplate;
struct FactionEntry;
struct GameObjectTemplate;
struct GemPropertiesEntry;
struct GlyphPropertiesEntry;
struct ItemTemplate;
struct Loot;
struct MySQLConnectionInfo;
struct PvPDifficultyEntry;
struct SpawnCreatureBuilder;
struct SpawnGameObjectBuilder;
struct SpellCastTimesEntry;
struct SpellCategoryEntry;
struct SpellChainNode;
struct SpellDurationEntry;
struct SpellRadiusEntry;
struct SpellRangeEntry;
struct SummonPropertiesEntry;
struct VehicleEntry;
struct VendorItem;
struct VendorItemData;

using ChatCommandBuilderBuilderBox = std::shared_ptr<ChatCommandBuilderBuilder>;
using QueryResult = std::shared_ptr<ResultSet>;

using AreaDamageData = decltype(GameObjectTemplate().areadamage);
using AuraGeneratorData = decltype(GameObjectTemplate().auraGenerator);
using BarberChairData = decltype(GameObjectTemplate().barberChair);
using ButtonData = decltype(GameObjectTemplate().button);
using CameraData = decltype(GameObjectTemplate().camera);
using CapturePointData = decltype(GameObjectTemplate().capturePoint);
using ChairData = decltype(GameObjectTemplate().chair);
using ChestData = decltype(GameObjectTemplate().chest);
using DestructibleBuildingData = decltype(GameObjectTemplate().building);
using DoorData = decltype(GameObjectTemplate().door);
using DungeonDifficultyData = decltype(GameObjectTemplate().dungeonDifficulty);
using FishingHoleData = decltype(GameObjectTemplate().fishinghole);
using FlagDropData = decltype(GameObjectTemplate().flagdrop);
using FlagStandData = decltype(GameObjectTemplate().flagstand);
using GenericData = decltype(GameObjectTemplate()._generic);
using GooberData = decltype(GameObjectTemplate().goober);
using GuardPostData = decltype(GameObjectTemplate().guardpost);
using MeetingStoneData = decltype(GameObjectTemplate().meetingstone);
using MiniGameData = decltype(GameObjectTemplate().miniGame);
using MoTransportData = decltype(GameObjectTemplate().moTransport);
using QuestGiverData = decltype(GameObjectTemplate().questgiver);
using SpellcasterData = decltype(GameObjectTemplate().spellcaster);
using SpellFocusData = decltype(GameObjectTemplate().spellFocus);
using SummoningRitualData = decltype(GameObjectTemplate().summoningRitual);
using TextData = decltype(GameObjectTemplate().text);
using TransportData = decltype(GameObjectTemplate().transport);
using TrapData = decltype(GameObjectTemplate().trap);
using TrapDoorData = decltype(GameObjectTemplate().trapDoor);

void add_global_functions(TypedTemplate<NodeJs *> ft);

template <>
v8::Local<v8::FunctionTemplate> jcreate_template<NodeJs *>() {
	TypedTemplate<NodeJs *> const ft = jctor();

	ft->SetClassName(jstr_intern("Acore"));

#define REGISTER_CLASS_PROP_SPLIT_NAMES(cname, jname) \
	NodeJs::instance()->reg_template<cname *>(jcreate_template<cname *>()); \
	reg_prop_ro(ft, #jname, [](NodeJs * r) { \
		return r->get_template<cname *>()->GetFunction(v8::Isolate::GetCurrent()->GetCurrentContext()).ToLocalChecked(); \
	});
#define REGISTER_CLASS_PROP(tclass) REGISTER_CLASS_PROP_SPLIT_NAMES(tclass, tclass)
#define REGISTER_CLASS_PROP_RO(tclass) REGISTER_CLASS_PROP_SPLIT_NAMES(tclass const, tclass)

	REGISTER_CLASS_PROP_RO(AchievementEntry)
	REGISTER_CLASS_PROP_SPLIT_NAMES(Object, ACObject)
	REGISTER_CLASS_PROP_RO(AreaDamageData)
	REGISTER_CLASS_PROP_SPLIT_NAMES(AuctionEntry, Auction)
	REGISTER_CLASS_PROP_SPLIT_NAMES(AuctionHouseObject, AuctionHouse)
	REGISTER_CLASS_PROP(Aura)
	REGISTER_CLASS_PROP(AuraApplication)
	REGISTER_CLASS_PROP(AuraEffect)
	REGISTER_CLASS_PROP_RO(AuraGeneratorData)
	REGISTER_CLASS_PROP_RO(BarberChairData)
	REGISTER_CLASS_PROP(Battleground)
	REGISTER_CLASS_PROP(BattlegroundQueue)
	REGISTER_CLASS_PROP_RO(ButtonData)
	REGISTER_CLASS_PROP(ByteBuffer)
	REGISTER_CLASS_PROP_RO(CameraData)
	REGISTER_CLASS_PROP_RO(CapturePointData)
	REGISTER_CLASS_PROP(CastSpellBuilder)
	REGISTER_CLASS_PROP_RO(ChairData)
	REGISTER_CLASS_PROP_RO(CharTitlesEntry)
	REGISTER_CLASS_PROP(Channel)
	REGISTER_CLASS_PROP_SPLIT_NAMES(ChatCommandBuilderBuilderBox, ChatCommandBuilder)
	REGISTER_CLASS_PROP(ChatHandler)
	REGISTER_CLASS_PROP_RO(ChestData)
	REGISTER_CLASS_PROP(Condition)
	REGISTER_CLASS_PROP(ConditionSourceInfo)
	REGISTER_CLASS_PROP_SPLIT_NAMES(ConfigMgr const, Config)
	REGISTER_CLASS_PROP_RO(CreatureTemplate)
	REGISTER_CLASS_PROP_RO(DestructibleBuildingData)
	REGISTER_CLASS_PROP_RO(DoorData)
	REGISTER_CLASS_PROP_RO(DungeonDifficultyData)
	REGISTER_CLASS_PROP_RO(FactionEntry)
	REGISTER_CLASS_PROP(Field)
	REGISTER_CLASS_PROP_RO(FishingHoleData)
	REGISTER_CLASS_PROP_RO(FlagDropData)
	REGISTER_CLASS_PROP_RO(FlagStandData)
	REGISTER_CLASS_PROP_RO(GameObjectTemplate)
	REGISTER_CLASS_PROP_RO(GemPropertiesEntry)
	REGISTER_CLASS_PROP_RO(GenericData)
	REGISTER_CLASS_PROP_RO(GlyphPropertiesEntry)
	REGISTER_CLASS_PROP(GmTicket)
	REGISTER_CLASS_PROP(Group)
	REGISTER_CLASS_PROP_RO(GooberData)
	REGISTER_CLASS_PROP_RO(GuardPostData)
	REGISTER_CLASS_PROP(Guild)
	REGISTER_CLASS_PROP_SPLIT_NAMES(Guild::Member, GuildMember)
	REGISTER_CLASS_PROP_RO(ItemTemplate)
	REGISTER_CLASS_PROP(Loot)
	REGISTER_CLASS_PROP_RO(LootStore)
	REGISTER_CLASS_PROP_RO(LootTemplate)
	REGISTER_CLASS_PROP(MailDraft)
	REGISTER_CLASS_PROP(MailSender)
	REGISTER_CLASS_PROP_SPLIT_NAMES(Map, ACMap)
	REGISTER_CLASS_PROP_RO(MeetingStoneData)
	REGISTER_CLASS_PROP_RO(MiniGameData)
	REGISTER_CLASS_PROP_RO(MoTransportData)
	REGISTER_CLASS_PROP_RO(MySQLConnectionInfo)
	REGISTER_CLASS_PROP(ObjectMgr)
	REGISTER_CLASS_PROP_RO(PvPDifficultyEntry)
	REGISTER_CLASS_PROP(QueryResult)
	REGISTER_CLASS_PROP_RO(Quest)
	REGISTER_CLASS_PROP_RO(QuestGiverData)
	REGISTER_CLASS_PROP(Roll)
	REGISTER_CLASS_PROP(SpawnCreatureBuilder)
	REGISTER_CLASS_PROP(SpawnGameObjectBuilder)
	REGISTER_CLASS_PROP_RO(SpellcasterData)
	REGISTER_CLASS_PROP_RO(SpellCastTimesEntry)
	REGISTER_CLASS_PROP_RO(SpellCategoryEntry)
	REGISTER_CLASS_PROP(SpellChainNode)
	REGISTER_CLASS_PROP_RO(SpellDurationEntry)
	REGISTER_CLASS_PROP_RO(SpellEffectInfo)
	REGISTER_CLASS_PROP_RO(SpellFocusData)
	REGISTER_CLASS_PROP_RO(SpellImplicitTargetInfo)
	REGISTER_CLASS_PROP_RO(SpellInfo)
	REGISTER_CLASS_PROP_RO(SpellRadiusEntry)
	REGISTER_CLASS_PROP_RO(SpellRangeEntry)
	REGISTER_CLASS_PROP(Spell)
	REGISTER_CLASS_PROP_RO(SummoningRitualData)
	REGISTER_CLASS_PROP_RO(SummonPropertiesEntry)
	REGISTER_CLASS_PROP_RO(TextData)
	REGISTER_CLASS_PROP(ThreatReference)
	REGISTER_CLASS_PROP_RO(TransportData)
	REGISTER_CLASS_PROP_RO(TrapData)
	REGISTER_CLASS_PROP_RO(TrapDoorData)
	REGISTER_CLASS_PROP(Vehicle)
	REGISTER_CLASS_PROP_RO(VehicleEntry)
	REGISTER_CLASS_PROP(VendorItem)
	REGISTER_CLASS_PROP(VendorItemData)

	REGISTER_CLASS_PROP(Item) // ACObject
	REGISTER_CLASS_PROP(WorldObject) // ACObject
	REGISTER_CLASS_PROP(WorldPacket) // ByteBuffer

	REGISTER_CLASS_PROP(Corpse) // WorldObject
	REGISTER_CLASS_PROP(DynamicObject) // WorldObject
	REGISTER_CLASS_PROP(GameObject) // WorldObject
	REGISTER_CLASS_PROP(Unit) // WorldObject

	REGISTER_CLASS_PROP(Creature) // Unit
	REGISTER_CLASS_PROP(Player) // Unit
	REGISTER_CLASS_PROP(Transport) // GameObject

	REGISTER_CLASS_PROP(TempSummon) // Creature

	REGISTER_CLASS_PROP(Minion) // TempSummon

	REGISTER_CLASS_PROP(Guardian) // Minion

	REGISTER_CLASS_PROP(Pet) // Guardian

#undef REGISTER_CLASS_PROP_RO
#undef REGISTER_CLASS_PROP
#undef REGISTER_CLASS_PROP_SPLIT_NAMES

	add_global_functions(ft);

	return ft;
}

template<>
std::optional<NodeJs *> cval<NodeJs *>(v8::Local<v8::Value> const) {
	return {NodeJs::instance()};
}
