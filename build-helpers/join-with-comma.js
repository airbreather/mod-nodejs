const parts = new Intl.ListFormat('en', { type: 'conjunction', style: 'long' }).formatToParts(process.argv.slice(2));
process.stdout.write(parts.map(p => p.type === 'literal' ? `'${p.value}'` : p.value).join(''));
