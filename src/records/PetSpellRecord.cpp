#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "NodeJPropHelpers.h"
#include "Pet.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<PetSpell const &>(PetSpell const & p) {
	return jobj(
		jprop("active", p.active),
		jprop("state", p.state),
		jprop("type", p.type)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<PetSpell const>(PetSpell const p) {
	return jval<PetSpell const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<PetSpell>(PetSpell const p) {
	return jval<PetSpell const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<PetSpell const *>(PetSpell const * p) {
	return p ? jval<PetSpell const &>(*p) : jnull();
}
