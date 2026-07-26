#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "NodeJPropHelpers.h"
#include "Position.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<Position const &>(Position const & p) {
	return jobj(
		jprop("x", p.GetPositionX()),
		jprop("y", p.GetPositionY()),
		jprop("z", p.GetPositionZ()),
		jprop("o", p.GetOrientation())
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<Position const>(Position const p) {
	return jval<Position const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<Position>(Position const p) {
	return jval<Position const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<Position const *>(Position const * p) {
	return p ? jval<Position const &>(*p) : jnull();
}
