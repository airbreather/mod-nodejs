#include "CtoJ.h"
#include "DurationWrapper.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using ButtonData = decltype(GameObjectTemplate().button);
JVAL_CVAL_TMPLS_RO(ButtonData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<ButtonData const *>() {
	TypedTemplate<ButtonData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("ButtonData"));

	reg_prop_ro(ft, "startOpen", [](ButtonData const * b) {
		return b->startOpen != 0;
	});
	reg_prop_ro(ft, "lockId", [](ButtonData const * b) {
		return b->lockId;
	});
	reg_prop_ro(ft, "autoCloseTime", [](ButtonData const * b) {
		return DurationWrapper::from_milliseconds(b->autoCloseTime);
	});
	reg_prop_ro(ft, "linkedTrap", [](ButtonData const * b) {
		return b->linkedTrap;
	});
	reg_prop_ro(ft, "noDamageImmune", [](ButtonData const * b) {
		return b->noDamageImmune != 0;
	});
	reg_prop_ro(ft, "large", [](ButtonData const * b) {
		return b->large != 0;
	});
	reg_prop_ro(ft, "openTextId", [](ButtonData const * b) {
		return b->openTextID;
	});
	reg_prop_ro(ft, "closeTextId", [](ButtonData const * b) {
		return b->closeTextID;
	});
	reg_prop_ro(ft, "losOk", [](ButtonData const * b) {
		return b->losOK != 0;
	});

	return ft;
}
