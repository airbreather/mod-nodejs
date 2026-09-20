#include "NodePropertySystem.h"
#include "SpawnCreatureBuilder.h"

JVAL_CVAL_TMPLS_RW(SpawnCreatureBuilder)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<SpawnCreatureBuilder *>() {
	TypedTemplate<SpawnCreatureBuilder *> const ft = jctor<SpawnCreatureBuilder *>();

	ft->SetClassName(jstr_intern("SpawnCreatureBuilder"));

	reg_method(ft, "spawn", [](SpawnCreatureBuilder * b) {
		return b->spawn();
	});
	reg_method(ft, "setPhaseMask", [](SpawnCreatureBuilder * b, uint32_t phase_mask) {
		b->phase_mask = phase_mask;
		return b;
	});
	reg_method(ft, "setDisplayId", [](SpawnCreatureBuilder * b, uint32_t display_id) {
		b->ensure_data().displayid = display_id;
		return b;
	});
	reg_method(ft, "setEquipmentId", [](SpawnCreatureBuilder * b, int8_t equipment_id) {
		b->ensure_data().equipmentId = equipment_id;
		return b;
	});
	reg_method(ft, "addNpcFlags", [](SpawnCreatureBuilder * b, NPCFlags flags) {
		b->ensure_data().npcflag |= flags;
		return b;
	});
	reg_method(ft, "removeNpcFlags", [](SpawnCreatureBuilder * b, NPCFlags flags) {
		b->ensure_data().npcflag &= ~flags;
		return b;
	});
	reg_method(ft, "replaceNpcFlags", [](SpawnCreatureBuilder * b, NPCFlags flags) {
		b->ensure_data().npcflag = flags;
		return b;
	});
	reg_method(ft, "addUnitFlags", [](SpawnCreatureBuilder * b, UnitFlags flags) {
		b->ensure_data().unit_flags |= flags;
		return b;
	});
	reg_method(ft, "removeUnitFlags", [](SpawnCreatureBuilder * b, UnitFlags flags) {
		b->ensure_data().unit_flags &= ~flags;
		return b;
	});
	reg_method(ft, "replaceUnitFlags", [](SpawnCreatureBuilder * b, UnitFlags flags) {
		b->ensure_data().unit_flags = flags;
		return b;
	});
	reg_method(ft, "addDynamicFlags", [](SpawnCreatureBuilder * b, UnitDynFlags flags) {
		b->ensure_data().unit_flags |= flags;
		return b;
	});
	reg_method(ft, "removeDynamicFlags", [](SpawnCreatureBuilder * b, UnitDynFlags flags) {
		b->ensure_data().unit_flags &= ~flags;
		return b;
	});
	reg_method(ft, "replaceDynamicFlags", [](SpawnCreatureBuilder * b, UnitDynFlags flags) {
		b->ensure_data().unit_flags = flags;
		return b;
	});

	return ft;
}
