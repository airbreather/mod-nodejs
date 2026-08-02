declare global {
	namespace Acore {
		class SpellImplicitTargetInfo {
			readonly isArea: boolean;
			readonly selectionCategory: SpellTargetSelectionCategories;
			readonly referenceType: SpellTargetReferenceTypes;
			readonly objectType: SpellTargetObjectTypes;
			readonly checkType: SpellTargetCheckTypes;
			readonly directionType: SpellTargetDirectionTypes;
			readonly calcDirectionAngle: number;
			readonly target: Targets;
		}
	}
}
export {};
