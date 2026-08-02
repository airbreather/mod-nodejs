declare global {
	interface SpellCastTimesEntry {
		id: number;
		castTime: Temporal.Duration;
	}
}
export {};
