#include "LootScript.h"

#include <string>

#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_Loot : public LootScript {
public:
	NODEJS_Loot() : LootScript("NODEJS_Loot") {
	}

	void OnLootMoney(Player * player, uint32_t const gold) override {
		NodeJs::invoke_hook("loot:money", jarg("player", player), jarg("gold", gold));
	}
};

void AddSC_Loot() {
	new NODEJS_Loot();
}
