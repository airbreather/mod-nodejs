#include "CtoJ.h"
#include "DurationWrapper.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using ChestData = decltype(GameObjectTemplate().chest);
JVAL_CVAL_TMPLS_RO(ChestData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<ChestData const *>() {
	TypedTemplate<ChestData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("ChestData"));

	reg_prop_ro(ft, "lockId", [](ChestData const * c) {
		return c->lockId;
	});
	reg_prop_ro(ft, "lootId", [](ChestData const * c) {
		return c->lootId;
	});
	reg_prop_ro(ft, "chestRestockTime", [](ChestData const * c) {
		return DurationWrapper::from_chrono(Seconds(c->chestRestockTime));
	});
	reg_prop_ro(ft, "consumable", [](ChestData const * c) {
		return c->consumable != 0;
	});
	reg_prop_ro(ft, "minSuccessOpens", [](ChestData const * c) {
		return c->minSuccessOpens;
	});
	reg_prop_ro(ft, "maxSuccessOpens", [](ChestData const * c) {
		return c->maxSuccessOpens;
	});
	reg_prop_ro(ft, "eventId", [](ChestData const * c) {
		return c->eventId;
	});
	reg_prop_ro(ft, "linkedTrapId", [](ChestData const * c) {
		return c->linkedTrapId;
	});
	reg_prop_ro(ft, "questId", [](ChestData const * c) {
		return c->questId;
	});
	reg_prop_ro(ft, "level", [](ChestData const * c) {
		return c->level;
	});
	reg_prop_ro(ft, "losOk", [](ChestData const * c) {
		return c->losOK != 0;
	});
	reg_prop_ro(ft, "leaveLoot", [](ChestData const * c) {
		return c->leaveLoot != 0;
	});
	reg_prop_ro(ft, "notInCombat", [](ChestData const * c) {
		return c->notInCombat != 0;
	});
	reg_prop_ro(ft, "logLoot", [](ChestData const * c) {
		return c->logLoot != 0;
	});
	reg_prop_ro(ft, "openTextId", [](ChestData const * c) {
		return c->openTextID;
	});
	reg_prop_ro(ft, "groupLootRules", [](ChestData const * c) {
		return c->groupLootRules != 0;
	});
	reg_prop_ro(ft, "floatingTooltip", [](ChestData const * c) {
		return c->floatingTooltip != 0;
	});

	return ft;
}
