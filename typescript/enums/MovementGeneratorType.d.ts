declare global {
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
}
export {};
