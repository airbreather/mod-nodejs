declare global {
	namespace Acore {
		class CreatureTemplate {
			readonly entry: number;
			readonly difficultyEntry: number[];
			readonly killCredit: number[];
			readonly models: CreatureModel[];
			readonly name: string;
			readonly subName: string;
			readonly iconName: string;
			readonly gossipMenuId: number;
			readonly minLevel: number;
			readonly maxLevel: number;
			readonly expansion: Expansions;
			readonly faction: number;
			readonly npcFlag: NPCFlags;
			readonly speedWalk: number;
			readonly speedRun: number;
			readonly speedSwim: number;
			readonly speedFlight: number;
			readonly detectionRange: number;
			readonly rank: CreatureEliteType;
			readonly dmgSchool: SpellSchools;
			readonly damageModifier: number;
			readonly baseAttackTime: Temporal.Duration;
			readonly rangeAttackTime: Temporal.Duration;
			readonly baseVariance: number;
			readonly rangeVariance: number;
			readonly unitClass: CreatureClasses;
			readonly unitFlags: UnitFlags;
			readonly unitFlags2: UnitFlags2;
			readonly dynamicflags: UnitDynFlags;
			readonly family: CreatureFamily;
			readonly creatureType: CreatureType;
			readonly creatureTypeFlags: CreatureTypeFlags;
			readonly lootId: number;
			readonly pickpocketLootId: number;
			readonly skinLootId: number;
			readonly resistance: number[];
			readonly spells: number[];
			readonly petSpellDataId: number;
			readonly vehicleId: number;
			readonly minGold: number;
			readonly maxGold: number;
			readonly movementType: MovementGeneratorType;
			readonly movement: CreatureMovementData;
			readonly hoverHeight: number;
			readonly modHealth: number;
			readonly modMana: number;
			readonly modArmor: number;
			readonly modExperience: number;
			readonly racialLeader: boolean;
			// CreatureMovementInfo.dbc
			readonly movementId: number;
			readonly regenHealth: boolean;
			readonly creatureImmunitiesId: number;
			readonly flagsExtra: CreatureFlagsExtra;
			readonly scriptId: number;
			readonly requiredLootSkill: SkillType;
			readonly isExotic: boolean;

			getModelByIdx(idx: number): CreatureModel;
			getRandomValidModel(): CreatureModel;
			getFirstValidModel(): CreatureModel;
			getModelWithDisplayId(displayId: number): CreatureModel;
			getFirstInvisibleModel(): CreatureModel;
			getFirstVisibleModel(): CreatureModel;
			isTameable(exotic: boolean): boolean;
			hasFlagsExtra(flag: CreatureFlagsExtra): boolean;
		}
	}
}
export {};
