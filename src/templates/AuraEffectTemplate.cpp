#include <list>
#include <optional>
#include <v8-function-callback.h>
#include <v8-isolate.h>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "JtoC.h"
#include "NodePropertySystem.h"
#include "ObjectGuid.h"
#include "SpellAuraEffects.h"

JVAL_CVAL_TMPLS_RW(AuraEffect)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<AuraEffect *>() {
	TypedTemplate<AuraEffect *> const ft = jctor();

	ft->SetClassName(jstr_intern("AuraEffect"));

	reg_prop_ro(ft, "caster", [](AuraEffect * eff) {
		return eff->GetCaster();
	});
	reg_prop_ro(ft, "casterGuid", [](AuraEffect * eff) {
		return eff->GetCasterGUID();
	});
	reg_prop_ro(ft, "base", [](AuraEffect * eff) {
		return eff->GetBase();
	});
	reg_prop_ro(ft, "targetList", [](AuraEffect * eff) {
		std::list<Unit *> list;
		eff->GetTargetList(list);
		return jarr(list);
	});
	reg_prop_ro(ft, "applicationList", [](AuraEffect * eff) {
		std::list<AuraApplication *> list;
		eff->GetApplicationList(list);
		return jarr(list);
	});
	reg_prop_ro(ft, "spellModifier", [](AuraEffect * eff) {
		return (SpellModifier const *){eff->GetSpellModifier()};
	});
	reg_prop_ro(ft, "spellInfo", [](AuraEffect * eff) {
		return eff->GetSpellInfo();
	});
	reg_prop_ro(ft, "id", [](AuraEffect * eff) {
		return eff->GetId();
	});
	reg_prop_ro(ft, "effIndex", [](AuraEffect * eff) {
		return eff->GetEffIndex();
	});
	reg_prop_ro(ft, "baseAmount", [](AuraEffect * eff) {
		return eff->GetBaseAmount();
	});
	reg_prop_ro(ft, "dieSides", [](AuraEffect * eff) {
		return eff->GetDieSides();
	});
	reg_prop_ro(ft, "amplitude", [](AuraEffect * eff) {
		return eff->GetAmplitude();
	});
	reg_prop_ro(ft, "miscValue", [](AuraEffect * eff) {
		return eff->GetMiscValue();
	});
	reg_prop_ro(ft, "miscValueB", [](AuraEffect * eff) {
		return eff->GetMiscValueB();
	});
	reg_prop_ro(ft, "auraType", [](AuraEffect * eff) {
		return eff->GetAuraType();
	});
	reg_prop_ro(ft, "forcedAmount", [](AuraEffect * eff) {
		return eff->GetForcedAmount();
	});
	reg_prop_ro(ft, "tickNumber", [](AuraEffect * eff) {
		return eff->GetTickNumber();
	});
	reg_prop_ro(ft, "totalTicks", [](AuraEffect * eff) {
		return eff->GetTotalTicks();
	});
	reg_prop_ro(ft, "hasSpellClassMask", [](AuraEffect * eff) {
		return eff->HasSpellClassMask();
	});
	reg_prop_ro(ft, "casterLevel", [](AuraEffect * eff) {
		return eff->GetCasterLevel();
	});
	reg_prop_ro(ft, "canApplyResilience", [](AuraEffect * eff) {
		return eff->CanApplyResilience();
	});

	reg_prop(ft, "amount",
		[](AuraEffect * eff) { return eff->GetAmount(); },
		[](AuraEffect * eff, int32_t const amount) { eff->SetAmount(amount); }
	);
	reg_prop(ft, "periodicTimer",
		[](AuraEffect * eff) { return eff->GetPeriodicTimer(); },
		[](AuraEffect * eff, int32_t const periodic_timer) { eff->SetPeriodicTimer(periodic_timer); }
	);
	reg_prop(ft, "canBeRecalculated",
		[](AuraEffect * eff) { return eff->CanBeRecalculated(); },
		[](AuraEffect * eff, bool const can_be_recalculated) { eff->SetCanBeRecalculated(can_be_recalculated); }
	);
	reg_prop(ft, "isPeriodic",
		[](AuraEffect * eff) { return eff->IsPeriodic(); },
		[](AuraEffect * eff, bool const is_periodic) { eff->SetPeriodic(is_periodic); }
	);
	reg_prop(ft, "critChance",
		[](AuraEffect * eff) { return eff->GetCritChance(); },
		[](AuraEffect * eff, float const crit_chance) { eff->SetCritChance(crit_chance); }
	);
	reg_prop(ft, "pctMods",
		[](AuraEffect * eff) { return eff->GetPctMods(); },
		[](AuraEffect * eff, float const pct_mods) { eff->SetPctMods(pct_mods); }
	);
	reg_prop(ft, "oldAmount",
		[](AuraEffect * eff) { return eff->GetOldAmount(); },
		[](AuraEffect * eff, int32_t const old_amount) { eff->SetOldAmount(old_amount); }
	);
	reg_prop(ft, "isEnabled",
		[](AuraEffect * eff) { return eff->GetEnabled(); },
		[](AuraEffect * eff, bool const enabled) { eff->SetEnabled(enabled); }
	);

	reg_method(ft, "calculatePeriodic", [](AuraEffect * eff, Unit * caster, std::optional<bool> const create, std::optional<bool> const load) {
		eff->CalculatePeriodic(caster, create.value_or(false), load.value_or(false));
	});
	reg_method(ft, "calculatePeriodicData", [](AuraEffect * eff) {
		eff->CalculatePeriodicData();
	});
	reg_method(ft, "calculateSpellMod", [](AuraEffect * eff) {
		eff->CalculateSpellMod();
	});
	reg_method(ft, "changeAmount", [](AuraEffect * eff, int32_t const new_amount, std::optional<bool> const mark, std::optional<bool> const on_stack_or_reapply) {
		eff->ChangeAmount(new_amount, mark.value_or(true), on_stack_or_reapply.value_or(false));
	});
	reg_method(ft, "recalculateAmount", [](AuraEffect * eff, std::optional<Unit *> const caster) {
		return caster
			? eff->RecalculateAmount(*caster)
			: eff->RecalculateAmount();
	});
	reg_method_raw(ft, "handleEffect", [](AuraEffect * eff, v8::FunctionCallbackInfo<v8::Value> const & args) {
		if (args.Length() < 3) {
			args.GetIsolate()->ThrowError(jstr_intern("Too few arguments (need 3)."));
			return;
		}
		auto failed = false;
		auto const mode = carg<uint8_t, 1>(args, failed);
		auto const apply = carg<uint8_t, 2>(args, failed);
		if (failed) {
			// it threw already
			return;
		}
		if (jtemplate<AuraApplication *>()->HasInstance(args[0])) {
			eff->HandleEffect(*cval<AuraApplication *>(args[0]), mode, apply);
		} else if (jtemplate<Unit *>()->HasInstance(args[0])) {
			eff->HandleEffect(*cval<Unit *>(args[0]), mode, apply);
		} else {
			args.GetIsolate()->ThrowError(jstr_intern("First arg must be either AuraApplication or Unit"));
		}
	});

	return ft;
}
