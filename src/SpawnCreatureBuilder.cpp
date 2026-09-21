#include "SpawnCreatureBuilder.h"

#include <utility>

#include "ObjectMgr.h"

SpawnCreatureBuilder::SpawnCreatureBuilder(uint32_t entry, Map * map, Position pos) :
	creature_template(sObjectMgr->GetCreatureTemplate(entry)), map(map), pos(std::move(pos)) {
}

CreatureData & SpawnCreatureBuilder::ensure_data() {
	return data ? *data : data.emplace();
}

Creature * SpawnCreatureBuilder::spawn() const {
	if (!creature_template) {
		return nullptr;
	}

	auto * creature = new Creature();
	if (!creature->Create(
		map->GenerateLowGuid<HighGuid::Unit>(), map, phase_mask, creature_template->Entry, 0,
		pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(),
		data ? &data.value() : nullptr)) {
		delete creature;
		return nullptr;
	}

	creature->SaveToDB(map->GetId(), 1 << map->GetSpawnMode(), phase_mask);

	auto spawnId = creature->GetSpawnId();

	creature->CleanupsBeforeDelete();
	delete creature;
	creature = new Creature();
	if (!creature->LoadCreatureFromDB(spawnId, map, true, true)) {
		delete creature;
		return nullptr;
	}

	sObjectMgr->AddCreatureToGrid(spawnId, sObjectMgr->GetCreatureData(spawnId));
	return creature;
}
