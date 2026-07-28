declare global {
	namespace Acore {
		class DynamicObject extends WorldObject {
			readonly casterGuid: ObjectGuidNative;
			readonly caster: Unit | undefined;
			readonly spellId: number;
			readonly radius: number;
			readonly isViewpoint: boolean;
			readonly oldFarsightGuid: ObjectGuidNative | undefined;
			duration: number;

			remove(): void;
			delay(delayTime: number): void;
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
