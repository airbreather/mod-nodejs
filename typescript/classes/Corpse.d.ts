declare global {
	namespace Acore {
		class Corpse extends WorldObject {
			ghostTime: Temporal.Instant;
			corpseType: CorpseType;
			ownerGuid: bigint;
			owner: Player | undefined;

			resetGhostTime(): void;
			saveToDB(): void;
		}
	}
}
export {};
