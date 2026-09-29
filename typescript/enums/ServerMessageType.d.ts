declare global {
	// ServerMessages.dbc
	const enum ServerMessageType {
		SERVER_MSG_SHUTDOWN_TIME      = 1,
		SERVER_MSG_RESTART_TIME       = 2,
		SERVER_MSG_STRING             = 3,
		SERVER_MSG_SHUTDOWN_CANCELLED = 4,
		SERVER_MSG_RESTART_CANCELLED  = 5,
	}
}
export {};
