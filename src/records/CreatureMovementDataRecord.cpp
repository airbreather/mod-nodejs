#include <string>
#include <v8-local-handle.h>

#include "CreatureData.h"
#include "CtoJ.h"
#include "DurationWrapper.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<CreatureMovementData const &>(CreatureMovementData const & m) {
	return jobj(
		jprop("ground", m.Ground),
		jprop("flight", m.Flight),
		jprop("swim", m.Swim),
		jprop("rooted", m.Rooted),
		jprop("chase", m.Chase),
		jprop("random", m.Random),
		jprop("interactionPauseTimer", DurationWrapper::from_milliseconds(m.InteractionPauseTimer))
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<CreatureMovementData const>(CreatureMovementData const p) {
	return jval<CreatureMovementData const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<CreatureMovementData>(CreatureMovementData const p) {
	return jval<CreatureMovementData const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<CreatureMovementData const *>(CreatureMovementData const * p) {
	return p ? jval<CreatureMovementData const &>(*p) : jnull();
}
