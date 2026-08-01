#include <ranges>
#include <boost/preprocessor/iteration/local.hpp>

#include "ChatCommandBuilderBuilder.h"

#include <v8-isolate.h>

#include "ChatCommand.h"
#include "Log.h"
#include "NodePropertySystem.h"

namespace {
	class IncompleteVariantError : public std::logic_error {
	public:
		explicit IncompleteVariantError()
			: std::logic_error("Tried to build a runnable command without all required parameters.") {
		}
	};
	class IncompatibleVariantError : public std::logic_error {
	public:
		explicit IncompatibleVariantError()
			: std::logic_error("Tried to mix mutually exclusive calls to ChatCommandBuilderBuilder.") {
		}
	};
	class TooManyCommandsError : public std::runtime_error {
	public:
		explicit TooManyCommandsError()
			: std::runtime_error("Tried to register too many commands.") {
		}
	};
}

void ChatCommandBuilderBuilder::assign_slots_rec(std::vector<std::string> & path, std::function<size_t(std::vector<std::string> &, v8::Global<v8::Function>)> assign) {
	if (!m_data) {
		return;
	}
	if (std::holds_alternative<runnable_data>(*m_data)) {
		auto & data = std::get<runnable_data>(*m_data);
		if (!data.m_handler) {
			throw IncompleteVariantError();
		}
		if (std::holds_alternative<v8::Global<v8::Function>>(*data.m_handler)) {
			auto handler = std::move(std::get<v8::Global<v8::Function>>(*data.m_handler));
			data.m_handler = assign(path, std::move(handler));
		}
		return;
	}
	for (auto & [name, sub] : std::get<subcommand_data>(*m_data).m_builders) {
		path.emplace_back(name);
		sub->assign_slots_rec(path, assign);
		path.pop_back();
	}
}

ChatCommandBuilderBuilder::ChatCommandBuilderBuilder(std::string name) : m_name(std::move(name)) {
}

void ChatCommandBuilderBuilder::add_subcommand(ChatCommandBuilderBuilderBox sub) {
	if (!m_data) {
		m_data = subcommand_data{};
	}
	if (std::holds_alternative<runnable_data>(*m_data)) {
		throw IncompatibleVariantError();
	}
	auto & [builders, built] = std::get<subcommand_data>(*m_data);
	builders.erase(sub->m_name);
	built = {};
	Acore::ChatCommands::InvalidateCommandMap();
	builders.emplace(sub->m_name, std::move(sub));
}

void ChatCommandBuilderBuilder::assign_slots(std::function<size_t(std::vector<std::string> &, v8::Global<v8::Function>)> fn) {
	std::vector<std::string> vec{};
	assign_slots_rec(vec, fn);
}

void ChatCommandBuilderBuilder::set_handler(v8::Local<v8::Function> handler) {
	if (!m_data) {
		m_data = runnable_data{};
	}
	if (std::holds_alternative<subcommand_data>(*m_data)) {
		throw IncompatibleVariantError();
	}
	std::get<runnable_data>(*m_data).m_handler = v8::Global<v8::Function>(v8::Isolate::GetCurrent(), handler);
}

void ChatCommandBuilderBuilder::set_security_level(AccountTypes security_level) {
	if (!m_data) {
		m_data = runnable_data{};
	}
	if (std::holds_alternative<subcommand_data>(*m_data)) {
		throw IncompatibleVariantError();
	}
	std::get<runnable_data>(*m_data).m_security_level = security_level;
}

void ChatCommandBuilderBuilder::set_allow_console(Console allow_console) {
	if (!m_data) {
		m_data = runnable_data{};
	}
	if (std::holds_alternative<subcommand_data>(*m_data)) {
		throw IncompatibleVariantError();
	}
	std::get<runnable_data>(*m_data).m_allow_console = allow_console;
}

void ChatCommandBuilderBuilder::set_help(AcoreStrings help) {
	if (!m_data) {
		m_data = runnable_data{};
	}
	if (std::holds_alternative<subcommand_data>(*m_data)) {
		throw IncompatibleVariantError();
	}
	std::get<runnable_data>(*m_data).m_help = help;
}

typedef bool (*HandlerFn)(ChatHandler *, char const *);
HandlerFn dispatch_handler(size_t slot) {
#define BOOST_PP_LOCAL_MACRO(n) \
	if (slot == n) { \
		return exec_chat_command_in_slot<n>; \
	}
#define BOOST_PP_LOCAL_LIMITS (0, 1023)
#include BOOST_PP_LOCAL_ITERATE()
	throw TooManyCommandsError();
}

ChatCommandBuilder ChatCommandBuilderBuilder::build() {
	if (!m_data) {
		m_data = subcommand_data {};
	}
	if (std::holds_alternative<subcommand_data>(*m_data)) {
		auto & [builders, built] = std::get<subcommand_data>(*m_data);
		if (!built) {
			// the subcommand variant of ChatCommandBuilder stores only a REFERENCE to the vector of
			// children that we pass it, so that vector needs to be kept alive by some means other
			// than whatever keeps the resulting ChatCommandBuilder alive. typically, modules just
			// ignore the issue and give everything a static lifetime because they don't need to be
			// able to change the commands that they register dynamically. for us, since we register
			// our commands from Node.js scripts that can change dramatically while the server is
			// still running, that's just not possible for us.
			auto const built_range = builders
				| std::views::values
				| std::ranges::views::transform([](auto & b) { return b->build(); })
				;
			built = Subcommands{built_range.begin(), built_range.end()};
		}
		return {m_name.c_str(), *built};
	}
	if (
		auto const & [handler, security_level, allow_console, help] = std::get<runnable_data>(*m_data);
		handler && security_level && allow_console
	) {
		if (std::holds_alternative<v8::Global<v8::Function>>(*handler)) {
			throw IncompleteVariantError();
		}
		if (help) {
			return {m_name.c_str(), *dispatch_handler(std::get<size_t>(*handler)), *help, *security_level, *allow_console};
		}
		return {m_name.c_str(), *dispatch_handler(std::get<size_t>(*handler)), *security_level, *allow_console};
	}
	throw IncompleteVariantError();
}
