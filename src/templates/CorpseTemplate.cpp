#include <v8-local-handle.h>
#include <v8-template.h>

#include "Corpse.h"
#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "ObjectGuid.h"

JVAL_CVAL_TMPLS_RW(Corpse)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Corpse *>() {
	TypedTemplate<Corpse *> const ft = jctor();

	ft->SetClassName(jstr_intern("Corpse"));
	ft.safe_inherit<WorldObject *>();

	reg_prop_ro(ft, "ghostTime", [](Corpse * corpse) {
		return UnixTimestamp{corpse->GetGhostTime()};
	});
	reg_prop_ro(ft, "type", [](Corpse * corpse) {
		return corpse->GetType();
	});
	reg_prop_ro(ft, "owner", [](Corpse * corpse) {
		return ObjectAccessor::FindPlayer(corpse->GetOwnerGUID());
	});
	reg_prop_ro(ft, "ownerGuid", [](Corpse * corpse) {
		return corpse->GetOwnerGUID();
	});

	reg_method(ft, "resetGhostTime", [](Corpse * corpse) {
		corpse->ResetGhostTime();
	});
	reg_method(ft, "saveToDB", [](Corpse * corpse) {
		corpse->SaveToDB();
	});

	return ft;
}
