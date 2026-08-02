#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "DurationWrapper.h"
#include "Item.h"
#include "NodeJPropHelpers.h"
#include "NodePropertySystem.h"
#include "Object.h"
#include "Position.h"
#include "Spells/Spell.h"

JVAL_CVAL_TMPLS_RW(Spell)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Spell *>() {
	TypedTemplate<Spell *> const ft = jctor();

	ft->SetClassName(jstr_intern("Spell"));

	reg_prop_ro(ft, "spellInfo", [](Spell * spell) {
		return spell->GetSpellInfo();
	});
	reg_prop_ro(ft, "castTime", [](Spell * spell) {
		return DurationWrapper::from_milliseconds(spell->GetCastTime());
	});
	reg_prop_ro(ft, "powerCost", [](Spell * spell) {
		return spell->GetPowerCost();
	});
	reg_prop_ro(ft, "caster", [](Spell * spell) {
		return spell->GetCaster();
	});
	reg_prop_ro(ft, "targetDest", [](Spell * spell) {
		return spell->m_targets.HasDst()
			? (Position const *){spell->m_targets.GetDstPos()}
			: nullptr;
	});
	reg_prop_ro(ft, "target", [](Spell * spell) -> Object * {
		if (auto const target = spell->m_targets.GetObjectTarget()) {
			return target;
		}
		if (auto const target = spell->m_targets.GetItemTarget()) {
			return target;
		}
		return nullptr;
	});

	reg_prop(ft, "isAutoRepeat",
		[](Spell * spell) { return spell->IsAutoRepeat(); },
		[](Spell * spell, bool const value) { spell->SetAutoRepeat(value); }
	);

	reg_method(ft, "cast", [](Spell * spell, std::optional<bool> const skipCheck) {
		spell->cast(skipCheck.value_or(false));
	});
	reg_method(ft, "cancel", [](Spell * spell) {
		spell->cancel();
	});
	reg_method(ft, "finish", [](Spell * spell) {
		spell->finish();
	});

	return ft;
}
