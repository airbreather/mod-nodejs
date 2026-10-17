#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using TrapDoorData = decltype(GameObjectTemplate().trapDoor);
JVAL_CVAL_TMPLS_RO(TrapDoorData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<TrapDoorData const *>() {
	TypedTemplate<TrapDoorData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("TrapDoorData"));

	reg_prop_ro(ft, "whenToPause", [](TrapDoorData const * t) {
		return t->whenToPause;
	});
	reg_prop_ro(ft, "startOpen", [](TrapDoorData const * t) {
		return t->startOpen != 0;
	});
	reg_prop_ro(ft, "autoClose", [](TrapDoorData const * t) {
		return t->autoClose != 0;
	});

	return ft;
}
