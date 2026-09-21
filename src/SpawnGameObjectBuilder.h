#ifndef MOD_NODEJS_SPAWNGAMEOBJECTBUILDER_H
#define MOD_NODEJS_SPAWNGAMEOBJECTBUILDER_H

#include "GameObject.h"

struct SpawnGameObjectBuilder {
	SpawnGameObjectBuilder(uint32_t, Map *, Position);
	~SpawnGameObjectBuilder() = default;

	// take a cue from HandleGameObjectAddCommand about how to properly do this.
	//
	// these all are required:
	GameObjectTemplate const * game_object_template;
	Map * map;
	Position pos;

	// and all of these have sensible defaults:
	uint32_t phase_mask = PHASEMASK_ANYWHERE;
	std::optional<G3D::Quat> rotation;
	uint32_t animation_progress = 0;
	GOState state = GO_STATE_READY;

	GameObject * spawn() const;
};

#endif //MOD_NODEJS_SPAWNGAMEOBJECTBUILDER_H
