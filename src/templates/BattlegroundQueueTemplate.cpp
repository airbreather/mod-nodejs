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

	reg_prop_ro(ft, "queuedPlayers", [](BattlegroundQueue * bg) {
		std::map<ObjectGuid::LowType, GroupQueueInfo *> result;
		for (auto const [guid, info] : bg->m_QueuedPlayers) {
			result.insert(std::make_pair(guid.GetCounter(), info));
		}
		return jmap(result);
	});

	reg_method(ft, "getAverageQueueWaitTime", [](BattlegroundQueue * bg, TeamId team_id, uint8_t bracket_id) {
		// the method requires a full GroupQueueInfo, but it only observes at most three values.
		GroupQueueInfo info{};
		info.teamId = team_id;
		info.BracketId = bracket_id;
		return bg->GetAverageQueueWaitTime(&info);
	});
	reg_method(ft, "getAverageArenaQueueWaitTime", [](BattlegroundQueue * bg, uint8_t arena_type, bool is_rated, uint8_t bracket_id) {
		// the method requires a full GroupQueueInfo, but it only observes at most three values.
		GroupQueueInfo info{};
		// probably could get away with hardcoding ArenaType to like 2 or something since the code
		// today only cares about "zero or nonzero?", but maybe it will later have different wait
		// times for the different 2v2/3v3/5v5 types, so set it anyway.
		info.ArenaType = arena_type;
		info.IsRated = is_rated;
		info.BracketId = bracket_id;
		return bg->GetAverageQueueWaitTime(&info);
	});
	reg_method(ft, "checkPremadeMatch", [](BattlegroundQueue * bg, BattlegroundBracketId const bracket_id, uint32_t const min_players_per_team, uint32_t const max_players_per_team) {
		return bg->CheckPremadeMatch(bracket_id, min_players_per_team, max_players_per_team);
	});

	return ft;
}
