#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using GuardPostData = decltype(GameObjectTemplate().guardpost);
JVAL_CVAL_TMPLS_RO(GuardPostData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<GuardPostData const *>() {
	TypedTemplate<GuardPostData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("GuardPostData"));

	reg_prop_ro(ft, "creatureId", [](GuardPostData const * p) {
		return p->creatureID;
	});
	reg_prop_ro(ft, "charges", [](GuardPostData const * p) {
		return p->charges;
	});

	return ft;
}
