import packageJson from 'eslint-plugin-package-json';
import { defineConfig } from 'eslint/config';

export default defineConfig([
	{
		extends: [packageJson.configs.stylistic],
		files: ['package.json'],
	},
]);
