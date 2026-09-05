#!/usr/bin/zsh

set -euxo pipefail

SCRIPT_DIR=$(dirname "$(realpath "$0")")
MODULE_BASE_DIR="$(dirname $SCRIPT_DIR)"
ACORE_BASE_DIR="$(dirname $(dirname ${MODULE_BASE_DIR}))"
# be somewhat careful not to clobber anything if we're not cloned to a "modules/" subdirectory
if ! git --no-pager -C $ACORE_BASE_DIR show --no-patch --oneline e8e94a0a663be0a1cefe704d8c6860a526b2d7e9; then
	echo we are not within acore/modules/something >&2
	exit 1
fi

# "sprinkles" = includes changes from the two downstream forks that are required for other modules.
# eventually, I feel like I'm well on my way to have yet another one of my own forks, but we'll see.
SPRINKLES_SLUG="my-archipelago-sprinkles"
SPRINKLES_BASE_BRANCH="mod-playerbots/Playerbot"
SPRINKLES_MERGE_BRANCHES=("for-mod-nodejs-on-merge-base" "allow-external-zlib-on-merge-base" "for-my-archipelago" "Grimfeather/master" "fix-socket-file-connections")

# it also needs to build on master, though, so don't leave that behind
MASTER_SLUG="my-archipelago-master"
MASTER_BASE_BRANCH="upstream/master"
MASTER_MERGE_BRANCHES=("for-mod-nodejs-on-merge-base" "allow-external-zlib-on-merge-base" "for-my-archipelago" "fix-socket-file-connections")

# short-circuit if either rebuild would clobber an existing temporary branch
check-branch() {
	local slug=$1
	local rebuild_branch="for-mod-nodejs-${slug}"
	local rebuild_tmp_branch="${rebuild_branch}-rebuild"
	if git -C $ACORE_BASE_DIR show-branch $rebuild_tmp_branch 2>/dev/null; then
		echo rebuild temporary branch already exists: $rebuild_tmp_branch >&2
		exit 2
	fi
}
check-branch $SPRINKLES_SLUG
check-branch $MASTER_SLUG

rebuild-branch() {
	local slug=$1
	local base_branch=$2
	shift 2
	local rebuild_branch="for-mod-nodejs-${slug}"
	local rebuild_tmp_branch="${rebuild_branch}-rebuild"

	git -C $ACORE_BASE_DIR checkout -b $rebuild_tmp_branch $base_branch
	for target in "$@"; do
		if ! git -C $ACORE_BASE_DIR merge -m "Merge branch '$target' into $rebuild_tmp_branch" $target; then
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
			git -C $ACORE_BASE_DIR commit -m "Merge branch '$target' into $rebuild_tmp_branch"
		fi
	done
	local merged_tree
	merged_tree="$(git -C $ACORE_BASE_DIR rev-parse $rebuild_tmp_branch^{tree})"
	local -a parent_args
	parent_args=(-p $base_branch)
	for target in "$@"; do
		parent_args+=(-p $target)
	done
	local synth_commit
	synth_commit="$(git -C $ACORE_BASE_DIR commit-tree $merged_tree ${parent_args[@]} \
		-m "Merge branches '$(node "${SCRIPT_DIR}/join-with-comma.js" "$@")'")"
	git -C $ACORE_BASE_DIR checkout $rebuild_branch
	git -C $ACORE_BASE_DIR reset --hard $synth_commit
	git -C $ACORE_BASE_DIR commit --amend --reset-author --date=now --no-edit
	git -C $ACORE_BASE_DIR branch -D $rebuild_tmp_branch
}

git -C $ACORE_BASE_DIR fetch --all
touch $ACORE_BASE_DIR/.workaround
git -C $ACORE_BASE_DIR stash --include-untracked

rebuild-branch $SPRINKLES_SLUG $SPRINKLES_BASE_BRANCH ${SPRINKLES_MERGE_BRANCHES[@]}
rebuild-branch $MASTER_SLUG $MASTER_BASE_BRANCH ${MASTER_MERGE_BRANCHES[@]}

git -C $ACORE_BASE_DIR stash pop
rm $ACORE_BASE_DIR/.workaround
