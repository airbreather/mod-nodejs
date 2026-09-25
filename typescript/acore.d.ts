import { EventEmitter } from 'node:events';

type ToGlobalHooks<Prefix extends string, Hooks extends object> = {
	[K in (keyof Hooks & string) as `${Prefix}:${K}`]: Hooks[K];
};

type ObjToHookArgs<T extends object> = {
	[K in keyof T]: [T[K]];
};

declare global {
	type Hooks =
		& GlobalHooks
		& ToGlobalHooks<'player', PlayerHooks>
		;
	namespace Acore {
		const hooks: EventEmitter<ObjToHookArgs<Hooks>>;

		function gc(): void;
		function guidsEqual(a: ObjectGuid | undefined, b: ObjectGuid | undefined): boolean;
		function decodeGuid(g: ObjectGuid | undefined): ObjectGuidDecoded;
		function getCurrTime(): Temporal.Instant;
		function getTimeDiff(before: Temporal.Instant): Temporal.Duration;
		function isGameEventActive(id: number): boolean;
		function dbQuery(db: Db, q: string): MaybeQueryResult;
		function dbQueryAsync(db: Db, q: string): Promise<MaybeQueryResult>;
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
		function playerHooksForGuid(guid: bigint): EventEmitter<ObjToHookArgs<PlayerHooks>>;
		function playerHooksForName(name: string): EventEmitter<ObjToHookArgs<PlayerHooks>>;
	}
}
