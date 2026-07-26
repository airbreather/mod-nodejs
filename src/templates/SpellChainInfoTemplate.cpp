#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "SharedDefines.h"
#include "Spells/SpellInfo.h"

JVAL_CVAL_TMPLS_RW(SpellChainNode)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<SpellChainNode *>() {
	TypedTemplate<SpellChainNode *> const ft = jctor();

	ft->SetClassName(jstr_intern("SpellChainNode"));

	// TODO: SPECIAL: encapsulate, using SpellMgr methods like GetPrevSpellInChain.

	return ft;
}
