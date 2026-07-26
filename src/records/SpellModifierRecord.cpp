#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "NodeJPropHelpers.h"
#include "Player.h"
#include "Util.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellModifier const &>(SpellModifier const & p) {
	return jobj(
		jprop("op", p.op),
		jprop("type", p.type),
		jprop("value", p.value),
		jprop("mask", p.mask),
		jprop("spellId", p.spellId),
		jprop("ownerAura", p.ownerAura)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellModifier const>(SpellModifier const p) {
	return jval<SpellModifier const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellModifier>(SpellModifier const p) {
	return jval<SpellModifier const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellModifier const *>(SpellModifier const * p) {
	return p ? jval<SpellModifier const &>(*p) : jnull();
}

template<>
std::optional<SpellModifier> cval<SpellModifier>(v8::Local<v8::Value> const v) {
	if (!v->IsObject()) {
		return std::nullopt;
	}
	auto const obj = v.As<v8::Object>();
	if (auto const op = cval<SpellModOp>(obj, "op")) {
		if (auto const type = cval<SpellModType>(obj, "type")) {
			if (auto const value = cval<int32_t>(obj, "value")) {
				if (auto const mask = cval<flag96>(obj, "mask")) {
					if (auto const spell_id = cval<uint32_t>(obj, "spellId")) {
						auto const owner_aura = cval<Aura *>(obj, "ownerAura");
						SpellModifier ret(owner_aura.value_or(nullptr));
						ret.op = *op;
						ret.type = *type;
						ret.value = *value;
						ret.mask = *mask;
						ret.spellId = *spell_id;
						return ret;
					}
				}
			}
		}
	}
	return std::nullopt;
}

template<>
std::optional<SpellModifier const> cval<SpellModifier const>(v8::Local<v8::Value> const v) {
	return cval<SpellModifier>(v);
}
