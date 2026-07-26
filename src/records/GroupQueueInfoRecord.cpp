#include <string>
#include <v8-local-handle.h>

#include "BattlegroundQueue.h"
#include "CtoJ.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<GroupQueueInfo const &>(GroupQueueInfo const & p) {
	return jobj(
		jprop("players", jarr(p.Players)),
		jprop("teamId", p.teamId),
		jprop("realTeamID", p.RealTeamID),
		jprop("bgTypeId", p.BgTypeId),
		jprop("isRated", p.IsRated),
		jprop("arenaType", p.ArenaType),
		jprop("arenaTeamId", p.ArenaTeamId),
		jprop("joinTime", p.JoinTime),
		jprop("removeInviteTime", p.RemoveInviteTime),
		jprop("isInvitedToBGInstanceGUID", p.IsInvitedToBGInstanceGUID),
		jprop("arenaTeamRating", p.ArenaTeamRating),
		jprop("arenaMatchmakerRating", p.ArenaMatchmakerRating),
		jprop("opponentsTeamRating", p.OpponentsTeamRating),
		jprop("opponentsMatchmakerRating", p.OpponentsMatchmakerRating),
		jprop("previousOpponentsTeamId", p.PreviousOpponentsTeamId),
		jprop("bracketId", p.BracketId),
		jprop("groupType", p.GroupType)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<GroupQueueInfo const>(GroupQueueInfo const p) {
	return jval<GroupQueueInfo const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<GroupQueueInfo>(GroupQueueInfo const p) {
	return jval<GroupQueueInfo const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<GroupQueueInfo const *>(GroupQueueInfo const * p) {
	return p ? jval<GroupQueueInfo const &>(*p) : jnull();
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<GroupQueueInfo *>(GroupQueueInfo * p) {
	return p ? jval<GroupQueueInfo const &>(*p) : jnull();
}
