#include "NodeWrappedObject.h"

#include <node_object_wrap.h>
#include <stdexcept>
#include <v8-object.h>

namespace {
class NotOurTemplatedObjectError : public std::logic_error {
public:
	explicit NotOurTemplatedObjectError()
		: std::logic_error("The object was not created by one of our templates - i.e., it has fewer than 2 internal fields.") {
	}
};

// node::ObjectWrap is deprecated in vNext, but it's EXACTLY what we need.
// https://github.com/nodejs/node/pull/63756#issuecomment-4883149032
class WrappedObject : public node::ObjectWrap {
	void * m_wrapped;
	void (* m_destroy)(void *);

public:
	WrappedObject(v8::Local<v8::Object> const wrapped_in, void * wrapped, void destroy(void *)) : m_wrapped(wrapped), m_destroy(destroy) {
		Wrap(wrapped_in);
	}

	~WrappedObject() override {
		(* m_destroy)(m_wrapped);
	}

	static void wrap_in(v8::Local<v8::Object> const obj, void * wrapped, void (* destroy)(void *)) {
		new WrappedObject(obj, wrapped, destroy);
	}

	static void * unwrap_from(v8::Local<v8::Object> const handle) {
		return Unwrap<WrappedObject>(handle)->m_wrapped;
	}
};
}

static void * const WRAPPED_OBJECT_SENTINEL = new bool(true);
static void * const REFERENCED_OBJECT_SENTINEL = new bool(false);

void manage_void_pointer_with(v8::Local<v8::Object> const obj, void * wrapped, void (* destroy)(void *)) {
	if (obj->InternalFieldCount() < 2) {
		throw NotOurTemplatedObjectError();
	}
	WrappedObject::wrap_in(obj, wrapped, destroy);
	obj->SetAlignedPointerInInternalField(1, WRAPPED_OBJECT_SENTINEL, v8::kEmbedderDataTypeTagDefault);
}

void reference_pointer_from(v8::Local<v8::Object> const obj, void * wrapped) {
	if (obj->InternalFieldCount() < 2) {
		throw NotOurTemplatedObjectError();
	}
	obj->SetAlignedPointerInInternalField(0, wrapped, v8::kEmbedderDataTypeTagDefault);
	obj->SetAlignedPointerInInternalField(1, REFERENCED_OBJECT_SENTINEL, v8::kEmbedderDataTypeTagDefault);
}

void * extract_native_void_pointer_from(v8::Local<v8::Object> const obj) {
	if (obj->InternalFieldCount() < 2) {
		throw NotOurTemplatedObjectError();
	}
	if (*static_cast<bool *>(obj->GetAlignedPointerFromInternalField(1, v8::kEmbedderDataTypeTagDefault))) {
		return WrappedObject::unwrap_from(obj);
	}
	return obj->GetAlignedPointerFromInternalField(0, v8::kEmbedderDataTypeTagDefault);
}
