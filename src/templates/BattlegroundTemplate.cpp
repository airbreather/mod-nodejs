#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "Battleground.h"
#include "CtoJ.h"
#include "NodePropertySystem.h"

enum TeamId : uint8_t;

JVAL_CVAL_TMPLS_RW(Battleground)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Battleground *>() {
	TypedTemplate<Battleground *> const ft = jctor();

	ft->SetClassName(jstr_intern("Battleground"));

	reg_prop_ro(ft, "name", [](Battleground * bg) {
		return bg->GetName();
	});
	reg_prop_ro(ft, "instanceId", [](Battleground * bg) {
		return bg->GetInstanceID();
	});
	reg_prop_ro(ft, "mapId", [](Battleground * bg) {
		return bg->GetMapId();
	});
	reg_prop_ro(ft, "battlegroundTypeId", [](Battleground * bg) {
		return bg->GetBgTypeID();
	});
	reg_prop_ro(ft, "playerScores", [](Battleground * bg) {
		return jmap(*bg->GetPlayerScores());
	});

	reg_method(ft, "getPlayersCountByTeam", [](Battleground * bg, TeamId const team_id) {
		return bg->GetPlayersCountByTeam(team_id);
	});
	reg_method(ft, "getAlivePlayersCountByTeam", [](Battleground * bg, TeamId const team_id) {
		return bg->GetAlivePlayersCountByTeam(team_id);
	});

	reg_prop(ft, "isRandom",
		[](Battleground * bg) { return bg->IsRandom(); },
		[](Battleground * bg, bool const is_random) { bg->SetRandom(is_random); }
	);

	return ft;
}
