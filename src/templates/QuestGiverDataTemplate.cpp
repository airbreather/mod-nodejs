#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using QuestGiverData = decltype(GameObjectTemplate().questgiver);
JVAL_CVAL_TMPLS_RO(QuestGiverData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<QuestGiverData const *>() {
	TypedTemplate<QuestGiverData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("QuestGiverData"));

	reg_prop_ro(ft, "lockId", [](QuestGiverData const * q) {
		return q->lockId;
	});
	reg_prop_ro(ft, "questList", [](QuestGiverData const * q) {
		return q->questList;
	});
	reg_prop_ro(ft, "pageMaterial", [](QuestGiverData const * q) {
		return q->pageMaterial;
	});
	reg_prop_ro(ft, "gossipId", [](QuestGiverData const * q) {
		return q->gossipID;
	});
	reg_prop_ro(ft, "customAnim", [](QuestGiverData const * q) {
		return q->customAnim;
	});
	reg_prop_ro(ft, "noDamageImmune", [](QuestGiverData const * q) {
		return q->noDamageImmune != 0;
	});
	reg_prop_ro(ft, "openTextId", [](QuestGiverData const * q) {
		return q->openTextID;
	});
	reg_prop_ro(ft, "losOk", [](QuestGiverData const * q) {
		return q->losOK != 0;
	});
	reg_prop_ro(ft, "allowMounted", [](QuestGiverData const * q) {
		return q->allowMounted != 0;
	});
	reg_prop_ro(ft, "large", [](QuestGiverData const * q) {
		return q->large != 0;
	});

	return ft;
}
