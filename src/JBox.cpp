#include "JBox.h"

#include "CtoJ.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RW(JBox)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<JBox *>() {
	TypedTemplate<JBox *> const ft = jctor([](v8::Local<v8::Value> val) -> JBox * {
		return new JBoxT(val);
	});

	ft->SetClassName(jstr_intern("Box"));

	reg_method(ft, "get", [](JBox * b) {
		return b->getter();
	});
	reg_method(ft, "set", [](JBox * b, v8::Local<v8::Value> v) {
		if (!b->setter(v)) {
			jthrow("Cannot set native value.");
		}
	});

	return ft;
}
