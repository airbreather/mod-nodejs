#include "WorldObjectScript.h"

#include <string>

#include "DurationWrapper.h"
#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_WorldObject : public WorldObjectScript {
public:
	NODEJS_WorldObject() : WorldObjectScript("NODEJS_WorldObject") {
	}

	void OnWorldObjectDestroy(WorldObject * object) override {
		NodeJs::invoke_hook("world-object:destroy", jarg("obj", object));
	}
	void OnWorldObjectCreate(WorldObject * object) override {
		NodeJs::invoke_hook("world-object:create", jarg("obj", object));
	}
	void OnWorldObjectSetMap(WorldObject * object, Map * map ) override {
		NodeJs::invoke_hook("world-object:set-map", jarg("obj", object), jarg("map", map));
	}
	void OnWorldObjectResetMap(WorldObject * object) override {
		NodeJs::invoke_hook("world-object:reset-map", jarg("obj", object));
	}
	void OnWorldObjectUpdate(WorldObject * object, uint32_t const diff) override {
		NodeJs::invoke_hook("world-object:update", jarg("obj", object), jarg("diff", DurationWrapper::from_milliseconds(diff)));
	}
};

void AddSC_WorldObject() {
	new NODEJS_WorldObject();
}
