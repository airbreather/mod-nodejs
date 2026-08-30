declare global {
	interface GroupMember {
		guid: bigint;
		name: string;
		roles: LfgRoles;
		flags: GroupMemberFlags;
	}
}
export {};
