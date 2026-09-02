declare global {
	interface Hooks {
		['player:just-died']: { readonly player: Acore.Player; };
		['player:calculate-talents-points']: {
			readonly player: Acore.Player;
			talentPointsForLevel: number;
		};
		['player:released-ghost']: { readonly player: Acore.Player; };
		['player:send-initial-packets-before-add-to-map']: {
			readonly player: Acore.Player;
			// data: Acore.WorldPacket;
		};
		['player:battleground-desertion']: {
			readonly player: Acore.Player;
			readonly desertionType: BattlegroundDesertionType;
		};
		['player:complete-quest']: {
			readonly player: Acore.Player;
			readonly quest: Acore.Quest;
		};
		['player:pvp-kill']: {
			readonly killer: Acore.Player;
			readonly killed: Acore.Player;
		};
		['player:pvp-flag-change']: {
			readonly player: Acore.Player;
			readonly state: boolean;
		};
		['player:creature-kill']: {
			readonly killer: Acore.Player;
			readonly killed: Acore.Creature;
		};
		['player:creature-killed-by-pet']: {
			readonly petOwner: Acore.Player;
			readonly killed: Acore.Creature;
		};
		['player:killed-by-creature']: {
			readonly killer: Acore.Creature;
			readonly killed: Acore.Player;
		};
		['player:level-changed']: {
			readonly player: Acore.Player;
			readonly oldLevel: number;
		};
		['player:free-talent-points-changed']: {
			readonly player: Acore.Player;
			readonly points: number;
		};
		['player:talents-reset']: {
			readonly player: Acore.Player;
			readonly noCost: boolean;
		};
		['player:can-learn-talent']: {
			readonly player: Acore.Player;
			// readonly talent: TalentEntry;
			readonly rank: number;
			__return: boolean;
		};
		['player:after-spec-slot-changed']: {
			readonly player: Acore.Player;
			readonly newSlot: number;
		};
		['player:before-update']: {
			readonly player: Acore.Player;
			readonly diff: Temporal.Duration;
		};
		['player:update']: {
			readonly player: Acore.Player;
			readonly diff: Temporal.Duration;
		};
		['player:money-changed']: {
			readonly player: Acore.Player;
			amount: number;
		};
		['player:before-loot-money']: {
			readonly player: Acore.Player;
			readonly loot: Acore.Loot;
		};
		['player:give-xp']: {
			readonly player: Acore.Player;
			amount: number;
			readonly victim: Acore.Unit | undefined;
			readonly xpSource: PlayerXPSource;
		};
		['player:reputation-change']: {
			readonly player: Acore.Player;
			readonly factionId: number;
			standing: number;
			readonly incremental: boolean;
			__return: boolean;
		};
		['player:reputation-rank-change']: {
			readonly player: Acore.Player;
			readonly factionId: number;
			readonly newRank: ReputationRank;
			readonly oldRank: ReputationRank;
			readonly increased: boolean;
		};
		['player:give-reputation']: {
			readonly player: Acore.Player;
			readonly factionId: number;
			amount: number;
			readonly repSource: ReputationSource;
		};
		['player:learn-spell']: {
			readonly player: Acore.Player;
			readonly spellId: number;
		};
		['player:forgot-spell']: {
			readonly player: Acore.Player;
			readonly spellId: number;
		};
		['player:duel-request']: {
			readonly target: Acore.Player;
			readonly challenger: Acore.Player;
		};
		['player:duel-start']: {
			readonly player1: Acore.Player;
			readonly player2: Acore.Player;
		};
		['player:duel-end']: {
			readonly winner: Acore.Player;
			readonly loser: Acore.Player;
			readonly type: DuelCompleteType;
		};
		['player:before-send-chat-message']: {
			readonly player: Acore.Player;
			type: ChatMsg;
			lang: Language;
			msg: string;
		};
		['player:emote']: {
			readonly player: Acore.Player;
			readonly emote: Emote;
		};
		['player:text-emote']: {
			readonly player: Acore.Player;
			readonly textEmote: TextEmotes;
			readonly emoteNum: number; // ?
			readonly guid: bigint | undefined;
		};
		['player:spell-cast']: {
			readonly player: Acore.Player;
			readonly spell: Acore.Spell;
			readonly skipCheck: boolean;
		};
		['player:load-from-db']: { readonly player: Acore.Player; };
		['player:login']: { readonly player: Acore.Player; };
		['player:before-logout']: { readonly player: Acore.Player; };
		['player:logout']: { readonly player: Acore.Player; };
		['player:create']: { readonly player: Acore.Player; };
		['player:delete']: {
			readonly guid: bigint;
			readonly accountId: number;
		};
		['player:failed-delete']: {
			readonly guid: bigint;
			readonly accountId: number;
		};
		['player:save']: { readonly player: Acore.Player; };
		['player:bind-to-instance']: {
			readonly player: Acore.Player;
			readonly difficulty: Difficulty;
			readonly mapId: number;
			readonly permanent: boolean;
		};
		['player:update-zone']: {
			readonly player: Acore.Player;
			readonly newZone: number;
			readonly newArea: number;
		};
		['player:update-area']: {
			readonly player: Acore.Player;
			readonly oldArea: number;
			readonly newArea: number;
		};
		['player:map-changed']: { readonly player: Acore.Player; };
		['player:before-teleport']: {
			readonly player: Acore.Player;
			readonly mapId: number;
			readonly x: number;
			readonly y: number;
			readonly z: number;
			readonly o: number;
			readonly options: TeleportToOptions;
			readonly target: Acore.Unit | undefined;
			__return: boolean;
		};
		['player:update-faction']: { readonly player: Acore.Player; };
		['player:add-to-battleground']: {
			readonly player: Acore.Player;
			readonly bg: Acore.Battleground;
		};
		['player:queue-random-dungeon']: {
			readonly player: Acore.Player;
			rDungeonId: number;
		};
		['player:remove-from-battleground']: {
			readonly player: Acore.Player;
			readonly bg: Acore.Battleground;
		};
		['player:achievement-complete']: {
			readonly player: Acore.Player;
			readonly achievement: Acore.AchievementEntry;
		};
		['player:before-achievement-complete']: {
			readonly player: Acore.Player;
			readonly achievement: Acore.AchievementEntry;
			__return: boolean;
		};
		['player:criteria-progress']: {
			readonly player: Acore.Player;
			// readonly criteria: Acore.AchievementCriteriaEntry;
		};
		['player:before-criteria-progress']: {
			readonly player: Acore.Player;
			// readonly criteria: Acore.AchievementCriteriaEntry;
			__return: boolean;
		};
		// ['player:achievement-save']: unknown; // thinking about the transaction arg right now...
		// ['player:criteria-save']: unknown; // thinking about the transaction arg right now...
		['player:gossip-select']: {
			readonly player: Acore.Player;
			readonly menuId: number;
			readonly sender: GossipSender;
			readonly action: GossipAction;
		};
		['player:gossip-select-code']: {
			readonly player: Acore.Player;
			readonly menuId: number;
			readonly sender: GossipSender;
			readonly action: GossipAction;
			readonly code: string;
		};
		['player:being-charmed']: {
			readonly player: Acore.Player;
			readonly charmer: Acore.Unit;
			readonly oldFactionId: number;
			readonly newFactionId: number;
		};
		['player:after-set-visible-item-slot']: {
			readonly player: Acore.Player;
			readonly slot: number;
			readonly item: Acore.Item;
		};
		['player:after-move-item-from-inventory']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly bag: number;
			readonly slot: number;
			readonly update: boolean;
		};
		['player:equip']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly bag: number;
			readonly slot: number;
			readonly update: boolean;
		};
		['player:unequip']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
		};
		['player:join-bg']: { readonly player: Acore.Player; };
		['player:join-arena']: { readonly player: Acore.Player; };
		['player:get-max-personal-arena-rating-requirement']: {
			readonly player: Acore.Player;
			readonly minSlot: number;
			maxArenaRating: number;
		};
		['player:loot-item']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly count: number;
			readonly lootGuid: bigint | undefined;
		};
		['player:before-fill-quest-loot-item']: {
			readonly player: Acore.Player;
			// TODO: this shouldn't be readonly, I think I just need to abandon the whole idea of
			// "records" being a separate thing. "templates" are extremely easy now, and very nearly
			// everything that can be a "record" can also be a "template"
			readonly item: LootItem;
		};
		['player:store-new-item']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly count: number;
		};
		['player:create-item']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly count: number;
		};
		['player:quest-reward-item']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly count: number;
		};
		['player:can-place-auction-bid']: {
			readonly player: Acore.Player;
			readonly auction: Acore.Auction;
			__return: boolean;
		};
		['player:group-roll-reward-item']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly count: number;
			readonly voteType: RollVote;
			readonly roll: Acore.Roll;
		};
		['player:before-open-item']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			__return: boolean;
		};
		['player:before-quest-complete']: {
			readonly player: Acore.Player;
			readonly questId: number;
			__return: boolean;
		};
		['player:quest-compute-xp']: {
			readonly player: Acore.Player;
			readonly quest: Acore.Quest;
			xpValue: number;
		};
		['player:before-durability-repair']: {
			readonly player: Acore.Player;
			readonly npcGuid: bigint;
			readonly itemGuid: bigint;
			discountMod: number;
			readonly guildBank: boolean;
		};
		['player:before-buy-item-from-vendor']: {
			readonly player: Acore.Player;
			readonly vendorGuid: bigint;
			readonly vendorSlot: number;
			item: number;
			readonly count: number;
			readonly bag: number;
			readonly slot: number;
		};
		['player:before-store-or-equip-new-item']: {
			readonly player: Acore.Player;
			readonly vendorSlot: number;
			item: number;
			readonly count: number;
			readonly bag: number;
			readonly slot: number;
			readonly proto: Acore.ItemTemplateNarrowable;
			readonly vendor: Acore.Creature;
			// readonly crItem: Acore.VendorItem;
			readonly store: boolean;
		};
		['player:after-store-or-equip-new-item']: {
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
		['player:after-update-max-power']: {
			readonly player: Acore.Player;
			power: Powers;
			value: number;
		};
		['player:after-update-max-health']: {
			readonly player: Acore.Player;
			value: number;
		};
		['player:before-update-attack-power-and-damage']: {
			readonly player: Acore.Player;
			level: number;
			val2: number;
			readonly ranged: boolean;
		};
		['player:after-update-attack-power-and-damage']: {
			readonly player: Acore.Player;
			level: number;
			baseAttPower: number;
			attPowerMod: number;
			attPowerMultiplier: number;
			readonly ranged: boolean;
		};
		['player:before-init-talent-for-level']: {
			readonly player: Acore.Player;
			level: number;
			talentPointsForLevel: number;
		};
		['player:first-login']: { readonly player: Acore.Player; };
		['player:set-max-level']: {
			readonly player: Acore.Player;
			maxPlayerLevel: number;
		};
		['player:can-join-in-battleground-queue']: {
			readonly player: Acore.Player;
			readonly battlemasterGuid: bigint | undefined;
			readonly bgTypeId: BattlegroundTypeId;
			readonly joinAsGroup: boolean;
			err: GroupJoinBattlegroundResult;
			__return: boolean;
		};
		['player:should-be-rewarded-with-money-instead-of-exp']: {
			readonly player: Acore.Player;
			__return: boolean;
		};
		['player:before-temp-summon-init-stats']: {
			readonly player: Acore.Player;
			readonly tempSummon: Acore.TempSummon;
			duration: Temporal.Duration;
		};
		['player:before-guardian-init-stats-for-level']: {
			readonly player: Acore.Player;
			readonly guardian: Acore.Guardian;
			readonly cInfo: Acore.CreatureTemplate;
			petType: PetType;
		};
		['player:after-guardian-init-stats-for-level']: {
			readonly player: Acore.Player;
			readonly guardian: Acore.Guardian;
		};
		['player:before-load-pet-from-db']: {
			readonly player: Acore.Player;
			petEntry: number;
			petNumber: number;
			current: boolean;
			forceLoadFromDB: boolean;
		};
		['player:can-join-in-arena-queue']: {
			readonly player: Acore.Player;
			readonly battlemasterGuid: bigint;
			readonly arenaSlot: number;
			readonly bgTypeId: number; // BattlegroundTypeId enum in native, but clearly it's not one of those.
			readonly joinAsGroup: boolean;
			readonly isRated: boolean;
			err: GroupJoinBattlegroundResult;
			__return: boolean;
		};
		['player:can-battle-field-port']: {
			readonly player: Acore.Player;
			readonly arenaType: ArenaType;
			readonly bgTypeId: BattlegroundTypeId;
			readonly action: number; // from a comment: enter battle 0x1, leave queue 0x0
			__return: boolean;
		};
		['player:can-group-invite']: {
			readonly player: Acore.Player;
			memberName: string;
			__return: boolean;
		};
		['player:can-group-accept']: {
			readonly player: Acore.Player;
			readonly group: Acore.Group;
			__return: boolean;
		};
		['player:can-sell-item']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly creature: Acore.Creature;
			__return: boolean;
		};
		['player:can-send-mail']: {
			readonly player: Acore.Player;
			readonly receiverGuid: bigint;
			readonly mailbox: bigint;
			subject: string;
			body: string;
			readonly money: number;
			readonly cod: number;
			readonly item: Acore.Item | undefined;
			__return: boolean;
		};
		['player:petition-buy']: {
			readonly player: Acore.Player;
			readonly creature: Acore.Creature;
			charterId: number;
			cost: number;
			type: CharterTypes;
		};
		['player:petition-show-list']: {
			readonly player: Acore.Player;
			readonly creature: Acore.Creature;
			charterEntry: number;
			charterDisplayId: number;
			charterCost: number;
		};
		['player:reward-kill-rewarder']: {
			readonly player: Acore.Player;
			// readonly rewarder: Acore.KillRewarder;
			readonly isDungeon: boolean;
			rate: number;
		};
		['player:can-give-mail-reward-at-give-level']: {
			readonly player: Acore.Player;
			readonly level: number;
			__return: boolean;
		};
		// ['player:delete-from-db']: unknown; // thinking about the transaction arg right now...
		['player:can-repop-at-graveyard']: {
			readonly player: Acore.Player;
			__return: boolean;
		};
		['player:is-class']: {
			readonly player: Acore.Player;
			readonly playerClass: Classes;
			readonly context: ClassContext;
			__return: boolean | undefined;
		};
		['player:get-max-skill-value']: {
			readonly player: Acore.Player;
			readonly skill: SkillType;
			result: number;
			readonly isPure: boolean;
		};
		['player:has-active-power-type']: {
			readonly player: Acore.Player;
			readonly power: Powers;
			__return: boolean;
		};
		['player:update-gathering-skill']: {
			readonly player: Acore.Player;
			readonly skillId: SkillType;
			readonly current: number;
			readonly gray: number;
			readonly green: number;
			readonly yellow: number;
			gain: number;
		};
		['player:update-crafting-skill']: {
			readonly player: Acore.Player;
			// readonly skill: Acore.SkillLineAbilityEntry;
			readonly currentLevel: number;
			gain: number;
		};
		['player:update-fishing-skill']: {
			readonly player: Acore.Player;
			readonly skill: number;
			readonly zoneSkill: number;
			readonly chance: number;
			readonly roll: number;
			__return: boolean;
		};
		['player:can-area-explore-and-outdoor']: {
			readonly player: Acore.Player;
			__return: boolean;
		};
		['player:victim-reward-before']: {
			readonly player: Acore.Player;
			readonly victim: Acore.Player;
			killerTitle: number;
			victimRank: number;
		};
		['player:victim-reward-after']: {
			readonly player: Acore.Player;
			readonly victim: Acore.Player;
			killerTitle: number;
			victimRank: number;
			honor: number;
		};
		['player:custom-scaling-stat-value-before']: {
			readonly player: Acore.Player;
			readonly proto: Acore.ItemTemplateNarrowable;
			readonly slot: number;
			readonly apply: boolean;
			customScalingStatValue: number;
		};
		['player:custom-scaling-stat-value']: {
			readonly player: Acore.Player;
			readonly proto: Acore.ItemTemplateNarrowable;
			statType: Stats;
			val: number;
			readonly itemProtoStatNumber: number;
			readonly scalingStatValue: number;
			// readonly ssv: Acore.ScalingStatValuesEntry;
		};
		['player:apply-item-mods-before']: {
			readonly player: Acore.Player;
			readonly slot: number;
			readonly apply: boolean;
			readonly itemProtoStatNumber: number;
			readonly statType: Stats;
			val: number;
		};
		['player:apply-enchantment-item-mods-before']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly slot: EnchantmentSlot;
			readonly apply: boolean;
			readonly enchantSpellId: number;
			enchantAmount: number;
		};
		['player:apply-weapon-damage']: {
			readonly player: Acore.Player;
			readonly slot: number;
			readonly proto: Acore.ItemTemplateNarrowable;
			minDamage: number;
			maxDamage: number;
			readonly damageIndex: number;
		};
		['player:can-armor-damage-modifier']: {
			readonly player: Acore.Player;
			__return: boolean;
		};
		['player:get-feral-ap-bonus']: {
			readonly player: Acore.Player;
			feralBonus: number;
			readonly dpsMod: number;
			readonly proto: Acore.ItemTemplateNarrowable;
			// readonly ssv: Acore.ScalingStatValuesEntry;
		};
		['player:can-apply-weapon-dependent-aura-damage-mod']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly attackType: WeaponAttackType;
			readonly aura: Acore.AuraEffect;
			readonly apply: boolean;
			__return: boolean;
		};
		['player:can-apply-equip-spell']: {
			readonly player: Acore.Player;
			readonly spellInfo: Acore.SpellInfo;
			readonly item: Acore.Item;
			readonly apply: boolean;
			readonly formChange: boolean;
			__return: boolean;
		};
		['player:can-apply-equip-spells-item-set']: {
			readonly player: Acore.Player;
			// readonly eff: Acore.ItemSetEffect;
			__return: boolean;
		};
		['player:can-cast-item-combat-spell']: {
			readonly player: Acore.Player;
			readonly target: Acore.Unit;
			readonly attType: WeaponAttackType;
			readonly procVictim: ProcFlags;
			readonly procEx: ProcFlagsHit;
			readonly item: Acore.Item;
			readonly proto: Acore.ItemTemplateNarrowable;
			__return: boolean;
		};
		['player:can-cast-item-use-spell']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			// readonly targets: Acore.SpellCastTargets;
			readonly castCount: number;
			readonly glyphIndex: number;
			__return: boolean;
		};
		['player:apply-ammo-bonuses']: {
			readonly player: Acore.Player;
			readonly proto: Acore.ItemTemplateNarrowable;
			currentAmmoDps: number;
		};
		['player:can-equip-item']: {
			readonly player: Acore.Player;
			readonly slot: number;
			dest: number;
			readonly item: Acore.Item;
			readonly swap: boolean;
			readonly notLoading: boolean;
			__return: boolean;
		};
		['player:can-unequip-item']: {
			readonly player: Acore.Player;
			readonly pos: number;
			readonly swap: boolean;
			__return: boolean;
		};
		['player:can-use-item']: {
			readonly player: Acore.Player;
			readonly proto: Acore.ItemTemplateNarrowable;
			result: InventoryResult;
			__return: boolean;
		};
		['player:can-save-equip-new-item']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly pos: number;
			readonly update: boolean;
			__return: boolean;
		};
		['player:can-apply-enchantment']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly slot: number;
			readonly apply: boolean;
			readonly applyDur: boolean;
			readonly ignoreCondition: boolean;
			__return: boolean;
		};
		['player:get-quest-rate']: {
			readonly player: Acore.Player;
			result: number;
		};
		['player:passed-quest-killed-monster-credit']: {
			readonly player: Acore.Player;
			readonly qInfo: Acore.Quest;
			readonly entry: number;
			readonly realEntry: number;
			readonly guid: bigint | undefined;
			__return: boolean;
		};
		['player:check-item-in-slot-at-load-inventory']: {
			readonly player: Acore.Player;
			readonly item: Acore.Item;
			readonly slot: number;
			err: InventoryResult;
			dest: number;
			__return: boolean;
		};
		['player:not-avoid-satisfy']: {
			readonly player: Acore.Player;
			// readonly ar: Acore.DungeonProgressionRequirements;
			readonly targetMap: number;
			readonly report: boolean;
			__return: boolean;
		};
		['player:not-visible-globally-for']: {
			readonly player: Acore.Player;
			readonly u: Acore.Player;
			__return: boolean;
		};
		['player:get-arena-personal-rating']: {
			readonly player: Acore.Player;
			readonly slot: number;
			result: number;
		};
		['player:get-arena-team-id']: {
			readonly player: Acore.Player;
			readonly slot: number;
			result: number;
		};
		['player:is-ffa-pvp']: {
			readonly player: Acore.Player;
			result: boolean;
		};
		['player:ffa-pvp-state-update']: {
			readonly player: Acore.Player;
			readonly result: boolean;
		};
		['player:is-pvp']: {
			readonly player: Acore.Player;
			result: boolean;
		};
		['player:get-max-skill-value-for-level']: {
			readonly player: Acore.Player;
			result: number;
		};
		['player:not-set-arena-team-info-field']: {
			readonly player: Acore.Player;
			readonly slot: number;
			readonly type: ArenaTeamInfoType;
			readonly value: number;
			__return: boolean;
		};
		['player:can-join-lfg']: {
			readonly player: Acore.Player;
			readonly roles: LfgRoles;
			// dungeons: ReadonlySet<number>;
			readonly comment: string;
			__return: boolean;
		};
		['player:can-enter-map']: {
			readonly player: Acore.Player;
			// readonly entry: Acore.MapEntry;
			// readonly instance: Acore.InstanceTemplate;
			// readonly mapDiff: Acore.MapDifficulty;
			readonly loginCheck: boolean;
			__return: boolean;
		};
		['player:can-init-trade']: {
			readonly player: Acore.Player;
			readonly target: Acore.Player;
			__return: boolean;
		};
		['player:can-set-trade-item']: {
			readonly player: Acore.Player;
			readonly tradedItem: Acore.Item;
			readonly tradeSlot: number;
			__return: boolean;
		};
		['player:set-server-side-visibility']: {
			readonly player: Acore.Player;
			type: ServerSideVisibilityType;
			sec: AccountTypes;
		};
		['player:set-server-side-visibility-detect']: {
			readonly player: Acore.Player;
			type: ServerSideVisibilityType;
			sec: AccountTypes;
		};
		['player:resurrect']: {
			readonly player: Acore.Player;
			readonly restorePercent: number;
			applySickness: boolean;
		};
		['player:before-choose-graveyard']: {
			readonly player: Acore.Player;
			readonly teamId: TeamId;
			readonly nearCorpse: boolean;
			graveyardOverride: number;
		};
		['player:can-use-chat']: {
			readonly player: Acore.Player;
			readonly type: ChatMsg;
			readonly lang: Language;
			msg: string;
			__return: boolean;
		};
		['player:can-use-chat:player']: {
			readonly player: Acore.Player;
			readonly type: ChatMsg;
			readonly lang: Language;
			msg: string;
			readonly receiver: Acore.Player;
			__return: boolean;
		};
		['player:can-use-chat:group']: {
			readonly player: Acore.Player;
			readonly type: ChatMsg;
			readonly lang: Language;
			msg: string;
			readonly group: Acore.Group;
			__return: boolean;
		};
		['player:can-use-chat:guild']: {
			readonly player: Acore.Player;
			readonly type: ChatMsg;
			readonly lang: Language;
			msg: string;
			readonly guild: Acore.Guild;
			__return: boolean;
		};
		['player:can-use-chat:channel']: {
			readonly player: Acore.Player;
			readonly type: ChatMsg;
			readonly lang: Language;
			msg: string;
			readonly channel: Acore.Channel;
			__return: boolean;
		};
		['player:learn-talents']: {
			readonly player: Acore.Player;
			readonly talentId: number;
			readonly talentRank: number;
			readonly spellId: number;
		};
		['player:enter-combat']: {
			readonly player: Acore.Player;
			readonly enemy: Acore.Unit;
		};
		['player:leave-combat']: { readonly player: Acore.Player; };
		['player:quest-abandon']: {
			readonly player: Acore.Player;
			readonly questId: number;
		};
		['player:quest-accept']: {
			readonly player: Acore.Player;
			readonly quest: Acore.Quest;
		};
		['player:can-fly-in-zone']: {
			readonly player: Acore.Player;
			readonly mapId: number;
			readonly zoneId: number;
			readonly bySpell: Acore.SpellInfo;
			__return: boolean;
		};
		['player:anticheat:set-can-flyby-server']: {
			readonly player: Acore.Player;
			readonly apply: boolean;
		};
		['player:anticheat:set-under-ack-mount']: { readonly player: Acore.Player; };
		['player:anticheat:set-root-ack-upd']: { readonly player: Acore.Player; };
		['player:anticheat:set-jumping-by-opcode']: {
			readonly player: Acore.Player;
			readonly jump: boolean;
		};
		['player:anticheat:update-movement-info']: {
			readonly player: Acore.Player;
			// readonly movementInfo: Acore.MovementInfo;
		};
		['player:anticheat-handle-double-jump']: {
			readonly player: Acore.Player;
			readonly mover: Acore.Unit;
			__return: boolean;
		};
		['player:anticheat-check-movement-info']: {
			readonly player: Acore.Player;
			// readonly movementInfo: Acore.MovementInfo;
			readonly mover: Acore.Unit;
			readonly jump: boolean;
			__return: boolean;
		};
		['player:can-send-error-already-looted']: {
			readonly player: Acore.Player;
			__return: boolean;
		};
		['player:after-creature-loot']: { readonly player: Acore.Player; };
		['player:after-creature-loot-money']: { readonly player: Acore.Player; };
		['player:can-update-skill']: {
			readonly player: Acore.Player;
			readonly skillId: SkillType;
			__return: boolean;
		};
		['player:before-update-skill']: {
			readonly player: Acore.Player;
			readonly skillId: SkillType;
			value: number;
			readonly max: number;
			readonly step: number;
		};
		['player:update-skill']: {
			readonly player: Acore.Player;
			readonly skillId: SkillType;
			readonly value: number;
			readonly max: number;
			readonly step: number;
			readonly newValue: number;
		};
		['player:set-skill']: {
			readonly player: Acore.Player;
			readonly skillId: SkillType;
			readonly value: number;
			readonly max: number;
			readonly step: number;
			readonly newValue: number;
		};
		['player:can-resurrect']: {
			readonly player: Acore.Player;
			__return: boolean;
		};
		['player:can-give-level']: {
			readonly player: Acore.Player;
			readonly newLevel: number;
			__return: boolean;
		};
		['player:send-list-inventory']: {
			readonly player: Acore.Player;
			readonly vendorGuid: bigint;
			vendorEntry: number;
		};
		['player:get-reputation-price-discount:by-creature']: {
			readonly player: Acore.Player;
			readonly creature: Acore.Creature;
			discount: number;
		};
		['player:get-reputation-price-discount']: {
			readonly player: Acore.Player;
			// readonly factionTemplate: Acore.FactionTemplateEntry;
			discount: number;
		};
		['player:learn-taxi-node']: {
			readonly player: Acore.Player;
			readonly nodeId: number;
		};
		['player:before-get-level-for-xp-gain']: {
			readonly player: Acore.Player;
			level: number;
		};
		// BEGIN: new for my Archipelago
		['player:before-learn-spell']: {
			readonly player: Acore.Player;
			readonly spellId: number;
			__return: boolean;
		};
		['player:before-send-spell-list-to-trainer']: {
			readonly player: Acore.Player;
			readonly creature: Acore.Creature;
			readonly trainerList: Acore.TrainerSpellListMessage;
		};
		['player:before-can-take-quest']: {
			readonly player: Acore.Player;
			readonly quest: Acore.Quest;
			__return: boolean;
		};
		['player:before-can-reward-quest']: {
			readonly player: Acore.Player;
			readonly quest: Acore.Quest;
			__return: boolean;
		};
		['player:before-check-quest-menu-item']: {
			readonly player: Acore.Player;
			readonly questGiver: Acore.Creature | Acore.GameObject;
			questId: number;
		};
		// END: new for my Archipelago
	}
}
export {};
