#ifndef MOD_NODEJS_CASTSPELLBUILDER_H
#define MOD_NODEJS_CASTSPELLBUILDER_H

#include "Spell.h"

struct CastSpellBuilder {
	CastSpellBuilder(Unit *, SpellInfo const *);
	~CastSpellBuilder() = default;

	Unit * caster;
	SpellInfo const * spell_info;
	SpellCastTargets targets = {};
	std::unordered_map<SpellValueMod, int32_t> custom_spell_values = {};
	TriggerCastFlags trigger_cast_flags = TRIGGERED_NONE;
	Item * cast_item = nullptr;
	AuraEffect const * triggered_by_aura = nullptr;
	ObjectGuid original_caster = ObjectGuid::Empty;

	SpellCastResult cast();
};

#endif //MOD_NODEJS_CASTSPELLBUILDER_H
