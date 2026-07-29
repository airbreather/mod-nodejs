import type Long from 'long';

declare global {
	namespace Acore {
		class Guild {
			static byLeaderGuid(guid: ObjectGuid): Guild | undefined;
			static byName(name: string): Guild | undefined;
			static byId(id: number): Guild | undefined;

			readonly id: number;
			readonly leaderGuid: ObjectGuidNative;
			readonly memberCount: GuildMember[];
			readonly members: number;
			readonly totalBankMoney: number | (Long & { unsigned: true });
			readonly createdDate: Temporal.Instant;
			name: string;
			motd: string;
			info: string;

			getMemberByGuid(guid: ObjectGuid): GuildMember | undefined;
			getMemberByName(name: string): GuildMember | undefined;
			addMember(guid: ObjectGuid, rank?: GuildDefaultRanks | number): void;
			removeMember(guid: ObjectGuid, kicked?: boolean): void;
			disband(): void;
			modifyBankMoney(money: LongLike): boolean;
			// more to come, see the TODOs on the C++ side.
		}
	}
}
export {};
