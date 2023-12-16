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

## Editing
The cut, copy, and paste commands are the following in emacs:
* Cut: `M-x kill-region`
* Copy: `M-x kill-ring-save`
* Paste: `M-x yank`

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
* Deleting backup files recursively: `M-x find-name-dired` select directory, file pattern `~\*​~​~` and repeat the procedure above
* Opening file from dired: `M-x dired` specify directory, press enter on a file.
* Creating a new diretory in dired mode - Once in dired mode press `+`
* Easy way to rename files in dired: Press `R`, it prompts for the filename to rename to. Press downarrow if you want to access the earlier filename. Change the filename and press enter.
* To rename files in dired: `%R <original file name> <new file name>`
* Dired go up a directory: `^`
* Dired remove the delete flag: `u`

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

## Config
* Substitute selection `(delete-selection-mode 1)`
* Display line numbers `(global-linum-mode t)`
* Sometimes the zenburn theme may not be installed, install it with: `M-x package-install <RET> zenburn-theme <RET>`
