#include <ranges>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "BattlegroundQueue.h"
#include "CtoJ.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RW(BattlegroundQueue)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<BattlegroundQueue *>() {
	TypedTemplate<BattlegroundQueue *> const ft = jctor();

	ft->SetClassName(jstr_intern("BattlegroundQueue"));

	reg_prop_ro(ft, "qp", [](BattlegroundQueue * bg) {
		std::map<ObjectGuid::LowType, GroupQueueInfo *> result;
		for (auto const [guid, info] : bg->m_QueuedPlayers) {
			result.insert(std::make_pair(guid.GetCounter(), info));
		}
		return jmap(result);
	});

	reg_method(ft, "getAverageQueueWaitTime", [](BattlegroundQueue * bg) {
		return bg->GetAverageQueueWaitTime(nullptr);
	});
	reg_method(ft, "checkPremadeMatch", [](BattlegroundQueue * bg, BattlegroundBracketId const bracket_id, uint32_t const min_players_per_team, uint32_t const max_players_per_team) {
		return bg->CheckPremadeMatch(bracket_id, min_players_per_team, max_players_per_team);
	});

	return ft;
}
