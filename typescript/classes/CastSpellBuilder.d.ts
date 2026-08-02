declare global {
	namespace Acore {
		class CastSpellBuilder {
			cast(): SpellCastResult;

			resetCaster(caster: Unit): this;
			resetSpell(spell: SpellInfo): this;
			targetUnit(target: Unit): this;
			targetGameObject(target: GameObject): this;
			targetCorpse(target: Corpse): this;
			targetItem(target: Item): this;
			targetItemInTradeWith(player: Player): this;
			updateTradeSlotItem(): this;
			resetObjectTarget(): this;
			setSrcWorldObject(src: WorldObject): this;
			setSrcPos(x: number, y: number, z: number, o?: number): this;
			moveSrcPos(x: number, y: number, z: number, o?: number): this;
			resetSrc(): this;
			setDstWorldObject(dst: WorldObject): this;
			setDstPos(x: number, y: number, z: number, o?: number, mapId?: number): this;
			moveDstPos(x: number, y: number, z: number, o?: number): this;
			resetDst(): this;
			setElevation(elevation: number): this;
			setSpeed(speed: number): this;
			setObjectTargetChannel(guid: ObjectGuid | undefined): this;
			setDstChannelWorldObject(dstChannel: WorldObject): this;
			setDstChannelPos(x: number, y: number, z: number, o?: number, mapId?: number): this;
			resetDstChannel(): this;
			setCustomSpellValue(mod: SpellValueMod, val: number): this;
			appendTriggerFlags(flags: TriggerCastFlags): this;
			resetTriggerFlags(newFlags?: TriggerCastFlags): this;
			setCastItem(item: Item): this;
			resetCastItem(): this;
			setTriggeredByAura(aura: AuraEffect): this;
			resetTriggeredByAura(): this;
			setOriginalCaster(originalCaster: ObjectGuid | undefined): this;
			setTargetFlagsAdvanced(newFlags: SpellCastTargetFlags): this;
		}
	}
}
export {};
