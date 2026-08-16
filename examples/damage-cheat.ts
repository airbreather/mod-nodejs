export function installDamageCheat() {
	Acore.hooks.on('unit:damage', (args) => {
		const attacker = args.attacker;
		if (!attacker) {
			return;
		}
		const byPlayer = attacker.isPlayer || attacker.owner?.isPlayer;
		if (!byPlayer) {
			return;
		}
		const player = (attacker.isPlayer ? attacker : attacker.owner) as Acore.Player;
		if (!player.isBot) {
			args.amount *= 10;
		}
	});
}
