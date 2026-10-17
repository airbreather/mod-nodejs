#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using MeetingStoneData = decltype(GameObjectTemplate().meetingstone);
JVAL_CVAL_TMPLS_RO(MeetingStoneData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<MeetingStoneData const *>() {
	TypedTemplate<MeetingStoneData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("MeetingStoneData"));

	reg_prop_ro(ft, "minLevel", [](MeetingStoneData const * s) {
		return s->minLevel;
	});
	reg_prop_ro(ft, "maxLevel", [](MeetingStoneData const * s) {
		return s->maxLevel;
	});
	reg_prop_ro(ft, "areaId", [](MeetingStoneData const * s) {
		return s->areaID;
	});

	return ft;
}
