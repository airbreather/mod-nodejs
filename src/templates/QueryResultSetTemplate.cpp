#include <optional>
#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "Player.h"
#include "QueryResult.h"

JVAL_CVAL_TMPLS_RW(QueryResult)

template<>
v8::Local<v8::Value> jval<QueryResult>(QueryResult r) {
	return jmove(new QueryResult{std::move(r)});
}

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<QueryResult *>() {
	TypedTemplate<QueryResult *> const ft = jctor<QueryResult *>();

	ft->SetClassName(jstr_intern("QueryResult"));

	reg_prop_ro(ft, "rowCount", [](QueryResult * r) {
		return r->get()->GetRowCount();
	});
	reg_prop_ro(ft, "fieldCount", [](QueryResult * r) {
		return r->get()->GetFieldCount();
	});
	reg_prop_ro(ft, "allFields", [](QueryResult * r) {
		auto const isolate = v8::Isolate::GetCurrent();
		auto const ctx = isolate->GetCurrentContext();
		auto const cnt = r->get()->GetFieldCount();
		auto const arr = v8::Array::New(isolate, cnt);
		Field const * p = r->get()->Fetch();
		for (uint32_t i = 0; i < cnt; i++) {
			arr->Set(ctx, i, jval(p + i)).Check();
		}
		return arr.As<v8::Value>();
	});

	reg_method(ft, "getFieldName", [](QueryResult * r, uint32_t const i) {
		return r->get()->GetFieldName(i);
	});
	reg_method(ft, "getField", [](QueryResult * r, uint32_t const i) {
		return &(*r->get())[i];
	});

	reg_method(ft, "nextRow", [](QueryResult * r) {
		return r->get()->NextRow();
	});

	return ft;
}
