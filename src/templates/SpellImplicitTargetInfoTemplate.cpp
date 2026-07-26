#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "Spells/SpellInfo.h"

JVAL_CVAL_TMPLS_RO(SpellImplicitTargetInfo const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<SpellImplicitTargetInfo const *>() {
	TypedTemplate<SpellImplicitTargetInfo const *> const ft = jctor();

	ft->SetClassName(jstr_intern("SpellImplicitTargetInfo"));

	reg_prop_ro(ft, "isArea", [](SpellImplicitTargetInfo const * ti) {
		return ti->IsArea();
	});
	reg_prop_ro(ft, "selectionCategory", [](SpellImplicitTargetInfo const * ti) {
		return ti->GetSelectionCategory();
	});
	reg_prop_ro(ft, "referenceType", [](SpellImplicitTargetInfo const * ti) {
		return ti->GetReferenceType();
	});
	reg_prop_ro(ft, "objectType", [](SpellImplicitTargetInfo const * ti) {
		return ti->GetObjectType();
	});
	reg_prop_ro(ft, "checkType", [](SpellImplicitTargetInfo const * ti) {
		return ti->GetCheckType();
	});
	reg_prop_ro(ft, "directionType", [](SpellImplicitTargetInfo const * ti) {
		return ti->GetDirectionType();
	});
	reg_prop_ro(ft, "calcDirectionAngle", [](SpellImplicitTargetInfo const * ti) {
		return ti->CalcDirectionAngle();
	});
	reg_prop_ro(ft, "target", [](SpellImplicitTargetInfo const * ti) {
		return ti->GetTarget();
	});

	reg_method(ft, "getExplicitTargetMask", [](SpellImplicitTargetInfo const * ti, bool src_set, bool dst_set) {
		auto const mask = ti->GetExplicitTargetMask(src_set, dst_set);
		return jobj(
			jprop("mask", mask),
			jprop("srcSet", src_set),
			jprop("dstSet", dst_set)
		);
	});

	return ft;
}
