#include "CtoJ.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using CameraData = decltype(GameObjectTemplate().camera);
JVAL_CVAL_TMPLS_RO(CameraData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<CameraData const *>() {
	TypedTemplate<CameraData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("CameraData"));

	reg_prop_ro(ft, "lockId", [](CameraData const * c) {
		return c->lockId;
	});
	reg_prop_ro(ft, "cinematicId", [](CameraData const * c) {
		return c->cinematicId;
	});
	reg_prop_ro(ft, "eventId", [](CameraData const * c) {
		return c->eventID;
	});
	reg_prop_ro(ft, "openTextId", [](CameraData const * c) {
		return c->openTextID;
	});

	return ft;
}
