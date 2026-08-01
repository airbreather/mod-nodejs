#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "Chat/Chat.h"

JVAL_CVAL_TMPLS_RW(CharacterDatabaseTransaction)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<CharacterDatabaseTransaction *>() {
	TypedTemplate<CharacterDatabaseTransaction *> const ft = jctor();

	ft->SetClassName(jstr_intern("CharacterDatabaseTransaction"));

	reg_static_method(ft, "runSync", [](v8::Local<v8::Function> f) {
		auto const isolate = v8::Isolate::GetCurrent();
		if (!NodeJs::instance()->enter_transaction(CharacterDatabase)) {
			isolate->ThrowError("Already in a transaction (MySQL does not support nesting).");
			return;
		}
		v8::TryCatch try_catch(isolate);
		auto trans = *NodeJs::instance()->current_transaction(CharacterDatabase);
		auto jtrans = jval(trans);
		auto fail = f->Call(isolate->GetCurrentContext(), jnull(), 1, &jtrans).IsEmpty();
		if (fail) {
			try_catch.ReThrow();
		} else {
			CharacterDatabase.CommitTransaction(*trans);
		}
		NodeJs::instance()->exit_transaction(std::move(*trans));
	});

	reg_method(ft, "appendRaw", [](CharacterDatabaseTransaction * t, std::string cmd) {
		t->get()->Append(cmd);
	});

	return ft;
}
