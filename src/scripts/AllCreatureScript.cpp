#include "AllCreatureScript.h"

#include <string>

#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_AllCreature : public AllCreatureScript {
public:
	NODEJS_AllCreature() : AllCreatureScript("NODEJS_AllCreature") {
	}

	void OnAllCreatureUpdate(Creature * creature, uint32_t const diff) override {
		NodeJs::invoke_hook("all-creature:update", jarg("creature", creature), jarg("diff", diff));
	}
	void OnBeforeCreatureSelectLevel(CreatureTemplate const * cinfo, Creature * creature, uint8 & level) override {
		NodeJs::invoke_hook("all-creature:before-select-level"/*, jarg("cinfo", cinfo)*/, jarg("creature", creature), jarg_inout("level", level));
	}
	void OnCreatureSelectLevel(CreatureTemplate const * cinfo, Creature * creature) override {
		NodeJs::invoke_hook("all-creature:select-level"/*, jarg("cinfo", cinfo)*/, jarg("creature", creature));
	}
	void OnCreatureAddWorld(Creature * creature) override {
		NodeJs::invoke_hook("all-creature:add-world", jarg("creature", creature));
	}
	void OnCreatureRemoveWorld(Creature * creature) override {
		NodeJs::invoke_hook("all-creature:remove-world", jarg("creature", creature));
	}
	void OnCreatureSaveToDB(Creature * creature) override {
		NodeJs::invoke_hook("all-creature:save-to-db", jarg("creature", creature));
	}
	[[nodiscard]] bool CanCreatureGossipHello(Player * player, Creature * creature) override {
		return NodeJs::invoke_hook_t("all-creature:can-gossip-hello", AllCreatureScript::CanCreatureGossipHello(player, creature)
			, jarg("player", player), jarg("creature", creature));
	}
	[[nodiscard]] bool CanCreatureGossipSelect(Player * player, Creature * creature, uint32_t const sender, uint32_t const action) override {
		return NodeJs::invoke_hook_t("all-creature:can-gossip-select", AllCreatureScript::CanCreatureGossipSelect(player, creature, sender, action)
			, jarg("player", player), jarg("creature", creature), jarg("sender", sender), jarg("action", action));
	}
	[[nodiscard]] bool CanCreatureGossipSelectCode(Player * player, Creature * creature, uint32_t const sender, uint32_t const action, char const * code) override {
		return NodeJs::invoke_hook_t("all-creature:can-gossip-select-code", AllCreatureScript::CanCreatureGossipSelectCode(player, creature, sender, action, code)
			, jarg("player", player), jarg("creature", creature), jarg("sender", sender), jarg("action", action), jarg("code", code));
	}
	[[nodiscard]] bool CanCreatureQuestAccept(Player * player, Creature * creature, Quest const * quest) override {
		return NodeJs::invoke_hook_t("all-creature:can-quest-accept", AllCreatureScript::CanCreatureQuestAccept(player, creature, quest)
			, jarg("player", player), jarg("creature", creature), jarg("quest", quest));
	}
	[[nodiscard]] bool CanCreatureQuestReward(Player * player, Creature * creature, Quest const * quest, uint32_t const opt) override {
		return NodeJs::invoke_hook_t("all-creature:can-quest-reward", AllCreatureScript::CanCreatureQuestReward(player, creature, quest, opt)
			, jarg("player", player), jarg("creature", creature), jarg("quest", quest), jarg("opt", opt));
	}
	void OnFfaPvpStateUpdate(Creature* creature, bool const InPvp) override {
		NodeJs::invoke_hook("all-creature:ffa-pvp-state-update", jarg("creature", creature), jarg("inPvp", InPvp));
	}

	// CreatureAI is going to be a whole thing, I'm sure, but not right now
	////[[nodiscard]] CreatureAI* GetCreatureAI(Creature * creature) const override { return nullptr; }
};

void AddSC_AllCreature() {
	new NODEJS_AllCreature();
}
