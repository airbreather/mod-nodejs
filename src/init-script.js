import {EventEmitter} from 'node:events';
import module from 'node:module';
import process from 'node:process';
import util from 'node:util';

// it's just so much more convenient to write some of this code in JavaScript.
export function createHooks(addListenerCallback, removeListenerCallback) {
	const hooks = new EventEmitter().setMaxListeners(0);

	Object.seal(hooks);

	hooks.on('newListener', addListenerCallback);
	hooks.on('removeListener', removeListenerCallback);

	return hooks;
}

export function finishInit(acore) {
	globalThis.Acore = Object.freeze(acore);

	process.on('unhandledRejection', (reason) => {
		globalThis.Acore.logError('module.nodejs', reason instanceof Error ? reason.stack : util.inspect(reason))
	});

	return module.createRequire(process.cwd());
}
