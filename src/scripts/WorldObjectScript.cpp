#include "WorldObjectScript.h"

#include <string>

#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_WorldObject : public WorldObjectScript {
public:
	NODEJS_WorldObject() : WorldObjectScript("NODEJS_WorldObject") {
	}

	void OnWorldObjectDestroy(WorldObject * object) override {
		NodeJs::invoke_hook("world-object:install", jarg("object", object));
	}
	void OnWorldObjectCreate(WorldObject * object) override {
		NodeJs::invoke_hook("world-object:create", jarg("object", object));
	}
	void OnWorldObjectSetMap(WorldObject * object, Map * map ) override {
		NodeJs::invoke_hook("world-object:set-map", jarg("object", object), jarg("map", map));
	}
	void OnWorldObjectResetMap(WorldObject * object) override {
		NodeJs::invoke_hook("world-object:reset-map", jarg("object", object));
	}
	void OnWorldObjectUpdate(WorldObject * object, uint32_t const diff) override {
		NodeJs::invoke_hook("world-object:update", jarg("object", object), jarg("diff", diff));
	}
};

void AddSC_WorldObject() {
	new NODEJS_WorldObject();
}
