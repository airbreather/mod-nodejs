declare global {
	const enum NearObjectsMask {
		None = 0,
		Player = 1 << 0,
		Creature = 1 << 1,
		GameObject = 1 << 2,
	}
}
export {};
