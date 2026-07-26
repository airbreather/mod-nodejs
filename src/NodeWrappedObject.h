#ifndef MOD_NODEJS_NODEWRAPPEDOBJECT_H
#define MOD_NODEJS_NODEWRAPPEDOBJECT_H

#include <v8-object.h>

void manage_void_pointer_with(v8::Local<v8::Object>, void *, void (*)(void *));
void reference_pointer_from(v8::Local<v8::Object>, void *);
void * extract_native_void_pointer_from(v8::Local<v8::Object>);

template <typename T>
requires std::is_pointer_v<T>
void manage_pointer_with(v8::Local<v8::Object> const obj, T wrapped) {
	using NonConstPointer = std::remove_const_t<std::remove_pointer_t<T>> *;
	manage_void_pointer_with(
		obj,
		std::is_same_v<T, NonConstPointer> ? wrapped : const_cast<NonConstPointer>(wrapped),
		[](void * ptr) { delete static_cast<T>(ptr); }
	);
}

template <typename T>
requires std::is_pointer_v<T>
T extract_native_pointer_from(v8::Local<v8::Object> const obj) {
	return static_cast<T>(extract_native_void_pointer_from(obj));
}

#endif //MOD_NODEJS_NODEWRAPPEDOBJECT_H
