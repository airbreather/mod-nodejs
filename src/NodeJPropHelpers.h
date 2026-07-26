#ifndef MOD_NODEJS_NODEJOBJHELPERS_H
#define MOD_NODEJS_NODEJOBJHELPERS_H

#include <string>
#include <v8-isolate.h>
#include <v8-local-handle.h>
#include <v8-value.h>

#include "JtoC.h"

class WorldObject;

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
PropT<T> jprop(std::string const & name, T data) {
	return PropT<T>(name, data);
}

struct Arg : Prop {
	explicit Arg(std::string const & name_init) : Prop(name_init) {
	}

	virtual bool try_set_val(v8::Local<v8::Value>) { return false; }
};

template <typename T>
struct InArg : Arg {
	T src;

	InArg(std::string const & name_init, T src_init) : Arg(name_init), src(src_init) {
	}

	~InArg() override = default;

	[[nodiscard]] std::string const & get_name() const { return name; }
	[[nodiscard]] v8::Local<v8::Value> val() override {
		return jval(src);
	}
	bool try_set_val(v8::Local<v8::Value> const) override {
		return false;
	}
};

template <typename T>
InArg<T> jarg(std::string const & name, T data) {
	return InArg<T>(name, data);
}

template <typename T>
struct InOutArg : Arg {
	T & data;

	InOutArg(std::string const & name_init, T & data_init) : Arg(name_init), data(data_init) {
	}

	~InOutArg() override = default;

	[[nodiscard]] std::string const & get_name() const { return name; }
	[[nodiscard]] v8::Local<v8::Value> val() override { return jval(data); }
	bool try_set_val(v8::Local<v8::Value> const v) override {
		if (auto const converted = cval<T>(v)) {
			data = *converted;
			return true;
		}
		return false;
	}
};

template <typename T>
InOutArg<T> jarg_inout(std::string const & name, T & data) {
	return InOutArg<T>(name, data);
}

#endif //MOD_NODEJS_NODEJOBJHELPERS_H
