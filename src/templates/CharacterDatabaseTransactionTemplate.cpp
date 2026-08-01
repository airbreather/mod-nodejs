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
		NodeJs::transactional(CharacterDatabase, [f](auto trans) {
			auto jtrans = jval(&trans);
			f->Call(v8::Isolate::GetCurrent()->GetCurrentContext(), jnull(), 1, &jtrans)
				.FromMaybe(jtrans); // just get rid of the warning
		});
	});

	reg_method(ft, "appendRaw", [](CharacterDatabaseTransaction * t, std::string cmd) {
		t->get()->Append(cmd);
	});

	return ft;
}
