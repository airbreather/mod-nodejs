#include "CtoJ.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(CharTitlesEntry const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<CharTitlesEntry const *>() {
	TypedTemplate<CharTitlesEntry const *> const ft = jctor();

	ft->SetClassName(jstr_intern("CharTitlesEntry"));

	reg_static_method(ft, "byId", [](uint32_t id) {
		return sCharTitlesStore.LookupEntry(id);
	});

	reg_prop_ro(ft, "id", [](CharTitlesEntry const * t) {
		return t->ID;
	});
	reg_prop_ro(ft, "nameMale", [](CharTitlesEntry const * t) {
		return jarr(t->nameMale);
	});
	reg_prop_ro(ft, "nameFemale", [](CharTitlesEntry const * t) {
		return jarr(t->nameFemale);
	});
	reg_prop_ro(ft, "bitIndex", [](CharTitlesEntry const * t) {
		return t->bit_index;
	});

	return ft;
}
