#include "SpawnGameObjectBuilder.h"

#include <utility>

#include "ObjectMgr.h"
#include "Transport.h"

SpawnGameObjectBuilder::SpawnGameObjectBuilder(uint32_t entry, Map * map, Position pos) :
	game_object_template(sObjectMgr->GetGameObjectTemplate(entry)), map(map), pos(std::move(pos)) {
}

GameObject * SpawnGameObjectBuilder::spawn() const {
	if (!game_object_template) {
		return nullptr;
	}

	auto final_rotation = rotation
		? *rotation
		: G3D::Quat::fromAxisAngleRotation(G3D::Vector3::unitZ(), pos.GetOrientation());
	auto entry = game_object_template->entry;
	auto is_static_transport = sObjectMgr->IsGameObjectStaticTransport(entry);
	auto * obj = is_static_transport ? new StaticTransport() : new GameObject();
	if (!obj->Create(
		map->GenerateLowGuid<HighGuid::GameObject>(), entry, map, phase_mask,
		pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(),
		final_rotation, animation_progress, state)) {
		delete obj;
		return nullptr;
	}

	// fill the gameobject data and save to the db
	obj->SaveToDB(map->GetId(), 1 << map->GetSpawnMode(), phase_mask);
	auto spawn_id = obj->GetSpawnId();

	// delete the old object and do a clean load from DB with a fresh new GameObject instance.
	// this is required to avoid weird behavior and memory leaks
	delete obj;

	obj = is_static_transport ? new StaticTransport() : new GameObject();
	// this will generate a new guid if the object is in an instance
	if (!obj->LoadGameObjectFromDB(spawn_id, map, true)) {
		delete obj;
		return nullptr;
	}

	/// @todo is it really necessary to add both the real and DB table guid here ?
	sObjectMgr->AddGameobjectToGrid(spawn_id, sObjectMgr->GetGameObjectData(spawn_id));
	return obj;
}
