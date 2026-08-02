declare global {
	const enum EvadeReason {
		EVADE_REASON_NO_HOSTILES,       // the creature's threat list is empty
		EVADE_REASON_BOUNDARY,          // the creature has moved outside its evade boundary
		EVADE_REASON_SEQUENCE_BREAK,    // this is a boss and the pre-requisite encounters for engaging it are not defeated yet
		EVADE_REASON_NO_PATH,           // the creature was unable to reach its target for over 5 seconds
		EVADE_REASON_OTHER,
	}
}
export {};
