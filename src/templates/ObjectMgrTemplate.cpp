#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "DurationWrapper.h"
#include "NodePropertySystem.h"
#include "ObjectMgr.h"
#include "Player.h"

JVAL_CVAL_TMPLS_RW(ObjectMgr)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<ObjectMgr *>() {
	TypedTemplate<ObjectMgr *> const ft = jctor();

	ft->SetClassName(jstr_intern("ObjectMgr"));

	reg_static_method(ft, "getNpcVendorItemList", [](uint32_t vendor) {
		return ObjectMgr::instance()->GetNpcVendorItemList(vendor);
	});
	reg_static_method(ft, "setNpcVendorItemList", [](uint32_t vendor, VendorItemData * data, std::optional<bool> persist) {
		// mod-nodejs invention
		if (auto old_data = ObjectMgr::instance()->GetNpcVendorItemList(vendor)) {
			std::vector old_items(old_data->m_items);
			for (auto item : old_items) {
				ObjectMgr::instance()->RemoveVendorItem(vendor, item->item, persist.value_or(true));
			}
		}
		for (auto item : data->m_items) {
			ObjectMgr::instance()->AddVendorItem(vendor, item->item, item->maxcount, item->incrtime, item->ExtendedCost, persist.value_or(true));
		}
	});
	reg_static_method(ft, "addVendorItem", [](uint32_t vendor, uint32_t item, uint32_t max_count, DurationWrapper incr_time, uint32_t extended_cost, std::optional<bool> persist) {
		ObjectMgr::instance()->AddVendorItem(vendor, item, max_count, incr_time.count<Seconds>(), extended_cost, persist.value_or(true));
	});
	reg_static_method(ft, "removeVendorItem", [](uint32_t vendor, uint32_t item, std::optional<bool> persist) {
		ObjectMgr::instance()->RemoveVendorItem(vendor, item, persist.value_or(true));
	});

	return ft;
}
