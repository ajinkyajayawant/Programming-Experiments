# Emacs
* Open file in view/read only mode: `M-x view-file`
* Convert and already opened file into view mode: `M-x view-mode`
* view-file has its special shortcuts like q which exits the view mode. So a better solution in later versions of emacs is: `M-x read-only-mode`
* To have a ruler on top of emacs to measure row width: `M-x ruler-mode`
* The variable that controls where the line will wrap is: `M-x fill-column`
* To set the fill column variable you can use the function: `M-x set-fill-column`
* Open file in read only mode from terminal:
```
emacsclient --create-frame --eval '(view-file "<filename>")'
```
* A file opened from gui closes all the frames when I close that buffer. A better option is to create an emacsclient frame assuming a server exists:
```
emacsclient --create-frame &
```
* Replacing newline, enter newline character C-q C-j
* Replace expressions - Suppose we have to replace a linebreak. This is basically an a newline at the end of a line to maintain fixed column width. `\(\ca\)C-q C-j \(\ca\)` replace with `\1 \2`. \(\) forms a group and in the replacing we can refer to the group by a number. Similarly if we want to replace three or more newlines with two newlines we can say replace `C-qC-jC-qC-j+` with `C-qC-jC-qC-j`
* Add a whitespace after comma: `M-x query-replace-regexp ,\([[:graph:]]\) -> , \1`
* Replace all occurences - `!`
* Ido mode suggestion ignore- press C-f again
* Delete lines containing a phrase - `Meta-x flush-lines`(It also has keep lines)
* Reload file - `M-x revert-buffer`
* `M-x list-packages` and `M-x package-list-packages` are different, wasn't able to install matlab mode from former, installed it with later
* Mark package for install: `i`
* Mark package for removal: `d`
* Set mark - `C-space`
* Incremental regexp search: `isearch-forward-regexp`. But for convenience `Ctrl+Alt+S` is better to make the same search again and again. `Ctrl+Alt+S` is a shortcut to the `isearch-forward-regexp` command.
* You can hit `M-e` to edit the current search term. This runs the command `isearch-edit-string`. You can then type `C-s` to resume the search.
* Center page around the cursor: `C-l`
* Count number of lines in the page(before and after cursor): `C-x l`
* Filter regexp: `M-x occur RET <regexp>` and then `M-x keep-lines`
* Help on a `C-x` command: `C-x ?`
* Open a new frame: `C-x 5 2`
* Close the current frame: `C-x 5 0`
* (Frames are the gui windows in emacs)
* It makes sense to have different contexts in different frames. Like programming related stuff in a frame. Text notes in one frame. And so on.
* Reload config file `M-x load-file`
* To close an emacs window opened by clicking, `C-x C-c`. To close a frame from opened from inside emacs `C-x 5 0`.
* To see what all operations were done say after a file locally changed and emacs tried to revert, check out the Messages buffer. *Messages* buffer is also useful in general for installation and command logs.
* Convert region to lowercase: `M-x downcase-region`
* Find the value of a variable: `M-x describe-variable`
* Repeat previously issued command: `M-x repeat` or `C-x z`
* If I am trying to edit matlab files in emacs, just use the octave mode.
* To see the edited portion after the last save: `diff-buffer-with-file`
* Batch indent in python one tab to the right: `python-indent-shift-right`
* Batch indent in python one tab to the left: `python-indent-shift-left`
* When you are opening files, in the minibuffer sometimes there is one persistent suggestion that you do not want. If you just press enter that suggestion gets selected. If you don't want that suggestion, press `C-x C-f` again, and you would be in a prompt without the suggestion.
* Command to increase font size in current buffer: `text-scale-increase`
* Command to decrease font size in current buffer: `text-scale-decrease`
* In the bar at the bottom you will see display like (Octave SP AC Abbrev Fill), the first word means the major mode and the later words mean the minor modes.
* To diff files use `M-x ediff` if that doesn't work as expected think of installing vdiff
* Run an command in the tiny space at the bottom: `M-: <command>`
* Command to find definitions from a keywords: `apropos`
* To change the name of the emacs window: `set-frame-name`

## Setup
* Writing your config in `init.el` file inside `.emacs.d` is recommended. But keep in mind the `init.el` is not read if emacs finds a `.emacs` file.

## Info
* Find the version: `M-x emacs-version`
* Count words and lines:
```
M-x count-words
M-x count-lines
```
* Show cursor position(especially column number) momentarily: `M-x what-cursor-position`
* Find emacs uptime: `M-x emacs-uptime`

## Navigation
* Page up: `M-v`
* Page down: `C-v`
* One word forward: `M-f`
* One word backward: `M-b`
* Line up: `C-p`
* Line down: `C-n`
* Character forward: `C-f`
* Character backward: `C-b`
* Paragraph start: `M-a`
* Paragraph end: `M-e`
* Delete a word after the cursor: `M-d`
* Deleting the word before the cursor can either be done with `C-Backspace` or `M-Backspace`
* Command to go to a particular line: `goto-line`

## Directories and file
```
M-x create-directory
M-x delete-directory
M-x delete-file
```

## Editing
The cut, copy, and paste commands are the following in emacs:
* Cut: `M-x kill-region`
* Copy: `M-x kill-ring-save`
* Paste: `M-x yank`

## Keys
* Find the description of a key in emacs. This is also useful to find the command corresponding to a shortcut: `M-x describe-key`
* `(local-unset-key key)` removes the binding of the key from the current map.

## Search
* The search that gives the results one by one in emacs is the incremental search. Its commands start with isearch keyword. The shortcut to move to the next word in the incremental search is C-M-s.
* To count the number of occurences of a pattern, use the command: `how-many`
### Filtering
For filtering the buffer based on patterns the following commands are useful:
```
flush-lines
delete-matching-lines
keep-lines
delete-non-matching-lines
occur
loccur
```

### Rectangle commands
* For cutting rectangle, mark one corner of the rectangle go to the other end and do `M-x kill-rectangle`
* Copy a rectangle: `M-x copy-rectangle-as-kill`
* Paste the copied rectangle starting at the position of cursor(no need to select the region here) `M-x yank-rectangle`
* For inserting text in a rectangle: `M-x string-insert-rectangle RET string RET`
* Replace rectangle: `M-x string-rectangle`

## Buffer menu
* Kill/save multiple buffers: `M-x buffer-menu`
* Flag buffers for deletion using `d`
* Flag buffers for save using `s`
* Execute the commands with `x`

## Dired
* Deleting backup files: Open dired, press `~​~​~` (flags all backup files), press `x`, confirm
* Find files using dired: `find-name-dired`
* Deleting backup files recursively: `M-x find-name-dired` select directory, file pattern `~\*​~​~` and repeat the procedure above
* Opening file from dired: `M-x dired` specify directory, press enter on a file.
* Creating a new diretory in dired mode - Once in dired mode press `+`
* Easy way to rename files in dired: Press `R`, it prompts for the filename to rename to. Press downarrow if you want to access the earlier filename. Change the filename and press enter.
* To rename files in dired: `%R <original file name> <new file name>`
* Dired go up a directory: `^`
* Dired remove the delete flag: `u`

## Modes
To find the name of the current major mode:
```
M-x describe-variable
major-mode
```

## Term mode
* If you change the input mode to `line-mode`, then regular Emacs commands work. You can switch to `line-mode` with `C-c C-j`. You can switch back to `char-mode` with `C-c C-k`.
* Char-mode is used for the terminal behavior and line mode is used for emacs shortcuts

## Tables
* Insert table: `M-x table-insert`
* Insert row: `M-x table-insert-row table-delete-row`
* Insert column: `M-x table-insert-column`
* Insert column: `M-x table-delete-column`

## Calculator
* To start the calculator: `M-x calc`
* For infix type of operations use apostrphe operator, for example: `'2+3`

## Magit
* To start magit run: `magit-status`
* To refresh the status, can use(g): `magit-refresh`
* To fold and unfold entries use `TAB`
* To see all the remotes, open a split window and use the command(y): `magit-show-refs`
* To fetch use the command(f): `magit-fetch`
* To pull use the command(F): `magit-pull`
* To checkout a branch use the command(bound to b): `magit-branch`
* To delete branches, whether local or remote, point at that branch and give the following command(b m): `magit-branch-delete`
* See an ascii visualization of commits and branches: `magit-log`
* To stage(add) changes, go the the corresponding unstaged entry and use the command(s): `magit-stage`
* To unstage changes (u): `magit-unstage`
* To commit the changes(c): `magit-commit`
* After the `magit-commit` command you will first get the diff buffer. If that is okay, press the `c` key which will then take you to the commit buffer.
* After writing the text for the commit use the command: `with-editor-finish`
* To save a stash use the following and follow up with the prompts(z): `magit-stash`
* Amend a commit: `magit-commit-amend`
* It is easier to go through the commit menu by pressing `c` and then selecting the amend option using `a`.

## Tab bar
* If the tabbar crashes or disappears just enable it from `Options->Show/Hide->Tab Bar`
* Switch to a different tab: `M-x tab-bar-switch-to-tab`
* To move a tab to the right in the deafult tab bar mode use the command: `tab-bar-move-tab`
* To move to the left use: `tab-bar-move-backward`
* It makes sense to have split window inside a tab so we can have different locations views of the same file.

## Tramp
* To start tramp, do `C-x C-f` and type the filename as `/ssh:<username>@<host>:`
* Once you press the colon after the hostname it will ask you for the password and will then connect you once you enter it.
* To end tramp connections use the following command: `tramp-cleanup-connection`
* To run octave on the remote machine just give the `M-x run-octave` command when current directory is one of the remote directories.

## Org mode
* The variable `org-agenda-files` holds the search paths for agenda files
* Add the current file to agenda search list: `org-agenda-file-to-front`
* To move between TODO, DONE, unlabeled states, use shift left and shift right
* If you want to see the TODO tasks from a list, use `M-x org-show-todo-tree`
* If you want to move back from the tree view to the full view, go to the header and press TAB
* Pressing TAB at a header sycles between only header, header and all bullets, header all bullets and descriptions.
* Doing Alt left and right moves the bullet one level deeper or outer.
* Doing Alt up or down moves the task up or down in the list spatially.
* For opening the agenda view use the command: `org-agenda`
* For selecting day/month/year view while in aenda mode use: `v d/v m/v y`
* To enter a time stamp: `org-time-stamp`
* Deadline: You start seeing this early in the agenda view
* Scheduled: You start seeing this in the agenda view after the set date
* Plain timestamp: You don't see this in the agenda view after that date
* To have an am/pm timestamp in org-agenda, toggle the variable: `org-agenda-timegrid-use-ampm`
* Once you have set the custom time format in the `org-display-custom-times` or `org-time-stamp-custom-formats` variables, you can toggle the viewing of the time format with the command `org-toggle-time-stamp-overlays`.
* To set up or change priorities Use `S-up` or `S-down`.
* To set a tag use the command: `org-set-tags-command`
* To isolate all the tasks for a tag, do: `M-x org-agenda m`
* To view agenda for specific week, go to the agenda view and type: `v <week number> w`
* To find the week number of the current week, look at the topmost line when in the org-agenda mode
* When you use scheduled or deadline it automatically appears in your agenda till you mark it done. You don't need to mark it todo explicitly for it to appear.
* The repeat in emacs works with end date if you do not have todo with it. So it just adds a calendar entry on that day. I think this would be ideal for birthdays.
* To cycle the folding states for the entire buffer, including putting the folder in the only-headings state: `M-x org-global-cycle`
* Cycling the entire buffer in the folding states can also be done with the shortcut: `S-TAB`
* To create tables in org mode simply make the title like `| a | b | c |` and use tab to align them every now and then
* To start a reminder for a deadline different number of days earlier, add words like -5d. For example if the deadline is mentioned as DEADLINE: `<2004-02-29 Sun>`, edit it to DEADLINE: `<2004-02-29 Sun -5d>`.
* To see the agenda for the next <n> days, use the command: `C-u <n> M-x org-agenda a`
* To repeat a subtree: `org-clone-subtree-wth-time-shift`
* To match by tags, run the `org-agenda` command, press `m`, and then enter the tag name with `TAB` for completion if needed.
* To display images inline in org mode, use the command: `org-toggle-inline-images` or `org-display-inline-images`
* To resize images put the following in the config file: `(setq org-image-actual-width nil)`, and put the following just above the image link: `#+ATTR_ORG: :width <width in numbers>`
* Make sure the path of the image is specified even if the image is in the same directory.
* For showing the full text of the links, for example image links, use the command: `org-toggle-link-display`

## Config
* Substitute selection `(delete-selection-mode 1)`
* Display line numbers `(global-linum-mode t)`
* Sometimes the zenburn theme may not be installed, install it with: `M-x package-install <RET> zenburn-theme <RET>`
### Local config
* Per repository config can be written inside `.dir-locals.el` and it will apply to all files inside that directory.

## Elpy
* Specifying elpy to use a particular python: (setq elpy-rpc-python-command "python3")
* Remove keybindings after loading a mode, example:
```
(eval-after-load "elpy"
  '(cl-dolist (key '("M-<up>" "M-<down>" "M-<left>" "M-<right>"))
     (define-key elpy-mode-map (kbd key) nil)))
```
* To get the details how elpy is configured in your system, use the command: elpy-config
* To check whether flycheck is installed and working, do: M-x flycheck-verify-setup
* Generate pylint configuration file if needed using: pylint --generate-rcfile > ~/.pylintrc
* To have syntax highlighting in emacs elpy, use the command: pyvenv-activate
### Flake8
Create .flake8 file in the home directory for a global config. Sample config file below:
```
[flake8]
ignore = H903, E266, D203, H306
exclude = .git
max-complexity = 10
max_line_length = 120
```
Sometimes emacs doesn't check the config files unless you restart it.

## Flymake
* Go to next error: `flymake-goto-next-error`
* Go to previous error: `flymake-goto-prev-error`

# Regular expressions replace
* Convert variables with underscore name to camel case: `_\([a-z]\)` to `\,(upcase \1)`
