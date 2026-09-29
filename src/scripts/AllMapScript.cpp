#include "AllMapScript.h"

#include "DurationWrapper.h"
#include "NodeJs.h"

class Map;

class NODEJS_AllMap : public AllMapScript {
public:
	NODEJS_AllMap() : AllMapScript("NODEJS_AllMap") {
	}

	void OnPlayerEnterAll(Map * map, Player * player) override {
		NodeJs::invoke_hook("map:player-enter"
			, jprop("map", map), jprop("player", player));
	}
	void OnPlayerLeaveAll(Map * map, Player * player) override {
		NodeJs::invoke_hook("map:player-leave"
			, jprop("map", map), jprop("player", player));
	}
	void OnBeforeCreateInstanceScript(InstanceMap * instanceMap, InstanceScript * * instanceData, bool const load, std::string const data, uint32_t const completedEncounterMask) override {
		// TODO: InstanceMap has more properties than just any ol' Map
		NodeJs::invoke_hook("map:before-create-instance"
			, jprop("instanceMap", reinterpret_cast<Map *>(instanceMap))/*, jprop("instanceData", instanceData)*/, jprop("load", load), jprop<std::string const &>("data", data), jprop("completedEncounterMask", completedEncounterMask));
	}
	void OnDestroyInstance(MapInstanced * mapInstanced, Map * map) override {
		// TODO: MapInstanced has more properties than just any ol' Map
		NodeJs::invoke_hook("map:destroy-instance",
			jprop("mapInstanced", reinterpret_cast<Map *>(mapInstanced)), jprop("map", map));
	}
	void OnCreateMap(Map * map) override {
		NodeJs::invoke_hook("map:create"
			, jprop("map", map));
	}
	void OnDestroyMap(Map * map) override {
		NodeJs::invoke_hook("map:destroy"
			, jprop("map", map));
	}
	void OnMapUpdate(Map * map, uint32_t diff) override {
		NodeJs::invoke_hook("map:update"
			, jprop("map", map), jprop("diff", DurationWrapper::from_milliseconds(diff)));
	}
};

void AddSC_AllMap() {
	new NODEJS_AllMap();
}
