#include "Db.h"

#include "DatabaseEnv.h"

template <>
decltype(CharacterDatabase) & DatabaseProxy<Db::Character>::worker() {
	return CharacterDatabase;
}

template <>
decltype(LoginDatabase) & DatabaseProxy<Db::Login>::worker() {
	return LoginDatabase;
}

template <>
decltype(WorldDatabase) & DatabaseProxy<Db::World>::worker() {
	return WorldDatabase;
}

#ifdef MOD_PLAYERBOTS
template <>
decltype(PlayerbotsDatabase) & DatabaseProxy<Db::Playerbots>::worker() {
	return PlayerbotsDatabase;
}
#endif

static CharacterDatabaseTransaction character_db_transaction = nullptr;
static LoginDatabaseTransaction login_db_transaction = nullptr;
static WorldDatabaseTransaction world_db_transaction = nullptr;
#ifdef MOD_PLAYERBOTS
static PlayerbotsDatabaseTransaction playerbots_db_transaction = nullptr;
#endif

template<>
CharacterDatabaseTransaction & current_transaction<Db::Character>() {
	return character_db_transaction;
}

template<>
LoginDatabaseTransaction & current_transaction<Db::Login>() {
	return login_db_transaction;
}

template<>
WorldDatabaseTransaction & current_transaction<Db::World>() {
	return world_db_transaction;
}

#ifdef MOD_PLAYERBOTS
template<>
PlayerbotsDatabaseTransaction & current_transaction<Db::Playerbots>() {
	return playerbots_db_transaction;
}
#endif
