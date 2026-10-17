#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using SpellcasterData = decltype(GameObjectTemplate().spellcaster);
JVAL_CVAL_TMPLS_RO(SpellcasterData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<SpellcasterData const *>() {
	TypedTemplate<SpellcasterData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("SpellcasterData"));

	reg_prop_ro(ft, "spellId", [](SpellcasterData const * s) {
		return s->spellId;
	});
	reg_prop_ro(ft, "charges", [](SpellcasterData const * s) {
		return s->charges;
	});
	reg_prop_ro(ft, "partyOnly", [](SpellcasterData const * s) {
		return s->partyOnly != 0;
	});
	reg_prop_ro(ft, "allowMounted", [](SpellcasterData const * s) {
		return s->allowMounted != 0;
	});
	reg_prop_ro(ft, "large", [](SpellcasterData const * s) {
		return s->large != 0;
	});

	return ft;
}
