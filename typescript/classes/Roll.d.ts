declare global {
	namespace Acore {
		class Roll {
			readonly rollId: number;
			readonly rollType: RollMask;
			readonly itemId: number;
			readonly itemRandomPropId: number;
			readonly itemSuffix: number;
			readonly itemCount: number;
			readonly isRollInProgress: boolean;
		}
	}
}
export {};
