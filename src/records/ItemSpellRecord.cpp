#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "ItemTemplate.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_Spell const &>(_Spell const & p) {
	return jobj(
		jprop("spellId", p.SpellId),
		jprop("spellTrigger", p.SpellTrigger),
		jprop("spellCharges", p.SpellCharges),
		jprop("spellPPMRate", p.SpellPPMRate),
		jprop("spellCooldown", p.SpellCooldown),
		jprop("spellCategory", p.SpellCategory),
		jprop("spellCategoryCooldown", p.SpellCategoryCooldown)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_Spell const>(_Spell const p) {
	return jval<_Spell const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_Spell>(_Spell const p) {
	return jval<_Spell const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_Spell const *>(_Spell const * p) {
	return p ? jval<_Spell const &>(*p) : jnull();
}
