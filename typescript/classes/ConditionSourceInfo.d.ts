declare global {
	namespace Acore {
		class ConditionSourceInfo {
			constructor(target0: WorldObject);
			constructor(target0: WorldObject, target1: WorldObject);
			constructor(target0: WorldObject, target1: WorldObject, target2: WorldObject);

			target0: WorldObject;
			target1: WorldObject | undefined;
			target2: WorldObject | undefined;
			lastFailedCondition: Condition | undefined;
		}
	}
}
export {};
