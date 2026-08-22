declare global {
	const enum ChannelFlags {
		CHANNEL_FLAG_NONE       = 0x00,
		CHANNEL_FLAG_CUSTOM     = 0x01,
		// 0x02
		CHANNEL_FLAG_TRADE      = 0x04,
		CHANNEL_FLAG_NOT_LFG    = 0x08,
		CHANNEL_FLAG_GENERAL    = 0x10,
		CHANNEL_FLAG_CITY       = 0x20,
		CHANNEL_FLAG_LFG        = 0x40,
		CHANNEL_FLAG_VOICE      = 0x80,
		// General                  0x18 = 0x10 | 0x08
		// Trade                    0x3C = 0x20 | 0x10 | 0x08 | 0x04
		// LocalDefence             0x18 = 0x10 | 0x08
		// GuildRecruitment         0x38 = 0x20 | 0x10 | 0x08
		// LookingForGroup          0x50 = 0x40 | 0x10
	}
}
export {};
