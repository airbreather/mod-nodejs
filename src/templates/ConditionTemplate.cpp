#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "Chat/Chat.h"

class Player;

JVAL_CVAL_TMPLS_RW(Condition)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Condition *>() {
	TypedTemplate<Condition *> const ft = jctor([] {
		return new Condition();
	});

	ft->SetClassName(jstr_intern("Condition"));

	reg_prop_ro(ft, "isLoaded", [](Condition * c) {
		return c->isLoaded();
	});
	reg_prop_ro(ft, "searcherTypeMaskForCondition", [](Condition * c) {
		return c->GetSearcherTypeMaskForCondition();
	});
	reg_prop_ro(ft, "maxAvailableConditionTargets", [](Condition * c) {
		return c->GetMaxAvailableConditionTargets();
	});

	reg_method(ft, "meets", [](Condition * c, ConditionSourceInfo * source_info) {
		return c->Meets(*source_info);
	});

	reg_prop(ft, "sourceType",
		[](Condition * c) { return c->SourceType; },
		[](Condition * c, auto v) { c->SourceType = v; }
	);
	reg_prop(ft, "sourceGroup",
		[](Condition * c) { return c->SourceGroup; },
		[](Condition * c, auto v) { c->SourceGroup = v; }
	);
	reg_prop(ft, "sourceEntry",
		[](Condition * c) { return c->SourceEntry; },
		[](Condition * c, auto v) { c->SourceEntry = v; }
	);
	reg_prop(ft, "sourceId",
		[](Condition * c) { return c->SourceId; },
		[](Condition * c, auto v) { c->SourceId = v; }
	);
	reg_prop(ft, "elseGroup",
		[](Condition * c) { return c->ElseGroup; },
		[](Condition * c, auto v) { c->ElseGroup = v; }
	);
	reg_prop(ft, "conditionType",
		[](Condition * c) { return c->ConditionType; },
		[](Condition * c, auto v) { c->ConditionType = v; }
	);
	reg_prop(ft, "conditionValue1",
		[](Condition * c) { return c->ConditionValue1; },
		[](Condition * c, auto v) { c->ConditionValue1 = v; }
	);
	reg_prop(ft, "conditionValue2",
		[](Condition * c) { return c->ConditionValue2; },
		[](Condition * c, auto v) { c->ConditionValue2 = v; }
	);
	reg_prop(ft, "conditionValue3",
		[](Condition * c) { return c->ConditionValue3; },
		[](Condition * c, auto v) { c->ConditionValue3 = v; }
	);
	reg_prop(ft, "errorType",
		[](Condition * c) { return c->ErrorType; },
		[](Condition * c, auto v) { c->ErrorType = v; }
	);
	reg_prop(ft, "errorTextId",
		[](Condition * c) { return c->ErrorTextId; },
		[](Condition * c, auto v) { c->ErrorTextId = v; }
	);
	reg_prop(ft, "referenceId",
		[](Condition * c) { return c->ReferenceId; },
		[](Condition * c, auto v) { c->ReferenceId = v; }
	);
	reg_prop(ft, "scriptId",
		[](Condition * c) { return c->ScriptId; },
		[](Condition * c, auto v) { c->ScriptId = v; }
	);
	reg_prop(ft, "conditionTarget",
		[](Condition * c) { return c->ConditionTarget; },
		[](Condition * c, auto v) { c->ConditionTarget = v; }
	);
	reg_prop(ft, "negativeCondition",
		[](Condition * c) { return c->NegativeCondition; },
		[](Condition * c, auto v) { c->NegativeCondition = v; }
	);

	return ft;
}
