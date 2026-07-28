declare global {
	namespace Acore {
		class ByteBuffer {
			readonly size: number;

			readByte(): number;
			readUByte(): number;
			readShort(): number;
			readUShort(): number;
			readLong(): number;
			readULong(): number;
			readFloat(): number;
			readDouble(): number;
			readString(): string;
			readGuid(): ObjectGuidNative;
			readPackedGuid(): ObjectGuidNative;

			writeByte(v: number): void;
			writeUByte(v: number): void;
			writeShort(v: number): void;
			writeUShort(v: number): void;
			writeLong(v: number): void;
			writeULong(v: number): void;
			writeFloat(v: number): void;
			writeDouble(v: number): void;
			writeString(v: string): void;
			writeGuidFrom(obj: ACObject): void;
			writeGuid(v: ObjectGuid): void;
			writePackedGuidFrom(obj: ACObject): void;
			writePackedGuid(v: ObjectGuid): void;
		}
	}
}
export {};
