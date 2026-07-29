declare global {
	const enum GroupType {
		GROUPTYPE_NORMAL         = 0x00,
		GROUPTYPE_BG             = 0x01,
		GROUPTYPE_RAID           = 0x02,
		GROUPTYPE_BGRAID         = GROUPTYPE_BG | GROUPTYPE_RAID, // mask
		GROUPTYPE_LFG_RESTRICTED = 0x04, // Script_HasLFGRestrictions()
		GROUPTYPE_LFG            = 0x08,
		// 0x10, leave/change group?, I saw this flag when leaving group and after leaving BG while in group
		// GROUPTYPE_ONE_PERSON_PARTY   = 0x20, 4.x Script_IsOnePersonParty()
		// GROUPTYPE_EVERYONE_ASSISTANT = 0x40, 4.x Script_IsEveryoneAssistant()
	}
}
export {};
