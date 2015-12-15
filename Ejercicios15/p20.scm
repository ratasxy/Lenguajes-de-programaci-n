(define (doit-helper n acc)
  (if (= n 0)
    acc
    (doit-helper (- n 1) (+ acc n))
  )
)

(define (doit n)
  (doit-helper n 0)
)
