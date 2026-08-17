/// <reference path="../typescript/index.d.ts" />
// ^ you probably ought to remove that line when copying to your own project. the intended way to
// get the types into your context is to install the @airbreather/mod-nodejs-types package. this is
// just so you can get type checking while browsing these example files in the source.
const DEFAULT_MAX = 5;
const ABSOLUTE_MAX = 50;

interface Accelerator {
	interval: ReturnType<typeof setInterval>;
	modified: boolean;
}
const allAccelerators = new Map<number, Accelerator>();

export function installRunSpeedCheat() {
	Acore.registerCommand(new Acore.ChatCommandBuilder('runfast')
		.withSecurityLevel(AccountTypes.SEC_GAMEMASTER)
		.withAllowConsole(false)
		.withHandler((h, arg) => {
			const player = h.player!; // should be safe because of withAllowConsole(false)
			const [_type, _entry, counter] = Acore.decodeGuid(player.guid);
			let max = arg.trim() ? Number(arg.trim()) : DEFAULT_MAX;
			if (max > ABSOLUTE_MAX) {
				max = ABSOLUTE_MAX;
			}

			const accelerator = allAccelerators.get(counter);
			if (accelerator) {
				clearInterval(accelerator.interval);
				if (accelerator.modified) {
					player.setSpeed(UnitMoveType.MOVE_RUN, 1, true);
					player.setSpeed(UnitMoveType.MOVE_SWIM, 1, true);
				}
				allAccelerators.delete(counter);
			}
			if (max > 1) {
				let speedup = 1;
				// only close over the GUID: the player object is freed when the player disconnects, so once
				// the synchronous part of your code ends, future handlers need to re-fetch and re-check.
				const guid = player.guid;
				const accelerator = {
					modified: false,
					interval: setInterval(() => {
						const player = Acore.Player.byGuid(guid);
						if (!player) {
							allAccelerators.delete(counter);
							clearInterval(accelerator.interval);
							return;
						}
						if (player.isMounted) {
							// if setSpeedRate were working, then this would be a different story. as it stands,
							// it's simplest just to let the mount's speed modification stuff win.
							speedup = 1;
							accelerator.modified = false;
							return;
						}

						if (player.hasUnitMovementFlag(MovementFlags.MOVEMENTFLAG_FORWARD)) {
							speedup = Math.min(speedup * 1.03, max);
						} else {
							speedup = Math.max(1, speedup * 0.95);
						}
						// TODO: why isn't setSpeedRate working? it's definitely setting the right flag.
						player.setSpeed(UnitMoveType.MOVE_RUN, speedup, true);
						player.setSpeed(UnitMoveType.MOVE_SWIM, speedup, true);
						accelerator.modified = speedup > 1;
					}, 400),
				};
				allAccelerators.set(counter, accelerator);
			}
			return true;
		}));
}
