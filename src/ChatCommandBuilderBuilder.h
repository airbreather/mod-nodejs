#ifndef MOD_NODEJS_CHATCOMMANDBUILDERBUILDER_H
#define MOD_NODEJS_CHATCOMMANDBUILDERBUILDER_H

#include <v8-function.h>

#include <functional>
#include <optional>
#include <string>

#include "ChatCommand.h"
#include "Common.h"

using ChatCommandBuilder = Acore::ChatCommands::ChatCommandBuilder;
using CommandInvoker = Acore::Impl::ChatCommands::CommandInvoker;
using Console = Acore::ChatCommands::Console;

class ChatCommandBuilderBuilder;
using ChatCommandBuilderBuilderBox = std::shared_ptr<ChatCommandBuilderBuilder>;

class ChatCommandBuilderBuilder {
	using SubcommandBuilders = std::unordered_map<std::string, ChatCommandBuilderBuilderBox>;
	using Subcommands = std::vector<ChatCommandBuilder>;
	struct subcommand_data {
		SubcommandBuilders m_builders = {};
		std::optional<Subcommands> m_built = {};
	};
	struct runnable_data {
		std::optional<std::variant<v8::Global<v8::Function>, size_t>> m_handler;
		std::optional<AccountTypes> m_security_level;
		std::optional<Console> m_allow_console;
		std::optional<AcoreStrings> m_help;
	};

	std::string const m_name;
	// if a command has subcommands, then it may not also be runnable itself.
	// some fields are only supported (and only make sense) on runnable ones.
	std::optional<std::variant<subcommand_data, runnable_data>> m_data;

	void assign_slots_rec(std::vector<std::string> &, std::function<size_t(std::vector<std::string> &, v8::Global<v8::Function>)> &);

public:
	explicit ChatCommandBuilderBuilder(std::string);

	[[nodiscard]] std::string const & get_name() const { return m_name; }

	void add_subcommand(ChatCommandBuilderBuilderBox);
	void assign_slots(std::function<size_t(std::vector<std::string> &, v8::Global<v8::Function>)>);
	void set_handler(v8::Local<v8::Function>);
	void set_security_level(AccountTypes);
	void set_allow_console(Console);
	void set_help(AcoreStrings);

	ChatCommandBuilder build();
};

#endif //MOD_NODEJS_CHATCOMMANDBUILDERBUILDER_H
