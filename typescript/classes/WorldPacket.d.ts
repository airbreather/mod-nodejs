declare global {
	namespace Acore {
		class WorldPacket extends ByteBuffer {
			constructor(opcode?: number, sizeToReserve?: number);

			opcode: number;
		}
	}
}
export {};
