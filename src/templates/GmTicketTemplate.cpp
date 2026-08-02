#include <string>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "CtoJ.h"
#include "NodePropertySystem.h"
#include "ObjectGuid.h"
#include "TicketMgr.h"
#include "UnixTimestamp.h"

JVAL_CVAL_TMPLS_RW(GmTicket)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<GmTicket *>() {
	TypedTemplate<GmTicket *> const ft = jctor();

	ft->SetClassName(jstr_intern("GmTicket"));

	reg_prop_ro(ft, "ticketId", [](GmTicket * ticket) {
		return ticket->GetId();
	});
	reg_prop_ro(ft, "lastModifiedTime", [](GmTicket * ticket) {
		return UnixTimestamp::from_chrono(Seconds{ticket->GetLastModifiedTime()});
	});
	reg_prop_ro(ft, "escalatedStatus", [](GmTicket * ticket) {
		return ticket->GetEscalatedStatus();
	});
	reg_prop_ro(ft, "playerName", [](GmTicket * ticket) {
		return ticket->GetPlayerName();
	});
	reg_prop_ro(ft, "assignedGmName", [](GmTicket * ticket) {
		auto name = ticket->GetAssignedToName();
		return name.empty() ? jstr(ticket->GetAssignedToName()) : jnull();
	});
	reg_prop_ro(ft, "isClosed", [](GmTicket * ticket) {
		return ticket->IsClosed();
	});
	reg_prop_ro(ft, "isCompleted", [](GmTicket * ticket) {
		return ticket->IsCompleted();
	});
	reg_prop_ro(ft, "isAssigned", [](GmTicket * ticket) {
		return ticket->IsAssigned();
	});
	reg_prop_ro(ft, "response", [](GmTicket * ticket) {
		return ticket->GetResponse();
	});
	reg_prop_ro(ft, "chatLog", [](GmTicket * ticket) {
		return ticket->GetChatLog();
	});

	reg_prop(ft, "message",
		[](GmTicket * ticket) { return ticket->GetMessage(); },
		[](GmTicket * ticket, std::string const message) { ticket->SetMessage(message); }
	);
	reg_prop(ft, "assignedToGuid",
		[](GmTicket * ticket) { return ticket->GetAssignedToGUID(); },
		[](GmTicket * ticket, ObjectGuid const guid) { ticket->SetAssignedTo(guid, false); }
	);

	reg_method(ft, "appendResponse", [](GmTicket * ticket, std::string const response) {
		ticket->AppendResponse(response);
	});
	reg_method(ft, "deleteResponse", [](GmTicket * ticket) {
		ticket->DeleteResponse();
	});
	reg_method(ft, "setViewed", [](GmTicket * ticket) {
		ticket->SetViewed();
	});
	reg_method(ft, "setCompleted", [](GmTicket * ticket) {
		ticket->SetCompleted();
	});

	return ft;
}
