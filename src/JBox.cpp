#include "JBox.h"

#include "CtoJ.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RW(JBox)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<JBox *>() {
	TypedTemplate<JBox *> const ft = jctor<JBox *>();

	ft->SetClassName(jstr_intern("$$$JBox$$$"));

	reg_method(ft, "get", [](JBox * b) {
		return b->getter();
	});
	reg_method(ft, "set", [](JBox * b, v8::Local<v8::Value> v) {
		if (!b->setter(v)) {
			v8::Isolate::GetCurrent()->ThrowError("Cannot set native value.");
		}
	});

	return ft;
}
