#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "NodeJPropHelpers.h"
#include "SpellInfo.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<ImmunityInfo const &>(ImmunityInfo const & p) {
	return jobj(
		jprop("schoolImmuneMask", p.SchoolImmuneMask),
		jprop("applyHarmfulAuraImmuneMask", p.ApplyHarmfulAuraImmuneMask),
		jprop("mechanicImmuneMask", p.MechanicImmuneMask),
		jprop("dispelImmuneMask", p.DispelImmuneMask),
		jprop("damageSchoolMask", p.DamageSchoolMask),
		jprop("auraTypeImmune", jset(p.AuraTypeImmune)),
		jprop("spellEffectImmune", jset(p.SpellEffectImmune))
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<ImmunityInfo const>(ImmunityInfo const p) {
	return jval<ImmunityInfo const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<ImmunityInfo>(ImmunityInfo const p) {
	return jval<ImmunityInfo const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<ImmunityInfo const *>(ImmunityInfo const * p) {
	return p ? jval<ImmunityInfo const &>(*p) : jnull();
}
