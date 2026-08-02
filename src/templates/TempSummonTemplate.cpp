#include <v8-local-handle.h>
#include <v8-template.h>

#include "Creature.h"
#include "CtoJ.h"
#include "DurationWrapper.h"
#include "NodePropertySystem.h"
#include "TemporarySummon.h"

JVAL_CVAL_TMPLS_RW(TempSummon)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<TempSummon *>() {
	TypedTemplate<TempSummon *> const ft = jctor();

	ft->SetClassName(jstr_intern("TempSummon"));
	ft.safe_inherit<Creature *>();

	reg_prop_ro(ft, "summoner", [](TempSummon * tempSummon) {
		return tempSummon->GetSummoner();
	});
	reg_prop_ro(ft, "properties", [](TempSummon * tempSummon) {
		return tempSummon->m_Properties;
	});

	reg_prop(ft, "isVisibleBySummonerOnly",
		[](TempSummon * tempSummon) { return tempSummon->IsVisibleBySummonerOnly(); },
		[](TempSummon * tempSummon, bool const visibleBySummonerOnly) { tempSummon->SetVisibleBySummonerOnly(visibleBySummonerOnly); }
	);
	reg_prop(ft, "timer",
		[](TempSummon * tempSummon) { return DurationWrapper::from_milliseconds(tempSummon->GetTimer()); },
		[](TempSummon * tempSummon, DurationWrapper const t) { tempSummon->SetTimer(t.count<Milliseconds>()); }
	);
	reg_prop(ft, "summonType",
		[](TempSummon * tempSummon) { return tempSummon->GetSummonType(); },
		[](TempSummon * tempSummon, auto v) { tempSummon->SetTempSummonType(v); }
	);

	reg_method(ft, "unsummon", [](TempSummon * s, std::optional<DurationWrapper> delay) {
		if (delay) {
			s->UnSummon(delay->to_chrono<Milliseconds>());
		} else {
			s->UnSummon();
		}
	});

	return ft;
}
