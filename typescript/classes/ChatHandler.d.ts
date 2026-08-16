declare global {
	namespace Acore {
		class ChatHandler {
			readonly player: Player | undefined;
			readonly selectedPlayer: Player | undefined;
			readonly selectedPlayerOrSelf: Player | undefined;
			readonly selectedCreature: Creature | undefined;
			readonly selectedUnit: Unit | undefined;
			readonly selectedObject: WorldObject | undefined;
			readonly isConsole: boolean;
			readonly hasSentErrorMessage: boolean;

			isAvailable(sec: AccountTypes): boolean;
			sendSysMessageStored(msg: number): void;
			sendSysMessageInline(msg: string): void;
			sendGlobalSysMessage(msg: string): void;
			sendGlobalGMSysMessage(msg: string): void;
			hasLowerSecurity(player: Player, guid?: ObjectGuid, strong?: boolean): boolean;
			hasLowerSecurityAccount(accountId: number, strong?: boolean): boolean;
		}
	}
}
export {};
