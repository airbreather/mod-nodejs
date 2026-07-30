declare global {
	namespace Acore {
		class Quest {
			static byId(id: number): Quest | undefined;

			readonly questId: number;
			readonly questType: QuestTypes;
			readonly level: number;
			readonly logTitle: string;
			readonly objectiveText: string;
			readonly objectiveDescription: string;
			readonly areaDescription: string;
			readonly startAreaId: number;
			readonly rewardSpell: number;
			readonly isRepeatable: boolean;
			readonly isDaily: boolean;
			readonly isWeekly: boolean;
		}
	}
}
export {};
