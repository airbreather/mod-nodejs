#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "LootMgr.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(LootTemplate const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<LootTemplate const *>() {
	TypedTemplate<LootTemplate const *> const ft = jctor();

	ft->SetClassName(jstr_intern("LootTemplate"));

	reg_method(ft, "process", [](LootTemplate const * lt, Loot * loot, LootStore const * store, uint16_t const loot_mode, Player * player, std::optional<uint8_t> const group_id, std::optional<bool> const is_top_level) {
		lt->Process(*loot, *store,loot_mode, player, group_id.value_or(0), is_top_level.value_or(true));
	});

	return ft;
}
