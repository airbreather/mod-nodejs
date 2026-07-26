#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "SpellAuras.h"

JVAL_CVAL_TMPLS_RW(AuraApplication)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<AuraApplication *>() {
	TypedTemplate<AuraApplication *> const ft = jctor();

	ft->SetClassName(jstr_intern("AuraApplication"));

	reg_prop_ro(ft, "target", [](AuraApplication * app) {
		return app->GetTarget();
	});
	reg_prop_ro(ft, "base", [](AuraApplication * app) {
		return app->GetBase();
	});
	reg_prop_ro(ft, "slot", [](AuraApplication * app) {
		return app->GetSlot();
	});
	reg_prop_ro(ft, "flags", [](AuraApplication * app) {
		return app->GetFlags();
	});
	reg_prop_ro(ft, "effectMask", [](AuraApplication * app) {
		return app->GetEffectMask();
	});
	reg_prop_ro(ft, "isPositive", [](AuraApplication * app) {
		return app->IsPositive();
	});
	reg_prop_ro(ft, "isSelfcasted", [](AuraApplication * app) {
		return app->IsSelfcasted();
	});
	reg_prop_ro(ft, "effectsToApply", [](AuraApplication * app) {
		return app->GetEffectsToApply();
	});

	reg_method(ft, "hasEffect", [](AuraApplication * app, uint8_t const effect) {
		return app->HasEffect(effect);
	});
	reg_method(ft, "isActive", [](AuraApplication * app, uint8_t const effect_index) {
		return app->IsActive(effect_index);
	});

	reg_prop(ft, "removeMode",
		[](AuraApplication * app) { return app->GetRemoveMode(); },
		[](AuraApplication * app, AuraRemoveMode const mode) { app->SetRemoveMode(mode); }
	);

	reg_method(ft, "setDisableMask", [](AuraApplication * app, uint8_t const effect_index) {
		app->SetDisableMask(effect_index);
	});
	reg_method(ft, "removeDisableMask", [](AuraApplication * app, uint8_t const effect_index) {
		app->RemoveDisableMask(effect_index);
	});

	return ft;
}
