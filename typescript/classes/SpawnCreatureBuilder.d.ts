declare global {
	namespace Acore {
		class SpawnCreatureBuilder {
			private constructor();

			spawn(): Creature | undefined;

			setPhaseMask(phaseMask: number): this;
			setDisplayId(displayId: number): this;
			setEquipmentId(equipmentId: number): this;
			addNpcFlags(flags: NPCFlags): this;
			removeNpcFlags(flags: NPCFlags): this;
			replaceNpcFlags(flags: NPCFlags): this;
			addUnitFlags(flags: UnitFlags): this;
			removeUnitFlags(flags: UnitFlags): this;
			replaceUnitFlags(flags: UnitFlags): this;
			addDynamicFlags(flags: UnitDynFlags): this;
			removeDynamicFlags(flags: UnitDynFlags): this;
			replaceDynamicFlags(flags: UnitDynFlags): this;
		}
	}
}
export {};
