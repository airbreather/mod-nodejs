#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using GenericData = decltype(GameObjectTemplate()._generic);
JVAL_CVAL_TMPLS_RO(GenericData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<GenericData const *>() {
	TypedTemplate<GenericData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("GenericData"));

	reg_prop_ro(ft, "floatingTooltip", [](GenericData const * g) {
		// unused in core. values observed are 0, 1, 2, 5, 256, 65536
		return g->floatingTooltip;
	});
	reg_prop_ro(ft, "highlight", [](GenericData const * g) {
		// unused in core. values observed are 0, 1, 256, 65536
		return g->highlight;
	});
	reg_prop_ro(ft, "serverOnly", [](GenericData const * g) {
		// unused in core. values observed are 0, 1, 196608
		return g->serverOnly;
	});
	reg_prop_ro(ft, "large", [](GenericData const * g) {
		// values observed are 0, 1, 10000, 177749, 196608
		return g->large;
	});
	reg_prop_ro(ft, "floatOnWater", [](GenericData const * g) {
		return g->floatOnWater != 0;
	});
	reg_prop_ro(ft, "questId", [](GenericData const * g) {
		return g->questID;
	});

	return ft;
}
