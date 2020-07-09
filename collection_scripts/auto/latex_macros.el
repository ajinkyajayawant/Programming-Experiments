(TeX-add-style-hook
 "latex_macros"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "11pt")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("hyperref" "hidelinks") ("listings" "procnames") ("pseudocode" "noend")))
   (add-to-list 'LaTeX-verbatim-environments-local "lstlisting")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "lstinline")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "href")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperref")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperimage")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperbaseurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "nolinkurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "url")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "path")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "lstinline")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "path")
   (TeX-run-style-hooks
    "latex2e"
    "mathtools"
    "array"
    "hyperref"
    "article"
    "art10"
    "enumitem"
    "algpseudocode"
    "algorithm"
    "xcolor"
    "listings"
    "verbatim"
    "pagecolor"
    "graphicx"
    "pseudocode"
    "art11"
    "multirow")
   (TeX-add-symbols
    '("squareB" 1)
    '("roundB" 1)
    '("inner" 2)
    '("norm" 1)
    '("abs" 1)
    "numberthis"
    "pgfmathresult")
   (LaTeX-add-labels
    "eqn"
    "euclid"
    "euclidendwhile"
    "tab:multicol")
   (LaTeX-add-environments
    "prop"
    "theorem"
    "lemma")
   (LaTeX-add-bibliographies
    "pubs")
   (LaTeX-add-mathtools-DeclarePairedDelimiters
    '("ceil" ""))
   (LaTeX-add-array-newcolumntypes
    "L")
   (LaTeX-add-xcolor-definecolors
    "keywords"
    "comments"
    "red"
    "green"))
 :latex)

