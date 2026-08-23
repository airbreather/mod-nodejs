#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "NPCPackets.h"

using TrainerSpellListMessage = WorldPackets::NPC::TrainerList;

JVAL_CVAL_TMPLS_RW(TrainerSpellListMessage)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<TrainerSpellListMessage *>() {
	TypedTemplate<TrainerSpellListMessage *> const ft = jctor();

	ft->SetClassName(jstr_intern("TrainerSpellListMessage"));

	reg_prop_ro(ft, "spells", [](TrainerSpellListMessage * l) {
		return &l->Spells;
	});

	reg_prop(ft, "trainerGuid",
		[](TrainerSpellListMessage * l) { return l->TrainerGUID; },
		[](TrainerSpellListMessage * l, auto val) { l->TrainerGUID = val; }
	);
	reg_prop(ft, "trainerType",
		[](TrainerSpellListMessage * l) { return l->TrainerType; },
		[](TrainerSpellListMessage * l, auto val) { l->TrainerType = val; }
	);
	reg_prop(ft, "greeting",
		[](TrainerSpellListMessage * l) { return l->Greeting; },
		[](TrainerSpellListMessage * l, auto val) { l->Greeting = val; }
	);

	return ft;
}
