#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"
#include "ObjectMgr.h"

JVAL_CVAL_TMPLS_RO(GameObjectTemplate const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<GameObjectTemplate const *>() {
	TypedTemplate<GameObjectTemplate const *> const ft = jctor();

	ft->SetClassName(jstr_intern("GameObjectTemplate"));

	reg_static_method(ft, "byId", [](uint32_t id) {
		return sObjectMgr->GetGameObjectTemplate(id);
	});

	reg_prop_ro(ft, "entry", [](GameObjectTemplate const * t) {
		return t->entry;
	});
	reg_prop_ro(ft, "type", [](GameObjectTemplate const * t) {
		return t->type;
	});
	reg_prop_ro(ft, "displayId", [](GameObjectTemplate const * t) {
		return t->displayId;
	});
	reg_prop_ro(ft, "name", [](GameObjectTemplate const * t) {
		return t->name;
	});
	reg_prop_ro(ft, "iconName", [](GameObjectTemplate const * t) {
		return t->IconName;
	});
	reg_prop_ro(ft, "castBarCaption", [](GameObjectTemplate const * t) {
		return t->castBarCaption;
	});
	reg_prop_ro(ft, "unk1", [](GameObjectTemplate const * t) {
		return t->unk1;
	});
	reg_prop_ro(ft, "size", [](GameObjectTemplate const * t) {
		return t->size;
	});
	reg_prop_ro(ft, "doorData", [](GameObjectTemplate const * t) {
		return &t->door;
	});
	reg_prop_ro(ft, "buttonData", [](GameObjectTemplate const * t) {
		return &t->button;
	});
	reg_prop_ro(ft, "questgiverData", [](GameObjectTemplate const * t) {
		return &t->questgiver;
	});
	reg_prop_ro(ft, "chestData", [](GameObjectTemplate const * t) {
		return &t->chest;
	});
	reg_prop_ro(ft, "genericData", [](GameObjectTemplate const * t) {
		return &t->_generic;
	});
	reg_prop_ro(ft, "trapData", [](GameObjectTemplate const * t) {
		return &t->trap;
	});
	reg_prop_ro(ft, "chairData", [](GameObjectTemplate const * t) {
		return &t->chair;
	});
	reg_prop_ro(ft, "spellFocusData", [](GameObjectTemplate const * t) {
		return &t->spellFocus;
	});
	reg_prop_ro(ft, "textData", [](GameObjectTemplate const * t) {
		return &t->text;
	});
	reg_prop_ro(ft, "gooberData", [](GameObjectTemplate const * t) {
		return &t->goober;
	});
	reg_prop_ro(ft, "transportData", [](GameObjectTemplate const * t) {
		return &t->transport;
	});
	reg_prop_ro(ft, "areadamageData", [](GameObjectTemplate const * t) {
		return &t->areadamage;
	});
	reg_prop_ro(ft, "cameraData", [](GameObjectTemplate const * t) {
		return &t->camera;
	});
	reg_prop_ro(ft, "moTransportData", [](GameObjectTemplate const * t) {
		return &t->moTransport;
	});
	reg_prop_ro(ft, "summoningRitualData", [](GameObjectTemplate const * t) {
		return &t->summoningRitual;
	});
	reg_prop_ro(ft, "guardpostData", [](GameObjectTemplate const * t) {
		return &t->guardpost;
	});
	reg_prop_ro(ft, "spellcasterData", [](GameObjectTemplate const * t) {
		return &t->spellcaster;
	});
	reg_prop_ro(ft, "meetingstoneData", [](GameObjectTemplate const * t) {
		return &t->meetingstone;
	});
	reg_prop_ro(ft, "flagstandData", [](GameObjectTemplate const * t) {
		return &t->flagstand;
	});
	reg_prop_ro(ft, "fishingholeData", [](GameObjectTemplate const * t) {
		return &t->fishinghole;
	});
	reg_prop_ro(ft, "flagdropData", [](GameObjectTemplate const * t) {
		return &t->flagdrop;
	});
	reg_prop_ro(ft, "miniGameData", [](GameObjectTemplate const * t) {
		return &t->miniGame;
	});
	reg_prop_ro(ft, "capturePointData", [](GameObjectTemplate const * t) {
		return &t->capturePoint;
	});
	reg_prop_ro(ft, "auraGeneratorData", [](GameObjectTemplate const * t) {
		return &t->auraGenerator;
	});
	reg_prop_ro(ft, "dungeonDifficultyData", [](GameObjectTemplate const * t) {
		return &t->dungeonDifficulty;
	});
	reg_prop_ro(ft, "barberChairData", [](GameObjectTemplate const * t) {
		return &t->barberChair;
	});
	reg_prop_ro(ft, "buildingData", [](GameObjectTemplate const * t) {
		return &t->building;
	});
	reg_prop_ro(ft, "trapDoorData", [](GameObjectTemplate const * t) {
		return &t->trapDoor;
	});
	reg_prop_ro(ft, "rawData", [](GameObjectTemplate const * t) {
		return jarr(t->raw.data);
	});

	return ft;
}
