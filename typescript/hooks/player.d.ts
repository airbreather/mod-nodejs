declare global {
	interface PlayerHooks {
		['just-died']: { readonly player: Acore.Player; };
		['calculate-talents-points']: {
			readonly player: Acore.Player;
			readonly talentPointsForLevel: Acore.Box<number>;
		};
		['released-ghost']: { readonly player: Acore.Player; };
		['send-initial-packets-before-add-to-map']: {
			readonly player: Acore.Player;
			readonly data: Acore.WorldPacket;
		};
		['battleground-desertion']: {
			readonly player: Acore.Player;
			readonly desertionType: BattlegroundDesertionType;
		};
		['complete-quest']: {
			readonly player: Acore.Player;
			readonly quest: Acore.Quest;
		};
		['pvp-kill']: {
			readonly killer: Acore.Player;
			readonly killed: Acore.Player;
		};
		['pvp-flag-change']: {
			readonly player: Acore.Player;
			readonly state: boolean;
		};
		['creature-kill']: {
			readonly killer: Acore.Player;
			readonly killed: Acore.Creature;
		};
		['creature-killed-by-pet']: {
			readonly petOwner: Acore.Player;
			readonly killed: Acore.Creature;
		};
		['killed-by-creature']: {
			readonly killer: Acore.Creature;
			readonly killed: Acore.Player;
		};
		['level-changed']: {
			readonly player: Acore.Player;
			readonly oldLevel: number;
		};
		['free-talent-points-changed']: {
			readonly player: Acore.Player;
			readonly points: number;
		};
		['talents-reset']: {
			readonly player: Acore.Player;
			readonly noCost: boolean;
		};
		['can-learn-talent']: {
			readonly player: Acore.Player;
			// readonly talent: TalentEntry;
			readonly rank: number;
			readonly __return: Acore.Box<boolean>;
		};
		['after-spec-slot-changed']: {
			readonly player: Acore.Player;
			readonly newSlot: number;
		};
		['before-update']: {
			readonly player: Acore.Player;
			readonly diff: Temporal.Duration;
		};
		['update']: {
			readonly player: Acore.Player;
			readonly diff: Temporal.Duration;
		};
		['money-changed']: {
			readonly player: Acore.Player;
			readonly amount: Acore.Box<number>;
		};
		['before-loot-money']: {
			readonly player: Acore.Player;
			readonly loot: Acore.Loot;
		};
		['give-xp']: {
			readonly player: Acore.Player;
			readonly amount: Acore.Box<number>;
			readonly victim: Acore.Unit | undefined;
			readonly xpSource: PlayerXPSource;
		};
		['reputation-change']: {
			readonly player: Acore.Player;
			readonly factionId: number;
			readonly standing: Acore.Box<number>;
			readonly incremental: boolean;
			readonly __return: Acore.Box<boolean>;
		};
		['reputation-rank-change']: {
			readonly player: Acore.Player;
			readonly factionId: number;
			readonly newRank: ReputationRank;
			readonly oldRank: ReputationRank;
			readonly increased: boolean;
		};
		['give-reputation']: {
			readonly player: Acore.Player;
			readonly factionId: number;
			readonly amount: Acore.Box<number>;
			readonly repSource: ReputationSource;
		};
		['learn-spell']: {
			readonly player: Acore.Player;
			readonly spellId: number;
		};
		['forgot-spell']: {
			readonly player: Acore.Player;
			readonly spellId: number;
		};
		['duel-request']: {
			readonly target: Acore.Player;
			readonly challenger: Acore.Player;
		};
		['duel-start']: {
			readonly player1: Acore.Player;
			readonly player2: Acore.Player;
		};
		['duel-end']: {
			readonly winner: Acore.Player;
			readonly loser: Acore.Player;
			readonly type: DuelCompleteType;
		};
		['before-send-chat-message']: {
			readonly player: Acore.Player;
			readonly type: Acore.Box<ChatMsg>;
			readonly lang: Acore.Box<Language>;
			readonly msg: Acore.Box<string>;
		};
		['emote']: {
			readonly player: Acore.Player;
			readonly emote: Emote;
		};
		['text-emote']: {
			readonly player: Acore.Player;
			readonly textEmote: TextEmotes;
			readonly emoteNum: number; // ?
			readonly guid: bigint | undefined;
		};
		['spell-cast']: {
			readonly player: Acore.Player;
			readonly spell: Acore.Spell;
			readonly skipCheck: boolean;
		};
		['load-from-db']: { readonly player: Acore.Player; };
		['login']: { readonly player: Acore.Player; };
		['before-logout']: { readonly player: Acore.Player; };
		['logout']: { readonly player: Acore.Player; };
		['create']: { readonly player: Acore.Player; };
		['delete']: {
			readonly guid: bigint;
			readonly accountId: number;
		};
		['failed-delete']: {
			readonly guid: bigint;
			readonly accountId: number;
		};
		['save']: { readonly player: Acore.Player; };
		['bind-to-instance']: {
			readonly player: Acore.Player;
			readonly difficulty: Difficulty;
			readonly mapId: number;
			readonly permanent: boolean;
		};
		['update-zone']: {
			readonly player: Acore.Player;
			readonly newZone: number;
			readonly newArea: number;
		};
		['update-area']: {
			readonly player: Acore.Player;
			readonly oldArea: number;
			readonly newArea: number;
		};
		['map-changed']: { readonly player: Acore.Player; };
		['before-teleport']: {
			readonly player: Acore.Player;
			readonly mapId: number;
			readonly x: number;
			readonly y: number;
			readonly z: number;
			readonly o: number;
			readonly options: TeleportToOptions;
			readonly target: Acore.Unit | undefined;
			readonly __return: Acore.Box<boolean>;
		};
		['update-faction']: { readonly player: Acore.Player; };
		['add-to-battleground']: {
			readonly player: Acore.Player;
			readonly bg: Acore.Battleground;
		};
		['queue-random-dungeon']: {
			readonly player: Acore.Player;
			readonly rDungeonId: Acore.Box<number>;
		};
		['remove-from-battleground']: {
			readonly player: Acore.Player;
			readonly bg: Acore.Battleground;
		};
		['achievement-complete']: {
			readonly player: Acore.Player;
			readonly achievement: Acore.AchievementEntry;
		};
		['before-achievement-complete']: {
			readonly player: Acore.Player;
			readonly achievement: Acore.AchievementEntry;
			readonly __return: Acore.Box<boolean>;
		};
		['criteria-progress']: {
			readonly player: Acore.Player;
			// readonly criteria: Acore.AchievementCriteriaEntry;
		};
		['before-criteria-progress']: {
			readonly player: Acore.Player;
			// readonly criteria: Acore.AchievementCriteriaEntry;
			readonly __return: Acore.Box<boolean>;
		};
		['achievement-save']: {
			readonly player: Acore.Player;
			readonly achId: number;
			// readonly achiData: Acore.CompletedAchievementData;
		};
		['criteria-save']: {
			readonly player: Acore.Player;
			readonly achId: number;
			// readonly criteriaData: Acore.CriteriaProgress;
		};
		['gossip-select']: {
			readonly player: Acore.Player;
			readonly menuId: number;
			readonly sender: GossipSender;
			readonly action: GossipAction;
		};
		['gossip-select-code']: {
			readonly player: Acore.Player;
			readonly menuId: number;
			readonly sender: GossipSender;
			readonly action: GossipAction;
			readonly code: string;
		};
		['being-charmed']: {
			readonly player: Acore.Player;
			readonly charmer: Acore.Unit;
			readonly oldFactionId: number;
			readonly newFactionId: number;
		};
		['after-set-visible-item-slot']: {
			readonly player: Acore.Player;
			readonly slot: number;
			readonly item: Acore.Item;
		};
		['after-move-item-from-inventory']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly bag: number;
			readonly slot: number;
			readonly update: boolean;
		};
		['equip']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly bag: number;
			readonly slot: number;
			readonly update: boolean;
		};
		['unequip']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
		};
		['join-bg']: { readonly player: Acore.Player; };
		['join-arena']: { readonly player: Acore.Player; };
		['get-max-personal-arena-rating-requirement']: {
			readonly player: Acore.Player;
			readonly minSlot: number;
			readonly maxArenaRating: Acore.Box<number>;
		};
		['loot-item']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly count: number;
			readonly lootGuid: bigint | undefined;
		};
		['before-fill-quest-loot-item']: {
			readonly player: Acore.Player;
			// TODO: this shouldn't be readonly, I think I just need to abandon the whole idea of
			// "records" being a separate thing. "templates" are extremely easy now, and very nearly
			// everything that can be a "record" can also be a "template"
			readonly item: LootItem;
		};
		['store-new-item']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly count: number;
		};
		['create-item']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly count: number;
		};
		['quest-reward-item']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly count: number;
		};
		['can-place-auction-bid']: {
			readonly player: Acore.Player;
			readonly auction: Acore.Auction;
			readonly __return: Acore.Box<boolean>;
		};
		['group-roll-reward-item']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly count: number;
			readonly voteType: RollVote;
			readonly roll: Acore.Roll;
		};
		['before-open-item']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly __return: Acore.Box<boolean>;
		};
		['before-quest-complete']: {
			readonly player: Acore.Player;
			readonly questId: number;
			readonly __return: Acore.Box<boolean>;
		};
		['quest-compute-xp']: {
			readonly player: Acore.Player;
			readonly quest: Acore.Quest;
			readonly xpValue: Acore.Box<number>;
		};
		['before-durability-repair']: {
			readonly player: Acore.Player;
			readonly npcGuid: bigint;
			readonly itemGuid: bigint;
			readonly discountMod: Acore.Box<number>;
			readonly guildBank: boolean;
		};
		['before-buy-item-from-vendor']: {
			readonly player: Acore.Player;
			readonly vendorGuid: bigint;
			readonly vendorSlot: number;
			readonly item: Acore.Box<number>;
			readonly count: number;
			readonly bag: number;
			readonly slot: number;
		};
		['before-store-or-equip-new-item']: {
			readonly player: Acore.Player;
			readonly vendorSlot: number;
			readonly item: Acore.Box<number>;
			readonly count: number;
			readonly bag: number;
			readonly slot: number;
			readonly proto: Acore.ItemTemplateNarrowable;
			readonly vendor: Acore.Creature;
			// readonly crItem: Acore.VendorItem;
			readonly store: boolean;
		};
		['after-store-or-equip-new-item']: {
			readonly player: Acore.Player;
			readonly vendorSlot: number;
			readonly item: Acore.Item;
			readonly count: number;
			readonly bag: number;
			readonly slot: number;
			readonly proto: Acore.ItemTemplateNarrowable;
			readonly vendor: Acore.Creature;
			// readonly crItem: Acore.VendorItem;
			readonly store: boolean;
		};
		['after-update-max-power']: {
			readonly player: Acore.Player;
			readonly power: Acore.Box<Powers>;
			readonly value: Acore.Box<number>;
		};
		['after-update-max-health']: {
			readonly player: Acore.Player;
			readonly value: Acore.Box<number>;
		};
		['before-update-attack-power-and-damage']: {
			readonly player: Acore.Player;
			readonly level: Acore.Box<number>;
			readonly val2: Acore.Box<number>;
			readonly ranged: boolean;
		};
		['after-update-attack-power-and-damage']: {
			readonly player: Acore.Player;
			readonly level: Acore.Box<number>;
			readonly baseAttPower: Acore.Box<number>;
			readonly attPowerMod: Acore.Box<number>;
			readonly attPowerMultiplier: Acore.Box<number>;
			readonly ranged: boolean;
		};
		['before-init-talent-for-level']: {
			readonly player: Acore.Player;
			readonly level: Acore.Box<number>;
			readonly talentPointsForLevel: Acore.Box<number>;
		};
		['first-login']: { readonly player: Acore.Player; };
		['set-max-level']: {
			readonly player: Acore.Player;
			readonly maxPlayerLevel: Acore.Box<number>;
		};
		['can-join-in-battleground-queue']: {
			readonly player: Acore.Player;
			readonly battlemasterGuid: bigint | undefined;
			readonly bgTypeId: BattlegroundTypeId;
			readonly joinAsGroup: boolean;
			readonly err: Acore.Box<GroupJoinBattlegroundResult>;
			readonly __return: Acore.Box<boolean>;
		};
		['should-be-rewarded-with-money-instead-of-exp']: {
			readonly player: Acore.Player;
			readonly __return: Acore.Box<boolean>;
		};
		['before-temp-summon-init-stats']: {
			readonly player: Acore.Player;
			readonly tempSummon: Acore.TempSummon;
			readonly duration: Acore.Box<Temporal.Duration>;
		};
		['before-guardian-init-stats-for-level']: {
			readonly player: Acore.Player;
			readonly guardian: Acore.Guardian;
			readonly cInfo: Acore.CreatureTemplate;
			readonly petType: Acore.Box<PetType>;
		};
		['after-guardian-init-stats-for-level']: {
			readonly player: Acore.Player;
			readonly guardian: Acore.Guardian;
		};
		['before-load-pet-from-db']: {
			readonly player: Acore.Player;
			readonly petEntry: Acore.Box<number>;
			readonly petNumber: Acore.Box<number>;
			readonly current: Acore.Box<boolean>;
			readonly forceLoadFromDB: Acore.Box<boolean>;
		};
		['can-join-in-arena-queue']: {
			readonly player: Acore.Player;
			readonly battlemasterGuid: bigint;
			readonly arenaSlot: number;
			readonly bgTypeId: number; // BattlegroundTypeId enum in native, but clearly it's not one of those.
			readonly joinAsGroup: boolean;
			readonly isRated: boolean;
			readonly err: Acore.Box<GroupJoinBattlegroundResult>;
			readonly __return: Acore.Box<boolean>;
		};
		['can-battle-field-port']: {
			readonly player: Acore.Player;
			readonly arenaType: ArenaType;
			readonly bgTypeId: BattlegroundTypeId;
			readonly action: number; // from a comment: enter battle 0x1, leave queue 0x0
			readonly __return: Acore.Box<boolean>;
		};
		['can-group-invite']: {
			readonly player: Acore.Player;
			readonly memberName: Acore.Box<string>;
			readonly __return: Acore.Box<boolean>;
		};
		['can-group-accept']: {
			readonly player: Acore.Player;
			readonly group: Acore.Group;
			readonly __return: Acore.Box<boolean>;
		};
		['can-sell-item']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly creature: Acore.Creature;
			readonly __return: Acore.Box<boolean>;
		};
		['can-send-mail']: {
			readonly player: Acore.Player;
			readonly receiverGuid: bigint;
			readonly mailbox: bigint;
			readonly subject: Acore.Box<string>;
			readonly body: Acore.Box<string>;
			readonly money: number;
			readonly cod: number;
			readonly item: Acore.Item | undefined;
			readonly __return: Acore.Box<boolean>;
		};
		['petition-buy']: {
			readonly player: Acore.Player;
			readonly creature: Acore.Creature;
			readonly charterId: Acore.Box<number>;
			readonly cost: Acore.Box<number>;
			readonly type: Acore.Box<CharterTypes>;
		};
		['petition-show-list']: {
			readonly player: Acore.Player;
			readonly creature: Acore.Creature;
			readonly charterEntry: Acore.Box<number>;
			readonly charterDisplayId: Acore.Box<number>;
			readonly charterCost: Acore.Box<number>;
		};
		['reward-kill-rewarder']: {
			readonly player: Acore.Player;
			// readonly rewarder: Acore.KillRewarder;
			readonly isDungeon: boolean;
			readonly rate: Acore.Box<number>;
		};
		['can-give-mail-reward-at-give-level']: {
			readonly player: Acore.Player;
			readonly level: number;
			readonly __return: Acore.Box<boolean>;
		};
		['delete-from-db']: {
			readonly guid: bigint;
		};
		['can-repop-at-graveyard']: {
			readonly player: Acore.Player;
			readonly __return: Acore.Box<boolean>;
		};
		['is-class']: {
			readonly player: Acore.Player;
			readonly playerClass: Classes;
			readonly context: ClassContext;
			readonly __return: Acore.Box<boolean | undefined>;
		};
		['get-max-skill-value']: {
			readonly player: Acore.Player;
			readonly skill: SkillType;
			readonly result: Acore.Box<number>;
			readonly isPure: boolean;
		};
		['has-active-power-type']: {
			readonly player: Acore.Player;
			readonly power: Powers;
			readonly __return: Acore.Box<boolean>;
		};
		['update-gathering-skill']: {
			readonly player: Acore.Player;
			readonly skillId: SkillType;
			readonly current: number;
			readonly gray: number;
			readonly green: number;
			readonly yellow: number;
			readonly gain: Acore.Box<number>;
		};
		['update-crafting-skill']: {
			readonly player: Acore.Player;
			// readonly skill: Acore.SkillLineAbilityEntry;
			readonly currentLevel: number;
			readonly gain: Acore.Box<number>;
		};
		['update-fishing-skill']: {
			readonly player: Acore.Player;
			readonly skill: number;
			readonly zoneSkill: number;
			readonly chance: number;
			readonly roll: number;
			readonly __return: Acore.Box<boolean>;
		};
		['can-area-explore-and-outdoor']: {
			readonly player: Acore.Player;
			readonly __return: Acore.Box<boolean>;
		};
		['victim-reward-before']: {
			readonly player: Acore.Player;
			readonly victim: Acore.Player;
			readonly killerTitle: Acore.Box<number>;
			readonly victimRank: Acore.Box<number>;
		};
		['victim-reward-after']: {
			readonly player: Acore.Player;
			readonly victim: Acore.Player;
			readonly killerTitle: Acore.Box<number>;
			readonly victimRank: Acore.Box<number>;
			readonly honor: Acore.Box<number>;
		};
		['custom-scaling-stat-value-before']: {
			readonly player: Acore.Player;
			readonly proto: Acore.ItemTemplateNarrowable;
			readonly slot: number;
			readonly apply: boolean;
			readonly customScalingStatValue: Acore.Box<number>;
		};
		['custom-scaling-stat-value']: {
			readonly player: Acore.Player;
			readonly proto: Acore.ItemTemplateNarrowable;
			readonly statType: Acore.Box<Stats>;
			readonly val: Acore.Box<number>;
			readonly itemProtoStatNumber: number;
			readonly scalingStatValue: number;
			// readonly ssv: Acore.ScalingStatValuesEntry;
		};
		['apply-item-mods-before']: {
			readonly player: Acore.Player;
			readonly slot: number;
			readonly apply: boolean;
			readonly itemProtoStatNumber: number;
			readonly statType: Stats;
			readonly val: Acore.Box<number>;
		};
		['apply-enchantment-item-mods-before']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly slot: EnchantmentSlot;
			readonly apply: boolean;
			readonly enchantSpellId: number;
			readonly enchantAmount: Acore.Box<number>;
		};
		['apply-weapon-damage']: {
			readonly player: Acore.Player;
			readonly slot: number;
			readonly proto: Acore.ItemTemplateNarrowable;
			readonly minDamage: Acore.Box<number>;
			readonly maxDamage: Acore.Box<number>;
			readonly damageIndex: number;
		};
		['can-armor-damage-modifier']: {
			readonly player: Acore.Player;
			readonly __return: Acore.Box<boolean>;
		};
		['get-feral-ap-bonus']: {
			readonly player: Acore.Player;
			readonly feralBonus: Acore.Box<number>;
			readonly dpsMod: number;
			readonly proto: Acore.ItemTemplateNarrowable;
			// readonly ssv: Acore.ScalingStatValuesEntry;
		};
		['can-apply-weapon-dependent-aura-damage-mod']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly attackType: WeaponAttackType;
			readonly aura: Acore.AuraEffect;
			readonly apply: boolean;
			readonly __return: Acore.Box<boolean>;
		};
		['can-apply-equip-spell']: {
			readonly player: Acore.Player;
			readonly spellInfo: Acore.SpellInfo;
			readonly item: Acore.Item;
			readonly apply: boolean;
			readonly formChange: boolean;
			readonly __return: Acore.Box<boolean>;
		};
		['can-apply-equip-spells-item-set']: {
			readonly player: Acore.Player;
			// readonly eff: Acore.ItemSetEffect;
			readonly __return: Acore.Box<boolean>;
		};
		['can-cast-item-combat-spell']: {
			readonly player: Acore.Player;
			readonly target: Acore.Unit;
			readonly attType: WeaponAttackType;
			readonly procVictim: ProcFlags;
			readonly procEx: ProcFlagsHit;
			readonly item: Acore.Item;
			readonly proto: Acore.ItemTemplateNarrowable;
			readonly __return: Acore.Box<boolean>;
		};
		['can-cast-item-use-spell']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			// readonly targets: Acore.SpellCastTargets;
			readonly castCount: number;
			readonly glyphIndex: number;
			readonly __return: Acore.Box<boolean>;
		};
		['apply-ammo-bonuses']: {
			readonly player: Acore.Player;
			readonly proto: Acore.ItemTemplateNarrowable;
			readonly currentAmmoDps: Acore.Box<number>;
		};
		['can-equip-item']: {
			readonly player: Acore.Player;
			readonly slot: number;
			readonly dest: Acore.Box<number>;
			readonly item: Acore.Item;
			readonly swap: boolean;
			readonly notLoading: boolean;
			readonly __return: Acore.Box<boolean>;
		};
		['can-unequip-item']: {
			readonly player: Acore.Player;
			readonly pos: number;
			readonly swap: boolean;
			readonly __return: Acore.Box<boolean>;
		};
		['can-use-item']: {
			readonly player: Acore.Player;
			readonly proto: Acore.ItemTemplateNarrowable;
			readonly result: Acore.Box<InventoryResult>;
			readonly __return: Acore.Box<boolean>;
		};
		['can-save-equip-new-item']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly pos: number;
			readonly update: boolean;
			readonly __return: Acore.Box<boolean>;
		};
		['can-apply-enchantment']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly slot: number;
			readonly apply: boolean;
			readonly applyDur: boolean;
			readonly ignoreCondition: boolean;
			readonly __return: Acore.Box<boolean>;
		};
		['get-quest-rate']: {
			readonly player: Acore.Player;
			readonly result: Acore.Box<number>;
		};
		['passed-quest-killed-monster-credit']: {
			readonly player: Acore.Player;
			readonly qInfo: Acore.Quest;
			readonly entry: number;
			readonly realEntry: number;
			readonly guid: bigint | undefined;
			readonly __return: Acore.Box<boolean>;
		};
		['check-item-in-slot-at-load-inventory']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly slot: number;
			readonly err: Acore.Box<InventoryResult>;
			readonly dest: Acore.Box<number>;
			readonly __return: Acore.Box<boolean>;
		};
		['not-avoid-satisfy']: {
			readonly player: Acore.Player;
			// readonly ar: Acore.DungeonProgressionRequirements;
			readonly targetMap: number;
			readonly report: boolean;
			readonly __return: Acore.Box<boolean>;
		};
		['not-visible-globally-for']: {
			readonly player: Acore.Player;
			readonly u: Acore.Player;
			readonly __return: Acore.Box<boolean>;
		};
		['get-arena-personal-rating']: {
			readonly player: Acore.Player;
			readonly slot: number;
			readonly result: Acore.Box<number>;
		};
		['get-arena-team-id']: {
			readonly player: Acore.Player;
			readonly slot: number;
			readonly result: Acore.Box<number>;
		};
		['is-ffa-pvp']: {
			readonly player: Acore.Player;
			readonly result: Acore.Box<boolean>;
		};
		['ffa-pvp-state-update']: {
			readonly player: Acore.Player;
			readonly result: boolean;
		};
		['is-pvp']: {
			readonly player: Acore.Player;
			readonly result: Acore.Box<boolean>;
		};
		['get-max-skill-value-for-level']: {
			readonly player: Acore.Player;
			readonly result: Acore.Box<number>;
		};
		['not-set-arena-team-info-field']: {
			readonly player: Acore.Player;
			readonly slot: number;
			readonly type: ArenaTeamInfoType;
			readonly value: number;
			readonly __return: Acore.Box<boolean>;
		};
		['can-join-lfg']: {
			readonly player: Acore.Player;
			readonly roles: LfgRoles;
			// dungeons: ReadonlySet<number>;
			readonly comment: string;
			readonly __return: Acore.Box<boolean>;
		};
		['can-enter-map']: {
			readonly player: Acore.Player;
			// readonly entry: Acore.MapEntry;
			// readonly instance: Acore.InstanceTemplate;
			// readonly mapDiff: Acore.MapDifficulty;
			readonly loginCheck: boolean;
			readonly __return: Acore.Box<boolean>;
		};
		['can-init-trade']: {
			readonly player: Acore.Player;
			readonly target: Acore.Player;
			readonly __return: Acore.Box<boolean>;
		};
		['can-set-trade-item']: {
			readonly player: Acore.Player;
			readonly tradedItem: Acore.Item;
			readonly tradeSlot: number;
			readonly __return: Acore.Box<boolean>;
		};
		['set-server-side-visibility']: {
			readonly player: Acore.Player;
			readonly type: Acore.Box<ServerSideVisibilityType>;
			readonly sec: Acore.Box<AccountTypes>;
		};
		['set-server-side-visibility-detect']: {
			readonly player: Acore.Player;
			readonly type: Acore.Box<ServerSideVisibilityType>;
			readonly sec: Acore.Box<AccountTypes>;
		};
		['resurrect']: {
			readonly player: Acore.Player;
			readonly restorePercent: number;
			readonly applySickness: Acore.Box<boolean>;
		};
		['before-choose-graveyard']: {
			readonly player: Acore.Player;
			readonly teamId: TeamId;
			readonly nearCorpse: boolean;
			readonly graveyardOverride: Acore.Box<number>;
		};
		['can-use-chat']: {
			readonly player: Acore.Player;
			readonly type: ChatMsg;
			readonly lang: Language;
			readonly msg: Acore.Box<string>;
			readonly __return: Acore.Box<boolean>;
		};
		['can-use-chat:player']: {
			readonly player: Acore.Player;
			readonly type: ChatMsg;
			readonly lang: Language;
			readonly msg: Acore.Box<string>;
			readonly receiver: Acore.Player;
			readonly __return: Acore.Box<boolean>;
		};
		['can-use-chat:group']: {
			readonly player: Acore.Player;
			readonly type: ChatMsg;
			readonly lang: Language;
			readonly msg: Acore.Box<string>;
			readonly group: Acore.Group;
			readonly __return: Acore.Box<boolean>;
		};
		['can-use-chat:guild']: {
			readonly player: Acore.Player;
			readonly type: ChatMsg;
			readonly lang: Language;
			readonly msg: Acore.Box<string>;
			readonly guild: Acore.Guild;
			readonly __return: Acore.Box<boolean>;
		};
		['can-use-chat:channel']: {
			readonly player: Acore.Player;
			readonly type: ChatMsg;
			readonly lang: Language;
			readonly msg: Acore.Box<string>;
			readonly channel: Acore.Channel;
			readonly __return: Acore.Box<boolean>;
		};
		['learn-talents']: {
			readonly player: Acore.Player;
			readonly talentId: number;
			readonly talentRank: number;
			readonly spellId: number;
		};
		['enter-combat']: {
			readonly player: Acore.Player;
			readonly enemy: Acore.Unit;
		};
		['leave-combat']: { readonly player: Acore.Player; };
		['quest-abandon']: {
			readonly player: Acore.Player;
			readonly questId: number;
		};
		['quest-accept']: {
			readonly player: Acore.Player;
			readonly quest: Acore.Quest;
		};
		['can-fly-in-zone']: {
			readonly player: Acore.Player;
			readonly mapId: number;
			readonly zoneId: number;
			readonly bySpell: Acore.SpellInfo;
			readonly __return: Acore.Box<boolean>;
		};
		['anticheat:set-can-flyby-server']: {
			readonly player: Acore.Player;
			readonly apply: boolean;
		};
		['anticheat:set-under-ack-mount']: { readonly player: Acore.Player; };
		['anticheat:set-root-ack-upd']: { readonly player: Acore.Player; };
		['anticheat:set-jumping-by-opcode']: {
			readonly player: Acore.Player;
			readonly jump: boolean;
		};
		['anticheat:update-movement-info']: {
			readonly player: Acore.Player;
			// readonly movementInfo: Acore.MovementInfo;
		};
		['anticheat-handle-double-jump']: {
			readonly player: Acore.Player;
			readonly mover: Acore.Unit;
			readonly __return: Acore.Box<boolean>;
		};
		['anticheat-check-movement-info']: {
			readonly player: Acore.Player;
			// readonly movementInfo: Acore.MovementInfo;
			readonly mover: Acore.Unit;
			readonly jump: boolean;
			readonly __return: Acore.Box<boolean>;
		};
		['can-send-error-already-looted']: {
			readonly player: Acore.Player;
			readonly __return: Acore.Box<boolean>;
		};
		['after-creature-loot']: { readonly player: Acore.Player; };
		['after-creature-loot-money']: { readonly player: Acore.Player; };
		['can-update-skill']: {
			readonly player: Acore.Player;
			readonly skillId: SkillType;
			readonly __return: Acore.Box<boolean>;
		};
		['before-update-skill']: {
			readonly player: Acore.Player;
			readonly skillId: SkillType;
			readonly value: Acore.Box<number>;
			readonly max: number;
			readonly step: number;
		};
		['update-skill']: {
			readonly player: Acore.Player;
			readonly skillId: SkillType;
			readonly value: number;
			readonly max: number;
			readonly step: number;
			readonly newValue: number;
		};
		['set-skill']: {
			readonly player: Acore.Player;
			readonly skillId: SkillType;
			readonly value: number;
			readonly max: number;
			readonly step: number;
			readonly newValue: number;
		};
		['can-resurrect']: {
			readonly player: Acore.Player;
			readonly __return: Acore.Box<boolean>;
		};
		['can-give-level']: {
			readonly player: Acore.Player;
			readonly newLevel: number;
			readonly __return: Acore.Box<boolean>;
		};
		['send-list-inventory']: {
			readonly player: Acore.Player;
			readonly vendorGuid: bigint;
			readonly vendorEntry: Acore.Box<number>;
		};
		['get-reputation-price-discount:by-creature']: {
			readonly player: Acore.Player;
			readonly creature: Acore.Creature;
			readonly discount: Acore.Box<number>;
		};
		['get-reputation-price-discount']: {
			readonly player: Acore.Player;
			// readonly factionTemplate: Acore.FactionTemplateEntry;
			readonly discount: Acore.Box<number>;
		};
		['learn-taxi-node']: {
			readonly player: Acore.Player;
			readonly nodeId: number;
		};
		['before-get-level-for-xp-gain']: {
			readonly player: Acore.Player;
			readonly level: Acore.Box<number>;
		};
	}
}
export {};
