import { EventEmitter } from 'node:events';

type HooksConforming = {
	[K in keyof Hooks]: [Hooks[K]];
};

declare global {
	namespace Acore {
		const hooks: EventEmitter<HooksConforming>;

		function gc(): void;
		function guidsEqual(a: ObjectGuid | undefined, b: ObjectGuid | undefined): boolean;
		function decodeGuid(g: ObjectGuid | undefined): ObjectGuidDecoded;
		function getCurrTime(): Temporal.Instant;
		function getTimeDiff(before: Temporal.Instant): Temporal.Duration;
		function isGameEventActive(id: number): boolean;
		function dbQuery(db: Db, q: string): QueryResult;
		function dbQueryAsync(db: Db, q: string): Promise<QueryResult>;
		function dbNonQuery(db: Db, q: string): void;
		function inTransaction(db: Db, f: () => void): void;
		function log(level: LogLevel, filter: string, msg: string): void;
		function logTrace(filter: string, msg: string): void;
		function logDebug(filter: string, msg: string): void;
		function logInfo(filter: string, msg: string): void;
		function logWarn(filter: string, msg: string): void;
		function logError(filter: string, msg: string): void;
		function logFatal(filter: string, msg: string): void;
		function runCommandAsync(cmd: string, flush?: boolean): Promise<boolean>;
		function saveAllPlayers(): void;
		function box<T>(val: T): Box<T>;
		function registerCommand(command: ChatCommandBuilder): void;
		function shutdown(time: number, optionsMask: ShutdownMask, exitCode: number, reason?: string): void;
		function hasPlayerbotsModule(): boolean;
	}
}
