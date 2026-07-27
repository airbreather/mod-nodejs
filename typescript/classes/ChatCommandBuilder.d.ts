declare global {
	namespace Acore {
		class ChatCommandBuilder {
			constructor(name: string);
			withSubcommand(cmd: ChatCommandBuilder): ChatCommandBuilder;
			withHandler(handler: (h: ChatHandler, args: string) => boolean): ChatCommandBuilder;
			withSecurityLevel(sec: AccountTypes): ChatCommandBuilder;
			withAllowConsole(allow: boolean): ChatCommandBuilder;
			withHelp(help: AcoreStrings): ChatCommandBuilder;
		}
	}
}
export {};
