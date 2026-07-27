import Long from 'long';

declare global {
	namespace Acore {
		class Field {
			readonly typ: DatabaseFieldTypes;
			readonly isNull: boolean;

			asBool(): boolean;
			asU8(): number;
			asI8(): number;
			asU16(): number;
			asI16(): number;
			asU32(): number;
			asI32(): number;
			asU64(): Long;
			asI64(): Long;
			asF32(): number;
			asF64(): number;
			asString(): string;
			asBinary(): Uint8Array<ArrayBuffer>;
		}
	}
}
export {};
