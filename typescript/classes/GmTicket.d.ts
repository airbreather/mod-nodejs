declare global {
	namespace Acore {
		class GmTicket {
			readonly ticketId: number;
			readonly lastModifiedTime: Temporal.Instant;
			readonly escalatedStatus: GMTicketEscalationStatus;
			readonly playerName: string;
			readonly assignedGmName: string | undefined;
			readonly isClosed: boolean;
			readonly isCompleted: boolean;
			readonly isAssigned: boolean;
			readonly response: string;
			readonly chatLog: string;
			message: string;
			assignedToGuid: ObjectGuid | undefined;

			appendResponse(response: string): void;
			deleteResponse(): void;
			setViewed(): void;
			setCompleted(): void;
		}
	}
}
export {};
