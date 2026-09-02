#include "CtoJ.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "DurationWrapper.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(SpellCastTimesEntry const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<SpellCastTimesEntry const *>() {
	TypedTemplate<SpellCastTimesEntry const *> const ft = jctor();

	ft->SetClassName(jstr_intern("SpellCastTimesEntry"));

	reg_static_method(ft, "byId", [](uint32_t id) {
		return sSpellCastTimesStore.LookupEntry(id);
	});

	reg_prop_ro(ft, "id", [](SpellCastTimesEntry const * c) {
		return c->ID;
	});
	reg_prop_ro(ft, "castTime", [](SpellCastTimesEntry const * c) {
		return DurationWrapper::from_milliseconds(c->CastTime);
	});

	return ft;
}
