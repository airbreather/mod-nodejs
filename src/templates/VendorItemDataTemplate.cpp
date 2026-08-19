#include <v8-local-handle.h>
#include <v8-template.h>

#include "CreatureData.h"
#include "CtoJ.h"
#include "DurationWrapper.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RW(VendorItemData)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<VendorItemData *>() {
	TypedTemplate<VendorItemData *> const ft = jctor([] {
		return new VendorItemData();
	});

	ft->SetClassName(jstr_intern("VendorItemData"));

	reg_prop_ro(ft, "empty", [](VendorItemData * vd) {
		return vd->Empty();
	});
	reg_prop_ro(ft, "itemCount", [](VendorItemData * vd) {
		return vd->GetItemCount();
	});
	reg_prop_ro(ft, "items", [](VendorItemData * vd) {
		return jarr(vd->m_items);
	});

	reg_method(ft, "append", [](VendorItemData * vd, VendorItem * vi) {
		vd->m_items.push_back(vi);
	});
	reg_method(ft, "addItem", [](VendorItemData * vd, uint32_t item, int32_t max_count, DurationWrapper incr_time, uint32_t extended_cost) {
		vd->AddItem(item, max_count, incr_time.count<Seconds>(), extended_cost);
	});
	reg_method(ft, "removeItem", [](VendorItemData * vd, uint32_t item) {
		return vd->RemoveItem(item);
	});
	reg_method(ft, "findItemCostPair", [](VendorItemData * vd, uint32_t item, uint32_t extended_cost) {
		return vd->FindItemCostPair(item, extended_cost);
	});
	reg_method(ft, "clear", [](VendorItemData * vd) {
		vd->Clear();
	});
	reg_method(ft, "clone", [](VendorItemData * vd) {
		auto const & copy_from = vd->m_items;
		std::vector<VendorItem *> copy_to;
		copy_to.reserve(copy_from.size());
		for (auto item : copy_from) {
			copy_to.push_back(new VendorItem{ *item });
		}
		return jmove(new VendorItemData{copy_to});
	});

	return ft;
}
