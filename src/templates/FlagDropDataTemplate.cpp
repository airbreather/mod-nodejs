#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using FlagDropData = decltype(GameObjectTemplate().flagdrop);
JVAL_CVAL_TMPLS_RO(FlagDropData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<FlagDropData const *>() {
	TypedTemplate<FlagDropData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("FlagDropData"));

	reg_prop_ro(ft, "lockId", [](FlagDropData const * d) {
		return d->lockId;
	});
	reg_prop_ro(ft, "eventId", [](FlagDropData const * d) {
		return d->eventID;
	});
	reg_prop_ro(ft, "pickupSpell", [](FlagDropData const * d) {
		return d->pickupSpell;
	});
	reg_prop_ro(ft, "noDamageImmune", [](FlagDropData const * d) {
		return d->noDamageImmune != 0;
	});
	reg_prop_ro(ft, "openTextId", [](FlagDropData const * d) {
		return d->openTextID;
	});

	return ft;
}
