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
class Battleground;
class BattlegroundQueue;
class ByteBuffer;
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
struct AuctionEntry;
struct Condition;
struct ConditionSourceInfo;
struct CreatureTemplate;
struct ItemTemplate;
struct Loot;
struct SpellChainNode;
struct SpellEntry;

using ChatCommandBuilderBuilderBox = std::shared_ptr<ChatCommandBuilderBuilder>;
using QueryResult = std::shared_ptr<ResultSet>;

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

	REGISTER_CLASS_PROP_SPLIT_NAMES(Object, ACObject)
	REGISTER_CLASS_PROP_SPLIT_NAMES(AuctionEntry, Auction)
	REGISTER_CLASS_PROP_SPLIT_NAMES(AuctionHouseObject, AuctionHouse)
	REGISTER_CLASS_PROP(Aura)
	REGISTER_CLASS_PROP(Battleground)
	REGISTER_CLASS_PROP(BattlegroundQueue)
	REGISTER_CLASS_PROP(ByteBuffer)
	REGISTER_CLASS_PROP(CharacterDatabaseTransaction)
	REGISTER_CLASS_PROP_SPLIT_NAMES(ChatCommandBuilderBuilderBox, ChatCommandBuilder)
	REGISTER_CLASS_PROP(ChatHandler)
	REGISTER_CLASS_PROP(Condition)
	REGISTER_CLASS_PROP(ConditionSourceInfo)
	REGISTER_CLASS_PROP_SPLIT_NAMES(ConfigMgr const, Config)
	REGISTER_CLASS_PROP_RO(CreatureTemplate)
	REGISTER_CLASS_PROP(Field)
	REGISTER_CLASS_PROP(GmTicket)
	REGISTER_CLASS_PROP(Group)
	REGISTER_CLASS_PROP(Guild)
	REGISTER_CLASS_PROP_SPLIT_NAMES(Guild::Member, GuildMember)
	REGISTER_CLASS_PROP_RO(ItemTemplate)
	REGISTER_CLASS_PROP(Loot)
	REGISTER_CLASS_PROP_RO(LootStore)
	REGISTER_CLASS_PROP_RO(LootTemplate)
	REGISTER_CLASS_PROP(MailDraft)
	REGISTER_CLASS_PROP(MailSender)
	REGISTER_CLASS_PROP_SPLIT_NAMES(Map, ACMap)
	REGISTER_CLASS_PROP(QueryResult)
	REGISTER_CLASS_PROP_RO(Quest)
	REGISTER_CLASS_PROP(Roll)
	REGISTER_CLASS_PROP(SpellChainNode)
	REGISTER_CLASS_PROP_RO(SpellEntry)
	REGISTER_CLASS_PROP_RO(SpellEffectInfo)
	REGISTER_CLASS_PROP_RO(SpellImplicitTargetInfo)
	REGISTER_CLASS_PROP_RO(SpellInfo)
	REGISTER_CLASS_PROP(Spell)
	REGISTER_CLASS_PROP(ThreatReference)
	REGISTER_CLASS_PROP(Vehicle)

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
