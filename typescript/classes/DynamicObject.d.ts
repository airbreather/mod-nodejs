declare global {
	namespace Acore {
		class DynamicObject extends WorldObject {
			readonly casterGuid: bigint;
			readonly caster: Unit | undefined;
			readonly spellId: number;
			readonly radius: number;
			readonly isViewpoint: boolean;
			readonly oldFarsightGuid: bigint | undefined;
			duration: Temporal.Duration;

			remove(): void;
			delay(delayTime: Temporal.Duration): void;
			setAura(aura: Aura): void;
			removeAura(): void;
			setCasterViewpoint(updateViewerVisibility: boolean): void;
			removeCasterViewpoint(): void;
			bindToCaster(): void;
			unbindFromCaster(): void;
		}
	}
}
export {};
