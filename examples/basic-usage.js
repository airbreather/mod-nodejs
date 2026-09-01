// Basic useful example script for mod-nodejs.
// Adjust require path to match package layout.
'use strict';

async function main() {
  console.log('mod-nodejs basic example');
  // TODO: require the package entry and call a public API method.
}

main().catch((err) => {
  console.error(err);
  process.exitCode = 1;
});
