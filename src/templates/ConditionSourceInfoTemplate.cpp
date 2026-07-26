#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "Chat/Chat.h"

JVAL_CVAL_TMPLS_RW(ConditionSourceInfo)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<ConditionSourceInfo *>() {
	TypedTemplate<ConditionSourceInfo *> const ft = jctor([](WorldObject * target0, std::optional<WorldObject *> target1, std::optional<WorldObject *> target2) {
		return new ConditionSourceInfo(target0, target1.value_or(nullptr), target2.value_or(nullptr));
	});

	ft->SetClassName(jstr_intern("ConditionSourceInfo"));

	reg_prop(ft, "target0",
		[](ConditionSourceInfo * c) { return c->mConditionTargets[0]; },
		[](ConditionSourceInfo * c, auto v) { c->mConditionTargets[0] = v; }
	);
	reg_prop(ft, "target1",
		[](ConditionSourceInfo * c) { return c->mConditionTargets[1]; },
		[](ConditionSourceInfo * c, auto v) { c->mConditionTargets[1] = v; }
	);
	reg_prop(ft, "target2",
		[](ConditionSourceInfo * c) { return c->mConditionTargets[2]; },
		[](ConditionSourceInfo * c, auto v) { c->mConditionTargets[2] = v; }
	);
	reg_prop(ft, "lastFailedCondition",
		[](ConditionSourceInfo * c) { return c->mLastFailedCondition; },
		[](ConditionSourceInfo * c, auto v) { c->mLastFailedCondition = v; }
	);

	return ft;
}
