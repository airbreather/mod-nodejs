# mod-nodejs

*The module to end all modules!*

Basically just the same idea behind Eluna/ALE, but for JavaScript (Node.js, specifically) instead of Lua.

Requires core patch:
- azerothcore/azerothcore-wotlk#26648 for API tweaks

## Building natively on Windows does not work right now.

I have sunk too many hours into trying to make this work on native Windows. Use containers or WSL instead.

## Skeleton Project

There are some specific configuration settings you'll need to have in order to run scripts with this, so I've made a "skeleton" project that you can copy from in order to get started:

https://github.com/airbreather/mod-nodejs-skeleton

That project has:

- `package.json` / `package.lock.json` / `tsconfig.json` so you can get right into it.
- an `index.ts` file with a (more) commented example showing some of what you can do.
- some scripts (in `package.json`) to help make the single `index.js` you need for this module to work.
- `UNLICENSE`. Do whatever with that one: the base module is all I wanted to AGPL-3.0 license.

## TypeScript Declarations

Declarations are built from the `./typescript` directory in this project. Install them with:

`npm install -D @airbreather/mod-nodejs-types`

Highly recommended: add `@airbreather/mod-nodejs-types` to your `tsconfig.json`'s `"types"` array.

## Demo

I recorded my screen for a demo that includes building it all from scratch after checking out the code, then using the VSCode debugger to set breakpoints and step through the random ad-hoc script file from the `examples/` directory here:

[![Demo](https://i.ytimg.com/vi/Xmj0S-SFXc8/maxresdefault.jpg)](https://youtu.be/Xmj0S-SFXc8)

This particular demo was recorded with several other modules and a Playerbot fork because that's what I happen to be working with in my local environment right now, but mod-nodejs can be used as the only module on a Playerbot-free setup as well.

## Usage

The usual process of `mod_nodejs.conf.dist` --> `mod_nodejs.conf`. Set `NodeJs.Script` to the path to your script file that will be loaded at world startup. It can import other script files as well (or it can be a single-file bundle), there just needs to be exactly one.

Published documentation for all the APIs will come later, though the TypeScript declarations exist now for you to get going. See the config file for the flags you can turn on, and [Node.js docs](https://nodejs.org/learn/getting-started/debugging) for the different ways you can connect to the debugger once it's running.

See also the files under `/examples`.

## Building

The only thing I can promise to support is what I run with, which is Linux. Here, there should be no extra steps required for this module. [The normal process](https://www.azerothcore.org/wiki/installing-a-module) should work.

On Windows, I had a hard time trying to get it to work and gave up without any success.

<details>
<summary>Click to expand this section that goes over how far I got down the most promising path to making this work on Windows, but note that IT WILL NOT WORK AS-WRITTEN, so I've collapsed it by default in order to not confuse anybody.</summary>

I had entertained the notion that the official builds of `node.exe`/`node.lib` might work, and I could get it to build, but it didn't get very far at runtime. Almost definitely, you need to build `libnode.dll`/`libnode.lib`, probably by running something like this in the directory where you've cloned Node.js:

```
.\vcbuild.bat release dll full-icu x64 vs2026 no-cctest nonpm
```

No matter whether you try the `node.exe` or the `libnode.dll` route, you have to do something to work around the fact that both it and AzerothCore export zlib symbols.

I had started down the path of tweaking AzerothCore to let modules substitute in their own zlib implementations in azerothcore/azerothcore-wotlk#27003, and this has let me build, but something always fails.

Notably, this does **NOT** seem to have anything to do with AzerothCore only supporting MSVC and Node.js 24+ only supporting Clang-CL. A minimal embedder repro on Windows also failed for me when building the repro and libnode with Clang-CL, which is the point where I threw in the towel.
</details>

On everything else, I can't test it myself, so you're mostly on your own.

## Compatibility

At this time, the ONLY commitment to script compatibility is this: if it's possible for a script to do something useful and well-defined with AC objects (hooks and methods both), then any future changes that make it impossible shall be considered bugs that should be fixed with reasonably high priority. Otherwise, there are NO commitments to script compatibility; in particular, it is very likely that several APIs will change in the future. I've even been on the fence about keeping `Acore.*` vs. putting lots of things in the global scope.

I expect there to be a time in the future when all APIs available to scripts are considered stable and reliable for the sake of making bigger projects more palatable - nobody wants to sink hundreds of hours into an interesting module project where every interaction with AC can change dramatically. We are not there yet.

To rephrase: there should only be two reasons why you would intentionally want to NOT update to a newer version of mod-nodejs:
1. You don't have time to fix scripts to accommodate breaking changes yet, OR
2. The latest version has a regression bug that you can expect to be fixed soon.
