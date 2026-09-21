#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using FlagStandData = decltype(GameObjectTemplate().flagstand);
JVAL_CVAL_TMPLS_RO(FlagStandData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<FlagStandData const *>() {
	TypedTemplate<FlagStandData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("FlagStandData"));

	reg_prop_ro(ft, "lockId", [](FlagStandData const * s) {
		return s->lockId;
	});
	reg_prop_ro(ft, "pickupSpell", [](FlagStandData const * s) {
		return s->pickupSpell;
	});
	reg_prop_ro(ft, "radius", [](FlagStandData const * s) {
		return s->radius;
	});
	reg_prop_ro(ft, "returnAura", [](FlagStandData const * s) {
		return s->returnAura;
	});
	reg_prop_ro(ft, "returnSpell", [](FlagStandData const * s) {
		return s->returnSpell;
	});
	reg_prop_ro(ft, "noDamageImmune", [](FlagStandData const * s) {
		return s->noDamageImmune != 0;
	});
	reg_prop_ro(ft, "openTextId", [](FlagStandData const * s) {
		return s->openTextID;
	});
	reg_prop_ro(ft, "losOk", [](FlagStandData const * s) {
		return s->losOK != 0;
	});

	return ft;
}
