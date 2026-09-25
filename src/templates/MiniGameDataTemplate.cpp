#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using MiniGameData = decltype(GameObjectTemplate().miniGame);
JVAL_CVAL_TMPLS_RO(MiniGameData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<MiniGameData const *>() {
	TypedTemplate<MiniGameData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("MiniGameData"));

	reg_prop_ro(ft, "gameType", [](MiniGameData const * m) {
		return m->gameType;
	});

	return ft;
}
