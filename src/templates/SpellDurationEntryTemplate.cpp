#include "CtoJ.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "DurationWrapper.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(SpellDurationEntry const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<SpellDurationEntry const *>() {
	TypedTemplate<SpellDurationEntry const *> const ft = jctor();

	ft->SetClassName(jstr_intern("SpellDurationEntry"));

	reg_static_method(ft, "byId", [](uint32_t id) {
		return sSpellDurationStore.LookupEntry(id);
	});

	reg_prop_ro(ft, "id", [](SpellDurationEntry const * d) {
		return d->ID;
	});
	reg_prop_ro(ft, "duration0", [](SpellDurationEntry const * d) {
		return DurationWrapper::from_milliseconds(d->Duration[0]);
	});
	reg_prop_ro(ft, "duration1", [](SpellDurationEntry const * d) {
		return DurationWrapper::from_milliseconds(d->Duration[1]);
	});
	reg_prop_ro(ft, "duration2", [](SpellDurationEntry const * d) {
		return DurationWrapper::from_milliseconds(d->Duration[2]);
	});

	return ft;
}
