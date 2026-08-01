#include <optional>
#include <ranges>
#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>
#include <vector>

#include "CtoJ.h"
#include "Define.h"
#include "Map.h"
#include "MapMgr.h"
#include "MapReference.h"
#include "NodePropertySystem.h"
#include "Player.h"

JVAL_CVAL_TMPLS_RW(Map)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Map *>() {
	TypedTemplate<Map *> const ft = jctor();

	ft->SetClassName(jstr_intern("ACMap"));

	reg_prop_ro(ft, "mapId", [](Map * m) {
		return m->GetId();
	});
	reg_prop_ro(ft, "instanceId", [](Map * m) {
		return m->GetInstanceId();
	});
	reg_prop_ro(ft, "isDungeon", [](Map * m) {
		return m->IsDungeon();
	});
	reg_prop_ro(ft, "isRaid", [](Map * m) {
		return m->IsRaid();
	});
	reg_prop_ro(ft, "isBattleground", [](Map * m) {
		return m->IsBattleground();
	});
	reg_prop_ro(ft, "isArena", [](Map * m) {
		return m->IsBattleArena();
	});
	reg_prop_ro(ft, "is25ManRaid", [](Map * m) {
		return m->Is25ManRaid();
	});
	reg_prop_ro(ft, "isEmpty", [](Map * m) {
		return !m->HavePlayers();
	});
	reg_prop_ro(ft, "isHeroic", [](Map * m) {
		return m->IsHeroic();
	});
	reg_prop_ro(ft, "difficulty", [](Map * m) {
		return m->GetDifficulty();
	});
	reg_prop_ro(ft, "playerCount", [](Map * m) {
		return m->GetPlayersCountExceptGMs(false);
	});
	reg_prop_ro(ft, "alivePlayerCount", [](Map * m) {
		return m->GetPlayersCountExceptGMs(true);
	});
	reg_prop_ro(ft, "name", [](Map * m) {
		return std::string(m->GetMapName());
	});
	reg_prop_ro(ft, "players", [](Map * map) {
		std::vector players(map->GetPlayers().getFirst(), map->GetPlayers().getLast());
		return jarr(players | std::ranges::views::transform([](MapReference const & r) { return r.GetSource(); }));
	});

	reg_method(ft, "getPlayersInTeam", [](Map * map, TeamId const teamId) {
		std::vector<Player *> matching;
		for (auto const & it : map->GetPlayers()) {
			if (auto const player = it.GetSource()) {
				if (player->GetTeamId() == teamId) {
					matching.push_back(player);
				}
			}
		}
		return jarr(matching);
	});
	reg_method(ft, "getHeightAt", [](Map * map, float const x, float const y, float const z, std::optional<uint32_t> const phaseMask, std::optional<bool> const vmap, std::optional<float> const maxSearchDist) {
		return map->GetHeight(phaseMask.value_or(1), x, y, z, vmap.value_or(true), maxSearchDist.value_or(DEFAULT_HEIGHT_SEARCH));
	});
	reg_method(ft, "getAreaIdAt", [](Map * map, float const x, float const y, float const z, std::optional<uint32_t> const phaseMask) {
		return map->GetAreaId(phaseMask.value_or(1), x, y, z);
	});

	reg_static_method(ft, "nonInstancedById", [](uint32_t const id) {
		return sMapMgr->FindMap(id, 0);
	});
	reg_static_method(ft, "instancedById", [](uint32_t const id, uint32_t const instance_id) {
		return sMapMgr->FindMap(id, instance_id);
	});
	reg_static_method(ft, "entrancePosById", [](uint32_t const id) {
		auto const at = sObjectMgr->GetMapEntranceTrigger(id);
		return at
			? jval(Position(at->target_X, at->target_Y, at->target_Z, at->target_Orientation))
			: jnull();
	});

	return ft;
}
