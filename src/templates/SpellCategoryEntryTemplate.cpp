#include "CtoJ.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(SpellCategoryEntry const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<SpellCategoryEntry const *>() {
	TypedTemplate<SpellCategoryEntry const *> const ft = jctor();

	ft->SetClassName(jstr_intern("SpellCategoryEntry"));

	reg_static_method(ft, "byId", [](uint32_t id) {
		return sSpellCategoryStore.LookupEntry(id);
	});

	reg_prop_ro(ft, "id", [](SpellCategoryEntry const * c) {
		return c->Id;
	});
	reg_prop_ro(ft, "flags", [](SpellCategoryEntry const * c) {
		return c->Flags;
	});

	return ft;
}
