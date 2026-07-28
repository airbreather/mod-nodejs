#include <string>
#include <v8-local-handle.h>

#include "CreatureData.h"
#include "CtoJ.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<CreatureModel const &>(CreatureModel const & m) {
	return jobj(
		jprop("creatureDisplayId", m.CreatureDisplayID),
		jprop("displayScale", m.DisplayScale),
		jprop("probability", m.Probability)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<CreatureModel const>(CreatureModel const p) {
	return jval<CreatureModel const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<CreatureModel>(CreatureModel const p) {
	return jval<CreatureModel const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<CreatureModel const *>(CreatureModel const * p) {
	return p ? jval<CreatureModel const &>(*p) : jnull();
}
