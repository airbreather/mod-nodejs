#include "MiscScript.h"

#include <string>

#include "NodeJPropHelpers.h"
#include "NodeJs.h"
#include "SpellAuraEffects.h"
#include "WorldSession.h"

class NODEJS_Misc : public MiscScript {
public:
	NODEJS_Misc() : MiscScript("NODEJS_Misc") {
	}

	void OnItemCreate(Item * item, ItemTemplate const * itemProto, Player const * owner) override {
		NodeJs::invoke_hook("misc:item-create", jarg("item", item), jarg("proto", itemProto), jarg("owner", owner));
	}
	[[nodiscard]] bool CanApplySoulboundFlag(Item * item, ItemTemplate const * proto) override {
		return NodeJs::invoke_hook_t("misc:can-apply-soulbound-flag", MiscScript::CanApplySoulboundFlag(item, proto)
			, jarg("item", item), jarg("proto", proto));
	}
	[[nodiscard]] bool CanItemApplyEquipSpell(Player * player, Item * item) override {
		return NodeJs::invoke_hook_t("misc:can-item-apply-equip-spell", MiscScript::CanItemApplyEquipSpell(player, item)
			, jarg("player", player), jarg("item", item));
	}
	[[nodiscard]] bool CanSendAuctionHello(WorldSession const * session, ObjectGuid const guid, Creature * creature) override {
		if (auto const player = session->GetPlayer()) {
			return NodeJs::invoke_hook_t("misc:can-send-auction-hello", MiscScript::CanSendAuctionHello(session, guid, creature)
				, jarg("player", player), jarg("guid", guid), jarg("creature", creature));
		}
		return MiscScript::CanSendAuctionHello(session, guid, creature);
	}
	void ValidateSpellAtCastSpell(Player * player, uint32_t & oldSpellId, uint32_t & spellId, uint8_t & castCount, uint8_t & castFlags) override {
		NodeJs::invoke_hook("misc:validate-spell-at-cast-spell", jarg("player", player), jarg_inout("oldSpellId", oldSpellId), jarg_inout("spellId", spellId), jarg_inout("castCount", castCount), jarg_inout("castFlags", castFlags));
	}
	void ValidateSpellAtCastSpellResult(Player * player, Unit * mover, Spell * spell, uint32_t const oldSpellId, uint32_t const spellId) override {
		NodeJs::invoke_hook("misc:validate-spell-at-cast-spell-result", jarg("player", player), jarg("mover", mover), jarg("spell", spell), jarg("oldSpellId", oldSpellId), jarg("spellId", spellId));
	}
	void OnAfterLootTemplateProcess(Loot * loot, LootTemplate const * tab, LootStore const & store, Player * lootOwner, bool const personal, bool const noEmptyError, uint16_t const lootMode) override {
		NodeJs::invoke_hook("misc:after-loot-template-process", jarg("loot", loot), jarg("tab", tab), jarg("store", &store), jarg("lootOwner", lootOwner), jarg("personal", personal), jarg("noEmptyError", noEmptyError), jarg("lootMode", lootMode));
	}
	void OnInstanceSave(InstanceSave * instanceSave) override {
		NodeJs::invoke_hook("misc:instance-save"/*, jarg("instanceSave", instanceSave)*/);
	}
	void GetDialogStatus(Player * player, Object * questgiver) override {
		NodeJs::invoke_hook("misc:get-dialog-status", jarg("player", player), jarg("questGiver", questgiver));
	}
};

void AddSC_Misc() {
	new NODEJS_Misc();
}
