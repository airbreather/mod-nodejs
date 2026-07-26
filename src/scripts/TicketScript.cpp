#include "TicketScript.h"

#include <string>

#include "NodeJPropHelpers.h"
#include "NodeJs.h"

class NODEJS_Ticket : public TicketScript {
public:
	NODEJS_Ticket() : TicketScript("NODEJS_Ticket") {
	}

	void OnTicketCreate(GmTicket * ticket) override {
		NodeJs::invoke_hook("ticket:create", jarg("ticket", ticket));
	}
	void OnTicketUpdateLastChange(GmTicket * ticket) override {
		NodeJs::invoke_hook("ticket:update-last-change", jarg("ticket", ticket));
	}
	void OnTicketClose(GmTicket * ticket) override {
		NodeJs::invoke_hook("ticket:close", jarg("ticket", ticket));
	}
	void OnTicketStatusUpdate(GmTicket * ticket) override {
		NodeJs::invoke_hook("ticket:status-update", jarg("ticket", ticket));
	}
	void OnTicketResolve(GmTicket * ticket) override {
		NodeJs::invoke_hook("ticket:resolve", jarg("ticket", ticket));
	}
};

void AddSC_Ticket() {
	new NODEJS_Ticket();
}
