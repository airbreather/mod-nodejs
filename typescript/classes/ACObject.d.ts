declare global {
	namespace Acore {
		class ACObject {
			readonly typeID: TypeId;
			readonly entry: number;
			readonly guid: ObjectGuidNative;
			readonly guidCounter: number;
			readonly isPlayer: boolean;
			readonly isInWorld: boolean;
			scale: number;

			hasFlag(field: number, flag: number): boolean;
			getInt32Value(field: number): number;
			getUInt32Value(field: number): number;
			getFloatValue(field: number): number;
			getByteValue(field: number, offset: 0 | 1 | 2 | 3): number;
			getUInt16Value(field: number, offset: 0 | 1): number;
			getInt16Value(field: number, offset: 0 | 1): number;
			getUInt64Value(field: number): number | bigint;

			setFlag(field: number, flag: number): void;
			removeFlag(field: number, flag: number): void;
			setInt32Value(field: number, value: number): void;
			setUInt32Value(field: number, value: number): void;
			updateUInt32Value(field: number, value: number): void;
			setFloatValue(field: number, value: number): void;
			setByteValue(field: number, offset: 0 | 1 | 2 | 3, value: number): void;
			setUInt16Value(field: number, offset: 0 | 1, value: number): void;
			setInt16Value(field: number, offset: 0 | 1, value: number): void;
			setUInt64Value(field: number, value: number | bigint): void;
		}
	}
}
export {};
