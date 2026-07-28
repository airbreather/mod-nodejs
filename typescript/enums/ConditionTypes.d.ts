declare global {
	const enum ConditionTypes {
		// value1                           value2          value3
		CONDITION_NONE                      = 0,            // 0                0              0                  always true
		CONDITION_AURA                      = 1,            // spell_id         effindex       use target?        true if player (or target, if value3) has aura of spell_id with effect effindex
		CONDITION_ITEM                      = 2,            // item_id          count          bank               true if has #count of item_ids (if 'bank' is set it searches in bank slots too)
		CONDITION_ITEM_EQUIPPED             = 3,            // item_id          0              0                  true if has item_id equipped
		CONDITION_ZONEID                    = 4,            // zone_id          0              0                  true if in zone_id
		CONDITION_REPUTATION_RANK           = 5,            // faction_id       rankMask       0                  true if has min_rank for faction_id
		CONDITION_TEAM                      = 6,            // player_team      0,             0                  469 - Alliance, 67 - Horde)
		CONDITION_SKILL                     = 7,            // skill_id         skill_value    0                  true if has skill_value for skill_id
		CONDITION_QUESTREWARDED             = 8,            // quest_id         0              0                  true if quest_id was rewarded before
		CONDITION_QUESTTAKEN                = 9,            // quest_id         0,             0                  true while quest active
		CONDITION_DRUNKENSTATE              = 10,           // DrunkenState     0,             0                  true if player is drunk enough
		CONDITION_WORLD_STATE               = 11,           // index            value          0                  true if world has the value for the index
		CONDITION_ACTIVE_EVENT              = 12,           // event_id         0              0                  true if event is active
		CONDITION_INSTANCE_INFO             = 13,           // entry            data           type               true if the instance info defined by type (enum InstanceInfo) equals data.
		CONDITION_QUEST_NONE                = 14,           // quest_id         0              0                  true if doesn't have quest saved
		CONDITION_CLASS                     = 15,           // class            0              0                  true if player's class is equal to class
		CONDITION_RACE                      = 16,           // race             0              0                  true if player's race is equal to race
		CONDITION_ACHIEVEMENT               = 17,           // achievement_id   0              0                  true if achievement is complete
		CONDITION_TITLE                     = 18,           // title id         0              0                  true if player has title
		CONDITION_SPAWNMASK                 = 19,           // spawnMask        0              0                  true if in spawnMask
		CONDITION_GENDER                    = 20,           // gender           0              0                  true if player's gender is equal to gender
		CONDITION_UNIT_STATE                = 21,           // unitState        0              0                  true if unit has unitState
		CONDITION_MAPID                     = 22,           // map_id           0              0                  true if in map_id
		CONDITION_AREAID                    = 23,           // area_id          0              0                  true if in area_id
		CONDITION_CREATURE_TYPE             = 24,           // cinfo.type       0              0                  true if creature_template.type = value1
		CONDITION_SPELL                     = 25,           // spell_id         0              0                  true if player has learned spell
		CONDITION_PHASEMASK                 = 26,           // phasemask        0              0                  true if object is in phasemask
		CONDITION_LEVEL                     = 27,           // level            ComparisonType 0                  true if unit's level is equal to param1 (param2 can modify the statement)
		CONDITION_QUEST_COMPLETE            = 28,           // quest_id         0              0                  true if player has quest_id with all objectives complete, but not yet rewarded
		CONDITION_NEAR_CREATURE             = 29,           // creature entry   distance       dead               true if there is a creature of entry in range
		CONDITION_NEAR_GAMEOBJECT           = 30,           // gameobject entry distance       GoState            true if there is a gameobject of entry in range (param3 can check for GoState, 0 = dont't check, 1 = Ready , 2 = Not Ready)
		CONDITION_OBJECT_ENTRY_GUID         = 31,           // TypeID           entry          guid/Attackable    true if object is type TypeID and the entry is 0 or matches entry of the object or matches guid of the object
		CONDITION_TYPE_MASK                 = 32,           // TypeMask         0              0                  true if object is type object's TypeMask matches provided TypeMask
		CONDITION_RELATION_TO               = 33,           // ConditionTarget  RelationType   0                  true if object is in given relation with object specified by ConditionTarget
		CONDITION_REACTION_TO               = 34,           // ConditionTarget  rankMask       0                  true if object's reaction matches rankMask object specified by ConditionTarget
		CONDITION_DISTANCE_TO               = 35,           // ConditionTarget  distance       ComparisonType     true if object and ConditionTarget are within distance given by parameters
		CONDITION_ALIVE                     = 36,           // 0                0              0                  true if unit is alive
		CONDITION_HP_VAL                    = 37,           // hpVal            ComparisonType 0                  true if unit's hp matches given value
		CONDITION_HP_PCT                    = 38,           // hpPct            ComparisonType 0                  true if unit's hp matches given pct
		CONDITION_REALM_ACHIEVEMENT         = 39,           // achievement_id   0              0                  true if realm achievement is complete
		CONDITION_IN_WATER                  = 40,           // 0                0              0                  true if unit in water
		CONDITION_TERRAIN_SWAP              = 41,           // don't use on 3.3.5a
		CONDITION_STAND_STATE               = 42,           // stateType        state          0                  true if unit matches specified sitstate (0,x: has exactly state x; 1,0: any standing state; 1,1: any sitting state;)
		CONDITION_DAILY_QUEST_DONE          = 43,           // quest id         0              0                  true if daily quest has been completed for the day
		CONDITION_CHARMED                   = 44,           // 0                0              0                  true if unit is currently charmed
		CONDITION_PET_TYPE                  = 45,           // mask             0              0                  true if player has a pet of given type(s)
		CONDITION_TAXI                      = 46,           // 0                0              0                  true if player is on taxi
		CONDITION_QUESTSTATE                = 47,           // quest_id         state_mask     0                  true if player is in any of the provided quest states for the quest (1 = not taken, 2 = completed, 8 = in progress, 32 = failed, 64 = rewarded)
		CONDITION_QUEST_OBJECTIVE_PROGRESS = 48,            // quest_id         objectiveIndex objectiveCount     true if player has reached the specified objectiveCount quest progress for the objectiveIndex for the specified quest
		CONDITION_DIFFICULTY_ID            = 49,            // Difficulty       0              0                  true is map has difficulty id
		CONDITION_TC_END                   = 50,            // placeholder

		CONDITION_AC_START                 = 100,
		CONDITION_QUEST_SATISFY_EXCLUSIVE  = 101,           // quest_id         0              0                  true if satisfied exclusive group
		CONDITION_HAS_AURA_TYPE            = 102,           // aura_type        0              0                  true if has aura type
		CONDITION_WORLD_SCRIPT             = 103,           // conditionId      state          0                  true if WorldState::IsConditionFulfilled returns true
		CONDITION_AI_DATA                  = 104,           // dataId           value          0                  true if AI::GetData returns value
		CONDITION_PLAYER_QUEUED_RANDOM_DUNGEON = 105,       // checkDifficulty  difficulty     0                  true if player is queued for a random dungeon via RDF
		CONDITION_UNIT_IN_COMBAT           = 106,           // 0                0              0                  true if unit is engaged in combat

		CONDITION_AC_END                   = 107,           // placeholder
	}
}
export {};
