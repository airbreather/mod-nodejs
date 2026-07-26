#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "ThreatManager.h"

JVAL_CVAL_TMPLS_RW(ThreatReference)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<ThreatReference *>() {
	TypedTemplate<ThreatReference *> const ft = jctor();

	ft->SetClassName(jstr_intern("ThreatReference"));

	reg_prop_ro(ft, "owner", [](ThreatReference * tr) {
		return tr->GetOwner();
	});
	reg_prop_ro(ft, "victim", [](ThreatReference * tr) {
		return tr->GetVictim();
	});
	reg_prop_ro(ft, "threat", [](ThreatReference * tr) {
		return tr->GetThreat();
	});
	reg_prop_ro(ft, "onlineState", [](ThreatReference * tr) {
		return tr->GetOnlineState();
	});
	reg_prop_ro(ft, "isOnline", [](ThreatReference * tr) {
		return tr->IsOnline();
	});
	reg_prop_ro(ft, "isAvailable", [](ThreatReference * tr) {
		return tr->IsAvailable();
	});
	reg_prop_ro(ft, "isSuppressed", [](ThreatReference * tr) {
		return tr->IsSuppressed();
	});
	reg_prop_ro(ft, "isOffline", [](ThreatReference * tr) {
		return tr->IsOffline();
	});
	reg_prop_ro(ft, "tauntState", [](ThreatReference * tr) {
		return tr->GetTauntState();
	});
	reg_prop_ro(ft, "isTaunting", [](ThreatReference * tr) {
		return tr->IsTaunting();
	});
	reg_prop_ro(ft, "isDetaunted", [](ThreatReference * tr) {
		return tr->IsDetaunted();
	});

	reg_method(ft, "addThreat", [](ThreatReference * tr, float const amount) {
		tr->AddThreat(amount);
	});
	reg_method(ft, "scaleThreat", [](ThreatReference * tr, float const factor) {
		tr->ScaleThreat(factor);
	});
	reg_method(ft, "modifyThreatByPercent", [](ThreatReference * tr, int32_t const percent) {
		tr->ModifyThreatByPercent(percent);
	});
	reg_method(ft, "updateOffline", [](ThreatReference * tr) {
		tr->UpdateOffline();
	});
	reg_method(ft, "clearThreatAndDestroyThisObject", [](ThreatReference * tr) {
		tr->ClearThreat();
	});

	return ft;
}
