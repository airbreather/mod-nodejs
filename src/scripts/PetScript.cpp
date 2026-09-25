#include "PetScript.h"

#include <string>

#include "JBox.h"
#include "NodeJs.h"

class NODEJS_Pet : public PetScript {
public:
	NODEJS_Pet() : PetScript("NODEJS_Pet") {
	}

	void OnInitStatsForLevel(Guardian * guardian, uint8_t petlevel) override {
		NodeJs::invoke_hook("pet:init-stats-for-level"
			, jprop("pet", guardian), jprop("petLevel", petlevel));
	}

	void OnCalculateMaxTalentPointsForLevel(Pet * pet, uint8_t const level, uint8_t & points) override {
		NodeJs::invoke_hook("pet:calculate-max-talent-points-for-level"
			, jprop("pet", pet), jprop("level", level), jprop_box("points", points));
	}

	[[nodiscard]] bool CanUnlearnSpellSet(Pet * pet, uint32_t const level, uint32_t const spell) override {
		return NodeJs::invoke_hook_t("pet:can-unlearn-spell-set", PetScript::CanUnlearnSpellSet(pet, level, spell)
			, jprop("pet", pet), jprop("level", level), jprop("spell", spell));
	}

	[[nodiscard]] bool CanUnlearnSpellDefault(Pet * pet, SpellInfo const * spellInfo) override {
		return NodeJs::invoke_hook_t("pet:can-unlearn-spell-default", PetScript::CanUnlearnSpellDefault(pet, spellInfo)
			, jprop("pet", pet), jprop("spellInfo", spellInfo));
	}

	[[nodiscard]] bool CanResetTalents(Pet * pet) override {
		return NodeJs::invoke_hook_t("pet:can-reset-talents", PetScript::CanResetTalents(pet)
			, jprop("pet", pet));
	}

	void OnPetAddToWorld(Pet * pet) override {
		NodeJs::invoke_hook("pet:add-to-world"
			, jprop("pet", pet));
	}
};

void AddSC_Pet() {
	new NODEJS_Pet();
}
