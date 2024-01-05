((c-mode . ((c-file-style . "k&r")
	    (fill-column . 80)
	    (indent-tabs-mode . nil)
	    (show-trailing-whitespace . t)
	    (eval . (setq whitespace-style '(tabs face)))
	    (eval . (whitespace-mode))
            (c-offsets-alist
             (statement-cont . (c-lineup-assignments +)))
	    (eval . (set-face-attribute 'fill-column-indicator nil :foreground "grey70"))
	    (eval . (display-fill-column-indicator-mode)))))
;; For some reason the whitespace-style has to placed before enabling the mode
;; Find a better solution for this in the future
