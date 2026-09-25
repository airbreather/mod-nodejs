#include "AllGameObjectScript.h"

#include <string>

#include "DurationWrapper.h"
#include "JBox.h"
#include "NodeJs.h"

class NODEJS_AllGameObject : public AllGameObjectScript {
public:
	NODEJS_AllGameObject() : AllGameObjectScript("NODEJS_AllGameObject") {
	}

	void OnGameObjectAddWorld(GameObject * go) override {
		NodeJs::invoke_hook("game-object:add-world"
			, jprop("gameObject", go));
	}
	void OnGameObjectSaveToDB(GameObject * go) override {
		NodeJs::invoke_hook("game-object:save-to-db"
			, jprop("gameObject", go));
	}
	void OnGameObjectRemoveWorld(GameObject * go) override {
		NodeJs::invoke_hook("game-object:remove-world"
			, jprop("gameObject", go));
	}
	void OnGameObjectUpdate(GameObject * go, uint32_t const diff) override {
		NodeJs::invoke_hook("game-object:update"
			, jprop("gameObject", go), jprop("diff", DurationWrapper::from_milliseconds(diff)));
	}
	[[nodiscard]] bool CanGameObjectGossipHello(Player* player, GameObject * go) override {
		return NodeJs::invoke_hook_t("game-object:can-gossip-hello", AllGameObjectScript::CanGameObjectGossipHello(player, go)
			, jprop("player", player), jprop("gameObject", go));
	}
	[[nodiscard]] bool CanGameObjectGossipSelect(Player * player, GameObject * go, uint32_t const sender, uint32_t const action) override {
		return NodeJs::invoke_hook_t("game-object:can-gossip-select", AllGameObjectScript::CanGameObjectGossipSelect(player, go, sender, action)
			, jprop("player", player), jprop("gameObject", go), jprop("sender", sender), jprop("action", action));
	}
	[[nodiscard]] bool CanGameObjectGossipSelectCode(Player * player, GameObject * go, uint32_t const sender, uint32_t const action, char const * code) override {
		return NodeJs::invoke_hook_t("game-object:can-gossip-select-code", AllGameObjectScript::CanGameObjectGossipSelectCode(player, go, sender, action, code)
			, jprop("player", player), jprop("gameObject", go), jprop("sender", sender), jprop("action", action), jprop("code", code));
	}
	[[nodiscard]] bool CanGameObjectQuestAccept(Player * player, GameObject * go, Quest const * quest) override {
		return NodeJs::invoke_hook_t("game-object:can-quest-accept", AllGameObjectScript::CanGameObjectQuestAccept(player, go, quest)
			, jprop("player", player), jprop("gameObject", go), jprop("quest", quest));
	}
	[[nodiscard]] bool CanGameObjectQuestReward(Player * player, GameObject * go, Quest const * quest, uint32_t opt) override {
		return NodeJs::invoke_hook_t("game-object:can-quest-reward", AllGameObjectScript::CanGameObjectQuestReward(player, go, quest, opt)
			, jprop("player", player), jprop("gameObject", go), jprop("quest", quest), jprop("opt", opt));
	}
	void OnGameObjectDestroyed(GameObject * go, Player * player) override {
		NodeJs::invoke_hook("game-object:destroyed"
			, jprop("gameObject", go), jprop("player", player));
	}
	void OnGameObjectDamaged(GameObject * go, Player * player) override {
		NodeJs::invoke_hook("game-object:damaged"
			, jprop("gameObject", go), jprop("player", player));
	}
	void OnGameObjectModifyHealth(GameObject * go, Unit * attackerOrHealer, int32 & change, SpellInfo const * spellInfo) override {
		NodeJs::invoke_hook("game-object:modify-health"
			, jprop("gameObject", go), jprop("attackerOrHealer", attackerOrHealer), jprop_box("change", change), jprop("spellInfo", spellInfo));
	}
	void OnGameObjectLootStateChanged(GameObject * go, uint32_t const state, Unit * unit) override {
		NodeJs::invoke_hook("game-object:loot-state-changed"
			, jprop("gameObject", go), jprop("state", state), jprop("unit", unit));
	}
	void OnGameObjectStateChanged(GameObject * go, uint32_t const state) override {
		NodeJs::invoke_hook("game-object:state-changed"
			, jprop("gameObject", go), jprop("state", state));
	}

	// GameObjectAI is going to be a whole thing, I'm sure, but not right now
	////GameObjectAI* GetGameObjectAI(GameObject* go) const override { return nullptr; }
};

void AddSC_AllGameObject() {
	new NODEJS_AllGameObject();
}
