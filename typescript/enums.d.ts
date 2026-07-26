declare global {
	const enum TypeId {
		TYPEID_OBJECT        = 0,
		TYPEID_ITEM          = 1,
		TYPEID_CONTAINER     = 2,
		TYPEID_UNIT          = 3,
		TYPEID_PLAYER        = 4,
		TYPEID_GAMEOBJECT    = 5,
		TYPEID_DYNAMICOBJECT = 6,
		TYPEID_CORPSE        = 7,
	}

	const enum HighGuid {
		Item           = 0x4000,                      // blizz 4000
		Container      = 0x4000,                      // blizz 4000
		Player         = 0x0000,                      // blizz 0000
		GameObject     = 0xF110,                      // blizz F110
		Transport      = 0xF120,                      // blizz F120 (for GAMEOBJECT_TYPE_TRANSPORT)
		Unit           = 0xF130,                      // blizz F130
		Pet            = 0xF140,                      // blizz F140
		Vehicle        = 0xF150,                      // blizz F550
		DynamicObject  = 0xF100,                      // blizz F100
		Corpse         = 0xF101,                      // blizz F100
		Mo_Transport   = 0x1FC0,                      // blizz 1FC0 (for GAMEOBJECT_TYPE_MO_TRANSPORT)
		Instance       = 0x1F40,                      // blizz 1F40
		Group          = 0x1F50,
	}

	const enum LogLevel {
		LOG_LEVEL_DISABLED = 0,
		LOG_LEVEL_FATAL = 1,
		LOG_LEVEL_ERROR = 2,
		LOG_LEVEL_WARN = 3,
		LOG_LEVEL_INFO = 4,
		LOG_LEVEL_DEBUG = 5,
		LOG_LEVEL_TRACE = 6,
	}

	const enum MailCheckedMask {
		MAIL_CHECK_MASK_NONE        = 0x00,
		MAIL_CHECK_MASK_READ        = 0x01,
		MAIL_CHECK_MASK_RETURNED    = 0x02,                     /// This mail was returned. Do not allow returning mail back again.
		MAIL_CHECK_MASK_COPIED      = 0x04,                     /// This mail was copied. Do not allow making a copy of items in mail.
		MAIL_CHECK_MASK_COD_PAYMENT = 0x08,
		MAIL_CHECK_MASK_HAS_BODY    = 0x10,                     /// This mail has body text.
	}

	const enum MailMessageType {
		MAIL_NORMAL         = 0,
		MAIL_AUCTION        = 2,
		MAIL_CREATURE       = 3,                                // client send CMSG_CREATURE_QUERY on this mailmessagetype
		MAIL_GAMEOBJECT     = 4,                                // client send CMSG_GAMEOBJECT_QUERY on this mailmessagetype
		MAIL_CALENDAR       = 5,
	}

	// gathered from Stationery.dbc
	const enum MailStationery {
		MAIL_STATIONERY_TEST    = 1,
		MAIL_STATIONERY_DEFAULT = 41,
		MAIL_STATIONERY_GM      = 61,
		MAIL_STATIONERY_AUCTION = 62,
		MAIL_STATIONERY_VAL     = 64,                           // Valentine
		MAIL_STATIONERY_CHR     = 65,                           // Christmas
		MAIL_STATIONERY_ORP     = 67,                           // Orphan
	}

	const enum AuctionHouseId {
		Alliance    = 2,
		Horde       = 6,
		Neutral     = 7,
	}

	const enum NearObjectsMask {
		None = 0,
		Player = 1 << 0,
		Creature = 1 << 1,
		GameObject = 1 << 2,
	}

	const enum Gender {
		GENDER_MALE                        = 0,
		GENDER_FEMALE                      = 1,
		GENDER_NONE                        = 2,
	}

	// CreatureType.dbc
	const enum CreatureType {
		CREATURE_TYPE_BEAST            = 1,
		CREATURE_TYPE_DRAGONKIN        = 2,
		CREATURE_TYPE_DEMON            = 3,
		CREATURE_TYPE_ELEMENTAL        = 4,
		CREATURE_TYPE_GIANT            = 5,
		CREATURE_TYPE_UNDEAD           = 6,
		CREATURE_TYPE_HUMANOID         = 7,
		CREATURE_TYPE_CRITTER          = 8,
		CREATURE_TYPE_MECHANICAL       = 9,
		CREATURE_TYPE_NOT_SPECIFIED    = 10,
		CREATURE_TYPE_TOTEM            = 11,
		CREATURE_TYPE_NON_COMBAT_PET   = 12,
		CREATURE_TYPE_GAS_CLOUD        = 13,
	}

	// values 0 ... MAX_DB_MOTION_TYPE-1 used in DB
	const enum MovementGeneratorType {
		IDLE_MOTION_TYPE      = 0,                              // IdleMovementGenerator.h
		RANDOM_MOTION_TYPE    = 1,                              // RandomMovementGenerator.h
		WAYPOINT_MOTION_TYPE  = 2,                              // WaypointMovementGenerator.h
		MAX_DB_MOTION_TYPE    = 3,                              // *** this and below motion types can't be set in DB.
		ANIMAL_RANDOM_MOTION_TYPE = MAX_DB_MOTION_TYPE,         // AnimalRandomMovementGenerator.h
		CONFUSED_MOTION_TYPE  = 4,                              // ConfusedMovementGenerator.h
		CHASE_MOTION_TYPE     = 5,                              // TargetedMovementGenerator.h
		HOME_MOTION_TYPE      = 6,                              // HomeMovementGenerator.h
		FLIGHT_MOTION_TYPE    = 7,                              // WaypointMovementGenerator.h
		POINT_MOTION_TYPE     = 8,                              // PointMovementGenerator.h
		FLEEING_MOTION_TYPE   = 9,                              // FleeingMovementGenerator.h
		DISTRACT_MOTION_TYPE  = 10,                             // IdleMovementGenerator.h
		ASSISTANCE_MOTION_TYPE = 11,                            // PointMovementGenerator.h (first part of flee for assistance)
		ASSISTANCE_DISTRACT_MOTION_TYPE = 12,                   // IdleMovementGenerator.h (second part of flee for assistance)
		TIMED_FLEEING_MOTION_TYPE = 13,                         // FleeingMovementGenerator.h (alt.second part of flee for assistance)
		FOLLOW_MOTION_TYPE    = 14,
		ROTATE_MOTION_TYPE    = 15,
		EFFECT_MOTION_TYPE    = 16,
		ESCORT_MOTION_TYPE    = 17,                             // xinef: EscortMovementGenerator.h
		FORMATION_MOTION_TYPE = 18,                             // FormationMovementGenerator.h
		NULL_MOTION_TYPE      = 19,
	}

	const enum CurrentSpellTypes {
		CURRENT_MELEE_SPELL             = 0,
		CURRENT_GENERIC_SPELL           = 1,
		CURRENT_CHANNELED_SPELL         = 2,
		CURRENT_AUTOREPEAT_SPELL        = 3,
	}

	const enum Stats {
		STAT_STRENGTH                      = 0,
		STAT_AGILITY                       = 1,
		STAT_STAMINA                       = 2,
		STAT_INTELLECT                     = 3,
		STAT_SPIRIT                        = 4,
	}

	const enum Powers {
		POWER_MANA                          = 0,
		POWER_RAGE                          = 1,
		POWER_FOCUS                         = 2,
		POWER_ENERGY                        = 3,
		POWER_HAPPINESS                     = 4,
		POWER_RUNE                          = 5,
		POWER_RUNIC_POWER                   = 6,
		MAX_POWERS                          = 7,
		POWER_ALL                           = 127,    // default for class?
		POWER_HEALTH                        = 0xFFFFFFFE,   // (-2 as signed value)
	}

	const enum UnitMoveType {
		MOVE_WALK           = 0,
		MOVE_RUN            = 1,
		MOVE_RUN_BACK       = 2,
		MOVE_SWIM           = 3,
		MOVE_SWIM_BACK      = 4,
		MOVE_TURN_RATE      = 5,
		MOVE_FLIGHT         = 6,
		MOVE_FLIGHT_BACK    = 7,
		MOVE_PITCH_RATE     = 8,
	}

	const enum SpellSchools {
		SPELL_SCHOOL_NORMAL                 = 0,
		SPELL_SCHOOL_HOLY                   = 1,
		SPELL_SCHOOL_FIRE                   = 2,
		SPELL_SCHOOL_NATURE                 = 3,
		SPELL_SCHOOL_FROST                  = 4,
		SPELL_SCHOOL_SHADOW                 = 5,
		SPELL_SCHOOL_ARCANE                 = 6,
	}

	const enum UnitState {
		UNIT_STATE_DIED                     = 0x00000001,       // player has fake death aura
		UNIT_STATE_MELEE_ATTACKING          = 0x00000002,       // player is melee attacking someone
		UNIT_STATE_CHARMED                  = 0x00000004,       // having any kind of charm aura on self
		UNIT_STATE_STUNNED                  = 0x00000008,
		UNIT_STATE_ROAMING                  = 0x00000010,
		UNIT_STATE_CHASE                    = 0x00000020,
		//UNIT_STATE_SEARCHING              = 0x00000040,
		UNIT_STATE_FLEEING                  = 0x00000080,
		UNIT_STATE_IN_FLIGHT                = 0x00000100,       // player is in flight mode
		UNIT_STATE_FOLLOW                   = 0x00000200,
		UNIT_STATE_ROOT                     = 0x00000400,
		UNIT_STATE_CONFUSED                 = 0x00000800,
		UNIT_STATE_DISTRACTED               = 0x00001000,
		UNIT_STATE_ISOLATED                 = 0x00002000,       // area auras do not affect other players
		UNIT_STATE_ATTACK_PLAYER            = 0x00004000,
		UNIT_STATE_CASTING                  = 0x00008000,
		UNIT_STATE_POSSESSED                = 0x00010000,
		UNIT_STATE_CHARGING                 = 0x00020000,
		UNIT_STATE_JUMPING                  = 0x00040000,
		UNIT_STATE_MOVE                     = 0x00100000,
		UNIT_STATE_ROTATING                 = 0x00200000,
		UNIT_STATE_EVADE                    = 0x00400000,
		UNIT_STATE_ROAMING_MOVE             = 0x00800000,
		UNIT_STATE_CONFUSED_MOVE            = 0x01000000,
		UNIT_STATE_FLEEING_MOVE             = 0x02000000,
		UNIT_STATE_CHASE_MOVE               = 0x04000000,
		UNIT_STATE_FOLLOW_MOVE              = 0x08000000,
		UNIT_STATE_IGNORE_PATHFINDING       = 0x10000000,       // do not use pathfinding in any MovementGenerator
		UNIT_STATE_NO_ENVIRONMENT_UPD       = 0x20000000,

		// serverside region
		UNIT_STATE_NO_COMBAT_MOVEMENT       = 0x40000000,       // should not be changed outside the core and should be placed at the end
		UNIT_STATE_LOGOUT_TIMER             = 0x80000000,       // Unit is logging out

		UNIT_STATE_ALL_STATE_SUPPORTED = UNIT_STATE_DIED | UNIT_STATE_MELEE_ATTACKING | UNIT_STATE_CHARMED | UNIT_STATE_STUNNED | UNIT_STATE_ROAMING | UNIT_STATE_CHASE
			| UNIT_STATE_FLEEING | UNIT_STATE_IN_FLIGHT | UNIT_STATE_FOLLOW | UNIT_STATE_ROOT | UNIT_STATE_CONFUSED
			| UNIT_STATE_DISTRACTED | UNIT_STATE_ISOLATED | UNIT_STATE_ATTACK_PLAYER | UNIT_STATE_CASTING
			| UNIT_STATE_POSSESSED | UNIT_STATE_CHARGING | UNIT_STATE_JUMPING | UNIT_STATE_MOVE | UNIT_STATE_ROTATING
			| UNIT_STATE_EVADE | UNIT_STATE_ROAMING_MOVE | UNIT_STATE_CONFUSED_MOVE | UNIT_STATE_FLEEING_MOVE
			| UNIT_STATE_CHASE_MOVE | UNIT_STATE_FOLLOW_MOVE | UNIT_STATE_IGNORE_PATHFINDING | UNIT_STATE_NO_ENVIRONMENT_UPD,

		UNIT_STATE_UNATTACKABLE             = UNIT_STATE_IN_FLIGHT,

		// for real move using movegen check and stop (except unstoppable flight)
		UNIT_STATE_MOVING                   = UNIT_STATE_ROAMING_MOVE | UNIT_STATE_CONFUSED_MOVE | UNIT_STATE_FLEEING_MOVE | UNIT_STATE_CHASE_MOVE | UNIT_STATE_FOLLOW_MOVE,
		UNIT_STATE_CONTROLLED               = (UNIT_STATE_CONFUSED | UNIT_STATE_STUNNED | UNIT_STATE_FLEEING),
		UNIT_STATE_LOST_CONTROL             = (UNIT_STATE_CONTROLLED | UNIT_STATE_JUMPING | UNIT_STATE_CHARGING),
		UNIT_STATE_SIGHTLESS                = (UNIT_STATE_LOST_CONTROL | UNIT_STATE_EVADE),
		UNIT_STATE_CANNOT_AUTOATTACK        = (UNIT_STATE_LOST_CONTROL | UNIT_STATE_CASTING),
		UNIT_STATE_CANNOT_TURN              = (UNIT_STATE_LOST_CONTROL | UNIT_STATE_ROTATING | UNIT_STATE_ROOT),

		// stay by different reasons
		UNIT_STATE_NOT_MOVE                 = UNIT_STATE_ROOT | UNIT_STATE_STUNNED | UNIT_STATE_DIED | UNIT_STATE_DISTRACTED,
		UNIT_STATE_IGNORE_ANTISPEEDHACK     = UNIT_STATE_FLEEING | UNIT_STATE_CONFUSED | UNIT_STATE_CHARGING | UNIT_STATE_DISTRACTED | UNIT_STATE_POSSESSED,
		UNIT_STATE_ALL_STATE                = 0xffffffff,       //(UNIT_STATE_STOPPED | UNIT_STATE_MOVING | UNIT_STATE_IN_COMBAT | UNIT_STATE_IN_FLIGHT)
	}

	const enum ChatMsg {
		CHAT_MSG_ADDON                  = 0xFFFFFFFF,
		CHAT_MSG_SYSTEM                 = 0x00,
		CHAT_MSG_SAY                    = 0x01,
		CHAT_MSG_PARTY                  = 0x02,
		CHAT_MSG_RAID                   = 0x03,
		CHAT_MSG_GUILD                  = 0x04,
		CHAT_MSG_OFFICER                = 0x05,
		CHAT_MSG_YELL                   = 0x06,
		CHAT_MSG_WHISPER                = 0x07,
		CHAT_MSG_WHISPER_FOREIGN        = 0x08,
		CHAT_MSG_WHISPER_INFORM         = 0x09,
		CHAT_MSG_EMOTE                  = 0x0A,
		CHAT_MSG_TEXT_EMOTE             = 0x0B,
		CHAT_MSG_MONSTER_SAY            = 0x0C,
		CHAT_MSG_MONSTER_PARTY          = 0x0D,
		CHAT_MSG_MONSTER_YELL           = 0x0E,
		CHAT_MSG_MONSTER_WHISPER        = 0x0F,
		CHAT_MSG_MONSTER_EMOTE          = 0x10,
		CHAT_MSG_CHANNEL                = 0x11,
		CHAT_MSG_CHANNEL_JOIN           = 0x12,
		CHAT_MSG_CHANNEL_LEAVE          = 0x13,
		CHAT_MSG_CHANNEL_LIST           = 0x14,
		CHAT_MSG_CHANNEL_NOTICE         = 0x15,
		CHAT_MSG_CHANNEL_NOTICE_USER    = 0x16,
		CHAT_MSG_AFK                    = 0x17,
		CHAT_MSG_DND                    = 0x18,
		CHAT_MSG_IGNORED                = 0x19,
		CHAT_MSG_SKILL                  = 0x1A,
		CHAT_MSG_LOOT                   = 0x1B,
		CHAT_MSG_MONEY                  = 0x1C,
		CHAT_MSG_OPENING                = 0x1D,
		CHAT_MSG_TRADESKILLS            = 0x1E,
		CHAT_MSG_PET_INFO               = 0x1F,
		CHAT_MSG_COMBAT_MISC_INFO       = 0x20,
		CHAT_MSG_COMBAT_XP_GAIN         = 0x21,
		CHAT_MSG_COMBAT_HONOR_GAIN      = 0x22,
		CHAT_MSG_COMBAT_FACTION_CHANGE  = 0x23,
		CHAT_MSG_BG_SYSTEM_NEUTRAL      = 0x24,
		CHAT_MSG_BG_SYSTEM_ALLIANCE     = 0x25,
		CHAT_MSG_BG_SYSTEM_HORDE        = 0x26,
		CHAT_MSG_RAID_LEADER            = 0x27,
		CHAT_MSG_RAID_WARNING           = 0x28,
		CHAT_MSG_RAID_BOSS_EMOTE        = 0x29,
		CHAT_MSG_RAID_BOSS_WHISPER      = 0x2A,
		CHAT_MSG_FILTERED               = 0x2B,
		CHAT_MSG_BATTLEGROUND           = 0x2C,
		CHAT_MSG_BATTLEGROUND_LEADER    = 0x2D,
		CHAT_MSG_RESTRICTED             = 0x2E,
		CHAT_MSG_BATTLENET              = 0x2F,
		CHAT_MSG_ACHIEVEMENT            = 0x30,
		CHAT_MSG_GUILD_ACHIEVEMENT      = 0x31,
		CHAT_MSG_ARENA_POINTS           = 0x32,
		CHAT_MSG_PARTY_LEADER           = 0x33,
	}

	const enum Language {
		LANG_UNIVERSAL      = 0,
		LANG_ORCISH         = 1,
		LANG_DARNASSIAN     = 2,
		LANG_TAURAHE        = 3,
		LANG_DWARVISH       = 6,
		LANG_COMMON         = 7,
		LANG_DEMONIC        = 8,
		LANG_TITAN          = 9,
		LANG_THALASSIAN     = 10,
		LANG_DRACONIC       = 11,
		LANG_KALIMAG        = 12,
		LANG_GNOMISH        = 13,
		LANG_TROLL          = 14,
		LANG_GUTTERSPEAK    = 33,
		LANG_DRAENEI        = 35,
		LANG_ZOMBIE         = 36,
		LANG_GNOMISH_BINARY = 37,
		LANG_GOBLIN_BINARY  = 38,
		LANG_ADDON          = 0xFFFFFFFF,                       // used by addons, in 2.4.0 not exist, replaced by messagetype?
	}

	// low byte (0 from 0..3) of UNIT_FIELD_BYTES_2
	const enum SheathState {
		SHEATH_STATE_UNARMED                = 0,        // non prepared weapon
		SHEATH_STATE_MELEE                  = 1,        // prepared melee weapon
		SHEATH_STATE_RANGED                 = 2,        // prepared ranged weapon
	}

	// byte value (UNIT_FIELD_BYTES_1, 0)
	const enum UnitStandStateType {
		UNIT_STAND_STATE_STAND              = 0,
		UNIT_STAND_STATE_SIT                = 1,
		UNIT_STAND_STATE_SIT_CHAIR          = 2,
		UNIT_STAND_STATE_SLEEP              = 3,
		UNIT_STAND_STATE_SIT_LOW_CHAIR      = 4,
		UNIT_STAND_STATE_SIT_MEDIUM_CHAIR   = 5,
		UNIT_STAND_STATE_SIT_HIGH_CHAIR     = 6,
		UNIT_STAND_STATE_DEAD               = 7,
		UNIT_STAND_STATE_KNEEL              = 8,
		UNIT_STAND_STATE_SUBMERGED          = 9,
	}
	// Emotes.dbc
	const enum Emote {
		EMOTE_ONESHOT_NONE                  = 0, // SKIP
		EMOTE_ONESHOT_TALK                  = 1,
		EMOTE_ONESHOT_BOW                   = 2,
		EMOTE_ONESHOT_WAVE                  = 3,
		EMOTE_ONESHOT_CHEER                 = 4,
		EMOTE_ONESHOT_EXCLAMATION           = 5,
		EMOTE_ONESHOT_QUESTION              = 6,
		EMOTE_ONESHOT_EAT                   = 7,
		EMOTE_STATE_DANCE                   = 10,
		EMOTE_ONESHOT_LAUGH                 = 11,
		EMOTE_STATE_SLEEP                   = 12,
		EMOTE_STATE_SIT                     = 13,
		EMOTE_ONESHOT_RUDE                  = 14,
		EMOTE_ONESHOT_ROAR                  = 15,
		EMOTE_ONESHOT_KNEEL                 = 16,
		EMOTE_ONESHOT_KISS                  = 17,
		EMOTE_ONESHOT_CRY                   = 18,
		EMOTE_ONESHOT_CHICKEN               = 19,
		EMOTE_ONESHOT_BEG                   = 20,
		EMOTE_ONESHOT_APPLAUD               = 21,
		EMOTE_ONESHOT_SHOUT                 = 22,
		EMOTE_ONESHOT_FLEX                  = 23,
		EMOTE_ONESHOT_SHY                   = 24,
		EMOTE_ONESHOT_POINT                 = 25,
		EMOTE_STATE_STAND                   = 26,
		EMOTE_STATE_READY_UNARMED           = 27,
		EMOTE_STATE_WORK_SHEATHED           = 28,
		EMOTE_STATE_POINT                   = 29,
		EMOTE_STATE_NONE                    = 30,
		EMOTE_ONESHOT_WOUND                 = 33,
		EMOTE_ONESHOT_WOUND_CRITICAL        = 34,
		EMOTE_ONESHOT_ATTACK_UNARMED        = 35,
		EMOTE_ONESHOT_ATTACK1H              = 36,
		EMOTE_ONESHOT_ATTACK2HTIGHT         = 37,
		EMOTE_ONESHOT_ATTACK2H_LOOSE        = 38,
		EMOTE_ONESHOT_PARRY_UNARMED         = 39,
		EMOTE_ONESHOT_PARRY_SHIELD          = 43,
		EMOTE_ONESHOT_READY_UNARMED         = 44,
		EMOTE_ONESHOT_READY1H               = 45,
		EMOTE_ONESHOT_READY_BOW             = 48,
		EMOTE_ONESHOT_SPELL_PRECAST         = 50,
		EMOTE_ONESHOT_SPELL_CAST            = 51,
		EMOTE_ONESHOT_BATTLE_ROAR           = 53,
		EMOTE_ONESHOT_SPECIALATTACK1H       = 54,
		EMOTE_ONESHOT_KICK                  = 60,
		EMOTE_ONESHOT_ATTACK_THROWN         = 61,
		EMOTE_STATE_STUN                    = 64,
		EMOTE_STATE_DEAD                    = 65,
		EMOTE_ONESHOT_SALUTE                = 66,
		EMOTE_STATE_KNEEL                   = 68,
		EMOTE_STATE_USE_STANDING            = 69,
		EMOTE_ONESHOT_WAVE_NO_SHEATHE       = 70,
		EMOTE_ONESHOT_CHEER_NO_SHEATHE      = 71,
		EMOTE_ONESHOT_EAT_NO_SHEATHE        = 92,
		EMOTE_STATE_STUN_NO_SHEATHE         = 93,
		EMOTE_ONESHOT_DANCE                 = 94,
		EMOTE_ONESHOT_SALUTE_NO_SHEATH      = 113,
		EMOTE_STATE_USE_STANDING_NO_SHEATHE = 133,
		EMOTE_ONESHOT_LAUGH_NO_SHEATHE      = 153,
		EMOTE_STATE_WORK                    = 173,
		EMOTE_STATE_SPELL_PRECAST           = 193,
		EMOTE_ONESHOT_READY_RIFLE           = 213,
		EMOTE_STATE_READY_RIFLE             = 214,
		EMOTE_STATE_WORK_MINING             = 233,
		EMOTE_STATE_WORK_CHOPWOOD           = 234,
		EMOTE_STATE_APPLAUD                 = 253,
		EMOTE_ONESHOT_LIFTOFF               = 254,
		EMOTE_ONESHOT_YES                   = 273,
		EMOTE_ONESHOT_NO                    = 274,
		EMOTE_ONESHOT_TRAIN                 = 275,
		EMOTE_ONESHOT_LAND                  = 293,
		EMOTE_STATE_AT_EASE                 = 313,
		EMOTE_STATE_READY1H                 = 333,
		EMOTE_STATE_SPELL_KNEEL_START       = 353,
		EMOTE_STATE_SUBMERGED               = 373,
		EMOTE_ONESHOT_SUBMERGE              = 374,
		EMOTE_STATE_READY2H                 = 375,
		EMOTE_STATE_READY_BOW               = 376,
		EMOTE_ONESHOT_MOUNT_SPECIAL         = 377,
		EMOTE_STATE_TALK                    = 378,
		EMOTE_STATE_FISHING                 = 379,
		EMOTE_ONESHOT_FISHING               = 380,
		EMOTE_ONESHOT_LOOT                  = 381,
		EMOTE_STATE_WHIRLWIND               = 382,
		EMOTE_STATE_DROWNED                 = 383,
		EMOTE_STATE_HOLD_BOW                = 384,
		EMOTE_STATE_HOLD_RIFLE              = 385,
		EMOTE_STATE_HOLD_THROWN             = 386,
		EMOTE_ONESHOT_DROWN                 = 387,
		EMOTE_ONESHOT_STOMP                 = 388,
		EMOTE_ONESHOT_ATTACK_OFF            = 389,
		EMOTE_ONESHOT_ATTACK_OFF_PIERCE     = 390,
		EMOTE_STATE_ROAR                    = 391,
		EMOTE_STATE_LAUGH                   = 392,
		EMOTE_ONESHOT_CREATURE_SPECIAL      = 393,
		EMOTE_ONESHOT_JUMPLANDRUN           = 394,
		EMOTE_ONESHOT_JUMPEND               = 395,
		EMOTE_ONESHOT_TALK_NO_SHEATHE       = 396,
		EMOTE_ONESHOT_POINT_NO_SHEATHE      = 397,
		EMOTE_STATE_CANNIBALIZE             = 398,
		EMOTE_ONESHOT_JUMPSTART             = 399,
		EMOTE_STATE_DANCESPECIAL            = 400,
		EMOTE_ONESHOT_DANCESPECIAL          = 401,
		EMOTE_ONESHOT_CUSTOM_SPELL_01       = 402,
		EMOTE_ONESHOT_CUSTOM_SPELL_02       = 403,
		EMOTE_ONESHOT_CUSTOM_SPELL_03       = 404,
		EMOTE_ONESHOT_CUSTOM_SPELL_04       = 405,
		EMOTE_ONESHOT_CUSTOM_SPELL_05       = 406,
		EMOTE_ONESHOT_CUSTOM_SPELL_06       = 407,
		EMOTE_ONESHOT_CUSTOM_SPELL_07       = 408,
		EMOTE_ONESHOT_CUSTOM_SPELL_08       = 409,
		EMOTE_ONESHOT_CUSTOM_SPELL_09       = 410,
		EMOTE_ONESHOT_CUSTOM_SPELL_10       = 411,
		EMOTE_STATE_EXCLAIM                 = 412,
		EMOTE_STATE_DANCE_CUSTOM            = 413,
		EMOTE_STATE_SIT_CHAIR_MED           = 415,
		EMOTE_STATE_CUSTOM_SPELL_01         = 416,
		EMOTE_STATE_CUSTOM_SPELL_02         = 417,
		EMOTE_STATE_EAT                     = 418,
		EMOTE_STATE_CUSTOM_SPELL_04         = 419,
		EMOTE_STATE_CUSTOM_SPELL_03         = 420,
		EMOTE_STATE_CUSTOM_SPELL_05         = 421,
		EMOTE_STATE_SPELLEFFECT_HOLD        = 422,
		EMOTE_STATE_EAT_NO_SHEATHE          = 423,
		EMOTE_STATE_MOUNT                   = 424,
		EMOTE_STATE_READY2HL                = 425,
		EMOTE_STATE_SIT_CHAIR_HIGH          = 426,
		EMOTE_STATE_FALL                    = 427,
		EMOTE_STATE_LOOT                    = 428,
		EMOTE_STATE_SUBMERGED_NEW           = 429,
		EMOTE_ONESHOT_COWER                 = 430,
		EMOTE_STATE_COWER                   = 431,
		EMOTE_ONESHOT_USE_STANDING          = 432,
		EMOTE_STATE_STEALTH_STAND           = 433,
		EMOTE_ONESHOT_OMNICAST_GHOUL        = 434,
		EMOTE_ONESHOT_ATTACK_BOW            = 435,
		EMOTE_ONESHOT_ATTACK_RIFLE          = 436,
		EMOTE_STATE_SWIM_IDLE               = 437,
		EMOTE_STATE_ATTACK_UNARMED          = 438,
		EMOTE_ONESHOT_SPELL_CAST_W_SOUND    = 439,
		EMOTE_ONESHOT_DODGE                 = 440,
		EMOTE_ONESHOT_PARRY1H               = 441,
		EMOTE_ONESHOT_PARRY2H               = 442,
		EMOTE_ONESHOT_PARRY2HL              = 443,
		EMOTE_STATE_FLYFALL                 = 444,
		EMOTE_ONESHOT_FLYDEATH              = 445,
		EMOTE_STATE_FLY_FALL                = 446,
		EMOTE_ONESHOT_FLY_SIT_GROUND_DOWN   = 447,
		EMOTE_ONESHOT_FLY_SIT_GROUND_UP     = 448,
		EMOTE_ONESHOT_EMERGE                = 449,
		EMOTE_ONESHOT_DRAGON_SPIT           = 450,
		EMOTE_STATE_SPECIAL_UNARMED         = 451,
		EMOTE_ONESHOT_FLYGRAB               = 452,
		EMOTE_STATE_FLYGRABCLOSED           = 453,
		EMOTE_ONESHOT_FLYGRABTHROWN         = 454,
		EMOTE_STATE_FLY_SIT_GROUND          = 455,
		EMOTE_STATE_WALK_BACKWARDS          = 456,
		EMOTE_ONESHOT_FLYTALK               = 457,
		EMOTE_ONESHOT_FLYATTACK1H           = 458,
		EMOTE_STATE_CUSTOM_SPELL_08         = 459,
		EMOTE_ONESHOT_FLY_DRAGON_SPIT       = 460,
		EMOTE_STATE_SIT_CHAIR_LOW           = 461,
		EMOTE_ONESHOT_STUN                  = 462,
		EMOTE_ONESHOT_SPELL_CAST_OMNI       = 463,
		EMOTE_STATE_READY_THROWN            = 465,
		EMOTE_ONESHOT_WORK_CHOPWOOD         = 466,
		EMOTE_ONESHOT_WORK_MINING           = 467,
		EMOTE_STATE_SPELL_CHANNEL_OMNI      = 468,
		EMOTE_STATE_SPELL_CHANNEL_DIRECTED  = 469,
		EMOTE_STAND_STATE_NONE              = 470,
		EMOTE_STATE_READYJOUST              = 471,
		EMOTE_STATE_STRANGULATE             = 473,
		EMOTE_STATE_READY_SPELL_OMNI        = 474,
		EMOTE_STATE_HOLD_JOUST              = 475,
		EMOTE_ONESHOT_CRY_JAINA             = 476,
	}

	const enum MovementSlot {
		MOTION_SLOT_IDLE,
		MOTION_SLOT_ACTIVE,
		MOTION_SLOT_CONTROLLED,
	}

	const enum AuraRemoveMode {
		AURA_REMOVE_NONE                = 0,
		AURA_REMOVE_BY_DEFAULT          = 1,    // scripted remove, remove by stack with aura with different ids and sc aura remove
		AURA_REMOVE_BY_CANCEL,
		AURA_REMOVE_BY_ENEMY_SPELL,             // dispel and absorb aura destroy
		AURA_REMOVE_BY_EXPIRE,                  // aura duration has ended
		AURA_REMOVE_BY_DEATH,
	}

	const enum WeaponAttackType {
		BASE_ATTACK   = 0,
		OFF_ATTACK    = 1,
		RANGED_ATTACK = 2,
	}

	const enum SpellImmuneBlockType {
		SPELL_BLOCK_TYPE_ALL        = 0,
		SPELL_BLOCK_TYPE_POSITIVE   = 1,
	}
	//To all Immune system, if target has immunes,
	//some spell that related to ImmuneToDispel or ImmuneToSchool or ImmuneToDamage type can't cast to it,
	//some spell_effects that related to ImmuneToEffect<effect>(only this effect in the spell) can't cast to it,
	//some aura(related to Mechanics or ImmuneToState<aura>) can't apply to it.
	const enum SpellImmunity {
		IMMUNITY_EFFECT                = 0,                     // enum SpellEffects
		IMMUNITY_STATE                 = 1,                     // enum AuraType
		IMMUNITY_SCHOOL                = 2,                     // enum SpellSchoolMask
		IMMUNITY_DAMAGE                = 3,                     // enum SpellSchoolMask
		IMMUNITY_DISPEL                = 4,                     // enum DispelType
		IMMUNITY_MECHANIC              = 5,                     // enum Mechanics
		IMMUNITY_ID                    = 6,
		IMMUNITY_ALLOW_ID              = 7,                     // xinef: special type of immunity, npc is immune to everything except for those spells id
	}

	const enum UnitMods {
		UNIT_MOD_STAT_STRENGTH,                                 // UNIT_MOD_STAT_STRENGTH..UNIT_MOD_STAT_SPIRIT must be in existed order, it's accessed by index values of Stats enum.
		UNIT_MOD_STAT_AGILITY,
		UNIT_MOD_STAT_STAMINA,
		UNIT_MOD_STAT_INTELLECT,
		UNIT_MOD_STAT_SPIRIT,
		UNIT_MOD_HEALTH,
		UNIT_MOD_MANA,                                          // UNIT_MOD_MANA..UNIT_MOD_RUNIC_POWER must be in existed order, it's accessed by index values of Powers enum.
		UNIT_MOD_RAGE,
		UNIT_MOD_FOCUS,
		UNIT_MOD_ENERGY,
		UNIT_MOD_HAPPINESS,
		UNIT_MOD_RUNE,
		UNIT_MOD_RUNIC_POWER,
		UNIT_MOD_ARMOR,                                         // UNIT_MOD_ARMOR..UNIT_MOD_RESISTANCE_ARCANE must be in existed order, it's accessed by index values of SpellSchools enum.
		UNIT_MOD_RESISTANCE_HOLY,
		UNIT_MOD_RESISTANCE_FIRE,
		UNIT_MOD_RESISTANCE_NATURE,
		UNIT_MOD_RESISTANCE_FROST,
		UNIT_MOD_RESISTANCE_SHADOW,
		UNIT_MOD_RESISTANCE_ARCANE,
		UNIT_MOD_ATTACK_POWER,
		UNIT_MOD_ATTACK_POWER_RANGED,
		UNIT_MOD_DAMAGE_MAINHAND,
		UNIT_MOD_DAMAGE_OFFHAND,
		UNIT_MOD_DAMAGE_RANGED,
		UNIT_MOD_END,
		// synonyms
		UNIT_MOD_STAT_START = UNIT_MOD_STAT_STRENGTH,
		UNIT_MOD_STAT_END = UNIT_MOD_STAT_SPIRIT + 1,
		UNIT_MOD_RESISTANCE_START = UNIT_MOD_ARMOR,
		UNIT_MOD_RESISTANCE_END = UNIT_MOD_RESISTANCE_ARCANE + 1,
		UNIT_MOD_POWER_START = UNIT_MOD_MANA,
		UNIT_MOD_POWER_END = UNIT_MOD_RUNIC_POWER + 1,
	}

	const enum UnitModifierFlatType {
		BASE_VALUE = 0,
		TOTAL_VALUE = 1,
		MODIFIER_TYPE_FLAT_END = 3,
	}

	const enum UnitModifierPctType {
		BASE_PCT = 0,
		TOTAL_PCT = 1,
		MODIFIER_TYPE_PCT_END = 2,
	}

	const enum DeathState {
		Alive         = 0,
		JustDied      = 1,
		Corpse        = 2,
		Dead          = 3,
		JustRespawned = 4,
	}

	// Race value is index in ChrRaces.dbc
	const enum Races {
		RACE_NONE               = 0,  // SKIP
		RACE_HUMAN              = 1,  // TITLE Human
		RACE_ORC                = 2,  // TITLE Orc
		RACE_DWARF              = 3,  // TITLE Dwarf
		RACE_NIGHTELF           = 4,  // TITLE Night Elf
		RACE_UNDEAD_PLAYER      = 5,  // TITLE Undead
		RACE_TAUREN             = 6,  // TITLE Tauren
		RACE_GNOME              = 7,  // TITLE Gnome
		RACE_TROLL              = 8,  // TITLE Troll
		//RACE_GOBLIN             = 9,
		RACE_BLOODELF           = 10, // TITLE Blood Elf
		RACE_DRAENEI            = 11, // TITLE Draenei
		//RACE_FEL_ORC        = 12,
		//RACE_NAGA           = 13,
		//RACE_BROKEN         = 14,
		//RACE_SKELETON       = 15,
		//RACE_VRYKUL         = 16,
		//RACE_TUSKARR        = 17,
		//RACE_FOREST_TROLL   = 18,
		//RACE_TAUNKA         = 19,
		//RACE_NORTHREND_SKELETON = 20,
		//RACE_ICE_TROLL      = 21,
	}

	// Class value is index in ChrClasses.dbc
	const enum Classes {
		CLASS_NONE          = 0, // SKIP
		CLASS_WARRIOR       = 1, // TITLE Warrior
		CLASS_PALADIN       = 2, // TITLE Paladin
		CLASS_HUNTER        = 3, // TITLE Hunter
		CLASS_ROGUE         = 4, // TITLE Rogue
		CLASS_PRIEST        = 5, // TITLE Priest
		CLASS_DEATH_KNIGHT  = 6, // TITLE Death Knight
		CLASS_SHAMAN        = 7, // TITLE Shaman
		CLASS_MAGE          = 8, // TITLE Mage
		CLASS_WARLOCK       = 9, // TITLE Warlock
		//CLASS_UNK           = 10,
		CLASS_DRUID         = 11,// TITLE Druid
	}

	const enum TeamId {
		TEAM_ALLIANCE = 0,
		TEAM_HORDE,
		TEAM_NEUTRAL,
	}

	// indexes of BattlemasterList.dbc
	const enum BattlegroundTypeId {
		BATTLEGROUND_TYPE_NONE     = 0, // None
		BATTLEGROUND_AV            = 1, // Alterac Valley
		BATTLEGROUND_WS            = 2, // Warsong Gulch
		BATTLEGROUND_AB            = 3, // Arathi Basin
		BATTLEGROUND_NA            = 4, // Nagrand Arena
		BATTLEGROUND_BE            = 5, // Blade's Edge Arena
		BATTLEGROUND_AA            = 6, // All Arenas
		BATTLEGROUND_EY            = 7, // Eye of the Storm
		BATTLEGROUND_RL            = 8, // Ruins of Lordaernon
		BATTLEGROUND_SA            = 9, // Strand of the Ancients
		BATTLEGROUND_DS            = 10, // Dalaran Sewers
		BATTLEGROUND_RV            = 11, // Ring of Valor
		BATTLEGROUND_IC            = 30, // Isle of Conquest
		BATTLEGROUND_RB            = 32, // Random Battleground
	}

	const enum AccountTypes {
		SEC_PLAYER         = 0,
		SEC_MODERATOR      = 1,
		SEC_GAMEMASTER     = 2,
		SEC_ADMINISTRATOR  = 3,
		SEC_CONSOLE        = 4,                                 // must be always last in list, accounts must have less security level always also
	}

	const enum Difficulty {
		REGULAR_DIFFICULTY           = 0,

		DUNGEON_DIFFICULTY_NORMAL    = 0,
		DUNGEON_DIFFICULTY_HEROIC    = 1,
		DUNGEON_DIFFICULTY_EPIC      = 2,

		RAID_DIFFICULTY_10MAN_NORMAL = 0,
		RAID_DIFFICULTY_25MAN_NORMAL = 1,
		RAID_DIFFICULTY_10MAN_HEROIC = 2,
		RAID_DIFFICULTY_25MAN_HEROIC = 3,
	}

	const enum PlayerChatTag {
		CHAT_TAG_NONE       = 0x00,
		CHAT_TAG_AFK        = 0x01,
		CHAT_TAG_DND        = 0x02,
		CHAT_TAG_GM         = 0x04,
		CHAT_TAG_COM        = 0x08, // Commentator tag. Do not exist in clean client
		CHAT_TAG_DEV        = 0x10,
	}

	const enum LocaleConstant {
		LOCALE_enUS = 0,
		LOCALE_koKR = 1,
		LOCALE_frFR = 2,
		LOCALE_deDE = 3,
		LOCALE_zhCN = 4,
		LOCALE_zhTW = 5,
		LOCALE_esES = 6,
		LOCALE_esMX = 7,
		LOCALE_ruRU = 8,
	}

	const enum ReputationRank {
		REP_HATED       = 0,
		REP_HOSTILE     = 1,
		REP_UNFRIENDLY  = 2,
		REP_NEUTRAL     = 3,
		REP_FRIENDLY    = 4,
		REP_HONORED     = 5,
		REP_REVERED     = 6,
		REP_EXALTED     = 7,
	}

	const enum QuestStatus {
		QUEST_STATUS_NONE           = 0,
		QUEST_STATUS_COMPLETE       = 1,
		//QUEST_STATUS_UNAVAILABLE    = 2,
		QUEST_STATUS_INCOMPLETE     = 3,
		//QUEST_STATUS_AVAILABLE      = 4,
		QUEST_STATUS_FAILED         = 5,
		QUEST_STATUS_REWARDED       = 6,        // Not used in DB
	}

	const enum SkillType {
		SKILL_NONE                     = 0,

		SKILL_FROST                    = 6,
		SKILL_FIRE                     = 8,
		SKILL_ARMS                     = 26,
		SKILL_COMBAT                   = 38,
		SKILL_SUBTLETY                 = 39,
		SKILL_SWORDS                   = 43,
		SKILL_AXES                     = 44,
		SKILL_BOWS                     = 45,
		SKILL_GUNS                     = 46,
		SKILL_BEAST_MASTERY            = 50,
		SKILL_SURVIVAL                 = 51,
		SKILL_MACES                    = 54,
		SKILL_2H_SWORDS                = 55,
		SKILL_HOLY                     = 56,
		SKILL_SHADOW                   = 78,
		SKILL_DEFENSE                  = 95,
		SKILL_LANG_COMMON              = 98,
		SKILL_RACIAL_DWARVEN           = 101,
		SKILL_LANG_ORCISH              = 109,
		SKILL_LANG_DWARVEN             = 111,
		SKILL_LANG_DARNASSIAN          = 113,
		SKILL_LANG_TAURAHE             = 115,
		SKILL_DUAL_WIELD               = 118,
		SKILL_RACIAL_TAUREN            = 124,
		SKILL_ORC_RACIAL               = 125,
		SKILL_RACIAL_NIGHT_ELF         = 126,
		SKILL_FIRST_AID                = 129,
		SKILL_FERAL_COMBAT             = 134,
		SKILL_STAVES                   = 136,
		SKILL_LANG_THALASSIAN          = 137,
		SKILL_LANG_DRACONIC            = 138,
		SKILL_LANG_DEMON_TONGUE        = 139,
		SKILL_LANG_TITAN               = 140,
		SKILL_LANG_OLD_TONGUE          = 141,
		SKILL_SURVIVAL2                = 142,
		SKILL_RIDING_HORSE             = 148,
		SKILL_RIDING_WOLF              = 149,
		SKILL_RIDING_TIGER             = 150,
		SKILL_RIDING_RAM               = 152,
		SKILL_SWIMING                  = 155,
		SKILL_2H_MACES                 = 160,
		SKILL_UNARMED                  = 162,
		SKILL_MARKSMANSHIP             = 163,
		SKILL_BLACKSMITHING            = 164,
		SKILL_LEATHERWORKING           = 165,
		SKILL_ALCHEMY                  = 171,
		SKILL_2H_AXES                  = 172,
		SKILL_DAGGERS                  = 173,
		SKILL_THROWN                   = 176,
		SKILL_HERBALISM                = 182,
		SKILL_GENERIC_DND              = 183,
		SKILL_RETRIBUTION              = 184,
		SKILL_COOKING                  = 185,
		SKILL_MINING                   = 186,
		SKILL_PET_IMP                  = 188,
		SKILL_PET_FELHUNTER            = 189,
		SKILL_TAILORING                = 197,
		SKILL_ENGINEERING              = 202,
		SKILL_PET_SPIDER               = 203,
		SKILL_PET_VOIDWALKER           = 204,
		SKILL_PET_SUCCUBUS             = 205,
		SKILL_PET_INFERNAL             = 206,
		SKILL_PET_DOOMGUARD            = 207,
		SKILL_PET_WOLF                 = 208,
		SKILL_PET_CAT                  = 209,
		SKILL_PET_BEAR                 = 210,
		SKILL_PET_BOAR                 = 211,
		SKILL_PET_CROCILISK            = 212,
		SKILL_PET_CARRION_BIRD         = 213,
		SKILL_PET_CRAB                 = 214,
		SKILL_PET_GORILLA              = 215,
		SKILL_PET_RAPTOR               = 217,
		SKILL_PET_TALLSTRIDER          = 218,
		SKILL_RACIAL_UNDED             = 220,
		SKILL_CROSSBOWS                = 226,
		SKILL_WANDS                    = 228,
		SKILL_POLEARMS                 = 229,
		SKILL_PET_SCORPID              = 236,
		SKILL_ARCANE                   = 237,
		SKILL_PET_TURTLE               = 251,
		SKILL_ASSASSINATION            = 253,
		SKILL_FURY                     = 256,
		SKILL_PROTECTION               = 257,
		SKILL_PROTECTION2              = 267,
		SKILL_PET_TALENTS              = 270,
		SKILL_PLATE_MAIL               = 293,
		SKILL_LANG_GNOMISH             = 313,
		SKILL_LANG_TROLL               = 315,
		SKILL_ENCHANTING               = 333,
		SKILL_DEMONOLOGY               = 354,
		SKILL_AFFLICTION               = 355,
		SKILL_FISHING                  = 356,
		SKILL_ENHANCEMENT              = 373,
		SKILL_RESTORATION              = 374,
		SKILL_ELEMENTAL_COMBAT         = 375,
		SKILL_SKINNING                 = 393,
		SKILL_MAIL                     = 413,
		SKILL_LEATHER                  = 414,
		SKILL_CLOTH                    = 415,
		SKILL_SHIELD                   = 433,
		SKILL_FIST_WEAPONS             = 473,
		SKILL_RIDING_RAPTOR            = 533,
		SKILL_RIDING_MECHANOSTRIDER    = 553,
		SKILL_RIDING_UNDEAD_HORSE      = 554,
		SKILL_RESTORATION2             = 573,
		SKILL_BALANCE                  = 574,
		SKILL_DESTRUCTION              = 593,
		SKILL_HOLY2                    = 594,
		SKILL_DISCIPLINE               = 613,
		SKILL_LOCKPICKING              = 633,
		SKILL_PET_BAT                  = 653,
		SKILL_PET_HYENA                = 654,
		SKILL_PET_BIRD_OF_PREY         = 655,
		SKILL_PET_WIND_SERPENT         = 656,
		SKILL_LANG_GUTTERSPEAK         = 673,
		SKILL_RIDING_KODO              = 713,
		SKILL_RACIAL_TROLL             = 733,
		SKILL_RACIAL_GNOME             = 753,
		SKILL_RACIAL_HUMAN             = 754,
		SKILL_JEWELCRAFTING            = 755,
		SKILL_RACIAL_BLOODELF          = 756,
		SKILL_PET_EVENT_RC             = 758,
		SKILL_LANG_DRAENEI             = 759,
		SKILL_RACIAL_DRAENEI           = 760,
		SKILL_PET_FELGUARD             = 761,
		SKILL_RIDING                   = 762,
		SKILL_PET_DRAGONHAWK           = 763,
		SKILL_PET_NETHER_RAY           = 764,
		SKILL_PET_SPOREBAT             = 765,
		SKILL_PET_WARP_STALKER         = 766,
		SKILL_PET_RAVAGER              = 767,
		SKILL_PET_SERPENT              = 768,
		SKILL_INTERNAL                 = 769,
		SKILL_DK_BLOOD                 = 770,
		SKILL_DK_FROST                 = 771,
		SKILL_DK_UNHOLY                = 772,
		SKILL_INSCRIPTION              = 773,
		SKILL_PET_MOTH                 = 775,
		SKILL_RUNEFORGING              = 776,
		SKILL_MOUNTS                   = 777,
		SKILL_COMPANIONS               = 778,
		SKILL_PET_EXOTIC_CHIMAERA      = 780,
		SKILL_PET_EXOTIC_DEVILSAUR     = 781,
		SKILL_PET_GHOUL                = 782,
		SKILL_PET_EXOTIC_SILITHID      = 783,
		SKILL_PET_EXOTIC_WORM          = 784,
		SKILL_PET_WASP                 = 785,
		SKILL_PET_EXOTIC_RHINO         = 786,
		SKILL_PET_EXOTIC_CORE_HOUND    = 787,
		SKILL_PET_EXOTIC_SPIRIT_BEAST  = 788,
	}

	const enum ItemSubclassArmor {
		ITEM_SUBCLASS_ARMOR_MISC                    = 0,
		ITEM_SUBCLASS_ARMOR_CLOTH                   = 1,
		ITEM_SUBCLASS_ARMOR_LEATHER                 = 2,
		ITEM_SUBCLASS_ARMOR_MAIL                    = 3,
		ITEM_SUBCLASS_ARMOR_PLATE                   = 4,
		ITEM_SUBCLASS_ARMOR_BUCKLER                 = 5,
		ITEM_SUBCLASS_ARMOR_SHIELD                  = 6,
		ITEM_SUBCLASS_ARMOR_LIBRAM                  = 7,
		ITEM_SUBCLASS_ARMOR_IDOL                    = 8,
		ITEM_SUBCLASS_ARMOR_TOTEM                   = 9,
		ITEM_SUBCLASS_ARMOR_SIGIL                   = 10,
	}

	const enum ItemSubclassWeapon {
		ITEM_SUBCLASS_WEAPON_AXE                    = 0,
		ITEM_SUBCLASS_WEAPON_AXE2                   = 1,
		ITEM_SUBCLASS_WEAPON_BOW                    = 2,
		ITEM_SUBCLASS_WEAPON_GUN                    = 3,
		ITEM_SUBCLASS_WEAPON_MACE                   = 4,
		ITEM_SUBCLASS_WEAPON_MACE2                  = 5,
		ITEM_SUBCLASS_WEAPON_POLEARM                = 6,
		ITEM_SUBCLASS_WEAPON_SWORD                  = 7,
		ITEM_SUBCLASS_WEAPON_SWORD2                 = 8,
		ITEM_SUBCLASS_WEAPON_obsolete               = 9,
		ITEM_SUBCLASS_WEAPON_STAFF                  = 10,
		ITEM_SUBCLASS_WEAPON_EXOTIC                 = 11,
		ITEM_SUBCLASS_WEAPON_EXOTIC2                = 12,
		ITEM_SUBCLASS_WEAPON_FIST                   = 13,
		ITEM_SUBCLASS_WEAPON_MISC                   = 14,
		ITEM_SUBCLASS_WEAPON_DAGGER                 = 15,
		ITEM_SUBCLASS_WEAPON_THROWN                 = 16,
		ITEM_SUBCLASS_WEAPON_SPEAR                  = 17,
		ITEM_SUBCLASS_WEAPON_CROSSBOW               = 18,
		ITEM_SUBCLASS_WEAPON_WAND                   = 19,
		ITEM_SUBCLASS_WEAPON_FISHING_POLE           = 20,
	}

	const enum DatabaseFieldTypes {
		Null,
		Int8,
		Int16,
		Int32,
		Int64,
		Float,
		Double,
		Decimal,
		Date,
		Binary,
	}

	const enum ArenaType {
		ARENA_TYPE_NONE                 = 0,
		ARENA_TYPE_2v2                  = 2,
		ARENA_TYPE_3v3                  = 3,
		ARENA_TYPE_5v5                  = 5,
	}

	const enum AcoreStrings {
		// for chat commands
		LANG_SELECT_CHAR_OR_CREATURE        = 1,
		LANG_SELECT_CREATURE                = 2,

		// level 0 chat
		LANG_SYSTEMMESSAGE                  = 3,
		LANG_EVENTMESSAGE                   = 4,
		LANG_NO_HELP_CMD                    = 5,
		LANG_CMD_INVALID                    = 6,
		LANG_SUBCMD_AMBIGUOUS               = 7,
		LANG_SUBCMDS_LIST                   = 8,
		LANG_AVAILABLE_CMDS                 = 9,
		LANG_CMD_SYNTAX                     = 10,
		LANG_ACCOUNT_LEVEL                  = 11,
		LANG_CONNECTED_USERS                = 12,
		LANG_UPTIME                         = 13,
		LANG_PLAYER_SAVED                   = 14,
		LANG_PLAYERS_SAVED                  = 15,
		LANG_GMS_ON_SRV                     = 16,
		LANG_GMS_NOT_LOGGED                 = 17,
		LANG_YOU_IN_FLIGHT                  = 18,
		LANG_UPDATE_DIFF                    = 19,
		LANG_SHUTDOWN_TIMELEFT              = 20,
		LANG_CHAR_IN_FLIGHT                 = 21,
		LANG_CHAR_NON_MOUNTED               = 22,
		LANG_YOU_IN_COMBAT                  = 23,
		LANG_YOU_USED_IT_RECENTLY           = 24,
		LANG_COMMAND_NOTCHANGEPASSWORD      = 25,
		LANG_COMMAND_PASSWORD               = 26,
		LANG_COMMAND_WRONGOLDPASSWORD       = 27,
		LANG_COMMAND_ACCLOCKLOCKED          = 28,
		LANG_COMMAND_ACCLOCKUNLOCKED        = 29,
		LANG_SPELL_RANK                     = 30,
		LANG_KNOWN                          = 31,
		LANG_LEARN                          = 32,
		LANG_PASSIVE                        = 33,
		LANG_TALENT                         = 34,
		LANG_ACTIVE                         = 35,
		LANG_COMPLETE                       = 36,
		LANG_OFFLINE                        = 37,
		LANG_ON                             = 38,
		LANG_OFF                            = 39,
		LANG_YOU_ARE                        = 40,
		LANG_VISIBLE                        = 41,
		LANG_INVISIBLE                      = 42,
		LANG_DONE                           = 43,
		LANG_YOU                            = 44,
		LANG_UNKNOWN                        = 45,
		LANG_ERROR                          = 46,
		LANG_NON_EXIST_CHARACTER            = 47,
		LANG_FRIEND_IGNORE_UNKNOWN          = 48,
		LANG_LEVEL_MINREQUIRED              = 49,
		LANG_LEVEL_MINREQUIRED_AND_ITEM     = 50,
		LANG_NPC_TAINER_HELLO               = 51,
		LANG_COMMAND_INVALID_ITEM_COUNT     = 52,
		LANG_COMMAND_MAIL_ITEMS_LIMIT       = 53,
		LANG_NEW_PASSWORDS_NOT_MATCH        = 54,
		LANG_PASSWORD_TOO_LONG              = 55,
		LANG_MOTD_CURRENT                   = 56,
		LANG_USING_WORLD_DB                 = 57,
		LANG_USING_SCRIPT_LIB               = 58,
		LANG_USING_EVENT_AI                 = 59,
		LANG_CONNECTED_PLAYERS              = 60,
		LANG_ACCOUNT_ADDON                  = 61,
		LANG_IMPROPER_VALUE                 = 62,
		LANG_RBAC_WRONG_PARAMETER_ID        = 63,
		LANG_RBAC_WRONG_PARAMETER_REALM     = 64,
		LANG_RBAC_LIST_HEADER_GRANTED       = 65,
		LANG_RBAC_LIST_HEADER_DENIED        = 66,
		LANG_RBAC_LIST_HEADER_BY_SEC_LEVEL  = 67,
		LANG_RBAC_LIST_PERMISSIONS_HEADER   = 68,
		LANG_RBAC_LIST_PERMS_LINKED_HEADER  = 69,
		LANG_RBAC_LIST_EMPTY                = 70,
		LANG_RBAC_LIST_ELEMENT              = 71,
		LANG_RBAC_PERM_GRANTED_IN_LIST      = 72,
		LANG_RBAC_PERM_GRANTED_IN_DENIED_LIST = 73,
		LANG_RBAC_PERM_GRANTED              = 74,
		LANG_RBAC_PERM_DENIED_IN_LIST       = 75,
		LANG_RBAC_PERM_DENIED_IN_GRANTED_LIST = 76,
		LANG_RBAC_PERM_DENIED               = 77,
		LANG_RBAC_PERM_REVOKED              = 78,
		LANG_RBAC_PERM_REVOKED_NOT_IN_LIST  = 79,
		LANG_PVPSTATS                       = 80,
		LANG_PVPSTATS_DISABLED              = 81,
		LANG_GENERIC_TWO_CURLIES_WITH_COLON = 82,
		LANG_RBAC_HELP_ACC_LIST             = 83,
		LANG_RBAC_HELP_ACC_GRANT            = 84,
		LANG_RBAC_HELP_ACC_DENY             = 85,
		LANG_RBAC_HELP_ACC_REVOKE           = 86,

		LANG_UNKNOWN_ERROR                  = 87,
		LANG_2FA_COMMANDS_NOT_SETUP         = 88,
		LANG_2FA_ALREADY_SETUP              = 89,
		LANG_2FA_INVALID_TOKEN              = 90,
		LANG_2FA_SECRET_SUGGESTION          = 91,
		LANG_2FA_SETUP_COMPLETE             = 92,
		LANG_2FA_NOT_SETUP                  = 93,
		LANG_2FA_REMOVE_NEED_TOKEN          = 94,
		LANG_2FA_REMOVE_COMPLETE            = 95,

		LANG_GUILD_RENAME_ALREADY_EXISTS    = 96,
		LANG_GUILD_RENAME_DONE              = 97,
		LANG_RENAME_PLAYER_ALREADY_EXISTS   = 98,
		LANG_RENAME_PLAYER_WITH_NEW_NAME    = 99,

		// level 1 chat
		LANG_GLOBAL_NOTIFY                  = 100,
		LANG_MAP_POSITION                   = 101,
		LANG_IS_TELEPORTED                  = 102,
		LANG_CANNOT_SUMMON_TO_INST          = 103,
		LANG_CANNOT_GO_TO_INST_PARTY        = 104,
		LANG_CANNOT_GO_TO_INST_GM           = 105,
		LANG_CANNOT_GO_INST_INST            = 106,
		LANG_CANNOT_SUMMON_INST_INST        = 107,
		LANG_SUMMONING                      = 108,
		LANG_SUMMONED_BY                    = 109,
		LANG_TELEPORTING_TO                 = 110,
		LANG_TELEPORTED_TO_BY               = 111,
		LANG_NO_PLAYER                      = 112,
		LANG_APPEARING_AT                   = 113,
		LANG_APPEARING_TO                   = 114,
		LANG_BAD_VALUE                      = 115,
		LANG_NO_CHAR_SELECTED               = 116,
		LANG_NOT_IN_GROUP                   = 117,

		LANG_YOU_CHANGE_HP                  = 118,
		LANG_YOURS_HP_CHANGED               = 119,
		LANG_YOU_CHANGE_MANA                = 120,
		LANG_YOURS_MANA_CHANGED             = 121,
		LANG_YOU_CHANGE_ENERGY              = 122,
		LANG_YOURS_ENERGY_CHANGED           = 123,

		LANG_CURRENT_ENERGY                 = 124,              //log
		LANG_YOU_CHANGE_RAGE                = 125,
		LANG_YOURS_RAGE_CHANGED             = 126,
		LANG_YOU_CHANGE_LVL                 = 127,
		LANG_CURRENT_FACTION                = 128,
		LANG_WRONG_FACTION                  = 129,
		LANG_YOU_CHANGE_FACTION             = 130,
		LANG_YOU_CHANGE_SPELLFLATID         = 131,
		LANG_YOURS_SPELLFLATID_CHANGED      = 132,
		LANG_YOU_GIVE_TAXIS                 = 133,
		LANG_YOU_REMOVE_TAXIS               = 134,
		LANG_YOURS_TAXIS_ADDED              = 135,
		LANG_YOURS_TAXIS_REMOVED            = 136,

		LANG_YOU_CHANGE_ASPEED              = 137,
		LANG_YOURS_ASPEED_CHANGED           = 138,
		LANG_YOU_CHANGE_SPEED               = 139,
		LANG_YOURS_SPEED_CHANGED            = 140,
		LANG_YOU_CHANGE_SWIM_SPEED          = 141,
		LANG_YOURS_SWIM_SPEED_CHANGED       = 142,
		LANG_YOU_CHANGE_BACK_SPEED          = 143,
		LANG_YOURS_BACK_SPEED_CHANGED       = 144,
		LANG_YOU_CHANGE_FLY_SPEED           = 145,
		LANG_YOURS_FLY_SPEED_CHANGED        = 146,

		LANG_YOU_CHANGE_SIZE                = 147,
		LANG_YOURS_SIZE_CHANGED             = 148,
		LANG_NO_MOUNT                       = 149,
		LANG_YOU_GIVE_MOUNT                 = 150,
		LANG_MOUNT_GIVED                    = 151,

		LANG_CURRENT_MONEY                  = 152,
		LANG_YOU_TAKE_ALL_MONEY             = 153,
		LANG_YOURS_ALL_MONEY_GONE           = 154,
		LANG_YOU_TAKE_MONEY                 = 155,
		LANG_YOURS_MONEY_TAKEN              = 156,
		LANG_YOU_GIVE_MONEY                 = 157,
		LANG_YOURS_MONEY_GIVEN              = 158,
		LANG_YOU_HEAR_SOUND                 = 159,

		LANG_NEW_MONEY                      = 160,              // Log

		LANG_REMOVE_BIT                     = 161,
		LANG_SET_BIT                        = 162,
		LANG_COMMAND_TELE_TABLEEMPTY        = 163,
		LANG_COMMAND_TELE_NOTFOUND          = 164,
		LANG_COMMAND_TELE_PARAMETER         = 165,
		LANG_COMMAND_TELE_NOLOCATION        = 166,
		LANG_RESERVED_NAME                  = 167,
		LANG_COMMAND_TELE_LOCATION          = 168,

		LANG_MAIL_SENT                      = 169,
		LANG_SOUND_NOT_EXIST                = 170,
		LANG_CANT_TELEPORT_SELF             = 171,
		LANG_CONSOLE_COMMAND                = 172,
		LANG_YOU_CHANGE_RUNIC_POWER         = 173,
		LANG_YOURS_RUNIC_POWER_CHANGED      = 174,
		LANG_LIQUID_STATUS                  = 175,
		LANG_INVALID_GAMEOBJECT_TYPE        = 176,
		LANG_GAMEOBJECT_DAMAGED             = 177,
		LANG_GRID_POSITION                  = 178,

		LANG_ACCOUNT_FLAGS_PINFO            = 179,

		// Free 180-185

		LANG_TRANSPORT_POSITION             = 186,
		LANG_PROFANITY_NAME                 = 187,
		LANG_2FA_SECRET_TOO_LONG            = 188,
		LANG_2FA_SECRET_INVALID             = 189,
		LANG_2FA_SECRET_SET_COMPLETE        = 190,
		LANG_SUBCMDS_LIST_ENTRY             = 191,
		LANG_SUBCMDS_LIST_ENTRY_ELLIPSIS    = 192,
		LANG_SUBCMD_INVALID                 = 193,
		LANG_CMD_AMBIGUOUS                  = 194,
		LANG_CMD_HELP_GENERIC               = 195,
		LANG_CMD_NO_HELP_AVAILABLE          = 196,

		LANG_ITEM_RESTORE_LIST              = 197,
		LANG_ITEM_RESTORE_LIST_EMPTY        = 198,
		LANG_ITEM_RESTORE_MISSING           = 199,

		// level 2 chat
		LANG_NO_SELECTION                   = 200,
		LANG_OBJECT_GUID                    = 201,
		LANG_TOO_LONG_NAME                  = 202,
		LANG_CHARS_ONLY                     = 203,
		LANG_TOO_LONG_SUBNAME               = 204,
		LANG_NOT_IMPLEMENTED                = 205,

		LANG_ITEM_ADDED_TO_LIST             = 206,
		LANG_ITEM_NOT_FOUND                 = 207,
		LANG_ITEM_DELETED_FROM_LIST         = 208,
		LANG_ITEM_NOT_IN_LIST               = 209,
		LANG_ITEM_ALREADY_IN_LIST           = 210,

		LANG_RESET_SPELLS_ONLINE            = 211,
		LANG_RESET_SPELLS_OFFLINE           = 212,
		LANG_RESET_TALENTS_ONLINE           = 213,
		LANG_RESET_TALENTS_OFFLINE          = 214,
		LANG_RESET_SPELLS                   = 215,
		LANG_RESET_TALENTS                  = 216,

		LANG_RESETALL_UNKNOWN_CASE          = 217,
		LANG_RESETALL_SPELLS                = 218,
		LANG_RESETALL_TALENTS               = 219,

		LANG_WAYPOINT_NOTFOUND              = 220,
		LANG_WAYPOINT_NOTFOUNDLAST          = 221,
		LANG_WAYPOINT_NOTFOUNDSEARCH        = 222,
		LANG_WAYPOINT_NOTFOUNDDBPROBLEM     = 223,
		LANG_WAYPOINT_CREATSELECTED         = 224,
		LANG_WAYPOINT_CREATNOTFOUND         = 225,
		LANG_WAYPOINT_VP_SELECT             = 226,
		LANG_WAYPOINT_VP_NOTFOUND           = 227,
		LANG_WAYPOINT_VP_NOTCREATED         = 228,
		LANG_WAYPOINT_VP_ALLREMOVED         = 229,
		LANG_WAYPOINT_NOTCREATED            = 230,
		LANG_WAYPOINT_NOGUID                = 231,
		LANG_WAYPOINT_NOWAYPOINTGIVEN       = 232,
		LANG_WAYPOINT_ARGUMENTREQ           = 233,
		LANG_WAYPOINT_ADDED                 = 234,
		LANG_WAYPOINT_ADDED_NO              = 235,
		LANG_WAYPOINT_CHANGED               = 236,
		LANG_WAYPOINT_CHANGED_NO            = 237,
		LANG_WAYPOINT_EXPORTED              = 238,
		LANG_WAYPOINT_NOTHINGTOEXPORT       = 239,
		LANG_WAYPOINT_IMPORTED              = 240,
		LANG_WAYPOINT_REMOVED               = 241,
		LANG_WAYPOINT_NOTREMOVED            = 242,
		LANG_WAYPOINT_TOOFAR1               = 243,
		LANG_WAYPOINT_TOOFAR2               = 244,
		LANG_WAYPOINT_TOOFAR3               = 245,
		LANG_WAYPOINT_INFO_TITLE            = 246,
		LANG_WAYPOINT_INFO_WAITTIME         = 247,
		LANG_WAYPOINT_INFO_MODEL            = 248,
		LANG_WAYPOINT_INFO_EMOTE            = 249,
		LANG_WAYPOINT_INFO_SPELL            = 250,
		LANG_WAYPOINT_INFO_TEXT             = 251,
		LANG_WAYPOINT_INFO_AISCRIPT         = 252,

		LANG_RENAME_PLAYER                  = 253,
		LANG_RENAME_PLAYER_GUID             = 254,

		LANG_WAYPOINT_WPCREATNOTFOUND       = 255,
		LANG_WAYPOINT_NPCNOTFOUND           = 256,

		LANG_MOVE_TYPE_SET                  = 257,
		LANG_MOVE_TYPE_SET_NODEL            = 258,
		LANG_USE_BOL                        = 259,
		LANG_VALUE_SAVED                    = 260,
		LANG_VALUE_SAVED_REJOIN             = 261,

		LANG_COMMAND_GOAREATRNOTFOUND       = 262,
		LANG_INVALID_TARGET_COORD           = 263,
		LANG_INVALID_ZONE_COORD             = 264,
		LANG_INVALID_ZONE_MAP               = 265,
		LANG_COMMAND_TARGETOBJNOTFOUND      = 266,
		LANG_COMMAND_GOOBJNOTFOUND          = 267,
		LANG_COMMAND_GOCREATNOTFOUND        = 268,
		LANG_COMMAND_GOCREATMULTIPLE        = 269,
		LANG_COMMAND_DELCREATMESSAGE        = 270,
		LANG_COMMAND_CREATUREMOVED          = 271,
		LANG_COMMAND_CREATUREATSAMEMAP      = 272,
		LANG_COMMAND_OBJNOTFOUND            = 273,
		LANG_COMMAND_DELOBJREFERCREATURE    = 274,
		LANG_COMMAND_DELOBJMESSAGE          = 275,
		LANG_COMMAND_TURNOBJMESSAGE         = 276,
		LANG_COMMAND_MOVEOBJMESSAGE         = 277,
		LANG_COMMAND_VENDORSELECTION        = 278,
		LANG_COMMAND_NEEDITEMSEND           = 279,
		LANG_COMMAND_ADDVENDORITEMITEMS     = 280,
		LANG_COMMAND_KICKSELF               = 281,
		LANG_COMMAND_KICKMESSAGE            = 282,
		LANG_COMMAND_DISABLE_CHAT_DELAYED   = 283,
		LANG_COMMAND_WHISPERACCEPTING       = 284,
		LANG_COMMAND_WHISPERON              = 285,
		LANG_COMMAND_WHISPEROFF             = 286,
		LANG_COMMAND_CREATGUIDNOTFOUND      = 287,
		LANG_COMMAND_GONOTENOUGHSPAWNS      = 288,
		// TICKET STRINGS NEED REWRITE // 289-296 FREE

		// END
		LANG_COMMAND_WANDER_DISTANCE        = 297,
		LANG_COMMAND_SPAWNTIME              = 298,
		LANG_COMMAND_MODIFY_HONOR           = 299,

		LANG_YOUR_CHAT_DISABLED             = 300,
		LANG_YOU_DISABLE_CHAT               = 301,
		LANG_CHAT_ALREADY_ENABLED           = 302,
		LANG_YOUR_CHAT_ENABLED              = 303,
		LANG_YOU_ENABLE_CHAT                = 304,

		LANG_COMMAND_MODIFY_REP             = 305,
		LANG_COMMAND_MODIFY_ARENA           = 306,
		LANG_COMMAND_FACTION_NOTFOUND       = 307,
		LANG_COMMAND_FACTION_UNKNOWN        = 308,
		LANG_COMMAND_FACTION_INVPARAM       = 309,
		LANG_COMMAND_FACTION_DELTA          = 310,
		LANG_FACTION_LIST                   = 311,
		LANG_FACTION_VISIBLE                = 312,
		LANG_FACTION_ATWAR                  = 313,
		LANG_FACTION_PEACE_FORCED           = 314,
		LANG_FACTION_HIDDEN                 = 315,
		LANG_FACTION_INVISIBLE_FORCED       = 316,
		LANG_FACTION_INACTIVE               = 317,
		LANG_REP_HATED                      = 318,
		LANG_REP_HOSTILE                    = 319,
		LANG_REP_UNFRIENDLY                 = 320,
		LANG_REP_NEUTRAL                    = 321,
		LANG_REP_FRIENDLY                   = 322,
		LANG_REP_HONORED                    = 323,
		LANG_REP_REVERED                    = 324,
		LANG_REP_EXALTED                    = 325,
		LANG_COMMAND_FACTION_NOREP_ERROR    = 326,
		LANG_FACTION_NOREPUTATION           = 327,
		LANG_LOOKUP_PLAYER_ACCOUNT          = 328,
		LANG_LOOKUP_PLAYER_CHARACTER        = 329,
		LANG_NO_PLAYERS_FOUND               = 330,
		LANG_EXTENDED_COST_NOT_EXIST        = 331,
		LANG_GM_ON                          = 332,
		LANG_GM_OFF                         = 333,
		LANG_GM_CHAT_ON                     = 334,
		LANG_GM_CHAT_OFF                    = 335,
		LANG_YOU_REPAIR_ITEMS               = 336,
		LANG_YOUR_ITEMS_REPAIRED            = 337,
		LANG_YOU_SET_WATERWALK              = 338,
		LANG_YOUR_WATERWALK_SET             = 339,
		LANG_CREATURE_FOLLOW_YOU_NOW        = 340,
		LANG_CREATURE_NOT_FOLLOW_YOU        = 341,
		LANG_CREATURE_NOT_FOLLOW_YOU_NOW    = 342,
		LANG_CREATURE_NON_TAMEABLE          = 343,
		LANG_YOU_ALREADY_HAVE_PET           = 344,
		LANG_CUSTOMIZE_PLAYER               = 345,
		LANG_CUSTOMIZE_PLAYER_GUID          = 346,
		LANG_COMMAND_GOTAXINODENOTFOUND     = 347,
		LANG_GAMEOBJECT_HAVE_INVALID_DATA   = 348,
		LANG_TITLE_LIST_CHAT                = 349,
		LANG_TITLE_LIST_CONSOLE             = 350,
		LANG_COMMAND_NOTITLEFOUND           = 351,
		LANG_INVALID_TITLE_ID               = 352,
		LANG_TITLE_ADD_RES                  = 353,
		LANG_TITLE_REMOVE_RES               = 354,
		LANG_TITLE_CURRENT_RES              = 355,
		LANG_CURRENT_TITLE_RESET            = 356,
		LANG_COMMAND_CHEAT_STATUS           = 357,
		LANG_COMMAND_CHEAT_GOD              = 358,
		LANG_COMMAND_CHEAT_CT               = 359,
		LANG_COMMAND_CHEAT_CD               = 360,
		LANG_COMMAND_CHEAT_POWER            = 361,
		LANG_COMMAND_CHEAT_WW               = 362,
		LANG_COMMAND_WHISPEROFFPLAYER       = 363,
		LANG_COMMAND_CHEAT_TAXINODES        = 364,

		// [START] .reset items command strings:
		LANG_COMMAND_RESET_ITEMS_EQUIPPED   = 365,
		LANG_COMMAND_RESET_ITEMS_BAGS       = 366,
		LANG_COMMAND_RESET_ITEMS_BANK       = 367,
		LANG_COMMAND_RESET_ITEMS_KEYRING    = 368,
		LANG_COMMAND_RESET_ITEMS_CURRENCY   = 369,
		LANG_COMMAND_RESET_ITEMS_BUYBACK    = 370,
		LANG_COMMAND_RESET_ITEMS_ALL        = 371,
		LANG_COMMAND_RESET_ITEMS_ALL_BAGS   = 372,
		// [END] reset items command strings

		// .aura stack
		LANG_COMMAND_AURASTACK_NO_AURA      = 373,
		LANG_COMMAND_AURASTACK_NO_STACK     = 374,
		LANG_COMMAND_AURASTACK_CANT_STACK   = 375,

		// Room for more level 2              376-399 not used

		// level 3 chat
		LANG_SCRIPTS_RELOADED               = 400,
		LANG_YOU_CHANGE_SECURITY            = 401,
		LANG_YOURS_SECURITY_CHANGED         = 402,
		LANG_YOURS_SECURITY_IS_LOW          = 403,
		LANG_CREATURE_MOVE_DISABLED         = 404,
		LANG_CREATURE_MOVE_ENABLED          = 405,
		LANG_NO_WEATHER                     = 406,
		LANG_WEATHER_DISABLED               = 407,

		LANG_BAN_YOUBANNED                  = 408,
		LANG_BAN_YOUPERMBANNED              = 409,
		LANG_BAN_NOTFOUND                   = 410,

		LANG_UNBAN_UNBANNED                 = 411,
		LANG_UNBAN_ERROR                    = 412,

		LANG_ACCOUNT_NOT_EXIST              = 413,

		LANG_BANINFO_NOCHARACTER            = 414,
		LANG_BANINFO_NOIP                   = 415,
		LANG_BANINFO_NOACCOUNTBAN           = 416,
		LANG_BANINFO_BANHISTORY             = 417,
		LANG_BANINFO_HISTORYENTRY           = 418,
		LANG_BANINFO_INFINITE               = 419,
		LANG_BANINFO_NEVER                  = 420,
		LANG_YES                            = 421,
		LANG_NO                             = 422,
		LANG_BANINFO_IPENTRY                = 423,

		LANG_BANLIST_NOIP                   = 424,
		LANG_BANLIST_NOACCOUNT              = 425,
		LANG_BANLIST_NOCHARACTER            = 426,
		LANG_BANLIST_MATCHINGIP             = 427,
		LANG_BANLIST_MATCHINGACCOUNT        = 428,

		LANG_COMMAND_LEARN_MANY_SPELLS      = 429,
		LANG_COMMAND_LEARN_CLASS_SPELLS     = 430,
		LANG_COMMAND_LEARN_CLASS_TALENTS    = 431,
		LANG_COMMAND_LEARN_ALL_LANG         = 432,
		LANG_COMMAND_LEARN_ALL_CRAFT        = 433,
		LANG_COMMAND_COULDNOTFIND           = 434,
		LANG_COMMAND_ITEMIDINVALID          = 435,
		LANG_COMMAND_NOITEMFOUND            = 436,
		LANG_COMMAND_LISTOBJINVALIDID       = 437,
		LANG_COMMAND_LISTITEMMESSAGE        = 438,
		LANG_COMMAND_LISTOBJMESSAGE         = 439,
		LANG_COMMAND_INVALIDCREATUREID      = 440,
		LANG_COMMAND_LISTCREATUREMESSAGE    = 441,
		LANG_COMMAND_NOAREAFOUND            = 442,
		LANG_COMMAND_NOITEMSETFOUND         = 443,
		LANG_COMMAND_NOSKILLFOUND           = 444,
		LANG_COMMAND_NOSPELLFOUND           = 445,
		LANG_COMMAND_NOQUESTFOUND           = 446,
		LANG_COMMAND_NOCREATUREFOUND        = 447,
		LANG_COMMAND_NOGAMEOBJECTFOUND      = 448,
		LANG_COMMAND_GRAVEYARDNOEXIST       = 449,
		LANG_COMMAND_GRAVEYARDALRLINKED     = 450,
		LANG_COMMAND_GRAVEYARDLINKED        = 451,
		LANG_COMMAND_GRAVEYARDWRONGZONE     = 452,
		//                                  = 453, see LANG_PINFO_BAN
		LANG_COMMAND_GRAVEYARDERROR         = 454,
		LANG_COMMAND_GRAVEYARD_NOTEAM       = 455,
		LANG_COMMAND_GRAVEYARD_ANY          = 456,
		LANG_COMMAND_GRAVEYARD_ALLIANCE     = 457,
		LANG_COMMAND_GRAVEYARD_HORDE        = 458,
		LANG_COMMAND_GRAVEYARDNEAREST       = 459,
		LANG_COMMAND_ZONENOGRAVEYARDS       = 460,
		LANG_COMMAND_ZONENOGRAFACTION       = 461,
		LANG_COMMAND_TP_ALREADYEXIST        = 462,
		LANG_COMMAND_TP_ADDED               = 463,
		LANG_COMMAND_TP_ADDEDERR            = 464,
		LANG_COMMAND_TP_DELETED             = 465,
		LANG_COMMAND_NOTAXINODEFOUND        = 466,
		LANG_COMMAND_TARGET_LISTAURAS       = 467,
		LANG_COMMAND_TARGET_AURADETAIL      = 468,
		LANG_COMMAND_TARGET_LISTAURATYPE    = 469,
		LANG_COMMAND_TARGET_AURASIMPLE      = 470,

		LANG_COMMAND_QUEST_NOTFOUND         = 471,
		LANG_COMMAND_QUEST_STARTFROMITEM    = 472,
		LANG_COMMAND_QUEST_REMOVED          = 473,
		LANG_COMMAND_QUEST_REWARDED         = 474,
		LANG_COMMAND_QUEST_COMPLETE         = 475,
		LANG_COMMAND_QUEST_ACTIVE           = 476,

		LANG_COMMAND_FLYMODE_STATUS         = 477,

		LANG_COMMAND_OPCODESENT             = 478,

		LANG_COMMAND_IMPORT_SUCCESS         = 479,
		LANG_COMMAND_IMPORT_FAILED          = 480,
		LANG_COMMAND_EXPORT_SUCCESS         = 481,
		LANG_COMMAND_EXPORT_FAILED          = 482,

		LANG_COMMAND_SPELL_BROKEN           = 483,

		LANG_SET_SKILL                      = 484,
		LANG_SET_SKILL_ERROR                = 485,

		LANG_INVALID_SKILL_ID               = 486,
		LANG_LEARNING_GM_SKILLS             = 487,
		LANG_YOU_KNOWN_SPELL                = 488,
		LANG_TARGET_KNOWN_SPELL             = 489,
		LANG_UNKNOWN_SPELL                  = 490,
		LANG_FORGET_SPELL                   = 491,
		LANG_REMOVEALL_COOLDOWN             = 492,
		LANG_REMOVE_COOLDOWN                = 493,

		LANG_ADDITEM                        = 494,              //log
		LANG_ADDITEMSET                     = 495,              //log
		LANG_REMOVEITEM                     = 496,
		LANG_ITEM_CANNOT_CREATE             = 497,
		LANG_INSERT_GUILD_NAME              = 498,
		LANG_PLAYER_NOT_FOUND               = 499,
		LANG_PLAYER_IN_GUILD                = 500,
		LANG_GUILD_NOT_CREATED              = 501,
		LANG_NO_ITEMS_FROM_ITEMSET_FOUND    = 502,

		LANG_DISTANCE                       = 503,

		LANG_ITEM_SLOT                      = 504,
		LANG_ITEM_SLOT_NOT_EXIST            = 505,
		LANG_ITEM_ADDED_TO_SLOT             = 506,
		LANG_ITEM_SAVE_FAILED               = 507,
		LANG_ITEMLIST_SLOT                  = 508,
		LANG_ITEMLIST_MAIL                  = 509,
		LANG_ITEMLIST_AUCTION               = 510,

		LANG_WRONG_LINK_TYPE                = 511,
		LANG_ITEM_LIST_CHAT                 = 512,
		LANG_QUEST_LIST_CHAT                = 513,
		LANG_CREATURE_ENTRY_LIST_CHAT       = 514,
		LANG_CREATURE_LIST_CHAT             = 515,
		LANG_GO_ENTRY_LIST_CHAT             = 516,
		LANG_GO_LIST_CHAT                   = 517,
		LANG_ITEMSET_LIST_CHAT              = 518,
		LANG_TELE_LIST                      = 519,
		LANG_SPELL_LIST                     = 520,
		LANG_SKILL_LIST_CHAT                = 521,

		LANG_GAMEOBJECT_NOT_EXIST           = 522,

		LANG_GAMEOBJECT_CURRENT             = 523,              //log
		LANG_GAMEOBJECT_DETAIL              = 524,
		LANG_GAMEOBJECT_ADD                 = 525,

		LANG_MOVEGENS_LIST                  = 526,
		LANG_MOVEGENS_IDLE                  = 527,
		LANG_MOVEGENS_RANDOM                = 528,
		LANG_MOVEGENS_WAYPOINT              = 529,
		LANG_MOVEGENS_ANIMAL_RANDOM         = 530,
		LANG_MOVEGENS_CONFUSED              = 531,
		LANG_MOVEGENS_CHASE_PLAYER          = 532,
		LANG_MOVEGENS_CHASE_CREATURE        = 533,
		LANG_MOVEGENS_CHASE_NULL            = 534,
		LANG_MOVEGENS_HOME_CREATURE         = 535,
		LANG_MOVEGENS_HOME_PLAYER           = 536,
		LANG_MOVEGENS_FLIGHT                = 537,
		LANG_MOVEGENS_UNKNOWN               = 538,

		LANG_NPCINFO_CHAR                   = 539,
		LANG_NPCINFO_LEVEL                  = 540,
		LANG_NPCINFO_HEALTH                 = 541,
		LANG_NPCINFO_FLAGS                  = 542,
		LANG_NPCINFO_LOOT                   = 543,
		LANG_NPCINFO_POSITION               = 544,
		LANG_NPCINFO_VENDOR                 = 545,
		LANG_NPCINFO_TRAINER                = 546,
		LANG_NPCINFO_DUNGEON_ID             = 547,

		LANG_PINFO_ACCOUNT                  = 548,
		LANG_PINFO_LEVEL                    = 549,
		LANG_PINFO_MUTE                     = 550,
		LANG_PINFO_BAN                      = 453,
		LANG_PINFO_MAP_ONLINE               = 714,
		LANG_PINFO_MAP_OFFLINE              = 716,

		LANG_YOU_SET_EXPLORE_ALL            = 551,
		LANG_YOU_SET_EXPLORE_NOTHING        = 552,
		LANG_YOURS_EXPLORE_SET_ALL          = 553,
		LANG_YOURS_EXPLORE_SET_NOTHING      = 554,

		LANG_NPC_SETDATA                    = 555,

		//! Old ones now free:
		LANG_COMMAND_NEAR_NPC_MESSAGE       = 556,

		LANG_YOURS_LEVEL_UP                 = 557,
		LANG_YOURS_LEVEL_DOWN               = 558,
		LANG_YOURS_LEVEL_PROGRESS_RESET     = 559,
		LANG_EXPLORE_AREA                   = 560,
		LANG_UNEXPLORE_AREA                 = 561,

		LANG_UPDATE                         = 562,
		LANG_UPDATE_CHANGE                  = 563,
		LANG_TOO_BIG_INDEX                  = 564,
		LANG_SET_UINT                       = 565,              //log
		LANG_SET_UINT_FIELD                 = 566,
		LANG_SET_FLOAT                      = 567,              //log
		LANG_SET_FLOAT_FIELD                = 568,
		LANG_GET_UINT                       = 569,              //log
		LANG_GET_UINT_FIELD                 = 570,
		LANG_GET_FLOAT                      = 571,              //log
		LANG_GET_FLOAT_FIELD                = 572,
		LANG_SET_32BIT                      = 573,              //log
		LANG_SET_32BIT_FIELD                = 574,
		LANG_CHANGE_32BIT                   = 575,              //log
		LANG_CHANGE_32BIT_FIELD             = 576,

		LANG_INVISIBLE_INVISIBLE              = 577,
		LANG_INVISIBLE_VISIBLE                = 578,
		LANG_SELECTED_TARGET_NOT_HAVE_VICTIM  = 579,

		LANG_COMMAND_LEARN_ALL_DEFAULT_AND_QUEST = 580,
		LANG_COMMAND_NEAROBJMESSAGE         = 581,
		LANG_COMMAND_RAWPAWNTIMES           = 582,

		LANG_EVENT_ENTRY_LIST_CHAT          = 583,
		LANG_NOEVENTFOUND                   = 584,
		LANG_EVENT_NOT_EXIST                = 585,
		LANG_EVENT_INFO                     = 586,
		LANG_EVENT_ALREADY_ACTIVE           = 587,
		LANG_EVENT_NOT_ACTIVE               = 588,

		LANG_MOVEGENS_POINT                 = 589,
		LANG_MOVEGENS_FEAR                  = 590,
		LANG_MOVEGENS_DISTRACT              = 591,

		LANG_COMMAND_LEARN_ALL_RECIPES      = 592,
		LANG_BANLIST_ACCOUNTS               = 593,
		LANG_BANLIST_ACCOUNTS_HEADER        = 594,
		LANG_BANLIST_IPS                    = 595,
		LANG_BANLIST_IPS_HEADER             = 596,
		LANG_GMLIST                         = 597,
		LANG_GMLIST_HEADER                  = 598,
		LANG_GMLIST_EMPTY                   = 599,

		LANG_EVENT_STARTED                  = 600,
		LANG_EVENT_STOPPED                  = 601,

		LANG_REWARDED                       = 602,

		LANG_NPC_DO_ACTION                  = 603,

		// 603-704 - free

		LANG_WAIT_BEFORE_SPEAKING           = 705,
		LANG_NOT_EQUIPPED_ITEM              = 706,
		LANG_PLAYER_DND                     = 707,
		LANG_PLAYER_AFK                     = 708,
		LANG_PLAYER_DND_DEFAULT             = 709,
		LANG_PLAYER_AFK_DEFAULT             = 710,

		// BG announce
		LANG_BG_QUEUE_ANNOUNCE_SELF         = 711,
		LANG_BG_QUEUE_ANNOUNCE_WORLD        = 712,

		// Arena announce
		LANG_ARENA_QUEUE_ANNOUNCE_SELF      = 713,
		LANG_ARENA_QUEUE_ANNOUNCE_WORLD     = 726,

		//                                      = 714, see LANG_PINFO_MAP_ONLINE
		LANG_YOUR_BG_LEVEL_REQ_ERROR        = 715,
		//                                      = 716, see LANG_PINFO_MAP_OFFLINE
		LANG_BG_STARTED_ANNOUNCE_WORLD      = 717,
		LANG_ARENA_QUEUE_ANNOUNCE_WORLD_JOIN_NAME_RATING = 718,
		LANG_ARENA_QUEUE_ANNOUNCE_WORLD_EXIT_NAME_RATING = 719,

		LANG_BG_GROUP_TOO_LARGE             = 720,              // "Your group is too large for this battleground. Please regroup to join."
		LANG_ARENA_GROUP_TOO_LARGE          = 721,              // "Your group is too large for this arena. Please regroup to join."
		LANG_ARENA_YOUR_TEAM_ONLY           = 722,              // "Your group has members not in your arena team. Please regroup to join."
		LANG_ARENA_NOT_ENOUGH_PLAYERS       = 723,              // "Your group does not have enough players to join this match."
		// 724-726 - free
		LANG_BG_GROUP_OFFLINE_MEMBER        = 727,              // "Your group has an offline member. Please remove him before joining."
		LANG_BG_GROUP_MIXED_FACTION         = 728,              // "Your group has players from the opposing faction. You can't join the battleground as a group."
		LANG_BG_GROUP_MIXED_LEVELS          = 729,              // "Your group has players from different battleground brakets. You can't join as group."
		LANG_BG_GROUP_MEMBER_ALREADY_IN_QUEUE = 730,            // "Someone in your party is already in this battleground queue. (S)he must leave it before joining as group."
		LANG_BG_GROUP_MEMBER_DESERTER       = 731,              // "Someone in your party is Deserter. You can't join as group."
		LANG_BG_GROUP_MEMBER_NO_FREE_QUEUE_SLOTS = 732,         // "Someone in your party is already in three battleground queues. You cannot join as group."

		LANG_CANNOT_TELE_TO_BG              = 733,              // "You cannot teleport to a battleground or arena map."
		LANG_CANNOT_SUMMON_TO_BG            = 734,              // "You cannot summon players to a battleground or arena map."
		LANG_CANNOT_GO_TO_BG_GM             = 735,              // "You must be in GM mode to teleport to a player in a battleground."
		LANG_CANNOT_GO_TO_BG_FROM_BG        = 736,              // "You cannot teleport to a battleground from another battleground. Please leave the current battleground first."
		LANG_DEBUG_ARENA_ON                 = 737,
		LANG_DEBUG_ARENA_OFF                = 738,
		LANG_DEBUG_BG_ON                    = 739,
		LANG_DEBUG_BG_OFF                   = 740,
		LANG_DIST_ARENA_POINTS_START        = 741,
		LANG_DIST_ARENA_POINTS_ONLINE_START = 742,
		LANG_DIST_ARENA_POINTS_ONLINE_END   = 743,
		LANG_DIST_ARENA_POINTS_TEAM_START   = 744,
		LANG_DIST_ARENA_POINTS_TEAM_END     = 745,
		LANG_DIST_ARENA_POINTS_END          = 746,
		LANG_BG_DISABLED                    = 747,
		LANG_ARENA_DISABLED                 = 748,
		//                                      = 749, see LANG_PINFO_ACC_OS
		LANG_BATTLEGROUND_PREMATURE_FINISH_WARNING = 750,       // "Not enough players. This game will close in %u mins."
		LANG_BATTLEGROUND_PREMATURE_FINISH_WARNING_SECS = 751,  // "Not enough players. This game will close in %u seconds."
		//                                      = 752, see LANG_PINFO_ACC_IP

		// Room for BG/ARENA                = 779-784, 788-799 not used
		LANG_ARENA_QUEUE_ANNOUNCE_WORLD_JOIN_NAME = 773,
		LANG_ARENA_QUEUE_ANNOUNCE_WORLD_EXIT_NAME = 774,
		LANG_ARENA_QUEUE_ANNOUNCE_WORLD_JOIN_RATING = 775,
		LANG_ARENA_QUEUE_ANNOUNCE_WORLD_EXIT_RATING = 776,
		LANG_ARENA_QUEUE_ANNOUNCE_WORLD_JOIN = 777,
		LANG_ARENA_QUEUE_ANNOUNCE_WORLD_EXIT = 778,
		LANG_ARENA_TESTING                  = 785,
		LANG_AUTO_ANN                       = 786,
		LANG_ANNOUNCE_COLOR                 = 787,

		// in game strings
		LANG_PET_INVALID_NAME               = 800,
		LANG_NOT_ENOUGH_GOLD                = 801,
		LANG_NOT_FREE_TRADE_SLOTS           = 802,
		LANG_NOT_PARTNER_FREE_TRADE_SLOTS   = 803,
		LANG_PERMISSION_DENIED              = 804,  //  You do not have permission to perform this function.
		LANG_UNKNOWN_LANGUAGE               = 805,
		LANG_NOT_LEARNED_LANGUAGE           = 806,
		LANG_NEED_CHARACTER_NAME            = 807,
		LANG_PLAYER_NOT_EXIST_OR_OFFLINE    = 808,
		LANG_ACCOUNT_FOR_PLAYER_NOT_FOUND   = 809,
		// unused                           = 810,
		LANG_GUILD_MASTER                   = 811,
		LANG_GUILD_OFFICER                  = 812,
		LANG_GUILD_VETERAN                  = 813,
		LANG_GUILD_MEMBER                   = 814,
		LANG_GUILD_INITIATE                 = 815,
		LANG_ZONE_NOFLYZONE                 = 816,

		LANG_COMMAND_CREATURETEMPLATE_NOTFOUND = 817,
		LANG_COMMAND_CREATURESTORAGE_NOTFOUND  = 818,

		LANG_CHANNEL_CITY                   = 819,

		LANG_NPCINFO_GOSSIP                 = 820,
		LANG_NPCINFO_QUESTGIVER             = 821,
		LANG_NPCINFO_TRAINER_CLASS          = 822,
		LANG_NPCINFO_TRAINER_PROFESSION     = 823,
		LANG_NPCINFO_VENDOR_AMMO            = 824,
		LANG_NPCINFO_VENDOR_FOOD            = 825,
		LANG_NPCINFO_VENDOR_POISON          = 826,
		LANG_NPCINFO_VENDOR_REAGENT         = 827,
		LANG_NPCINFO_REPAIR                 = 828,
		LANG_NPCINFO_FLIGHTMASTER           = 829,
		LANG_NPCINFO_SPIRITHEALER           = 830,
		LANG_NPCINFO_SPIRITGUIDE            = 831,
		LANG_NPCINFO_INNKEEPER              = 832,
		LANG_NPCINFO_BANKER                 = 833,
		LANG_NPCINFO_PETITIONER             = 834,
		LANG_NPCINFO_TABARDDESIGNER         = 835,
		LANG_NPCINFO_BATTLEMASTER           = 836,
		LANG_NPCINFO_AUCTIONEER             = 837,
		LANG_NPCINFO_STABLEMASTER           = 838,
		LANG_NPCINFO_GUILD_BANKER           = 839,
		LANG_NPCINFO_SPELLCLICK             = 840,
		LANG_NPCINFO_MAILBOX                = 841,
		LANG_NPCINFO_PLAYER_VEHICLE         = 842,

		// Pinfo commands
		LANG_PINFO_PLAYER                   = 35400,
		LANG_PINFO_GM_ACTIVE                = 35401,
		LANG_PINFO_BANNED                   = 35402,
		LANG_PINFO_MUTED                    = 35403,
		LANG_PINFO_ACC_ACCOUNT              = 35404,
		LANG_PINFO_ACC_LASTLOGIN            = 35405,
		LANG_PINFO_ACC_OS                   = 749,
		LANG_PINFO_ACC_REGMAILS             = 35406,
		LANG_PINFO_ACC_IP                   = 752,
		LANG_PINFO_CHR_LEVEL_LOW            = 843,
		LANG_PINFO_CHR_RACE                 = 844,
		LANG_PINFO_CHR_ALIVE                = 845,
		LANG_PINFO_CHR_PHASE                = 846,
		LANG_PINFO_CHR_MONEY                = 847,
		LANG_PINFO_CHR_MAP                  = 848,
		LANG_PINFO_CHR_GUILD                = 849,
		LANG_PINFO_CHR_GUILD_RANK           = 850,
		LANG_PINFO_CHR_GUILD_NOTE           = 851,
		LANG_PINFO_CHR_GUILD_ONOTE          = 852,
		LANG_PINFO_CHR_PLAYEDTIME           = 853,
		LANG_PINFO_CHR_MAILS                = 854,
		LANG_PINFO_CHR_LEVEL_HIGH           = 871,
		LANG_NO_REASON                      = 35407,
		LANG_UNAUTHORIZED                   = 35408,
		LANG_PINFO_CHR_MAP_WITH_AREA        = 35409,
		LANG_PINFO_CHR_ONLINETIME           = 35410,

		LANG_CHARACTER_GENDER_MALE          = 855,
		LANG_CHARACTER_GENDER_FEMALE        = 856,

		LANG_ARENA_ERROR_NOT_FOUND          = 857,
		LANG_ARENA_ERROR_NAME_EXISTS        = 858,
		LANG_ARENA_ERROR_SIZE               = 859,
		LANG_ARENA_ERROR_COMBAT             = 860,
		LANG_ARENA_ERROR_NAME_NOT_FOUND     = 861,
		LANG_ARENA_ERROR_NOT_MEMBER         = 862,
		LANG_ARENA_ERROR_CAPTAIN            = 863,
		LANG_ARENA_CREATE                   = 864,
		LANG_ARENA_DISBAND                  = 865,
		LANG_ARENA_RENAME                   = 866,
		LANG_ARENA_CAPTAIN                  = 867,
		LANG_ARENA_INFO_HEADER              = 868,
		LANG_ARENA_INFO_MEMBERS             = 869,
		LANG_ARENA_LOOKUP                   = 870,
		//                                  = 871, see LANG_PINFO_CHR_LEVEL_HIGH
		LANG_COMMAND_WRONGEMAIL             = 872,
		LANG_NEW_EMAILS_NOT_MATCH           = 873,
		LANG_COMMAND_EMAIL                  = 874,
		LANG_EMAIL_TOO_LONG                 = 875,
		LANG_COMMAND_NOTCHANGEEMAIL         = 876,
		LANG_OLD_EMAIL_IS_NEW_EMAIL         = 877,
		LANG_COMMAND_EMAIL_OUTPUT           = 878,
		//                                  = 879, see LANG_PINFO_CHR_REGMAILS
		LANG_ACCOUNT_SEC_TYPE               = 880,
		LANG_RBAC_EMAIL_REQUIRED            = 881,
		// Room for in-game strings           882-999 not used

		//Access Requirements
		LANG_ACCESS_REQUIREMENT_COMPLETE_QUESTS = 882,
		LANG_ACCESS_REQUIREMENT_COMPLETE_ACHIEVEMENTS = 883,
		LANG_ACCESS_REQUIREMENT_OBTAIN_ITEMS = 884,
		LANG_ACCESS_REQUIREMENT_NOTE = 885,
		LANG_ACCESS_REQUIREMENT_NOT_MET = 886,
		LANG_ACCESS_REQUIREMENT_AVERAGE_ILVL_NOT_MET = 887,
		LANG_ACCESS_REQUIREMENT_MAX_LEVEL = 888,
		LANG_ACCESS_REQUIREMENT_LEADER_COMPLETE_QUESTS = 889,
		LANG_ACCESS_REQUIREMENT_LEADER_COMPLETE_ACHIEVEMENTS = 890,
		LANG_ACCESS_REQUIREMENT_LEADER_OBTAIN_ITEMS = 891,
		// End Level 3 list, continued at 1100

		// Level 4 (CLI only commands)
		LANG_COMMAND_EXIT                   = 1000,
		LANG_ACCOUNT_DELETED                = 1001,
		LANG_ACCOUNT_NOT_DELETED_SQL_ERROR  = 1002,
		LANG_ACCOUNT_NOT_DELETED            = 1003,
		LANG_ACCOUNT_CREATED                = 1004,
		LANG_ACCOUNT_TOO_LONG               = 1005,
		LANG_ACCOUNT_ALREADY_EXIST          = 1006,
		LANG_ACCOUNT_NOT_CREATED_SQL_ERROR  = 1007,
		LANG_ACCOUNT_NOT_CREATED            = 1008,
		LANG_CHARACTER_DELETED              = 1009,
		LANG_ACCOUNT_LIST_HEADER            = 1010,
		LANG_ACCOUNT_LIST_ERROR             = 1011,
		LANG_ACCOUNT_LIST_BAR               = 1012,
		LANG_ACCOUNT_LIST_LINE              = 1013,
		LANG_ACCOUNT_LIST_EMPTY             = 1014,
		LANG_ACCOUNT_LIST_BAR_HEADER        = 1015,
		LANG_CHARACTER_DELETED_LIST_HEADER  = 1016,
		LANG_CHARACTER_DELETED_LIST_LINE_CONSOLE = 1017,
		LANG_CHARACTER_DELETED_LIST_BAR     = 1018,
		LANG_CHARACTER_DELETED_LIST_EMPTY   = 1019,
		LANG_CHARACTER_DELETED_RESTORE      = 1020,
		LANG_CHARACTER_DELETED_DELETE       = 1021,
		LANG_CHARACTER_DELETED_ERR_RENAME   = 1022,
		LANG_CHARACTER_DELETED_SKIP_ACCOUNT = 1023,
		LANG_CHARACTER_DELETED_SKIP_FULL    = 1024,
		LANG_CHARACTER_DELETED_SKIP_NAME    = 1025,
		LANG_CHARACTER_DELETED_LIST_LINE_CHAT = 1026,
		LANG_SQLDRIVER_QUERY_LOGGING_ENABLED  = 1027,
		LANG_SQLDRIVER_QUERY_LOGGING_DISABLED = 1028,
		// 1029-1030 used in other client versions
		// Room for more level 4              1031-1099 not used
		LANG_ACCOUNT_PASS_TOO_LONG            = 1031,

		// Level 3 (continue)
		LANG_ACCOUNT_SETADDON               = 1100,
		LANG_MOTD_NEW                       = 1101,
		LANG_SENDMESSAGE                    = 1102,
		LANG_EVENT_ENTRY_LIST_CONSOLE       = 1103,
		LANG_CREATURE_ENTRY_LIST_CONSOLE    = 1104,
		LANG_ITEM_LIST_CONSOLE              = 1105,
		LANG_ITEMSET_LIST_CONSOLE           = 1106,
		LANG_GO_ENTRY_LIST_CONSOLE          = 1107,
		LANG_QUEST_LIST_CONSOLE             = 1108,
		LANG_SKILL_LIST_CONSOLE             = 1109,
		LANG_CREATURE_LIST_CONSOLE          = 1110,
		LANG_GO_LIST_CONSOLE                = 1111,
		LANG_FILE_OPEN_FAIL                 = 1112,
		LANG_ACCOUNT_CHARACTER_LIST_FULL    = 1113,
		LANG_DUMP_BROKEN                    = 1114,
		LANG_INVALID_CHARACTER_NAME         = 1115,
		LANG_INVALID_CHARACTER_GUID         = 1116,
		LANG_CHARACTER_GUID_IN_USE          = 1117,
		LANG_ITEMLIST_GUILD                 = 1118,
		LANG_MUST_MALE_OR_FEMALE            = 1119,
		LANG_YOU_CHANGE_GENDER              = 1120,
		LANG_YOUR_GENDER_CHANGED            = 1121,
		LANG_SKILL_VALUES                   = 1122,
		LANG_NO_PET_FOUND                   = 1123,
		LANG_WRONG_PET_TYPE                 = 1124,
		LANG_COMMAND_LEARN_PET_TALENTS      = 1125,
		LANG_RESET_PET_TALENTS              = 1126,
		LANG_RESET_PET_TALENTS_ONLINE       = 1127,
		LANG_TAXINODE_ENTRY_LIST_CHAT       = 1128,
		LANG_TAXINODE_ENTRY_LIST_CONSOLE    = 1129,
		LANG_COMMAND_EXPORT_DELETED_CHAR    = 1130,
		LANG_BANLIST_MATCHINGCHARACTER      = 1131,
		LANG_BANLIST_CHARACTERS             = 1132,
		LANG_BANLIST_CHARACTERS_HEADER      = 1133,
		LANG_ALLOW_TICKETS                  = 1134,
		LANG_DISALLOW_TICKETS               = 1135,
		LANG_CHAR_NOT_BANNED                = 1136,
		LANG_DEV_ON                         = 1137,
		LANG_DEV_OFF                        = 1138,
		LANG_MOVEGENS_FOLLOW_PLAYER         = 1139,
		LANG_MOVEGENS_FOLLOW_CREATURE       = 1140,
		LANG_MOVEGENS_FOLLOW_NULL           = 1141,
		LANG_MOVEGENS_EFFECT                = 1142,
		LANG_MOVEFLAGS_GET                  = 1143,
		LANG_MOVEFLAGS_SET                  = 1144,
		LANG_GROUP_ALREADY_IN_GROUP         = 1145,
		LANG_GROUP_PLAYER_JOINED            = 1146,
		LANG_GROUP_NOT_IN_GROUP             = 1147,
		LANG_GROUP_FULL                     = 1148,
		LANG_GROUP_TYPE                     = 1149,
		LANG_GROUP_PLAYER_NAME_GUID         = 1150,
		LANG_LIST_MAIL_HEADER               = 1151,
		LANG_LIST_MAIL_INFO_1               = 1152,
		LANG_LIST_MAIL_INFO_2               = 1153,
		LANG_LIST_MAIL_INFO_3               = 1154,
		LANG_LIST_MAIL_INFO_ITEM            = 1155,
		LANG_LIST_MAIL_NOT_FOUND            = 1156,
		LANG_AHBOT_RELOAD_OK                = 1157,
		LANG_AHBOT_STATUS_BAR_CONSOLE       = 1158,
		LANG_AHBOT_STATUS_MIDBAR_CONSOLE    = 1159,
		LANG_AHBOT_STATUS_TITLE1_CONSOLE    = 1160,
		LANG_AHBOT_STATUS_TITLE1_CHAT       = 1161,
		LANG_AHBOT_STATUS_FORMAT_CONSOLE    = 1162,
		LANG_AHBOT_STATUS_FORMAT_CHAT       = 1163,
		LANG_AHBOT_STATUS_ITEM_COUNT        = 1164,
		LANG_AHBOT_STATUS_ITEM_RATIO        = 1165,
		LANG_AHBOT_STATUS_TITLE2_CONSOLE    = 1166,
		LANG_AHBOT_STATUS_TITLE2_CHAT       = 1167,
		LANG_AHBOT_QUALITY_GRAY             = 1168,
		LANG_AHBOT_QUALITY_WHITE            = 1169,
		LANG_AHBOT_QUALITY_GREEN            = 1170,
		LANG_AHBOT_QUALITY_BLUE             = 1171,
		LANG_AHBOT_QUALITY_PURPLE           = 1172,
		LANG_AHBOT_QUALITY_ORANGE           = 1173,
		LANG_AHBOT_QUALITY_YELLOW           = 1174,
		LANG_AHBOT_ITEMS_AMOUNT             = 1175,
		LANG_AHBOT_ITEMS_RATIO              = 1176,
		LANG_GUILD_INFO_NAME                = 1177,
		LANG_GUILD_INFO_GUILD_MASTER        = 1178,
		LANG_GUILD_INFO_CREATION_DATE       = 1179,
		LANG_GUILD_INFO_MEMBER_COUNT        = 1180,
		LANG_GUILD_INFO_BANK_GOLD           = 1181,
		LANG_GUILD_INFO_MOTD                = 1182,
		LANG_GUILD_INFO_EXTRA_INFO          = 1183,
		LANG_GUILD_INFO_RANKS               = 1184,
		LANG_GUILD_INFO_RANKS_LIST          = 1185,
		LANG_COMMAND_BEASTMASTER_MODE       = 1186,
		// Room for more level 3              1187-1198 not used

		// Debug commands
		LANG_DO_NOT_USE_6X_DEBUG_AREATRIGGER_LEFT = 1999,
		LANG_CINEMATIC_NOT_EXIST            = 1200,
		LANG_MOVIE_NOT_EXIST                = 1201,
		LANG_DEBUG_AREATRIGGER_ON           = 1202,
		LANG_DEBUG_AREATRIGGER_OFF          = 1203,
		LANG_DEBUG_AREATRIGGER_REACHED      = 1204,

		// 1205-1333 - free

		//Player Ticket Strings
		LANG_TICKET_CLOSED                  = 1334,
		LANG_TICKET_COMPLETED               = 1335,
		// FREE IDS                           1336-1499

		// Command argument parsers
		LANG_CMDPARSER_EITHER                 = 1500,
		LANG_CMDPARSER_OR                     = 1501,
		LANG_CMDPARSER_STRING_VALUE_INVALID   = 1502,
		LANG_CMDPARSER_INVALID_UTF8           = 1503,
		LANG_CMDPARSER_LINKDATA_INVALID       = 1504,
		LANG_CMDPARSER_ACCOUNT_NAME_NO_EXIST  = 1505,
		LANG_CMDPARSER_ACCOUNT_ID_NO_EXIST    = 1506,
		LANG_CMDPARSER_CHAR_GUID_NO_EXIST     = 1507,
		LANG_CMDPARSER_CHAR_NAME_NO_EXIST     = 1508,
		LANG_CMDPARSER_CHAR_NAME_INVALID      = 1509,
		LANG_CMDPARSER_ACHIEVEMENT_NO_EXIST   = 1510,
		LANG_CMDPARSER_GAME_TELE_ID_NO_EXIST  = 1511,
		LANG_CMDPARSER_GAME_TELE_NO_EXIST     = 1512,
		LANG_CMDPARSER_ITEM_NO_EXIST          = 1513,
		LANG_CMDPARSER_SPELL_NO_EXIST         = 1514,
		LANG_CMDPARSER_EXACT_SEQ_MISMATCH     = 1515,
		LANG_CMDPARSER_QUEST_NO_EXIST         = 1516,
		// FREE IDS                             1517-1499

		// Ticket Strings 2000-2030
		LANG_COMMAND_TICKETNEW              = 2000,
		LANG_COMMAND_TICKETUPDATED          = 2001,
		LANG_COMMAND_TICKETPLAYERABANDON    = 2002,
		LANG_COMMAND_TICKETCLOSED           = 2003,
		LANG_COMMAND_TICKETDELETED          = 2004,
		LANG_COMMAND_TICKETNOTEXIST         = 2005,
		LANG_COMMAND_TICKETCLOSEFIRST       = 2006,
		LANG_COMMAND_TICKETALREADYASSIGNED  = 2007,
		LANG_COMMAND_TICKETRELOAD           = 2008,
		LANG_COMMAND_TICKETSHOWLIST         = 2009,
		LANG_COMMAND_TICKETSHOWONLINELIST   = 2010,
		LANG_COMMAND_TICKETSHOWCLOSEDLIST   = 2011,
		LANG_COMMAND_TICKETASSIGNERROR_A    = 2012,
		LANG_COMMAND_TICKETASSIGNERROR_B    = 2013,
		LANG_COMMAND_TICKETNOTASSIGNED      = 2014,
		LANG_COMMAND_TICKETUNASSIGNSECURITY = 2015,
		LANG_COMMAND_TICKETCANNOTCLOSE      = 2016,
		LANG_COMMAND_TICKETLISTGUID         = 2017,
		LANG_COMMAND_TICKETLISTNAME         = 2018,
		LANG_COMMAND_TICKETLISTAGE          = 2019,
		LANG_COMMAND_TICKETLISTASSIGNEDTO   = 2020,
		LANG_COMMAND_TICKETLISTUNASSIGNED   = 2021,
		LANG_COMMAND_TICKETLISTMESSAGE      = 2022,
		LANG_COMMAND_TICKETLISTCOMMENT      = 2023,
		LANG_COMMAND_TICKETLISTADDCOMMENT   = 2024,
		LANG_COMMAND_TICKETLISTAGECREATE    = 2025,
		LANG_COMMAND_TICKETSHOWESCALATEDLIST = 2026,
		LANG_COMMAND_TICKETPENDING          = 2027,
		LANG_COMMAND_TICKETRESET            = 2028,
		LANG_COMMAND_TICKETLISTRESPONSE     = 2029,
		LANG_COMMAND_TICKETCOMPLETED        = 2030,
		LANG_COMMAND_TICKETRESPONSEAPPENDED = 2031,
		LANG_COMMAND_TICKETRESPONSEDELETED  = 2032,

		// acore strings                    5000-9999
		LANG_COMMAND_FREEZE                 = 5000,
		LANG_COMMAND_FREEZE_ERROR           = 5001,
		LANG_COMMAND_FREEZE_WRONG           = 5002,
		LANG_COMMAND_UNFREEZE               = 5003,
		LANG_COMMAND_NO_FROZEN_PLAYERS      = 5004,
		LANG_COMMAND_LIST_FREEZE            = 5005,
		LANG_COMMAND_FROZEN_PLAYERS         = 5006,
		LANG_INSTANCE_RAID_GROUP_ONLY       = 5007,
		LANG_INSTANCE_CLOSED                = 5008,
		LANG_COMMAND_PLAYED_TO_ALL          = 5009,
		LANG_NPCINFO_LINKGUID               = 5010,
		LANG_TELEPORTED_TO_BY_CONSOLE       = 5011,
		// for command lookup map
		LANG_COMMAND_NOMAPFOUND             = 5012,
		LANG_CONTINENT                      = 5013,
		LANG_INSTANCE                       = 5014,
		LANG_BATTLEGROUND                   = 5015,
		LANG_ARENA                          = 5016,
		LANG_RAID                           = 5017,
		// unused                           = 5018,
		LANG_COMMAND_TEMP_FROZEN_PLAYER     = 5019,
		LANG_NPCINFO_PHASEMASK              = 5020,
		LANG_NPCINFO_ARMOR                  = 5021,
		LANG_CHANNEL_ENABLE_OWNERSHIP       = 5022,
		LANG_CHANNEL_DISABLE_OWNERSHIP      = 5023,
		LANG_GOINFO_ENTRY                   = 5024,
		LANG_GOINFO_TYPE                    = 5025,
		LANG_GOINFO_DISPLAYID               = 5026,
		LANG_GOINFO_NAME                    = 5027,
		LANG_GOINFO_LOOTID                  = 5028,
		LANG_COMMAND_LOOKUP_MAX_RESULTS     = 5029,
		// unused                           = 5030,
		LANG_NPCINFO_AIINFO                 = 5031,
		LANG_COMMAND_NO_BATTLEGROUND_FOUND  = 5032,
		LANG_COMMAND_NO_ACHIEVEMENT_CRITERIA_FOUND = 5033,
		LANG_COMMAND_NO_OUTDOOR_PVP_FORUND  = 5034,
		// unused                           = 5035,
		LANG_NPCINFO_EQUIPMENT              = 5036,
		LANG_NPCINFO_MECHANIC_IMMUNE        = 5037,
		LANG_NPCINFO_UNIT_FIELD_FLAGS       = 5038,
		LANG_CONSOLE                        = 5039,
		LANG_CHARACTER                      = 5040,
		LANG_PERMANENTLY                    = 5041,
		LANG_GPS_POSITION_OUTDOORS          = 5042,
		LANG_GPS_POSITION_INDOORS           = 5043,
		LANG_GPS_NO_VMAP                    = 5044,

		// Instance commands
		LANG_COMMAND_LIST_BIND_INFO         = 5045,
		LANG_COMMAND_LIST_BIND_PLAYER_BINDS = 5046,
		LANG_COMMAND_LIST_BIND_GROUP_BINDS  = 5047,
		LANG_COMMAND_INST_UNBIND_UNBINDING  = 5048,
		LANG_COMMAND_INST_UNBIND_UNBOUND    = 5049,
		LANG_COMMAND_INST_STAT_LOADED_INST  = 5050,
		LANG_COMMAND_INST_STAT_PLAYERS_IN   = 5051,
		LANG_COMMAND_INST_STAT_SAVES        = 5052,
		LANG_COMMAND_INST_STAT_PLAYERSBOUND = 5053,
		LANG_COMMAND_INST_STAT_GROUPSBOUND  = 5054,
		LANG_NOT_DUNGEON                    = 5055, // Map is not a dungeon.
		LANG_NO_INSTANCE_DATA               = 5056, // Map has no instance data.
		LANG_COMMAND_INST_SET_BOSS_STATE    = 5057,
		LANG_COMMAND_INST_GET_BOSS_STATE    = 5058,

		// Mutehistory commands
		LANG_COMMAND_MUTEHISTORY            = 5059,
		LANG_COMMAND_MUTEHISTORY_EMPTY      = 5060,
		LANG_COMMAND_MUTEHISTORY_OUTPUT     = 5061,

		LANG_NPCINFO_SPELL_SCHOOL_IMMUNE    = 5062,

		LANG_COMMAND_CACHE_INFO             = 5063,
		LANG_COMMAND_CACHE_DELETE           = 5064,
		LANG_COMMAND_CACHE_REFRESH          = 5065,
		LANG_COMMAND_CACHE_NOT_FOUND        = 5066,

		LANG_COMMAND_QUEST_ADD              = 5067,
		LANG_COMMAND_QUEST_NOT_FOUND_IN_LOG = 5068,
		LANG_COMMAND_QUEST_NOT_COMPLETE     = 5069,

		LANG_COMMAND_DISABLED               = 5070,

		LANG_CMD_ITEM_REFUND_BAD_EXTENDED_COST = 5071,
		LANG_CMD_ITEM_REFUND_MAX_HONOR         = 5072,
		LANG_CMD_ITEM_REFUND_HONOR_FAILED      = 5073,
		LANG_CMD_ITEM_REFUNDED_HONOR           = 5074,
		LANG_CMD_ITEM_REFUND_MAX_AP            = 5075,
		LANG_CMD_ITEM_REFUND_AP_FAILED         = 5076,
		LANG_CMD_ITEM_REFUNDED_AP              = 5077,
		LANG_CMD_ITEM_REFUND_NOT_FOUND         = 5078,

		LANG_CMD_AUTOBROADCAST_LVL_ERROR    = 5079,
		LANG_CMD_SETTINGS_ANNOUNCER_ON      = 5080,
		LANG_CMD_SETTINGS_ANNOUNCER_OFF     = 5081,

		LANG_CMD_GOQUEST_INVALID_SYNTAX     = 5082,

		LANG_CMD_CHAR_CHANGE_ACC_SUCCESS    = 5083,

		LANG_CMD_CAST_ERROR_CODE            = 5084,

		LANG_CMD_GO_RESPAWN                 = 5085,

		LANG_CMD_NO_DOOR_FOUND              = 5086,
		LANG_CMD_DOOR_OPENED                = 5087,

		LANG_CMD_QUEST_STATUS               = 5088,
		LANG_CMD_QUEST_UNAVAILABLE          = 5089,
		LANG_CMD_QUEST_STATUS_DISABLED      = 5090,
		LANG_CMD_QUEST_STATUS_ALREADY_DONE  = 5091,
		LANG_CMD_QUEST_STATUS_CLASS         = 5092,
		LANG_CMD_QUEST_STATUS_RACE          = 5093,
		LANG_CMD_QUEST_STATUS_LOW_LEVEL     = 5094,
		LANG_CMD_QUEST_STATUS_HIGH_LEVEL    = 5095,
		LANG_CMD_QUEST_STATUS_SKILL         = 5096,
		LANG_CMD_QUEST_STATUS_REPUTATION    = 5097,
		LANG_CMD_QUEST_STATUS_PREV_QUEST    = 5098,
		LANG_CMD_QUEST_STATUS_TIMED         = 5099,
		LANG_CMD_QUEST_STATUS_EXCLUSIVE     = 5100,
		LANG_CMD_QUEST_STATUS_NEXT_CHAIN    = 5101,
		LANG_CMD_QUEST_STATUS_PREV_CHAIN    = 5102,
		LANG_CMD_QUEST_STATUS_BREADCRUMB    = 5103,
		LANG_CMD_QUEST_STATUS_DAY           = 5104,
		LANG_CMD_QUEST_STATUS_WEEK          = 5105,
		LANG_CMD_QUEST_STATUS_MONTH         = 5106,
		LANG_CMD_QUEST_STATUS_SEASONAL      = 5107,
		LANG_CMD_QUEST_STATUS_CONDITION     = 5108,
		LANG_CMD_QUEST_STATUS_LOG_FULL      = 5109,
		LANG_CMD_QUEST_STATUS_COND_DETAIL   = 5110,

		// Battlefield commands
		LANG_BF_NOT_FOUND                   = 5111,
		LANG_BF_STARTED                     = 5112,
		LANG_BF_STOPPED                     = 5113,
		LANG_BF_SWITCHED                    = 5114,
		LANG_BF_TIMER_SET                   = 5115,
		LANG_BF_ENABLED                     = 5116,
		LANG_BF_DISABLED                    = 5117,

		LANG_RESETALL_HONOR                 = 5118,
		LANG_RESETALL_ARENA                 = 5119,

		// Battlefield queue display (.bf queue)
		LANG_BF_QUEUE_HDR_WAR               = 5120,
		LANG_BF_QUEUE_HDR_WAIT              = 5121,
		LANG_BF_QUEUE_TEAM_HDR              = 5122,
		LANG_BF_QUEUE_PLAYER_QUEUE          = 5123,
		LANG_BF_QUEUE_PLAYER_INVITED        = 5124,
		LANG_BF_QUEUE_PLAYER_WAR            = 5125,

		// Autobroadcast commands
		LANG_AUTOBROADCAST_LIST_HEADER      = 5126,
		LANG_AUTOBROADCAST_LIST_ENTRY       = 5127,
		LANG_AUTOBROADCAST_LIST_EMPTY       = 5128,
		LANG_AUTOBROADCAST_ADD_SUCCESS      = 5129,
		LANG_AUTOBROADCAST_REMOVE_SUCCESS   = 5130,
		LANG_AUTOBROADCAST_NOT_FOUND        = 5131,
		LANG_AUTOBROADCAST_LOCALE_SUCCESS   = 5132,
		LANG_AUTOBROADCAST_LOCALE_ENTRY     = 5133,
		LANG_AUTOBROADCAST_INVALID_LOCALE   = 5134,

		// Mail commands
		LANG_MAIL_LIST_HEADER               = 5135,
		LANG_MAIL_LIST_ENTRY                = 5136,
		LANG_MAIL_LIST_EMPTY                = 5137,
		LANG_MAIL_RETURN_SUCCESS            = 5138,
		LANG_MAIL_RETURN_NOT_FOUND          = 5139,
		LANG_MAIL_RETURN_NOT_NORMAL         = 5140,
		LANG_MAIL_RETURN_NO_SENDER          = 5141,
		LANG_MAIL_RETURN_ALREADY_RETURNED   = 5142,
		LANG_MAIL_RETURN_HOOK_BLOCKED       = 5143,

		// Chat filter
		LANG_CHATFILTER_EMOTE               = 5144,
		LANG_CHATFILTER_SAY                 = 5145,
		LANG_CHATFILTER_YELL                = 5146,

		// Room for more strings    5147-9999

		// Level requirement notifications
		LANG_SAY_REQ                        = 6604,
		LANG_WHISPER_REQ                    = 6605,
		LANG_CHANNEL_REQ                    = 6606,
		LANG_AUCTION_REQ                    = 6607,
		LANG_TICKET_REQ                     = 6608,
		LANG_TRADE_REQ                      = 6609,
		LANG_TRADE_OTHER_REQ                = 6610,
		LANG_MAIL_SENDER_REQ                = 6611,
		LANG_MAIL_RECEIVER_REQ              = 6612,

		// Used for GM Announcements
		LANG_GM_BROADCAST                    = 6613,
		LANG_GM_NOTIFY                       = 6614,
		LANG_GM_ANNOUNCE_COLOR               = 6615,

		LANG_GM_SILENCE                      = 6616,              // "Silence is ON for %s" - Spell 1852
		LANG_GM_SPECTATOR_ON                 = 6617,
		LANG_GM_SPECTATOR_OFF                = 6618,

		// Free strings 6619-7522

		LANG_WORLD_CLOSED                    = 7523,
		LANG_WORLD_OPENED                    = 7524,

		LANG_LFG_PLAYER_INFO                = 9980,
		LANG_LFG_GROUP_INFO                 = 9981,
		LANG_LFG_NOT_IN_GROUP               = 9982,
		LANG_LFG_CLEAN                      = 9983,
		LANG_LFG_OPTIONS                    = 9984,
		LANG_LFG_OPTIONS_CHANGED            = 9985,
		LANG_LFG_STATE_NONE                 = 9986,
		LANG_LFG_STATE_ROLECHECK            = 9987,
		LANG_LFG_STATE_QUEUED               = 9988,
		LANG_LFG_STATE_PROPOSAL             = 9989,
		LANG_LFG_STATE_BOOT                 = 9990,
		LANG_LFG_STATE_DUNGEON              = 9991,
		LANG_LFG_STATE_FINISHED_DUNGEON     = 9992,
		LANG_LFG_STATE_RAIDBROWSER          = 9993,
		LANG_LFG_ROLE_TANK                  = 9994,
		LANG_LFG_ROLE_HEALER                = 9995,
		LANG_LFG_ROLE_DAMAGE                = 9996,
		LANG_LFG_ROLE_LEADER                = 9997,
		LANG_LFG_ROLE_NONE                  = 9998,
		LANG_LFG_ERROR                      = 9999,

		// Use for not-in-offcial-sources patches
		//                                    10000-10999
		// opvp hp
		LANG_OPVP_HP_CAPTURE_OVERLOOK_H     = 10001,
		LANG_OPVP_HP_CAPTURE_OVERLOOK_A     = 10002,
		LANG_OPVP_HP_CAPTURE_STADIUM_H      = 10003,
		LANG_OPVP_HP_CAPTURE_STADIUM_A      = 10004,
		LANG_OPVP_HP_CAPTURE_BROKENHILL_H   = 10005,
		LANG_OPVP_HP_CAPTURE_BROKENHILL_A   = 10006,
		LANG_OPVP_HP_LOSE_OVERLOOK_H       = 10007,
		LANG_OPVP_HP_LOSE_OVERLOOK_A       = 10008,
		LANG_OPVP_HP_LOSE_STADIUM_H        = 10009,
		LANG_OPVP_HP_LOSE_STADIUM_A        = 10010,
		LANG_OPVP_HP_LOSE_BROKENHILL_H     = 10011,
		LANG_OPVP_HP_LOSE_BROKENHILL_A     = 10012,
		// opvp zm
		LANG_OPVP_ZM_CAPTURE_WEST_H         = 10013,
		LANG_OPVP_ZM_CAPTURE_WEST_A         = 10014,
		LANG_OPVP_ZM_CAPTURE_EAST_H         = 10015,
		LANG_OPVP_ZM_CAPTURE_EAST_A         = 10016,
		LANG_OPVP_ZM_CAPTURE_GY_H           = 10017,
		LANG_OPVP_ZM_CAPTURE_GY_A           = 10018,
		LANG_OPVP_ZM_LOSE_WEST_H           = 10019,
		LANG_OPVP_ZM_LOSE_WEST_A           = 10020,
		LANG_OPVP_ZM_LOSE_EAST_H           = 10021,
		LANG_OPVP_ZM_LOSE_EAST_A           = 10022,
		LANG_OPVP_ZM_LOSE_GY_H             = 10023,
		LANG_OPVP_ZM_LOSE_GY_A             = 10024,
		// opvp na
		LANG_OPVP_NA_CAPTURE_H              = 10025,
		LANG_OPVP_NA_CAPTURE_A              = 10026,
		LANG_OPVP_NA_LOSE_H                = 10027,
		LANG_OPVP_NA_LOSE_A                = 10028,
		LANG_OPVP_NA_DEFENSELESS           = 10074,
		// opvp tf
		LANG_OPVP_TF_CAPTURE_H              = 10029,
		LANG_OPVP_TF_CAPTURE_A              = 10030,
		LANG_OPVP_TF_LOSE_H                = 10031,
		LANG_OPVP_TF_LOSE_A                = 10032,
		// opvp ep
		LANG_OPVP_EP_CAPTURE_NPT_H          = 10033,
		LANG_OPVP_EP_CAPTURE_NPT_A          = 10034,
		LANG_OPVP_EP_CAPTURE_EWT_H          = 10035,
		LANG_OPVP_EP_CAPTURE_EWT_A          = 10036,
		LANG_OPVP_EP_CAPTURE_CGT_H          = 10037,
		LANG_OPVP_EP_CAPTURE_CGT_A          = 10038,
		LANG_OPVP_EP_CAPTURE_PWT_H          = 10039,
		LANG_OPVP_EP_CAPTURE_PWT_A          = 10040,
		LANG_OPVP_EP_LOSE_NPT_H            = 10041,
		LANG_OPVP_EP_LOSE_NPT_A            = 10042,
		LANG_OPVP_EP_LOSE_EWT_H            = 10043,
		LANG_OPVP_EP_LOSE_EWT_A            = 10044,
		LANG_OPVP_EP_LOSE_CGT_H            = 10045,
		LANG_OPVP_EP_LOSE_CGT_A            = 10046,
		LANG_OPVP_EP_LOSE_PWT_H            = 10047,
		LANG_OPVP_EP_LOSE_PWT_A            = 10048,
		// opvp si
		LANG_OPVP_SI_CAPTURE_H              = 10049,
		LANG_OPVP_SI_CAPTURE_A              = 10050,
		// opvp gossips
		LANG_OPVP_EP_FLIGHT_NPT             = 10051,
		LANG_OPVP_EP_FLIGHT_EWT             = 10052,
		LANG_OPVP_EP_FLIGHT_CGT             = 10053,
		LANG_OPVP_ZM_GOSSIP_ALLIANCE        = 10054,
		LANG_OPVP_ZM_GOSSIP_HORDE           = 10055,

		LANG_BG_SA_START_TWO_MINUTES            = 10056,
		LANG_BG_SA_START_ONE_MINUTE             = 10057,
		LANG_BG_SA_START_HALF_MINUTE            = 10058,
		LANG_BG_SA_HAS_BEGUN                    = 10059,
		LANG_BG_SA_IS_UNDER_ATTACK              = 10060, //The %s is under attack!
		LANG_BG_SA_WAS_DESTROYED                = 10061, //The %s was destroyed!
		LANG_BG_SA_ROUND_ONE_END                = 10062, //Round 1 - finished!
		LANG_BG_SA_ALLIANCE_CAPTURED_RELIC      = 10063, //The Alliance captured the titan portal!
		LANG_BG_SA_HORDE_CAPTURED_RELIC         = 10064, //The Horde captured the titan portal!
		LANG_BG_SA_ROUND_TWO_ONE_MINUTE         = 10065, //Round 2 of the Battle for the Strand of the Ancients begins in 1 minute.
		LANG_BG_SA_ROUND_TWO_START_HALF_MINUTE  = 10066, //Round 2 begins in 30 seconds. Prepare yourselves!
		LANG_BG_SA_CHAMBER_BREACHED             = 10067, //The chamber has been breached! The titan relic is vulnerable!
		LANG_BG_SA_A_GY_SOUTH                   = 10068, //The Alliance captured the South Graveyard!
		LANG_BG_SA_A_GY_WEST                    = 10069, //The Alliance captured the West Graveyard!
		LANG_BG_SA_A_GY_EAST                    = 10070, //The Alliance captured the East Graveyard!
		LANG_BG_SA_H_GY_SOUTH                   = 10071, //The Horde captured the South Graveyard!
		LANG_BG_SA_H_GY_WEST                    = 10072, //The Horde captured the West Graveyard!
		LANG_BG_SA_H_GY_EAST                    = 10073, //The Horde captured the East Graveyard!

		// Use for custom patches             11000-11999
		LANG_AUTO_BROADCAST                 = 11000,
		LANG_INVALID_REALMID                = 11001,

		// Show Kick in world
		LANG_COMMAND_KICKMESSAGE_WORLD = 11002,

		// Show Mute in world
		LANG_COMMAND_MUTEMESSAGE_WORLD = 11003,

		// Show Ban in world
		LANG_BAN_CHARACTER_YOUBANNEDMESSAGE_WORLD     = 11004,
		LANG_BAN_CHARACTER_YOUPERMBANNEDMESSAGE_WORLD = 11005,
		LANG_BAN_ACCOUNT_YOUBANNEDMESSAGE_WORLD       = 11006,
		LANG_BAN_ACCOUNT_YOUPERMBANNEDMESSAGE_WORLD   = 11007,

		LANG_NPCINFO_MOVEMENT_DATA                    = 11008,
		LANG_NPCINFO_FLAGS_EXTRA                      = 11009,
		LANG_INSTANCE_LOGIN_GAMEMASTER_EXCEPTION      = 11010,

		LANG_CREATURE_NO_INTERIOR_POINT_FOUND         = 11011,
		LANG_CREATURE_MOVEMENT_NOT_BOUNDED            = 11012,
		LANG_CREATURE_MOVEMENT_MAYBE_UNBOUNDED        = 11013,
		LANG_INSTANCE_BIND_MISMATCH                   = 11014,
		LANG_CREATURE_NOT_AI_ENABLED                  = 11015,
		LANG_SELECT_PLAYER_OR_PET                     = 11016,

		// Continue show Ban in world (ip)
		LANG_BAN_IP_YOUBANNEDMESSAGE_WORLD            = 11017,
		LANG_BAN_IP_YOUPERMBANNEDMESSAGE_WORLD        = 11018,

		LANG_LFG_COOLDOWN_CLEARED                     = 11019,

		LANG_MUTED_PLAYER                             = 30000, // Mute for player 2 hour

		// Instant Flight
		LANG_TOGGLE_INSTANT_FLIGHT                    = 30077,
		LANG_INSTANT_FLIGHT_ON                        = 30078,
		LANG_INSTANT_FLIGHT_OFF                       = 30079,

		LANG_DEBUG_OPCODE_FILE_MISSING                = 30080,

		LANG_REMOVEITEM_FAILURE                       = 30081,
		LANG_REMOVEITEM_ERROR                         = 30082,

		LANG_BG_SHARE_QUEST_ERROR                     = 30083,
		LANG_BG_READY_CHECK_ERROR                     = 30084,

		LANG_DEBUG_BG_CONF                            = 30085,
		LANG_DEBUG_ARENA_CONF                         = 30086,

		// 30087-30095 reserved for passive anticheat

		LANG_DEBUG_LFG_ON                             = 30096,
		LANG_DEBUG_LFG_OFF                            = 30097,
		LANG_DEBUG_LFG_CONF                           = 30098,

		// debug loot command
		LANG_DEBUG_LOOT_HEADER                        = 30099,
		LANG_DEBUG_LOOT_ITEM                          = 30100,
		LANG_DEBUG_LOOT_ITEM_QUEST                    = 30101,
		LANG_DEBUG_LOOT_GOLD                          = 30102,
		LANG_DEBUG_LOOT_EMPTY                         = 30103,
		LANG_DEBUG_LOOT_INVALID_TYPE                  = 30104,
		LANG_DEBUG_LOOT_NO_TEMPLATE                   = 30105,
		LANG_DEBUG_LOOT_HEADER_MULTI                  = 30106,
		LANG_DEBUG_LOOT_ITEM_MULTI                    = 30107,
		LANG_DEBUG_LOOT_ITEM_QUEST_MULTI              = 30108,
		LANG_DEBUG_LOOT_GOLD_MULTI                    = 30109,

		// debug factionchange command (30110-30125)
		LANG_DEBUG_FACTIONCHANGE_HEADER               = 30110,
		LANG_DEBUG_FACTIONCHANGE_FLAG_FACTION          = 30111,
		LANG_DEBUG_FACTIONCHANGE_FLAG_RACE             = 30112,
		LANG_DEBUG_FACTIONCHANGE_FLAG_NONE             = 30113,
		LANG_DEBUG_FACTIONCHANGE_GUILD_FAIL            = 30114,
		LANG_DEBUG_FACTIONCHANGE_GUILD_OK              = 30115,
		LANG_DEBUG_FACTIONCHANGE_ARENA_CAPTAIN_FAIL    = 30116,
		LANG_DEBUG_FACTIONCHANGE_ARENA_CAPTAIN_OK      = 30117,
		LANG_DEBUG_FACTIONCHANGE_MAIL_FAIL             = 30118,
		LANG_DEBUG_FACTIONCHANGE_MAIL_OK               = 30119,
		LANG_DEBUG_FACTIONCHANGE_AUCTION_FAIL          = 30120,
		LANG_DEBUG_FACTIONCHANGE_AUCTION_OK            = 30121,
		LANG_DEBUG_FACTIONCHANGE_GOLD_FAIL             = 30122,
		LANG_DEBUG_FACTIONCHANGE_GOLD_OK               = 30123,
		LANG_DEBUG_FACTIONCHANGE_GOLD_NOLIMIT          = 30124,
		LANG_DEBUG_FACTIONCHANGE_NA                    = 30125,

		// Achievement commands
		LANG_ACHIEVEMENT_ADD_ONLINE                    = 30126,
		LANG_ACHIEVEMENT_ADD_OFFLINE                   = 30127,

		// Spawn group commands
		LANG_SPAWNGROUP_SPAWN_SYSTEM_ERROR  = 35411,
		LANG_SPAWNGROUP_SPAWN_SUCCESS       = 35412,
		LANG_SPAWNGROUP_SPAWN_FAILED        = 35413,
		LANG_SPAWNGROUP_DESPAWN_SYSTEM_ERROR = 35414,
		LANG_SPAWNGROUP_DESPAWN_SUCCESS     = 35415,
		LANG_SPAWNGROUP_DESPAWN_FAILED      = 35416,
		LANG_LIST_RESPAWNS_CREATURE_HEADER  = 35419,
		LANG_LIST_RESPAWNS_CREATURE_ENTRY   = 35420,
		LANG_LIST_RESPAWNS_GO_HEADER        = 35421,
		LANG_LIST_RESPAWNS_GO_ENTRY         = 35422,
		LANG_LIST_RESPAWNS_LIMIT            = 35423,
		LANG_SPAWNGROUP_NOT_FOUND           = 35424,

		// Pool debug commands
		LANG_POOL_NOT_FOUND                 = 35425,
		LANG_POOL_INFO_HEADER               = 35426,
		LANG_POOL_INFO_MEMBERS_HEADER       = 35427,
		LANG_POOL_INFO_MEMBER               = 35428,
		LANG_POOL_INFO_SUBPOOLS_HEADER      = 35429,
		LANG_POOL_INFO_SUBPOOL              = 35430,
		LANG_POOL_LOOKUP_IN_POOL            = 35431,
		LANG_POOL_LOOKUP_NOT_IN_POOL        = 35432,
		LANG_POOL_LOOKUP_USE_INFO           = 35433,
		LANG_POOL_LOOKUP_NOTARGET           = 35434,

		// Pet list command
		LANG_PET_LIST_HEADER                = 35435,
		LANG_PET_LIST_ENTRY                 = 35436,
		LANG_PET_LIST_EMPTY                 = 35437,

		// Pet delete command
		LANG_PET_DELETE_NOT_FOUND           = 35438,
		LANG_PET_DELETE_SUCCESS             = 35439,

		LANG_CHARACTER_DELETED_LIST_LIMIT   = 35440,

		// Respawn creature/gameobject by spawn GUID commands
		LANG_RESPAWN_GUID_CREATURE_NOT_FOUND    = 35441,
		LANG_RESPAWN_GUID_MAP_NOT_LOADED        = 35442,
		LANG_RESPAWN_GUID_CREATURE_ALIVE        = 35443,
		LANG_RESPAWN_GUID_CREATURE_QUEUED       = 35444,
		LANG_RESPAWN_GUID_GAMEOBJECT_ACTIVE     = 35445,
		LANG_RESPAWN_GUID_GAMEOBJECT_QUEUED     = 35446,
		// 35447 is reserved for LANG_LIST_RESPAWNS_NO_MAP (list respawns command, defined at the end of this enum)
		LANG_RESPAWN_GUID_GAMEOBJECT_NOT_FOUND  = 35448,

		// Respawn creature/gameobject by entry commands
		LANG_RESPAWN_ENTRY_CREATURE_NOT_FOUND    = 35449,
		LANG_RESPAWN_ENTRY_GAMEOBJECT_NOT_FOUND  = 35450,
		LANG_RESPAWN_ENTRY_CREATURE_QUEUED       = 35451,
		LANG_RESPAWN_ENTRY_GAMEOBJECT_QUEUED     = 35452,

		// List respawns console support
		LANG_LIST_RESPAWNS_NO_MAP           = 35447,

		// Pet rename command
		LANG_PET_RENAME_INVALID             = 35453,
		LANG_PET_RENAME_SUCCESS             = 35454,

		// Wintergrasp shutdown deferral
		LANG_WG_SHUTDOWN_DEFERRED           = 35455,

		// npc showloot command
		LANG_COMMAND_NOT_DEAD_OR_NO_LOOT    = 35456,
		LANG_COMMAND_NPC_SHOWLOOT_HEADER    = 35457,
		LANG_COMMAND_NPC_SHOWLOOT_MONEY     = 35458,
		LANG_COMMAND_NPC_SHOWLOOT_ITEMS     = 35459,
		LANG_COMMAND_NPC_SHOWLOOT_ENTRY     = 35460,
		LANG_COMMAND_NPC_SHOWLOOT_QUEST     = 35461,
	}

	const enum ShutdownMask {
		SHUTDOWN_MASK_NONE  =   0, // invented for mod_nodejs; others just hardcode 0
		SHUTDOWN_MASK_RESTART = 1,
		SHUTDOWN_MASK_IDLE    = 2,
	}

	// loot modes for creatures and gameobjects, bitmask!
	const enum LootModes {
		LOOT_MODE_DEFAULT                  = 0x01,
		LOOT_MODE_HARD_MODE_1              = 0x02,
		LOOT_MODE_HARD_MODE_2              = 0x04,
		LOOT_MODE_HARD_MODE_3              = 0x08,
		LOOT_MODE_HARD_MODE_4              = 0x10,
		LOOT_MODE_JUNK_FISH                = 0x8000,
	}

	const enum LootType {
		LOOT_NONE                           = 0,

		LOOT_CORPSE                         = 1,
		LOOT_PICKPOCKETING                  = 2,
		LOOT_FISHING                        = 3,
		LOOT_DISENCHANTING                  = 4,
		// ignored always by client
		LOOT_SKINNING                       = 6,
		LOOT_PROSPECTING                    = 7,
		LOOT_MILLING                        = 8,

		LOOT_FISHINGHOLE                    = 20,   // unsupported by client, sending LOOT_FISHING instead
		LOOT_INSIGNIA                       = 21,   // unsupported by client, sending LOOT_CORPSE instead
		LOOT_FISHING_JUNK                   = 22,   // unsupported by client, sending LOOT_FISHING instead
	}

	// mod-nodejs invention to make it easier to refer to one of the static values.
	const enum LootStoreType {
		LootTemplates_Creature =          0,
		LootTemplates_Disenchant =        1,
		LootTemplates_Fishing =           2,
		LootTemplates_Gameobject =        3,
		LootTemplates_Item =              4,
		LootTemplates_Mail =              5,
		LootTemplates_Milling =           6,
		LootTemplates_Pickpocketing =     7,
		LootTemplates_Prospecting =       8,
		LootTemplates_Reference =         9,
		LootTemplates_Skinning =         10,
		LootTemplates_Spell =            11,
		LootTemplates_Player =           12,
	}
}
export {};
