#include "CtoJ.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(GemPropertiesEntry const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<GemPropertiesEntry const *>() {
	TypedTemplate<GemPropertiesEntry const *> const ft = jctor();

	ft->SetClassName(jstr_intern("GemPropertiesEntry"));

	reg_static_method(ft, "byId", [](uint32_t id) {
		return sGemPropertiesStore.LookupEntry(id);
	});

	reg_prop_ro(ft, "id", [](GemPropertiesEntry const * g) {
		return g->ID;
	});
	reg_prop_ro(ft, "spellItemEnchantment", [](GemPropertiesEntry const * g) {
		return g->spellitemenchantement;
	});
	reg_prop_ro(ft, "color", [](GemPropertiesEntry const * g) {
		return g->color;
	});

	return ft;
}
