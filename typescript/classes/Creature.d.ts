declare global {
	namespace Acore {
		class Creature extends Unit {
			// 0 for new or temporary, Acore.decodeGuid(guid)[2] otherwise.
			readonly spawnId: number;
			readonly template: CreatureTemplate;
			readonly shieldBlockValue: number;
			readonly isInEvadeMode: boolean;
			readonly isElite: boolean;
			readonly isGuard: boolean;
			readonly isCivilian: boolean;
			readonly isRacialLeader: boolean;
			readonly isDungeonBoss: boolean;
			readonly isWorldBoss: boolean;
			readonly isTrigger: boolean;
			readonly isDamageEnoughForLootingAndReward: boolean;
			readonly canSwim: boolean;
			readonly canWalk: boolean;
			readonly canFly: boolean;
			readonly hasSearchedAssistance: boolean;
			readonly hasLootRecipient: boolean;
			readonly canAggro: boolean;
			readonly waypointPath: number;
			readonly currentWaypointId: number;
			readonly scriptName: string;
			readonly aiName: string;
			readonly scriptId: number;
			readonly lootRecipientGuid: ObjectGuidNative | undefined;
			readonly lootRecipient: Player | undefined;
			readonly lootRecipientGroupId: number;
			readonly lootRecipientGroup: Group | undefined;
			readonly homePosition: Position;
			regeneratingHealth: boolean;
			reputationGainDisabled: boolean;
			respawnDelay: number;
			wanderRadius: number;
			corpseDelay: number;
			defaultMovementType: MovementGeneratorType;
			npcFlags: NPCFlags;
			unitFlags: UnitFlags;
			unitFlags2: UnitFlags2;
			reactState: ReactStates;
			lootMode: LootModes;

			canCompleteQuest(questId: number): boolean;
			canAssistTo(friend: Unit, enemy: Unit, checkFaction?: boolean): boolean;
			isTappedBy(player: Player): boolean;
			isTargetableForAttack(mustBeDead?: boolean, byWhom?: Unit): boolean;
			canStartAttack(target: Unit, force?: boolean): boolean;
			getAggroRange(target: Unit): number;
			hasSpell(spellId: number): boolean;
			hasSpellCooldown(spellId: number): boolean;
			getSpellCooldown(spellId: number): number;
			hasQuest(questId: number): boolean;
			hasLootMode(lootMode: LootModes): boolean;
			getAITargets(): ThreatReference[];
			getAITargetsCount(): number;
			setInCombatWithZone(): void;
			attackStart(target: Unit): void;
			setHomePosition(x: number, y: number, z: number, o: number): void;
			setAggroEnabled(allow?: boolean): void;
			setEquipmentSlots(mainHand: number, offHand: number, ranged: number): void;
			setNoSearchAssistance(v?: boolean): void;
			setNoCallAssistance(v?: boolean): void;
			despawnOrUnsummon(msTimeToDespawn?: number, forcedRespawnTimer?: number): void;
			respawn(force?: boolean): void;
			removeCorpse(setSpawnTime?: boolean, skipVisibility?: boolean): void;
			allLootRemovedFromCorpse(): void;
			saveToDB(): void;
			moveWaypoint(): void;
			callAssistance(target?: Unit): void;
			callForHelp(radius: number, target?: Unit): void;
			fleeToGetAssistance(): void;
			selectVictim(): void;
			updateEntry(entry: number, spawnIdForCreatureData?: number, changeLevel?: boolean, updateAi?: boolean): void;
		}
	}
}
export {};
