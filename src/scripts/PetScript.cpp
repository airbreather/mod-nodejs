#include "PetScript.h"

#include <string>

#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_Pet : public PetScript {
public:
	NODEJS_Pet() : PetScript("NODEJS_Pet") {
	}

	void OnInitStatsForLevel(Guardian * guardian, uint8_t petlevel) override {
		NodeJs::invoke_hook("pet:init-stats-for-level", jarg("pet", guardian), jarg("petLevel", petlevel));
	}

	void OnCalculateMaxTalentPointsForLevel(Pet * pet, uint8_t const level, uint8_t & points) override {
		NodeJs::invoke_hook("pet:calculate-max-talent-points-for-level", jarg("pet", pet), jarg("level", level), jarg_inout("points", points));
	}

	[[nodiscard]] bool CanUnlearnSpellSet(Pet * pet, uint32_t const level, uint32_t const spell) override {
		return NodeJs::invoke_hook_t("pet:can-unlearn-spell-set", PetScript::CanUnlearnSpellSet(pet, level, spell)
			, jarg("pet", pet), jarg("level", level), jarg("spell", spell));
	}

	[[nodiscard]] bool CanUnlearnSpellDefault(Pet * pet, SpellInfo const * spellInfo) override {
		return NodeJs::invoke_hook_t("pet:can-unlearn-spell-default", PetScript::CanUnlearnSpellDefault(pet, spellInfo)
			, jarg("pet", pet), jarg("spellInfo", spellInfo));
	}

	[[nodiscard]] bool CanResetTalents(Pet * pet) override {
		return NodeJs::invoke_hook_t("pet:can-reset-talents", PetScript::CanResetTalents(pet)
			, jarg("pet", pet));
	}

	void OnPetAddToWorld(Pet * pet) override {
		NodeJs::invoke_hook("pet:add-to-world", jarg("pet", pet));
	}
};

void AddSC_Pet() {
	new NODEJS_Pet();
}
