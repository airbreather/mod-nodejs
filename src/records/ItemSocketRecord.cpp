#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "ItemTemplate.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_Socket const &>(_Socket const & v) {
	return jobj(
		jprop("color", v.Color),
		jprop("content", v.Content)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_Socket const>(_Socket const v) {
	return jval<_Socket const &>(v);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_Socket>(_Socket const v) {
	return jval<_Socket const &>(v);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_Socket const *>(_Socket const * v) {
	return v ? jval<_Socket const &>(*v) : jnull();
}
