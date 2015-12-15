(define (power a b)
  (if (zero? b) 1
    (let ((t (power a (quotient b 2))))
      (* t t (if (odd? b) a 1))
    )
  )
)
