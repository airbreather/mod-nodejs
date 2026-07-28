declare global {
	namespace Acore {
		class Condition {
			constructor();

			readonly isLoaded: boolean;
			readonly searcherTypeMaskForCondition: number;
			readonly maxAvailableConditionTargets: number;
			sourceType: ConditionSourceType;
			sourceGroup: number;
			sourceEntry: number;
			sourceId: number;
			elseGroup: number;
			conditionType: ConditionTypes;
			conditionValue1: number;
			conditionValue2: number;
			conditionValue3: number;
			errorType: number;
			errorTextId: number;
			referenceId: number;
			scriptId: number;
			conditionTarget: number;
			negativeCondition: boolean;

			meets(source: ConditionSourceInfo): boolean;
		}
	}
}
export {};
