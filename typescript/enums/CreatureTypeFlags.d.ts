declare global {
	const enum CreatureTypeFlags {
		CREATURE_TYPE_FLAG_TAMEABLE                          = 0x00000001,   // Makes the mob tameable (must also be a beast and have family set)
		CREATURE_TYPE_FLAG_VISIBLE_TO_GHOSTS                 = 0x00000002,   // Creature is also visible for not alive player. Allows gossip interaction if npcflag allows?
		CREATURE_TYPE_FLAG_BOSS_MOB                          = 0x00000004,   // Changes creature's visible level to "??" in the creature's portrait - Immune Knockback.
		CREATURE_TYPE_FLAG_DO_NOT_PLAY_WOUND_ANIM            = 0x00000008,   // Does not play wound animation on parry
		CREATURE_TYPE_FLAG_NO_FACTION_TOOLTIP                = 0x00000010,
		CREATURE_TYPE_FLAG_MORE_AUDIBLE                      = 0x00000020,   // Sound related
		CREATURE_TYPE_FLAG_SPELL_ATTACKABLE                  = 0x00000040,
		CREATURE_TYPE_FLAG_INTERACT_WHILE_DEAD               = 0x00000080,   // Player can interact with the creature if creature is dead (not if player is dead)
		CREATURE_TYPE_FLAG_SKIN_WITH_HERBALISM               = 0x00000100,   // Can be looted by herbalist
		CREATURE_TYPE_FLAG_SKIN_WITH_MINING                  = 0x00000200,   // Can be looted by miner
		CREATURE_TYPE_FLAG_NO_DEATH_MESSAGE                  = 0x00000400,   // Death event will not show up in combat log
		CREATURE_TYPE_FLAG_ALLOW_MOUNTED_COMBAT              = 0x00000800,   // Creature can remain mounted when entering combat
		CREATURE_TYPE_FLAG_CAN_ASSIST                        = 0x00001000,   // ? Can aid any player in combat if in range?
		CREATURE_TYPE_FLAG_NO_PET_BAR                        = 0x00002000,
		CREATURE_TYPE_FLAG_MASK_UID                          = 0x00004000,
		CREATURE_TYPE_FLAG_SKIN_WITH_ENGINEERING             = 0x00008000,   // Can be looted by engineer
		CREATURE_TYPE_FLAG_TAMEABLE_EXOTIC                   = 0x00010000,   // Can be tamed by hunter as exotic pet
		CREATURE_TYPE_FLAG_USE_MODEL_COLLISION_SIZE          = 0x00020000,   // Collision related. (always using default collision box?)
		CREATURE_TYPE_FLAG_ALLOW_INTERACTION_WHILE_IN_COMBAT = 0x00040000,
		CREATURE_TYPE_FLAG_COLLIDE_WITH_MISSILES             = 0x00080000,   // Projectiles can collide with this creature - interacts with TARGET_DEST_TRAJ
		CREATURE_TYPE_FLAG_NO_NAME_PLATE                     = 0x00100000,
		CREATURE_TYPE_FLAG_DO_NOT_PLAY_MOUNTED_ANIMATIONS    = 0x00200000,
		CREATURE_TYPE_FLAG_LINK_ALL                          = 0x00400000,
		CREATURE_TYPE_FLAG_INTERACT_ONLY_WITH_CREATOR        = 0x00800000,
		CREATURE_TYPE_FLAG_DO_NOT_PLAY_UNIT_EVENT_SOUNDS     = 0x01000000,
		CREATURE_TYPE_FLAG_HAS_NO_SHADOW_BLOB                = 0x02000000,
		CREATURE_TYPE_FLAG_TREAT_AS_RAID_UNIT                = 0x04000000,   // ! Creature can be targeted by spells that require target to be in caster's party/raid
		CREATURE_TYPE_FLAG_FORCE_GOSSIP                      = 0x08000000,   // Allows the creature to display a single gossip option.
		CREATURE_TYPE_FLAG_DO_NOT_SHEATHE                    = 0x10000000,
		CREATURE_TYPE_FLAG_DO_NOT_TARGET_ON_INTERACTION      = 0x20000000,
		CREATURE_TYPE_FLAG_DO_NOT_RENDER_OBJECT_NAME         = 0x40000000,
		CREATURE_TYPE_FLAG_QUEST_BOSS                        = 0x80000000,   // Not verified
	}
}
export {};
