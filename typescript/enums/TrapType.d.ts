declare global {
	// mod-nodejs invention based on this comment in core:
	// https://github.com/azerothcore/azerothcore-wotlk/blob/c1544e400de5c0e0bcf7e11bbcc859efc0f53eda/src/server/game/Entities/GameObject/GameObjectData.h#L120
	const enum TrapType {
		TrapWithNoDespawnAfterCast = 0,
		TrapDespawnsAfterCast = 1,
		BombCastsOnSpawn = 2,
	}
}
export {};
