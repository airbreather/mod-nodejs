#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "NPCPackets.h"

using TrainerSpell = WorldPackets::NPC::TrainerListSpell;
using TrainerSpellList = std::vector<TrainerSpell>;

JVAL_CVAL_TMPLS_RW(TrainerSpellList)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<TrainerSpellList *>() {
	TypedTemplate<TrainerSpellList *> const ft = jctor([](std::optional<v8::Local<v8::Array>> spells) -> TrainerSpellList * {
		if (!spells) {
			return new TrainerSpellList;
		}
		auto cspells = cval_arr<TrainerSpell *>(*spells);
		if (!cspells) {
			v8::Isolate::GetCurrent()->ThrowError("Failed to convert spells.");
			return nullptr;
		}
		auto result = new TrainerSpellList;
		result->reserve(cspells->size());
		for (auto spell : *cspells) {
			result->emplace_back(*spell);
		}

		return result;
	});

	ft->SetClassName(jstr_intern("TrainerSpellList"));

	reg_prop_ro(ft, "size", [](TrainerSpellList * l) {
		return l->size();
	});

	reg_method(ft, "clear", [](TrainerSpellList * l) {
		l->clear();
	});
	reg_method(ft, "get", [](TrainerSpellList * l, uint32_t i) -> TrainerSpell * {
		if (i >= l->size()) {
			v8::Isolate::GetCurrent()->ThrowError("Invalid index.");
			return nullptr;
		}
		return &l->at(i);
	});
	reg_method(ft, "set", [](TrainerSpellList * l, uint32_t i, TrainerSpell * spell) {
		if (i >= l->size()) {
			v8::Isolate::GetCurrent()->ThrowError("Invalid index.");
			return;
		}
		l->emplace(l->begin() + i, *spell);
	});
	reg_method(ft, "add", [](TrainerSpellList * l, TrainerSpell * spell) {
		l->emplace_back(*spell);
	});
	reg_method(ft, "delete", [](TrainerSpellList * l, uint32_t i) {
		if (i >= l->size()) {
			v8::Isolate::GetCurrent()->ThrowError("Invalid index.");
			return;
		}
		l->erase(l->begin() + i);
	});
	reg_method(ft, "toArray", [](TrainerSpellList * l) {
		return jarr(*l);
	});

	return ft;
}
