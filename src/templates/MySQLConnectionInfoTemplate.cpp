#include "CtoJ.h"
#include "DatabaseEnv.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RO(MySQLConnectionInfo const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<MySQLConnectionInfo const *>() {
	TypedTemplate<MySQLConnectionInfo const *> const ft = jctor([](std::string conn) {
		return new MySQLConnectionInfo(conn);
	});

	ft->SetClassName(jstr_intern("MySQLConnectionInfo"));

	reg_static_method(ft, "forDb", [](Db db) -> MySQLConnectionInfo const * {
		switch (db) {
			case Db::Character:
				return CharacterDatabase.GetConnectionInfo();

			case Db::Login:
				return LoginDatabase.GetConnectionInfo();

			case Db::World:
				return WorldDatabase.GetConnectionInfo();

			default:
				v8::Isolate::GetCurrent()->ThrowError("Db not found");
				return nullptr;
		}
	});

	reg_prop_ro(ft, "user", [](MySQLConnectionInfo const * i) -> std::string const & {
		return i->user;
	});
	reg_prop_ro(ft, "password", [](MySQLConnectionInfo const * i) -> std::string const & {
		return i->password;
	});
	reg_prop_ro(ft, "database", [](MySQLConnectionInfo const * i) -> std::string const & {
		return i->database;
	});
	reg_prop_ro(ft, "host", [](MySQLConnectionInfo const * i) -> std::string const & {
		return i->host;
	});
	reg_prop_ro(ft, "port_or_socket", [](MySQLConnectionInfo const * i) -> std::string const & {
		return i->port_or_socket;
	});
	reg_prop_ro(ft, "ssl", [](MySQLConnectionInfo const * i) -> std::string const & {
		return i->ssl;
	});

	return ft;
}
