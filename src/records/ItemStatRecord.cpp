#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "ItemTemplate.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_ItemStat const &>(_ItemStat const & v) {
	return jobj(
		jprop("itemStatType", v.ItemStatType),
		jprop("itemStatValue", v.ItemStatValue)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_ItemStat const>(_ItemStat const v) {
	return jval<_ItemStat const &>(v);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_ItemStat>(_ItemStat const v) {
	return jval<_ItemStat const &>(v);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<_ItemStat const *>(_ItemStat const * v) {
	return v ? jval<_ItemStat const &>(*v) : jnull();
}
