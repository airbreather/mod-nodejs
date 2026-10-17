#ifndef MOD_NODEJS_NODEJPROPHELPERS_H
#define MOD_NODEJS_NODEJPROPHELPERS_H

#include <string>
#include <v8-local-handle.h>
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

	[[nodiscard]] v8::Local<v8::Value> val() override { return jval(data); }
};

template <typename T>
struct PropTBox : Prop {
	JBoxT<T> box;

	PropTBox(std::string const & name_init, T & ref) : Prop(name_init), box(ref) {
	}

	~PropTBox() override = default;

	// known issue: undefined behavior if JavaScript captures this box and uses it after the
	// synchronous portion of some routine has completed and this goes out of scope. this isn't
	// completely unique to mod-nodejs since any other module can also misuse exactly the same stuff
	// in exactly the same way, but whereas it would be extremely obvious if C++ code made this
	// mistake, all it takes for the JavaScript equivalent to hit this would be to try to use it
	// after an await. it's technically *possible* to fully eliminate this issue ("just" block the
	// thread and keep pumping the libuv event loop until the method finishes executing). there are
	// more reasonable solutions, though, than either extreme of:
	// - merely trying to accessing the value at the "wrong" time triggers UB, which is something JS
	//   developers absolutely are not used to having to worry about, or
	// - sync-over-async blocking (potentially indefinitely) for the most faithful possible behavior
	// for example, it probably wouldn't be *terribly* much effort to replace "JBox *" with a smart
	// pointer when making the template instead, where we can see if the underlying JBox has already
	// been destroyed before we try to dereference it and just throw a regular error instead of UB.
	// I'm not seeing immediately how to orchestrate shared_ptr + weak_ptr to make that work, so I'm
	// leaving it as a TODO for now, but those do seem to be the primitives that it would need.
	[[nodiscard]] v8::Local<v8::Value> val() override { return jval<JBox *>(&box); }
};

template <typename T>
PropT<T> jprop(std::string const & name, T data) {
	return PropT<T>(name, data);
}

template <typename T>
PropTBox<T> jprop_box(std::string const & name, T & data) {
	return PropTBox<T>(name, data);
}

#endif //MOD_NODEJS_NODEJPROPHELPERS_H
