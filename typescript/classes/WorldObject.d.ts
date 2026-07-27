declare global {
	namespace Acore {
		class WorldObject extends ACObject {
			readonly mapId: number;
			readonly zoneId: number;
			readonly areaId: number;
			readonly phaseMask: number;
			readonly instanceId: number;
			readonly location: Position;
			readonly transport: Transport | undefined;
			readonly sightRange: number;
			name: string;

			getNearestPlayer(range: number): Player | undefined;
			getNearestCreature(range: number, entry?: number): Creature | undefined;
			getNearestGameObject(range: number, entry?: number): GameObject | undefined;
			getDistanceTo(target: WorldObject, only2d?: boolean, mustBeExact?: boolean): number;
			getSightRangeTo(target: WorldObject): number;
			getAngleTo(target: WorldObject): number;
			isWithinLoSTo(target: WorldObject): boolean;
			isWithinDistTo(target: WorldObject, dist: number, mustBeInSameMap?: boolean): boolean;
			isInSameMapAs(target: WorldObject): boolean;
			isWithinDist3d(x: number, y: number, z: number, dist: number): boolean;
			isWithinDist2d(x: number, y: number, dist: number): boolean;
			isInRangeTo(target: WorldObject, max: number, min?: number, only2d?: boolean): boolean;
			isInFrontOf(target: WorldObject): boolean;
			isInBackOf(target: WorldObject): boolean;
			getRelativePoint(range: number, deg: number): number;
			getNearObject(range: number): WorldObject | undefined;
			getPlayersInRange(range: number): Player[];
			getCreaturesInRange(range: number, entry?: number): Creature[];
			getGameObjectsInRange(range: number, entry?: number): GameObject[];
			getUnitsInRange(range: number): Unit[];
			getNearObjects(range: number, mask?: NearObjectsMask): WorldObject[];
			getNearObjects(range: number, mask?: NearObjectsMask): WorldObject[];
			sendMessageToSet(packet: WorldPacket, self: boolean): void;
			sendMessageToSetInRange(packet: WorldPacket, range: number): void;
			sendMessageToSetExceptPlayer(packet: WorldPacket, skippedReceiver: Player): void;
			playMusic(soundKitId: number, zoneWide?: boolean): void;
			playDirectSound(soundId: number): void;
			playDistanceSound(soundId: number): void;
			// TODO: this is how they're defined today, but I think I want to make a breaking change before documenting them
			// in a declaration file like this. if you're reading this and you are OK with having to update in a future
			// version, feel free to uncomment and use them as written...
			// summonGameObject(entry: number, x?: number, y?: number, z?: number, o?: number): GameObject | undefined;
			// spawnCreature(entry: number, x?: number, y?: number, z?: number, o?: number): Creature | undefined;
		}
	}
}
export {};
