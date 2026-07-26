#include <vector>

#include "CommandScript.h"
#include "Chat.h"
#include "ChatCommand.h"
#include "NodeJs.h"
#include "RBAC.h"

class NODEJS_Command : public CommandScript {
public:
	NODEJS_Command() : CommandScript("NODEJS_Command") {
	}

	[[nodiscard]] std::vector<Acore::ChatCommands::ChatCommandBuilder> GetCommands() const override {
		static Acore::ChatCommands::ChatCommandTable nodejs_command_table =
		{
			{"reload", handle_reload_command, rbac::RBAC_PERM_COMMAND_SERVER_RESTART, Acore::ChatCommands::Console::Yes},
			{"gc", handle_gc_command, rbac::RBAC_PERM_COMMAND_SERVER_RESTART, Acore::ChatCommands::Console::Yes},
		};

		static Acore::ChatCommands::ChatCommandTable command_table =
		{
			{"js", nodejs_command_table},
		};

		auto res = std::vector{command_table};

		if (auto const instance = NodeJs::instance()) {
			for (auto & cmd : instance->get_commands()) {
				res.push_back(std::move(cmd));
			}
		}

		return res;
	}

	static bool handle_reload_command(ChatHandler * handler) {
		handler->SendErrorMessage("Restarting Node.js...");
		NodeJs::reload_instance();
		handler->SendErrorMessage("Restarted Node.js!");
		return false; // stop here, we've handled it
	}

	static bool handle_gc_command(ChatHandler * handler) {
		handler->SendErrorMessage("Running garbage collection...");
		NodeJs::instance()->run_scoped([] {
			NodeJs::instance()->run_garbage_collection_once();
		});
		handler->SendErrorMessage("Ran garbage collection!");
		return false; // stop here, we've handled it
	}
};

void AddSC_Command() {
	new NODEJS_Command();
}
