#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>
#include <v8-value.h>

#include "CtoJ.h"
#include "JtoC.h"
#include "LootMgr.h"
#include "NodePropertySystem.h"

JVAL_TMPL_RO(LootStore const)

// cval is implemented differently here.

static LootStore const * ALL_LOOT_STORES[] = {
	&LootTemplates_Creature,
	&LootTemplates_Disenchant,
	&LootTemplates_Fishing,
	&LootTemplates_Gameobject,
	&LootTemplates_Item,
	&LootTemplates_Mail,
	&LootTemplates_Milling,
	&LootTemplates_Pickpocketing,
	&LootTemplates_Prospecting,
	&LootTemplates_Reference,
	&LootTemplates_Skinning,
	&LootTemplates_Spell,
	&LootTemplates_Player,
};

template<>
std::optional<LootStore const *> cval<LootStore const *>(v8::Local<v8::Value> const v) {
	return v->IsNumber()
		? std::optional{ALL_LOOT_STORES[*cval<uint32_t>(v)]}
		: ctemplated_object<LootStore *>(v);
}

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<LootStore const *>() {
	TypedTemplate<LootStore const *> const ft = jctor();

	ft->SetClassName(jstr_intern("LootStore"));

	reg_prop_ro(ft, "name", [](LootStore const * ls) {
		return ls->GetName();
	});
	reg_prop_ro(ft, "entryName", [](LootStore const * ls) {
		return ls->GetEntryName();
	});
	reg_prop_ro(ft, "ratesAllowed", [](LootStore const * ls) {
		return ls->IsRatesAllowed();
	});

	reg_method(ft, "haveLootFor", [](LootStore const * ls, uint32_t const loot_id) {
		return ls->HaveLootFor(loot_id);
	});
	reg_method(ft, "haveQuestLootFor", [](LootStore const * ls, uint32_t const loot_id, std::optional<Player *> const player) {
		return player
			? ls->HaveQuestLootForPlayer(loot_id, *player)
			: ls->HaveQuestLootFor(loot_id);
	});
	reg_method(ft, "getLootFor", [](LootStore const * ls, uint32_t const loot_id) {
		return ls->GetLootFor(loot_id);
	});

	return ft;
}
