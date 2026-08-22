declare global {
	namespace Acore {
		class Channel {
			static byName(teamId: TeamId, name: string): Channel | undefined;

			constructor(name: string, channelId: number, channelDBId: number, teamId?: TeamId, announce?: boolean, ownership?: boolean);

			readonly name: string;
			readonly channelId: number;
			readonly channelDBId: number;
			readonly isConstant: boolean;
			readonly isAnnounce: boolean;
			readonly isLFG: boolean;
			readonly numPlayers: number;
			readonly flags: ChannelFlags;
			password: string;

			hasFlag(flag: ChannelFlags): boolean;
			joinChannel(player: Player, pass: string): void;
			leaveChannel(player: Player, send?: boolean): void;
			kick(player: Player, badName: string): void;
			ban(player: Player, badName: string): void;
			addBan(guid: ObjectGuid, time: Temporal.Instant): void;
			unBan(player: Player, badName: string): void;
			unBanById(guid: ObjectGuid): void;
			changePassword(player: Player, pass: string): void;
			setModerator(player: Player, newName: string): void;
			unsetModerator(player: Player, newName: string): void;
			setMute(player: Player, newName: string): void;
			unsetMute(player: Player, newName: string): void;
			list(player: Player): void;
			announce(player: Player): void;
			say(guid: ObjectGuid, what: string, lang: Language): void;
			invite(player: Player, newName: string): void;
			voice(guid1: ObjectGuid, guid2: ObjectGuid): void;
			deVoice(guid1: ObjectGuid, guid2: ObjectGuid): void;
			joinNotify(player: Player): void;
			leaveNotify(player: Player): void;
			flagsNotify(player: Player): void;
			toggleModeration(player: Player): void;
			addWatching(player: Player): void;
			removeWatching(player: Player): void;
		}
	}
}
export {};
