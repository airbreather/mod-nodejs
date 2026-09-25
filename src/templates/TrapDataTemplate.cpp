#include "CtoJ.h"
#include "DurationWrapper.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using TrapData = decltype(GameObjectTemplate().trap);
JVAL_CVAL_TMPLS_RO(TrapData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<TrapData const *>() {
	TypedTemplate<TrapData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("TrapData"));

	reg_prop_ro(ft, "lockId", [](TrapData const * t) {
		return t->lockId;
	});
	reg_prop_ro(ft, "level", [](TrapData const * t) {
		return t->level;
	});
	reg_prop_ro(ft, "diameter", [](TrapData const * t) {
		return t->diameter;
	});
	reg_prop_ro(ft, "spellId", [](TrapData const * t) {
		return t->spellId;
	});
	reg_prop_ro(ft, "type", [](TrapData const * t) {
		// 0 trap with no despawn after cast.
		// 1 trap despawns after cast.
		// 2 bomb casts on spawn.
		return t->type;
	});
	reg_prop_ro(ft, "cooldown", [](TrapData const * t) {
		return DurationWrapper::from_chrono(Seconds(t->cooldown));
	});
	reg_prop_ro(ft, "autoCloseTime", [](TrapData const * t) {
		// sometimes -1, but see:
		// https://github.com/azerothcore/azerothcore-wotlk/pull/26152#issuecomment-5763004153
		return DurationWrapper::from_milliseconds(t->autoCloseTime);
	});
	reg_prop_ro(ft, "startDelay", [](TrapData const * t) {
		return DurationWrapper::from_chrono(Seconds(t->startDelay));
	});
	reg_prop_ro(ft, "serverOnly", [](TrapData const * t) {
		// note: core DB values are all 0
		return t->serverOnly != 0;
	});
	reg_prop_ro(ft, "stealthed", [](TrapData const * t) {
		return t->stealthed != 0;
	});
	reg_prop_ro(ft, "large", [](TrapData const * t) {
		return t->large != 0;
	});
	reg_prop_ro(ft, "invisible", [](TrapData const * t) {
		return t->invisible != 0;
	});
	reg_prop_ro(ft, "openTextId", [](TrapData const * t) {
		return t->openTextID;
	});
	reg_prop_ro(ft, "closeTextId", [](TrapData const * t) {
		return t->closeTextID;
	});
	reg_prop_ro(ft, "ignoreTotems", [](TrapData const * t) {
		return t->ignoreTotems != 0;
	});

	return ft;
}
