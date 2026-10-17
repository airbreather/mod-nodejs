#include "CtoJ.h"
#include "DurationWrapper.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using AreaDamageData = decltype(GameObjectTemplate().areadamage);
JVAL_CVAL_TMPLS_RO(AreaDamageData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<AreaDamageData const *>() {
	TypedTemplate<AreaDamageData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("AreaDamageData"));

	reg_prop_ro(ft, "lockId", [](AreaDamageData const * d) {
		return d->lockId;
	});
	reg_prop_ro(ft, "radius", [](AreaDamageData const * d) {
		return d->radius;
	});
	reg_prop_ro(ft, "damageMin", [](AreaDamageData const * d) {
		return d->damageMin;
	});
	reg_prop_ro(ft, "damageMax", [](AreaDamageData const * d) {
		return d->damageMax;
	});
	reg_prop_ro(ft, "damageSchool", [](AreaDamageData const * d) {
		return d->damageSchool;
	});
	reg_prop_ro(ft, "autoCloseTime", [](AreaDamageData const * d) {
		return DurationWrapper::from_milliseconds(d->autoCloseTime);
	});
	reg_prop_ro(ft, "openTextId", [](AreaDamageData const * d) {
		return d->openTextID;
	});
	reg_prop_ro(ft, "closeTextId", [](AreaDamageData const * d) {
		return d->closeTextID;
	});

	return ft;
}
