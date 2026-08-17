/// <reference path="../typescript/index.d.ts" />
// ^ you probably ought to remove that line when copying to your own project. the intended way to
// get the types into your context is to install the @airbreather/mod-nodejs-types package. this is
// just so you can get type checking while browsing these example files in the source.
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
