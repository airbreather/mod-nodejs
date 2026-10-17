#include "MiscScript.h"

#include <string>

#include "NodeJs.h"
#include "SpellAuraEffects.h"
#include "WorldSession.h"

class NODEJS_Misc : public MiscScript {
public:
	NODEJS_Misc() : MiscScript("NODEJS_Misc") {
	}

	void OnItemCreate(Item * item, ItemTemplate const * itemProto, Player const * owner) override {
		NodeJs::invoke_hook("misc:item-create"
			, jprop("item", item), jprop("proto", itemProto), jprop("owner", owner));
	}
	[[nodiscard]] bool CanApplySoulboundFlag(Item * item, ItemTemplate const * proto) override {
		return NodeJs::invoke_hook_t("misc:can-apply-soulbound-flag", MiscScript::CanApplySoulboundFlag(item, proto)
			, jprop("item", item), jprop("proto", proto));
	}
	[[nodiscard]] bool CanItemApplyEquipSpell(Player * player, Item * item) override {
		return NodeJs::invoke_hook_t("misc:can-item-apply-equip-spell", MiscScript::CanItemApplyEquipSpell(player, item)
			, jprop("player", player), jprop("item", item));
	}
	[[nodiscard]] bool CanSendAuctionHello(WorldSession const * session, ObjectGuid const guid, Creature * creature) override {
		if (auto const player = session->GetPlayer()) {
			return NodeJs::invoke_hook_t("misc:can-send-auction-hello", MiscScript::CanSendAuctionHello(session, guid, creature)
				, jprop("player", player), jprop("guid", guid), jprop("creature", creature));
		}
		return MiscScript::CanSendAuctionHello(session, guid, creature);
	}
	void ValidateSpellAtCastSpell(Player * player, uint32_t & oldSpellId, uint32_t & spellId, uint8_t & castCount, uint8_t & castFlags) override {
		NodeJs::invoke_hook("misc:validate-spell-at-cast-spell"
			, jprop("player", player), jprop_box("oldSpellId", oldSpellId), jprop_box("spellId", spellId), jprop_box("castCount", castCount), jprop_box("castFlags", castFlags));
	}
	void ValidateSpellAtCastSpellResult(Player * player, Unit * mover, Spell * spell, uint32_t const oldSpellId, uint32_t const spellId) override {
		NodeJs::invoke_hook("misc:validate-spell-at-cast-spell-result"
			, jprop("player", player), jprop("mover", mover), jprop("spell", spell), jprop("oldSpellId", oldSpellId), jprop("spellId", spellId));
	}
	void OnAfterLootTemplateProcess(Loot * loot, LootTemplate const * tab, LootStore const & store, Player * lootOwner, bool const personal, bool const noEmptyError, uint16_t const lootMode) override {
		NodeJs::invoke_hook("misc:after-loot-template-process"
			, jprop("loot", loot), jprop("tab", tab), jprop("store", &store), jprop("lootOwner", lootOwner), jprop("personal", personal), jprop("noEmptyError", noEmptyError), jprop("lootMode", lootMode));
	}
	void OnInstanceSave(InstanceSave * instanceSave) override {
		NodeJs::invoke_hook("misc:instance-save"
			/*, jprop("instanceSave", instanceSave)*/);
	}
	void GetDialogStatus(Player * player, Object * questgiver) override {
		NodeJs::invoke_hook("misc:get-dialog-status"
			, jprop("player", player), jprop("questGiver", questgiver));
	}
};

void AddSC_Misc() {
	new NODEJS_Misc();
}
