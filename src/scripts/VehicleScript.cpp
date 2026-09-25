#include "VehicleScript.h"

#include <string>

#include "NodeJPropHelpers.h"
#include "NodeJs.h"
#include "Vehicle.h"

class NODEJS_Vehicle : public VehicleScript {
public:
	NODEJS_Vehicle() : VehicleScript("NODEJS_Vehicle") {
	}

	void OnInstall(Vehicle * veh) override {
		NodeJs::invoke_hook("vehicle:install"
			, jprop("vehicle", veh));
	}
	void OnUninstall(Vehicle * veh) override {
		NodeJs::invoke_hook("vehicle:uninstall"
			, jprop("vehicle", veh));
	}
	void OnReset(Vehicle * veh) override {
		NodeJs::invoke_hook("vehicle:reset"
			, jprop("vehicle", veh));
	}
	void OnInstallAccessory(Vehicle * veh, Creature * accessory) override {
		NodeJs::invoke_hook("vehicle:install-accessory"
			, jprop("vehicle", veh), jprop("accessory", accessory));
	}
	void OnAddPassenger(Vehicle * veh, Unit * passenger, int8_t const seatId) override {
		NodeJs::invoke_hook("vehicle:add-passenger"
			, jprop("vehicle", veh), jprop("passenger", passenger), jprop("seatId", seatId));
	}
	void OnRemovePassenger(Vehicle * veh, Unit * passenger) override {
		NodeJs::invoke_hook("vehicle:remove-passenger"
			, jprop("vehicle", veh), jprop("passenger", passenger));
	}
};

void AddSC_Vehicle() {
	new NODEJS_Vehicle();
}
