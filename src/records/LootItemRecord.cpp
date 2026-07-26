#include <string>
#include <v8-local-handle.h>

#include "CtoJ.h"
#include "LootMgr.h"
#include "NodeJPropHelpers.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<LootItem const &>(LootItem const & li) {
	return jobj(
		jprop("itemid", li.itemid),
		jprop("index", li.itemIndex),
		jprop("count", li.count),
		jprop("needs_quest", li.needs_quest),
		jprop("is_looted", li.is_looted),
		jprop("randomSuffix", li.randomSuffix),
		jprop("randomPropertyId", li.randomPropertyId)
	);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<LootItem const>(LootItem const p) {
	return jval<LootItem const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<LootItem>(LootItem const p) {
	return jval<LootItem const &>(p);
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<LootItem *>(LootItem * p) {
	return p ? jval<LootItem const &>(*p) : jnull();
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<LootItem const *>(LootItem const * p) {
	return p ? jval<LootItem const &>(*p) : jnull();
}
