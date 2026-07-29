#include <algorithm>
#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>
#include <vector>

#include "CtoJ.h"
#include "Define.h"
#include "ItemTemplate.h"
#include "LootMgr.h"
#include "NodePropertySystem.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "Random.h"

JVAL_CVAL_TMPLS_RW(Loot)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Loot *>() {
	TypedTemplate<Loot *> const ft = jctor<Loot *>();

	ft->SetClassName(jstr_intern("Loot"));

	reg_prop_ro(ft, "itemCount", [](Loot * loot) {
		return uint32_t{loot->items.size() + loot->quest_items.size()};
	});
	reg_prop_ro(ft, "isLooted", [](Loot * loot) {
		return loot->isLooted();
	});
	reg_prop_ro(ft, "isEmpty", [](Loot * loot) {
		return loot->empty();
	});
	reg_prop_ro(ft, "hasQuestItems", [](Loot * loot) {
		return !loot->quest_items.empty();
	});
	reg_prop_ro(ft, "hasItemForAll", [](Loot * loot) {
		return loot->hasItemForAll();
	});
	reg_prop_ro(ft, "hasOverThresholdItem", [](Loot * loot) {
		return loot->hasOverThresholdItem();
	});
	reg_prop_ro(ft, "items", [](Loot * loot) {
		return jarr(loot->items);
	});
	reg_prop_ro(ft, "questItems", [](Loot * loot) {
		return jarr(loot->quest_items);
	});

	reg_method(ft, "getMaxSlotForPlayer", [](Loot * loot, Player * player) {
		return loot->GetMaxSlotInLootFor(player);
	});
	reg_method(ft, "hasItem", [](Loot * loot, std::optional<uint32_t> const item_id, std::optional<uint32_t> const count) {
		if (!item_id) {
			return std::ranges::any_of(loot->items, [](LootItem const & li) {
				return li.itemid != 0;
			});
		}
		auto const item_id_val = *item_id;
		if (!count) {
			return std::ranges::any_of(loot->items, [item_id_val](LootItem const & li) {
				return li.itemid == item_id_val;
			});
		}
		auto const count_val = *count;
		return std::ranges::any_of(loot->items, [item_id_val, count_val](LootItem const & li) {
			return li.itemid == item_id_val && li.count == count_val;
		});
	});

	reg_prop(ft, "gold",
		[](Loot * loot) { return loot->gold; },
		[](Loot * loot, uint32_t const val) { loot->gold = val; }
	);
	reg_prop(ft, "unlootedCount",
		[](Loot * loot) { return loot->unlootedCount; },
		[](Loot * loot, uint8_t const val) { loot->unlootedCount = val; }
	);
	reg_prop(ft, "lootType",
		[](Loot * loot) { return loot->loot_type; },
		[](Loot * loot, LootType const val) {
			if (val <= LOOT_FISHING_JUNK) {
				loot->loot_type = val;
			}
		}
	);
	reg_prop(ft, "roundRobinPlayer",
		[](Loot * loot) { return loot->roundRobinPlayer; },
		[](Loot * loot, ObjectGuid const val) { loot->roundRobinPlayer = val; }
	);
	reg_prop(ft, "lootOwnerGuid",
		[](Loot * loot) { return loot->lootOwnerGUID; },
		[](Loot * loot, ObjectGuid const val) { loot->lootOwnerGUID = val; }
	);
	reg_prop(ft, "containerGuid",
		[](Loot * loot) { return loot->containerGUID; },
		[](Loot * loot, ObjectGuid const val) { loot->containerGUID = val; }
	);
	reg_prop(ft, "sourceWorldObjectGuid",
		[](Loot * loot) { return loot->sourceWorldObjectGUID; },
		[](Loot * loot, ObjectGuid const val) { loot->sourceWorldObjectGUID = val; }
	);

	reg_method(ft, "addItem", [](Loot * loot, uint32_t const item_id, uint32_t const min_count, uint32_t const max_count, float const chance, uint16_t const loot_mode, std::optional<bool> const needs_quest, std::optional<bool> const allow_stacking, std::optional<uint32_t> max_stack_size) {
		// roll for the amount ourselves - LootStoreItem min/max are uint8_t
		auto amount = urand(min_count, max_count);
		if (!amount) {
			// min_count was 0, and we rolled 0
			return;
		}
		if (!max_stack_size) {
			if (auto const proto = sObjectMgr->GetItemTemplate(item_id)) {
				max_stack_size = std::optional(proto->GetMaxStackSize());
			} else {
				return;
			}
		}
		auto & items = needs_quest.value_or(false) ? loot->quest_items : loot->items;
		if (allow_stacking.value_or(true)) {
			// first, fill all stacks that we can.
			for (auto & existing_stack : items) {
				if (existing_stack.itemid != item_id || existing_stack.count >= *max_stack_size) {
					continue;
				}
				auto const room = *max_stack_size - existing_stack.count;
				if (amount <= room) {
					// all the rest of what we rolled can fit cleanly into this existing stack.
					// no need to create any new ones, just fill it up a bit and call it a day.
					existing_stack.count += amount;
					return;
				}
				existing_stack.count = *max_stack_size;
				amount -= room;
			}
		}
		// we have to check this ourselves to know whether items.back() will silently be something unrelated.
		const size_t limit = needs_quest.value_or(false) ? MAX_NR_QUEST_ITEMS : MAX_NR_LOOT_ITEMS;
		while (amount > 0 && items.size() < limit) {
			const LootStoreItem storeItem(item_id, 0, chance, needs_quest.value_or(false), loot_mode, 0, 1, 1);
			loot->AddItem(storeItem);
			auto const stack_size = std::min(amount, *max_stack_size);
			amount -= stack_size;
			items.back().count = stack_size;
		}
	});
	reg_method(ft, "removeItem", [](Loot * loot, uint32_t const item_id, std::optional<uint32_t> const count) {
		if (!count) {
			std::erase_if(loot->items, [&](LootItem const & item) { return item.itemid == item_id; });
			std::erase_if(loot->quest_items, [&](LootItem const & item) { return item.itemid == item_id; });
			return;
		}
		auto remaining = *count;
		auto erase_them = [& item_id, & remaining](std::vector<LootItem> v) {
			for (auto it = v.end() - 1; remaining && it >= v.begin(); --it) {
				if (it->itemid != item_id) {
					continue;
				}
				if (it->count > remaining) {
					it->count -= remaining;
					remaining = 0;
				} else {
					remaining -= it->count;
					v.erase(it);
				}
			}
		};
		erase_them(loot->items);
		erase_them(loot->quest_items);
	});
	reg_method(ft, "clear", [](Loot * loot) {
		loot->clear();
	});
	reg_method(ft, "generateMoney", [](Loot * loot, uint32_t const min, uint32_t const max) {
		loot->generateMoneyLoot(min, max);
	});
	reg_method(ft, "setItemLooted", [](Loot * loot, uint32_t const itemId, uint32_t const count, bool const looted) {
		for (auto & li : loot->items) {
			if (li.itemid == itemId && li.count == count) {
				li.is_looted = looted;
				break;
			}
		}
	});
	reg_method(ft, "addLooter", [](Loot * loot, ObjectGuid const guid) {
		loot->AddLooter(guid);
	});
	reg_method(ft, "removeLooter", [](Loot * loot, ObjectGuid const guid) {
		loot->RemoveLooter(guid);
	});

	return ft;
}
