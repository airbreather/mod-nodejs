declare global {
	interface SpellModifier {
		op: SpellModOp;
		type: SpellModType;
		value: number;
		mask: bigint;
		spellId: number;
		ownerAura: Acore.Aura;
	}
}
export {};
