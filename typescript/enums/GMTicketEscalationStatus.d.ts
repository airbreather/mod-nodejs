declare global {
	// from Blizzard LUA:
	// GMTICKET_ASSIGNEDTOGM_STATUS_NOT_ASSIGNED      = 0;    -- ticket is not currently assigned to a gm
	// GMTICKET_ASSIGNEDTOGM_STATUS_ASSIGNED          = 1;    -- ticket is assigned to a normal gm
	// GMTICKET_ASSIGNEDTOGM_STATUS_ESCALATED         = 2;    -- ticket is in the escalation queue
	// 3 is a custom value and should never actually be sent
	const enum GMTicketEscalationStatus {
		TICKET_UNASSIGNED                             = 0,
		TICKET_ASSIGNED                               = 1,
		TICKET_IN_ESCALATION_QUEUE                    = 2,
		TICKET_ESCALATED_ASSIGNED                     = 3,
	}
}
export {};
