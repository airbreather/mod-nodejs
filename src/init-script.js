import {EventEmitter} from 'node:events';
import module from 'node:module';
import process from 'node:process';
import util from 'node:util';

// it's just so much more convenient to write some of this code in JavaScript.
export function finishInit(acore, addListenerCallback, removeListenerCallback) {
	acore.hooks = new EventEmitter().setMaxListeners(0);
	// TODO: this will probably go to the C++ side
	// just trying to wrap up this commit once I see it work.
	acore.normalizeLongLike = ll => {
		if (typeof ll == 'number') {
			return ll;
		}
		if (!globalThis.Long.isLong(ll)) {
			ll = globalThis.Long.fromValue(ll);
		}
		return ll.isSafeInteger()
			? ll.toNumber()
			: ll.toBigInt();
	};

	Object.freeze(acore);
	Object.seal(acore.hooks);

	acore.hooks.on('newListener', addListenerCallback);
	acore.hooks.on('removeListener', removeListenerCallback);

	globalThis.Acore = acore;

	process.on('unhandledRejection', (reason) => {
		globalThis.Acore.logError('module.nodejs', reason instanceof Error ? reason.stack : util.inspect(reason))
	});

	return module.createRequire(process.cwd());
}
