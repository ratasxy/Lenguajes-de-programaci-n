(define (extract-min lista)
  (eval (cons 'min lista) user-initial-environment)
)

(define (remove-first lista x)
  (if (null? lista)
    lista
    (let ((h (car lista)) (t (cdr lista)))
      (if (= x h)
        t
        (cons h (remove-first t x))
      )
    )
  )
)

(define (sorted lista)
  (if (null? lista)
    lista
    (let ((m (extract-min lista)))
      (cons m (sorted (remove-first lista m)))
    )
  )
)
