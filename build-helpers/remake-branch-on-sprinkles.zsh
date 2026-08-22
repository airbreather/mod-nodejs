#!/usr/bin/zsh

set -euxo pipefail

MODULE_BASE_DIR="$(dirname $(dirname "$(realpath "$0")"))"
ACORE_BASE_DIR="$(dirname $(dirname ${MODULE_BASE_DIR}))"
# be somewhat careful not to clobber anything if we're not cloned to a "modules/" subdirectory
if ! git --no-pager -C $ACORE_BASE_DIR show --no-patch --oneline e8e94a0a663be0a1cefe704d8c6860a526b2d7e9; then
	echo we are not within acore/modules/something >&2
	exit 1
fi

# "sprinkles" = includes changes from the two downstream forks that are required for other modules.
# eventually, I feel like I'm well on my way to have yet another one of my own forks, but we'll see.
REBUILD_BRANCH="for-mod-nodejs-sprinkles"
REBUILD_TMP_BRANCH="${REBUILD_BRANCH}-rebuild"
MERGE_BRANCHES=("for-mod-nodejs-on-merge-base" "Grimfeather/master" "fix-socket-file-connections")

if git -C $ACORE_BASE_DIR show-branch $REBUILD_TMP_BRANCH 2>/dev/null; then
	echo rebuild temporary branch already exists >&2
	exit 2
fi

git -C $ACORE_BASE_DIR fetch --all
touch $ACORE_BASE_DIR/.workaround
git -C $ACORE_BASE_DIR stash --include-untracked
git -C $ACORE_BASE_DIR checkout -b $REBUILD_TMP_BRANCH mod-playerbots/Playerbot
for target in ${MERGE_BRANCHES[@]}; do
	if ! git -C $ACORE_BASE_DIR merge -m "Merge branch '$target' into $REBUILD_TMP_BRANCH" $target; then
		echo "RESOLVE CONFLICTS THEN PRESS ENTER SO WE CAN COMMIT THE MERGE!!!!!!!"
		read _
		if git -C $ACORE_BASE_DIR diff --name-only --diff-filter=U | grep -q .; then
			echo "unmerged paths remain; resolve them first" >&2
			exit 3
		fi
		if ! git -C $ACORE_BASE_DIR diff --check >/dev/null; then
			echo "git diff --check reports conflict markers; fix them first" >&2
			exit 4
		fi
		git -C $ACORE_BASE_DIR commit -m "Merge branch '$target' into $REBUILD_TMP_BRANCH"
	fi
done
SYNTH_COMMIT="$(git -C $ACORE_BASE_DIR commit-tree $REBUILD_TMP_BRANCH^{tree} \
	-p mod-playerbots/Playerbot \
	-p for-mod-nodejs-on-merge-base \
	-p Grimfeather/master \
	-p fix-socket-file-connections \
	-m "Merge branches 'for-mod-nodejs-on-merge-base', 'Grimfeather/master', and 'fix-socket-file-connections'")"

git -C $ACORE_BASE_DIR checkout $REBUILD_BRANCH
git -C $ACORE_BASE_DIR reset --hard $SYNTH_COMMIT
git -C $ACORE_BASE_DIR commit --amend --reset-author --date=now --no-edit
git -C $ACORE_BASE_DIR stash pop
rm $ACORE_BASE_DIR/.workaround
git -C $ACORE_BASE_DIR branch -D $REBUILD_TMP_BRANCH
