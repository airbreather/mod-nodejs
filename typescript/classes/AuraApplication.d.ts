declare global {
	namespace Acore {
		class AuraApplication {
			readonly target: Unit;
			readonly base: Aura;
			readonly slot: number;
			readonly flags: AURA_FLAGS;
			readonly effectMask: number;
			readonly isPositive: boolean;
			readonly isSelfcasted: boolean;
			readonly effectsToApply: number;
			removeMode: AuraRemoveMode;

			hasEffect(effect: number): boolean;
			isActive(effectIndex: number): boolean;
			setDisableMask(effectIndex: number): void;
			removeDisableMask(effectIndex: number): void;
		}
	}
}
export {};
