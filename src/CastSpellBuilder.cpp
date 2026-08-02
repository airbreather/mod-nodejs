#include "CastSpellBuilder.h"

CastSpellBuilder::CastSpellBuilder(Unit * caster, SpellInfo const * spell_info)
	: caster(caster), spell_info(spell_info) { }

SpellCastResult CastSpellBuilder::cast() {
	CustomSpellValues custom_spell_values_real{};
	for (auto [mod, val] : custom_spell_values) {
		custom_spell_values_real.AddSpellMod(mod, val);
	}
	return caster->CastSpell(
		targets, spell_info, &custom_spell_values_real, trigger_cast_flags, cast_item, triggered_by_aura, original_caster
	);
}
