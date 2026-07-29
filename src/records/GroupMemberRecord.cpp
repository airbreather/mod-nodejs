#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "Group.h"
#include "NodeJPropHelpers.h"
#include "ObjectGuid.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<Group::MemberSlot const &>(Group::MemberSlot const & p) {
	return jobj(
		jprop("guid", p.guid),
		jprop("name", p.name),
		jprop("roles", p.roles),
		jprop("flags", p.flags)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<Group::MemberSlot const>(Group::MemberSlot const p) {
	return jval<Group::MemberSlot const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<Group::MemberSlot>(Group::MemberSlot const p) {
	return jval<Group::MemberSlot const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<Group::MemberSlot const *>(Group::MemberSlot const * p) {
	return p ? jval<Group::MemberSlot const &>(*p) : jnull();
}
