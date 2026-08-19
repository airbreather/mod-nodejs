// Brother Danil <General Supplies>
const FIDDLED_VENDOR_ORIG = 152;
// just pick an unused NPC entry ID
const FIDDLED_VENDOR_NEW = 300000;

export function installVendorFiddle() {
	const orig = Acore.ObjectMgr.getNpcVendorItemList(FIDDLED_VENDOR_ORIG);
	if (!orig) {
		console.error('Expected NPC', FIDDLED_VENDOR_ORIG, 'to have a vendor list.');
		return;
	}
	const fiddled = orig.clone();
	// in the special menu, the vendor will sell item 19019. only one will be available at a time,
	// but it restocks every minute.
	fiddled.addItem(19019, 1, Temporal.Duration.from({ minutes: 1 }), 0);
	// false is "persist": we don't need this to stay in the DB, we can just recreate it every time
	Acore.ObjectMgr.setNpcVendorItemList(FIDDLED_VENDOR_NEW, fiddled, false);

	Acore.hooks.on('player:send-list-inventory', (args) => {
		const [highGuid, entry, _counter] = Acore.decodeGuid(args.vendorGuid);
		if (!(entry === FIDDLED_VENDOR_ORIG && highGuid === HighGuid.Unit)) {
			// we're not fiddling with the specific relevant vendor
			return;
		}

		const { player } = args;
		if (!(player.accountFlags & AccountFlag.ACCOUNT_FLAG_GM)) {
			// player doesn't have GM privileges
			return;
		}

		if (!/^T/.exec(player.name)) {
			// player name doesn't start with T
			return;
		}

		// all of the above checks passed, so send the secret vendor menu.
		args.vendorEntry = FIDDLED_VENDOR_NEW;
	});
}
