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
// - one that wraps a reference of a particular native type (and doesn't own it)
// - one that can hold any value in the V8 universe (and owns it)
// we need the former so JavaScript code can set the values of (in/)out parameters.
// we need the latter so JavaScript code can create their own boxes on the fly.
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
