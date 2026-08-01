#include <array>
#include <optional>
#include <sstream>
#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "ItemTemplate.h"
#include "Bag.h"
#include "Common.h"
#include "CtoJ.h"
#include "DatabaseEnv.h"
#include "DatabaseWorkerPool.h"
#include "DBCStore.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "Define.h"
#include "Item.h"
#include "NodePropertySystem.h"
#include "Object.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QuestDef.h"
#include "SharedDefines.h"

JVAL_CVAL_TMPLS_RW(Item)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Item *>() {
	TypedTemplate<Item *> const ft = jctor();

	ft->SetClassName(jstr_intern("Item"));
 	ft.safe_inherit<Object *>();

	reg_static_method(ft, "create", [](uint32_t entry, uint32_t count, std::optional<Player *> player, std::optional<uint32_t> random_property_id, std::optional<bool> temp) {
		return jmove(Item::CreateItem(entry, count, player.value_or(nullptr), false, random_property_id.value_or(0), temp.value_or(false)));
	});

	reg_prop_ro(ft, "isBoundAccountWide", [](Item * item) {
		return item->IsBoundAccountWide();
	});
	reg_prop_ro(ft, "isBoundByEnchant", [](Item * item) {
		return item->IsBoundByEnchant();
	});
	reg_prop_ro(ft, "isLocked", [](Item * item) {
		return item->IsLocked();
	});
	reg_prop_ro(ft, "isBag", [](Item * item) {
		return item->IsBag();
	});
	reg_prop_ro(ft, "isCurrencyToken", [](Item * item) {
		return item->IsCurrencyToken();
	});
	reg_prop_ro(ft, "isNotEmptyBag", [](Item * item) {
		return item->IsNotEmptyBag();
	});
	reg_prop_ro(ft, "isBroken", [](Item * item) {
		return item->IsBroken();
	});
	reg_prop_ro(ft, "isInTrade", [](Item * item) {
		return item->IsInTrade();
	});
	reg_prop_ro(ft, "isInBag", [](Item * item) {
		return item->IsInBag();
	});
	reg_prop_ro(ft, "isEquipped", [](Item * item) {
		return item->IsEquipped();
	});
	reg_prop_ro(ft, "isPotion", [](Item * item) {
		return item->IsPotion();
	});
	reg_prop_ro(ft, "isWeaponVellum", [](Item * item) {
		return item->IsWeaponVellum();
	});
	reg_prop_ro(ft, "isArmorVellum", [](Item * item) {
		return item->IsArmorVellum();
	});
	reg_prop_ro(ft, "isConjuredConsumable", [](Item * item) {
		return item->IsConjuredConsumable();
	});
	reg_prop_ro(ft, "isRefundExpired", [](Item * item) {
		return item->IsRefundExpired();
	});
	reg_prop_ro(ft, "maxStackCount", [](Item * item) {
		return item->GetMaxStackCount();
	});
	reg_prop_ro(ft, "slot", [](Item * item) {
		return item->GetSlot();
	});
	reg_prop_ro(ft, "bagSlot", [](Item * item) {
		return item->GetBagSlot();
	});
	reg_prop_ro(ft, "template", [](Item * item) {
		return item->GetTemplate();
	});
	reg_prop_ro(ft, "bagSize", [](Item * item) {
		if (auto const bag = item->ToBag()) {
			return bag->GetBagSize();
		}
		return uint32_t{0};
	});

	reg_method(ft, "hasQuest", [](Item * item, uint32_t quest_id) {
		return item->hasQuest(quest_id);
	});
	reg_method(ft, "getEnchantmentId", [](Item * item, EnchantmentSlot const slot) {
		return item->GetEnchantmentId(slot);
	});
	reg_method(ft, "canBeTraded", [](Item * item, std::optional<bool> const mail, std::optional<bool> const trade) {
		return item->CanBeTraded(mail.value_or(false), trade.value_or(false));
	});
	reg_method(ft, "isBindedNotWith", [](Item * item, Player * player) {
		return item->IsBindedNotWith(player);
	});
	reg_method(ft, "getItemLinkText", [](Item * item, std::optional<uint8_t> const locale) {
		auto const resolved_locale = locale.value_or(DEFAULT_LOCALE);
		auto const temp = item->GetTemplate();

		auto name = temp->Name1;
		if (auto const il = sObjectMgr->GetItemLocale(temp->ItemId)) {
			sObjectMgr->GetLocaleString(il->Name, resolved_locale, name);
		}

		if (auto const item_random_property_id = item->GetItemRandomPropertyId()) {
			std::array<char const *, 16> const * suffix = nullptr;
			if (item_random_property_id < 0) {
				if (auto const re = sItemRandomSuffixStore.LookupEntry(-item_random_property_id)) {
					suffix = &re->Name;
				}
			} else {
				if (auto const re = sItemRandomPropertiesStore.LookupEntry(item_random_property_id)) {
					suffix = &re->Name;
				}
			}
			if (suffix) {
				if (
					auto const suffix_name = (*suffix)[name != temp->Name1 ? resolved_locale : DEFAULT_LOCALE];
					suffix_name[0] != '\0'
				) {
					name += ' ';
					name += suffix_name;
				}
			}
		}

		Player * owner = item->GetOwner();
		std::ostringstream oss;
		oss << "|c" << std::hex << ItemQualityColors[temp->Quality] << std::dec
			<< "|Hitem:" << temp->ItemId << ":"
			<< item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT) << ":"
			<< item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT) << ":"
			<< item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2) << ":"
			<< item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3) << ":"
			<< item->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT) << ":"
			<< item->GetItemRandomPropertyId() << ":"
			<< item->GetItemSuffixFactor() << ":"
			<< uint32_t{owner ? owner->GetLevel() : 0}
			<< "|h[" << name << "]|h|r";

		return oss.str();
	});

	reg_prop(ft, "ownerGuid",
		[](Item * item) { return item->GetOwnerGUID(); },
		[](Item * item, ObjectGuid const guid) { item->SetOwnerGUID(guid); }
	);
	reg_prop(ft, "count",
		[](Item * item) { return item->GetCount(); },
		[](Item * item, uint32_t const val) { item->SetCount(val); }
	);
	reg_prop(ft, "isSoulBound",
		[](Item * item) { return item->IsSoulBound(); },
		[](Item * item, bool const val) {
			item->SetBinding(val);
			if (auto const owner = item->GetOwner()) {
				item->SetState(ITEM_CHANGED, owner);
			}
		}
	);

	reg_method(ft, "setEnchantment", [](Item * item, EnchantmentSlot const slot, uint32_t const enchantment_id, uint32_t const duration, uint32_t const charges, std::optional<ObjectGuid> caster) {
		if (auto const owner = item->GetOwner()) {
			owner->ApplyEnchantment(item, slot, false);
			item->SetEnchantment(slot, enchantment_id, duration, charges, caster.value_or({}));
			owner->ApplyEnchantment(item, slot, true);
			return true;
		}
		return false;
	});
	reg_method(ft, "clearEnchantment", [](Item * item, EnchantmentSlot const slot) {
		if (auto const owner = item->GetOwner()) {
			owner->ApplyEnchantment(item, slot, false);
			return true;
		}
		return false;
	});
	reg_method(ft, "setRandomProperties", [](Item * item, int32_t const prop) {
		item->SetItemRandomProperties(prop);
	});
	reg_method(ft, "setRandomSuffix", [](Item * item, int32_t const suffix) {
		item->SetItemRandomProperties(-suffix);
	});
	reg_method(ft, "save", [](Item * item) {
		auto const trans = CharacterDatabase.BeginTransaction();
		item->SaveToDB(trans);
		CharacterDatabase.CommitTransaction(trans);
	});

	return ft;
}
