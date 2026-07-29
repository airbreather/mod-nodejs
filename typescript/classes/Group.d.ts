declare global {
	namespace Acore {
		class Group {
			readonly isRaid: boolean;
			readonly isLFG: boolean;
			readonly isBG: boolean;
			readonly isFull: boolean;
			readonly leaderName: string;
			readonly guid: ObjectGuidNative;
			readonly memberCount: number;
			readonly groupType: GroupType;
			readonly members: GroupMember[];
			leaderGuid: ObjectGuid;

			hasFreeSlotInSubgroup(subgroup: number): boolean;
			disband(): void;
			convertToRaid(): void;
			changeSubgroup(member: ObjectGuid, subgroup: number): void;
			setTargetIcon(icon: TargetIcon, setBy: ObjectGuid | undefined, target: ObjectGuid | undefined): void;
			addMember(player: Player, roles?: LfgRoles): boolean;
			removeMember(member: ObjectGuid, method?: RemoveMethod, kicker?: ObjectGuid, reason?: string): void;
			setAssistant(player: ObjectGuid): void;
			removeAssistant(member: ObjectGuid): void;
			sendPacket(packet: WorldPacket, ignorePlayersInBG?: boolean, subgroup?: number, ignorePlayer?: ObjectGuid): void;
		}
	}
}
export {};
