declare global {
	const enum PlayerChatTag {
		CHAT_TAG_NONE       = 0x00,
		CHAT_TAG_AFK        = 0x01,
		CHAT_TAG_DND        = 0x02,
		CHAT_TAG_GM         = 0x04,
		CHAT_TAG_COM        = 0x08, // Commentator tag. Do not exist in clean client
		CHAT_TAG_DEV        = 0x10,
	}
}
export {};
