#ifndef MOD_NODEJS_JBOX_H
#define MOD_NODEJS_JBOX_H

#include <v8-local-handle.h>

#include "JtoC.h"

struct JBox {
	virtual ~JBox() = default;

	virtual v8::Local<v8::Value> getter() = 0;
	virtual bool setter(v8::Local<v8::Value>) = 0;
};

// there are basically two types of arbitrary boxes we support here:
// - one that we create as an owner of a value/object with a specific type
// - one that can hold any V8-world object
// the former can be fully generic (this), but the latter needs help (see specialization below).
template <typename T>
struct JBoxT : JBox {
	T boxed_val;

	explicit JBoxT(T val) : boxed_val(val) {
	}

	v8::Local<v8::Value> getter() override {
		return jval(boxed_val);
	}

	bool setter(v8::Local<v8::Value> val) override {
		if (auto conv_val = cval<T>(val)) {
			boxed_val = *conv_val;
			return true;
		}
		return false;
	}
};

// the existence of a JBoxT<v8::Local<v8::Value>> would not be a GC root for the boxed value if all
// we had was the above generic version.
template <>
struct JBoxT<v8::Local<v8::Value>> : JBox {
	v8::Global<v8::Value> boxed_val;

	explicit JBoxT(v8::Local<v8::Value> val) : boxed_val(v8::Global<v8::Value>(v8::Isolate::GetCurrent(), val)) {
	}

	v8::Local<v8::Value> getter() override {
		return boxed_val.Get(v8::Isolate::GetCurrent());
	}

	bool setter(v8::Local<v8::Value> val) override {
		boxed_val = v8::Global<v8::Value>(v8::Isolate::GetCurrent(), val);
		return true;
	}
};

#endif //MOD_NODEJS_JBOX_H
