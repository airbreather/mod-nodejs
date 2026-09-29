#include "AllItemScript.h"

#include <string>

#include "NodeJs.h"

class NODEJS_AllItem : public AllItemScript {
public:
	NODEJS_AllItem() : AllItemScript("NODEJS_AllItem") {
	}

	[[nodiscard]] bool CanItemQuestAccept(Player * player, Item * item, Quest const * quest) override {
		return NodeJs::invoke_hook_t("item:can-quest-accept", AllItemScript::CanItemQuestAccept(player, item, quest)
			, jprop("player", player), jprop("item", item), jprop("quest", quest));
	}
	[[nodiscard]] bool CanItemUse(Player * player, Item * item, SpellCastTargets const & targets) override {
		return NodeJs::invoke_hook_t("item:can-use", AllItemScript::CanItemUse(player, item, targets)
			, jprop("player", player), jprop("item", item)/*, jprop("targets", &targets)*/);
	}
	[[nodiscard]] bool CanItemRemove(Player * player, Item * item) override {
		return NodeJs::invoke_hook_t("item:can-remove", AllItemScript::CanItemRemove(player, item)
			, jprop("player", player), jprop("item", item));
	}
	[[nodiscard]] bool CanItemExpire(Player * player, ItemTemplate const * proto) override {
		return NodeJs::invoke_hook_t("item:can-expire", AllItemScript::CanItemExpire(player, proto)
			, jprop("player", player), jprop("proto", proto));
	}
	void OnItemGossipSelect(Player * player, Item * item, uint32_t const sender, uint32_t const action) override {
		NodeJs::invoke_hook("item:gossip-select"
			, jprop("player", player), jprop("item", item), jprop("sender", sender), jprop("action", action));
	}
	void OnItemGossipSelectCode(Player * player, Item * item, uint32_t const sender, uint32_t const action, const char* code) override {
		NodeJs::invoke_hook("item:gossip-select-code"
			, jprop("player", player), jprop("item", item), jprop("sender", sender), jprop("action", action), jprop("code", code));
	}
};

void AddSC_AllItem() {
	new NODEJS_AllItem();
}
