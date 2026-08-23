declare global {
	namespace Acore {
		class TrainerSpellList {
			constructor();
			constructor(spells: readonly TrainerSpell[]);

			readonly size: number;

			clear(): void;
			get(index: number): TrainerSpell;
			set(index: number, value: TrainerSpell): void;
			add(value: TrainerSpell): void;
			delete(index: number): void;
			toArray(): TrainerSpell[];
		}
	}
}
export {};
