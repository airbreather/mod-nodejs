#include <array>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "DBCStructure.h"
#include "NodePropertySystem.h"
#include "ObjectGuid.h"
#include "SpellAuraDefines.h"
#include "SpellAuras.h"
#include "SpellInfo.h"

JVAL_CVAL_TMPLS_RW(Aura)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Aura *>() {
	TypedTemplate<Aura *> const ft = jctor();

	ft->SetClassName(jstr_intern("Aura"));

	reg_prop_ro(ft, "caster", [](Aura * aura) {
		return aura->GetCaster();
	});
	reg_prop_ro(ft, "casterGuid", [](Aura * aura) {
		return aura->GetCasterGUID();
	});
	reg_prop_ro(ft, "castItemGuid", [](Aura * aura) {
		return aura->GetCastItemGUID();
	});
	reg_prop_ro(ft, "castItemEntry", [](Aura * aura) {
		return aura->GetCastItemEntry();
	});
	reg_prop_ro(ft, "owner", [](Aura * aura) {
		return aura->GetOwner();
	});
	reg_prop_ro(ft, "casterLevel", [](Aura * aura) {
		return aura->GetCasterLevel();
	});
	reg_prop_ro(ft, "spellId", [](Aura * aura) {
		return aura->GetId();
	});
	reg_prop_ro(ft, "spellInfo", [](Aura * aura) {
		return aura->GetSpellInfo();
	});
	reg_prop_ro(ft, "type", [](Aura * aura) {
		auto const effMask = aura->GetEffectMask();
		for (uint8_t i = 0; i < MAX_SPELL_EFFECTS; ++i) {
			if (effMask & 1 << i) {
				return aura->GetSpellInfo()->Effects[i].ApplyAuraName;
			}
		}
		return SPELL_AURA_NONE;
	});
	reg_prop_ro(ft, "charges", [](Aura * aura) {
		return aura->GetCharges();
	});
	reg_prop_ro(ft, "isExpired", [](Aura * aura) {
		return aura->IsExpired();
	});
	reg_prop_ro(ft, "isPermanent", [](Aura * aura) {
		return aura->IsPermanent();
	});

	reg_prop(ft, "duration",
		[](Aura * aura) { return aura->GetDuration(); },
		[](Aura * aura, int32_t const duration) { aura->SetDuration(duration); }
	);
	reg_prop(ft, "maxDuration",
		[](Aura * aura) { return aura->GetMaxDuration(); },
		[](Aura * aura, int32_t const duration) { aura->SetMaxDuration(duration); }
	);
	reg_prop(ft, "stackAmount",
		[](Aura * aura) { return aura->GetStackAmount(); },
		[](Aura * aura, uint8_t const num) { aura->SetStackAmount(num); }
	);

	reg_method(ft, "setDurationWithMods", [](Aura * a, int32_t const duration) {
		a->SetDuration(duration, true);
	});
	reg_method(ft, "remove", [](Aura * a) {
		a->Remove();
	});

	return ft;
}
