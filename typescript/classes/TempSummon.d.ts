declare global {
	namespace Acore {
		class TempSummon extends Creature {
			readonly summoner: WorldObject | undefined;
			readonly properties: SummonPropertiesEntry | undefined;

			isVisibleBySummonerOnly: boolean;
			timer: Temporal.Duration;
			summonType: TempSummonType;

			unsummon(delay?: Temporal.Duration): void;
		}
	}
}
export {};
