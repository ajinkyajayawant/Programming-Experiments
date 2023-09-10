;; Configs for packages that I have tried, tested, and found useful
;; This config skips the automated config added by packages
;; Some of the commands in this config are redundant in the sense that
;; they achieve the same goal in a different way. Pick and choose according
;; to preference.

(require 'package)
(setq package-archives '(("gnu" . "https://elpa.gnu.org/packages/")
                         ("melpa" . "https://melpa.org/packages/")))
(package-initialize)

(require 'smartparens-config)
(smartparens-global-mode t)
;; To highlight the matching parenthesis
(show-smartparens-global-mode t)

;; Delete trailing whitespaces after save
(add-hook 'before-save-hook
          'delete-trailing-whitespace)

;; I am happy with smartparens on linux but the skeleton pair also
;; works well enough on mac
(setq skeleton-pair t)
(global-set-key "(" 'skeleton-pair-insert-maybe)
(global-set-key "[" 'skeleton-pair-insert-maybe)
(global-set-key "{" 'skeleton-pair-insert-maybe)

(require 'ido)
(ido-mode t)

;; Rather useful for figuring out which starting
;; parenthesis matches with which ending parenthesis
(add-hook 'prog-mode-hook #'rainbow-delimiters-mode)

;; To enable completion everywhere
(add-hook 'after-init-hook 'global-company-mode)

;; This may be needed for mac
(setq ispell-program-name "aspell")

;; Alternative command for global line numbers
(global-display-line-numbers-mode)

(require 'popup)
(require 'pos-tip)
(require 'popup-kill-ring)
(global-set-key "\M-y" 'popup-kill-ring)

(load-theme 'zenburn t)

;;disable the top toolbar in emacs
(tool-bar-mode -1)

;; auto revert mode
(global-auto-revert-mode 1)
(setq auto-revert-use-notify nil)
(setq auto-revert-check-vc-info t)

;; For moving between windows
(windmove-default-keybindings 'meta)

;; Maximised mode on startup
(add-to-list 'default-frame-alist '(fullscreen . maximized))

;; Replace selection by copying
(delete-selection-mode 1)

;;Show line numbers
(global-linum-mode t)

;; Enable uppercasing and lowercasing
(put 'upcase-region 'disabled nil)
(put 'downcase-region 'disabled nil)

;; For latex viewing
 (setq TeX-auto-save t)
(setq TeX-parse-self t)
(setq-default TeX-master nil)

;; For bigger equations, taken from https://tex.stackexchange.com/questions/110819/auctex-preview-font-size-too-small
(set-default 'preview-scale-function 1.2)

;; For opening files using emacsclient, no longer needed because I included command to start emacs daemon on startup. So this one just starts another server and causes issues.
;;(server-start)
;; The command below didn't seem to work
(setq pop-up-frames nil)
(add-to-list 'display-buffer-alist
             '("^[^\\*].*[^\\*]$" display-buffer-same-window) t)

;; For slime
(load (expand-file-name "~/.quicklisp/slime-helper.el"))
(setq inferior-lisp-program "sbcl")

;; For python IDE like experience
(elpy-enable)
(eval-after-load "elpy"
  '(cl-dolist (key '("M-<right>" "M-<left>"))
     (define-key elpy-mode-map (kbd key) nil)))

;; Alternative elpy enabling
(use-package elpy
  :ensure t
  :init
  (elpy-enable))

;; For different image sizes in org
(setq org-image-actual-width nil)

;; Disabling the C-Tab option in magit because it comflicts with the tab bar mode
(with-eval-after-load 'magit-status
  (define-key magit-status-mode-map (kbd "C-<tab>") nil))

;; Want to preserve Ctrl tab functionality for tab bar movement
(add-hook 'org-mode-hook
	  '(lambda ()
	     (define-key org-mode-map [(control tab)] nil)))

;; autolad octave mode for *.m-files
(setq auto-mode-alist
      (cons '("\\.m$" . octave-mode) auto-mode-alist))

;; to turn on the abbrevs, auto-fill and font-lock features automatically
;; I am using auto-complete mode only for octave as it's a bit of a nuisance
;; globally and
(require 'ac-octave)
(add-hook 'octave-mode-hook
	  (lambda ()
	    (abbrev-mode 1)
	    (auto-fill-mode 1)
	    (auto-complete-mode 1)
	    (ac-octave-setup)
	    (if (eq window-system 'x)
		(font-lock-mode 1))))

;; Project management
(use-package projectile
  :ensure t
  :init
  (projectile-mode +1))

;; Change tab width for c mode to 2
(setq c-default-style "linux"
      c-basic-offset 2)

;; For code folding
(load-library "hideshow")
(add-hook 'c-mode-common-hook 'hs-minor-mode)

;; For telling the name of the function we are inside
;; when browsing
(which-function-mode 1)
(eval-after-load "which-func"
  '(setq which-function-modes '(c-mode c++-mode python-mode)))
