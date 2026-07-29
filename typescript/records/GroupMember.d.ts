declare global {
	interface GroupMember {
		guid: ObjectGuidNative;
		name: string;
		roles: LfgRoles;
		flags: GroupMemberFlags;
	}
}
export {};
