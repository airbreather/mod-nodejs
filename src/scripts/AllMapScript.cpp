#include "AllMapScript.h"

#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class Map;

class NODEJS_AllMap : public AllMapScript {
public:
	NODEJS_AllMap() : AllMapScript("NODEJS_AllMap") {
	}

	void OnPlayerEnterAll(Map * map, Player * player) override {
		NodeJs::invoke_hook("all-map:player-enter", jarg("map", map), jarg("player", player));
	}
	void OnPlayerLeaveAll(Map * map, Player * player) override {
		NodeJs::invoke_hook("all-map:player-leave", jarg("map", map), jarg("player", player));
	}
	void OnBeforeCreateInstanceScript(InstanceMap * instanceMap, InstanceScript * * instanceData, bool const load, std::string const data, uint32_t const completedEncounterMask) override {
		// TODO: InstanceMap has more properties than just any ol' Map
		NodeJs::invoke_hook("all-map:before-create-instance", jarg("instanceMap", reinterpret_cast<Map *>(instanceMap))/*, jarg("instanceData", instanceData)*/, jarg("load", load), jarg<std::string const &>("data", data), jarg("completedEncounterMask", completedEncounterMask));
	}
	void OnDestroyInstance(MapInstanced * mapInstanced, Map * map) override {
		// TODO: MapInstanced has more properties than just any ol' Map
		NodeJs::invoke_hook("all-map:destroy-instance", jarg("mapInstanced", reinterpret_cast<Map *>(mapInstanced)), jarg("map", map));
	}
	void OnCreateMap(Map * map) override {
		NodeJs::invoke_hook("all-map:create", jarg("map", map));
	}
	void OnDestroyMap(Map * map) override {
		NodeJs::invoke_hook("all-map:destroy", jarg("map", map));
	}
	void OnMapUpdate(Map * map, uint32_t diff) override {
		NodeJs::invoke_hook("all-map:update", jarg("map", map), jarg("diff", diff));
	}
};

void AddSC_AllMap() {
	new NODEJS_AllMap();
}
