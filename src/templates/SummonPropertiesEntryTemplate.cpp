#include "CtoJ.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(SummonPropertiesEntry const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<SummonPropertiesEntry const *>() {
	TypedTemplate<SummonPropertiesEntry const *> const ft = jctor();

	ft->SetClassName(jstr_intern("SummonPropertiesEntry"));

	reg_static_method(ft, "byId", [](uint32_t id) {
		return sSummonPropertiesStore.LookupEntry(id);
	});

	reg_prop_ro(ft, "id", [](SummonPropertiesEntry const * s) {
		return s->Id;
	});
	reg_prop_ro(ft, "category", [](SummonPropertiesEntry const * s) {
		return s->Category;
	});
	reg_prop_ro(ft, "faction", [](SummonPropertiesEntry const * s) {
		return s->Faction;
	});
	reg_prop_ro(ft, "type", [](SummonPropertiesEntry const * s) {
		return s->Type;
	});
	reg_prop_ro(ft, "slot", [](SummonPropertiesEntry const * s) {
		return s->Slot;
	});
	reg_prop_ro(ft, "flags", [](SummonPropertiesEntry const * s) {
		return s->Flags;
	});

	return ft;
}
