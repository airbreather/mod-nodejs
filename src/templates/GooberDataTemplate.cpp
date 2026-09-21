#include "CtoJ.h"
#include "DurationWrapper.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using GooberData = decltype(GameObjectTemplate().goober);
JVAL_CVAL_TMPLS_RO(GooberData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<GooberData const *>() {
	TypedTemplate<GooberData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("GooberData"));

	reg_prop_ro(ft, "lockId", [](GooberData const * g) {
		return g->lockId;
	});
	reg_prop_ro(ft, "questId", [](GooberData const * g) {
		return g->questId;
	});
	reg_prop_ro(ft, "eventId", [](GooberData const * g) {
		return g->eventId;
	});
	reg_prop_ro(ft, "autoCloseTime", [](GooberData const * g) {
		return DurationWrapper::from_milliseconds(g->autoCloseTime);
	});
	reg_prop_ro(ft, "customAnim", [](GooberData const * g) {
		return g->customAnim != 0;
	});
	reg_prop_ro(ft, "consumable", [](GooberData const * g) {
		return g->consumable != 0;
	});
	reg_prop_ro(ft, "cooldown", [](GooberData const * g) {
		return DurationWrapper::from_chrono(Seconds(g->cooldown));
	});
	reg_prop_ro(ft, "pageId", [](GooberData const * g) {
		return g->pageId;
	});
	reg_prop_ro(ft, "language", [](GooberData const * g) {
		return g->language;
	});
	reg_prop_ro(ft, "pageMaterial", [](GooberData const * g) {
		return g->pageMaterial;
	});
	reg_prop_ro(ft, "spellId", [](GooberData const * g) {
		return g->spellId;
	});
	reg_prop_ro(ft, "noDamageImmune", [](GooberData const * g) {
		return g->noDamageImmune != 0;
	});
	reg_prop_ro(ft, "linkedTrapId", [](GooberData const * g) {
		return g->linkedTrapId;
	});
	reg_prop_ro(ft, "large", [](GooberData const * g) {
		return g->large != 0;
	});
	reg_prop_ro(ft, "openTextId", [](GooberData const * g) {
		return g->openTextID;
	});
	reg_prop_ro(ft, "closeTextId", [](GooberData const * g) {
		return g->closeTextID;
	});
	reg_prop_ro(ft, "losOk", [](GooberData const * g) {
		return g->losOK != 0;
	});
	reg_prop_ro(ft, "allowMounted", [](GooberData const * g) {
		return g->allowMounted != 0;
	});
	reg_prop_ro(ft, "floatingTooltip", [](GooberData const * g) {
		return g->floatingTooltip != 0;
	});
	reg_prop_ro(ft, "gossipId", [](GooberData const * g) {
		return g->gossipID;
	});
	reg_prop_ro(ft, "worldStateSetsState", [](GooberData const * g) {
		return g->WorldStateSetsState != 0;
	});

	return ft;
}
