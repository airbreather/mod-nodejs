#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using ChairData = decltype(GameObjectTemplate().chair);
JVAL_CVAL_TMPLS_RO(ChairData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<ChairData const *>() {
	TypedTemplate<ChairData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("ChairData"));

	reg_prop_ro(ft, "slots", [](ChairData const * c) {
		return c->slots;
	});
	reg_prop_ro(ft, "height", [](ChairData const * c) {
		return c->height;
	});
	reg_prop_ro(ft, "onlyCreatorUse", [](ChairData const * c) {
		return c->onlyCreatorUse != 0;
	});
	reg_prop_ro(ft, "triggeredEvent", [](ChairData const * c) {
		return c->triggeredEvent;
	});

	return ft;
}
