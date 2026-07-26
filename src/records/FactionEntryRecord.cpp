#include <optional>
#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "JtoC.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<FactionEntry const &>(FactionEntry const & a) {
	return jobj(
		jprop("id", a.ID),
		jprop("reputationListId", a.reputationListID),
		jprop("baseRepRaceMask", jarr(a.BaseRepRaceMask)),
		jprop("baseRepClassMask", jarr(a.BaseRepClassMask)),
		jprop("baseRepValue", jarr(a.BaseRepValue)),
		jprop("reputationFlags", jarr(a.ReputationFlags)),
		jprop("team", a.team),
		jprop("spilloverRateIn", a.spilloverRateIn),
		jprop("spilloverRateOut", a.spilloverRateOut),
		jprop("spilloverMaxRankIn", a.spilloverMaxRankIn),
		jprop("name", jarr(a.name)),
		jprop("canHaveReputation", a.CanHaveReputation()),
		jprop("canBeSetAtWar", a.CanBeSetAtWar())
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<FactionEntry const>(FactionEntry const p) {
	return jval<FactionEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<FactionEntry>(FactionEntry const p) {
	return jval<FactionEntry const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<FactionEntry const *>(FactionEntry const * p) {
	return p ? jval<FactionEntry const &>(*p) : jnull();
}

template<>
[[nodiscard]] std::optional<FactionEntry const *> cval<FactionEntry const *>(v8::Local<v8::Value> const v) {
	return centry_lookup(v, sFactionStore);
}
