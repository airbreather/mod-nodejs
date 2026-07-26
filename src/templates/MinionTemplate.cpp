#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "TemporarySummon.h"

JVAL_CVAL_TMPLS_RW(Minion)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Minion *>() {
	TypedTemplate<Minion *> const ft = jctor();

	ft->SetClassName(jstr_intern("Minion"));
 	ft.safe_inherit<TempSummon *>();

	reg_prop_ro(ft, "owner", [](Minion * m) {
		// ...why does Pet shadow Minion's perfectly usable GetOwner()?
		// ...why does Minion shadow Unit's perfectly usable GetOwner()?
		return m->GetOwner();
	});
	reg_prop_ro(ft, "isPetGhoul", [](Minion * m) {
		return m->IsPetGhoul();
	});
	reg_prop_ro(ft, "isGuardianPet", [](Minion * m) {
		return m->IsGuardianPet();
	});

	reg_prop(ft, "followAngle",
		[](Minion * m) { return m->GetFollowAngle(); },
		[](Minion * m, auto a) { m->SetFollowAngle(a); }
	);

	return ft;
}
