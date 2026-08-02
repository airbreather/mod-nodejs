declare global {
	namespace Acore {
		class AuraApplication {
			readonly target: Unit;
			readonly base: Aura;
			readonly slot: number;
			readonly flags: AURA_FLAGS;
			readonly effectMask: AURA_FLAGS_ONLY_EFFECTS;
			readonly isPositive: boolean;
			readonly isSelfcasted: boolean;
			readonly effectsToApply: SpellEffIndexMask;
			removeMode: AuraRemoveMode;

			hasEffect(effect: SpellEffIndex): boolean;
			isActive(effectIndex: SpellEffIndex): boolean;
			setDisableMask(effectIndex: SpellEffIndex): void;
			removeDisableMask(effectIndex: SpellEffIndex): void;
		}
	}
}
export {};
