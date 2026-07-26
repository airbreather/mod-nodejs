#include <cmath>
#include <optional>
#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>
#include <vector>

#include "Cell.h"
// ReSharper disable once CppUnusedIncludeDirective -- Cell::VisitObjects
#include "CellImpl.h"
#include "CtoJ.h"
#include "GameObject.h"
#include "GameObjectData.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "NodeJPropHelpers.h"
#include "NodePropertySystem.h"
#include "Object.h"
#include "ObjectGuid.h"
#include "Transport.h"
#include "Unit.h"

JVAL_CVAL_TMPLS_RW(WorldObject)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<WorldObject *>() {
	TypedTemplate<WorldObject *> const ft = jctor();

	ft->SetClassName(jstr_intern("WorldObject"));
	ft.safe_inherit<Object *>();

	reg_prop_ro(ft, "mapId", [](WorldObject * wo) {
		return wo->GetMapId();
	});
	reg_prop_ro(ft, "zoneId", [](WorldObject * wo) {
		return wo->GetZoneId();
	});
	reg_prop_ro(ft, "areaId", [](WorldObject * wo) {
		return wo->GetAreaId();
	});
	reg_prop_ro(ft, "phaseMask", [](WorldObject * wo) {
		return wo->GetPhaseMask();
	});
	reg_prop_ro(ft, "instanceId", [](WorldObject * wo) {
		return wo->GetInstanceId();
	});
	reg_prop_ro(ft, "location", [](WorldObject * wo) {
		return (Position const *){wo};
	});
	reg_prop_ro(ft, "transport", [](WorldObject * wo) {
		return wo->GetTransport();
	});
	reg_prop_ro(ft, "sightRange", [](WorldObject * wo) {
		return wo->GetSightRange();
	});

	reg_method(ft, "getNearestPlayer", [](WorldObject * wo, float const range) {
		Player * nearest = nullptr;
		Acore::AnyPlayerInObjectRangeCheck checker(wo, range, true, false);
		Acore::PlayerLastSearcher searcher(wo, nearest, checker);
		Cell::VisitObjects(wo, searcher, range);
		return nearest;
	});
	reg_method(ft, "getNearestCreature", [](WorldObject * wo, float const range, std::optional<uint32_t> const entry) {
		return wo->FindNearestCreature(entry.value_or(0), range, false);
	});
	reg_method(ft, "getNearestGameObject", [](WorldObject * wo, float const range, std::optional<uint32_t> const entry) {
		return wo->FindNearestGameObject(entry.value_or(0), range, false);
	});
	reg_method(ft, "getDistanceTo", [](WorldObject * wo, WorldObject * target, std::optional<bool> const only2d, std::optional<bool> const must_be_exact) {
		if (only2d.value_or(false)) {
			auto const dx = wo->GetPositionX() - target->GetPositionX();
			auto const dy = wo->GetPositionY() - target->GetPositionY();
			return sqrtf(dx * dx + dy * dy);
		}
		return must_be_exact.value_or(false) ? wo->GetExactDist(target) : wo->GetDistance(target);
	});
	reg_method(ft, "getSightRangeTo", [](WorldObject * wo, WorldObject * target) {
		return wo->GetSightRange(target);
	});
	reg_method(ft, "getAngleTo", [](WorldObject * wo, WorldObject * target) {
		return wo->GetAngle(target->GetPositionX(), target->GetPositionY());
	});
	reg_method(ft, "isWithinLoSTo", [](WorldObject * wo, WorldObject * target) {
		return wo->IsWithinLOSInMap(target);
	});
	reg_method(ft, "isWithinDistTo", [](WorldObject * wo, WorldObject * target, float dist, std::optional<bool> must_be_in_same_map) {
		return must_be_in_same_map.value_or(false)
			? wo->IsWithinDistInMap(target, dist)
			: wo->IsWithinDist(target, dist);
	});
	reg_method(ft, "isInSameMapAs", [](WorldObject * wo, WorldObject * target) {
		return wo->IsInMap(target);
	});
	reg_method(ft, "isWithinDist3d", [](WorldObject * wo, float const x, float const y, float const z, float const dist) {
		return wo->IsWithinDist3d(x, y, z, dist);
	});
	reg_method(ft, "isWithinDist2d", [](WorldObject * wo, float const x, float const y, float const dist) {
		return wo->IsWithinDist2d(x, y, dist);
	});
	reg_method(ft, "isInRangeTo", [](WorldObject * wo, WorldObject * target, float max, std::optional<float> min, std::optional<bool> only2d) {
		return wo->IsInRange(target, min.value_or(0), max, !only2d.value_or(false));
	});
	reg_method(ft, "isInFrontOf", [](WorldObject * wo, WorldObject * target) {
		return wo->isInFront(target);
	});
	reg_method(ft, "isInBackOf", [](WorldObject * wo, WorldObject * target) {
		return wo->isInBack(target);
	});
	reg_method(ft, "getRelativePoint", [](WorldObject * wo, float const range, float const deg) {
		float const rad = M_PI * deg / 180.0f;
		return jobj(
			jprop("x", wo->GetPositionX() + range * cosf(rad)),
			jprop("y", wo->GetPositionY() + range * sinf(rad)),
			jprop("z", wo->GetPositionZ())
		);
	});
	reg_method(ft, "getNearObject", [](WorldObject * wo, float const range) {
		WorldObject * nearest = nullptr;
		Acore::AllWorldObjectsInRange checker(wo, range);
		Acore::WorldObjectLastSearcher searcher(wo, nearest, checker);
		Cell::VisitObjects(wo, searcher, range);
		return nearest;
	});
	reg_method(ft, "getPlayersInRange", [](WorldObject * wo, float const range) {
		std::vector<Player *> list;
		Acore::AnyPlayerInObjectRangeCheck checker(wo, range, true, false);
		Acore::PlayerListSearcher searcher(wo, list, checker);
		Cell::VisitObjects(wo, searcher, range);
		return jarr(list);
	});
	reg_method(ft, "getCreaturesInRange", [](WorldObject * wo, float const range, std::optional<uint32_t> const entryOpt) {
		auto const entry = entryOpt.value_or(0);
		std::vector<Creature *> list;

		struct CreatureInRangeCheck {
			WorldObject * i_obj;
			float i_range;
			uint32_t i_entry;

			CreatureInRangeCheck(WorldObject * o, float const r, uint32_t const e) : i_obj(o), i_range(r), i_entry(e) {}

			bool operator()(Unit const * u) const {
				if (!u->IsAlive()) return false;
				if (i_entry && u->GetEntry() != i_entry) return false;
				if (!i_obj->IsWithinDistInMap(u, i_range)) return false;
				if (u->GetTypeId() != TYPEID_UNIT) return false;
				return true;
			}
		};
		CreatureInRangeCheck checker(wo, range, entry);
		Acore::CreatureListSearcher searcher(wo, list, checker);
		Cell::VisitObjects(wo, searcher, range);
		return jarr(list);
	});
	reg_method(ft, "getGameObjectsInRange", [](WorldObject * wo, float const range, std::optional<uint32_t> const entryOpt) {
		auto const entry = entryOpt.value_or(0);
		std::vector<GameObject *> list;

		struct GameObjectInRangeCheck {
			WorldObject * i_obj;
			float i_range;
			uint32_t i_entry;

			GameObjectInRangeCheck(WorldObject * o, float const r, uint32_t const e) : i_obj(o), i_range(r), i_entry(e) {}

			bool operator()(WorldObject * w) const {
				if (!i_obj->IsWithinDistInMap(w, i_range)) return false;
				const GameObject * go = w->ToGameObject();
				if (!go) return false;
				if (i_entry && go->GetGOInfo()->entry != i_entry) return false;
				return true;
			}
		};
		GameObjectInRangeCheck checker(wo, range, entry);
		Acore::GameObjectListSearcher searcher(wo, list, checker);
		Cell::VisitObjects(wo, searcher, range);
		return jarr(list);
	});
	reg_method(ft, "getUnitsInRange", [](WorldObject * wo, float const range) {
		std::vector<Unit *> list;
		Acore::AnyUnitInObjectRangeCheck checker(wo, range);
		Acore::UnitListSearcher searcher(wo, list, checker);
		Cell::VisitObjects(wo, searcher, range);
		return jarr(list);
	});
	reg_method(ft, "getNearObjects", [](WorldObject * wo, float const range, std::optional<uint8_t> const maskOpt) {
		auto const typeMask = maskOpt.value_or(0b111);

		struct NearObjectsCheck {
			WorldObject * i_obj;
			float i_range;
			uint8_t i_typeMask;

			NearObjectsCheck(WorldObject * o, float const r, uint8_t const m)
				: i_obj(o), i_range(r), i_typeMask(m) {}

			bool operator()(WorldObject * w) const {
				if (!i_obj->IsWithinDistInMap(w, i_range)) return false;
				if (i_typeMask & 0b001 && w->IsPlayer()) return true;
				if (i_typeMask & 0b010 && w->IsCreature()) return true;
				if (i_typeMask & 0b100 && w->IsGameObject()) return true;
				return false;
			}
		};

		NearObjectsCheck checker(wo, range, typeMask);
		std::vector<WorldObject *> list;
		Acore::WorldObjectListSearcher searcher(wo, list, checker);
		Cell::VisitObjects(wo, searcher, range);
		return jarr(list);
	});
	reg_method(ft, "sendMessageToSet", [](WorldObject * wo, WorldPacket * packet, bool self) {
		wo->SendMessageToSet(packet, self);
	});
	reg_method(ft, "sendMessageToSetInRange", [](WorldObject * wo, WorldPacket * packet, float range) {
		wo->SendMessageToSetInRange(packet, range, false); // method implementation ignores the last parameter
	});
	reg_method(ft, "sendMessageToSetExceptPlayer", [](WorldObject * wo, WorldPacket * packet, Player * skipped_rcvr) {
		wo->SendMessageToSet(packet, skipped_rcvr);
	});

	reg_prop(ft, "name",
		[](WorldObject * wo) { return wo->GetName(); },
		[](WorldObject * wo, std::string const name) { wo->SetName(name); }
	);

	reg_method(ft, "playMusic", [](WorldObject * wo, uint32_t const soundKitId, std::optional<bool> const zoneWide) {
		wo->SendPlayMusic(soundKitId, !zoneWide.value_or(false));
	});
	reg_method(ft, "playDirectSound", [](WorldObject * wo, uint32_t const soundId) {
		wo->PlayDirectSound(soundId, nullptr);
	});
	reg_method(ft, "playDistanceSound", [](WorldObject * wo, uint32_t const soundId) {
		wo->PlayDistanceSound(soundId, nullptr);
	});
	// TODO: there is SO MUCH MORE we can expose as far as parameters go
	reg_method(ft, "summonGameObject", [](WorldObject * wo, uint32_t const entry, std::optional<float> const x, std::optional<float> const y, std::optional<float> const z, std::optional<float> const o) {
		auto const fx = x.value_or(wo->GetPositionX());
		auto const fy = y.value_or(wo->GetPositionY());
		auto const fz = z.value_or(wo->GetPositionZ());
		auto const fo = o.value_or(wo->GetOrientation());
		return wo->SummonGameObject(entry, fx, fy, fz, fo, 0, 0, 0, 0, 60);
	});
	// TODO: there is SO MUCH MORE we can expose as far as parameters go
	reg_method(ft, "spawnCreature", [](WorldObject * wo, uint32_t const entry, std::optional<float> const x, std::optional<float> const y, std::optional<float> const z, std::optional<float> const o) {
		auto const fx = x.value_or(wo->GetPositionX());
		auto const fy = y.value_or(wo->GetPositionY());
		auto const fz = z.value_or(wo->GetPositionZ());
		auto const fo = o.value_or(wo->GetOrientation());
		return wo->SummonCreature(entry, fx, fy, fz, fo, TEMPSUMMON_TIMED_DESPAWN, 60000);
	});

	return ft;
}
