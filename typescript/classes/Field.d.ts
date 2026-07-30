declare global {
	namespace Acore {
		class Field {
			readonly fieldType: DatabaseFieldTypes;
			readonly isNull: boolean;

			getBool(): boolean;
			getU8(): number;
			getI8(): number;
			getU16(): number;
			getI16(): number;
			getU32(): number;
			getI32(): number;
			getU64(): number | bigint;
			getI64(): number | bigint;
			getF32(): number;
			getF64(): number;
			getString(): string;
			getBinary(): Uint8Array<ArrayBuffer>;
		}
	}
}
export {};
