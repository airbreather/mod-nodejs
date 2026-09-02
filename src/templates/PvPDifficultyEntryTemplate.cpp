#include "CtoJ.h"
#include "DBCStructure.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(PvPDifficultyEntry const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<PvPDifficultyEntry const *>() {
	TypedTemplate<PvPDifficultyEntry const *> const ft = jctor();

	ft->SetClassName(jstr_intern("PvPDifficultyEntry"));

	reg_prop_ro(ft, "mapId", [](PvPDifficultyEntry const * p) {
		return p->mapId;
	});
	reg_prop_ro(ft, "bracketId", [](PvPDifficultyEntry const * p) {
		return p->bracketId;
	});
	reg_prop_ro(ft, "minLevel", [](PvPDifficultyEntry const * p) {
		return p->minLevel;
	});
	reg_prop_ro(ft, "maxLevel", [](PvPDifficultyEntry const * p) {
		return p->maxLevel;
	});
	reg_prop_ro(ft, "difficulty", [](PvPDifficultyEntry const * p) {
		return p->difficulty;
	});

	return ft;
}
