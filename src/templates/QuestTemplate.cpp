#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "ObjectMgr.h"
#include "QuestDef.h"

JVAL_CVAL_TMPLS_RO(Quest const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Quest const *>() {
	TypedTemplate<Quest const *> const ft = jctor();

	ft->SetClassName(jstr_intern("Quest"));

	reg_static_method(ft, "byId", [](uint32_t const id) {
		return sObjectMgr->GetQuestTemplate(id);
	});

	reg_prop_ro(ft, "questId", [](Quest const * q) {
		return q->GetQuestId();
	});
	reg_prop_ro(ft, "questType", [](Quest const * q) {
		return q->GetType();
	});
	reg_prop_ro(ft, "level", [](Quest const * q) {
		return q->GetQuestLevel();
	});
	reg_prop_ro(ft, "logTitle", [](Quest const * q) {
		return q->GetTitle();
	});
	reg_prop_ro(ft, "objectiveText", [](Quest const * q) {
		return q->GetDetails();
	});
	reg_prop_ro(ft, "objectiveDescription", [](Quest const * q) {
		return q->GetObjectives();
	});
	reg_prop_ro(ft, "areaDescription", [](Quest const * q) {
		return q->GetAreaDescription();
	});
	reg_prop_ro(ft, "startAreaId", [](Quest const * q) {
		return q->GetZoneOrSort();
	});
	reg_prop_ro(ft, "rewardSpell", [](Quest const * q) {
		return q->GetRewSpellCast();
	});
	reg_prop_ro(ft, "isRepeatable", [](Quest const * q) {
		return q->IsRepeatable();
	});
	reg_prop_ro(ft, "isDaily", [](Quest const * q) {
		return q->IsDaily();
	});
	reg_prop_ro(ft, "isWeekly", [](Quest const * q) {
		return q->IsWeekly();
	});

	return ft;
}
