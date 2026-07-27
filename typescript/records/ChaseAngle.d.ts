declare global {
	type ChaseAngle =
		| number
		| { angle: number; tolerance?: number; }
		;
}
export {};
