#!/usr/bin/zsh

set -euxo pipefail

MODULE_BASE_DIR="$(dirname $(dirname "$(realpath "$0")"))"
ACORE_BASE_DIR="$(dirname $(dirname ${MODULE_BASE_DIR}))"
# be somewhat careful not to clobber anything if we're not cloned to a "modules/" subdirectory
if ! git --no-pager -C $ACORE_BASE_DIR show --no-patch --oneline e8e94a0a663be0a1cefe704d8c6860a526b2d7e9; then
	echo we are not within acore/modules/something >&2
	exit 1
fi

REBUILD_BRANCH="for-mod-nodejs-master"
REBUILD_TMP_BRANCH="${REBUILD_BRANCH}-rebuild"

if git -C $ACORE_BASE_DIR show-branch $REBUILD_TMP_BRANCH 2>/dev/null; then
	echo rebuild temporary branch already exists >&2
	exit 2
fi

git -C $ACORE_BASE_DIR fetch upstream
touch $ACORE_BASE_DIR/.workaround
git -C $ACORE_BASE_DIR stash --include-untracked
git -C $ACORE_BASE_DIR checkout -b $REBUILD_TMP_BRANCH upstream/master
git -C $ACORE_BASE_DIR merge for-mod-nodejs-on-merge-base fix-socket-file-connections allow-external-zlib -m "Merge branches 'for-mod-nodejs-on-merge-base', 'fix-socket-file-connections', and 'allow-external-zlib'"
git -C $ACORE_BASE_DIR checkout $REBUILD_BRANCH
git -C $ACORE_BASE_DIR reset --hard $REBUILD_TMP_BRANCH
git -C $ACORE_BASE_DIR stash pop
rm $ACORE_BASE_DIR/.workaround
git -C $ACORE_BASE_DIR branch -D $REBUILD_TMP_BRANCH
