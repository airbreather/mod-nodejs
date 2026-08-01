#ifndef MOD_NODEJS_DATABASESELECTION_H
#define MOD_NODEJS_DATABASESELECTION_H

#include <cstdint>
#include <v8-isolate.h>

#include "DatabaseWorkerPool.h"

class MySQLConnection;
class CharacterDatabaseConnection;
class LoginDatabaseConnection;
class WorldDatabaseConnection;

enum class Db : uint8_t {
	Character = 0,
	Login = 1,
	World = 2,
#ifdef MOD_PLAYERBOTS
	Playerbots = 3,
#endif
};

template <Db Db>
struct db_connection;

template <Db Db> using db_connection_t = db_connection<Db>::type;
template <Db Db> using db_worker_t = DatabaseWorkerPool<db_connection_t<Db>>;
template <Db Db> using db_transaction_t = SQLTransaction<db_connection_t<Db>>;

template <Db Db>
db_transaction_t<Db> & current_transaction();

template <Db Db>
struct DatabaseProxy {
	db_worker_t<Db> & worker();
	db_transaction_t<Db> begin_transaction() { return worker().BeginTransaction(); }
	void commit_transaction(db_transaction_t<Db> && trans) { return worker().CommitTransaction(std::move(trans)); }
	void execute_or_append(std::string_view s) { worker().ExecuteOrAppend(current_transaction<Db>(), s); }
	QueryResult query(std::string_view s) { return worker().Query(s); }

	template <typename F>
	requires std::is_void_v<std::invoke_result_t<F, db_transaction_t<Db> &&>>
	void transactional(F && fn) {
		auto & tv = current_transaction<Db>();
		auto create_transaction = tv == nullptr;
		auto trans = create_transaction
			? tv = worker().BeginTransaction()
			: tv;
		auto isolate = v8::Isolate::GetCurrent();
		v8::TryCatch try_catch(isolate);
		fn(std::move(trans));
		if (create_transaction) {
			if (!try_catch.HasCaught()) {
				worker().CommitTransaction(std::move(tv));
			}
			tv.reset();
		}
		if (try_catch.HasCaught()) {
			try_catch.ReThrow();
		}
	}
};

#endif //MOD_NODEJS_DATABASESELECTION_H

template <Db Db>
DatabaseProxy<Db> db() { return {}; }

template <>
struct db_connection<Db::Character> {
	using type = CharacterDatabaseConnection;
};

template <>
struct db_connection<Db::Login> {
	using type = LoginDatabaseConnection;
};

template <>
struct db_connection<Db::World> {
	using type = WorldDatabaseConnection;
};

#ifdef MOD_PLAYERBOTS
template <>
struct db_connection<Db::Playerbots> {
	using type = PlayerbotsDatabaseConnection;
};
#endif
