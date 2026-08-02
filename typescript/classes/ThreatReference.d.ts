declare global {
	namespace Acore {
		class ThreatReference {
			readonly owner: Creature;
			readonly victim: Unit;
			readonly threat: number;
			readonly onlineState: OnlineState;
			readonly isOnline: boolean;
			readonly isAvailable: boolean;
			readonly isSuppressed: boolean;
			readonly isOffline: boolean;
			readonly tauntState: TauntState;
			readonly isTaunting: boolean;
			readonly isDetaunted: boolean;

			addThreat(amount: number): void;
			scaleThreat(factor: number): void;
			modifyThreatByPercent(percent: number): void;
			updateOffline(): void;
			clearThreatAndDestroyThisObject(): void;
		}
	}
}
export {};
