declare global {
	// Values from ItemPetFood (power of (value-1) used for compare with CreatureFamilyEntry.petDietMask
	const enum PetDiet {
		PET_DIET_MEAT     = 1,
		PET_DIET_FISH     = 2,
		PET_DIET_CHEESE   = 3,
		PET_DIET_BREAD    = 4,
		PET_DIET_FUNGAS   = 5,
		PET_DIET_FRUIT    = 6,
		PET_DIET_RAW_MEAT = 7,
		PET_DIET_RAW_FISH = 8,
	}
}
export {};
