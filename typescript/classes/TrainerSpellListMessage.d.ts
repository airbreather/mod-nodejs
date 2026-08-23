declare global {
	namespace Acore {
		class TrainerSpellListMessage {
			private constructor();

			readonly spells: TrainerSpellList;

			trainerGuid: ObjectGuid;
			trainerType: TrainerType;
			greeting: string;
		}
	}
}
export {};
