#include <optional>
#include <string>
#include <v8-function-callback.h>
#include <v8-isolate.h>
#include <v8-local-handle.h>
#include <v8-maybe.h>
#include <v8-object.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "Guild.h"
#include "JtoC.h"
#include "NodeJs.h"
#include "NodePropertySystem.h"

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
struct Condition;
struct ConditionSourceInfo;
struct ItemTemplate;
struct Loot;
struct SpellChainNode;
struct SpellEntry;

using ChatCommandBuilderBuilderBox = std::shared_ptr<ChatCommandBuilderBuilder>;
using QueryResult = std::shared_ptr<ResultSet>;

void AddGlobalFunctions(TypedTemplate<NodeJs *> ft);

void PopulateGlobalInteropObjectTemplate(TypedTemplate<NodeJs *> const ft) {

#define REGISTER_CLASS_PROP_SPLIT_NAMES(cname, jname) \
	NodeJs::instance()->reg_template<cname *>(jcreate_template<cname *>()); \
	reg_prop_ro(ft, #jname, [](NodeJs * r) { \
		return r->get_template<cname *>()->GetFunction(v8::Isolate::GetCurrent()->GetCurrentContext()).ToLocalChecked(); \
	});
#define REGISTER_CLASS_PROP(tclass) REGISTER_CLASS_PROP_SPLIT_NAMES(tclass, tclass)
#define REGISTER_CLASS_PROP_RO(tclass) REGISTER_CLASS_PROP_SPLIT_NAMES(tclass const, tclass)

	REGISTER_CLASS_PROP_SPLIT_NAMES(Object, ACObject)
	REGISTER_CLASS_PROP(Aura)
	REGISTER_CLASS_PROP(Battleground)
	REGISTER_CLASS_PROP(BattlegroundQueue)
	REGISTER_CLASS_PROP(ByteBuffer)
	REGISTER_CLASS_PROP_SPLIT_NAMES(ChatCommandBuilderBuilderBox, ChatCommandBuilder)
	REGISTER_CLASS_PROP(ChatHandler)
	REGISTER_CLASS_PROP(Condition)
	REGISTER_CLASS_PROP(ConditionSourceInfo)
	REGISTER_CLASS_PROP_SPLIT_NAMES(ConfigMgr const, Config)
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
	REGISTER_CLASS_PROP(Map)
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

#undef REGISTER_CLASS_PROP

	AddGlobalFunctions(ft);
}

v8::Local<v8::FunctionTemplate> create_global_interop_object_template() {
	auto const isolate = v8::Isolate::GetCurrent();
	auto const ft = v8::FunctionTemplate::New(isolate,
		[](v8::FunctionCallbackInfo<v8::Value> const & info) {
			auto const context = info.GetIsolate()->GetCurrentContext();
			info.This().As<v8::Object>()->Set(
				context,
				jstr_intern("hooks"),
				info[0]
			).Check();
		});
	ft->InstanceTemplate()->SetInternalFieldCount(2);

	PopulateGlobalInteropObjectTemplate(ft);

	return ft;
}

v8::Local<v8::FunctionTemplate> create_add_listener_callback_template() {
	auto const isolate = v8::Isolate::GetCurrent();
	return v8::FunctionTemplate::New(isolate,
		[](v8::FunctionCallbackInfo<v8::Value> const & info) {
			auto const event_name = *cval<std::string>(info[0]);
			NodeJs::instance()->add_listener(event_name);
		});
}

v8::Local<v8::FunctionTemplate> create_remove_listener_callback_template() {
	auto const isolate = v8::Isolate::GetCurrent();
	return v8::FunctionTemplate::New(isolate,
		[](v8::FunctionCallbackInfo<v8::Value> const & info) {
			auto const event_name = *cval<std::string>(info[0]);
			NodeJs::instance()->remove_listener(event_name);
		});
}

template<>
std::optional<NodeJs *> cval<NodeJs *>(v8::Local<v8::Value> const) {
	return {NodeJs::instance()};
}
