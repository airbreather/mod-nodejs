import Long from 'long';
import { EventEmitter } from 'node:events';

declare global {
	type LongLike =
		| Long
		| number
		| bigint
		| string
		| { low: number; high: number; unsigned: boolean };

	namespace Acore {
		const hooks: EventEmitter<HooksConforming>;

		class ACObject {
			readonly typeID: TypeId;
			readonly entry: number;
			readonly guid: ObjectGuidNative;
			readonly isPlayer: boolean;
			readonly isInWorld: boolean;
			scale: number;

			hasFlag(field: number, flag: number): boolean;
			getInt32Value(field: number): number;
			getUInt32Value(field: number): number;
			getFloatValue(field: number): number;
			getByteValue(field: number, offset: 0 | 1 | 2 | 3): number;
			getUInt16Value(field: number, offset: 0 | 1): number;
			getInt16Value(field: number, offset: 0 | 1): number;
			getUInt64Value(field: number): number | (Long & { unsigned: true });

			setFlag(field: number, flag: number): void;
			removeFlag(field: number, flag: number): void;
			setInt32Value(field: number, value: number): void;
			setUInt32Value(field: number, value: number): void;
			updateUInt32Value(field: number, value: number): void;
			setFloatValue(field: number, value: number): void;
			setByteValue(field: number, offset: 0 | 1 | 2 | 3, value: number): void;
			setUInt16Value(field: number, offset: 0 | 1, value: number): void;
			setInt16Value(field: number, offset: 0 | 1, value: number): void;
			setUInt64Value(field: number, value: LongLike): void;
		}

		class ByteBuffer {
		}

		class WorldPacket extends ByteBuffer {
			constructor(opcode?: number, sizeToReserve?: number);
		}

		class Item extends ACObject {
		}

		class WorldObject extends ACObject {
			readonly mapId: number;
			readonly zoneId: number;
			readonly areaId: number;
			readonly phaseMask: number;
			readonly instanceId: number;
			readonly location: Position;
			readonly transport: Transport | undefined;
			readonly sightRange: number;
			name: string;

			getNearestPlayer(range: number): Player | undefined;
			getNearestCreature(range: number, entry?: number): Creature | undefined;
			getNearestGameObject(range: number, entry?: number): GameObject | undefined;
			getDistanceTo(target: WorldObject, only2d?: boolean, mustBeExact?: boolean): number;
			getSightRangeTo(target: WorldObject): number;
			getAngleTo(target: WorldObject): number;
			isWithinLoSTo(target: WorldObject): boolean;
			isWithinDistTo(target: WorldObject, dist: number, mustBeInSameMap?: boolean): boolean;
			isInSameMapAs(target: WorldObject): boolean;
			isWithinDist3d(x: number, y: number, z: number, dist: number): boolean;
			isWithinDist2d(x: number, y: number, dist: number): boolean;
			isInRangeTo(target: WorldObject, max: number, min?: number, only2d?: boolean): boolean;
			isInFrontOf(target: WorldObject): boolean;
			isInBackOf(target: WorldObject): boolean;
			getRelativePoint(range: number, deg: number): number;
			getNearObject(range: number): WorldObject | undefined;
			getPlayersInRange(range: number): Player[];
			getCreaturesInRange(range: number, entry?: number): Creature[];
			getGameObjectsInRange(range: number, entry?: number): GameObject[];
			getUnitsInRange(range: number): Unit[];
			getNearObjects(range: number, mask?: NearObjectsMask): WorldObject[];
			getNearObjects(range: number, mask?: NearObjectsMask): WorldObject[];
			sendMessageToSet(packet: WorldPacket, self: boolean): void;
			sendMessageToSetInRange(packet: WorldPacket, range: number): void;
			sendMessageToSetExceptPlayer(packet: WorldPacket, skippedReceiver: Player): void;
			playMusic(soundKitId: number, zoneWide?: boolean): void;
			playDirectSound(soundId: number): void;
			playDistanceSound(soundId: number): void;
			// TODO: this is how they're defined today, but I think I want to make a breaking change before documenting them
			// in a declaration file like this. if you're reading this and you are OK with having to update in a future
			// version, feel free to uncomment and use them as written...
			// summonGameObject(entry: number, x?: number, y?: number, z?: number, o?: number): GameObject | undefined;
			// spawnCreature(entry: number, x?: number, y?: number, z?: number, o?: number): Creature | undefined;
		}

		class Corpse extends WorldObject {
		}

		class DynamicObject extends WorldObject {
		}

		class GameObject extends WorldObject {
		}

		type ChaseRange =
			| number
			| { minRange: number; maxRange: number; }
			| { minRange: number; maxRange: number; minTolerance: number; maxTolerance: number }
			;
		type ChaseAngle =
			| number
			| { angle: number; tolerance?: number; }
			;
		class Unit extends WorldObject {
			readonly gender: Gender;
			readonly creatureType: CreatureType;
			readonly healthPct: number;
			readonly movementType: MovementGeneratorType;
			readonly mountId: number;
			readonly vehicle: Vehicle | undefined;
			readonly isDying: boolean;
			readonly victim: Unit | undefined;
			readonly isAttackingPlayer: boolean;
			readonly isStandState: boolean;
			readonly charmGuid: ObjectGuid | undefined;
			readonly charmerGuid: ObjectGuid | undefined;
			readonly charmerOrOwnerGuid: ObjectGuid | undefined;
			readonly charmerOrOwnerOrOwnGuid: ObjectGuid | undefined;
			readonly owner: Unit | undefined;
			readonly followAngle: number;
			readonly isAlive: boolean;
			readonly isDead: boolean;
			readonly isInCombat: boolean;
			readonly isMounted: boolean;
			readonly isInWater: boolean;
			readonly isUnderWater: boolean;
			readonly isFlying: boolean;
			readonly isFalling: boolean;
			readonly isStopped: boolean;
			readonly isCharmed: boolean;
			readonly isFullHealth: boolean;
			readonly isPvP: boolean;
			readonly isOnVehicle: boolean;
			readonly isArmorer: boolean;
			readonly isAuctioneer: boolean;
			readonly isBanker: boolean;
			readonly isBattleMaster: boolean;
			readonly isGossip: boolean;
			readonly isGuildMaster: boolean;
			readonly isInnkeeper: boolean;
			readonly isQuestGiver: boolean;
			readonly isServiceProvider: boolean;
			readonly isSpiritGuide: boolean;
			readonly isSpiritHealer: boolean;
			readonly isSpiritService: boolean;
			readonly isTabardDesigner: boolean;
			readonly isTaxi: boolean;
			readonly isTrainer: boolean;
			readonly isVendor: boolean;
			readonly comboTarget: Unit | undefined;
			readonly isMoving: boolean;
			readonly comboPoints: 0 | 1 | 2 | 3 | 4 | 5;
			readonly attackers: Unit[];
			readonly unorderedThreatList: ThreatReference[];
			// FactionTemplates in the C++ template has a bunch, but there's also things like
			// KarazhanChessGameFactions, which are different numbers from what you'd expect, and
			// magic number 2082 which seems to show up only in a Zul'Drak encounter with Drakuru.
			faction: number;
			health: number;
			maxHealth: number;
			displayId: number;
			nativeDisplayId: number;
			sheath: SheathState;
			speedWalk: number;
			speedRun: number;
			speedSwim: number;
			speedTurn: number;
			level: number;
			powerType: Powers;
			isPvPFlagged: boolean;
			standState: UnitStandStateType;
			creatorGuid: ObjectGuid | undefined;
			critterGuid: ObjectGuid | undefined;
			ownerGuid: ObjectGuid | undefined;
			petGuid: ObjectGuid | undefined;
			isFFA: boolean;
			isInSanctuary: boolean;
			isRooted: boolean;
			isConfused: boolean;
			// sometimes aka feared
			isFleeing: boolean;
			emoteState: Emote;

			getCurrentSpell(spellType?: CurrentSpellTypes): Spell | undefined;
			isNonMeleeSpellCast(withDelayed: boolean, skipChanneled?: boolean, skipAutorepeat?: boolean, isAutoshoot?: boolean, skipInstant?: boolean): boolean;
			getComboPointsOn(who: Unit): 0 | 1 | 2 | 3 | 4 | 5;
			getAura(spellId: number, caster?: ObjectGuid, itemCaster?: ObjectGuid, requiredEffectMask?: number): Aura | undefined;
			getStat(stat: Stats): number;
			getPower(power: Powers): number;
			getMaxPower(power: Powers): number;
			getPowerPct(power: Powers): number;
			getSpeed(type: UnitMoveType): number;
			getSpeedRate(type: UnitMoveType): number;
			getThreat(target: Unit, includeOffline?: boolean): number;
			isInAccessiblePlaceFor(creature: Creature): boolean;
			getFriendlyUnitsInRange(range: number): Unit[];
			getUnfriendlyUnitsInRange(range: number): Unit[];
			hasAura(spellId: number, caster?: ObjectGuid, itemCaster?: ObjectGuid, requiredEffectMask?: number): boolean;
			healthAbovePct(pct: number): boolean;
			healthBelowPct(pct: number): boolean;
			countPctFromCurHealth(amount: number): boolean;
			countPctFromMaxHealth(amount: number): boolean;
			getBaseSpellPower(spellSchool: SpellSchools): number;
			hasUnitState(state: UnitState): boolean;
			sendChatMessageToPlayer(type: ChatMsg, lang: Language, msg: string, target: Player): void;
			demorph(): void;
			dismount(): void;
			performEmote(emote: Emote): void;
			mount(mountDisplayId: number, vehicleId?: number, creatureEntry?: number): void;
			stopSpellCast(spellId?: number): void;
			// set withDelayed to true to interrupt delayed spells too<br>
			// delayed+channeled spells are always interrupted
			interruptNonMeleeSpells(withDelayed: boolean, spellId?: number, withInstant?: boolean, bySelf?: boolean): void;
			removeAllAuras(): void;
			removeArenaAuras(): void;
			setFacingToObject(target: WorldObject, timed?: number): void;
			setInCombatWith(target: Unit, addSecondUnitSuppressed?: boolean): void;
			clearThreatList(): void;
			addUnitState(state: UnitState): void;
			clearUnitState(state: UnitState): void;
			nearTeleportTo(x: number, y: number, z: number, o?: number, casting?: boolean, vehicleTeleport?: boolean, withPet?: boolean, removeTransport?: boolean): void;
			addThreat(target: Unit, amount: number, spell?: SpellInfo, ignoreModifiers?: boolean, ignoreRedirects?: boolean): void;
			modifyThreatByPercent(target: Unit, pct: number): void;
			resetThreat(target: Unit): void;
			resetAllThreat(): void;
			modifyPower(powerType: Powers, amount: number, withPowerUpdate?: boolean): void;
			moveStop(): void;
			moveExpire(reset?: boolean): void;
			moveClear(reset?: boolean): void;
			moveFollow(target: Unit, distance?: number, angle?: number, slot?: MovementSlot, inheritWalkState?: boolean, inheritSpeed?: boolean): void;
			moveChase(target: Unit, distance?: ChaseRange, angle?: ChaseAngle): void;
			moveFleeing(enemy: Unit, time?: number): void;
			moveJump(x: number, y: number, z: number, velXY: number, velZ: number, id?: number, target?: Unit): void;
			moveConfused(): void;
			clearComboPoints(): void;
			addComboPoints(count: number): void;
			addAura(spellId: number, target: Unit): void;
			removeAura(spellId: number, caster?: ObjectGuid, requiredEffectMask?: number, removeMode?: AuraRemoveMode): void;
			kill(target: Unit, durabilityLoss?: boolean, attackType?: WeaponAttackType, spellProto?: SpellInfo, spell?: Spell): void;
			clearInCombat(): void;
			// TODO: use enums / alternate names / (overloads?) so the type checker can help a bit more.
			// not doing that right now because it mirrors the C++ side anyway.
			applySpellImmune(spellId: number, op: SpellImmunity, type: number, apply: boolean, blockType?: SpellImmuneBlockType): void;
			setMaxPower(amt: number, type?: Powers): void;
			setPower(amt: number, type?: Powers): void;
			setSpeed(type: UnitMoveType, speed: number, forced?: boolean): void;
			setSpeedRate(type: UnitMoveType, speed: number): void;
			attack(target: Unit, meleeAttack: boolean): boolean;
			attackStop(): boolean;
			getFlatModifierValue(stat: UnitMods, type: UnitModifierFlatType): void;
			getPctModifierValue(stat: UnitMods, type: UnitModifierPctType): void;
			setStatFlatModifier(stat: UnitMods, type: UnitModifierFlatType, value: number): void;
			setStatPctModifier(stat: UnitMods, type: UnitModifierPctType, value: number): void;
			handleStatFlatModifier(stat: UnitMods, type: UnitModifierFlatType, value: number, apply: boolean): boolean;
			// Usage outside of AuraEffect Handlers is discouraged as the value will be lost when auras change. Use an Aura instead.
			applyStatPctModifier(stat: UnitMods, type: UnitModifierPctType, value: number): void;
			sendUnitEmote(msg: string, receiver?: Unit, bossEmote?: boolean): void;
			say(msg: string, language: Language): void;
			yell(msg: string, language: Language): void;
			whisper(msg: string, language: Language, target: Player): void;
			bossWhisper(msg: string, language: Language, target: Player): void;
			setDeathState(deathState: DeathState, despawn?: boolean): void;
			setWalk(enable: boolean): void;
			setDisableGravity(disable: boolean): void;
			setSwim(enable: boolean): void;
			setCanFly(enable: boolean): void;
			setWaterWalking(enable: boolean): void;
			setFeatherFall(enable: boolean): void;
			setHover(enable: boolean): void;
		}

		class Creature extends Unit {
		}

		class Player extends Unit {
			readonly race: Races;
			readonly raceMask: number;
			readonly clazz: Classes;
			readonly classMask: number;
			readonly teamId: TeamId;
			readonly guildId: number;
			readonly isInGroup: boolean;
			readonly isInGuild: boolean;
			readonly isRested: boolean;
			readonly hasCorpse: boolean;
			readonly isMaxLevel: boolean;
			readonly activeSpec: 0 | 1;
			readonly specsCount: 0 | 1 | 2;
			readonly restBonus: number;
			readonly xp: number;
			readonly battlegroundTypeId: BattlegroundTypeId;
			readonly gmRank: AccountTypes;
			readonly accountId: number;
			readonly accountName: string;
			readonly completedQuestsCount: number;
			readonly corpse: Corpse | undefined;
			readonly playerIP: string;
			readonly mailCount: number;
			readonly mostPointsTalentTree: 0 | 1 | 2;
			readonly group: Group | undefined;
			readonly difficulty: Difficulty;
			readonly inventoryFreeSlots: number;
			readonly canSpeak: boolean;
			readonly canUninviteFromGroup: boolean;
			readonly inBattlegroundQueue: boolean;
			readonly inArena: boolean;
			readonly inBattleground: boolean;
			readonly hasTankSpec: boolean;
			readonly hasMeleeSpec: boolean;
			readonly hasCasterSpec: boolean;
			readonly hasHealSpec: boolean;
			readonly isExistPet: boolean;
			readonly canTameExoticPets: boolean;
			readonly canPetResurrect: boolean;
			readonly canResummonPet: boolean;
			readonly isPetNeedBeTempUnsummoned: boolean;
			readonly inRandomLfgDungeon: boolean;
			readonly isUsingLfg: boolean;
			readonly achievementPoints: number;
			readonly dodgeFromAgility: number;
			readonly meleeCritFromAgility: number;
			readonly spellCritFromIntellect: number;
			readonly ammoDPS: number;
			readonly canSeeDKPet: boolean;
			readonly isImmuneToDamage: boolean;
			readonly battlegroundId: number;
			readonly championingFactionId: number;
			readonly chatTag: PlayerChatTag;
			readonly dbLocaleIndex: LocaleConstant;
			readonly dbcLocale: LocaleConstant;
			readonly latency: number;
			readonly groupInvite: Group | undefined;
			readonly inGameTime: number;
			readonly healthBonusFromStamina: number;
			readonly manaBonusFromIntellect: number;
			readonly originalGroup: number
			readonly originalSubGroup: number;
			// used for proper set phase for DB at GM-mode creature/GO spawn
			readonly phaseMaskForSpawn: number;
			readonly selectedPlayer: Player | undefined;
			readonly selectedUnit: Unit | undefined;
			readonly shield: Item | undefined;
			readonly shieldBlockValue: number;
			readonly subGroup: number;
			readonly todayHonorPoints: number;
			readonly todayKills: number;
			readonly trader: Player | undefined;
			readonly yesterdayHonorPoints: number;
			readonly yesterdayKills: number;
			readonly recruiterId: number;
			readonly bankFreeSlots: number;
			readonly levelPlayedTime: number;
			readonly averageItemLevel: number;
			readonly totalPlayedTime: number;
			readonly guildName: string;
			readonly runesState: number;
			// false if mod_playerbots is not installed
			readonly isBot: boolean;
			readonly isHorde: boolean;
			readonly isAlliance: boolean;
			readonly isInArena: boolean;
			readonly isInBattleground: boolean;
			readonly isInBattlegroundQueue: boolean;
			readonly canTitanGrip: boolean;
			readonly pet: Pet | undefined;
			readonly homebind: Homebind;
			readonly talentTreePoints: [number, number, number];
			readonly completedAchievementsCount: number;
			readonly completedAchievementsCountExcludingFeatsOfStrength: number;

			static byGuid(guid: ObjectGuid): Player | undefined;
			static byName(name: string): Player | undefined;
			static allInWorld(): Player[];

			resetTalentsCost(): void;
			getRaceAsString(locale?: LocaleConstant): string;
			getClassAsString(locale?: LocaleConstant): string;
			hasSpell(spellId: number): boolean;
			hasQuest(questId: number): boolean;
			hasItemCount(itemId: number, count?: number, checkBank?: false): boolean;
			getItemCount(itemId: number, checkBank?: false, skipItem?: Item): number;
			getReputationWith(factionId: number): number;
			getReputationRankWith(factionId: number): ReputationRank;
			getQuestStatus(questId: number): QuestStatus;
			// TODO: verify correctness
			getEquippedItemBySlot(slot: number): Item | undefined;
			// TODO: verify correctness
			getInventoryItem(slot: number): Item | undefined;
			// TODO: verify correctness
			getBankItem(slot: number): Item | undefined;
			getBarberShopCost(hairstyle: number, haircolor: number, facialhair: number, skincolor?: number): number;
			getSkillValue(skill: SkillType): number;
			getMaxSkillValue(skill: SkillType): number;
			hasTalent(talentId: number, spec?: 0 | 1): boolean;
			hasAchieved(achievementId: number): boolean;
			hasQuestForItem(itemId: number, excludeQuestId?: number, turnIn?: boolean, showInLoot?: Box<boolean>): boolean;
			canUseItem(itemId: number): boolean;
			hasSpellCooldown(spellId: number): boolean;
			canShareQuest(questId: number): boolean;
			isGroupVisibleFor(player: Player): boolean;
			isInSameRaidWith(player: Player): boolean;
			isInSameGroupWith(player: Player): boolean;
			isHonorOrXPTarget(target: Unit): boolean;
			isVisibleFor(player: Player): boolean;
			hasKnownTaxiNode(nodeId: number): boolean;
			isAtGroupRewardDistanceFor(target: Unit): boolean;
			isAtLootRewardDistanceFor(target: Unit): boolean;
			canEquipNewItem(itemId: number, slot: number, swap: boolean): boolean;
			isDailyQuestDone(quest: Quest): boolean;
			canSeeStartQuest(quest: Quest): boolean;
			canInteractWithQuestGiver(target: WorldObject): boolean;
			hasArmorProficiency(armor: ItemSubclassArmor): boolean;
			hasWeaponProficiency(weapon: ItemSubclassWeapon): boolean;
			getGlyph(slot: number): GlyphPropertiesEntry | undefined;




			sendSystemMessage(msg: string): void;
		}

		class Transport extends GameObject {
		}

		class MailDraft {
			constructor(subject: string, text: string);

			addMoney(money: number): MailDraft;
			addCOD(money: number): MailDraft;
			addItem(item: Item): MailDraft;
			createAndAddItem(entry: number, amount?: number): ObjectGuid;
			send(receiver: ObjectGuid, sender: MailSender, checked?: MailCheckedMask, deliverDelay?: number, customExpiration?: number): void;
			sendReturnToSender(senderAccount: number, sender: ObjectGuid, receiver: ObjectGuid): void;
		}

		class MailSender {
			constructor(messageType: MailMessageType, sender: number, stationery?: MailStationery);

			readonly messageType: MailMessageType;
			// creature's entry,
			// game object's entry,
			// player's ObjectGuid's counter,
			// {@link AuctionHouseId}, or
			// calendar entry's id (truncated to 32 bits for some reason)
			readonly senderId: number;
			readonly stationery: MailStationery;

			static forCreature(entry: number, stationery?: MailStationery): MailSender;
			static forPlayer(guid: ObjectGuid, stationery?: MailStationery): MailSender;
			static forGameObject(entry: number, stationery?: MailStationery): MailSender;
			static forAuctionHouse(id: AuctionHouseId, stationery?: MailStationery): MailSender;
			static forCalendarEvent(entry: number, stationery?: MailStationery): MailSender;
		}

		class BattlegroundQueue {
		}

		class Vehicle {
		}

		class ThreatReference {
		}

		class Spell {
		}

		class Aura {
		}

		class SpellInfo {
		}

		class Group {
		}

		class TempSummon extends Creature {
		}

		class Minion extends TempSummon {
		}

		class Guardian extends Minion {
		}

		class Pet extends Guardian {
		}

		class Quest {
		}

		class QueryResult {
			readonly rowCount: number;
			readonly fieldCount: number;
			readonly allFields: Field[];

			getFieldName(i: number): string;
			getField(i: number): Field;
			nextRow(): boolean;
		}

		class Field {
			readonly typ: DatabaseFieldTypes;
			readonly isNull: boolean;

			asBool(): boolean;
			asU8(): number;
			asI8(): number;
			asU16(): number;
			asI16(): number;
			asU32(): number;
			asI32(): number;
			asU64(): Long;
			asI64(): Long;
			asF32(): number;
			asF64(): number;
			asString(): string;
			asBinary(): Uint8Array<ArrayBuffer>;
		}

		class ChatCommandBuilder {
			constructor(name: string);
			withSubcommand(cmd: ChatCommandBuilder): ChatCommandBuilder;
			withHandler(handler: (h: ChatHandler, args: string) => boolean): ChatCommandBuilder;
			withSecurityLevel(sec: AccountTypes): ChatCommandBuilder;
			withAllowConsole(allow: boolean): ChatCommandBuilder;
			withHelp(help: AcoreStrings): ChatCommandBuilder;
		}

		class ChatHandler {
			readonly player: Player | undefined;
			readonly selectedPlayer: Player | undefined;
			readonly selectedPlayerOrSelf: Player | undefined;
			readonly selectedCreature: Creature | undefined;
			readonly selectedUnit: Unit | undefined
			readonly selectedObject: WorldObject | undefined;
			readonly isConsole: boolean;
			readonly hasSentErrorMessage: boolean;

			isAvailable(sec: AccountTypes): boolean;
			sendSysMessageStored(msg: number): void;
			sendSysMessageInline(msg: string): void;
			sendGlobalSysMessage(msg: string): void;
			sendGlobalGMSysMessage(msg: string): void;
			hasLowerSecurity(player: Player, guid?: ObjectGuid, strong?: boolean): boolean;
			hasLowerSecurityAccount(accountId: number, strong?: boolean): boolean;
		}

		class Loot {
			readonly lootType: LootType;
			readonly itemCount: number;
			readonly unlootedCount: number;
			readonly gold: number;
			// SOME of these `| undefined` MAY be incorrect. SOME of them are DEFINITELY correct.
			readonly roundRobinPlayer: ObjectGuidNative | undefined;
			readonly lootOwnerGuid: ObjectGuidNative | undefined;
			readonly containerGuid: ObjectGuidNative | undefined;
			readonly sourceWorldObjectGuid: ObjectGuidNative | undefined;

			addItem(itemId: number, minCount: number, maxCount: number, chance: number, lootMode: LootModes, needsQuest?: boolean, allowStacking?: boolean, maxStackSize?: number): void;
			clear(): void;
			generateMoney(min: number, max: number): void;
			addLooter(looter: ObjectGuid): void;
			removeLooter(looter: ObjectGuid): void;
		}

		class LootTemplate {
			process(loot: Loot, lootStore: LootStore, lootMode: LootModes, player: Player, groupId?: number, isTopLevel?: boolean): void;
		}

		class LootStoreObject {
			readonly name: string;
			readonly entryName: string;
			readonly ratesAllowed: boolean;

			haveLootFor(lootId: number): boolean;
			haveQuestLootFor(lootId: number, player?: Player): boolean;
			getLootFor(lootId: number): LootTemplate;
		}

		type LootStore = Acore.LootStoreObject | LootStoreType;

		function gc(): void;
		function guidsEqual(a: ObjectGuid | undefined, b: ObjectGuid | undefined): boolean;
		function decodeGuid(g: ObjectGuid | undefined): ObjectGuidDecoded;
		function getCurrTime(): number;
		function getTimeDiff(ms: number): number;
		function isGameEventActive(id: number): boolean;
		function worldDbQueryAsync(q: string): Promise<QueryResult>;
		function loginDbQueryAsync(q: string): Promise<QueryResult>;
		function characterDbQueryAsync(q: string): Promise<QueryResult>;
		function worldDbQuery(q: string): QueryResult;
		function loginDbQuery(q: string): QueryResult;
		function characterDbQuery(q: string): QueryResult;
		function log(level: LogLevel, filter: string, msg: string): void;
		function logTrace(filter: string, msg: string): void;
		function logDebug(filter: string, msg: string): void;
		function logInfo(filter: string, msg: string): void;
		function logWarn(filter: string, msg: string): void;
		function logError(filter: string, msg: string): void;
		function logFatal(filter: string, msg: string): void;
		function runCommandAsync(cmd: string, flush?: boolean): Promise<boolean>;
		function saveAllPlayers(): void;
		function box<T>(val: T): Box<T>;
		function registerCommand(command: ChatCommandBuilder): void;
		function shutdown(time: number, optionsMask: ShutdownMask, exitCode: number, reason?: string): void;
	}
}
