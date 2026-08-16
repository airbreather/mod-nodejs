declare global {
	namespace Acore {
		class Pet extends Guardian {
			readonly isHappy: boolean;
			readonly owner: Player;
			readonly isControlled: boolean;
			readonly isTemporary: boolean;
			readonly hasTempSpell: boolean;
			readonly autoSpellSize: number;
			readonly petInfo: PetInfo;
			readonly spells: Map<number, PetSpell>;
			readonly autospells: number[];
			readonly usedTalentCount: number;
			readonly declinedNames: string[];
			petType: PetType;
			isBeingLoaded: boolean;
			duration: Temporal.Duration;
			freeTalentPoints: number;
			happinessState: HappinessState;
			auraUpdateMaskForRaid: number | bigint;

			generateActionBarData(): string;
			isPermanentPetFor(owner: Player): boolean;
			getCurrentFoodBenefitLevel(itemLevel: number): number;
			getAutoSpellOnPos(pos: number): number;
			haveInDiet(item: ItemTemplate): boolean;
			createBaseAtCreature(creature: Creature): boolean;
			givePetXP(xp: number): void;
			givePetLevel(level: number): void;
			synchronizeLevelWithOwner(): void;
			learnPetPassives(): void;
			castWhenWillAvailable(spellId: number, target: Unit, oldTarget: ObjectGuid, isPositive?: boolean): void;
			clearCastWhenWillAvailable(): void;
			removeSpellCooldown(spellId: number, update: boolean): void;
			addSpell(spellId: number, activeStates?: ActiveStates, state?: PetSpellState, type?: PetSpellType): boolean;
			learnSpell(spellId: number): boolean;
			learnSpellHighRank(spellId: number): void;
			initLevelupSpellsForLevel(): void;
			unlearnSpell(spellId: number, learnPrev: boolean, clearAb?: boolean): boolean;
			removeSpell(spellId: number, learnPrev: boolean, clearAb?: boolean): boolean;
			cleanupActionBar(): void;
			initPetCreateSpells(): void;
			resetTalents(): boolean;
			initTalentForLevel(): void;
			savePetToDB(mode: PetSaveMode): void;
			loseHappiness(): void;
			remove(mode: PetSaveMode, returnReagent?: boolean): void;
			toggleAutocast(spellInfo: SpellInfo, apply: boolean): void;
			castPetAuras(current: boolean): void;
			getMaxTalentPointsForLevel(level: number): number;
			resetAuraUpdateMaskForRaid(): void;
		}
	}
}
export {};
