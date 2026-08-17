/// <reference path="../typescript/index.d.ts" />
// ^ you probably ought to remove that line when copying to your own project. the intended way to
// get the types into your context is to install the @airbreather/mod-nodejs-types package. this is
// just so you can get type checking while browsing these example files in the source.
export function installBagCheat() {
	Acore.hooks.on('player:first-login', (args) => {
		const PORTABLE_HOLE = 51809;
		args.player.storeNewItemInBestSlots(PORTABLE_HOLE, 4);
	});
}
