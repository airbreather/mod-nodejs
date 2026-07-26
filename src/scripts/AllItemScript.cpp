#include "AllItemScript.h"

#include <string>

#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_AllItem : public AllItemScript {
public:
	NODEJS_AllItem() : AllItemScript("NODEJS_AllItem") {
	}

	[[nodiscard]] bool CanItemQuestAccept(Player * player, Item * item, Quest const * quest) override {
		return NodeJs::invoke_hook_t("all-item:can-quest-accept", AllItemScript::CanItemQuestAccept(player, item, quest)
			, jarg("player", player), jarg("item", item), jarg("quest", quest));
	}
	[[nodiscard]] bool CanItemUse(Player * player, Item * item, SpellCastTargets const & targets) override {
		return NodeJs::invoke_hook_t("all-item:can-use", AllItemScript::CanItemUse(player, item, targets)
			, jarg("player", player), jarg("item", item)/*, jarg("targets", &targets)*/);
	}
	[[nodiscard]] bool CanItemRemove(Player * player, Item * item) override {
		return NodeJs::invoke_hook_t("all-item:can-remove", AllItemScript::CanItemRemove(player, item)
			, jarg("player", player), jarg("item", item));
	}
	[[nodiscard]] bool CanItemExpire(Player * player, ItemTemplate const * proto) override {
		return NodeJs::invoke_hook_t("all-item:can-expire", AllItemScript::CanItemExpire(player, proto)
			, jarg("player", player), jarg("proto", proto));
	}
	void OnItemGossipSelect(Player * player, Item * item, uint32_t const sender, uint32_t const action) override {
		NodeJs::invoke_hook("all-item:gossip-select", jarg("player", player), jarg("item", item), jarg("sender", sender), jarg("action", action));
	}
	void OnItemGossipSelectCode(Player * player, Item * item, uint32_t const sender, uint32_t const action, const char* code) override {
		NodeJs::invoke_hook("all-item:gossip-select-code", jarg("player", player), jarg("item", item), jarg("sender", sender), jarg("action", action), jarg("code", code));
	}
};

void AddSC_AllItem() {
	new NODEJS_AllItem();
}
