#include "CtoJ.h"
#include "DurationWrapper.h"
#include "GameObject.h"
#include "NodePropertySystem.h"

using DoorData = decltype(GameObjectTemplate().door);
JVAL_CVAL_TMPLS_RO(DoorData const)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<DoorData const *>() {
	TypedTemplate<DoorData const *> const ft = jctor();

	ft->SetClassName(jstr_intern("DoorData"));

	reg_prop_ro(ft, "startOpen", [](DoorData const * d) {
		return d->startOpen != 0;
	});
	reg_prop_ro(ft, "lockId", [](DoorData const * d) {
		return d->lockId;
	});
	reg_prop_ro(ft, "autoCloseTime", [](DoorData const * d) {
		return DurationWrapper::from_milliseconds(d->autoCloseTime);
	});
	reg_prop_ro(ft, "noDamageImmune", [](DoorData const * d) {
		return d->noDamageImmune != 0;
	});
	reg_prop_ro(ft, "openTextId", [](DoorData const * d) {
		return d->openTextID;
	});
	reg_prop_ro(ft, "closeTextId", [](DoorData const * d) {
		return d->closeTextID;
	});
	reg_prop_ro(ft, "ignoredByPathing", [](DoorData const * d) {
		// the only caller in core uses it as a bool, but the database has all of -1, 0, and 1.
		// the -1 is very interesting: columns Data1 and Data6 in the database are the only two
		// that are "int" instead of "int unsigned", but ignoredByPathing is uint32_t regardless.
		return static_cast<int32_t>(d->ignoredByPathing);
	});

	return ft;
}
