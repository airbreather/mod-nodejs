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
		if (attacker.guid != args.victim.guid) {
			args.amount *= 10;
		}
	});
}
