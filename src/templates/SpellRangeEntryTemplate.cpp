#include "CtoJ.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(SpellRangeEntry const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<SpellRangeEntry const *>() {
	TypedTemplate<SpellRangeEntry const *> const ft = jctor();

	ft->SetClassName(jstr_intern("SpellRangeEntry"));

	reg_static_method(ft, "byId", [](uint32_t id) {
		return sSpellRangeStore.LookupEntry(id);
	});

	reg_prop_ro(ft, "id", [](SpellRangeEntry const * r) {
		return r->ID;
	});
	reg_prop_ro(ft, "minHostile", [](SpellRangeEntry const * r) {
		return r->RangeMin[0];
	});
	reg_prop_ro(ft, "minFriendly", [](SpellRangeEntry const * r) {
		return r->RangeMin[1];
	});
	reg_prop_ro(ft, "maxHostile", [](SpellRangeEntry const * r) {
		return r->RangeMax[0];
	});
	reg_prop_ro(ft, "maxFriendly", [](SpellRangeEntry const * r) {
		return r->RangeMax[1];
	});
	reg_prop_ro(ft, "flags", [](SpellRangeEntry const * r) {
		return r->Flags;
	});

	return ft;
}
