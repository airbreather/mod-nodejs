declare global {
	type ChaseRange =
		| number
		| { minRange: number; maxRange: number; }
		| { minRange: number; maxRange: number; minTolerance: number; maxTolerance: number }
		;
}
export {};
