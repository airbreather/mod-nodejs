#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CastSpellBuilder.h"
#include "CtoJ.h"
#include "NodePropertySystem.h"

JVAL_CVAL_TMPLS_RW(CastSpellBuilder)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<CastSpellBuilder *>() {
	TypedTemplate<CastSpellBuilder *> const ft = jctor<CastSpellBuilder *>();

	ft->SetClassName(jstr_intern("CastSpellBuilder"));

	// what it's all about :D
	reg_method(ft, "cast", [](CastSpellBuilder * b) {
		return b->cast();
	});

	// all the stuff you can do below.
	reg_method(ft, "resetCaster", [](CastSpellBuilder * b, Unit * caster) {
		b->caster = caster;
		return b;
	});
	reg_method(ft, "resetSpell", [](CastSpellBuilder * b, SpellInfo const * s) {
		b->spell_info = s;
		return b;
	});
	reg_method(ft, "targetUnit", [](CastSpellBuilder * b, Unit * t) {
		b->targets.SetUnitTarget(t);
		return b;
	});
	reg_method(ft, "targetGameObject", [](CastSpellBuilder * b, GameObject * t) {
		b->targets.SetGOTarget(t);
		return b;
	});
	reg_method(ft, "targetCorpse", [](CastSpellBuilder * b, Corpse * t) {
		b->targets.SetCorpseTarget(t);
		return b;
	});
	reg_method(ft, "targetItem", [](CastSpellBuilder * b, Item * t) {
		b->targets.SetItemTarget(t);
		return b;
	});
	reg_method(ft, "targetItemInTradeWith", [](CastSpellBuilder * b, Player * p) {
		b->targets.SetTradeItemTarget(p);
		return b;
	});
	reg_method(ft, "updateTradeSlotItem", [](CastSpellBuilder * b) {
		b->targets.UpdateTradeSlotItem();
		return b;
	});
	reg_method(ft, "resetObjectTarget", [](CastSpellBuilder * b) {
		b->targets.RemoveObjectTarget();
		return b;
	});
	reg_method(ft, "setSrcWorldObject", [](CastSpellBuilder * b, WorldObject * wo) {
		b->targets.SetSrc(*wo);
		return b;
	});
	reg_method(ft, "setSrcPos", [](CastSpellBuilder * b, float x, float y, float z, std::optional<float> o) {
		Position pos(x, y, z, o.value_or(0));
		b->targets.SetSrc(pos);
		return b;
	});
	reg_method(ft, "moveSrcPos", [](CastSpellBuilder * b, float x, float y, float z, std::optional<float> o) {
		Position pos(x, y, z, o.value_or(0));
		b->targets.ModSrc(pos);
		return b;
	});
	reg_method(ft, "resetSrc", [](CastSpellBuilder * b) {
		b->targets.RemoveSrc();
		return b;
	});
	reg_method(ft, "setDstWorldObject", [](CastSpellBuilder * b, WorldObject * wo) {
		b->targets.SetDst(*wo);
		return b;
	});
	reg_method(ft, "setDstPos", [](CastSpellBuilder * b, float x, float y, float z, std::optional<float> o, std::optional<uint32_t> map_id) {
		SpellDestination dst(x, y, z, o.value_or(0), map_id.value_or(MAPID_INVALID));
		b->targets.SetDst(dst);
		return b;
	});
	reg_method(ft, "moveDstPos", [](CastSpellBuilder * b, float x, float y, float z, std::optional<float> o) {
		Position pos(x, y, z, o.value_or(0));
		b->targets.ModDst(pos);
		return b;
	});
	reg_method(ft, "resetDst", [](CastSpellBuilder * b) {
		b->targets.RemoveDst();
		return b;
	});
	reg_method(ft, "setElevation", [](CastSpellBuilder * b, float elevation) {
		b->targets.SetElevation(elevation);
		return b;
	});
	reg_method(ft, "setSpeed", [](CastSpellBuilder * b, float speed) {
		b->targets.SetSpeed(speed);
		return b;
	});
	reg_method(ft, "setObjectTargetChannel", [](CastSpellBuilder * b, ObjectGuid guid) {
		b->targets.SetObjectTargetChannel(guid);
		return b;
	});
	reg_method(ft, "setDstChannelWorldObject", [](CastSpellBuilder * b, WorldObject * wo) {
		SpellDestination loc(*wo);
		b->targets.SetDstChannel(loc);
		return b;
	});
	reg_method(ft, "setDstChannelPos", [](CastSpellBuilder * b, float x, float y, float z, std::optional<float> o, std::optional<uint32_t> map_id) {
		SpellDestination loc(x, y, z, o.value_or(0), map_id.value_or(MAPID_INVALID));
		b->targets.SetDstChannel(loc);
		return b;
	});
	reg_method(ft, "resetDstChannel", [](CastSpellBuilder * b) {
		b->targets.SetDstChannel({});
		return b;
	});
	reg_method(ft, "setCustomSpellValue", [](CastSpellBuilder * b, SpellValueMod mod, int32_t v) {
		b->custom_spell_values[mod] = v;
		return b;
	});
	reg_method(ft, "appendTriggerFlags", [](CastSpellBuilder * b, TriggerCastFlags flags) {
		b->trigger_cast_flags = static_cast<TriggerCastFlags>(b->trigger_cast_flags | flags);
		return b;
	});
	reg_method(ft, "resetTriggerFlags", [](CastSpellBuilder * b, std::optional<TriggerCastFlags> flags) {
		b->trigger_cast_flags = flags.value_or(TRIGGERED_NONE);
		return b;
	});
	reg_method(ft, "setCastItem", [](CastSpellBuilder * b, Item * item) {
		b->cast_item = item;
		return b;
	});
	reg_method(ft, "resetCastItem", [](CastSpellBuilder * b) {
		b->cast_item = nullptr;
		return b;
	});
	reg_method(ft, "setTriggeredByAura", [](CastSpellBuilder * b, AuraEffect * aura) {
		b->triggered_by_aura = aura;
		return b;
	});
	reg_method(ft, "resetTriggeredByAura", [](CastSpellBuilder * b) {
		b->triggered_by_aura = nullptr;
		return b;
	});
	reg_method(ft, "setOriginalCaster", [](CastSpellBuilder * b, ObjectGuid original_caster) {
		b->original_caster = original_caster;
		return b;
	});
	reg_method(ft, "setTargetFlagsAdvanced", [](CastSpellBuilder * b, SpellCastTargetFlags flags) {
		b->targets.SetTargetFlag(flags);
		return b;
	});

	return ft;
}
