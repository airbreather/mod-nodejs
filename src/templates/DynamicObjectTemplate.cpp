#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "DynamicObject.h"
#include "NodePropertySystem.h"
#include "Object.h"
#include "ObjectGuid.h"

JVAL_CVAL_TMPLS_RW(DynamicObject)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<DynamicObject *>() {
	TypedTemplate<DynamicObject *> const ft = jctor();

	ft->SetClassName(jstr_intern("DynamicObject"));
	ft.safe_inherit<WorldObject *>();

	reg_prop_ro(ft, "caster", [](DynamicObject * dyno) {
		return dyno->GetCaster();
	});
	reg_prop_ro(ft, "spellId", [](DynamicObject * dyno) {
		return dyno->GetSpellId();
	});
	reg_prop_ro(ft, "casterGuid", [](DynamicObject * dyno) {
		return dyno->GetCasterGUID();
	});
	reg_prop_ro(ft, "radius", [](DynamicObject * dyno) {
		return dyno->GetRadius();
	});
	reg_prop_ro(ft, "isViewpoint", [](DynamicObject * dyno) {
		return dyno->IsViewpoint();
	});
	reg_prop_ro(ft, "oldFarsightGuid", [](DynamicObject * dyno) {
		return dyno->GetOldFarsightGUID();
	});

	reg_prop(ft, "duration",
		[](DynamicObject * dyno) { return dyno->GetDuration(); },
		[](DynamicObject * dyno, int32_t const duration) { dyno->SetDuration(duration); }
	);

	reg_method(ft, "remove", [](DynamicObject * dyno) {
		dyno->Remove();
	});
	reg_method(ft, "delay", [](DynamicObject * dyno, int32_t const delay_time) {
		dyno->Delay(delay_time);
	});
	reg_method(ft, "setAura", [](DynamicObject * dyno, Aura * aura) {
		dyno->SetAura(aura);
	});
	reg_method(ft, "removeAura", [](DynamicObject * dyno) {
		dyno->RemoveAura();
	});
	reg_method(ft, "setCasterViewpoint", [](DynamicObject * dyno, bool const update_viewer_visibility) {
		dyno->SetCasterViewpoint(update_viewer_visibility);
	});
	reg_method(ft, "removeCasterViewpoint", [](DynamicObject * dyno) {
		dyno->RemoveCasterViewpoint();
	});
	reg_method(ft, "bindToCaster", [](DynamicObject * dyno) {
		dyno->BindToCaster();
	});
	reg_method(ft, "unbindFromCaster", [](DynamicObject * dyno) {
		dyno->UnbindFromCaster();
	});

	return ft;
}
