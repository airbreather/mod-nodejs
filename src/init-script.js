import {EventEmitter} from 'node:events';
import module from 'node:module';
import process from 'node:process';
import util from 'node:util';

// it's just so much more convenient to write some of this code in JavaScript.
export function finishInit(acore, addListenerCallback, removeListenerCallback) {
	acore.hooks = new EventEmitter().setMaxListeners(0);

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
