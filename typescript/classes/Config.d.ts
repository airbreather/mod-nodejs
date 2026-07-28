import type Long from 'long';

declare global {
	namespace Acore {
		class Config {
			static getArguments(): string[];
			static getConfigPath(): string;
			static getFilename(): string;
			static getKeysStartingWith(): string[];
			static getBool(): boolean;
			static getString(): string;
			static getFloat(): number;
			static getU8(): number;
			static getI8(): number;
			static getU16(): number;
			static getI16(): number;
			static getU32(): number;
			static getI32(): number;
			static getU64(): number | Long;
			static getI64(): number | Long;
		}
	}
}
export {};
