(require 'package)
(setq package-archives '(("gnu" . "https://elpa.gnu.org/packages/")
                         ("melpa" . "https://melpa.org/packages/")))
(package-initialize)

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(inhibit-startup-screen t)
 '(package-selected-packages
   (quote
    (haskell-mode zenburn-theme smartparens smart-tab popup-kill-ring paradox matlab-mode auto-complete auctex)))
 '(paradox-github-token t))

(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )

(require 'smartparens-config)
(smartparens-global-mode t)

;;(require 'smart-tab)
;;(global-smart-tab-mode 1)


(require 'ido)
(ido-mode t)

(require 'popup)
(require 'pos-tip)
(require 'popup-kill-ring)
(global-set-key "\M-y" 'popup-kill-ring)

;; Good theme
(load-theme 'zenburn t)

;; auto-complete
;; This isn't that useful I think, I will just enable it when I need it
;;(ac-config-default)

;;disable the top toolbar in emacs
(tool-bar-mode -1)

;; For moving between windows
(windmove-default-keybindings 'meta)

;; Maximised mode on startup
(add-to-list 'default-frame-alist '(fullscreen . maximized))

;; Installing auctex solved the problem of double indentation on pressing C-j

;; Replace selection by copying
(delete-selection-mode 1)

;;Show line numbers
(global-linum-mode t)
(put 'upcase-region 'disabled nil)
(put 'downcase-region 'disabled nil)

;; For latex viewing
 (setq TeX-auto-save t)
(setq TeX-parse-self t)
(setq-default TeX-master nil)

;; For bigger equations, taken from https://tex.stackexchange.com/questions/110819/auctex-preview-font-size-too-small
(set-default 'preview-scale-function 1.2)