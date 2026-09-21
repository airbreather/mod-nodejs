#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using SpellFocusData = decltype(GameObjectTemplate().spellFocus);
JVAL_CVAL_TMPLS_RO(SpellFocusData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<SpellFocusData const *>() {
	TypedTemplate<SpellFocusData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("SpellFocusData"));

	reg_prop_ro(ft, "focusId", [](SpellFocusData const * f) {
		return f->focusId;
	});
	reg_prop_ro(ft, "dist", [](SpellFocusData const * f) {
		return f->dist;
	});
	reg_prop_ro(ft, "linkedTrapId", [](SpellFocusData const * f) {
		return f->linkedTrapId;
	});
	reg_prop_ro(ft, "serverOnly", [](SpellFocusData const * f) {
		return f->serverOnly != 0;
	});
	reg_prop_ro(ft, "questId", [](SpellFocusData const * f) {
		return f->questID;
	});
	reg_prop_ro(ft, "large", [](SpellFocusData const * f) {
		return f->large != 0;
	});
	reg_prop_ro(ft, "floatingTooltip", [](SpellFocusData const * f) {
		// observed values -1, 0, 1
		return f->floatingTooltip;
	});

	return ft;
}
