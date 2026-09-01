export function installDevHelpers() {
	Acore.registerCommand(new Acore.ChatCommandBuilder('quest-ids')
		.withSecurityLevel(AccountTypes.SEC_PLAYER)
		.withAllowConsole(false)
		.withHandler((h) => {
			for (const id of h.player!.currentQuestIds) {
				const q = Acore.Quest.byId(id);
				h.sendSysMessageInline(`${q?.logTitle}: ${id}`);
			}
			return true;
		})
	);

	Acore.hooks.on('player:quest-accept', (args) => {
		if (!args.player.isBot) {
			args.player.sendSystemMessage(`${args.quest.logTitle}: ${args.quest.questId}`);
		}
	});

	Acore.hooks.on('player:before-quest-complete', (args) => {
		if (!args.player.isBot) {
			const q = Acore.Quest.byId(args.questId);
			args.player.sendSystemMessage(`${q?.logTitle}: ${args.questId}`);
		}
	});
}
