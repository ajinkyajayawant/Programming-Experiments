;; The ltk document does not explicitly state the available widget names. But note that under each section name of the widget is given in slightly different font.

;; One way to run this is to run the following commands at slime
;; (load "ltk")
;; in-package :ltk)
;; (load "/media/ajin/AJ-WORK/Programming-Experiments/lisp/ltk_widgets.lisp")
;; (all-widgets)

;; For some reason I was unable to use menu based widgets

(defun all-widgets()
  (with-ltk ()
    (let ((b (make-instance 'button))
	  (cb (make-instance 'check-button))
	  (ent (make-instance 'entry))
	  (fr (make-instance 'frame))
	  (lb (make-instance 'label))
	  (lbf (make-instance 'labelframe))
	  (lstb (make-instance 'listbox))
	  (msg (make-instance 'message))
	  (pnw (make-instance 'paned-window))
	  (rdb (make-instance 'radio-button))
	  (scl (make-instance 'scale)))
      (pack b)
      (pack cb)
      (pack ent)
      (pack fr)
      (pack lb)
      (pack lbf)
      (pack lstb)
      (pack msg)
      (pack pnw)
      (pack rdb)
      (pack scl))))
