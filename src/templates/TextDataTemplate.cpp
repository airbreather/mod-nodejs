#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using TextData = decltype(GameObjectTemplate().text);
JVAL_CVAL_TMPLS_RO(TextData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<TextData const *>() {
	TypedTemplate<TextData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("TextData"));

	reg_prop_ro(ft, "pageId", [](TextData const * t) {
		return t->pageID;
	});
	reg_prop_ro(ft, "language", [](TextData const * t) {
		return t->language;
	});
	reg_prop_ro(ft, "pageMaterial", [](TextData const * t) {
		return t->pageMaterial;
	});
	reg_prop_ro(ft, "allowMounted", [](TextData const * t) {
		return t->allowMounted != 0;
	});

	return ft;
}
