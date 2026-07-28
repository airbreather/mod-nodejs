declare global {
	namespace Acore {
		class Corpse extends WorldObject {
			ghostTime: Temporal.Instant;
			corpseType: CorpseType;
			ownerGuid: ObjectGuidNative;
			owner: Player | undefined;

			resetGhostTime(): void;
			saveToDB(): void;
		}
	}
}
export {};
