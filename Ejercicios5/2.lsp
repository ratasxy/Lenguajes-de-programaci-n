;Static scoping

(defvar a "odio lisp")

a

;Dynamic scoping
(
  let (
    (b "odio lisp más que perl")
  )
  b
)

;b  obtain error;

