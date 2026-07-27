declare global {
	//To all Immune system, if target has immunes,
	//some spell that related to ImmuneToDispel or ImmuneToSchool or ImmuneToDamage type can't cast to it,
	//some spell_effects that related to ImmuneToEffect<effect>(only this effect in the spell) can't cast to it,
	//some aura(related to Mechanics or ImmuneToState<aura>) can't apply to it.
	const enum SpellImmunity {
		IMMUNITY_EFFECT                = 0,                     // enum SpellEffects
		IMMUNITY_STATE                 = 1,                     // enum AuraType
		IMMUNITY_SCHOOL                = 2,                     // enum SpellSchoolMask
		IMMUNITY_DAMAGE                = 3,                     // enum SpellSchoolMask
		IMMUNITY_DISPEL                = 4,                     // enum DispelType
		IMMUNITY_MECHANIC              = 5,                     // enum Mechanics
		IMMUNITY_ID                    = 6,
		IMMUNITY_ALLOW_ID              = 7,                     // xinef: special type of immunity, npc is immune to everything except for those spells id
	}
}
export {};
