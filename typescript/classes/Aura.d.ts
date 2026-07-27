declare global {
	namespace Acore {
		class Aura {
			readonly caster: Unit;
			readonly casterGuid: ObjectGuidNative;
			readonly castItemGuid: ObjectGuidNative | undefined;
			readonly castItemEntry: number;
			readonly owner: WorldObject;
			readonly casterLevel: number;
			readonly spellId: number;
			readonly spellInfo: SpellInfo;
			readonly type: AuraType;
			readonly charges: number;
			readonly isExpired: boolean;
			readonly isPermanent: boolean;
			duration: number;
			maxDuration: number;
			stackAmount: number;

			setDurationWithMods(duration: number): void;
			remove(): void;
		}
	}
}
export {};
