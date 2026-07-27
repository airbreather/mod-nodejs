declare global {
	namespace Acore {
		class BattlegroundQueue {
			readonly qp: Map<number, GroupQueueInfo>;
		}
	}
}
export {};
