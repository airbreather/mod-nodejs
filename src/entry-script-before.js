import {EventEmitter} from 'node:events';
import module from 'node:module';
import process from 'node:process';
import util from 'node:util';

globalThis.STAGE_2_HELPERS = {
	hooks: new EventEmitter().setMaxListeners(0),
	finishInit: (globalInteropObject, addListenerCallback, removeListenerCallback) => {
		delete globalThis.STAGE_2_HELPERS;

		Object.freeze(globalInteropObject);
		Object.seal(globalInteropObject.hooks);

		globalInteropObject.hooks.on('newListener', addListenerCallback);
		globalInteropObject.hooks.on('removeListener', removeListenerCallback);

		globalThis.Acore = globalInteropObject;

		process.on('unhandledRejection', (reason) => {
			globalThis.Acore.logError('module.nodejs', reason instanceof Error ? reason.stack : util.inspect(reason))
		});

		return (userScriptPath) => module.createRequire(userScriptPath)(userScriptPath);
	}
}
