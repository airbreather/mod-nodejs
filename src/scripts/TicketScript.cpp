#include "TicketScript.h"

#include <string>

#include "NodeJs.h"

class NODEJS_Ticket : public TicketScript {
public:
	NODEJS_Ticket() : TicketScript("NODEJS_Ticket") {
	}

	void OnTicketCreate(GmTicket * ticket) override {
		NodeJs::invoke_hook("ticket:create"
			, jprop("ticket", ticket));
	}
	void OnTicketUpdateLastChange(GmTicket * ticket) override {
		NodeJs::invoke_hook("ticket:update-last-change"
			, jprop("ticket", ticket));
	}
	void OnTicketClose(GmTicket * ticket) override {
		NodeJs::invoke_hook("ticket:close"
			, jprop("ticket", ticket));
	}
	void OnTicketStatusUpdate(GmTicket * ticket) override {
		NodeJs::invoke_hook("ticket:status-update"
			, jprop("ticket", ticket));
	}
	void OnTicketResolve(GmTicket * ticket) override {
		NodeJs::invoke_hook("ticket:resolve"
			, jprop("ticket", ticket));
	}
};

void AddSC_Ticket() {
	new NODEJS_Ticket();
}
