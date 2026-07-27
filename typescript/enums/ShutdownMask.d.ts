declare global {
	const enum ShutdownMask {
		SHUTDOWN_MASK_NONE  =   0, // invented for mod_nodejs; others just hardcode 0
		SHUTDOWN_MASK_RESTART = 1,
		SHUTDOWN_MASK_IDLE    = 2,
	}
}
export {};
