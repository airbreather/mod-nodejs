#ifndef MOD_NODEJS_JBOX_H
#define MOD_NODEJS_JBOX_H

#include <v8-local-handle.h>

#include "JtoC.h"

struct JBox {
	virtual ~JBox() = default;

	virtual v8::Local<v8::Value> getter() = 0;
	virtual bool setter(v8::Local<v8::Value>) = 0;
};

template <typename T>
struct JBoxT : JBox {
	T & ref;

	explicit JBoxT(T & ref) : ref(ref) {
	}

	v8::Local<v8::Value> getter() override {
		return jval(ref);
	}

	bool setter(v8::Local<v8::Value> val) override {
		if (auto conv_val = cval<T>(val)) {
			ref = *conv_val;
			return true;
		}
		return false;
	}
};

#endif //MOD_NODEJS_JBOX_H
