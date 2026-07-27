import Long from 'long';
import { EventEmitter } from 'node:events';

type HooksConforming = {
	[K in keyof Hooks]: [Hooks[K]];
};

declare global {
	type LongLike =
		| Long
		| number
		| bigint
		| string
		| { low: number; high: number; unsigned: boolean };

	namespace Acore {
		const hooks: EventEmitter<HooksConforming>;

		function gc(): void;
		function guidsEqual(a: ObjectGuid | undefined, b: ObjectGuid | undefined): boolean;
		function decodeGuid(g: ObjectGuid | undefined): ObjectGuidDecoded;
		function getCurrTime(): number;
		function getTimeDiff(ms: number): number;
		function isGameEventActive(id: number): boolean;
		function worldDbQueryAsync(q: string): Promise<QueryResult>;
		function loginDbQueryAsync(q: string): Promise<QueryResult>;
		function characterDbQueryAsync(q: string): Promise<QueryResult>;
		function worldDbQuery(q: string): QueryResult;
		function loginDbQuery(q: string): QueryResult;
		function characterDbQuery(q: string): QueryResult;
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
	}
}
