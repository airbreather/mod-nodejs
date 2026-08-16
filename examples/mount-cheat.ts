const isNormalPlayer = (obj: Acore.ACObject): obj is (Acore.Player & { isBot: false }) => {
	return obj.isPlayer && !(obj as Acore.Player).isBot;
};

// usage:
/*
installMountCheat({
	groundMountId: 26656,   // ground-only mount is the scarab lord mount
	flyingMountId: 48025,   // flying mount is the headless horseman mount
	groundMountSpeedup: 5,  // these two mounts are "400% mounts" on the ground (5x speedup)
	flyingMountSpeedup: 10, // the flying mount is a "900% mount" when flying (10x speedup)
});
*/

export interface MountCustomizations {
	groundMountId: number;
	flyingMountId: number;
	groundMountSpeedup: number;
	flyingMountSpeedup: number;
}

export function installMountCheat(options: MountCustomizations) {
	Acore.hooks.on('unit:aura-apply', checkForCustomizedMount(options));
	Acore.registerCommand(new Acore.ChatCommandBuilder('grant-custom-mounts')
		.withSecurityLevel(AccountTypes.SEC_GAMEMASTER)
		.withAllowConsole(false)
		.withHandler((h) => {
			h.player?.learnSpell(options.groundMountId);
			h.player?.learnSpell(options.flyingMountId);
			return true;
		})
	);
}

function checkForCustomizedMount(options: MountCustomizations): ((args: Hooks['unit:aura-apply']) => void) {
	const { groundMountId, flyingMountId, groundMountSpeedup, flyingMountSpeedup } = options;
	return (args) => {
		const unit = args.unit;
		if (!isNormalPlayer(unit)) {
			return;
		}
		const spellId = args.aura.spellId;
		switch (spellId) {
			case flyingMountId:
			case groundMountId:
				break;
			default:
				return;
		}
		Acore.hooks.once('world:update-early', () => {
			switch (spellId) {
				case flyingMountId:
					// ordinarily, dismounting would set you back to normal speeds. for ground mounts
					// and flying mounts where the game would normally let you fly, it does. but in the
					// majority of expected cases where someone uses this to fly elsewhere, those flags
					// stay at whatever they otherwise would have been, and the "can fly?" flags don't
					// change at all in either direction. so we need a bit more babysitting.
					const oldFlightSpeed = unit.getSpeed(UnitMoveType.MOVE_FLIGHT);
					unit.setSpeed(UnitMoveType.MOVE_FLIGHT, flyingMountSpeedup, true);
					unit.canFly = true;
					const playerGuid = unit.guid;
					const clearSpeedFunc = (args: Hooks['unit:aura-remove']) => {
						const unit = args.unit;
						if (!(isNormalPlayer(unit) && Acore.guidsEqual(unit.guid, playerGuid))) {
							return;
						}
						const { aurApp } = args;
						if (aurApp.base.spellId === flyingMountId) {
							Acore.hooks.off('unit:aura-remove', clearSpeedFunc);
							unit.canFly = false;
							unit.setSpeed(UnitMoveType.MOVE_FLIGHT, oldFlightSpeed, true);
						}
					};
					Acore.hooks.on('unit:aura-remove', clearSpeedFunc);
				// noinspection FallThroughInSwitchStatementJS
				case groundMountId:
					unit.setSpeed(UnitMoveType.MOVE_RUN, groundMountSpeedup, true);
					// no need for an explicit clear here
					break;
			}
		});
	}
}
