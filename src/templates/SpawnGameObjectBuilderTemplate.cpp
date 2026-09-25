#include "NodePropertySystem.h"
#include "SpawnGameObjectBuilder.h"

JVAL_CVAL_TMPLS_RW(SpawnGameObjectBuilder)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<SpawnGameObjectBuilder *>() {
	TypedTemplate<SpawnGameObjectBuilder *> const ft = jctor<SpawnGameObjectBuilder *>();

	ft->SetClassName(jstr_intern("SpawnGameObjectBuilder"));

	reg_method(ft, "spawn", [](SpawnGameObjectBuilder * b) {
		return b->spawn();
	});
	reg_method(ft, "setPhaseMask", [](SpawnGameObjectBuilder * b, uint32_t phase_mask) {
		b->phase_mask = phase_mask;
		return b;
	});
	reg_method(ft, "setRotation", [](SpawnGameObjectBuilder * b, float x, float y, float z, float w) {
		b->rotation = { x, y, z, w };
		return b;
	});
	reg_method(ft, "setRotationByZAxisAngle", [](SpawnGameObjectBuilder * b, float rotation) {
		b->rotation = G3D::Quat::fromAxisAngleRotation(G3D::Vector3::unitZ(), rotation);
		return b;
	});
	reg_method(ft, "setAnimationProgress", [](SpawnGameObjectBuilder * b, uint32_t animation_progress) {
		b->animation_progress = animation_progress;
		return b;
	});
	reg_method(ft, "setState", [](SpawnGameObjectBuilder * b, GOState state) {
		b->state = state;
		return b;
	});

	return ft;
}
