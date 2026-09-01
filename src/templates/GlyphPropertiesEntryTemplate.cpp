#include "CtoJ.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(GlyphPropertiesEntry const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<GlyphPropertiesEntry const *>() {
	TypedTemplate<GlyphPropertiesEntry const *> const ft = jctor();

	ft->SetClassName(jstr_intern("GlyphPropertiesEntry"));

	reg_static_method(ft, "byId", [](uint32_t id) {
		return sGlyphPropertiesStore.LookupEntry(id);
	});

	reg_prop_ro(ft, "id", [](GlyphPropertiesEntry const * g) {
		return g->Id;
	});
	reg_prop_ro(ft, "spellId", [](GlyphPropertiesEntry const * g) {
		return g->SpellId;
	});
	reg_prop_ro(ft, "typeFlags", [](GlyphPropertiesEntry const * g) {
		return g->TypeFlags;
	});

	return ft;
}
