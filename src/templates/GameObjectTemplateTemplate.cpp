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
	reg_prop_ro(ft, "rawData", [](GameObjectTemplate const * t) {
		return jarr(t->raw.data);
	});
	reg_prop_ro(ft, "data", [](GameObjectTemplate const * t) {
		switch (t->type) {
			case GAMEOBJECT_TYPE_DOOR: return jval(&t->door);
			case GAMEOBJECT_TYPE_BUTTON: return jval(&t->button);
			case GAMEOBJECT_TYPE_QUESTGIVER: return jval(&t->questgiver);
			case GAMEOBJECT_TYPE_CHEST: return jval(&t->chest);
			// case GAMEOBJECT_TYPE_BINDER: return jnull();
			case GAMEOBJECT_TYPE_GENERIC: return jval(&t->_generic);
			case GAMEOBJECT_TYPE_TRAP: return jval(&t->trap);
			case GAMEOBJECT_TYPE_CHAIR: return jval(&t->chair);
			case GAMEOBJECT_TYPE_SPELL_FOCUS: return jval(&t->spellFocus);
			case GAMEOBJECT_TYPE_TEXT: return jval(&t->text);
			case GAMEOBJECT_TYPE_GOOBER: return jval(&t->goober);
			case GAMEOBJECT_TYPE_TRANSPORT: return jval(&t->transport);
			case GAMEOBJECT_TYPE_AREADAMAGE: return jval(&t->areadamage);
			case GAMEOBJECT_TYPE_CAMERA: return jval(&t->camera);
			// case GAMEOBJECT_TYPE_MAP_OBJECT: return jnull();
			case GAMEOBJECT_TYPE_MO_TRANSPORT: return jval(&t->moTransport);
			// case GAMEOBJECT_TYPE_DUEL_ARBITER: return jnull();
			// case GAMEOBJECT_TYPE_FISHINGNODE: return jnull();
			case GAMEOBJECT_TYPE_SUMMONING_RITUAL: return jval(&t->summoningRitual);
			// case GAMEOBJECT_TYPE_MAILBOX: return jnull();
			// case GAMEOBJECT_TYPE_DO_NOT_USE: return jnull();
			case GAMEOBJECT_TYPE_GUARDPOST: return jval(&t->guardpost);
			case GAMEOBJECT_TYPE_SPELLCASTER: return jval(&t->spellcaster);
			case GAMEOBJECT_TYPE_MEETINGSTONE: return jval(&t->meetingstone);
			case GAMEOBJECT_TYPE_FLAGSTAND: return jval(&t->flagstand);
			case GAMEOBJECT_TYPE_FISHINGHOLE: return jval(&t->fishinghole);
			case GAMEOBJECT_TYPE_FLAGDROP: return jval(&t->flagdrop);
			case GAMEOBJECT_TYPE_MINI_GAME: return jval(&t->miniGame);
			// case GAMEOBJECT_TYPE_DO_NOT_USE_2: return jnull();
			case GAMEOBJECT_TYPE_CAPTURE_POINT: return jval(&t->capturePoint);
			case GAMEOBJECT_TYPE_AURA_GENERATOR: return jval(&t->auraGenerator);
			case GAMEOBJECT_TYPE_DUNGEON_DIFFICULTY: return jval(&t->dungeonDifficulty);
			case GAMEOBJECT_TYPE_BARBER_CHAIR: return jval(&t->barberChair);
			case GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING: return jval(&t->building);
			// case GAMEOBJECT_TYPE_GUILD_BANK: return jnull();
			case GAMEOBJECT_TYPE_TRAPDOOR: return jval(&t->trapDoor);
			default: return jnull();
		}
	});

	return ft;
}
