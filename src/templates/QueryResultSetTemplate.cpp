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
	auto const isolate = v8::Isolate::GetCurrent();
	// v8::External with just a single arg is how we detect that an object has an externally managed
	// lifetime. that's normally the case for things created from the C++ side, so it's usually just
	// a tool to let the script create GC-managed objects. this one's special because it's an object
	// that we need to survive across await boundaries, which effectively means that the script will
	// take ownership of it (instead of our usual stack-managed lifetime strategy) so this call will
	// look *ALMOST* the same as the default, just with an extra arg that makes the miracles happen.
	auto const arg = v8::External::New(isolate, new QueryResult(std::move(r)), v8::kEmbedderDataTypeTagDefault);
	return jnew<QueryResult *>(arg, 0);
}

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<QueryResult *>() {
	TypedTemplate<QueryResult *> const ft = jctor([](v8::Local<v8::External> v, int) -> QueryResult * {
		return static_cast<QueryResult *>(v->Value());
	});

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
