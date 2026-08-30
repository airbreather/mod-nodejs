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
			readGuid(): bigint | undefined;
			readPackedGuid(): bigint | undefined;

			writeByte(v: number): this;
			writeUByte(v: number): this;
			writeShort(v: number): this;
			writeUShort(v: number): this;
			writeLong(v: number): this;
			writeULong(v: number): this;
			writeFloat(v: number): this;
			writeDouble(v: number): this;
			writeString(v: string): this;
			writeGuidFrom(obj: ACObject): this;
			writeGuid(v: ObjectGuid | undefined): this;
			writePackedGuidFrom(obj: ACObject): this;
			writePackedGuid(v: ObjectGuid | undefined): this;
		}
	}
}
export {};
