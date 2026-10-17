#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using AuraGeneratorData = decltype(GameObjectTemplate().auraGenerator);
JVAL_CVAL_TMPLS_RO(AuraGeneratorData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<AuraGeneratorData const *>() {
	TypedTemplate<AuraGeneratorData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("AuraGeneratorData"));

	reg_prop_ro(ft, "startOpen", [](AuraGeneratorData const * g) {
		return g->startOpen != 0;
	});
	reg_prop_ro(ft, "radius", [](AuraGeneratorData const * g) {
		return g->radius;
	});
	reg_prop_ro(ft, "auraId1", [](AuraGeneratorData const * g) {
		return g->auraID1;
	});
	reg_prop_ro(ft, "conditionId1", [](AuraGeneratorData const * g) {
		return g->conditionID1;
	});
	reg_prop_ro(ft, "auraId2", [](AuraGeneratorData const * g) {
		return g->auraID2;
	});
	reg_prop_ro(ft, "conditionId2", [](AuraGeneratorData const * g) {
		return g->conditionID2;
	});
	reg_prop_ro(ft, "serverOnly", [](AuraGeneratorData const * g) {
		// observed values: -1, 0
		return g->serverOnly;
	});

	return ft;
}
