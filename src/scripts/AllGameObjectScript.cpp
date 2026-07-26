#include "AllGameObjectScript.h"

#include <string>

#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_AllGameObject : public AllGameObjectScript {
public:
	NODEJS_AllGameObject() : AllGameObjectScript("NODEJS_AllGameObject") {
	}

	void OnGameObjectAddWorld(GameObject * go) override {
		NodeJs::invoke_hook("all-game-object:add-world", jarg("gameObject", go));
	}
	void OnGameObjectSaveToDB(GameObject * go) override {
		NodeJs::invoke_hook("all-game-object:save-to-db", jarg("gameObject", go));
	}
	void OnGameObjectRemoveWorld(GameObject * go) override {
		NodeJs::invoke_hook("all-game-object:remove-world", jarg("gameObject", go));
	}
	void OnGameObjectUpdate(GameObject * go, uint32_t const diff) override {
		NodeJs::invoke_hook("all-game-object:update", jarg("gameObject", go), jarg("diff", diff));
	}
	[[nodiscard]] bool CanGameObjectGossipHello(Player* player, GameObject * go) override {
		return NodeJs::invoke_hook_t("all-game-object:can-gossip-hello", AllGameObjectScript::CanGameObjectGossipHello(player, go)
			, jarg("player", player), jarg("gameObject", go));
	}
	[[nodiscard]] bool CanGameObjectGossipSelect(Player * player, GameObject * go, uint32_t const sender, uint32_t const action) override {
		return NodeJs::invoke_hook_t("all-game-object:can-gossip-select", AllGameObjectScript::CanGameObjectGossipSelect(player, go, sender, action)
			, jarg("player", player), jarg("gameObject", go), jarg("sender", sender), jarg("action", action));
	}
	[[nodiscard]] bool CanGameObjectGossipSelectCode(Player * player, GameObject * go, uint32_t const sender, uint32_t const action, char const * code) override {
		return NodeJs::invoke_hook_t("all-game-object:can-gossip-select-code", AllGameObjectScript::CanGameObjectGossipSelectCode(player, go, sender, action, code)
			, jarg("player", player), jarg("gameObject", go), jarg("sender", sender), jarg("action", action), jarg("code", code));
	}
	[[nodiscard]] bool CanGameObjectQuestAccept(Player * player, GameObject * go, Quest const * quest) override {
		return NodeJs::invoke_hook_t("all-game-object:can-quest-accept", AllGameObjectScript::CanGameObjectQuestAccept(player, go, quest)
			, jarg("player", player), jarg("gameObject", go), jarg("quest", quest));
	}
	[[nodiscard]] bool CanGameObjectQuestReward(Player * player, GameObject * go, Quest const * quest, uint32_t opt) override {
		return NodeJs::invoke_hook_t("all-game-object:can-quest-reward", AllGameObjectScript::CanGameObjectQuestReward(player, go, quest, opt)
			, jarg("player", player), jarg("gameObject", go), jarg("quest", quest), jarg("opt", opt));
	}
	void OnGameObjectDestroyed(GameObject * go, Player * player) override {
		NodeJs::invoke_hook("all-game-object:destroyed", jarg("gameObject", go), jarg("player", player));
	}
	void OnGameObjectDamaged(GameObject * go, Player * player) override {
		NodeJs::invoke_hook("all-game-object:damaged", jarg("gameObject", go), jarg("player", player));
	}
	void OnGameObjectModifyHealth(GameObject * go, Unit * attackerOrHealer, int32 & change, SpellInfo const * spellInfo) override {
		NodeJs::invoke_hook("all-game-object:modify-health", jarg("gameObject", go), jarg("attackerOrHealer", attackerOrHealer), jarg("change", change), jarg("spellInfo", spellInfo));
	}
	void OnGameObjectLootStateChanged(GameObject * go, uint32_t const state, Unit * unit) override {
		NodeJs::invoke_hook("all-game-object:loot-state-changed", jarg("gameObject", go), jarg("state", state), jarg("unit", unit));
	}
	void OnGameObjectStateChanged(GameObject * go, uint32_t const state) override {
		NodeJs::invoke_hook("all-game-object:state-changed", jarg("gameObject", go), jarg("state", state));
	}

	// GameObjectAI is going to be a whole thing, I'm sure, but not right now
	////GameObjectAI* GetGameObjectAI(GameObject* go) const override { return nullptr; }
};

void AddSC_AllGameObject() {
	new NODEJS_AllGameObject();
}
