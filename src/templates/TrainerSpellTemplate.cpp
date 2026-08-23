#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "NPCPackets.h"

using TrainerSpell = WorldPackets::NPC::TrainerListSpell;

JVAL_CVAL_TMPLS_RW(TrainerSpell)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<TrainerSpell *>() {
	TypedTemplate<TrainerSpell *> const ft = jctor([] {
		return new TrainerSpell;
	});

	ft->SetClassName(jstr_intern("TrainerSpell"));

	reg_prop(ft, "spellId",
		[](TrainerSpell * l) { return l->SpellID; },
		[](TrainerSpell * l, auto val) { l->SpellID = val; }
	);
	reg_prop(ft, "usable",
		[](TrainerSpell * l) { return l->Usable; },
		[](TrainerSpell * l, auto val) { l->Usable = val; }
	);
	reg_prop(ft, "moneyCost",
		[](TrainerSpell * l) { return l->MoneyCost; },
		[](TrainerSpell * l, auto val) { l->MoneyCost = val; }
	);
	reg_prop(ft, "isPrimaryProfessionFirstRank",
		[](TrainerSpell * l) { return l->PointCost[1] != 0; },
		[](TrainerSpell * l, auto val) { l->PointCost[1] = val ? 1 : 0; }
	);
	reg_prop(ft, "reqLevel",
		[](TrainerSpell * l) { return l->ReqLevel; },
		[](TrainerSpell * l, auto val) { l->ReqLevel = val; }
	);
	reg_prop(ft, "reqSkillLine",
		[](TrainerSpell * l) { return l->ReqSkillLine; },
		[](TrainerSpell * l, auto val) { l->ReqSkillLine = val; }
	);
	reg_prop(ft, "reqSkillRank",
		[](TrainerSpell * l) { return l->ReqSkillRank; },
		[](TrainerSpell * l, auto val) { l->ReqSkillRank = val; }
	);
	reg_prop(ft, "reqAbility0",
		[](TrainerSpell * l) { return l->ReqAbility[0]; },
		[](TrainerSpell * l, auto val) { l->ReqAbility[0] = val; }
	);
	reg_prop(ft, "reqAbility1",
		[](TrainerSpell * l) { return l->ReqAbility[1]; },
		[](TrainerSpell * l, auto val) { l->ReqAbility[1] = val; }
	);
	reg_prop(ft, "reqAbility2",
		[](TrainerSpell * l) { return l->ReqAbility[2]; },
		[](TrainerSpell * l, auto val) { l->ReqAbility[2] = val; }
	);

	return ft;
}
