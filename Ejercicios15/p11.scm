(define (revert lista)
  (if (null? lista)
    '()
    (append (revert (cdr lista)) (list (car lista)))
  )
)
