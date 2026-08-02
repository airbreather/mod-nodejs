#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "DBCStructure.h"
#include "DurationWrapper.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellDurationEntry const &>(SpellDurationEntry const & p) {
	return jobj(
		jprop("id", p.ID),
		jprop("duration", jarr(p.Duration | std::ranges::views::transform([](auto dur) {
			return DurationWrapper::from_milliseconds(dur);
		})))
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellDurationEntry const>(SpellDurationEntry const p) {
	return jval<SpellDurationEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellDurationEntry>(SpellDurationEntry const p) {
	return jval<SpellDurationEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<SpellDurationEntry const *>(SpellDurationEntry const * p) {
	return p ? jval<SpellDurationEntry const &>(*p) : jnull();
}
