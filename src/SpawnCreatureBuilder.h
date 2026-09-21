#ifndef MOD_NODEJS_SPAWNCREATUREBUILDER_H
#define MOD_NODEJS_SPAWNCREATUREBUILDER_H

#include "Creature.h"

struct SpawnCreatureBuilder {
	SpawnCreatureBuilder(uint32_t, Map *, Position);
	~SpawnCreatureBuilder() = default;

	// take a cue from HandleNpcAddCommand about how to properly do this.
	//
	// these all are required:
	CreatureTemplate const * creature_template;
	Map * map;
	Position pos;

	// and all of these have sensible defaults:
	std::optional<CreatureData> data = std::nullopt;
	uint32_t phase_mask = PHASEMASK_ANYWHERE;

	// do this at some point in the future:
	// MotionTransport * transport = nullptr;

	CreatureData & ensure_data();
	Creature * spawn() const;
};

#endif //MOD_NODEJS_SPAWNCREATUREBUILDER_H
