#include "CtoJ.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(FactionEntry const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<FactionEntry const *>() {
	TypedTemplate<FactionEntry const *> const ft = jctor();

	ft->SetClassName(jstr_intern("FactionEntry"));

	reg_static_method(ft, "byId", [](uint32_t id) {
		return sFactionStore.LookupEntry(id);
	});

	reg_prop_ro(ft, "id", [](FactionEntry const * f) {
		return f->ID;
	});
	reg_prop_ro(ft, "reputationListId", [](FactionEntry const * f) {
		return f->reputationListID;
	});
	reg_prop_ro(ft, "baseRepRaceMask0", [](FactionEntry const * f) {
		return f->BaseRepRaceMask[0];
	});
	reg_prop_ro(ft, "baseRepRaceMask1", [](FactionEntry const * f) {
		return f->BaseRepRaceMask[1];
	});
	reg_prop_ro(ft, "baseRepRaceMask2", [](FactionEntry const * f) {
		return f->BaseRepRaceMask[2];
	});
	reg_prop_ro(ft, "baseRepRaceMask3", [](FactionEntry const * f) {
		return f->BaseRepRaceMask[3];
	});
	reg_prop_ro(ft, "baseRepClassMask0", [](FactionEntry const * f) {
		return f->BaseRepClassMask[0];
	});
	reg_prop_ro(ft, "baseRepClassMask1", [](FactionEntry const * f) {
		return f->BaseRepClassMask[1];
	});
	reg_prop_ro(ft, "baseRepClassMask2", [](FactionEntry const * f) {
		return f->BaseRepClassMask[2];
	});
	reg_prop_ro(ft, "baseRepClassMask3", [](FactionEntry const * f) {
		return f->BaseRepClassMask[3];
	});
	reg_prop_ro(ft, "baseRepValue0", [](FactionEntry const * f) {
		return f->BaseRepValue[0];
	});
	reg_prop_ro(ft, "baseRepValue1", [](FactionEntry const * f) {
		return f->BaseRepValue[1];
	});
	reg_prop_ro(ft, "baseRepValue2", [](FactionEntry const * f) {
		return f->BaseRepValue[2];
	});
	reg_prop_ro(ft, "baseRepValue3", [](FactionEntry const * f) {
		return f->BaseRepValue[3];
	});
	reg_prop_ro(ft, "reputationFlags0", [](FactionEntry const * f) {
		return f->ReputationFlags[0];
	});
	reg_prop_ro(ft, "reputationFlags1", [](FactionEntry const * f) {
		return f->ReputationFlags[1];
	});
	reg_prop_ro(ft, "reputationFlags2", [](FactionEntry const * f) {
		return f->ReputationFlags[2];
	});
	reg_prop_ro(ft, "reputationFlags3", [](FactionEntry const * f) {
		return f->ReputationFlags[3];
	});
	reg_prop_ro(ft, "team", [](FactionEntry const * f) {
		return f->team;
	});
	reg_prop_ro(ft, "spilloverRateIn", [](FactionEntry const * f) {
		return f->spilloverRateIn;
	});
	reg_prop_ro(ft, "spilloverRateOut", [](FactionEntry const * f) {
		return f->spilloverRateOut;
	});
	reg_prop_ro(ft, "spilloverMaxRankIn", [](FactionEntry const * f) {
		return f->spilloverMaxRankIn;
	});
	reg_prop_ro(ft, "name", [](FactionEntry const * f) {
		return jarr(f->name);
	});
	reg_prop_ro(ft, "canHaveReputation", [](FactionEntry const * f) {
		return f->CanHaveReputation();
	});
	reg_prop_ro(ft, "canBeSetAtWar", [](FactionEntry const * f) {
		return f->CanBeSetAtWar();
	});

	reg_method(ft, "otherFactionsInTeam", [](FactionEntry const * f) {
		if (auto list = GetFactionTeamList(f->team)) {
			return jarr(*list);
		}
		return jnull();
	});

	return ft;
}
