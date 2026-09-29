declare global {
	interface Hooks {
		['player:just-died']: { player: Acore.Player; };
		['player:calculate-talents-points']: {
			player: Acore.Player;
			talentPointsForLevel: Acore.Box<number>;
		};
		['player:released-ghost']: { player: Acore.Player; };
		['player:send-initial-packets-before-add-to-map']: {
			player: Acore.Player;
			data: Acore.WorldPacket;
		};
		['player:battleground-desertion']: {
			player: Acore.Player;
			desertionType: BattlegroundDesertionType;
		};
		['player:complete-quest']: {
			player: Acore.Player;
			quest: Acore.Quest;
		};
		['player:pvp-kill']: {
			killer: Acore.Player;
			killed: Acore.Player;
		};
		['player:pvp-flag-change']: {
			player: Acore.Player;
			state: boolean;
		};
		['player:creature-kill']: {
			killer: Acore.Player;
			killed: Acore.Creature;
		};
		['player:creature-killed-by-pet']: {
			petOwner: Acore.Player;
			killed: Acore.Creature;
		};
		['player:killed-by-creature']: {
			killer: Acore.Creature;
			killed: Acore.Player;
		};
		['player:level-changed']: {
			player: Acore.Player;
			oldLevel: number;
		};
		['player:free-talent-points-changed']: {
			player: Acore.Player;
			points: number;
		};
		['player:talents-reset']: {
			player: Acore.Player;
			noCost: boolean;
		};
		['player:can-learn-talent']: {
			player: Acore.Player;
			// talent: TalentEntry;
			rank: number;
			__return: Acore.Box<boolean>;
		};
		['player:after-spec-slot-changed']: {
			player: Acore.Player;
			newSlot: number;
		};
		['player:before-update']: {
			player: Acore.Player;
			diff: Temporal.Duration;
		};
		['player:update']: {
			player: Acore.Player;
			diff: Temporal.Duration;
		};
		['player:money-changed']: {
			player: Acore.Player;
			amount: Acore.Box<number>;
		};
		['player:before-loot-money']: {
			player: Acore.Player;
			loot: Acore.Loot;
		};
		['player:give-xp']: {
			player: Acore.Player;
			amount: Acore.Box<number>;
			victim: Acore.Unit | undefined;
			xpSource: PlayerXPSource;
		};
		['player:reputation-change']: {
			player: Acore.Player;
			factionId: number;
			standing: Acore.Box<number>;
			incremental: boolean;
			__return: Acore.Box<boolean>;
		};
		['player:reputation-rank-change']: {
			player: Acore.Player;
			factionId: number;
			newRank: ReputationRank;
			oldRank: ReputationRank;
			increased: boolean;
		};
		['player:give-reputation']: {
			player: Acore.Player;
			factionId: number;
			amount: Acore.Box<number>;
			repSource: ReputationSource;
		};
		['player:learn-spell']: {
			player: Acore.Player;
			spellId: number;
		};
		['player:forgot-spell']: {
			player: Acore.Player;
			spellId: number;
		};
		['player:duel-request']: {
			target: Acore.Player;
			challenger: Acore.Player;
		};
		['player:duel-start']: {
			player1: Acore.Player;
			player2: Acore.Player;
		};
		['player:duel-end']: {
			winner: Acore.Player;
			loser: Acore.Player;
			type: DuelCompleteType;
		};
		['player:before-send-chat-message']: {
			player: Acore.Player;
			type: Acore.Box<ChatMsg>;
			lang: Acore.Box<Language>;
			msg: Acore.Box<string>;
		};
		['player:emote']: {
			player: Acore.Player;
			emote: Emote;
		};
		['player:text-emote']: {
			player: Acore.Player;
			textEmote: TextEmotes;
			emoteNum: number; // ?
			guid: bigint | undefined;
		};
		['player:spell-cast']: {
			player: Acore.Player;
			spell: Acore.Spell;
			skipCheck: boolean;
		};
		['player:load-from-db']: { player: Acore.Player; };
		['player:login']: { player: Acore.Player; };
		['player:before-logout']: { player: Acore.Player; };
		['player:logout']: { player: Acore.Player; };
		['player:create']: { player: Acore.Player; };
		['player:delete']: {
			guid: bigint;
			accountId: number;
		};
		['player:failed-delete']: {
			guid: bigint;
			accountId: number;
		};
		['player:save']: { player: Acore.Player; };
		['player:bind-to-instance']: {
			player: Acore.Player;
			difficulty: Difficulty;
			mapId: number;
			permanent: boolean;
		};
		['player:update-zone']: {
			player: Acore.Player;
			newZone: number;
			newArea: number;
		};
		['player:update-area']: {
			player: Acore.Player;
			oldArea: number;
			newArea: number;
		};
		['player:map-changed']: { player: Acore.Player; };
		['player:before-teleport']: {
			player: Acore.Player;
			mapId: number;
			x: number;
			y: number;
			z: number;
			o: number;
			options: TeleportToOptions;
			target: Acore.Unit | undefined;
			__return: Acore.Box<boolean>;
		};
		['player:update-faction']: { player: Acore.Player; };
		['player:add-to-battleground']: {
			player: Acore.Player;
			bg: Acore.Battleground;
		};
		['player:queue-random-dungeon']: {
			player: Acore.Player;
			rDungeonId: Acore.Box<number>;
		};
		['player:remove-from-battleground']: {
			player: Acore.Player;
			bg: Acore.Battleground;
		};
		['player:achievement-complete']: {
			player: Acore.Player;
			achievement: Acore.AchievementEntry;
		};
		['player:before-achievement-complete']: {
			player: Acore.Player;
			achievement: Acore.AchievementEntry;
			__return: Acore.Box<boolean>;
		};
		['player:criteria-progress']: {
			player: Acore.Player;
			// criteria: Acore.AchievementCriteriaEntry;
		};
		['player:before-criteria-progress']: {
			player: Acore.Player;
			// criteria: Acore.AchievementCriteriaEntry;
			__return: Acore.Box<boolean>;
		};
		['player:achievement-save']: {
			player: Acore.Player;
			achId: number;
			// achiData: Acore.CompletedAchievementData;
		};
		['player:criteria-save']: {
			player: Acore.Player;
			achId: number;
			// criteriaData: Acore.CriteriaProgress;
		};
		['player:gossip-select']: {
			player: Acore.Player;
			menuId: number;
			sender: GossipSender;
			action: number;
		};
		['player:gossip-select-code']: {
			player: Acore.Player;
			menuId: number;
			sender: GossipSender;
			action: number;
			code: string;
		};
		['player:being-charmed']: {
			player: Acore.Player;
			charmer: Acore.Unit;
			oldFactionId: number;
			newFactionId: number;
		};
		['player:after-set-visible-item-slot']: {
			player: Acore.Player;
			slot: number;
			item: Acore.Item;
		};
		['player:after-move-item-from-inventory']: {
			player: Acore.Player;
			item: Acore.Item;
			bag: number;
			slot: number;
			update: boolean;
		};
		['player:equip']: {
			player: Acore.Player;
			item: Acore.Item;
			bag: number;
			slot: number;
			update: boolean;
		};
		['player:unequip']: {
			player: Acore.Player;
			item: Acore.Item;
		};
		['player:join-bg']: { player: Acore.Player; };
		['player:join-arena']: { player: Acore.Player; };
		['player:get-max-personal-arena-rating-requirement']: {
			player: Acore.Player;
			minSlot: number;
			maxArenaRating: Acore.Box<number>;
		};
		['player:loot-item']: {
			player: Acore.Player;
			item: Acore.Item;
			count: number;
			lootGuid: bigint | undefined;
		};
		['player:before-fill-quest-loot-item']: {
			player: Acore.Player;
			// TODO: this shouldn't be readonly, I think I just need to abandon the whole idea of
			// "records" being a separate thing. "templates" are extremely easy now, and very nearly
			// everything that can be a "record" can also be a "template"
			item: LootItem;
		};
		['player:store-new-item']: {
			player: Acore.Player;
			item: Acore.Item;
			count: number;
		};
		['player:create-item']: {
			player: Acore.Player;
			item: Acore.Item;
			count: number;
		};
		['player:quest-reward-item']: {
			player: Acore.Player;
			item: Acore.Item;
			count: number;
		};
		['player:can-place-auction-bid']: {
			player: Acore.Player;
			auction: Acore.Auction;
			__return: Acore.Box<boolean>;
		};
		['player:group-roll-reward-item']: {
			player: Acore.Player;
			item: Acore.Item;
			count: number;
			voteType: RollVote;
			roll: Acore.Roll;
		};
		['player:before-open-item']: {
			player: Acore.Player;
			item: Acore.Item;
			__return: Acore.Box<boolean>;
		};
		['player:before-quest-complete']: {
			player: Acore.Player;
			questId: number;
			__return: Acore.Box<boolean>;
		};
		['player:quest-compute-xp']: {
			player: Acore.Player;
			quest: Acore.Quest;
			xpValue: Acore.Box<number>;
		};
		['player:before-durability-repair']: {
			player: Acore.Player;
			npcGuid: bigint;
			itemGuid: bigint;
			discountMod: Acore.Box<number>;
			guildBank: boolean;
		};
		['player:before-buy-item-from-vendor']: {
			player: Acore.Player;
			vendorGuid: bigint;
			vendorSlot: number;
			item: Acore.Box<number>;
			count: number;
			bag: number;
			slot: number;
		};
		['player:before-store-or-equip-new-item']: {
			player: Acore.Player;
			vendorSlot: number;
			item: Acore.Box<number>;
			count: number;
			bag: number;
			slot: number;
			proto: Acore.ItemTemplateNarrowable;
			vendor: Acore.Creature;
			// crItem: Acore.VendorItem;
			store: boolean;
		};
		['player:after-store-or-equip-new-item']: {
			player: Acore.Player;
			vendorSlot: number;
			item: Acore.Item;
			count: number;
			bag: number;
			slot: number;
			proto: Acore.ItemTemplateNarrowable;
			vendor: Acore.Creature;
			// crItem: Acore.VendorItem;
			store: boolean;
		};
		['player:after-update-max-power']: {
			player: Acore.Player;
			power: Acore.Box<Powers>;
			value: Acore.Box<number>;
		};
		['player:after-update-max-health']: {
			player: Acore.Player;
			value: Acore.Box<number>;
		};
		['player:before-update-attack-power-and-damage']: {
			player: Acore.Player;
			level: Acore.Box<number>;
			val2: Acore.Box<number>;
			ranged: boolean;
		};
		['player:after-update-attack-power-and-damage']: {
			player: Acore.Player;
			level: Acore.Box<number>;
			baseAttPower: Acore.Box<number>;
			attPowerMod: Acore.Box<number>;
			attPowerMultiplier: Acore.Box<number>;
			ranged: boolean;
		};
		['player:before-init-talent-for-level']: {
			player: Acore.Player;
			level: Acore.Box<number>;
			talentPointsForLevel: Acore.Box<number>;
		};
		['player:first-login']: { player: Acore.Player; };
		['player:set-max-level']: {
			player: Acore.Player;
			maxPlayerLevel: Acore.Box<number>;
		};
		['player:can-join-in-battleground-queue']: {
			player: Acore.Player;
			battlemasterGuid: bigint | undefined;
			bgTypeId: BattlegroundTypeId;
			joinAsGroup: boolean;
			err: Acore.Box<GroupJoinBattlegroundResult>;
			__return: Acore.Box<boolean>;
		};
		['player:should-be-rewarded-with-money-instead-of-exp']: {
			player: Acore.Player;
			__return: Acore.Box<boolean>;
		};
		['player:before-temp-summon-init-stats']: {
			player: Acore.Player;
			tempSummon: Acore.TempSummon;
			duration: Acore.Box<Temporal.Duration>;
		};
		['player:before-guardian-init-stats-for-level']: {
			player: Acore.Player;
			guardian: Acore.Guardian;
			cInfo: Acore.CreatureTemplate;
			petType: Acore.Box<PetType>;
		};
		['player:after-guardian-init-stats-for-level']: {
			player: Acore.Player;
			guardian: Acore.Guardian;
		};
		['player:before-load-pet-from-db']: {
			player: Acore.Player;
			petEntry: Acore.Box<number>;
			petNumber: Acore.Box<number>;
			current: Acore.Box<boolean>;
			forceLoadFromDB: Acore.Box<boolean>;
		};
		['player:can-join-in-arena-queue']: {
			player: Acore.Player;
			battlemasterGuid: bigint;
			arenaSlot: number;
			bgTypeId: number; // BattlegroundTypeId enum in native, but clearly it's not one of those.
			joinAsGroup: boolean;
			isRated: boolean;
			err: Acore.Box<GroupJoinBattlegroundResult>;
			__return: Acore.Box<boolean>;
		};
		['player:can-battle-field-port']: {
			player: Acore.Player;
			arenaType: ArenaType;
			bgTypeId: BattlegroundTypeId;
			action: number; // from a comment: enter battle 0x1, leave queue 0x0
			__return: Acore.Box<boolean>;
		};
		['player:can-group-invite']: {
			player: Acore.Player;
			memberName: Acore.Box<string>;
			__return: Acore.Box<boolean>;
		};
		['player:can-group-accept']: {
			player: Acore.Player;
			group: Acore.Group;
			__return: Acore.Box<boolean>;
		};
		['player:can-sell-item']: {
			player: Acore.Player;
			item: Acore.Item;
			creature: Acore.Creature;
			__return: Acore.Box<boolean>;
		};
		['player:can-send-mail']: {
			player: Acore.Player;
			receiverGuid: bigint;
			mailbox: bigint;
			subject: Acore.Box<string>;
			body: Acore.Box<string>;
			money: number;
			cod: number;
			item: Acore.Item | undefined;
			__return: Acore.Box<boolean>;
		};
		['player:petition-buy']: {
			player: Acore.Player;
			creature: Acore.Creature;
			charterId: Acore.Box<number>;
			cost: Acore.Box<number>;
			type: Acore.Box<CharterTypes>;
		};
		['player:petition-show-list']: {
			player: Acore.Player;
			creature: Acore.Creature;
			charterEntry: Acore.Box<number>;
			charterDisplayId: Acore.Box<number>;
			charterCost: Acore.Box<number>;
		};
		['player:reward-kill-rewarder']: {
			player: Acore.Player;
			// rewarder: Acore.KillRewarder;
			isDungeon: boolean;
			rate: Acore.Box<number>;
		};
		['player:can-give-mail-reward-at-give-level']: {
			player: Acore.Player;
			level: number;
			__return: Acore.Box<boolean>;
		};
		['player:delete-from-db']: {
			guid: bigint;
		};
		['player:can-repop-at-graveyard']: {
			player: Acore.Player;
			__return: Acore.Box<boolean>;
		};
		['player:is-class']: {
			player: Acore.Player;
			playerClass: Classes;
			context: ClassContext;
			__return: Acore.Box<boolean | undefined>;
		};
		['player:get-max-skill-value']: {
			player: Acore.Player;
			skill: SkillType;
			result: Acore.Box<number>;
			isPure: boolean;
		};
		['player:has-active-power-type']: {
			player: Acore.Player;
			power: Powers;
			__return: Acore.Box<boolean>;
		};
		['player:update-gathering-skill']: {
			player: Acore.Player;
			skillId: SkillType;
			current: number;
			gray: number;
			green: number;
			yellow: number;
			gain: Acore.Box<number>;
		};
		['player:update-crafting-skill']: {
			player: Acore.Player;
			// skill: Acore.SkillLineAbilityEntry;
			currentLevel: number;
			gain: Acore.Box<number>;
		};
		['player:update-fishing-skill']: {
			player: Acore.Player;
			skill: number;
			zoneSkill: number;
			chance: number;
			roll: number;
			__return: Acore.Box<boolean>;
		};
		['player:can-area-explore-and-outdoor']: {
			player: Acore.Player;
			__return: Acore.Box<boolean>;
		};
		['player:victim-reward-before']: {
			player: Acore.Player;
			victim: Acore.Player;
			killerTitle: Acore.Box<number>;
			victimRank: Acore.Box<number>;
		};
		['player:victim-reward-after']: {
			player: Acore.Player;
			victim: Acore.Player;
			killerTitle: Acore.Box<number>;
			victimRank: Acore.Box<number>;
			honor: Acore.Box<number>;
		};
		['player:custom-scaling-stat-value-before']: {
			player: Acore.Player;
			proto: Acore.ItemTemplateNarrowable;
			slot: number;
			apply: boolean;
			customScalingStatValue: Acore.Box<number>;
		};
		['player:custom-scaling-stat-value']: {
			player: Acore.Player;
			proto: Acore.ItemTemplateNarrowable;
			statType: Acore.Box<Stats>;
			val: Acore.Box<number>;
			itemProtoStatNumber: number;
			scalingStatValue: number;
			// ssv: Acore.ScalingStatValuesEntry;
		};
		['player:apply-item-mods-before']: {
			player: Acore.Player;
			slot: number;
			apply: boolean;
			itemProtoStatNumber: number;
			statType: Stats;
			val: Acore.Box<number>;
		};
		['player:apply-enchantment-item-mods-before']: {
			player: Acore.Player;
			item: Acore.Item;
			slot: EnchantmentSlot;
			apply: boolean;
			enchantSpellId: number;
			enchantAmount: Acore.Box<number>;
		};
		['player:apply-weapon-damage']: {
			player: Acore.Player;
			slot: number;
			proto: Acore.ItemTemplateNarrowable;
			minDamage: Acore.Box<number>;
			maxDamage: Acore.Box<number>;
			damageIndex: number;
		};
		['player:can-armor-damage-modifier']: {
			player: Acore.Player;
			__return: Acore.Box<boolean>;
		};
		['player:get-feral-ap-bonus']: {
			player: Acore.Player;
			feralBonus: Acore.Box<number>;
			dpsMod: number;
			proto: Acore.ItemTemplateNarrowable;
			// ssv: Acore.ScalingStatValuesEntry;
		};
		['player:can-apply-weapon-dependent-aura-damage-mod']: {
			player: Acore.Player;
			item: Acore.Item;
			attackType: WeaponAttackType;
			aura: Acore.AuraEffect;
			apply: boolean;
			__return: Acore.Box<boolean>;
		};
		['player:can-apply-equip-spell']: {
			player: Acore.Player;
			spellInfo: Acore.SpellInfo;
			item: Acore.Item;
			apply: boolean;
			formChange: boolean;
			__return: Acore.Box<boolean>;
		};
		['player:can-apply-equip-spells-item-set']: {
			player: Acore.Player;
			// eff: Acore.ItemSetEffect;
			__return: Acore.Box<boolean>;
		};
		['player:can-cast-item-combat-spell']: {
			player: Acore.Player;
			target: Acore.Unit;
			attType: WeaponAttackType;
			procVictim: ProcFlags;
			procEx: ProcFlagsHit;
			item: Acore.Item;
			proto: Acore.ItemTemplateNarrowable;
			__return: Acore.Box<boolean>;
		};
		['player:can-cast-item-use-spell']: {
			player: Acore.Player;
			item: Acore.Item;
			// targets: Acore.SpellCastTargets;
			castCount: number;
			glyphIndex: number;
			__return: Acore.Box<boolean>;
		};
		['player:apply-ammo-bonuses']: {
			player: Acore.Player;
			proto: Acore.ItemTemplateNarrowable;
			currentAmmoDps: Acore.Box<number>;
		};
		['player:can-equip-item']: {
			player: Acore.Player;
			slot: number;
			dest: Acore.Box<number>;
			item: Acore.Item;
			swap: boolean;
			notLoading: boolean;
			__return: Acore.Box<boolean>;
		};
		['player:can-unequip-item']: {
			player: Acore.Player;
			pos: number;
			swap: boolean;
			__return: Acore.Box<boolean>;
		};
		['player:can-use-item']: {
			player: Acore.Player;
			proto: Acore.ItemTemplateNarrowable;
			result: Acore.Box<InventoryResult>;
			__return: Acore.Box<boolean>;
		};
		['player:can-save-equip-new-item']: {
			player: Acore.Player;
			item: Acore.Item;
			pos: number;
			update: boolean;
			__return: Acore.Box<boolean>;
		};
		['player:can-apply-enchantment']: {
			player: Acore.Player;
			item: Acore.Item;
			slot: number;
			apply: boolean;
			applyDur: boolean;
			ignoreCondition: boolean;
			__return: Acore.Box<boolean>;
		};
		['player:get-quest-rate']: {
			player: Acore.Player;
			result: Acore.Box<number>;
		};
		['player:passed-quest-killed-monster-credit']: {
			player: Acore.Player;
			qInfo: Acore.Quest;
			entry: number;
			realEntry: number;
			guid: bigint | undefined;
			__return: Acore.Box<boolean>;
		};
		['player:check-item-in-slot-at-load-inventory']: {
			player: Acore.Player;
			item: Acore.Item;
			slot: number;
			err: Acore.Box<InventoryResult>;
			dest: Acore.Box<number>;
			__return: Acore.Box<boolean>;
		};
		['player:not-avoid-satisfy']: {
			player: Acore.Player;
			// ar: Acore.DungeonProgressionRequirements;
			targetMap: number;
			report: boolean;
			__return: Acore.Box<boolean>;
		};
		['player:not-visible-globally-for']: {
			player: Acore.Player;
			u: Acore.Player;
			__return: Acore.Box<boolean>;
		};
		['player:get-arena-personal-rating']: {
			player: Acore.Player;
			slot: number;
			result: Acore.Box<number>;
		};
		['player:get-arena-team-id']: {
			player: Acore.Player;
			slot: number;
			result: Acore.Box<number>;
		};
		['player:is-ffa-pvp']: {
			player: Acore.Player;
			result: Acore.Box<boolean>;
		};
		['player:ffa-pvp-state-update']: {
			player: Acore.Player;
			result: boolean;
		};
		['player:is-pvp']: {
			player: Acore.Player;
			result: Acore.Box<boolean>;
		};
		['player:get-max-skill-value-for-level']: {
			player: Acore.Player;
			result: Acore.Box<number>;
		};
		['player:not-set-arena-team-info-field']: {
			player: Acore.Player;
			slot: number;
			type: ArenaTeamInfoType;
			value: number;
			__return: Acore.Box<boolean>;
		};
		['player:can-join-lfg']: {
			player: Acore.Player;
			roles: LfgRoles;
			// dungeons: ReadonlySet<number>;
			comment: string;
			__return: Acore.Box<boolean>;
		};
		['player:can-enter-map']: {
			player: Acore.Player;
			// entry: Acore.MapEntry;
			// instance: Acore.InstanceTemplate;
			// mapDiff: Acore.MapDifficulty;
			loginCheck: boolean;
			__return: Acore.Box<boolean>;
		};
		['player:can-init-trade']: {
			player: Acore.Player;
			target: Acore.Player;
			__return: Acore.Box<boolean>;
		};
		['player:can-set-trade-item']: {
			player: Acore.Player;
			tradedItem: Acore.Item;
			tradeSlot: number;
			__return: Acore.Box<boolean>;
		};
		['player:set-server-side-visibility']: {
			player: Acore.Player;
			type: Acore.Box<ServerSideVisibilityType>;
			sec: Acore.Box<AccountTypes>;
		};
		['player:set-server-side-visibility-detect']: {
			player: Acore.Player;
			type: Acore.Box<ServerSideVisibilityType>;
			sec: Acore.Box<AccountTypes>;
		};
		['player:resurrect']: {
			player: Acore.Player;
			restorePercent: number;
			applySickness: Acore.Box<boolean>;
		};
		['player:before-choose-graveyard']: {
			player: Acore.Player;
			teamId: TeamId;
			nearCorpse: boolean;
			graveyardOverride: Acore.Box<number>;
		};
		['player:can-use-chat']: {
			player: Acore.Player;
			type: ChatMsg;
			lang: Language;
			msg: Acore.Box<string>;
			__return: Acore.Box<boolean>;
		};
		['player:can-use-chat:player']: {
			player: Acore.Player;
			type: ChatMsg;
			lang: Language;
			msg: Acore.Box<string>;
			receiver: Acore.Player;
			__return: Acore.Box<boolean>;
		};
		['player:can-use-chat:group']: {
			player: Acore.Player;
			type: ChatMsg;
			lang: Language;
			msg: Acore.Box<string>;
			group: Acore.Group;
			__return: Acore.Box<boolean>;
		};
		['player:can-use-chat:guild']: {
			player: Acore.Player;
			type: ChatMsg;
			lang: Language;
			msg: Acore.Box<string>;
			guild: Acore.Guild;
			__return: Acore.Box<boolean>;
		};
		['player:can-use-chat:channel']: {
			player: Acore.Player;
			type: ChatMsg;
			lang: Language;
			msg: Acore.Box<string>;
			channel: Acore.Channel;
			__return: Acore.Box<boolean>;
		};
		['player:learn-talents']: {
			player: Acore.Player;
			talentId: number;
			talentRank: number;
			spellId: number;
		};
		['player:enter-combat']: {
			player: Acore.Player;
			enemy: Acore.Unit;
		};
		['player:leave-combat']: { player: Acore.Player; };
		['player:quest-abandon']: {
			player: Acore.Player;
			questId: number;
		};
		['player:quest-accept']: {
			player: Acore.Player;
			quest: Acore.Quest;
		};
		['player:can-fly-in-zone']: {
			player: Acore.Player;
			mapId: number;
			zoneId: number;
			bySpell: Acore.SpellInfo;
			__return: Acore.Box<boolean>;
		};
		['player:anticheat:set-can-flyby-server']: {
			player: Acore.Player;
			apply: boolean;
		};
		['player:anticheat:set-under-ack-mount']: { player: Acore.Player; };
		['player:anticheat:set-root-ack-upd']: { player: Acore.Player; };
		['player:anticheat:set-jumping-by-opcode']: {
			player: Acore.Player;
			jump: boolean;
		};
		['player:anticheat:update-movement-info']: {
			player: Acore.Player;
			// movementInfo: Acore.MovementInfo;
		};
		['player:anticheat-handle-double-jump']: {
			player: Acore.Player;
			mover: Acore.Unit;
			__return: Acore.Box<boolean>;
		};
		['player:anticheat-check-movement-info']: {
			player: Acore.Player;
			// movementInfo: Acore.MovementInfo;
			mover: Acore.Unit;
			jump: boolean;
			__return: Acore.Box<boolean>;
		};
		['player:can-send-error-already-looted']: {
			player: Acore.Player;
			__return: Acore.Box<boolean>;
		};
		['player:after-creature-loot']: { player: Acore.Player; };
		['player:after-creature-loot-money']: { player: Acore.Player; };
		['player:can-update-skill']: {
			player: Acore.Player;
			skillId: SkillType;
			__return: Acore.Box<boolean>;
		};
		['player:before-update-skill']: {
			player: Acore.Player;
			skillId: SkillType;
			value: Acore.Box<number>;
			max: number;
			step: number;
		};
		['player:update-skill']: {
			player: Acore.Player;
			skillId: SkillType;
			value: number;
			max: number;
			step: number;
			newValue: number;
		};
		['player:set-skill']: {
			player: Acore.Player;
			skillId: SkillType;
			value: number;
			max: number;
			step: number;
			newValue: number;
		};
		['player:can-resurrect']: {
			player: Acore.Player;
			__return: Acore.Box<boolean>;
		};
		['player:can-give-level']: {
			player: Acore.Player;
			newLevel: number;
			__return: Acore.Box<boolean>;
		};
		['player:send-list-inventory']: {
			player: Acore.Player;
			vendorGuid: bigint;
			vendorEntry: Acore.Box<number>;
		};
		['player:get-reputation-price-discount:by-creature']: {
			player: Acore.Player;
			creature: Acore.Creature;
			discount: Acore.Box<number>;
		};
		['player:get-reputation-price-discount']: {
			player: Acore.Player;
			// factionTemplate: Acore.FactionTemplateEntry;
			discount: Acore.Box<number>;
		};
		['player:learn-taxi-node']: {
			player: Acore.Player;
			nodeId: number;
		};
		['player:before-get-level-for-xp-gain']: {
			player: Acore.Player;
			level: Acore.Box<number>;
		};
	}
}
export {};
