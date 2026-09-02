declare global {
	namespace Acore {
		class FactionEntry {
			private constructor();

			static byId(id: number): FactionEntry | undefined;

			readonly id: number;
			readonly reputationListId: number;
			readonly baseRepRaceMask0: number;
			readonly baseRepRaceMask1: number;
			readonly baseRepRaceMask2: number;
			readonly baseRepRaceMask3: number;
			readonly baseRepClassMask0: number;
			readonly baseRepClassMask1: number;
			readonly baseRepClassMask2: number;
			readonly baseRepClassMask3: number;
			readonly baseRepValue0: number;
			readonly baseRepValue1: number;
			readonly baseRepValue2: number;
			readonly baseRepValue3: number;
			readonly reputationFlags0: number;
			readonly reputationFlags1: number;
			readonly reputationFlags2: number;
			readonly reputationFlags3: number;
			readonly team: number;
			readonly spilloverRateIn: number;
			readonly spilloverRateOut: number;
			readonly spilloverMaxRankIn: number;
			readonly name: number;
			readonly canHaveReputation: number;
			readonly canBeSetAtWar: number;

			// always nullish if team is 0, always number[] otherwise
			otherFactionsInTeam(): number[] | undefined;
		}
	}
}
export {};
