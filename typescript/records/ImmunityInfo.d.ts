declare global {
	interface ImmunityInfo {
		schoolImmuneMask: SpellSchoolMask;
		applyHarmfulAuraImmuneMask: SpellSchoolMask;
		mechanicImmuneMask: number;
		dispelImmuneMask: DispelType; // doesn't seem so much of a "mask", really...
		damageSchoolMask: SpellSchoolMask;
		auraTypeImmune: Set<AuraType>;
		spellEffectImmune: Set<SpellEffects>;
	}
}
export {};
