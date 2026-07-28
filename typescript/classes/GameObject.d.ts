declare global {
	namespace Acore {
		class GameObject extends WorldObject {
			readonly mapId: number;
			readonly isSpawned: boolean;
			readonly isTransport: boolean;
			readonly isActive: boolean;
			readonly displayId: number;
			readonly lootState: LootState;
			readonly spawnId: number;
			// readonly lootRecipientGuid: ObjectGuidNative; // not in the core PR yet.
			readonly lootRecipient: Player | undefined;
			// readonly lootRecipientGroupId: number; // not in the core PR yet.
			readonly lootRecipientGroup: Group | undefined;
			goState: GOState;
			nextAbsoluteRespawnTime: Temporal.Instant;
			ownerGuid: ObjectGuid | undefined;
			spellId: number;
			isSpawnedByDefault: boolean;

			setLootState(lootState: LootState, unit?: Unit): void;
			useDoorOrButton(timeToRestore?: number, alternative?: boolean, user?: Unit): void;
			despawn(): void;
			despawnOrUnsummon(msTimeToDespawn?: number, forcedRespawnTimer?: number): void;
			respawn(): void;
			refresh(): void;
			saveToDB(saveAddon?: boolean): void;
			saveToDBExtra(mapId: number, spawnMask: number, phaseMask: number, saveAddon?: boolean): void;
			// mod-nodejs inventions: SetRespawnTime and SetRespawnDelay names confuse me greatly. when I
			// worked out what they were, I thought of better names and a nicer way to handle the former.
			setSecondsUntilNextRespawn(delay: number): void;
			setSecondsBetweenRespawns(delay: number): void;
		}
	}
}
export {};
