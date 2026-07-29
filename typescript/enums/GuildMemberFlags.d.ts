declare global {
	const enum GuildMemberFlags {
		GUILDMEMBER_STATUS_NONE = 0x0000,
		GUILDMEMBER_STATUS_ONLINE = 0x0001,
		GUILDMEMBER_STATUS_AFK = 0x0002,
		GUILDMEMBER_STATUS_DND = 0x0004,
		GUILDMEMBER_STATUS_MOBILE = 0x0008, // remote chat from mobile app
	}
}
export {};
