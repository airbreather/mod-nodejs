export function installBagCheat() {
	Acore.hooks.on('player:first-login', (args) => {
		const PORTABLE_HOLE = 51809;
		args.player.storeNewItemInBestSlots(PORTABLE_HOLE, 4);
	});
}
