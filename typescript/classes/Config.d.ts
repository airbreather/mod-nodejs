declare global {
	namespace Acore {
		class Config {
			static getArguments(): string[];
			static getConfigPath(): string;
			static getFilename(): string;
			static getKeysStartingWith(prefix: string): string[];
			static getBool(key: string, def?: boolean, showLogs?: boolean): boolean;
			static getString(key: string, def?: string, showLogs?: boolean): string;
			static getFloat(key: string, def?: number, showLogs?: boolean): number;
			static getU8(key: string, def?: number, showLogs?: boolean): number;
			static getI8(key: string, def?: number, showLogs?: boolean): number;
			static getU16(key: string, def?: number, showLogs?: boolean): number;
			static getI16(key: string, def?: number, showLogs?: boolean): number;
			static getU32(key: string, def?: number, showLogs?: boolean): number;
			static getI32(key: string, def?: number, showLogs?: boolean): number;
			static getU64(key: string, def?: number | bigint, showLogs?: boolean): number | bigint;
			static getI64(key: string, def?: number | bigint, showLogs?: boolean): number | bigint;
		}
	}
}
export {};
