#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using BarberChairData = decltype(GameObjectTemplate().barberChair);
JVAL_CVAL_TMPLS_RO(BarberChairData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<BarberChairData const *>() {
	TypedTemplate<BarberChairData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("BarberChairData"));

	reg_prop_ro(ft, "chairHeight", [](BarberChairData const * c) {
		return c->chairheight;
	});
	reg_prop_ro(ft, "heightOffset", [](BarberChairData const * c) {
		return c->heightOffset;
	});

	return ft;
}
