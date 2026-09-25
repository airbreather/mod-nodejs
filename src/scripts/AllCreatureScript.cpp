#include "AllCreatureScript.h"

#include <string>

#include "DurationWrapper.h"
#include "NodeJs.h"

class NODEJS_AllCreature : public AllCreatureScript {
public:
	NODEJS_AllCreature() : AllCreatureScript("NODEJS_AllCreature") {
	}

	void OnAllCreatureUpdate(Creature * creature, uint32_t const diff) override {
		NodeJs::invoke_hook("creature:update"
			, jprop("creature", creature), jprop("diff", DurationWrapper::from_milliseconds(diff)));
	}
	void OnBeforeCreatureSelectLevel(CreatureTemplate const * cinfo, Creature * creature, uint8 & level) override {
		NodeJs::invoke_hook("creature:before-select-level"
			, jprop("cInfo", cinfo), jprop("creature", creature), jprop_box("level", level));
	}
	void OnCreatureSelectLevel(CreatureTemplate const * cinfo, Creature * creature) override {
		NodeJs::invoke_hook("creature:select-level"
			, jprop("cInfo", cinfo), jprop("creature", creature));
	}
	void OnCreatureAddWorld(Creature * creature) override {
		NodeJs::invoke_hook("creature:add-world"
			, jprop("creature", creature));
	}
	void OnCreatureRemoveWorld(Creature * creature) override {
		NodeJs::invoke_hook("creature:remove-world"
			, jprop("creature", creature));
	}
	void OnCreatureSaveToDB(Creature * creature) override {
		NodeJs::invoke_hook("creature:save-to-db"
			, jprop("creature", creature));
	}
	[[nodiscard]] bool CanCreatureGossipHello(Player * player, Creature * creature) override {
		return NodeJs::invoke_hook_t("creature:can-gossip-hello", AllCreatureScript::CanCreatureGossipHello(player, creature)
			, jprop("player", player), jprop("creature", creature));
	}
	[[nodiscard]] bool CanCreatureGossipSelect(Player * player, Creature * creature, uint32_t const sender, uint32_t const action) override {
		return NodeJs::invoke_hook_t("creature:can-gossip-select", AllCreatureScript::CanCreatureGossipSelect(player, creature, sender, action)
			, jprop("player", player), jprop("creature", creature), jprop("sender", sender), jprop("action", action));
	}
	[[nodiscard]] bool CanCreatureGossipSelectCode(Player * player, Creature * creature, uint32_t const sender, uint32_t const action, char const * code) override {
		return NodeJs::invoke_hook_t("creature:can-gossip-select-code", AllCreatureScript::CanCreatureGossipSelectCode(player, creature, sender, action, code)
			, jprop("player", player), jprop("creature", creature), jprop("sender", sender), jprop("action", action), jprop("code", code));
	}
	[[nodiscard]] bool CanCreatureQuestAccept(Player * player, Creature * creature, Quest const * quest) override {
		return NodeJs::invoke_hook_t("creature:can-quest-accept", AllCreatureScript::CanCreatureQuestAccept(player, creature, quest)
			, jprop("player", player), jprop("creature", creature), jprop("quest", quest));
	}
	[[nodiscard]] bool CanCreatureQuestReward(Player * player, Creature * creature, Quest const * quest, uint32_t const opt) override {
		return NodeJs::invoke_hook_t("creature:can-quest-reward", AllCreatureScript::CanCreatureQuestReward(player, creature, quest, opt)
			, jprop("player", player), jprop("creature", creature), jprop("quest", quest), jprop("opt", opt));
	}
	void OnFfaPvpStateUpdate(Creature* creature, bool const InPvp) override {
		NodeJs::invoke_hook("creature:ffa-pvp-state-update"
			, jprop("creature", creature), jprop("inPvp", InPvp));
	}

	// CreatureAI is going to be a whole thing, I'm sure, but not right now
	////[[nodiscard]] CreatureAI* GetCreatureAI(Creature * creature) const override { return nullptr; }
};

void AddSC_AllCreature() {
	new NODEJS_AllCreature();
}
