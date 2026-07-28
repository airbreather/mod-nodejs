#include <node.h>
#include <string>
#include <vector>

#include "WorldScript.h"
#include "Log.h"
#include "NodeJs.h"

class NODEJS_world : public WorldScript {
public:
	NODEJS_world() : WorldScript(
		"NODEJS_world",
		{
			WORLDHOOK_ON_STARTUP,
			WORLDHOOK_ON_UPDATE,
			WORLDHOOK_ON_SHUTDOWN,
		}) {
	}

	void OnStartup() override {
		LOG_ERROR("server.loading", "Starting Node.js...");
		NodeJs::init_instance();
		LOG_ERROR("server.loading", "Started Node.js!");
		NodeJs::invoke_hook("world:startup");
	}

	void OnUpdate(uint32_t) override {
		NodeJs::instance()->tick();
	}

	void OnShutdown() override {
		NodeJs::invoke_hook("nodejs:before-shutdown", jarg("reloading", false));
		NodeJs::invoke_hook("world:shutdown");
		NodeJs::shutdown();
		node::TearDownOncePerProcess();
	}
};

void AddSC_World() {
	new NODEJS_world();
}
