(defun newline2spaces ()
  (interactive)
					; Convert the newlines to spaces M-x C-q C-j + with space
  (query-replace-regexp " *\n+ *\\|  +" " ")
  )
