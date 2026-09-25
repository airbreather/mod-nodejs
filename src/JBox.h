#ifndef MOD_NODEJS_JBOX_H
#define MOD_NODEJS_JBOX_H

#include <functional>
#include <v8-local-handle.h>

struct JBox {
	std::function<v8::Local<v8::Value>()> getter;
	std::function<void(v8::Local<v8::Value>)> setter;
};

template <typename T>
v8::Local<v8::Object> jbox(T &);

#endif //MOD_NODEJS_JBOX_H
