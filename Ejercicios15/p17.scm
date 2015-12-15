(define (min-max lista)
  (list
    (eval (cons 'min lista) user-initial-environment)
    (eval (cons 'max lista) user-initial-environment)
  )
)
