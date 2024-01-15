## Branch
Since git checkout has many uses, if you want to simply switch branch you can use `git switch <branchname>`
### View
* To view the online repository that your current repository is linked to: `git remote --verbose`
### Detached head
* When you commit changes to detached head without making a branch, the commits will not be saved when you switch branches.

## Patch
* When you want to send someone your changes after `<base>` branch, `git format-patch <base>`
* If you have multiple commits and you just want to generate one file: `git format-patch master --stdout > myfeature.patch`

## Merge
### Conflict
* If conflict occurs after stash pop, you'll need to explicitly drop the stash after finishing your changes.
* A way to understand the `<<<`, `===` and `>>>` marks is that the content between `<<<` `===` is to merge into and the content between `===` and `>>>` is to be merged.

## Ignoring files
* To ignore file locally: `git update-index --skip-worktree <file>`
