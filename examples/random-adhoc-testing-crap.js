// this is just some random crap the developer was using for testing this as he was building it out.
// a lot of it makes no sense, but it exists.

let numberOfGuys = 0;

const asyncQueryStuff = async () => {
	const b4 = Date.now();
	const creatures = await Acore.worldDbQueryAsync(`
		SELECT * FROM creature_template;
	`);
	const afa = Date.now();
	if (!creatures) {
		console.log('null??');
		return;
	}
	const b4_2 = Date.now();
	const { rowCount, fieldCount, allFields } = creatures;
	numberOfGuys = rowCount;
	if (rowCount === 0) {
		console.log('no rows');
		return;
	}
	console.log('took', afa - b4, 'ms to fetch', rowCount, 'row(s) with', fieldCount, 'field(s) each');
	const relevantOnes = [];
	let entryField;
	for (let i = 0; i < fieldCount; i++) {
		if (allFields[i].typ === 9) {
			relevantOnes.push([allFields[i], creatures.getFieldName(i)]);
		} else if (!entryField && creatures.getFieldName(i) === 'entry') {
			entryField = allFields[i];
		}
	}
	if (!entryField) {
		throw new Error('did not find the field for "entry"');
	}
	const b4_3 = Date.now();
	for (let i = 0; i < rowCount; i++) {
		let logged = false;
		for (const [field, name] of relevantOnes) {
			const fv = field.getString();
			if (fv.match(/^The /)) {
				if (!logged) {
					console.log(`===ENTRY: ${entryField.getString()}===`);
					logged = true;
				}

				console.log(name, '=', fv);
			}
		}
		creatures.nextRow();
	}
	const afa2 = Date.now();
	console.log('took', afa2 - b4_2, 'ms to process all of that client-side,', b4_3 - b4_2, 'of which were spent with field metadata stuff.');
};

Acore.hooks.on('nodejs:startup', async ({ persistData }) => {
	console.log('numberOfGuys before:', numberOfGuys);
	if (persistData) {
		numberOfGuys = JSON.parse(persistData).numberOfGuys;
	} else {
		await asyncQueryStuff();
	}
	console.log('numberOfGuys after:', numberOfGuys);
	const mail = new Acore.MailDraft("Hi Joe", persistData
		? `I know I keep spamming you every time you reload, but this is fun for me. Here's something to make up for it...`
		: `This is the first time I'm mailing you this session, so I feel OK about it. Pay up.`
	);
	if (persistData) {
		mail.addMoney(10000);
	} else {
		mail.createAndAddItem(19019);
		mail.addCOD(30000);
	}
	const sender = Acore.MailSender.forPlayer([0, 0, 1], 41);
	mail.send([0, 0, 1], sender);
	Acore.logInfo('module.nodejs', 'sent mail!');
});

Acore.hooks.on('nodejs:before-shutdown', async (args) => {
	if (args.reloading) {
		console.log('persisting numberOfGuys:', numberOfGuys);
		args.persistData = JSON.stringify({ numberOfGuys });
	} else {
		console.log('not bothering to persist numberOfGuys, because we are not reloading.');
	}
});

Acore.hooks.on('player:before-send-chat-message', args => {
	const { player, type, lang, msg } = args;
	if (player.isBot) {
		return;
	}
	if (type !== 1) {
		return;
	}
	if (msg.match(/follow that car!/)) {
		if (player.selectedUnit) {
			if (Acore.guidsEqual(player.selectedUnit.guid, player.guid)) {
				args.msg = 'I sure am a weirdo, trying to follow myself.';
			} else {
				player.moveFollow(player.selectedUnit);
				args.msg = '';
			}
		} else {
			args.msg = 'I tried to follow a unit without targeting anything, thus making me the fool.';
		}
		return;
	}
	if (msg.match(/car that follow!/)) {
		if (player.selectedUnit) {
			if (Acore.guidsEqual(player.selectedUnit.guid, player.guid)) {
				args.msg = 'I sure am a weirdo, trying to follow myself.';
			} else {
				player.selectedUnit.moveFollow(player);
				args.msg = '';
			}
		} else {
			args.msg = 'I tried to have a unit follow me without targeting anything, thus making me the fool.';
		}
		return;
	}
	if (msg.match(/ok thats enough/)) {
		player.moveExpire();
		args.msg = '';
		return;
	}

	if (msg.match(/enough thats ok/)) {
		player.selectedUnit?.moveExpire();
		args.msg = '';
		return;
	}

	const lvl = Number(msg.match(/set my level to (?<lvl>\d+)$/)?.groups?.lvl);
	if (lvl < 1) {
		args.msg = `I am a really bad cheater because even when I can set my level to anything I want, I only try to set it to ${lvl} which is impossible.`;
	} else if (lvl > 80) {
		args.msg = `I am a very ambitious cheater who just tried to set his level to ${lvl}, which is way too high lol.`;
	} else if (lvl) {
		args.lang = 0;
		const oldLevel = player.level;
		player.level = lvl;
		if (lvl < oldLevel) {
			args.msg = `I am a glutton for punishment who just removed ${oldLevel - lvl} level${oldLevel - lvl === 1 ? '' : 's'} from myself, bringing me from level ${oldLevel} to level ${lvl}.`;
		} else if (lvl === oldLevel) {
			args.msg = 'I like to waste time by trying to set my level to its current value.';
		} else {
			args.msg = `I am a filthy cheater who just gave myself ${lvl - oldLevel} level${lvl - oldLevel === 1 ? '' : 's'}, bringing me from level ${oldLevel} to level ${lvl}.`;
		}
	}
});

Acore.hooks.on('player:complete-quest', ({ player, quest }) => {
	if (player.isBot) {
		return;
	}
	console.log(player.name, 'completed quest:', JSON.stringify(quest));
});

Acore.hooks.on('battleground-queue:update-validity', (args) => {
	console.log('queue update validity:', JSON.stringify(args));
	const { queue, diff, bgTypeId, bracketId, arenaType, isRated, arenaRating } = args;
});
