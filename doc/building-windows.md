# Building libnode.dll for mod-nodejs on Windows

This is the missing piece that the upstream README gave up on. It has two
separate problems that got tangled together in the original investigation;
solve them independently.

## Problem 1: MSVC vs ClangCL

AzerothCore's worldserver.exe is built with MSVC (cl.exe). Since Node.js 24,
Node can *only* be built on Windows with ClangCL (V8 dropped MSVC support
upstream in V8 13.0). These are not actually incompatible with each other:
clang-cl is a drop-in front end that targets the exact same ABI, calling
convention, and MSVC STL as cl.exe -- that's its entire purpose (it's what
Chromium and V8 themselves ship). As long as both sides:

- use the same Visual Studio 2022 installation / Windows SDK version, and
- use matching CRT linkage (Release, `/MD`, not `/MT`), and
- don't mix Debug and Release objects (different `_ITERATOR_DEBUG_LEVEL`)

...linking a clang-cl-built libnode.dll's import library into an
MSVC-built worldserver.exe is a supported pattern, not a dead end. You do
NOT need to build AzerothCore itself with clang-cl.

## Problem 2: zlib symbol collisions

This only bites you if you link the *static* Node build. If you build and
link against libnode.dll's import library (node.lib) instead, Windows DLLs
don't share a symbol namespace the way Linux .so's or static libs do --
nothing collides unless libnode.dll's own export table itself leaks zlib
symbols it shouldn't. That has genuinely happened in Node's Windows shared
build before (see nodejs/node's "fix various shared library build issues"),
so verify it rather than assume it:

```
dumpbin /exports Release\libnode.dll | findstr /i "deflate inflate crc32 zlibVersion compress2"
```

- **Nothing printed:** you're fine, skip to the build steps below.
- **Symbols show up:** libnode.dll is over-exporting. Fix it at the source
  by prefixing Node's vendored zlib so its symbols can never collide with
  anyone else's, regardless of what gets exported:
  1. In the Node.js source tree, open `deps/zlib/zlib.gyp` (or
     `deps/zlib/CMakeLists.txt` on newer Node versions that migrated zlib's
     build).
  2. Add `Z_PREFIX=1` to that target's `defines`.
  3. Rebuild. zlib's own headers (`zconf.h`) already support this --
     `Z_PREFIX` renames every exported symbol with a `z_` prefix
     (`deflate` -> `z_deflate`), entirely at compile time, no source
     changes needed elsewhere in Node.
  4. Re-run the `dumpbin` check above to confirm the plain names are gone.

## Build steps

1. Install Visual Studio 2022 with: Desktop development with C++, the
   "C++ Clang Compiler for Windows" component, and the Windows 10/11 SDK.
2. Fetch the exact Node.js tag mod-nodejs currently pins for Linux (check
   `CMakeLists.txt` for the version -- currently v26.7.0) so the embedder
   API surface matches what mod-nodejs's C++ code expects:
   ```
   git clone --branch v26.7.0 --depth 1 https://github.com/nodejs/node.git
   cd node
   ```
3. If Problem 2 applies to this Node version, apply the `Z_PREFIX` patch
   from above now, before building.
4. Build as a DLL with clang-cl (this is the same `dll` flag the Linux
   workflow's `--shared` maps to):
   ```
   .\vcbuild.bat dll release x64 clang-cl package
   ```
   `package` produces a self-contained install directory with
   `include\node\`, `Release\libnode.dll`, and `Release\node.lib` --
   equivalent in shape to the Linux tarball mod-nodejs already downloads.
5. Point mod-nodejs's CMake at it:
   ```
   cmake .. -DNODEJS_INCLUDE_DIR="C:/path/to/node/Release/include/node" ^
            -DNODEJS_LIB="C:/path/to/node/Release/node.lib" ^
            <your usual AzerothCore CMake args>
   ```
   (This assumes the CMakeLists.txt patch in
   `mod-nodejs-windows-fix.patch` has been applied, which replaces the
   hard `FATAL_ERROR` on WIN32 with this detection path and also copies
   `libnode.dll` next to worldserver.exe on install, since Windows has no
   rpath and won't find the DLL otherwise.)
6. Build worldserver as normal with MSVC. If the linker throws LNK2005 on
   any symbol, that symbol is still being exported from two places --
   go back to the `dumpbin` check in Problem 2 and look for whichever name
   the linker error names specifically, not just zlib.

## If it still doesn't link

The next most likely culprit, in order, is:

1. **CRT mismatch** -- confirm both worldserver.exe and libnode.dll were
   built Release/`​/MD`. Check with:
   ```
   dumpbin /dependents worldserver.exe
   dumpbin /dependents libnode.dll
   ```
   Both should depend on the same `VCRUNTIME140.dll` / `MSVCP140.dll`
   family, not `VCRUNTIME140.dll` for one and a static-linked absence for
   the other.
2. **A second symbol besides zlib** -- Node bundles more than zlib
   (OpenSSL, ICU, c-ares, llhttp, uvwasi...). Any of these could be
   independently vendored by AzerothCore too. Re-run the `dumpbin
   /exports` check against the *specific* symbol name in the LNK2005
   error, not just the zlib list above.
