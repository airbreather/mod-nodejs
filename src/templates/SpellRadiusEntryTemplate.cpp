#include "CtoJ.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(SpellRadiusEntry const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<SpellRadiusEntry const *>() {
	TypedTemplate<SpellRadiusEntry const *> const ft = jctor();

	ft->SetClassName(jstr_intern("SpellRadiusEntry"));

	reg_static_method(ft, "byId", [](uint32_t id) {
		return sSpellRadiusStore.LookupEntry(id);
	});

	reg_prop_ro(ft, "id", [](SpellRadiusEntry const * r) {
		return r->ID;
	});
	reg_prop_ro(ft, "radiusMin", [](SpellRadiusEntry const * r) {
		return r->RadiusMin;
	});
	reg_prop_ro(ft, "radiusPerLevel", [](SpellRadiusEntry const * r) {
		return r->RadiusPerLevel;
	});
	reg_prop_ro(ft, "radiusMax", [](SpellRadiusEntry const * r) {
		return r->RadiusMax;
	});

	return ft;
}
