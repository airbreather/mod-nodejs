#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "TemporarySummon.h"

JVAL_CVAL_TMPLS_RW(Guardian)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Guardian *>() {
	TypedTemplate<Guardian *> const ft = jctor();

	ft->SetClassName(jstr_intern("Guardian"));
	ft.safe_inherit<Minion *>();

	return ft;
}
