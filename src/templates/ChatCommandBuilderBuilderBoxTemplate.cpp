#include <optional>
#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "ChatCommandBuilderBuilder.h"
#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "Chat/Chat.h"

JVAL_CVAL_TMPLS_RW(ChatCommandBuilderBuilderBox)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<ChatCommandBuilderBuilderBox *>() {
	TypedTemplate<ChatCommandBuilderBuilderBox *> const ft = jctor([](std::string name) {
		ChatCommandBuilderBuilder builder(std::move(name));
		auto box = std::make_shared<ChatCommandBuilderBuilder>(std::move(builder));
		return new ChatCommandBuilderBuilderBox(std::move(box));
	});

	ft->SetClassName(jstr_intern("ChatCommandBuilder"));

	reg_method(ft, "withSubcommand", [](ChatCommandBuilderBuilderBox * b, ChatCommandBuilderBuilderBox * sub) {
		b->get()->add_subcommand(*sub);
		return b;
	});
	reg_method(ft, "withHandler", [](ChatCommandBuilderBuilderBox * b, v8::Local<v8::Function> cb) {
		b->get()->set_handler(cb);
		return b;
	});
	reg_method(ft, "withSecurityLevel", [](ChatCommandBuilderBuilderBox * b, AccountTypes sec) {
		b->get()->set_security_level(sec);
		return b;
	});
	reg_method(ft, "withAllowConsole", [](ChatCommandBuilderBuilderBox * b, Acore::ChatCommands::Console allow) {
		b->get()->set_allow_console(allow);
		return b;
	});
	reg_method(ft, "withHelp", [](ChatCommandBuilderBuilderBox * b, AcoreStrings help) {
		b->get()->set_help(help);
		return b;
	});

	return ft;
}
