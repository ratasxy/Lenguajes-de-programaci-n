(define (zeros lista)
  (if (null? lista)
    0
    (+ (if (zero? (car lista)) 1 0) (zeros (cdr lista)))
  )
)
