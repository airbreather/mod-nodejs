#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "Object.h"
#include "ObjectGuid.h"

JVAL_CVAL_TMPLS_RW(Object)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<Object *>() {
	TypedTemplate<Object *> const ft = jctor();

	ft->SetClassName(jstr_intern("ACObject"));

	reg_prop_ro(ft, "typeID", [](Object * obj) {
		return obj->GetTypeId();
	});
	reg_prop_ro(ft, "entry", [](Object * obj) {
		return obj->GetEntry();
	});
	reg_prop_ro(ft, "guid", [](Object * obj) {
		return obj->GetGUID();
	});
	reg_prop_ro(ft, "guidCounter", [](Object * obj) {
		return obj->GetGUID().GetCounter();
	});
	reg_prop_ro(ft, "isPlayer", [](Object * obj) {
		return obj->GetTypeId() == TYPEID_PLAYER;
	});
	reg_prop_ro(ft, "isInWorld", [](Object * obj) {
		return obj->IsInWorld();
	});

	reg_method(ft, "hasFlag", [](Object * obj, uint16_t const field, uint32_t const flag) {
		return obj->HasFlag(field, flag);
	});
	reg_method(ft, "getInt32Value", [](Object * obj, uint16_t const field) {
		return obj->GetInt32Value(field);
	});
	reg_method(ft, "getUInt32Value", [](Object * obj, uint16_t const field) {
		return obj->GetUInt32Value(field);
	});
	reg_method(ft, "getFloatValue", [](Object * obj, uint16_t const field) {
		return obj->GetFloatValue(field);
	});
	reg_method(ft, "getByteValue", [](Object * obj, uint16_t const field, uint8_t const offset) {
		return obj->GetByteValue(field, offset);
	});
	reg_method(ft, "getUInt16Value", [](Object * obj, uint16_t const field, uint8_t const offset) {
		return obj->GetUInt16Value(field, offset);
	});
	reg_method(ft, "getInt16Value", [](Object * obj, uint16_t const field, uint8_t const offset) {
		// not a typo: AC has SetInt16Value, but no GetInt16Value. it's all the same to us.
		return obj->GetUInt16Value(field, offset);
	});
	reg_method(ft, "getUInt64Value", [](Object * obj, uint16_t const field) {
		return obj->GetUInt64Value(field);
	});

	reg_prop(ft, "scale",
		[](Object * obj) { return obj->GetObjectScale(); },
		[](Object * obj, float const val) { obj->SetObjectScale(val); }
	);

	reg_method(ft, "setFlag", [](Object * obj, uint16_t const field, uint32_t const flag) {
		obj->SetFlag(field, flag);
	});
	reg_method(ft, "removeFlag", [](Object * obj, uint16_t const field, uint32_t const flag) {
		obj->RemoveFlag(field, flag);
	});
	reg_method(ft, "setInt32Value", [](Object * obj, uint16_t const field, int32_t const v) {
		obj->SetInt32Value(field, v);
	});
	reg_method(ft, "setUInt32Value", [](Object * obj, uint16_t const field, uint32_t const v) {
		obj->SetUInt32Value(field, v);
	});
	reg_method(ft, "updateUInt32Value", [](Object * obj, uint16_t const field, uint32_t const v) {
		obj->UpdateUInt32Value(field, v);
	});
	reg_method(ft, "setFloatValue", [](Object * obj, uint16_t const field, float const v) {
		obj->SetFloatValue(field, v);
	});
	reg_method(ft, "setByteValue", [](Object * obj, uint16_t const field, uint8_t const offset, uint8_t const value) {
		obj->SetByteValue(field, offset, value);
	});
	reg_method(ft, "setUInt16Value", [](Object * obj, uint16_t const field, uint8_t const offset, uint16_t const value) {
		obj->SetUInt16Value(field, offset, value);
	});
	reg_method(ft, "setInt16Value", [](Object * obj, uint16_t const field, uint8_t const offset, int16_t const value) {
		obj->SetInt16Value(field, offset, value);
	});
	reg_method(ft, "setUInt64Value", [](Object * obj, uint16_t const field, uint64_t const value) {
		obj->SetUInt64Value(field, value);
	});

	return ft;
}
