(define (remove-last lista)
  (if (null? (cdr lista))
    '()
    (cons (car lista) (remove-last (cdr lista)))
  )
)