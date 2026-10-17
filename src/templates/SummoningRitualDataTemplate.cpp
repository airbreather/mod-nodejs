#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using SummoningRitualData = decltype(GameObjectTemplate().summoningRitual);
JVAL_CVAL_TMPLS_RO(SummoningRitualData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<SummoningRitualData const *>() {
	TypedTemplate<SummoningRitualData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("SummoningRitualData"));

	reg_prop_ro(ft, "reqParticipants", [](SummoningRitualData const * r) {
		return r->reqParticipants;
	});
	reg_prop_ro(ft, "spellId", [](SummoningRitualData const * r) {
		return r->spellId;
	});
	reg_prop_ro(ft, "animSpell", [](SummoningRitualData const * r) {
		return r->animSpell;
	});
	reg_prop_ro(ft, "ritualPersistent", [](SummoningRitualData const * r) {
		return r->ritualPersistent != 0;
	});
	reg_prop_ro(ft, "casterTargetSpell", [](SummoningRitualData const * r) {
		return r->casterTargetSpell;
	});
	reg_prop_ro(ft, "casterTargetSpellTargets", [](SummoningRitualData const * r) {
		return r->casterTargetSpellTargets;
	});
	reg_prop_ro(ft, "castersGrouped", [](SummoningRitualData const * r) {
		return r->castersGrouped != 0;
	});
	reg_prop_ro(ft, "ritualNoTargetCheck", [](SummoningRitualData const * r) {
		return r->ritualNoTargetCheck != 0;
	});

	return ft;
}
