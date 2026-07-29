#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "ByteBuffer.h"
#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "Object.h"
#include "ObjectGuid.h"

JVAL_CVAL_TMPLS_RW(ByteBuffer)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<ByteBuffer *>() {
	TypedTemplate<ByteBuffer *> const ft = jctor();

	ft->SetClassName(jstr_intern("ByteBuffer"));

	reg_prop_ro(ft, "size", [](ByteBuffer * bb) {
		return bb->size();
	});

	reg_method(ft, "readByte", [](ByteBuffer * buf) {
		int8_t v; *buf>>v; return v;
	});
	reg_method(ft, "readUByte", [](ByteBuffer * buf) {
		uint8_t v; *buf>>v; return v;
	});
	reg_method(ft, "readShort", [](ByteBuffer * buf) {
		int16_t v; *buf>>v; return v;
	});
	reg_method(ft, "readUShort", [](ByteBuffer * buf) {
		uint16_t v; *buf>>v; return v;
	});
	reg_method(ft, "readLong", [](ByteBuffer * buf) {
		int32_t v; *buf>>v; return v;
	});
	reg_method(ft, "readULong", [](ByteBuffer * buf) {
		uint32_t v; *buf>>v; return v;
	});
	reg_method(ft, "readFloat", [](ByteBuffer * buf) {
		float v; *buf>>v; return v;
	});
	reg_method(ft, "readDouble", [](ByteBuffer * buf) {
		double v; *buf>>v; return v;
	});
	reg_method(ft, "readString", [](ByteBuffer * buf) {
		std::string v; *buf>>v; return v;
	});
	reg_method(ft, "readGuid", [](ByteBuffer * buf) {
		ObjectGuid v; *buf>>v; return v;
	});
	reg_method(ft, "readPackedGuid", [](ByteBuffer * buf) {
		uint64_t v;
		buf->readPackGUID(v);
		return ObjectGuid(v);
	});

	reg_method(ft, "writeByte", [](ByteBuffer * buf, int8_t const v) {
		*buf<<v; return buf;
	});
	reg_method(ft, "writeUByte", [](ByteBuffer * buf, uint8_t const v) {
		*buf<<v; return buf;
	});
	reg_method(ft, "writeShort", [](ByteBuffer * buf, int16_t const v) {
		*buf<<v; return buf;
	});
	reg_method(ft, "writeUShort", [](ByteBuffer * buf, uint16_t const v) {
		*buf<<v; return buf;
	});
	reg_method(ft, "writeLong", [](ByteBuffer * buf, int32_t const v) {
		*buf<<v; return buf;
	});
	reg_method(ft, "writeULong", [](ByteBuffer * buf, uint32_t const v) {
		*buf<<v; return buf;
	});
	reg_method(ft, "writeFloat", [](ByteBuffer * buf, float const v) {
		*buf<<v; return buf;
	});
	reg_method(ft, "writeDouble", [](ByteBuffer * buf, double const v) {
		*buf<<v; return buf;
	});
	reg_method(ft, "writeString", [](ByteBuffer * buf, std::string v) {
		*buf<<v; return buf;
	});
	reg_method(ft, "writeGuidFrom", [](ByteBuffer * buf, Object const * obj) {
		*buf<<obj->GetGUID(); return buf;
	});
	reg_method(ft, "writeGuid", [](ByteBuffer * buf, ObjectGuid const guid) {
		*buf<<guid; return buf;
	});
	reg_method(ft, "writePackedGuidFrom", [](ByteBuffer * buf, Object const * obj) {
		*buf<<obj->GetPackGUID(); return buf;
	});
	reg_method(ft, "writePackedGuid", [](ByteBuffer * buf, ObjectGuid const guid) {
		*buf<<guid.WriteAsPacked(); return buf;
	});

	return ft;
}
