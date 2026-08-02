#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "NodeJPropHelpers.h"
#include "PetDefines.h"
#include "UnixTimestamp.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<PetStable::PetInfo const &>(PetStable::PetInfo const & p) {
	return jobj(
		jprop("name", p.Name),
		jprop("actionBar", p.ActionBar),
		jprop("petNumber", p.PetNumber),
		jprop("creatureId", p.CreatureId),
		jprop("displayId", p.DisplayId),
		jprop("experience", p.Experience),
		jprop("health", p.Health),
		jprop("mana", p.Mana),
		jprop("happiness", p.Happiness),
		jprop("lastSaveTime", UnixTimestamp::from_chrono(Seconds{p.LastSaveTime})),
		jprop("createdBySpellId", p.CreatedBySpellId),
		jprop("level", p.Level),
		jprop("reactState", p.ReactState),
		jprop("type", p.Type),
		jprop("wasRenamed", p.WasRenamed)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<PetStable::PetInfo const>(PetStable::PetInfo const p) {
	return jval<PetStable::PetInfo const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<PetStable::PetInfo>(PetStable::PetInfo const p) {
	return jval<PetStable::PetInfo const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<PetStable::PetInfo const *>(PetStable::PetInfo const * p) {
	return p ? jval<PetStable::PetInfo const &>(*p) : jnull();
}
