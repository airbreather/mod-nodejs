#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "DurationWrapper.h"
#include "GameEventMgr.h"
#include "Guild.h"
#include "JtoC.h"
#include "NodeJs.h"
#include "NodePropertySystem.h"
#include "UnixTimestamp.h"

void add_global_functions(TypedTemplate<NodeJs *> const ft) {
	// don't register these as static.
	reg_method(ft, "gc", [](NodeJs *) {
		NodeJs::instance()->run_garbage_collection_once();
	});
	reg_method(ft, "getFactionEntry", [](NodeJs *, uint32_t const entry) {
		return sFactionStore.LookupEntry(entry);
	});
	reg_method(ft, "getItemTemplate", [](NodeJs *, uint32_t const entry) {
		return sObjectMgr->GetItemTemplate(entry);
	});
	reg_method(ft, "getVehicleEntry", [](NodeJs *, uint32_t const entry) {
		return sVehicleStore.LookupEntry(entry);
	});
	reg_method(ft, "guidsEqual", [](NodeJs *, ObjectGuid const g1, ObjectGuid const g2) {
		return g1 == g2;
	});
	reg_method(ft, "decodeGuid", [](NodeJs *, ObjectGuid const g) {
		return jarr(std::array {
			static_cast<uint32_t>(g.GetHigh()),
			g.GetEntry(),
			g.GetCounter()
		});
	});
	reg_method(ft, "dbQueryAsync", [](NodeJs *, Db db, std::string s) {
		switch (db) {
			case Db::Character:
				return NodeJs::instance()->db_query_async<Db::Character>(s);

			case Db::Login:
				return NodeJs::instance()->db_query_async<Db::Login>(s);

			case Db::World:
				return NodeJs::instance()->db_query_async<Db::World>(s);

#ifdef MOD_PLAYERBOTS
			case Db::Playerbots:
				return NodeJs::instance()->db_query_async<Db::Playerbots>(s);
#endif
		}
		v8::Isolate::GetCurrent()->ThrowError("unrecognized db");
		return jnull().As<v8::Promise>();
	});
	reg_method(ft, "dbQuery", [](NodeJs *, Db d, std::string s) {
		switch (d) {
			case Db::Character:
				return db<Db::Character>().query(s);

			case Db::Login:
				return db<Db::Login>().query(s);

			case Db::World:
				return db<Db::World>().query(s);

#ifdef MOD_PLAYERBOTS
			case Db::Playerbots:
				return db<Db::Playerbots>().query(s);
#endif
		}
		v8::Isolate::GetCurrent()->ThrowError("unrecognized db");
		return QueryResult{};
	});
	reg_method(ft, "dbNonQuery", [](NodeJs *, Db d, std::string s) {
		switch (d) {
			case Db::Character:
				db<Db::Character>().execute_or_append(s);
				return;

			case Db::Login:
				db<Db::Login>().execute_or_append(s);
				return;

			case Db::World:
				db<Db::World>().execute_or_append(s);
				return;

#ifdef MOD_PLAYERBOTS
			case Db::Playerbots:
				db<Db::Playerbots>().execute_or_append(s);
				return;
#endif
		}
		v8::Isolate::GetCurrent()->ThrowError("unrecognized db");
	});
	reg_method(ft, "inTransaction", [](NodeJs *, Db d, v8::Local<v8::Function> f) {
		std::function<void()> fn = [f] {
			auto isolate = v8::Isolate::GetCurrent();
			auto ctx = isolate->GetCurrentContext();
			f->Call(ctx, jnull(), 0, nullptr)
				.FromMaybe(jnull());
		};
		switch (d) {
			case Db::Character:
				db<Db::Character>().transactional([& fn](auto const&){fn();});
				return;

			case Db::Login:
				db<Db::Login>().transactional([& fn](auto const&){fn();});
				return;

			case Db::World:
				db<Db::World>().transactional([& fn](auto const&){fn();});
				return;

#ifdef MOD_PLAYERBOTS
			case Db::Playerbots:
				db<Db::Playerbots>().transactional([& fn](auto const&){fn();});
				return;
#endif
		}
		v8::Isolate::GetCurrent()->ThrowError("unrecognized db");
	});
	reg_method(ft, "getCurrTime", [](NodeJs *) {
		return UnixTimestamp::from_game_time_milliseconds(getMSTime());
	});
	reg_method(ft, "getTimeDiff", [](NodeJs *, UnixTimestamp const before) {
		auto before_chrn = before.to_chrono<Milliseconds>();
		auto after_chrn = GetTimeMS();
		return DurationWrapper::from_chrono(after_chrn - before_chrn);
	});
	reg_method(ft, "isGameEventActive", [](NodeJs *, uint16_t const id) {
		return sGameEventMgr->IsActiveEvent(id);
	});
	reg_method(ft, "log", [](NodeJs *, LogLevel const level, std::string filter, std::string msg) {
		LOG_MESSAGE_BODY(filter, level, "{}", msg);
	});
	reg_method(ft, "logTrace", [](NodeJs *, std::string filter, std::string msg) {
		LOG_TRACE(filter, "{}", msg);
	});
	reg_method(ft, "logDebug", [](NodeJs *, std::string filter, std::string msg) {
		LOG_DEBUG(filter, "{}", msg);
	});
	reg_method(ft, "logInfo", [](NodeJs *, std::string filter, std::string msg) {
		LOG_INFO(filter, "{}", msg);
	});
	reg_method(ft, "logWarn", [](NodeJs *, std::string filter, std::string msg) {
		LOG_WARN(filter, "{}", msg);
	});
	reg_method(ft, "logError", [](NodeJs *, std::string filter, std::string msg) {
		LOG_ERROR(filter, "{}", msg);
	});
	reg_method(ft, "logFatal", [](NodeJs *, std::string filter, std::string msg) {
		LOG_FATAL(filter, "{}", msg);
	});
	reg_method(ft, "runCommandAsync", [](NodeJs *, std::string command, std::optional<bool> flush) {
		auto const isolate = v8::Isolate::GetCurrent();
		auto const ctx = isolate->GetCurrentContext();
		auto const prom = v8::Promise::Resolver::New(ctx).ToLocalChecked();
		auto resolver_ref = new v8::Global<v8::Promise::Resolver>(isolate, prom);
		using CapturedResolverRef = decltype(resolver_ref);
		sWorld->QueueCliCommand(new CliCommandHolder(resolver_ref, command.c_str(),
			[](void *, std::string_view str) {
				std::string s{str};
				s.erase(std::find_if(s.rbegin(), s.rend(), [](char c) {
					return !std::isspace(c);
				}).base(), s.end());
				LOG_INFO("nodejs.cmd", "{}", s);
			},
			[](void * resolver_ref_void, bool success) {
				auto const resolver_ref = static_cast<CapturedResolverRef>(resolver_ref_void);
				NodeJs::instance()->run_scoped([resolver_ref, success] {
					auto const isolate = v8::Isolate::GetCurrent();
					auto const ctx = isolate->GetCurrentContext();
					auto const resolver = resolver_ref->Get(isolate);
					delete resolver_ref;
					resolver->Resolve(ctx, jval(success)).Check();
				});
			}
		));
		if (flush && *flush) {
			sWorld->ProcessCliCommands();
		}
		return prom->GetPromise();
	});
	reg_method(ft, "saveAllPlayers", [](NodeJs *) {
		ObjectAccessor::SaveAllPlayers();
	});
	reg_method(ft, "box", [](NodeJs *, v8::Local<v8::Value> val) {
		return jobj(jprop("boxed", val));
	});
	reg_method(ft, "registerCommand", [](NodeJs *, ChatCommandBuilderBuilderBox * b) {
		NodeJs::instance()->reg_command(*b);
	});
	reg_method(ft, "shutdown", [](NodeJs *, uint32_t time, ShutdownMask options, uint8_t exit_code, std::optional<std::string> reason) {
		sWorld->ShutdownServ(time, options, exit_code, reason.value_or({}));
	});
	reg_method(ft, "hasPlayerbotsModule", [](NodeJs *) {
#ifdef MOD_PLAYERBOTS
		return true;
#endif
		return false;
	});
}
