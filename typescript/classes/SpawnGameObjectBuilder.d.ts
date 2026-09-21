declare global {
	namespace Acore {
		class SpawnGameObjectBuilder {
			private constructor();

			spawn(): GameObject;

			setPhaseMask(phaseMask: number): this;
			setRotationQuat(x: number, y: number, z: number, w: number): this;
			setRotationByZAxisAngle(angle: number): this;
			setAnimationProgress(animationProgress: number): this;
			setState(state: GOState): this;
		}
	}
}
export {};
