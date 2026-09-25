#ifndef MOD_NODEJS_NODEJOBJHELPERS_H
#define MOD_NODEJS_NODEJOBJHELPERS_H

#include <string>
#include <v8-local-handle.h>
#include <v8-persistent-handle.h>
#include <v8-value.h>

#include "CtoJ.h"
#include "JBox.h"

struct Prop {
	explicit Prop(std::string const & name_init) : name(name_init) {
	}

	virtual ~Prop() = default;

	std::string const & name;

	[[nodiscard]] virtual v8::Local<v8::Value> val() = 0;
};

template <typename T>
struct PropT : Prop {
	T data;

	PropT(std::string const & name_init, T data_init) : Prop(name_init), data(data_init) {
	}

	~PropT() override = default;

	[[nodiscard]] std::string const & get_name() const { return name; }
	[[nodiscard]] v8::Local<v8::Value> val() override { return jval(data); }
};

template <typename T>
struct PropMovingT : Prop {
	T & data;
	v8::Global<v8::Object> moved {};

	PropMovingT(std::string const & name_init, T & data_init) : Prop(name_init), data(data_init) {
	}

	~PropMovingT() override = default;

	[[nodiscard]] std::string const & get_name() const { return name; }
	[[nodiscard]] v8::Local<v8::Value> val() override {
		if (moved.IsEmpty()) {
			moved = v8::Global<v8::Object>(v8::Isolate::GetCurrent(), jmove<JBox *>(new JBoxT(data)));
		}
		return moved.Get(v8::Isolate::GetCurrent());
	}
};

template <typename T>
PropT<T> jprop(std::string const & name, T data) {
	return PropT<T>(name, data);
}

template <typename T>
PropMovingT<T> jprop_box(std::string const & name, T & data) {
	return PropMovingT<T>(name, data);
}

#endif //MOD_NODEJS_NODEJOBJHELPERS_H
