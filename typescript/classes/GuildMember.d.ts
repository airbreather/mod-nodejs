declare global {
	namespace Acore {
		class GuildMember {
			readonly playerGuid: ObjectGuidNative;
			readonly playerName: string;
			readonly clazz: Classes;
			readonly level: number;
			readonly gender: Gender;
			readonly accountId: number;
			readonly logoutTime: Temporal.Instant;
			readonly flags: GuildMemberFlags;
			readonly zoneId: number;
			readonly isOnline: boolean;
			readonly remainingWithdrawalAllowedTodayTotal: number;
			rankId: GuildDefaultRanks | number;

			remainingWithdrawalAllowedTodayOnTab(tab: number): number;
		}
	}
}
export {};
