#include <v8-local-handle.h>
#include <v8-template.h>

#include "CreatureData.h"
#include "CtoJ.h"
#include "DurationWrapper.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RW(VendorItem)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<VendorItem *>() {
	TypedTemplate<VendorItem *> const ft = jctor([](uint32_t item, int32_t max_count, DurationWrapper incr_time, uint32_t extended_cost) {
		return new VendorItem(item, max_count, incr_time.count<Seconds>(), extended_cost);
	});

	ft->SetClassName(jstr_intern("VendorItem"));

	reg_prop(ft, "itemId",
		[](VendorItem * vi) { return vi->item; },
		[](VendorItem * vi, auto val) { vi->item = val; }
	);
	reg_prop(ft, "maxCount",
		[](VendorItem * vi) { return vi->maxcount; },
		[](VendorItem * vi, auto val) { vi->maxcount = val; }
	);
	reg_prop(ft, "incrTime",
		[](VendorItem * vi) { return DurationWrapper::from_chrono(Seconds{vi->incrtime}); },
		[](VendorItem * vi, DurationWrapper val) { vi->incrtime = val.count<Seconds>(); }
	);
	reg_prop(ft, "extendedCost",
		[](VendorItem * vi) { return vi->ExtendedCost; },
		[](VendorItem * vi, auto val) { vi->ExtendedCost = val; }
	);

	reg_method(ft, "isGoldRequired", [](VendorItem * vi, ItemTemplate const * proto) {
		return vi->IsGoldRequired(proto);
	});

	return ft;
}
