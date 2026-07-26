#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "ItemTemplate.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_Spell const &>(_Spell const & p) {
	return jobj(
		jprop("id", p.SpellId),
		jprop("trigger", p.SpellTrigger),
		jprop("charges", p.SpellCharges),
		jprop("ppmRate", p.SpellPPMRate),
		jprop("cooldown", p.SpellCooldown),
		jprop("category", p.SpellCategory),
		jprop("categoryCooldown", p.SpellCategoryCooldown)
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
