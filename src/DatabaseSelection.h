#ifndef MOD_NODEJS_DATABASESELECTION_H
#define MOD_NODEJS_DATABASESELECTION_H

#include <cstdint>

enum class DatabaseSelection : uint8_t {
	Character = 0,
	Login = 1,
	World = 2,
#ifdef MOD_PLAYERBOTS
	Playerbots = 3,
#endif
};

#endif //MOD_NODEJS_DATABASESELECTION_H
